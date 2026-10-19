#define _GNU_SOURCE
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SETUP_VA 0x477fd4u
#define SETUP_GOT_VA 0x568f38u
#define ADD_RESPONSE_STREAM_VA 0x472ba4u
#define SERVER_SOCKET_OPEN_VA 0x4cbf54u
#define KEY_STREAMS ((void *)0x52e2a8)
#define KEY_TYPE ((void *)0x52e300)
#define KEY_DATAPORT ((void *)0x52e450)
#define CB_ARRAY_VA ((void *)0x5630e4)
#define CB_DICT_KEY_VA ((void *)0x5630cc)
#define CB_DICT_VAL_VA ((void *)0x5630b8)
#define ALT_SCREEN_TYPE 111

typedef int (*setup_fn)(void *, void *, void **);
typedef int (*add_stream_fn)(void *, void *);
typedef int (*server_socket_open_fn)(int, int, int, int, int *, unsigned, int *);
typedef unsigned long (*type_id_fn)(void);
typedef void *(*dget_typed_fn)(void *, void *, unsigned long, int *);
typedef int64_t (*dget_i64_fn)(void *, void *, int *);
typedef void (*dset_i64_fn)(void *, void *, int64_t);
typedef void (*dset_val_fn)(void *, void *, void *);
typedef void *(*dmk_fn)(void *, long, void *, void *);
typedef void *(*dmkcopy_fn)(void *, long, void *);
typedef void *(*amk_fn)(void *, long, void *);
typedef long (*acount_fn)(void *);
typedef void *(*aat_fn)(void *, long);
typedef void (*aappend_fn)(void *, void *);
typedef void (*release_fn)(void *);

static setup_fn orig_setup = (setup_fn)SETUP_VA;
static add_stream_fn add_response_stream = (add_stream_fn)ADD_RESPONSE_STREAM_VA;
static server_socket_open_fn server_socket_open = (server_socket_open_fn)SERVER_SOCKET_OPEN_VA;
static type_id_fn cf_array_type_id = (type_id_fn)0x4925acu;
static dget_typed_fn cf_dict_get_typed = (dget_typed_fn)0x4a57fcu;
static dget_i64_fn cf_dict_get_int64 = (dget_i64_fn)0x4a5514u;
static dset_i64_fn cf_dict_set_int64 = (dset_i64_fn)0x4a77d0u;
static dset_val_fn cf_dict_set_value = (dset_val_fn)0x493470u;
static dmk_fn cf_dict_create_mutable = (dmk_fn)0x49324cu;
static dmkcopy_fn cf_dict_create_mutable_copy = (dmkcopy_fn)0x4933c4u;
static amk_fn cf_array_create_mutable = (amk_fn)0x492748u;
static acount_fn cf_array_count = (acount_fn)0x4927c0u;
static aat_fn cf_array_at = (aat_fn)0x492814u;
static aappend_fn cf_array_append = (aappend_fn)0x4929b4u;
static release_fn cf_release = (release_fn)0x492528u;
static void *arr_cb = CB_ARRAY_VA, *dict_key_cb = CB_DICT_KEY_VA, *dict_val_cb = CB_DICT_VAL_VA;

#define CLUSTER_STREAM_TYPE 0x6f
#define CLUSTER_UUID "b7e6c5a0-2222-4000-8000-000000000002"
#define CLUSTER_W 1440
#define CLUSTER_H 540

#define K_STREAMS ((void *)0x52105c)
#define K_TYPE ((void *)0x52106c)
#define K_DATAPORT ((void *)0x52107c)
#define K_CONNID ((void *)0x521090)
#define K_UUID ((void *)0x5210ac)
#define K_LATENCYMS ((void *)0x5210bc)
#define S_SETUP ((void *)0x51e0c8)
#define S_URL ((void *)0x520cb4)
#define S_PROTO ((void *)0x51d678)
#define S_MIME ((void *)0x51d6fc)
#define GPEERADDR ((void *)0x56c3e0)
#define GAIRPLAYCLIENT ((void **)0x56abf8)
#define GPAIRVERIFY_HK ((int *)0x56ad70)
#define GSESSION_AESKEY ((void *)0x56ad90)
#define GCONNID_LO ((unsigned *)0x56b378)
#define GCONNID_HI ((unsigned *)0x56b37c)

typedef int (*uuidget_fn)(void *);
typedef int (*httpmk_fn)(void **);
typedef int (*httpinit_fn)(void *, void *, void *, void *);
typedef int (*httpaddf_fn)(void *, void *, void *);
typedef void *(*httpsetbody_fn)(void *, void *, void *, int);
typedef int (*httpsend_fn)(void *, void *);
typedef void (*aensure_fn)(void **, void *);
typedef void *(*plistmk_fn)(void *, int *, int);
typedef void *(*plistrd_fn)(void *, int, int *);
typedef void (*dsetcstr_fn)(void *, void *, void *, unsigned);
typedef void *(*semmk_fn)(int);
typedef void (*semwait_fn)(void *, unsigned long long);
typedef void (*semsig_fn)(void *);
typedef void (*sockcopy_fn)(void *, void *);
typedef void (*sockport_fn)(void *, int);
typedef int (*socksize_fn)(void *);
typedef void (*qos_fn)(int, int);
typedef unsigned long (*typeid_fn)(void);
typedef void *(*aat_typed_fn)(void *, long, unsigned long, int *);
typedef int (*derive_fn)(void *, int, void *, int, void *, int, void *, void *);
typedef void (*aesinit_fn)(void *, void *, void *);
typedef void *(*at_fn)(void *, long);

static uuidget_fn cf_uuidget = (uuidget_fn)0x4ea9b0u;
static httpmk_fn http_create = (httpmk_fn)0x4b953cu;
static httpinit_fn http_init = (httpinit_fn)0x4bc550u;
static httpaddf_fn http_addf = (httpaddf_fn)0x4bcbf0u;
static httpsetbody_fn http_setbody = (httpsetbody_fn)0x4b962cu;
static httpsend_fn http_send = (httpsend_fn)0x4b90d0u;
static aensure_fn cf_arr_ensure = (aensure_fn)0x4a4144u;
static plistmk_fn cf_plist_create = (plistmk_fn)0x49d354u;
static plistrd_fn cf_plist_read = (plistrd_fn)0x49e3e4u;
static dsetcstr_fn cf_dict_set_cstr = (dsetcstr_fn)0x4a49dcu;
static semmk_fn d_sem_create = (semmk_fn)0x4b30b4u;
static semwait_fn d_sem_wait = (semwait_fn)0x4b35fcu;
static semsig_fn d_sem_signal = (semsig_fn)0x4b3208u;
static sockcopy_fn sock_copy = (sockcopy_fn)0x4cd2fcu;
static sockport_fn sock_setport = (sockport_fn)0x4cc6e0u;
static socksize_fn sock_getsize = (socksize_fn)0x4cbb30u;
static qos_fn sock_qos = (qos_fn)0x4caf40u;
static typeid_fn cf_dict_type_id = (typeid_fn)0x493234u;
typedef unsigned long (*gettypeid_fn)(void *);
static gettypeid_fn cf_get_type_id = (gettypeid_fn)0x4924a0u;
static derive_fn aes_derive = (derive_fn)0x42ce68u;
static aesinit_fn aes_ctr_init = (aesinit_fn)0x48b780u;
static at_fn cf_array_at2 = (at_fn)0x492814u;

typedef void (*derive_screen_fn)(void *, int, unsigned, unsigned, void *, void *);
typedef void (*aesctrinit_fn)(void *, void *, void *);
typedef void (*aesupd_fn)(void *, void *, int, void *);
static derive_screen_fn derive_screen = (derive_screen_fn)0x481af0u;
static aesctrinit_fn aesctr_init = (aesctrinit_fn)0x48b780u;
static aesupd_fn aesctr_update = (aesupd_fn)0x48b804u;

typedef int (*streamkeys_fn)(void *, int, unsigned, unsigned, int, void *, void *);
typedef void (*ccinit_fn)(void *, void *, void *);
typedef void (*ccaad_fn)(void *, void *, int);
typedef int (*ccdec_fn)(void *, void *, int, void *);
typedef int (*ccver_fn)(void *, void *, void *, int *);
static streamkeys_fn get_stream_keys = (streamkeys_fn)0x474254u;
static ccinit_fn cc_init = (ccinit_fn)0x4aa770u;
static ccaad_fn cc_aad = (ccaad_fn)0x4aad3cu;
static ccdec_fn cc_dec = (ccdec_fn)0x4aaec0u;
static ccver_fn cc_ver = (ccver_fn)0x4ab124u;
typedef int (*sendcmd_fn)(void *, void *, void *, void *);
static sendcmd_fn session_send_command = (sendcmd_fn)0x474fd0u;
#define K_CMD_PARAMS ((void *)0x52e490)
#define K_CMD_URL ((void *)0x52e558)
#define CLUSTER_MAP_URL "maps:/car/instrumentcluster/map"

static int send_phone_cmd(void *session, const char *type, int with_url) {
  void *req = cf_dict_create_mutable(0, 0, dict_key_cb, dict_val_cb);
  void *params = cf_dict_create_mutable(0, 0, dict_key_cb, dict_val_cb);
  if (!req || !params) return -1;
  cf_dict_set_cstr(req, KEY_TYPE, (void *)type, 0xffffffffu);
  cf_dict_set_cstr(params, K_UUID, (void *)CLUSTER_UUID, 0xffffffffu);
  if (with_url) cf_dict_set_cstr(params, K_CMD_URL, (void *)CLUSTER_MAP_URL, 0xffffffffu);
  cf_dict_set_value(req, K_CMD_PARAMS, params);
  cf_release(params);
  int rc = session_send_command(session, req, 0, 0);
  cf_release(req);
  return rc;
}

static int has_idr(const unsigned char *b, unsigned len) {
  unsigned pos = 0;
  while (pos + 5 <= len) {
    unsigned nlen = (b[pos] << 24) | (b[pos + 1] << 16) | (b[pos + 2] << 8) | b[pos + 3];
    if ((b[pos + 4] & 0x1f) == 5) return 1;
    if (nlen == 0 || pos + 4 + nlen > len) break;
    pos += 4 + nlen;
  }
  return 0;
}

static void *g_cluster_ctx;
static int g_cluster_started;
static int g_push_enabled = 1;
static void *g_session;
static unsigned long long g_conn111;
static int g_have_conn111;
static void *cluster_setup_to_car(void *);

static void dbg(const char *msg, int n) {
  int fd = open("/usr/data/log/altscreen.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd < 0) return;
  write(fd, msg, strlen(msg));
  if (n >= 0) {
    char b[16];
    int l = 0;
    if (n == 0) {
      b[l++] = '0';
    } else {
      char t[16];
      int k = 0, m = n;
      while (m) { t[k++] = '0' + m % 10; m /= 10; }
      while (k) b[l++] = t[--k];
    }
    b[l++] = '\n';
    write(fd, b, l);
  } else {
    write(fd, "\n", 1);
  }
  close(fd);
}

static void dbg_hex(const char *msg, const unsigned char *p, int n) {
  int fd = open("/usr/data/log/altscreen.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd < 0) return;
  write(fd, msg, strlen(msg));
  write(fd, " ", 1);
  if (n > 48) n = 48;
  static const char hx[] = "0123456789abcdef";
  char b[3];
  b[2] = ' ';
  for (int i = 0; i < n; i++) {
    b[0] = hx[p[i] >> 4];
    b[1] = hx[p[i] & 15];
    write(fd, b, 3);
  }
  write(fd, "\n", 1);
  close(fd);
}

static int writeall(int fd, const void *buf, int n) {
  const char *p = (const char *)buf;
  while (n > 0) {
    ssize_t w = send(fd, p, n, MSG_NOSIGNAL);
    if (w <= 0) return -1;
    p += w;
    n -= (int)w;
  }
  return 0;
}

static int send_to_car(int type, unsigned char *body, unsigned len) {
  char *ctx = (char *)g_cluster_ctx;
  unsigned char hdr[128];
  memset(hdr, 0, sizeof hdr);
  *(unsigned *)hdr = len;
  hdr[4] = (unsigned char)type;
  if (type == 1) {
    *(float *)(hdr + 0x10) = (float)CLUSTER_W;
    *(float *)(hdr + 0x14) = (float)CLUSTER_H;
    *(float *)(hdr + 0x28) = (float)CLUSTER_W;
    *(float *)(hdr + 0x2c) = (float)CLUSTER_H;
  }
  pthread_mutex_t *mu = *(pthread_mutex_t **)(ctx + 0x4c);
  pthread_mutex_lock(mu);
  if (type == 0) aesctr_update(ctx + 0x168, body, (int)len, body);
  int fd = *(int *)ctx;
  int rc = writeall(fd, hdr, 128);
  if (rc == 0 && len) rc = writeall(fd, body, (int)len);
  pthread_mutex_unlock(mu);
  return rc;
}

static int readn(int fd, void *buf, int n) {
  char *p = (char *)buf;
  int got = 0;
  while (got < n) {
    ssize_t r = read(fd, p + got, n - got);
    if (r <= 0) return -1;
    got += (int)r;
  }
  return 0;
}

static void *sink_thread(void *arg) {
  int srv = (int)(intptr_t)arg;
  dbg("alt sink thread up", -1);
  int c = accept(srv, 0, 0);
  close(srv);
  if (c < 0) { dbg("alt accept fail", -1); return 0; }
  dbg("alt connected", -1);
  {
    int sr = send_phone_cmd(g_session, "showUI", 1);
    dbg("alt showUI err", sr < 0 ? -sr : sr);
  }

  unsigned char dctx[0x120];
  unsigned char cctx[0x200] __attribute__((aligned(8)));
  unsigned char cckey[32], ccnonce[8];
  int dec_ready = 0, chacha = 0;
  void *pvs = g_session ? *(void **)((char *)g_session + 0x3ec) : 0;
  dbg("alt pairVerifySession set", pvs ? 1 : 0);
  if (pvs && g_have_conn111 && g_conn111 != 0) {
    int rc = get_stream_keys((char *)g_session + 0x3ec, 0,
                             (unsigned)(g_conn111 & 0xffffffffu),
                             (unsigned)(g_conn111 >> 32), 0, 0, cckey);
    dbg("alt chacha keys rc", rc);
    if (rc == 0) {
      memset(ccnonce, 0, sizeof ccnonce);
      dec_ready = 1;
      chacha = 1;
    }
  } else if (g_have_conn111 && g_session && g_conn111 != 0) {
    unsigned char key[16], iv[16];
    derive_screen((char *)g_session + 0x200, 0x10,
                  (unsigned)(g_conn111 & 0xffffffffu),
                  (unsigned)(g_conn111 >> 32), key, iv);
    aesctr_init(dctx, key, iv);
    dec_ready = 1;
    dbg("alt decrypt ready", -1);
  } else {
    dbg("alt no connID", (int)(g_conn111 & 0xffffffffu));
  }

  unsigned char hdr[128];
  unsigned char *body = 0;
  int bodycap = 0;
  long frames = 0, pushed = 0;
  int pushed_cfg = 0, dumped_vid = 0;
  unsigned char *cfg_body = 0;
  unsigned cfg_len = 0;
  int cfg_sent = 0, got_idr = 0, wait_idr = 0, send_failed = 0;
  for (;;) {
    if (readn(c, hdr, 128) != 0) break;
    unsigned bodylen = *(unsigned *)hdr;
    int ftype = hdr[4];
    if (bodylen > 4000000u) { dbg("alt bad bodylen", (int)bodylen); break; }
    frames++;
    if (frames == 1) dbg("alt first frame type", ftype);
    if (bodylen == 0) continue;
    if ((int)bodylen > bodycap) {
      free(body);
      body = (unsigned char *)malloc(bodylen + 16);
      if (!body) { dbg("alt body malloc fail", -1); break; }
      bodycap = bodylen;
    }
    if (readn(c, body, bodylen) != 0) break;
    if (ftype == 0) {
      if (dumped_vid < 2) dbg_hex("alt vid enc", body, 16);
      if (chacha) {
        if (bodylen < 16) continue;
        int err = 0;
        cc_init(cctx, cckey, ccnonce);
        cc_aad(cctx, hdr, 128);
        int n = cc_dec(cctx, body, bodylen - 16, body);
        n += cc_ver(cctx, body + n, body + bodylen - 16, &err);
        for (int k = 0; k < 8 && ++ccnonce[k] == 0; k++) {}
        if (dumped_vid < 2) dbg("alt chacha verify err", err);
        if (err != 0 || n != (int)bodylen - 16) { dbg("alt chacha fail", n); continue; }
        bodylen -= 16;
      } else if (dec_ready) aesctr_update(dctx, body, bodylen, body);
      if (dumped_vid < 2) { dbg_hex("alt vid dec", body, 32); dumped_vid++; }
      if (dec_ready && g_cluster_ctx && g_push_enabled && cfg_body) {
        if (!cfg_sent) {
          if (send_to_car(1, cfg_body, cfg_len) == 0) dbg("alt config sent late", (int)cfg_len);
          cfg_sent = 1;
          got_idr = 0;
          wait_idr = 0;
        }
        if (!got_idr && has_idr(body, bodylen)) { got_idr = 1; dbg("alt idr after frames", wait_idr); }
        if (!got_idr) {
          if ((wait_idr++ % 120) == 0) {
            int kr = send_phone_cmd(g_session, "forceKeyFrame", 0);
            dbg("alt force keyframe err", kr < 0 ? -kr : kr);
          }
          continue;
        }
        if (send_to_car(0, body, bodylen) == 0) pushed++;
        else if (!send_failed) { send_failed = 1; dbg("alt send to car fail", (int)pushed); }
      }
    } else if (ftype == 1) {
      if (pushed_cfg < 3) {
        dbg_hex("alt config hdr", hdr, 48);
        dbg_hex("alt config raw", body, bodylen);
        pushed_cfg++;
      }
      free(cfg_body);
      cfg_body = (unsigned char *)malloc(bodylen);
      if (cfg_body) {
        memcpy(cfg_body, body, bodylen);
        cfg_len = bodylen;
        cfg_sent = 0;
      }
      if (cfg_body && g_cluster_ctx && g_push_enabled) {
        if (send_to_car(1, cfg_body, cfg_len) == 0) { pushed++; dbg("alt config sent", (int)cfg_len); }
        cfg_sent = 1;
        got_idr = 0;
        wait_idr = 0;
      }
    }
    if ((frames % 300) == 0) dbg("alt frames pushed", (int)pushed);
  }
  dbg("alt stream end frames", (int)frames);
  free(body);
  free(cfg_body);
  close(c);
  return 0;
}

static int open_alt_sink(void *session) {
  int family = *(unsigned short *)((char *)session + 0x8c);
  int port = 0, fd = -1;
  int rc = server_socket_open(family, 2, 6, 0, &port, 0xfffd4000u, &fd);
  if (rc != 0 || fd < 0) { dbg("alt ServerSocketOpen rc", rc); return 0; }
  int fl = fcntl(fd, F_GETFL, 0);
  if (fl != -1) fcntl(fd, F_SETFL, fl & ~O_NONBLOCK);
  pthread_t t;
  if (pthread_create(&t, 0, sink_thread, (void *)(intptr_t)fd) != 0) { close(fd); return 0; }
  pthread_detach(t);
  return port;
}

static void *filter_streams(void *req, int *had_alt) {
  *had_alt = 0;
  void *orig = cf_dict_get_typed(req, KEY_STREAMS, cf_array_type_id(), 0);
  if (!orig) return 0;
  long n = cf_array_count(orig);
  dbg("req streams", (int)n);
  void *keep = cf_array_create_mutable(0, 0, arr_cb);
  for (long i = 0; i < n; i++) {
    void *sd = cf_array_at(orig, i);
    int64_t ty = cf_dict_get_int64(sd, KEY_TYPE, 0);
    dbg("req stream type", (int)ty);
    if (ty == ALT_SCREEN_TYPE) {
      *had_alt = 1;
      g_conn111 = (unsigned long long)cf_dict_get_int64(sd, K_CONNID, 0);
      g_have_conn111 = 1;
      {
        unsigned char cb[8];
        for (int k = 0; k < 8; k++) cb[k] = (unsigned char)(g_conn111 >> (k * 8));
        dbg_hex("alt connID", cb, 8);
      }
      continue;
    }
    cf_array_append(keep, sd);
  }
  if (!*had_alt) { cf_release(keep); return 0; }
  void *req2 = cf_dict_create_mutable_copy(0, 0, req);
  cf_dict_set_value(req2, KEY_STREAMS, keep);
  cf_release(keep);
  return req2;
}

int shim_session_setup(void *session, void *req, void **resp_out) {
  int had_alt = 0;
  g_session = session;
  void *req2 = filter_streams(req, &had_alt);
  int rc = orig_setup(session, req2 ? req2 : req, resp_out);
  if (req2) cf_release(req2);
  if (rc != 0 || !had_alt || !resp_out || !*resp_out) return rc;

  int port = open_alt_sink(session);
  if (port <= 0) { dbg("alt sink fail", -1); return rc; }
  void *entry = cf_dict_create_mutable(0, 0, dict_key_cb, dict_val_cb);
  if (!entry) return rc;
  cf_dict_set_int64(entry, KEY_TYPE, ALT_SCREEN_TYPE);
  cf_dict_set_int64(entry, KEY_DATAPORT, port);
  add_response_stream(*resp_out, entry);
  cf_release(entry);
  dbg("alt dataPort", port);
  if (!g_cluster_started) {
    g_cluster_started = 1;
    pthread_t ct;
    if (pthread_create(&ct, 0, cluster_setup_to_car, 0) == 0)
      pthread_detach(ct);
  }
  return rc;
}

static void cluster_response_cb(void *msg) {
  int len = *(int *)((char *)msg + 0x4a0);
  void *bodyp = *(void **)((char *)msg + 0x49c);
  if (len == 0) return;
  int err = 0;
  void *d = cf_plist_read(bodyp, len, &err);
  if (err != 0 || !d) return;
  if (cf_get_type_id(d) == cf_dict_type_id()) {
    void *streams = cf_dict_get_typed(d, K_STREAMS, cf_array_type_id(), 0);
    if (streams) {
      long n = cf_array_count(streams);
      for (long i = 0; i < n; i++) {
        void *sd = cf_array_at2(streams, i);
        if (!sd) continue;
        if (cf_dict_get_int64(sd, K_TYPE, 0) == CLUSTER_STREAM_TYPE) {
          int dp = (int)cf_dict_get_int64(sd, K_DATAPORT, 0);
          void *ctx = *(void **)((char *)msg + 0x8fc);
          *(int *)((char *)ctx + 4) = dp;
          dbg("cluster car dataPort", dp);
          d_sem_signal(*(void **)((char *)ctx + 0x30));
          break;
        }
      }
    }
  }
  cf_release(d);
}

static void *cluster_setup_to_car(void *unused) {
  (void)unused;
  if (*GPAIRVERIFY_HK != 0) { dbg("cluster homekit mode unsupported", -1); return 0; }
  char *ctx = (char *)malloc(0x288);
  if (!ctx) { dbg("cluster malloc fail", -1); return 0; }
  memset(ctx, 0, 0x288);
  *(int *)(ctx + 0) = -1;
  pthread_mutex_init((pthread_mutex_t *)(ctx + 0x34), 0);
  *(void **)(ctx + 0x4c) = ctx + 0x34;
  void *sem = d_sem_create(0);
  *(void **)(ctx + 0x30) = sem;

  void *msg = 0;
  if (http_create(&msg) != 0 || !msg) { dbg("cluster http create fail", -1); return 0; }
  if (http_init((char *)msg + 0x10, S_SETUP, S_URL, S_PROTO) != 0) {
    dbg("cluster http init fail", -1);
    return 0;
  }
  char cseq[16];
  snprintf(cseq, sizeof cseq, "%d", 1);
  http_addf((char *)msg + 0x10, (void *)0x51d698, cseq);

  void *req = cf_dict_create_mutable(0, 0, dict_key_cb, dict_val_cb);
  void *sd = cf_dict_create_mutable(0, 0, dict_key_cb, dict_val_cb);
  if (!req || !sd) { dbg("cluster dict fail", -1); return 0; }

  unsigned char u[16];
  cf_uuidget(u);
  unsigned hi = (u[0] << 24) | (u[1] << 16) | (u[2] << 8) | u[3];
  unsigned lo = (u[4] << 24) | (u[5] << 16) | (u[6] << 8) | u[7];
  *GCONNID_LO = lo;
  *GCONNID_HI = hi;
  unsigned long long connid = ((unsigned long long)hi << 32) | lo;
  cf_dict_set_int64(sd, K_CONNID, (int64_t)connid);
  cf_dict_set_int64(sd, K_TYPE, CLUSTER_STREAM_TYPE);
  cf_dict_set_cstr(sd, K_UUID, (void *)CLUSTER_UUID, 0xffffffffu);
  cf_dict_set_int64(sd, K_LATENCYMS, 0x19);

  void *arr = 0;
  cf_arr_ensure(&arr, sd);
  cf_dict_set_value(req, K_STREAMS, arr);

  int bodylen = 0;
  void *body = cf_plist_create(req, &bodylen, 0);
  if (!body) { dbg("cluster plist fail", -1); return 0; }
  if (http_setbody(msg, S_MIME, body, bodylen) != 0) { dbg("cluster setbody fail", -1); return 0; }
  cf_release(arr);
  cf_release(sd);
  cf_release(req);

  *(void **)((char *)msg + 0x904) = (void *)&cluster_response_cb;
  *(int *)((char *)msg + 0x8f4) = 0;
  *(int *)((char *)msg + 0x8f8) = 0;
  *(void **)((char *)msg + 0x8fc) = ctx;

  dbg("cluster SETUP sent", -1);
  http_send(*GAIRPLAYCLIENT, msg);
  d_sem_wait(sem, ~0ull);
  dbg("cluster SETUP replied", -1);

  int dp = *(int *)(ctx + 4);
  if (dp <= 0) { dbg("cluster no dataPort", -1); return 0; }

  char sa[160];
  memset(sa, 0, sizeof sa);
  sock_copy(GPEERADDR, sa);
  int family = *(unsigned short *)sa;
  int fd = socket(family, SOCK_STREAM, 0);
  if (fd < 0) { dbg("cluster socket fail", -1); return 0; }
  int one = 1;
  setsockopt(fd, 0xffff, 4, &one, 4);
  if (family == 10) setsockopt(fd, 0x29, 0x1a, &one, 4);
  sock_qos(fd, 0xc);
  sock_setport(sa, dp);
  int slen = sock_getsize(sa);
  int tries = 21, ok = 0;
  while (tries-- > 0) {
    if (connect(fd, (struct sockaddr *)sa, slen) == 0) { ok = 1; break; }
    usleep(100000);
  }
  if (!ok) { dbg("cluster connect fail", -1); close(fd); return 0; }
  dbg("cluster connected to car", dp);

  char ks[48], is[48];
  snprintf(ks, sizeof ks, "%s%llu", "AirPlayStreamKey", connid);
  snprintf(is, sizeof is, "%s%llu", "AirPlayStreamIV", connid);
  aes_derive(GSESSION_AESKEY, 0x10, ks, (int)strlen(ks), is, (int)strlen(is),
             ctx + 0x10, ctx + 0x20);
  aes_ctr_init(ctx + 0x168, ctx + 0x10, ctx + 0x20);

  *(int *)(ctx + 0xc) = 1;
  *(int *)(ctx + 0) = fd;
  g_cluster_ctx = ctx;
  dbg("cluster ctx ready", -1);
  return 0;
}

__attribute__((constructor)) static void init(void) {
  void **got = (void **)SETUP_GOT_VA;
  if (*got == (void *)SETUP_VA) {
    *got = (void *)&shim_session_setup;
    dbg("altscreen shim installed", -1);
  } else {
    dbg("altscreen GOT mismatch", -1);
  }
}
