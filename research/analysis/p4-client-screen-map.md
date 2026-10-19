# P4 — Mapa klijentskog screen puta (dongle→auto) i šta treba za drugi stream (111)

Target: `firmware/extracted/ax_202609051445/sdDongle` (stock). Statička analiza: Ghidra headless dekompilacija postojećeg projekta `/tmp/ghproj` plus rizin i skeniranje gp/GOT referenci (`_gp` = 0x570c30). Gdje nešto nije direktno provjereno, to piše uz stavku.

Ukratko:
- Context za SETUP prema autu je čist i alocira se po instanci, a slanje frameova uzima context kao argument. Za cluster je to dobra polazna tačka.
- Problemi su tri: tip 110 je hardkodiran na tri mjesta, `streamConnectionID` je globalan, a receiver frameove isporučuje kroz jedan globalni callback.
- UUID cluster ekrana se nigdje ne čuva. Parser `/info` uzme `displays[0]` i dalje ne gleda.

## 1. Klijentski screen context (`param_1` od `AirplayClientSendCmdSetupScreen` @0x4317a0)

Alocira ga `carplay_reverse_video_start` @0x4324e4: `malloc(0x288)`, pa `memset` na 0, `[0] = -1`, `pthread_mutex_init(ctx+0x34)` i `ctx[0x13] = ctx+0x34`. Zatim poziva `SetupScreen(ctx)`. Ako to uspije, registruje `{video_fake_video_conifig_notify_impl @0x430704, ctx}` i vraća ctx.

| Offset (word / byte) | Značenje |
|---|---|
| [0] +0x00 | TCP fd prema autu. Početno -1. Upisuje se tek na kraju uspješnog SETUP-a, pa `close` i ponovo -1 u `FUN_004305b0`. |
| [1] +0x04 | dataPort auta. Upisuje ga response callback @0x430b18. U logu: `HU video data port:6030 type:110`. |
| [2] +0x08 | dispatch timer source na main queue, period 2 s. Event handler @0x4308ec šalje "frame type 5" sa stats plistom (`sentFramesAvg`, `encoderCurrentFPS`, `queuedFramesAvg`, `rttAvg`). Cancel handler je @0x430538 i samo loguje. |
| [3] +0x0c | `active`, postavlja se na 1. Timer šalje samo kad su i ovo i `gClientReady` (0x56abec) različiti od nule. |
| [4..7] +0x10 | AES ključ, 16 B |
| [8..0xb] +0x20 | AES IV, 16 B |
| [0xc] +0x30 | `dispatch_semaphore` za čekanje odgovora na SETUP. Na izlazu se oslobađa. |
| [0xd..0x12] +0x34 | `pthread_mutex_t`, 24 B |
| [0x13] +0x4c | pokazivač na taj mutex (koriste ga timer, push i stop) |
| [0x14] +0x50 | bajt: 1 znači ChaCha20-Poly1305 mod (HomeKit). Pri postavljanju se dio +0x50..+0x167 nulira. |
| [0x15] +0x54 | ChaCha20-Poly1305 kontekst |
| [0x50] +0x140 | ChaCha ključ, 32 B (iz `simGetStreamSecurityKeys`) |
| [0x58] +0x160 | ChaCha nonce, 8 B, little-endian brojač koji se uvećava po frameu |
| [0x5a] +0x168 | `AES_CTR` kontekst do +0x288 (0x120 B). Inicijalizuje se `AES_CTR_Init(ctx+0x168, ctx+0x10, ctx+0x20)` @0x4323ac. |

Kako se dolazi do ključeva:
- Ako je `pairVerifySessionHomeKit` (0x56ad70) == 0: `simAirPlayDeriveAESKeySHA512(sessionAesKey 0x56ad90, 16, "AirPlayStreamKey%llu", "AirPlayStreamIV%llu", ctx+0x10, ctx+0x20)`. Broj `%llu` je globalni `streamConnectionID`.
- Inače: `simGetStreamSecurityKeys(..., streamConnectionID, ..., 0x20, out)`, zatim kopija u +0x140.

Gdje se čuva pokazivač na main context:
- **`FakeCarplay+0x108`**. Upisuju ga `FakeCarplay::wlCarplayVideoStartProc` @0x41d950 i `FakeCarplay::send_hu_video_start_cmd` @0x41d24c, a čitaju `CarplayVideoDataProc` i `FUN_00419760`.
- **0x56bdd4** drži ctx direktno (config-notify ctx; 0x56bdd0 je pokazivač na funkciju). Postavlja ga `carplay_fake_register_video_config_notify_callbacks` @0x47ebe8, briše `..._unregister` @0x47ec10 iz `carplay_reverse_video_stop`.
- Do samog `FakeCarplay*` dolazi se kroz video callback struct: **0x56c3ac**.

## 2. Lanac poziva i UUID ekrana

Ko poziva `SetupScreen`: samo `carplay_reverse_video_start` (poziv @0x432624). Njega pozivaju:
- `FakeCarplay::wlCarplayVideoStartProc` @0x41d950 (poziv @0x41dbec). Ovo je normalni put: phone `ScreenStreamStart` → globalni start callback → `CarplayVideoStartCB` @0x419598 → `FakeCarplay::CarplayVideoStart` @0x41a5f8 → `postEvent` na state machine → `wlCarplayVideoStartProc`.
- `FakeCarplay::send_hu_video_start_cmd` @0x41d24c (poziv @0x41d2bc).
- `FUN_00432cf0` @0x432f44, sim/test put koji pušta H.264 iz fajla.

Gašenje: `carplay_reverse_video_stop` @0x432c1c redom poziva unregister config-notify, `AirplayClientSendCmdTearDownScreen` @0x4326d0, `FUN_004305b0` (cancel timer, `close` fd, `AES_CTR_Final`) i `free`.

`gMainScreenUUID` (OBJ 0x56ada0, GOT 0x56939c):
- Postavlja se samo na **0x4290d0**, u `FUN_00428594`. To je parser carinfo/`/info` odgovora sa auta.
- Čita se u SETUP @0x431af8 i TEARDOWN @0x4328bc.

Kako parser bira display (petlja nad `displays` 0x51f628):
- Za svaki element čita `type` (0x51f240).
- Ako je `type == 0x6e`, ili ima samo jedan display, bira taj element.
- Ako čitanje `type` vrati grešku, prekida petlju i, kad ima više od jednog displaya, uzima trenutni element bez parsiranja viewAreas (skok na 0x4290b4).
- Iz izabranog elementa uzima `uuid` (0x51f3fc) i radi `CFStringCreateCopy`, plus `widthPixels`, `heightPixels` i `maxFPS` u `gVideoWidth`, `gVideoHeight` i `gFps`.

Šta se desilo u autu: log pokazuje `video stream count:2` i `video type:0 err:-6727`. Audi `displays[0]` nema ključ `type` (vidi `analysis/carinfo/audi_displays.json`), pa se uzima `displays[0]` (e5f7…) i petlja staje na indeksu 0. **`displays[1]` (b7e6c5a0…, type 111) se nikad ne pročita.** Nema globala ni polja koji čuva cluster uuid; bajtova `b7e6c5a0` u stock binarnom nema. `CarplayReverseSessionNotifyCarplayInfo` @0x41b564 samo kopira 0x8c B `ReverseCarplayInfo` u `FakeCarplay+300` i uuid ne sadrži. `_getScreenDisplays` je phone-facing i nije bitan za ovo.

## 3. Response handler za SETUP

Kako se šalje i gdje ide odgovor:
- Prije `HTTPClientSendMessage(gAirPlayClient 0x56abf8, msg)` postavlja se `msg+0x904 = 0x430b18` (completion), `msg+0x8f4 = 0`, `msg+0x8f8 = 0` i `msg+0x8fc = ctx`.
- **`FUN_00430b18`**: tijelo odgovora je na `msg+0x49c` (pokazivač) i `msg+0x4a0` (dužina), parsira se kao bplist.
- U nizu `streams` (0x52105c) traži element sa `type == 0x6e` (hardkodirano) i iz njega čita `dataPort` (0x52107c).
- Zatim `((ctx*)msg+0x8fc)[1] = dataPort` i `dispatch_semaphore_signal(ctx[0xc])`.

Šta to znači za drugi stream:
- **Rutiranje ide po porukama, kroz kontekst samog `msg`.** Dva SETUP-a, svaki sa svojim ctx, ne bi se pomiješala.
- Ali callback prihvata samo `type == 110`. Odgovor za 111 se ne bi prepoznao, semafor se ne bi signalizirao, a `dispatch_semaphore_wait` (bez timeouta) bi **zauvijek blokirao** pozivajući thread.
- Za 111 treba kopija callbacka koja poredi sa 0x6f.

## 4. Slanje frameova (dongle→auto)

Main bridge, od "primljeno sa telefona" do "poslano autu":

```
FUN_0046fdcc (screen thread: SocketAccept na session+0x18a4)
 └ AirPlayReceiverSessionScreen_ProcessFrames @0x47ef54 (screen=session+0x18a0, NetSocket=session+0x18a8)
    · 128 B header u screen+0x38 (word0 = veličina tijela, bajt +4 = tip: 0 video, 1 config/avcC)
    · tijelo: malloc → AES_CTR_Update(screen+0xb8) ili chacha (screen+0x1d8, key +0x2c4, nonce +0x2e4)
    · tip 0: ako 0x56bddc == 0 → @0x47f64c ScreenStreamProcessData(screen[0xbc]=+0x2f0, buf, len)
 └ ScreenStreamProcessData @0x50cc28  (stream+0x0c/+0x10 avcC, +0x14 "avcC poslan", +0x18 nalLen)
    · prvi poziv: šalje avcC; zatim length-prefixe pretvara u 00 00 00 01 (in-place)
    └ FUN_0050c55c @0x50c55c: (*0x56c3a8)(*0x56c3ac, buf, len)     ← GLOBALNI data callback
       └ CarplayVideoDataProcCB @0x4195c8 → FakeCarplay::CarplayVideoDataProc @0x41ab58 (this, buf, len)
          └ carplay_reverse_video_push_frame @0x431698 (ctx=this+0x108, buf, len, isConfig=this[0x10c])
             · lokalni 128 B header: [0]=len, +4=isConfig, za config +0x10/+0x14 = gVideoWidth/Height (float)
             └ video_fake_push_frame_cb @0x43108c (ctx, hdr, buf, len, 1)
                · tip 0: buf[0..3] = BE(len-4); AES_CTR_Update(ctx+0x168) ili chacha(ctx+0x54) (+16 B tag)
                · tip 1: h264_convert_AnnexBHeader2AVCC; viewArea iz gActiveViewArea/gInViewAreas → hdr+0x20..0x2c
                · writen(ctx[0], hdr, 0x80) + writen(ctx[0], buf, len) [+ writen tag]
                  (writen @0x4311bc/0x4311e4/0x43124c/0x4312f0/0x43155c/0x4315b4)
```

Ostale funkcije koje pišu na fd:
- `video_fake_video_conifig_notify_impl` @0x430704. ProcessFrames ga zove za tip 1 kad se viewArea promijeni (preko 0x56bdd0 i 0x56bdd4, @0x47f9a8–0x47fa04). Šalje header i avcC **nešifrovano**.
- Timer @0x4308ec.

Gdje su callback globali:
- `video_register_callbacks` @0x50c620 kopira 16 B na **0x56c3a0**: start, stop, data, ctx. Registruje se iz `FakeCarplay::init` @0x41c39c.
- Redoslijed {start, stop, data, ctx} je izveden iz `sw` offseta 0x60/0x64/0x68/0x6c, uz pretpostavku da je `a0 = sp+0x60`. To se slaže s tim kako ih koriste `ScreenStreamStart` i 0x50c55c.

## 5. Receiver strana i 111

- `ScreenStreamSetDelegateContext` @0x50c764 samo upisuje `stream+8`, i **taj ctx se za isporuku podataka ne koristi**. Isporuka uvijek ide kroz globalni callback na 0x56c3a0, dakle u isti `FakeCarplay`, u `+0x108`, u main ctx.
- Drugi `ScreenStream` za 111 (`ScreenStreamCreate` @0x50c6a0, CF instanca od 0x30 B) bi zato slao frameove u **main** stream prema autu. Pored toga, njegov `ScreenStreamStart` i `ScreenStreamStop` bi okinuli `FakeCarplay::CarplayVideoStart` i `CarplayVideoStop` za main.
- Prijedlog za P4: ne praviti drugi `ScreenStream`. Neka shim nakon dešifrovanja 111 frameova ide pravo na **`carplay_reverse_video_push_frame(clusterCtx, buf, len, isConfig)`** @0x431698, ili na `video_fake_push_frame_cb(clusterCtx, hdr128, buf, len, 1)` @0x43108c ako se header piše ručno. Obje funkcije primaju ctx eksplicitno i zaključavaju `ctx[0x13]`.
- Ulaz mora biti Annex-B (start kodovi), jer push zamjenjuje samo prva 4 bajta sa `len-4`. Ako access unit ima više NAL-ova, ostali start kodovi ostaju; vjerovatno je isto i kod maina danas, ali to nije provjereno.
- Za config ulaz su Annex-B SPS i PPS.

Cluster ctx bi se pravio kao kopija `carplay_reverse_video_start`, uz ove izmjene:
- `malloc(0x288)`, `[0] = -1`, mutex na +0x34, `[0x13] = +0x34`.
- Kopija `SetupScreen` sa `type 0x6f` (main je hardkodiran na @0x431adc), cluster uuid umjesto `gMainScreenUUID` i response callbackom koji poredi 0x6f.

## Šta smeta drugom paralelnom streamu

1. **`streamConnectionID` je globalan**: 0x56b378 (lo) i 0x56b37c (hi). Upisuje se @0x431ac0, čita za log @0x431b98 i za izvođenje ključeva @0x4322e4/0x432318/0x4323bc. Dva SETUP-a u isto vrijeme bi koristila pogrešne ključeve. Jedan za drugim je OK, jer se ključevi izvode prije nego što `SetupScreen` vrati.
2. **Tip 110 je hardkodiran** u SETUP-u (@0x431adc), u response filteru 0x430b18 i u TEARDOWN-u @0x4326d0. TEARDOWN šalje i `gMainScreenUUID`, a callback mu je @0x430530 sa ctx u `msg+0x8f4`.
3. **Semafor nema timeout.** Neprepoznat odgovor blokira thread zauvijek.
4. **Globalni data callback** (0x56c3a0–0x56c3ac) i jedno mjesto za ctx u `FakeCarplay+0x108`. Flag `this[0x10c]` ("sljedeći je config") postoji samo jednom.
5. **Config-notify** (0x56bdd0/0x56bdd4) i viewArea cache (0x56bde8–0x56bdf4) su singletoni. Resetuje ih `StartSession` @0x47fe40.
6. **Push koristi dimenzije maina**: `gVideoWidth`/`gVideoHeight` (GOT 0x569394/0x569398) i `gActiveViewArea`/`gInViewAreas` za config header. Cluster config bi dobio 1024×480 i viewArea maina, osim ako se header piše ručno i `gActiveViewArea == -1`.
7. **Receiver ekran je singleton**: `session+0x18a0` (`calloc(1,0x2f8)`), jedan listen socket na +0x18a4 i NetSocket na +0x18a8. Shim (`shim/altscreen.c`) to već zaobilazi.
8. **0x56bddc** (fake-video flag), ako je različit od nule, potpuno preskače `ScreenStreamProcessData`.
9. Manje bitno: cache stats plista za timer (0x56b324–0x56b32c) je dijeljen i ne smeta. `gPeerAddr` 0x56c3e0 je IP auta i dijeljen je, što je ispravno: port se uzima iz `ctx[1]`, a konekcija je TCP sa 21 pokušajem po 100 ms.

## Ključne adrese

| Šta | Adresa |
|---|---|
| main ctx | `*(FakeCarplay*)(*0x56c3ac)+0x108`, i direktno `*0x56bdd4` |
| `gMainScreenUUID` | 0x56ada0 (GOT 0x56939c), set @0x4290d0 |
| `sessionAesKey` / `sessionAesIV` | 0x56ad90 / 0x56ad7c |
| `gPeerAddr` | 0x56c3e0 |
| `gAirPlayClient` | 0x56abf8 |
| `streamConnectionID` | 0x56b378/0x56b37c |
| `pairVerifySessionHomeKit` | 0x56ad70 |
| cluster uuid | ne postoji |
| SETUP response callback | 0x430b18; TEARDOWN callback 0x430530 |
| bridge (main) | 0x47f64c → 0x50cc28 → 0x50c55c → 0x4195c8 → 0x41ab58 → 0x431698 → 0x43108c |
| bridge (kandidat za cluster) | shim receiver 111 → (AVCC→Annex-B) → 0x431698 ili 0x43108c sa cluster ctx |

Dekompilacije (privremeno): `/tmp/cpre/d1.c` do `d4.c`.
