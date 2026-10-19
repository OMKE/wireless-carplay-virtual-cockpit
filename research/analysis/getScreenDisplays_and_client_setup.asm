[2K            ; CALL XREF from sym.airPlayGetProperty @ 0x43f194
┌ sym._getScreenDisplays(int32_t arg1);
│           ; arg int32_t arg1 @ a0
│           ; var int32_t var_48h @ stack - 0x48
│           ; var int32_t var_44h @ stack - 0x44
│           ; var int32_t var_40h @ stack - 0x40
│           ; var int32_t var_3ch @ stack - 0x3c
│           ; var int32_t var_38h @ stack - 0x38
│           ; var int32_t var_30h @ stack - 0x30
│           ; var int32_t var_28h @ stack - 0x28
│           ; var int32_t var_1ch @ stack - 0x1c
│           ; var int32_t var_18h @ stack - 0x18
│           ; var int32_t var_14h @ stack - 0x14
│           ; var int32_t var_10h @ stack - 0x10
│           ; var int32_t var_ch @ stack - 0xc
│           ; var int32_t var_8h @ stack - 0x8
│           ; var int32_t var_4h @ stack - 0x4
│           0x0043dcfc      lui   gp, 0x13
│           0x0043dd00      addiu gp, gp, 0x2f34
│           0x0043dd04      addu  gp, gp, t9
│           0x0043dd08      addiu sp, sp, -0x58
│           0x0043dd0c      sw    s1, (var_18h)
│           0x0043dd10      move  s1, a0                               ; arg1
│           0x0043dd14      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043dd18      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043dd1c      sw    ra, (var_4h)
│           0x0043dd20      sw    s5, (var_8h)
│           0x0043dd24      sw    s4, (var_ch)
│           0x0043dd28      sw    s3, (var_10h)
│           0x0043dd2c      sw    s2, (var_14h)
│           0x0043dd30      sw    s0, (var_1ch)
│           0x0043dd34      sw    gp, (var_30h)
│           0x0043dd38      sw    zero, (var_28h)
│           0x0043dd3c      move  a1, zero
│           0x0043dd40      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043dd44      addiu a0, a0, -0x4300                      ; str.HAVE_KNOB
│                                                                      ; 0x51bd00 ; "HAVE_KNOB" ; arg1
│           0x0043dd48      lw    gp, (var_30h)
│           0x0043dd4c      move  a1, zero
│           0x0043dd50      addiu s0, zero, 2
│           0x0043dd54      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043dd58      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043dd5c      movz  s0, zero, v0
│           0x0043dd60      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043dd64      addiu a0, a0, -0x42c8                      ; str.HIFI_TOUCH
│                                                                      ; 0x51bd38 ; "HIFI_TOUCH" ; arg1
│           0x0043dd68      lw    gp, (var_30h)
│           0x0043dd6c      ori   v1, s0, 8
│           0x0043dd70      move  a1, zero
│           0x0043dd74      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043dd78      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043dd7c      movn  s0, v1, v0
│           0x0043dd80      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043dd84      addiu a0, a0, -0x42bc                      ; str.LOFI_TOUCH
│                                                                      ; 0x51bd44 ; "LOFI_TOUCH" ; arg1
│           0x0043dd88      lw    gp, (var_30h)
│           0x0043dd8c      ori   v1, s0, 4
│           0x0043dd90      move  a1, zero
│           0x0043dd94      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043dd98      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043dd9c      movn  s0, v1, v0
│           0x0043dda0      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043dda4      addiu a0, a0, 0x2f1c                       ; str.HAVE_TOUCHPAD
│                                                                      ; 0x522f1c ; "HAVE_TOUCHPAD" ; arg1
│           0x0043dda8      lw    gp, (var_30h)
│           0x0043ddac      ori   v1, s0, 0x10
│           0x0043ddb0      addiu a1, zero, 0x14
│           0x0043ddb4      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043ddb8      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043ddbc      movn  s0, v1, v0
│           0x0043ddc0      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043ddc4      addiu a0, a0, 0x2f2c                       ; str.VIDEO_FPS
│                                                                      ; 0x522f2c ; "VIDEO_FPS" ; arg1
│           0x0043ddc8      lw    gp, (var_30h)
│           0x0043ddcc      addiu a1, zero, 0x320
│           0x0043ddd0      move  s2, v0
│           0x0043ddd4      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043ddd8      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043dddc      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043dde0      addiu a0, a0, -0x4268                      ; str.VIDEO_WIDTH
│                                                                      ; 0x51bd98 ; "VIDEO_WIDTH" ; arg1
│           0x0043dde4      lw    gp, (var_30h)
│           0x0043dde8      addiu a1, zero, 0x1e0
│           0x0043ddec      move  s3, v0
│           0x0043ddf0      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043ddf4      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043ddf8      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043ddfc      addiu a0, a0, -0x4258                      ; str.VIDEO_HEIGHT
│                                                                      ; 0x51bda8 ; "VIDEO_HEIGHT" ; arg1
│           0x0043de00      lw    gp, (var_30h)
│           0x0043de04      addiu a1, zero, 0x9a
│           0x0043de08      move  s4, v0
│           0x0043de0c      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043de10      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043de14      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043de18      addiu a0, a0, -0x4224                      ; str.SCREEN_WIDTH_MM
│                                                                      ; 0x51bddc ; "SCREEN_WIDTH_MM" ; arg1
│           0x0043de1c      lw    gp, (var_30h)
│           0x0043de20      addiu a1, zero, 0x57
│           0x0043de24      move  s5, v0
│           0x0043de28      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043de2c      lw    t9, -sym.imp.ark_get_info_int(gp)    ; [0x56a85c:4]=0x51a0d0 sym.imp.ark_get_info_int
│           0x0043de30      jalr  t9                                   ; sym.imp.ark_get_info_int
│                                                                      ; 0x51a0d0
│           0x0043de34      addiu a0, a0, -0x4210                      ; str.SCREEN_HEIGHT_MM
│                                                                      ; 0x51bdf0 ; "SCREEN_HEIGHT_MM" ; arg1
│           0x0043de38      lw    gp, (var_30h)
│           0x0043de3c      sw    s5, (var_3ch)
│           0x0043de40      sw    s4, (var_40h)
│           0x0043de44      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
│           0x0043de48      lw    t9, -sym.AirPlayInfoArrayAddScreenDisplay(gp) ; [0x56960c:4]=0x47e910 sym.AirPlayInfoArrayAddScreenDisplay
│           0x0043de4c      sw    s3, (var_44h)
│           0x0043de50      sw    s2, (var_48h)
│           0x0043de54      move  a2, s0
│           0x0043de58      addiu a0, sp, 0x30
│           0x0043de5c      sw    v0, (var_38h)
│           0x0043de60      move  a3, zero
│           0x0043de64      jalr  t9                                   ; sym.AirPlayInfoArrayAddScreenDisplay
│                                                                      ; 0x47e910
│           0x0043de68      addiu a1, a1, 0x30d8                       ; 0x5230d8
│           0x0043de6c      lw    ra, (var_4h)
│           0x0043de70      lw    v0, (var_28h)
│           0x0043de74      lw    s5, (var_8h)
│           0x0043de78      lw    s4, (var_ch)
│           0x0043de7c      lw    s3, (var_10h)
│           0x0043de80      lw    s2, (var_14h)
│           0x0043de84      lw    s0, (var_1ch)
│           0x0043de88      sw    zero, (s1)
│           0x0043de8c      lw    s1, (var_18h)
└           0x0043de90      jr    ra
===== CLIENT SETUP BUILDER 0x427c34 =====
│           0x00427c34      jr    ra
└           0x00427c38      addiu sp, sp, 0x80
            ; DATA XREF from sym.AirplayClientSendCmdSetup @ 0x42a71c
            0x00427c3c      lui   gp, 0x15
            0x00427c40      addiu gp, gp, -0x700c
            0x00427c44      addu  gp, gp, t9
            0x00427c48      lw    t9, -sym.HTTPMessageCreate(gp)       ; [0x569254:4]=0x4b953c sym.HTTPMessageCreate
            0x00427c4c      addiu sp, sp, -0x1f8
            0x00427c50      sw    gp, 0x20(sp)
            0x00427c54      sw    ra, 0x1f4(sp)
            0x00427c58      sw    s4, 0x1f0(sp)
            0x00427c5c      sw    s3, 0x1ec(sp)
            0x00427c60      sw    s2, 0x1e8(sp)
            0x00427c64      sw    s1, 0x1e4(sp)
            0x00427c68      sw    s0, 0x1e0(sp)
            0x00427c6c      sw    zero, 0x1dc(sp)
            0x00427c70      sw    zero, 0x1d8(sp)
            0x00427c74      sw    zero, 0x1c8(sp)
            0x00427c78      sw    zero, 0x1cc(sp)
            0x00427c7c      sw    zero, 0x1d0(sp)
            0x00427c80      sw    zero, 0x1d4(sp)
            0x00427c84      jalr  t9                                   ; sym.HTTPMessageCreate
                                                                       ; 0x4b953c
            0x00427c88      addiu a0, sp, 0x1dc
        ┌─< 0x00427c8c      beqz  v0, 0x427cac
        │   0x00427c90      lw    gp, 0x20(sp)
        │   0x00427c94      lw    v1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
        │   0x00427c98      sw    zero, 0x18(sp)
        │   0x00427c9c      addiu v1, v1, -0x660                       ; str.AirplayClientSendCmdSetup
        │                                                              ; 0x51f9a0 ; "_AirplayClientSendCmdSetup"
        │   0x00427ca0      sw    v1, 0x14(sp)
       ┌──< 0x00427ca4      b     0x427cf0
       ││   0x00427ca8      addiu v1, zero, 0x672
       │└─> 0x00427cac      lw    a3, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427cb0      lw    a2, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427cb4      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427cb8      lw    a0, class.AoaService(sp)
       │    0x00427cbc      lw    t9, -sym.HTTPHeader_InitRequest(gp)  ; [0x569258:4]=0x4bc550 sym.HTTPHeader_InitRequest
       │    0x00427cc0      addiu a3, a3, -0x2988                      ; str.RTSP_1.0
       │                                                               ; 0x51d678 ; "RTSP/1.0"
       │    0x00427cc4      addiu a2, a2, -0x2918                      ; 0x51d6e8 ; "/"
       │    0x00427cc8      addiu a1, a1, -0x1f38                      ; str.SETUP
       │                                                               ; 0x51e0c8 ; "SETUP"
       │    0x00427ccc      jalr  t9                                   ; sym.HTTPHeader_InitRequest
       │                                                               ; 0x4bc550
       │    0x00427cd0      addiu a0, a0, 0x10
       │┌─< 0x00427cd4      beqz  v0, 0x427d08
       ││   0x00427cd8      lw    gp, 0x20(sp)
       ││   0x00427cdc      lw    v1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       ││   0x00427ce0      sw    zero, 0x18(sp)
       ││   0x00427ce4      addiu v1, v1, -0x660                       ; str.AirplayClientSendCmdSetup
       ││                                                              ; 0x51f9a0 ; "_AirplayClientSendCmdSetup"
       ││   0x00427ce8      sw    v1, 0x14(sp)
       ││   0x00427cec      addiu v1, zero, 0x675
       ││   ; CODE XREF from sym.timingSockInit @ +0x1c8
       └──> 0x00427cf0      lw    a3, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
        │   0x00427cf4      sw    v1, 0x10(sp)
        │   0x00427cf8      move  a2, zero
        │   0x00427cfc      addiu a3, a3, -0x2a00                      ; str.home_cxt_project_sdDongle_linux_reverseLink_carplay_32017_src_PlatformPOSIX_.._FakeCarplay_carplay_wl_proxy_client.c
        │                                                              ; 0x51d600 ; "/home/cxt/project/sdDongle_linux/reverseLink/carplay-32017/src/PlatformPOSIX/../FakeCarplay/carplay_wl_proxy_client.c"
       ┌──< 0x00427d00      b     0x427d7c
       ││   0x00427d04      move  a1, v0
       │└─> 0x00427d08      lw    a2, -0x7f54(gp)                      ; [0x568cdc:4]=0x530000 "yController [%p]."
       │    0x00427d0c      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427d10      lw    a0, class.AoaService(sp)
       │    0x00427d14      lw    t9, -sym.HTTPHeader_AddFieldF(gp)    ; [0x568d30:4]=0x4bcbf0 sym.HTTPHeader_AddFieldF
       │    0x00427d18      addiu a2, a2, -0x55b0                      ; 0x52aa50 ; "1"
       │    0x00427d1c      addiu a1, a1, -0x2968                      ; str.CSeq
       │                                                               ; 0x51d698 ; "CSeq"
       │    0x00427d20      jalr  t9                                   ; sym.HTTPHeader_AddFieldF
       │                                                               ; 0x4bcbf0
       │    0x00427d24      addiu a0, a0, 0x10
       │    0x00427d28      lw    gp, 0x20(sp)
       │    0x00427d2c      move  a1, zero
       │    0x00427d30      lw    t9, -sym.CFDictionaryCreateMutable(gp) ; [0x568e10:4]=0x49324c sym.CFDictionaryCreateMutable
       │    0x00427d34      lw    a3, -obj.kCFLDictionaryValueCallBacksCFLTypes(gp) ; [0x568e14:4]=0x5630b8 obj.kCFLDictionaryValueCallBacksCFLTypes
       │    0x00427d38      lw    a2, -obj.kCFLDictionaryKeyCallBacksCFLTypes(gp) ; [0x568e18:4]=0x5630cc obj.kCFLDictionaryKeyCallBacksCFLTypes
       │    0x00427d3c      jalr  t9                                   ; sym.CFDictionaryCreateMutable
       │                                                               ; 0x49324c
       │    0x00427d40      move  a0, zero
       │    0x00427d44      move  s0, v0
       │    0x00427d48      bnez  v0, 0x427d90
       │    0x00427d4c      lw    gp, 0x20(sp)
       │    0x00427d50      lw    v0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427d54      lw    a3, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427d58      lw    a2, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
       │    0x00427d5c      addiu v0, v0, -0x660                       ; str.AirplayClientSendCmdSetup
       │                                                               ; 0x51f9a0 ; "_AirplayClientSendCmdSetup"
       │    0x00427d60      sw    v0, 0x14(sp)
       │    0x00427d64      addiu v0, zero, 0x679
       │    0x00427d68      sw    zero, 0x18(sp)
       │    0x00427d6c      sw    v0, 0x10(sp)
       │    0x00427d70      addiu a3, a3, -0x2a00                      ; str.home_cxt_project_sdDongle_linux_reverseLink_carplay_32017_src_PlatformPOSIX_.._FakeCarplay_carplay_wl_proxy_client.c
       │                                                               ; 0x51d600 ; "/home/cxt/project/sdDongle_linux/reverseLink/carplay-32017/src/PlatformPOSIX/../FakeCarplay/carplay_wl_proxy_client.c"
       │    0x00427d74      addiu a2, a2, -0x1f30                      ; str.setupInfo
       │                                                               ; 0x51e0d0 ; "setupInfo"
       │    0x00427d78      move  a1, zero
       │    ; CODE XREF from sym.timingSockInit @ +0x224
       └──> 0x00427d7c      lw    t9, -sym.DebugPrintAssert(gp)        ; [0x568cd8:4]=0x4b0af0 sym.DebugPrintAssert
            0x00427d80      jalr  t9                                   ; sym.DebugPrintAssert
                                                                       ; 0x4b0af0
            0x00427d84      move  a0, zero
            0x00427d88      b     0x4283ec
            0x00427d8c      lw    gp, 0x20(sp)
            0x00427d90      lw    s2, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427d94      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427d98      lw    t9, -sym.imp.ark_get_info_string(gp) ; [0x56a770:4]=0x51a480 sym.imp.ark_get_info_string
            0x00427d9c      addiu a1, s2, -0x34c4                      ; str.12:13:23:aa:ca:ba
                                                                       ; 0x51cb3c ; "12:13:23:aa:ca:ba"
            0x00427da0      jalr  t9                                   ; sym.imp.ark_get_info_string
                                                                       ; 0x51a480
            0x00427da4      addiu a0, a0, -0x3fd8                      ; str.DEVID
                                                                       ; 0x51c028 ; "DEVID"
            0x00427da8      lw    gp, 0x20(sp)
            0x00427dac      addiu a3, zero, -1
            0x00427db0      move  a2, v0
            0x00427db4      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427db8      lw    t9, -sym.CFDictionarySetCString(gp)  ; [0x568e1c:4]=0x4a49dc sym.CFDictionarySetCString
            0x00427dbc      move  a0, s0
            0x00427dc0      jalr  t9                                   ; sym.CFDictionarySetCString
                                                                       ; 0x4a49dc ; "\r"
            0x00427dc4      addiu a1, a1, -0xb9c                       ; 0x51f464
            0x00427dc8      lw    gp, 0x20(sp)
            0x00427dcc      addiu s1, sp, 0x128
            0x00427dd0      lw    t9, -sym.SHA1_Init_compat(gp)        ; [0x569354:4]=0x4ddc64 sym.SHA1_Init_compat
            0x00427dd4      jalr  t9                                   ; sym.SHA1_Init_compat
                                                                       ; 0x4ddc64 ; "%\U00000010"
            0x00427dd8      move  a0, s1
            0x00427ddc      lw    gp, 0x20(sp)
            0x00427de0      move  a0, s1
            0x00427de4      addiu a2, zero, 7
            0x00427de8      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427dec      lw    t9, -sym.SHA1_Update_compat(gp)      ; [0x569358:4]=0x4ddcbc sym.SHA1_Update_compat
            0x00427df0      jalr  t9                                   ; sym.SHA1_Update_compat
                                                                       ; 0x4ddcbc ; "\t"
            0x00427df4      addiu a1, a1, -0x1f24                      ; str.AES_KEY
                                                                       ; 0x51e0dc ; "AES-KEY"
            0x00427df8      lw    gp, 0x20(sp)
            0x00427dfc      addiu a2, zero, 0x20
            0x00427e00      lw    t9, -sym.SHA1_Update_compat(gp)      ; [0x569358:4]=0x4ddcbc sym.SHA1_Update_compat
            0x00427e04      lw    a1, -obj.gSimSharedSecret(gp)        ; [0x56935c:4]=0x56c418 obj.gSimSharedSecret
            0x00427e08      jalr  t9                                   ; sym.SHA1_Update_compat
                                                                       ; 0x4ddcbc ; "\t"
            0x00427e0c      move  a0, s1
            0x00427e10      lw    gp, 0x20(sp)
            0x00427e14      lw    t9, -sym.SHA1_Final_compat(gp)       ; [0x569360:4]=0x4dddfc sym.SHA1_Final_compat
            0x00427e18      lw    a0, -obj.sessionAesKey(gp)           ; [0x569364:4]=0x56ad90 obj.sessionAesKey
            0x00427e1c      jalr  t9                                   ; sym.SHA1_Final_compat
                                                                       ; 0x4dddfc ; "\t"
            0x00427e20      move  a1, s1
            0x00427e24      lw    gp, 0x20(sp)
            0x00427e28      lw    t9, -sym.SHA1_Init_compat(gp)        ; [0x569354:4]=0x4ddc64 sym.SHA1_Init_compat
            0x00427e2c      jalr  t9                                   ; sym.SHA1_Init_compat
                                                                       ; 0x4ddc64 ; "%\U00000010"
            0x00427e30      move  a0, s1
            0x00427e34      lw    gp, 0x20(sp)
            0x00427e38      move  a0, s1
            0x00427e3c      addiu a2, zero, 6
            0x00427e40      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427e44      lw    t9, -sym.SHA1_Update_compat(gp)      ; [0x569358:4]=0x4ddcbc sym.SHA1_Update_compat
            0x00427e48      jalr  t9                                   ; sym.SHA1_Update_compat
                                                                       ; 0x4ddcbc ; "\t"
            0x00427e4c      addiu a1, a1, -0x1f1c                      ; str.AES_IV
                                                                       ; 0x51e0e4 ; "AES-IV"
            0x00427e50      lw    gp, 0x20(sp)
            0x00427e54      addiu a2, zero, 0x20
            0x00427e58      lw    t9, -sym.SHA1_Update_compat(gp)      ; [0x569358:4]=0x4ddcbc sym.SHA1_Update_compat
            0x00427e5c      lw    a1, -obj.gSimSharedSecret(gp)        ; [0x56935c:4]=0x56c418 obj.gSimSharedSecret
            0x00427e60      jalr  t9                                   ; sym.SHA1_Update_compat
                                                                       ; 0x4ddcbc ; "\t"
            0x00427e64      move  a0, s1
            0x00427e68      lw    gp, 0x20(sp)
            0x00427e6c      move  a1, s1
            0x00427e70      lw    t9, -sym.SHA1_Final_compat(gp)       ; [0x569360:4]=0x4dddfc sym.SHA1_Final_compat
            0x00427e74      lw    a0, -obj.sessionAesIV(gp)            ; [0x569368:4]=0x56ad7c obj.sessionAesIV
            0x00427e78      jalr  t9                                   ; sym.SHA1_Final_compat
                                                                       ; 0x4dddfc ; "\t"
            0x00427e7c      addiu s1, sp, 0x1c8
            0x00427e80      lw    gp, 0x20(sp)
            0x00427e84      move  a3, s1
            0x00427e88      lw    t9, -sym.AES_CTR_Update(gp)          ; [0x56936c:4]=0x48b804 sym.AES_CTR_Update
            0x00427e8c      lw    a1, -obj.sessionAesKey(gp)           ; [0x569364:4]=0x56ad90 obj.sessionAesKey
            0x00427e90      lw    a0, -obj.gSimAesCtx(gp)              ; [0x569370:4]=0x56c68c obj.gSimAesCtx
            0x00427e94      jalr  t9                                   ; sym.AES_CTR_Update
                                                                       ; 0x48b804
            0x00427e98      addiu a2, zero, 0x10
            0x00427e9c      beqz  v0, 0x427eb8
            0x00427ea0      lw    gp, 0x20(sp)
            0x00427ea4      lw    t9, -sym.AES_CTR_Final(gp)           ; [0x569374:4]=0x48ba9c sym.AES_CTR_Final
            0x00427ea8      lw    a0, -obj.gSimAesCtx(gp)              ; [0x569370:4]=0x56c68c obj.gSimAesCtx
            0x00427eac      jalr  t9                                   ; sym.AES_CTR_Final
                                                                       ; 0x48ba9c
            0x00427eb0      nop
            0x00427eb4      lw    gp, 0x20(sp)
            0x00427eb8      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427ebc      lw    t9, -sym.CFDictionarySetData(gp)     ; [0x569378:4]=0x4a5148 sym.CFDictionarySetData
            0x00427ec0      lw    a2, -obj.sessionAesIV(gp)            ; [0x569368:4]=0x56ad7c obj.sessionAesIV
            0x00427ec4      addiu a3, zero, 0x14
            0x00427ec8      addiu a1, a1, -0xb0c                       ; 0x51f4f4
            0x00427ecc      jalr  t9                                   ; sym.CFDictionarySetData
                                                                       ; 0x4a5148 ; "\r"
            0x00427ed0      move  a0, s0
            0x00427ed4      lw    gp, 0x20(sp)
            0x00427ed8      move  a2, s1
            0x00427edc      addiu a3, zero, 0x10
            0x00427ee0      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427ee4      lw    t9, -sym.CFDictionarySetData(gp)     ; [0x569378:4]=0x4a5148 sym.CFDictionarySetData
            0x00427ee8      move  a0, s0
            0x00427eec      jalr  t9                                   ; sym.CFDictionarySetData
                                                                       ; 0x4a5148 ; "\r"
            0x00427ef0      addiu a1, a1, -0xb00                       ; 0x51f500
            0x00427ef4      lw    gp, 0x20(sp)
            0x00427ef8      addiu a2, zero, 0x10
            0x00427efc      move  a3, zero
            0x00427f00      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427f04      lw    t9, -sym.CFDictionarySetInt64(gp)    ; [0x568e20:4]=0x4a77d0 sym.CFDictionarySetInt64
            0x00427f08      move  a0, s0
            0x00427f0c      jalr  t9                                   ; sym.CFDictionarySetInt64
                                                                       ; 0x4a77d0 ; "\r"
            0x00427f10      addiu a1, a1, -0xaf0                       ; 0x51f510
            0x00427f14      lw    gp, 0x20(sp)
            0x00427f18      addiu a1, s2, -0x34c4                      ; str.12:13:23:aa:ca:ba
                                                                       ; 0x51cb3c ; "12:13:23:aa:ca:ba"
            0x00427f1c      addiu s1, sp, 0x1a8
            0x00427f20      lw    a0, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427f24      lw    t9, -sym.imp.ark_get_info_string(gp) ; [0x56a770:4]=0x51a480 sym.imp.ark_get_info_string
            0x00427f28      jalr  t9                                   ; sym.imp.ark_get_info_string
                                                                       ; 0x51a480
            0x00427f2c      addiu a0, a0, -0x3fc8                      ; str.BTMAC
                                                                       ; 0x51c038 ; "BTMAC"
            0x00427f30      lw    gp, 0x20(sp)
            0x00427f34      addiu a3, zero, -1
            0x00427f38      move  a2, v0
            0x00427f3c      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427f40      lw    t9, -sym.CFDictionarySetCString(gp)  ; [0x568e1c:4]=0x4a49dc sym.CFDictionarySetCString
            0x00427f44      move  a0, s0
            0x00427f48      jalr  t9                                   ; sym.CFDictionarySetCString
                                                                       ; 0x4a49dc ; "\r"
            0x00427f4c      addiu a1, a1, -0xae4                       ; 0x51f51c
            0x00427f50      lw    gp, 0x20(sp)
            0x00427f54      addiu a3, zero, -1
            0x00427f58      move  a0, s0
            0x00427f5c      lw    a2, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427f60      lw    a1, -0x7fd4(gp)                      ; [0x568c5c:4]=0x520000
            0x00427f64      lw    t9, -sym.CFDictionarySetCString(gp)  ; [0x568e1c:4]=0x4a49dc sym.CFDictionarySetCString
            0x00427f68      addiu a2, a2, -0x1f14                      ; str.iPhone12_1
                                                                       ; 0x51e0ec ; "iPhone12,1"
            0x00427f6c      jalr  t9                                   ; sym.CFDictionarySetCString
                                                                       ; 0x4a49dc ; "\r"
            0x00427f70      addiu a1, a1, -0xad0                       ; 0x51f530
            0x00427f74      lw    gp, 0x20(sp)
            0x00427f78      move  a0, s1
