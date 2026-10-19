/* === CarplayReverseSessionNotifyCarplayInfoCB @ 00419640 === */

/* CarplayReverseSessionNotifyCarplayInfoCB(ReverseCarplayInfo const*, void*) */

void CarplayReverseSessionNotifyCarplayInfoCB(ReverseCarplayInfo *param_1,void *param_2)

{
  FakeCarplay::CarplayReverseSessionNotifyCarplayInfo(param_2,param_1);
  return;
}



/* === CarplayReverseSessionNotifyCarplayInfo @ 0041b564 === */

/* FakeCarplay::CarplayReverseSessionNotifyCarplayInfo(ReverseCarplayInfo const*) */

void __thiscall
FakeCarplay::CarplayReverseSessionNotifyCarplayInfo(FakeCarplay *this,ReverseCarplayInfo *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined1 auStack_1d0 [128];
  undefined1 auStack_150 [128];
  undefined1 auStack_d0 [128];
  undefined1 auStack_50 [32];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar4 = PTR_stderr_0056a674;
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)PTR_stderr_0056a674,PTR_s__0051fff8_8_00568c5c + -0x4da8,
             PTR_s__0051fff8_8_00568c5c + -0x3ce4,0x350);
  (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
  (*(code *)PTR_memset_0056a728)(auStack_d0,0,0x80);
  (*(code *)PTR_memset_0056a728)(auStack_150,0,0x80);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  (*(code *)PTR_memset_0056a728)(auStack_1d0,0,0x80);
  ark_get_video_parameters(this + 0x1b8,this + 0x1bc,this + 0x1c8);
  (*(code *)PTR_memcpy_0056aa64)(this + 300,param_1,0x8c);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar4,PTR_s__0051fff8_8_00568c5c + -0x48f0,
             *(undefined4 *)(this + 0x1b8),*(undefined4 *)(this + 0x1bc));
  (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
  iVar2 = *(int *)(this + 0x1b8);
  iVar3 = *(int *)(this + 0x1bc);
  if (iVar2 * iVar3 < 0x1fa401) {
    *(int *)(this + 0x1c4) = iVar3;
    *(int *)(this + 0x1c0) = iVar2;
  }
  else {
    if (iVar3 < iVar2) {
      if (iVar3 == 0) {
        trap(7);
      }
      *(int *)(this + 0x1c4) = iVar3;
      *(int *)(this + 0x1c0) = 0x1fa400 / iVar3;
    }
    else {
      if (iVar2 == 0) {
        trap(7);
      }
      *(int *)(this + 0x1c0) = iVar2;
      *(int *)(this + 0x1c4) = 0x1fa400 / iVar2;
    }
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar4,PTR_s__0051fff8_8_00568c5c + -0x48d8,
               *(undefined4 *)(this + 0x1c0),*(undefined4 *)(this + 0x1c4));
    (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
  }
  iVar2 = (*(code *)PTR_process_is_launcher_0056a734)(PTR_s__0051fff8_8_00568c5c + -0x49e4);
  if ((iVar2 == 0) && (this[0x101] != (FakeCarplay)0x0)) {
    (*(code *)PTR_memset_0056a728)(auStack_50,0,0x20);
    (*(code *)PTR_fputs_0056a93c)(PTR_s__0051fff8_8_00568c5c + -0x473c,*(undefined4 *)puVar4);
    (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x472c,0);
    (*(code *)PTR_sprintf_0056aa10)
              (auStack_50,PTR_s__0051fff8_8_00568c5c + -0x4710,*(undefined4 *)(this + 0x1c0),
               *(undefined4 *)(this + 0x1c4));
    (*(code *)PTR_system_0056a670)(auStack_50);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x49d8,1);
  }
  (*(code *)PTR_prop_get_string_0056a97c)(PTR_s__0051fff8_8_00568c5c + -0x48b0,auStack_d0);
  (*(code *)PTR_prop_get_string_0056a97c)(PTR_s__0051fff8_8_00568c5c + -0x488c,auStack_150);
  (*(code *)PTR_prop_get_string_0056a97c)(PTR_s__0051fff8_8_00568c5c + -0x4864,&local_30);
  (*(code *)PTR_prop_get_string_0056a97c)(PTR_s__0051fff8_8_00568c5c + -0x483c,auStack_1d0);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar4,PTR_s__0051fff8_8_00568c5c + -0x4814,auStack_d0,auStack_150,
             &local_30);
  (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
  iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_d0,PTR_s__0051fff8_8_00568c5c + -0x47ec);
  puVar1 = PTR_s__0051fff8_8_00568c5c;
  if (((((iVar2 == 0) ||
        (iVar2 = (*(code *)PTR_strstr_0056ab38)(&local_30,PTR_s__0051fff8_8_00568c5c + -0x47e4),
        iVar2 == 0)) ||
       ((iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_150,PTR_s__0051fff8_8_00568c5c + -0x47dc),
        iVar2 == 0 &&
        (iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_150,PTR_s__0051fff8_8_00568c5c + -0x47d0),
        iVar2 == 0)))) &&
      (((iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_d0,PTR_s__0051fff8_8_00568c5c + -0x4788),
        iVar2 == 0 ||
        (iVar2 = (*(code *)PTR_strstr_0056ab38)(&local_30,PTR_s__0051fff8_8_00568c5c + -0x2564),
        iVar2 == 0)) ||
       (iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_150,PTR_s__0051fff8_8_00568c5c + -0x477c),
       iVar2 == 0)))) &&
     ((iVar2 = (*(code *)PTR_strstr_0056ab38)(auStack_1d0,PTR_s__0051fff8_8_00568c5c + -0x4778),
      iVar2 == 0 ||
      ((iVar2 = (*(code *)PTR_strstr_0056ab38)(&local_30,PTR_s__0051fff8_8_00568c5c + -0x4768),
       iVar2 == 0 &&
       (iVar2 = (*(code *)PTR_strstr_0056ab38)(&local_30,PTR_s__0051fff8_8_00568c5c + -0x47e4),
       iVar2 == 0)))))) {
    iVar2 = (*(code *)PTR_prop_get_int_0056abb0)(puVar1 + -0x47c4,0);
    if (iVar2 != 1) {
      return;
    }
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x47c4,0);
    (*(code *)PTR_fputs_0056a93c)(PTR_s__0051fff8_8_00568c5c + -0x475c,*(undefined4 *)puVar4);
    uVar5 = *(undefined4 *)puVar4;
    puVar4 = (undefined *)0xa;
    pcVar6 = (code *)PTR_fputc_0056aa7c;
  }
  else {
    iVar2 = (*(code *)PTR_prop_get_int_0056abb0)(puVar1 + -0x47c4,0);
    if (iVar2 != 0) {
      return;
    }
    (*(code *)PTR_fputs_0056a93c)(PTR_s__0051fff8_8_00568c5c + -0x47a8,*(undefined4 *)puVar4);
    (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar4);
    uVar5 = 1;
    puVar4 = PTR_s__0051fff8_8_00568c5c + -0x47c4;
    pcVar6 = (code *)PTR_prop_set_int_0056a9e4;
  }
  (*pcVar6)(puVar4,uVar5);
  return;
}



/* === wlCarplayGetHuInfoProc @ 0041be64 === */

/* FakeCarplay::wlCarplayGetHuInfoProc() */

void __thiscall FakeCarplay::wlCarplayGetHuInfoProc(FakeCarplay *this)

{
  undefined *puVar1;
  
  puVar1 = PTR_stderr_0056a674;
  if (this[0xe] == (FakeCarplay)0x0) {
    (*(code *)PTR_fputs_0056a93c)
              (PTR_s__0051fff8_8_00568c5c + -0x4504,*(undefined4 *)PTR_stderr_0056a674);
    (*(code *)PTR_fputc_0056aa7c)(10,*(undefined4 *)puVar1);
                    /* WARNING: Could not recover jumptable at 0x0041bed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_system_0056a670)(PTR_s__0051fff8_8_00568c5c + -0x46c8);
    return;
  }
  return;
}



/* === MakeModeStateFromDictionary @ 0042cfec === */

int MakeModeStateFromDictionary(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined1 auStack_58 [32];
  int local_38 [2];
  undefined *local_30;
  
  (*(code *)PTR_memset_0056a728)(param_2,0,0x34);
  uVar3 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  iVar4 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (param_1,PTR_s__0051fff8_8_00568c5c + 0x5c4,uVar3,0);
  if (iVar4 != 0) {
    iVar5 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar4);
    puVar1 = PTR_s__0051fff8_8_00568c5c;
    local_30 = PTR_s__0051fff8_8_00568c5c + 0x5ec;
    puVar9 = PTR_s__0051fff8_8_00568c5c + 0x610;
    for (iVar8 = 0; iVar8 < iVar5; iVar8 = iVar8 + 1) {
      uVar3 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
      uVar3 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar4,iVar8,uVar3,local_38);
      if (local_38[0] != 0) {
        uVar3 = 0x95;
        goto LAB_0042d2b4;
      }
      iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar3,local_30,0);
      if (iVar6 == 1) {
        uVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar3,puVar9,local_38);
        if (local_38[0] == 0) {
          param_2[10] = uVar3;
        }
      }
      else if (iVar6 < 2) {
        if (iVar6 != 0) {
LAB_0042d218:
          (*(code *)PTR_puts_0056a780)(puVar1 + -0xcc);
        }
      }
      else if (iVar6 == 2) {
        uVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x600,local_38);
        if (local_38[0] == 0) {
          param_2[0xb] = uVar3;
        }
      }
      else {
        if (iVar6 != 3) goto LAB_0042d218;
        uVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x600,local_38);
        if (local_38[0] == 0) {
          param_2[0xc] = uVar3;
        }
      }
    }
  }
  uVar3 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  iVar4 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (param_1,PTR_s__0051fff8_8_00568c5c + 0x5d8,uVar3,0);
  if (iVar4 != 0) {
    iVar5 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar4);
    puVar1 = PTR_s__0051fff8_8_00568c5c;
    puVar10 = PTR_s__0051fff8_8_00568c5c + 0x624;
    puVar9 = PTR_s__0051fff8_8_00568c5c + 0x638;
    for (iVar8 = 0; iVar8 < iVar5; iVar8 = iVar8 + 1) {
      uVar3 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
      uVar3 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar4,iVar8,uVar3,local_38);
      if (local_38[0] != 0) {
        uVar3 = 0xbf;
LAB_0042d2b4:
        (*(code *)PTR_DebugPrintAssert_00568cd8)
                  (0,local_38[0],0,PTR_s__0051fff8_8_00568c5c + -0x418,uVar3,
                   PTR_s__0051fff8_8_00568c5c + 0x9b8,0);
        return local_38[0];
      }
      iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar3,puVar10,0);
      if (iVar6 == 1) {
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar3,puVar9,local_38);
        if (local_38[0] != 0) {
          uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                            (uVar3,PTR_s__0051fff8_8_00568c5c + 0x654,local_38);
        }
        puVar2 = PTR_CFDictionaryGetInt64_00568d00;
        param_2[3] = uVar7;
        uVar7 = (*(code *)puVar2)(uVar3,puVar1 + 0x670,local_38);
        if (local_38[0] == 0) {
          param_2[2] = uVar7;
        }
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x688,local_38);
        if (local_38[0] == 0) {
          param_2[1] = uVar7;
        }
        uVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x6a4,local_38);
        if (local_38[0] == 0) {
          *param_2 = uVar3;
        }
      }
      else if (iVar6 == 2) {
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar3,puVar9,local_38);
        if (local_38[0] != 0) {
          uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                            (uVar3,PTR_s__0051fff8_8_00568c5c + 0x654,local_38);
        }
        puVar2 = PTR_CFDictionaryGetInt64_00568d00;
        param_2[8] = uVar7;
        uVar7 = (*(code *)puVar2)(uVar3,puVar1 + 0x670,local_38);
        if (local_38[0] == 0) {
          param_2[7] = uVar7;
        }
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x688,local_38);
        if (local_38[0] == 0) {
          param_2[6] = uVar7;
        }
        uVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                          (uVar3,PTR_s__0051fff8_8_00568c5c + 0x6a4,local_38);
        if (local_38[0] == 0) {
          param_2[5] = uVar3;
        }
      }
      else if (iVar6 != 0) {
        (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_58,0x20);
        puVar2 = PTR_stderr_0056a674;
        (*(code *)PTR_fprintf_0056aa28)
                  (*(undefined4 *)PTR_stderr_0056a674,PTR_s__0051fff8_8_00568c5c + -0xac,auStack_58)
        ;
        (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      }
    }
  }
  return 0;
}



/* === AirplayClientSendCmdSetupScreen @ 004317a0 === */

short * AirplayClientSendCmdSetupScreen(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 local_a8 [8];
  short local_88 [14];
  byte local_6c;
  byte local_6b;
  byte local_6a;
  byte local_69;
  byte local_68;
  byte local_67;
  byte local_66;
  byte local_65;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40 [2];
  short *local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined *local_2c;
  
  local_40[0] = 0;
  local_44 = 0;
  local_48 = 0;
  if (param_1 == (int *)0x0) {
    uVar15 = 0x2d0;
    puVar10 = PTR_s__0051fff8_8_00568c5c + 0xca0;
LAB_00431868:
    iVar11 = 0;
    iVar12 = 0;
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,puVar10,PTR_s__0051fff8_8_00568c5c + 0xa50,uVar15,
               PTR_s__0051fff8_8_00568c5c + 0x1174,0);
  }
  else {
    iVar12 = (*(code *)PTR_dispatch_semaphore_create_0056945c)(0);
    param_1[0xc] = iVar12;
    if (iVar12 == 0) {
      uVar15 = 0x2d3;
      puVar10 = PTR_s__0051fff8_8_00568c5c + 0xca8;
      goto LAB_00431868;
    }
    psVar3 = (short *)(*(code *)PTR_HTTPMessageCreate_00569254)(local_40);
    if (psVar3 != (short *)0x0) {
      uVar15 = 0x2d6;
LAB_004318fc:
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,psVar3,0,PTR_s__0051fff8_8_00568c5c + 0xa50,uVar15,
                 PTR_s__0051fff8_8_00568c5c + 0x1174,0);
      iVar11 = 0;
      iVar12 = 0;
      goto LAB_00431f98;
    }
    psVar3 = (short *)(*(code *)PTR_HTTPHeader_InitRequest_00569258)
                                (local_40[0] + 0x10,PTR_s__0051fff8_8_00568c5c + -0x1f38,
                                 PTR_s__0051fff8_8_00568c5c + 0xcb4,
                                 PTR_s__0051fff8_8_00568c5c + -0x2988);
    puVar10 = PTR_sprintf_0056aa10;
    if (psVar3 != (short *)0x0) {
      uVar15 = 0x2d9;
      goto LAB_004318fc;
    }
    puVar9 = PTR_DAT_00568ef4 + -0x64c4;
    *(int *)PTR_g_http_cseq_0056925c = *(int *)PTR_g_http_cseq_0056925c + 1;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    (*(code *)puVar10)(&local_5c,puVar9);
    (*(code *)PTR_HTTPHeader_AddFieldF_00568d30)
              (local_40[0] + 0x10,PTR_s__0051fff8_8_00568c5c + -0x2968,&local_5c);
    iVar12 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                       (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                        PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
    if (iVar12 == 0) {
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,0,PTR_s__0051fff8_8_00568c5c + 0xcbc,PTR_s__0051fff8_8_00568c5c + 0xa50,0x2df,
                 PTR_s__0051fff8_8_00568c5c + 0x1174,0);
      iVar11 = 0;
    }
    else {
      iVar11 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                         (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                          PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
      if (iVar11 != 0) {
        (*(code *)PTR_UUIDGet_00569460)(&local_6c);
        puVar1 = PTR_CFDictionarySetInt64_00568e20;
        puVar9 = PTR_DAT_00568d8c;
        puVar10 = PTR_s__0051fff8_8_00568c5c;
        *(uint *)(PTR_DAT_00568d8c + -0x4c88) =
             (uint)local_65 | (uint)local_68 << 0x18 | (uint)local_67 << 0x10 | (uint)local_66 << 8;
        *(uint *)(puVar9 + -0x4c84) =
             (uint)local_6c << 0x18 | (uint)local_6b << 0x10 | (uint)local_6a << 8 | (uint)local_69;
        (*(code *)puVar1)(iVar11,puVar10 + 0x1090);
        (*(code *)PTR_CFDictionarySetInt64_00568e20)
                  (iVar11,PTR_s__0051fff8_8_00568c5c + 0x106c,0x6e,0);
        puVar10 = PTR_stderr_0056a674;
        if ((*(int *)PTR_gMainScreenUUID_0056939c != 0) &&
           (iVar4 = (*(code *)PTR_CFStringGetCStringPtr_005691e4)
                              (*(int *)PTR_gMainScreenUUID_0056939c,0x8000100), iVar4 != 0)) {
          (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
          (*(code *)PTR_fprintf_0056aa28)
                    (*(undefined4 *)puVar10,PTR_s__0051fff8_8_00568c5c + 0xcd8,local_a8,iVar4);
          (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar10);
          (*(code *)PTR_CFDictionarySetCString_00568e1c)
                    (iVar11,PTR_s__0051fff8_8_00568c5c + 0x10ac,iVar4,0xffffffff);
        }
        (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
        puVar1 = PTR_stderr_0056a674;
        uVar8 = *(undefined4 *)(puVar9 + -0x4c84);
        uVar15 = *(undefined4 *)(puVar9 + -0x4c88);
        (*(code *)PTR_fprintf_0056aa28)
                  (*(undefined4 *)puVar10,PTR_s__0051fff8_8_00568c5c + 0xcf8,local_a8);
        (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar10);
        (*(code *)PTR_CFDictionarySetInt64_00568e20)
                  (iVar11,PTR_s__0051fff8_8_00568c5c + 0x10bc,0x19,0,uVar15,uVar8);
        (*(code *)PTR_CFArrayEnsureCreatedAndAppend_00569410)(&local_48,iVar11);
        (*(code *)PTR_CFDictionarySetValue_00568d14)
                  (iVar12,PTR_s__0051fff8_8_00568c5c + 0x105c,local_48);
        iVar4 = (*(code *)PTR_CFBinaryPlistV0Create_00568d9c)(iVar12,&local_44,0);
        if (iVar4 == 0) {
          (*(code *)PTR_DebugPrintAssert_00568cd8)
                    (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x3c28,
                     PTR_s__0051fff8_8_00568c5c + 0xa50,0x319,PTR_s__0051fff8_8_00568c5c + 0x1174,0)
          ;
          psVar3 = (short *)0xffffe5d4;
          goto LAB_00431f98;
        }
        psVar5 = (short *)(*(code *)PTR_HTTPMessageSetBodyPtr_00568d38)
                                    (local_40[0],PTR_s__0051fff8_8_00568c5c + -0x2904,iVar4,local_44
                                    );
        puVar9 = PTR_HTTPClientSendMessage_00569260;
        if (psVar5 == (short *)0x0) {
          *(undefined **)(local_40[0] + 0x904) = PTR_LAB_00569274 + 0xb18;
          puVar2 = PTR_gAirPlayClient_00569264;
          *(undefined4 *)(local_40[0] + 0x8f4) = 0;
          *(undefined4 *)(local_40[0] + 0x8f8) = 0;
          uVar15 = *(undefined4 *)puVar2;
          *(int **)(local_40[0] + 0x8fc) = param_1;
          psVar3 = (short *)(*(code *)puVar9)(uVar15);
          (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
          (*(code *)PTR_fprintf_0056aa28)
                    (*(undefined4 *)puVar1,PTR_s__0051fff8_8_00568c5c + -0x2b84,local_a8,
                     PTR_s__0051fff8_8_00568c5c + 0x1154,0x322);
          (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar1);
          if (psVar3 == (short *)0x0) {
            (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
            (*(code *)PTR_fprintf_0056aa28)
                      (*(undefined4 *)puVar1,PTR_s__0051fff8_8_00568c5c + 0xd20,local_a8);
            (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar1);
            (*(code *)PTR_dispatch_semaphore_wait_00569464)(param_1[0xc]);
            (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
            (*(code *)PTR_fprintf_0056aa28)
                      (*(undefined4 *)puVar1,PTR_s__0051fff8_8_00568c5c + 0xd44,local_a8);
            (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar1);
            local_38 = local_88;
            iVar13 = param_1[1];
            (*(code *)PTR_SockAddrCopy_00569280)(PTR_gPeerAddr_00569284,local_38);
            iVar4 = (*(code *)PTR_socket_0056ab6c)(local_88[0],2,0);
            if (iVar4 < 0) {
              piVar6 = (int *)(*(code *)PTR___errno_location_0056a998)();
              psVar5 = (short *)*piVar6;
              if (psVar5 == (short *)0x0) {
                psVar5 = (short *)0xffffe5d4;
              }
            }
            else {
              local_34 = &local_4c;
              local_4c = 1;
              local_30 = 4;
              iVar7 = (*(code *)PTR_setsockopt_0056ab24)(iVar4,0xffff,4,local_34,4);
              if (iVar7 == 0) {
                if ((local_88[0] == 10) &&
                   (iVar7 = (*(code *)PTR_setsockopt_0056ab24)(iVar4,0x29,0x1a,local_34,local_30),
                   iVar7 != 0)) {
                  piVar6 = (int *)(*(code *)PTR___errno_location_0056a998)();
                  psVar5 = (short *)*piVar6;
                  if (psVar5 == (short *)0x0) {
                    psVar5 = (short *)0xffffe5d4;
                  }
                  uVar15 = 0x253;
                  goto LAB_00431ed0;
                }
                (*(code *)PTR_SocketSetQoS_00569350)(iVar4,0xc);
                iVar7 = 0x15;
                (*(code *)PTR_SockAddrSetPort_0056928c)(local_38,iVar13);
                local_34 = (undefined4 *)(*(code *)PTR_SockAddrGetSize_005692a4)(local_38);
                local_30 = 100000;
                local_2c = PTR_s__0051fff8_8_00568c5c + 0xd74;
                while (iVar13 = (*(code *)PTR_connect_0056aad0)(iVar4,local_38,local_34),
                      iVar13 != 0) {
                  iVar7 = iVar7 + -1;
                  piVar6 = (int *)(*(code *)PTR___errno_location_0056a998)();
                  psVar5 = (short *)*piVar6;
                  if (psVar5 == (short *)0x0) {
                    psVar5 = (short *)0xffffe5d4;
                  }
                  if (iVar7 == 0) {
                    local_38 = psVar5;
                    (*(code *)PTR_DebugPrintAssert_00568cd8)
                              (0,psVar5,0,PTR_s__0051fff8_8_00568c5c + 0xa50,0x264,
                               PTR_s__0051fff8_8_00568c5c + 0x1110,0);
                    psVar5 = local_38;
                    goto LAB_00431ef4;
                  }
                  (*(code *)PTR_usleep_0056aa2c)(local_30);
                  (*(code *)PTR_timestamp_ext_0056a7b0)(local_a8,0x20);
                  (*(code *)PTR_fprintf_0056aa28)(*(undefined4 *)puVar10,local_2c,local_a8);
                  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar10);
                }
                uVar15 = (*(code *)PTR_dispatch_get_main_queue_00569228)();
                iVar13 = (*(code *)PTR_dispatch_source_create_00568de8)(2,0,0,uVar15);
                param_1[2] = iVar13;
                if (iVar13 != 0) {
                  (*(code *)PTR_dispatch_set_context_00568dec)(iVar13,param_1);
                  (*(code *)PTR_dispatch_source_set_event_handler_f_00568df0)
                            (param_1[2],PTR_LAB_00569274 + 0x8ec);
                  (*(code *)PTR_dispatch_source_set_cancel_handler_f_005692c8)
                            (param_1[2],PTR_LAB_00569274 + 0x538);
                  iVar13 = param_1[2];
                  uVar14 = (*(code *)PTR_dispatch_time_00568df4)(0,0,2000000000,0);
                  (*(code *)PTR_dispatch_source_set_timer_00568df8)
                            (iVar13,0,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000000000,0,0,0)
                  ;
                  (*(code *)PTR_dispatch_resume_00568dfc)(param_1[2]);
                  puVar9 = PTR_s__0051fff8_8_00568c5c;
                  if (*(int *)PTR_pairVerifySessionHomeKit_005692a8 == 0) {
                    local_50 = 0;
                    local_a8[0] = 0;
                    local_38 = (short *)(*(code *)PTR_asprintf_0056a838)
                                                  (&local_50,PTR_s__0051fff8_8_00568c5c + -0x54,
                                                   PTR_s__0051fff8_8_00568c5c + 0xdb8);
                    uVar15 = (*(code *)PTR_asprintf_0056a838)
                                       (local_a8,puVar9 + -0x54,PTR_s__0051fff8_8_00568c5c + 0xdcc);
                    simAirPlayDeriveAESKeySHA512
                              (PTR_sessionAesKey_00569364,0x10,local_50,local_38,local_a8[0],uVar15,
                               param_1 + 4,param_1 + 8);
                    (*(code *)PTR_free_00568d70)(local_50);
                    (*(code *)PTR_free_00568d70)(local_a8[0]);
                    (*(code *)PTR_AES_CTR_Init_005693d0)(param_1 + 0x5a,param_1 + 4,param_1 + 8);
                  }
                  else {
                    puVar16 = local_a8;
                    psVar5 = (short *)simGetStreamSecurityKeys();
                    piVar6 = param_1 + 0x14;
                    if (psVar5 != (short *)0x0) {
                      (*(code *)PTR_DebugPrintAssert_00568cd8)
                                (0,psVar5,0,PTR_s__0051fff8_8_00568c5c + 0xa50,0x282,
                                 PTR_s__0051fff8_8_00568c5c + 0x1110,0,puVar16);
                      goto LAB_00431ef4;
                    }
                    for (; param_1 + 0x5a != piVar6; piVar6 = (int *)((int)piVar6 + 1)) {
                      *(undefined1 *)piVar6 = 0;
                    }
                    (*(code *)PTR_memcpy_0056aa64)(param_1 + 0x50,local_a8,0x20);
                    *(undefined1 *)(param_1 + 0x14) = 1;
                  }
                  puVar9 = PTR_timestamp_ext_0056a7b0;
                  param_1[3] = 1;
                  *param_1 = iVar4;
                  (*(code *)puVar9)(local_a8,0x20);
                  (*(code *)PTR_fprintf_0056aa28)
                            (*(undefined4 *)puVar10,PTR_s__0051fff8_8_00568c5c + 0xddc,local_a8);
                  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar10);
                  goto LAB_00431f98;
                }
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,0,PTR_s__0051fff8_8_00568c5c + 0xd9c,PTR_s__0051fff8_8_00568c5c + 0xa50
                           ,0x267,PTR_s__0051fff8_8_00568c5c + 0x1110,0);
                psVar5 = (short *)0xffffe5b8;
              }
              else {
                piVar6 = (int *)(*(code *)PTR___errno_location_0056a998)();
                psVar5 = (short *)*piVar6;
                if (psVar5 == (short *)0x0) {
                  psVar5 = (short *)0xffffe5d4;
                }
                uVar15 = 0x24f;
LAB_00431ed0:
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,psVar5,0,PTR_s__0051fff8_8_00568c5c + 0xa50,uVar15,
                           PTR_s__0051fff8_8_00568c5c + 0x1110,0);
              }
LAB_00431ef4:
              iVar4 = (*(code *)PTR_close_0056a6e4)(iVar4);
              if (iVar4 != 0) {
                piVar6 = (int *)(*(code *)PTR___errno_location_0056a998)();
                iVar4 = *piVar6;
                if (iVar4 == 0) {
                  iVar4 = -0x1a2c;
                }
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,iVar4,0,PTR_s__0051fff8_8_00568c5c + 0xa50,0x28f,
                           PTR_s__0051fff8_8_00568c5c + 0x1110,0);
              }
              psVar3 = psVar5;
              if (psVar5 == (short *)0x0) goto LAB_00431f98;
            }
            puVar10 = PTR_s__0051fff8_8_00568c5c + 0x1174;
            uVar15 = 0x328;
          }
          else {
            puVar10 = PTR_s__0051fff8_8_00568c5c + 0x1174;
            uVar15 = 0x323;
            psVar5 = psVar3;
          }
        }
        else {
          puVar10 = PTR_s__0051fff8_8_00568c5c + 0x1174;
          uVar15 = 0x31c;
        }
        (*(code *)PTR_DebugPrintAssert_00568cd8)
                  (0,psVar5,0,PTR_s__0051fff8_8_00568c5c + 0xa50,uVar15,puVar10,0);
        psVar3 = psVar5;
        goto LAB_00431f98;
      }
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,0,PTR_s__0051fff8_8_00568c5c + 0xccc,PTR_s__0051fff8_8_00568c5c + 0xa50,0x2e1,
                 PTR_s__0051fff8_8_00568c5c + 0x1174,0);
    }
  }
  psVar3 = (short *)0xffffe5b8;
LAB_00431f98:
  if (param_1[0xc] != 0) {
    (*(code *)PTR_dispatch_release_00568d80)();
  }
  if (iVar12 != 0) {
    (*(code *)PTR_CFRelease_00568d1c)(iVar12);
  }
  if (iVar11 != 0) {
    (*(code *)PTR_CFRelease_00568d1c)(iVar11);
  }
  if (local_48 != 0) {
    (*(code *)PTR_CFRelease_00568d1c)();
  }
  if (local_40[0] != 0) {
    (*(code *)PTR_CFRelease_00568d1c)();
  }
  return psVar3;
}



/* === _getScreenDisplays @ 0043dcfc === */

undefined4 _getScreenDisplays(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 local_28 [3];
  
  local_28[0] = 0;
  iVar1 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4300,0);
  uVar7 = 2;
  if (iVar1 == 0) {
    uVar7 = 0;
  }
  iVar1 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x42c8,0);
  if (iVar1 != 0) {
    uVar7 = uVar7 | 8;
  }
  iVar1 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x42bc,0);
  if (iVar1 != 0) {
    uVar7 = uVar7 | 4;
  }
  iVar1 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + 0x2f1c,0);
  if (iVar1 != 0) {
    uVar7 = uVar7 | 0x10;
  }
  uVar2 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + 0x2f2c,0x14);
  uVar3 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -17000,800);
  uVar4 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4258,0x1e0);
  uVar5 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4224,0x9a);
  uVar6 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4210,0x57);
  (*(code *)PTR_AirPlayInfoArrayAddScreenDisplay_0056960c)
            (local_28,PTR_s__0051fff8_8_00568c5c + 0x30d8,uVar7,0,uVar2,uVar3,uVar4,uVar5,uVar6);
  *param_1 = 0;
  return local_28[0];
}



/* === airPlayGetPropertyFromNativeHU @ 0043e208 === */

int airPlayGetPropertyFromNativeHU(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int local_48 [8];
  undefined4 local_28 [2];
  
  puVar6 = PTR_gFakeDict_00569618;
  if (*(int *)PTR_gFakeDict_00569618 == 0) {
    uVar3 = getDictionaryFromFile(PTR_s__0051fff8_8_00568c5c + -0x1608);
    *(undefined4 *)puVar6 = uVar3;
  }
  puVar1 = PTR_gFakeDict_00569618;
  iVar8 = 0;
  if (*(int *)puVar6 == 0) goto LAB_0043e930;
  iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x313c);
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3154);
    if (iVar8 == 0) {
      iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x316c);
      if (iVar8 == 0) {
        iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3184);
        if (iVar8 == 0) {
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x319c);
          if (iVar8 != 0) goto LAB_0043e2e8;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31b0);
          if (iVar8 != 0) goto LAB_0043e2e8;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31cc);
          if (iVar8 != 0) goto LAB_0043e2e8;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31e8);
          if (iVar8 != 0) goto LAB_0043e2e8;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31fc);
          puVar1 = PTR_s__0051fff8_8_00568c5c;
          if (iVar8 != 0) {
LAB_0043e5dc:
            uVar3 = *(undefined4 *)puVar6;
            goto LAB_0043e2f0;
          }
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x320c);
          if (iVar8 != 0) {
            local_48[0] = 0;
            uVar10 = *(undefined4 *)puVar6;
            (*(code *)PTR_puts_0056a780)(PTR_s__0051fff8_8_00568c5c + 0x2f60);
            uVar3 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
            iVar8 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                              (uVar10,puVar1 + 0x320c,uVar3,0);
            if (iVar8 != 0) {
              iVar4 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar8);
              for (iVar9 = 0; iVar9 < iVar4; iVar9 = iVar9 + 1) {
                uVar3 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
                (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar8,iVar9,uVar3,local_48);
                if (local_48[0] != 0) {
                  (*(code *)PTR_DebugPrintAssert_00568cd8)
                            (0,local_48[0],0,PTR_s__0051fff8_8_00568c5c + 0x2da8,0x30e,
                             PTR_s__0051fff8_8_00568c5c + 0x3470,0);
                  break;
                }
                if (iVar9 != 0) {
                  (*(code *)PTR_CFArrayRemoveValueAtIndex_005695cc)(iVar8,iVar9);
                }
              }
            }
            goto LAB_0043e5dc;
          }
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3220);
          if (iVar8 != 0) goto LAB_0043e5dc;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3234);
          if (iVar8 != 0) goto LAB_0043e5dc;
          iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3254);
          puVar1 = PTR_gDeviceID_00569568;
          if (iVar8 == 0) {
            iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3268);
            if (iVar8 == 0) {
              iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3280);
              if (iVar8 == 0) {
                iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3290)
                ;
                if (iVar8 != 0) goto LAB_0043e5dc;
                iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x32a8)
                ;
                if (iVar8 != 0) goto LAB_0043e5dc;
                iVar8 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x32c0)
                ;
                if (iVar8 == 0) goto LAB_0043e30c;
                iVar8 = (*(code *)PTR_cfg_get_int_0056a864)(PTR_s__0051fff8_8_00568c5c + -0x4d28,0);
                puVar1 = PTR_gInitialModes_00569624;
                puVar6 = PTR_gInitialModesRaw_00569620;
                if (iVar8 != 0) {
                  iVar8 = *(int *)PTR_gInitialModes_00569624;
                  *(undefined4 *)PTR_gInitialModesRaw_00569620 = 2;
                  *(undefined4 *)(puVar6 + 8) = 0;
                  *(undefined4 *)(puVar6 + 0xc) = 0;
                  if (iVar8 != 0) {
                    (*(code *)PTR_CFRelease_00568d1c)();
                  }
                  uVar3 = (*(code *)PTR_AirPlayCreateModesDictionary_00569628)
                                    (PTR_gInitialModesRaw_00569620,0,local_28);
                  *(undefined4 *)puVar1 = uVar3;
                }
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                puVar2 = PTR_stderr_0056a674;
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)PTR_stderr_0056a674,PTR_s__0051fff8_8_00568c5c + -0x1588,
                           local_48);
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                puVar7 = PTR_s__0051fff8_8_00568c5c;
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1568,local_48,
                           *(undefined4 *)puVar6,*(undefined4 *)(puVar6 + 4),
                           *(undefined4 *)(puVar6 + 8),*(undefined4 *)(puVar6 + 0xc));
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1538,local_48);
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)puVar2,puVar7 + -0x1568,local_48,
                           *(undefined4 *)(puVar6 + 0x14),*(undefined4 *)(puVar6 + 0x18),
                           *(undefined4 *)(puVar6 + 0x1c),*(undefined4 *)(puVar6 + 0x20));
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1518,local_48);
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                (*(code *)PTR_timestamp_ext_0056a7b0)(local_48,0x20);
                iVar8 = *(int *)(puVar6 + 0x2c);
                if (iVar8 == 0) {
                  puVar7 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
                }
                else if (iVar8 == -1) {
                  puVar7 = PTR_s__0051fff8_8_00568c5c + -0x1d78;
                }
                else if (iVar8 == 1) {
                  puVar7 = PTR_s__0051fff8_8_00568c5c + -0x1d70;
                }
                else {
                  puVar7 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
                }
                iVar8 = *(int *)(puVar6 + 0x28);
                if (iVar8 == 0) {
                  puVar5 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
                }
                else if (iVar8 == -1) {
                  puVar5 = PTR_s__0051fff8_8_00568c5c + -0x21b8;
                }
                else if (iVar8 == 1) {
                  puVar5 = PTR_s__0051fff8_8_00568c5c + -0x21b0;
                }
                else if (iVar8 == 2) {
                  puVar5 = PTR_s__0051fff8_8_00568c5c + -0x21a4;
                }
                else {
                  puVar5 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
                }
                iVar8 = *(int *)(puVar6 + 0x30);
                if (iVar8 == 0) {
                  puVar6 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
                }
                else if (iVar8 == -1) {
                  puVar6 = PTR_s__0051fff8_8_00568c5c + -0x1d78;
                }
                else if (iVar8 == 1) {
                  puVar6 = PTR_s__0051fff8_8_00568c5c + -0x1d70;
                }
                else {
                  puVar6 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
                }
                (*(code *)PTR_fprintf_0056aa28)
                          (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x14f4,local_48,
                           puVar7,puVar5,puVar6);
                (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
                iVar8 = *(int *)puVar1;
                goto LAB_0043e304;
              }
            }
            goto LAB_0043e5dc;
          }
          if (*(int *)PTR_gDeviceID_00569568 != 0) {
LAB_0043e564:
            iVar8 = *(int *)puVar1;
            goto LAB_0043e304;
          }
          uVar3 = (*(code *)PTR_ark_get_info_string_0056a770)
                            (PTR_s__0051fff8_8_00568c5c + -0x3fd8,
                             PTR_s__0051fff8_8_00568c5c + 0x2514);
          iVar8 = (*(code *)PTR_CFStringCreateWithCString_00569424)(0,uVar3,0x8000100);
          *(int *)puVar1 = iVar8;
          if (iVar8 != 0) goto LAB_0043e564;
        }
        else {
LAB_0043e2e8:
          uVar3 = *(undefined4 *)puVar1;
LAB_0043e2f0:
          iVar8 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)(uVar3,param_1);
LAB_0043e304:
          if (iVar8 != 0) {
            (*(code *)PTR_CFRetain_00568cf0)(iVar8);
            local_28[0] = 0;
            goto LAB_0043e930;
          }
        }
LAB_0043e30c:
        local_28[0] = 0xffffe5c6;
        iVar8 = 0;
        goto LAB_0043e930;
      }
    }
  }
  iVar8 = 0;
  local_28[0] = 0;
LAB_0043e930:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_28[0];
  }
  return iVar8;
}



/* === airPlayGetProperty @ 0043e968 === */

int airPlayGetProperty(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined *puVar11;
  undefined1 auStack_48 [32];
  int local_28 [2];
  
  puVar1 = PTR_DAT_00568d8c;
  (*(code *)PTR_pthread_mutex_lock_0056a8a4)(PTR_DAT_00568d8c + -0x4b78);
  iVar2 = airPlayGetPropertyFromNativeHU(param_1,local_28);
  if (iVar2 != 0) goto LAB_0043f6b0;
  iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x313c);
  piVar10 = (int *)PTR_gAudioFormats_005695ec;
  if (iVar3 == 0) {
    iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3154);
    piVar10 = (int *)PTR_gAudioLatencies_00569634;
    if (iVar3 != 0) {
      if (*(int *)PTR_gAudioLatencies_00569634 == 0) {
        uVar4 = _getAudioLatencies(local_28);
        *piVar10 = uVar4;
        if (local_28[0] != 0) {
          puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
          uVar4 = 0x400;
          goto LAB_0043ea94;
        }
      }
      goto LAB_0043eab8;
    }
    iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x316c);
    puVar5 = PTR_gBluetoothIDs_0056963c;
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3184);
      if (iVar3 == 0) {
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x319c);
        if (iVar3 != 0) {
          iVar3 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4334,0);
          piVar10 = (int *)PTR_gNightMode_00569644;
          goto LAB_0043f2dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31b0);
        piVar10 = (int *)PTR_gVehicleDict_00569648;
        if (iVar3 != 0) {
          if (*(int *)PTR_gVehicleDict_00569648 == 0) {
            uVar4 = _getVehicleInfo(local_28);
            *piVar10 = uVar4;
            if (local_28[0] != 0) {
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
              uVar4 = 0x42d;
              goto LAB_0043ea94;
            }
          }
          goto LAB_0043f224;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31cc);
        puVar5 = PTR_gExtendedFeatures_00569650;
        if (iVar3 != 0) {
          iVar3 = *(int *)PTR_gExtendedFeatures_00569650;
          if (iVar3 != 0) goto LAB_0043f69c;
          iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                            (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
          *(int *)puVar5 = iVar3;
          if (iVar3 == 0) goto LAB_0043eb2c;
          (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x32d0);
          iVar3 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x42f4,0);
          if (iVar3 != 0) {
            (*(code *)PTR_CFArrayAppendValue_00568cd4)
                      (*(undefined4 *)puVar5,PTR_s__0051fff8_8_00568c5c + 0x32e4);
          }
          iVar3 = (*(code *)PTR_CFArrayGetCount_00568e30)(*(undefined4 *)puVar5);
          if (iVar3 == 0) {
            if (*(int *)PTR_gExtendedFeatures_00569650 != 0) {
              (*(code *)PTR_CFRelease_00568d1c)();
            }
            *(undefined4 *)puVar5 = 0;
          }
          iVar3 = *(int *)puVar5;
          goto LAB_0043f408;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31e8);
        piVar10 = (int *)PTR_gIconsArray_00569654;
        if (iVar3 != 0) {
          if (*(int *)PTR_gIconsArray_00569654 == 0) {
            iVar6 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                              (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
            puVar5 = PTR_s__0051fff8_8_00568c5c;
            local_28[0] = -0x1a3a;
            iVar3 = iVar6;
            if (iVar6 != 0) {
              uVar4 = (*(code *)PTR_cfg_get_string_0056a694)
                                (PTR_s__0051fff8_8_00568c5c + -0x43b0,
                                 PTR_s__0051fff8_8_00568c5c + 0x2f7c);
              iVar7 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(uVar4,0);
              if ((iVar7 != 0) ||
                 (iVar7 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(puVar5 + 0x2f7c,0),
                 iVar7 != 0)) {
                iVar8 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                                  (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                   PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
                if (iVar8 != 0) {
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3304,0x78,0);
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3318,0x78,0);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3330,
                             *(undefined4 *)PTR_kCFLBooleanTrue_00568ce8);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3344,iVar7);
                  (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar6,iVar8);
                  (*(code *)PTR_CFRelease_00568d1c)(iVar8);
                }
                (*(code *)PTR_CFRelease_00568d1c)(iVar7);
              }
              uVar4 = (*(code *)PTR_cfg_get_string_0056a694)
                                (PTR_s__0051fff8_8_00568c5c + 0x2fc4,
                                 PTR_s__0051fff8_8_00568c5c + 0x2fa0);
              iVar7 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(uVar4,0);
              if (iVar7 != 0) {
                iVar8 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                                  (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                   PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
                if (iVar8 != 0) {
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3304,0xb4,0);
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3318,0xb4,0);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3330,
                             *(undefined4 *)PTR_kCFLBooleanTrue_00568ce8);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3344,iVar7);
                  (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar6,iVar8);
                  (*(code *)PTR_CFRelease_00568d1c)(iVar8);
                }
                (*(code *)PTR_CFRelease_00568d1c)(iVar7);
              }
              uVar4 = (*(code *)PTR_cfg_get_string_0056a694)
                                (PTR_s__0051fff8_8_00568c5c + 0x2ff8,
                                 PTR_s__0051fff8_8_00568c5c + 0x2fd4);
              iVar7 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(uVar4,0);
              if (iVar7 != 0) {
                iVar8 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                                  (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                   PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
                if (iVar8 != 0) {
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3304,0x100,0);
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3318,0x100,0);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3330,
                             *(undefined4 *)PTR_kCFLBooleanTrue_00568ce8);
                  (*(code *)PTR_CFDictionarySetValue_00568d14)
                            (iVar8,PTR_s__0051fff8_8_00568c5c + 0x3344,iVar7);
                  (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar6,iVar8);
                  (*(code *)PTR_CFRelease_00568d1c)(iVar8);
                }
                (*(code *)PTR_CFRelease_00568d1c)(iVar7);
              }
              iVar7 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar6);
              local_28[0] = 0;
              if (iVar7 < 1) {
                iVar3 = 0;
                (*(code *)PTR_CFRelease_00568d1c)(iVar6);
                local_28[0] = -0x1a3a;
              }
            }
            *piVar10 = iVar3;
            if (local_28[0] != 0) {
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
              uVar4 = 0x44a;
              goto LAB_0043ea94;
            }
          }
LAB_0043f224:
          iVar3 = *piVar10;
          goto LAB_0043f408;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x31fc);
        piVar10 = (int *)PTR_gOEMIcon_00569658;
        if (iVar3 != 0) {
          if (*(int *)PTR_gOEMIcon_00569658 == 0) {
            uVar4 = (*(code *)PTR_ark_get_info_string_0056a770)
                              (PTR_s__0051fff8_8_00568c5c + -0x43b0,
                               PTR_s__0051fff8_8_00568c5c + 0x3008);
            uVar4 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(uVar4,local_28);
            *piVar10 = uVar4;
            if (local_28[0] != 0) {
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
              uVar4 = 0x454;
              goto LAB_0043ea94;
            }
          }
          goto LAB_0043f224;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x320c);
        piVar10 = (int *)PTR_gScreenDisplays_0056965c;
        if (iVar3 != 0) {
          if (*(int *)PTR_gScreenDisplays_0056965c == 0) {
            uVar4 = _getScreenDisplays(local_28);
            *piVar10 = uVar4;
            if (local_28[0] != 0) {
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
              uVar4 = 0x45e;
              goto LAB_0043ea94;
            }
          }
          goto LAB_0043f224;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3220);
        piVar10 = (int *)PTR_gHidDevs_00569664;
        if (iVar3 != 0) {
          if (*(int *)PTR_gHidDevs_00569664 == 0) {
            uVar4 = _getHIDDevices(local_28);
            *piVar10 = uVar4;
            if (local_28[0] != 0) {
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
              uVar4 = 0x468;
              goto LAB_0043ea94;
            }
          }
          goto LAB_0043f224;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3234);
        if (iVar3 != 0) {
          piVar10 = (int *)PTR_giOSVersionMin_0056966c;
          if (*(int *)PTR_giOSVersionMin_0056966c == 0) {
            puVar11 = PTR_s__0051fff8_8_00568c5c + -0x438c;
            puVar5 = PTR_s__0051fff8_8_00568c5c + -0x4384;
LAB_0043f3a8:
            uVar4 = (*(code *)PTR_ark_get_info_string_0056a770)(puVar5,puVar11);
            iVar3 = (*(code *)PTR_CFStringCreateWithCString_00569424)(0,uVar4,0x8000100);
            *piVar10 = iVar3;
            if (iVar3 == 0) goto LAB_0043eb2c;
          }
LAB_0043f3dc:
          iVar3 = *piVar10;
          goto LAB_0043f408;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3254);
        if (iVar3 != 0) {
          piVar10 = (int *)PTR_gDeviceID_00569568;
          if (*(int *)PTR_gDeviceID_00569568 == 0) {
            puVar11 = PTR_s__0051fff8_8_00568c5c + 0x2514;
            puVar5 = PTR_s__0051fff8_8_00568c5c + -0x3fd8;
            goto LAB_0043f3a8;
          }
          goto LAB_0043f3dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3268);
        if (iVar3 != 0) {
          iVar3 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x43f0,1);
          piVar10 = (int *)PTR_gOEMIconVisible_00569670;
          goto LAB_0043f2dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3280);
        if (iVar3 != 0) {
          piVar10 = (int *)PTR_gOSInfo_00569674;
          if (*(int *)PTR_gOSInfo_00569674 == 0) {
            puVar11 = PTR_s__0051fff8_8_00568c5c + 0x3024;
            puVar5 = PTR_s__0051fff8_8_00568c5c + -0x4394;
            goto LAB_0043f3a8;
          }
          goto LAB_0043f3dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3290);
        if (iVar3 != 0) {
          piVar10 = (int *)PTR_gManfacturer_00569678;
          if (*(int *)PTR_gManfacturer_00569678 == 0) {
            puVar11 = PTR_s__0051fff8_8_00568c5c + 0x302c;
            puVar5 = PTR_s__0051fff8_8_00568c5c + -0x4454;
            goto LAB_0043f3a8;
          }
          goto LAB_0043f3dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x32a8);
        if (iVar3 != 0) {
          piVar10 = (int *)PTR_gOEMIconLabel_0056967c;
          if (*(int *)PTR_gOEMIconLabel_0056967c == 0) {
            puVar11 = PTR_s__0051fff8_8_00568c5c + 0x3030;
            puVar5 = PTR_s__0051fff8_8_00568c5c + -0x43d8;
            goto LAB_0043f3a8;
          }
          goto LAB_0043f3dc;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x32c0);
        if (iVar3 != 0) {
          iVar3 = *(int *)PTR_gInitialModes_00569624;
          goto LAB_0043f408;
        }
        iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3358);
        puVar5 = PTR_gSupportsUIContext_00569680;
        if (iVar3 == 0) {
          iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x33c4);
          if (iVar3 == 0) {
            iVar3 = (*(code *)PTR_CFEqual_00568ce4)(param_1,PTR_s__0051fff8_8_00568c5c + 0x3438);
            if (((iVar3 != 0) && (*PTR_gSupportsUIContext_00569680 != '\0')) &&
               (iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                                  (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28), iVar3 != 0)) {
              (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x3424);
              puVar5 = PTR_s__0051fff8_8_00568c5c + 0x33e8;
              goto LAB_0043f688;
            }
          }
          else if ((*PTR_gSupportsUIContext_00569680 != '\0') &&
                  (iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                                     (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28), iVar3 != 0)) {
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x33e8);
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x33f8);
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x3410);
            puVar5 = PTR_s__0051fff8_8_00568c5c + 0x3424;
LAB_0043f688:
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,puVar5);
            goto LAB_0043f69c;
          }
        }
        else if (((*PTR_gSupportsUIContext_00569680 != '\0') ||
                 (*PTR_gSupportsViewAreas_005693a8 != '\0')) ||
                ((*PTR_gSupportsCornerMasks_00569684 != '\0' ||
                 (*PTR_gSupportsFocusTransfer_00569688 != '\0')))) {
          iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                            (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
          if (iVar3 == 0) {
            local_28[0] = -0x1a48;
            iVar2 = 0;
            goto LAB_0043f6b0;
          }
          if (*puVar5 != '\0') {
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x3370);
          }
          if (*PTR_gSupportsViewAreas_005693a8 != '\0') {
            (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_48,0x20);
            puVar5 = PTR_stderr_0056a674;
            (*(code *)PTR_fprintf_0056aa28)
                      (*(undefined4 *)PTR_stderr_0056a674,PTR_s__0051fff8_8_00568c5c + 0x3038,
                       auStack_48);
            (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar5);
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x3384);
          }
          if (*PTR_gSupportsCornerMasks_00569684 != '\0') {
            (*(code *)PTR_CFArrayAppendValue_00568cd4)(iVar3,PTR_s__0051fff8_8_00568c5c + 0x3398);
          }
          if (*PTR_gSupportsFocusTransfer_00569688 == '\0') goto LAB_0043f69c;
          puVar5 = PTR_s__0051fff8_8_00568c5c + 0x33ac;
          goto LAB_0043f688;
        }
      }
      else {
        iVar3 = (*(code *)PTR_ark_get_info_int_0056a85c)(PTR_s__0051fff8_8_00568c5c + -0x4348,0);
        piVar10 = (int *)PTR_gRightHandDrive_00569640;
LAB_0043f2dc:
        piVar9 = (int *)PTR_kCFLBooleanTrue_00568ce8;
        if (iVar3 == 0) {
          piVar9 = (int *)PTR_kCFLBooleanFalse_00568cec;
        }
        *piVar10 = *piVar9;
        iVar3 = *piVar10;
LAB_0043f408:
        if (iVar3 != 0) goto LAB_0043f69c;
      }
LAB_0043eb2c:
      local_28[0] = -0x1a3a;
      goto LAB_0043f6b0;
    }
    if (*(int *)PTR_gBluetoothIDs_0056963c == 0) {
      uVar4 = (*(code *)PTR_ark_get_info_string_0056a770)
                        (PTR_s__0051fff8_8_00568c5c + -0x3fc8,PTR_s__0051fff8_8_00568c5c + 0x2514);
      iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                        (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
      *(int *)puVar5 = iVar3;
      if (iVar3 == 0) goto LAB_0043eb2c;
      (*(code *)PTR_CFArrayAppendCString_005692e0)(iVar3,uVar4,0x11);
    }
    iVar3 = *(int *)puVar5;
  }
  else {
    if (*(int *)PTR_gAudioFormats_005695ec == 0) {
      uVar4 = _getAudioFormats(local_28);
      *piVar10 = uVar4;
      if (local_28[0] != 0) {
        puVar5 = PTR_s__0051fff8_8_00568c5c + 0x345c;
        uVar4 = 0x3f4;
LAB_0043ea94:
        (*(code *)PTR_DebugPrintAssert_00568cd8)
                  (0,local_28[0],0,PTR_s__0051fff8_8_00568c5c + 0x2da8,uVar4,puVar5,0);
        goto LAB_0043f6b0;
      }
    }
LAB_0043eab8:
    iVar3 = *piVar10;
  }
LAB_0043f69c:
  (*(code *)PTR_CFRetain_00568cf0)(iVar3);
  local_28[0] = 0;
  iVar2 = iVar3;
LAB_0043f6b0:
  (*(code *)PTR_pthread_mutex_unlock_0056a924)(puVar1 + -0x4b78);
  if (param_2 != (int *)0x0) {
    *param_2 = local_28[0];
  }
  return iVar2;
}



/* === AirPlayReceiverServerCopyProperty @ 00465f3c === */

undefined *
AirPlayReceiverServerCopyProperty
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 local_20 [2];
  
  iVar1 = (*(code *)PTR_CFEqual_00568ce4)
                    (param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4a0c);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_CFEqual_00568ce4)
                      (param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x49fc);
    puVar3 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
    if (iVar1 == 0) {
      puVar3 = (undefined *)
               (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                         (param_1,param_2,param_3,param_4,local_20);
    }
    else {
      (*(code *)PTR_CFRetain_00568cf0)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4a20);
      puVar3 = puVar3 + -0x4a20;
      local_20[0] = 0;
    }
  }
  else {
    puVar2 = (undefined4 *)PTR_kCFLBooleanTrue_00568ce8;
    if (*(char *)(param_1 + 0x58) == '\0') {
      puVar2 = (undefined4 *)PTR_kCFLBooleanFalse_00568cec;
    }
    puVar3 = (undefined *)*puVar2;
    (*(code *)PTR_CFRetain_00568cf0)(puVar3);
    local_20[0] = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_20[0];
  }
  return puVar3;
}



/* === AirPlayGetFeatures @ 00467708 === */

ulonglong AirPlayGetFeatures(undefined4 param_1)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)PTR_CFObjectGetPropertyInt64Sync_00568da4)
                    (param_1,0,PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4,1,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4968,0,0);
  return uVar1 | 0x6104040280;
}



/* === AirPlayCopyServerInfo @ 00468afc === */

int AirPlayCopyServerInfo(int param_1,int param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  longlong lVar9;
  char local_1050 [4100];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_3c;
  int local_38 [2];
  code *local_30;
  int local_2c;
  
  iVar6 = *(int *)(param_1 + 0xc);
  if (iVar6 == 0) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x330,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x57c0,0x118,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f34,0);
    iVar7 = 0;
    uVar5 = 0xffffe5cf;
    goto LAB_004698b4;
  }
  iVar7 = (*(code *)PTR_CFDictionaryCreateMutable_00568e10)
                    (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                     PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  if (iVar7 == 0) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s__0051fff8_8_00568c5c + -0x2314,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x57c0,0x11b,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f34,0);
    uVar5 = 0xffffe5b8;
    goto LAB_004698b4;
  }
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x486c);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x486c,0,0);
    if (iVar2 != 0) goto LAB_00468c28;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_00468c28:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x486c,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4854);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x4854,0,0);
    if (iVar2 != 0) goto LAB_00468c80;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_00468c80:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4854,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x483c,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x483c,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  (*(code *)PTR_HardwareAddressToCString_00568dc4)(iVar6 + 0x5b,6,local_1050);
  (*(code *)PTR_CFDictionarySetCString_00568e1c)
            (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4898,local_1050,0xffffffff);
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4824,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4824,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4810);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x4810,0,0);
    if (iVar2 != 0) goto LAB_00468dbc;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_00468dbc:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4810,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  lVar9 = AirPlayGetFeatures(iVar6);
  if (lVar9 != 0) {
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4968,(int)lVar9,
               (int)((ulonglong)lVar9 >> 0x20));
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  local_1050[0] = '\0';
  pcVar8 = (code *)(PTR_LAB_00568ccc + 0x5e90);
  FUN_00465e90(iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x48b4,local_1050,0x1001,0);
  local_30 = pcVar8;
  if (local_1050[0] == '\0') {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x48b4,0,0);
    if (iVar2 != 0) {
      (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x48b4,iVar2);
      (*(code *)PTR_CFRelease_00568d1c)(iVar2);
    }
  }
  else {
    (*(code *)PTR_CFDictionarySetCString_00568e1c)(iVar7,puVar1 + -0x48b4,local_1050,0xffffffff);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  local_1050[0] = '\0';
  (*local_30)(iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x47f4,local_1050,0x1001,0);
  if (local_1050[0] == '\0') {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x47f4,0,0);
    if (iVar2 != 0) {
      (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x47f4,iVar2);
      (*(code *)PTR_CFRelease_00568d1c)(iVar2);
    }
  }
  else {
    (*(code *)PTR_CFDictionarySetCString_00568e1c)(iVar7,puVar1 + -0x47f4,local_1050,0xffffffff);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x47d8,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x47d8,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x47c4,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x47c4,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_kCFLBooleanTrue_00568ce8;
  (*(code *)PTR_CFDictionarySetValue_00568d14)
            (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x47ac,
             *(undefined4 *)PTR_kCFLBooleanTrue_00568ce8);
  (*(code *)PTR_CFDictionarySetValue_00568d14)
            (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4788,*(undefined4 *)puVar1);
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x476c);
  if (iVar2 == 0) {
LAB_00469954:
    iVar3 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x476c,0,0);
    if (iVar3 != 0) goto LAB_004690ec;
  }
  else {
    iVar3 = (*(code *)PTR_CFGetTypeID_00568cc0)(iVar2);
    iVar4 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
    if (iVar3 != iVar4) goto LAB_00469954;
    iVar3 = (*(code *)PTR_CFArrayCreateMutable_00568e2c)
                      (0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
    local_48 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar2);
    local_4c = 0;
    (*(code *)PTR_CFLArrayApplyFunction_00568e34)(iVar2,0,local_48,PTR_LAB_00568ccc + 0x5db0,iVar3);
    if (iVar3 == 0) goto LAB_00469954;
LAB_004690ec:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x476c,iVar3);
    (*(code *)PTR_CFRelease_00568d1c)(iVar3);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4750,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4750,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  local_1050[0] = '\0';
  (*local_30)(iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x473c,local_1050,0x1001,0);
  if (local_1050[0] == '\0') {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x473c,0,0);
    if (iVar2 != 0) {
      (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x473c,iVar2);
      (*(code *)PTR_CFRelease_00568d1c)(iVar2);
    }
  }
  else {
    (*(code *)PTR_CFDictionarySetCString_00568e1c)(iVar7,puVar1 + -0x473c,local_1050,0xffffffff);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x498c,0,0);
  if (iVar2 == 0) {
    local_1050[0] = '\0';
    FUN_00466e30(iVar6,local_1050,0x1001);
    (*(code *)PTR_CFDictionarySetCString_00568e1c)(iVar7,puVar1 + -0x498c,local_1050,0xffffffff);
  }
  else {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x498c,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverSessionPlatformCopyProperty_00568e38)
                    (param_1,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4724,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4724,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  local_1050[0] = '\0';
  AirPlayGetDeviceName(local_1050,0x1001);
  (*(code *)PTR_CFDictionarySetCString_00568e1c)
            (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4714,local_1050,0xffffffff);
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4704,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4704,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  local_1050[0] = '\0';
  (*local_30)(iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x46f0,local_1050,0x1001,0);
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  if (((local_1050[0] != '\0') &&
      (iVar2 = (*(code *)PTR_CFDataCreateWithFilePath_00568e3c)(local_1050,0), iVar2 != 0)) ||
     (iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                        (iVar6,1,puVar1 + -0x46dc,0,0), iVar2 != 0)) {
    local_2c = iVar2;
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x46dc,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(local_2c);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x46cc);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x46cc,0,0);
    if (iVar2 != 0) goto LAB_00469454;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_00469454:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x46cc,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  local_1050[0] = '\0';
  (*local_30)(iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x46b8,local_1050,0x1001,0);
  if (local_1050[0] == '\0') {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x46b8,0,0);
    if (iVar2 != 0) {
      (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x46b8,iVar2);
      (*(code *)PTR_CFRelease_00568d1c)(iVar2);
    }
  }
  else {
    (*(code *)PTR_CFDictionarySetCString_00568e1c)(iVar7,puVar1 + -0x46b8,local_1050,0xffffffff);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x46a0);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x46a0,0,0);
    if (iVar2 != 0) goto LAB_0046954c;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_0046954c:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x46a0,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4688);
  if (iVar2 == 0) {
LAB_004699e4:
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -0x4688,0,0);
    if (iVar2 != 0) goto LAB_004695c8;
  }
  else {
    iVar3 = (*(code *)PTR_CFGetTypeID_00568cc0)(iVar2);
    iVar4 = (*(code *)PTR_CFStringGetTypeID_00568cd0)();
    if (iVar3 != iVar4) goto LAB_004699e4;
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_004695c8:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4688,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4678,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4678,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  iVar2 = AirPlayCopyHomeKitPairingIdentity(&local_3c,0);
  if (iVar2 == 0) {
    (*(code *)PTR_CFDictionarySetCString_00568e1c)
              (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x465c,local_3c,0xffffffff);
    (*(code *)PTR_free_00568d70)(local_3c);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)
                    (*(undefined4 *)(iVar6 + 0x7c),
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -18000);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                      (iVar6,1,puVar1 + -18000,0,0);
    if (iVar2 != 0) goto LAB_004696bc;
  }
  else {
    (*(code *)PTR_CFRetain_00568cf0)(iVar2);
LAB_004696bc:
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -18000,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  (*(code *)PTR_CFDictionarySetValue_00568d14)
            (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x49fc,
             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4a20);
  iVar2 = AirPlayGetStatusFlags(iVar6);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x48c8,iVar2,0);
  }
  if (param_2 != 0) {
    uVar5 = (*(code *)PTR_CFArrayGetCount_00568e30)(param_2);
    puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
    iVar2 = (*(code *)PTR_CFArrayContainsValue_00568e40)
                      (param_2,0,uVar5,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4638);
    if (iVar2 != 0) {
      local_38[0] = 0;
      FUN_004679b8(iVar6,local_38);
      if (local_38[0] != 0) {
        (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4638);
        (*(code *)PTR_CFRelease_00568d1c)(local_38[0]);
      }
    }
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4624,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4624,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar2 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4608,0,0);
  if (iVar2 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x4608,iVar2);
    (*(code *)PTR_CFRelease_00568d1c)(iVar2);
  }
  puVar1 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  iVar6 = (*(code *)PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4)
                    (iVar6,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x45e4,0,0);
  uVar5 = 0;
  if (iVar6 != 0) {
    (*(code *)PTR_CFDictionarySetValue_00568d14)(iVar7,puVar1 + -0x45e4,iVar6);
    (*(code *)PTR_CFRelease_00568d1c)(iVar6);
    uVar5 = 0;
  }
LAB_004698b4:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar5;
  }
  return iVar7;
}



/* === AirPlayReceiverSessionCopyProperty @ 00474c90 === */

void AirPlayReceiverSessionCopyProperty
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  int iVar1;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d48);
  if (iVar1 == 0) {
    AirPlayReceiverSessionPlatformCopyProperty(param_1,param_2,local_18,local_14,local_20);
  }
  else {
    iVar1 = CFNumberCreate(0,3,param_1 + 0x88);
    local_20[0] = 0xffffe5b8;
    if (iVar1 != 0) {
      local_20[0] = 0;
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_20[0];
  }
  return;
}



/* === AirPlayReceiverSessionSetup @ 00477fd4 === */

/* WARNING: Removing unreachable block (ram,0x00478c50) */
/* WARNING: Removing unreachable block (ram,0x00478cd4) */
/* WARNING: Type propagation algorithm not settling */

undefined4 ******* AirPlayReceiverSessionSetup(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *******pppppppuVar7;
  undefined *puVar8;
  undefined4 *******pppppppuVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 *******pppppppuVar12;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  int iVar18;
  int *piVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  uint uVar22;
  double dVar23;
  undefined8 uVar24;
  double dVar25;
  ulonglong uVar26;
  longlong lVar27;
  undefined8 uVar28;
  longlong lVar29;
  undefined1 local_170 [4];
  uint local_16c;
  undefined4 local_168;
  int local_164;
  undefined4 local_160;
  int local_15c;
  int local_158;
  uint local_154;
  undefined4 local_150;
  undefined1 local_14c [4];
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  uint local_13c;
  undefined4 local_138;
  int local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_128 [4];
  undefined4 local_124;
  int local_114;
  int local_110;
  undefined1 local_104 [32];
  undefined1 auStack_e4 [32];
  undefined1 auStack_c4 [32];
  undefined4 ******local_a4 [7];
  undefined4 *******local_88;
  undefined4 *******local_84;
  undefined4 *******local_80 [2];
  int local_78;
  undefined8 local_74;
  int local_6c;
  int local_68;
  undefined4 *******local_64;
  int local_60;
  int local_5c;
  undefined4 *******local_58;
  undefined4 *local_54;
  undefined *local_50;
  undefined *local_4c;
  int *local_48;
  undefined *local_44;
  undefined *local_40;
  
  puVar3 = PTR_gLogCategory_AirPlayReceiverCore_00569b78;
  if ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 < 0x1f) &&
     ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 != -1 ||
      (iVar4 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                         (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x1e), iVar4 != 0)))) {
    uVar20 = *(undefined4 *)(param_1 + 0xd0);
    uVar21 = *(undefined4 *)(param_1 + 0xd4);
    if ((*(int *)puVar3 < 0x15) &&
       ((*(int *)puVar3 != -1 ||
        (iVar4 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                           (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x14), iVar4 != 0)))) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    (*(code *)PTR_LogPrintF_00568d20)
              (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30,0x1e,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x25b4,uVar20,uVar21,param_1 + 0x8c,
               uVar5,param_2);
  }
  iVar4 = CFDictionaryCreateMutable
                    (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                     PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
  puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
  if (iVar4 == 0) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x258c,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,899,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30,0);
    local_80[0] = (undefined4 *******)0xffffe5b8;
  }
  else {
    if (*(char *)(param_1 + 0x3cc) == '\0') {
      iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                        (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d6c,0);
      if (iVar6 < 1) {
        iVar6 = 0x1772;
      }
      *(int *)(param_1 + 0x1780) = iVar6;
      pppppppuVar7 = (undefined4 *******)AirTunesClock_Create(param_1 + 0x1774);
      if (pppppppuVar7 == (undefined4 *******)0x0) {
        pppppppuVar7 = (undefined4 *******)FUN_0046f9b0(param_1);
        if (pppppppuVar7 != (undefined4 *******)0x0) {
          uVar20 = 0x75f;
          goto LAB_004781cc;
        }
        (*(code *)PTR_CFDictionarySetInt64_00568e20)
                  (iVar4,puVar8 + -0x1d6c,*(int *)(param_1 + 0x177c),
                   *(int *)(param_1 + 0x177c) >> 0x1f);
        lVar27 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                           (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1cd8,0);
        if (lVar27 != 0) {
          if (-1 < *(int *)(param_1 + 0x17b4)) {
            (*(code *)PTR_DebugPrintAssert_00568cd8)
                      (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x257c,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xec8,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf74,0);
          }
          (*(code *)PTR_SockAddrCopy_00569280)(param_1 + 0x8c,local_170);
          pppppppuVar9 = (undefined4 *******)
                         (*(code *)PTR_ServerSocketOpen_00569348)
                                   ((uint)local_170 & 0xffff,1,0x11,0,param_1 + 0x17b8,0xffffffff,
                                    param_1 + 0x17b4);
          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
          if (pppppppuVar9 == (undefined4 *******)0x0) {
            (*(code *)PTR_SocketSetQoS_00569350)(*(undefined4 *)(param_1 + 0x17b4),1);
            if ((*(int *)puVar3 < 0x1f) &&
               ((*(int *)puVar3 != -1 ||
                (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                   (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x1e), iVar6 != 0)
                ))) {
              (*(code *)PTR_LogPrintF_00568d20)
                        (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf74,0x1e,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2244,
                         *(undefined4 *)(param_1 + 0x17b8));
            }
LAB_004783dc:
            (*(code *)PTR_CFDictionarySetInt64_00568e20)
                      (iVar4,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1cbc,
                       *(int *)(param_1 + 0x17b8),*(int *)(param_1 + 0x17b8) >> 0x1f);
            goto LAB_004783fc;
          }
          (*(code *)PTR_DebugPrintAssert_00568cd8)
                    (0,pppppppuVar9,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xecf,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf74,0);
          if ((*(int *)puVar3 < 0x3d) &&
             ((*(int *)puVar3 != -1 ||
              (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                 (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x3c), iVar6 != 0)))
             ) {
            (*(code *)PTR_LogPrintF_00568d20)
                      (PTR_gLogCategory_AirPlayReceiverCore_00569b78,puVar8 + -0xf74,0x3c,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2224,pppppppuVar9);
          }
          FUN_0046e6f4(param_1);
          if (pppppppuVar9 == (undefined4 *******)0x0) goto LAB_004783dc;
          uVar20 = 0x767;
          pppppppuVar7 = pppppppuVar9;
LAB_00478464:
          (*(code *)PTR_DebugPrintAssert_00568cd8)
                    (0,pppppppuVar7,0,puVar8 + -0x3f10,uVar20,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf40,0);
          goto LAB_004784d8;
        }
LAB_004783fc:
        if (*(char *)(param_1 + 0x3cd) != '\0') {
          pppppppuVar9 = (undefined4 *******)
                         (*(code *)PTR_ServerSocketOpen_00569348)
                                   (*(undefined2 *)(param_1 + 0x8c),2,6,0,param_1 + 0x3e4,0xffffffff
                                    ,param_1 + 0x3e0);
          if (pppppppuVar9 != (undefined4 *******)0x0) {
            uVar20 = 0x76f;
            pppppppuVar7 = pppppppuVar9;
            puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
            goto LAB_00478464;
          }
          (*(code *)PTR_CFDictionarySetInt64_00568e20)
                    (iVar4,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1ca4,
                     *(int *)(param_1 + 0x3e4),*(int *)(param_1 + 0x3e4) >> 0x1f);
          if ((*(int *)puVar3 < 0x1f) &&
             ((*(int *)puVar3 != -1 ||
              (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                 (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x1e), iVar6 != 0)))
             ) {
            (*(code *)PTR_LogPrintF_00568d20)
                      (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf40,0x1e,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2200,
                       *(undefined4 *)(param_1 + 0x3e4));
          }
        }
        *(undefined1 *)(param_1 + 0x3cc) = 1;
      }
      else {
        uVar20 = 0x75c;
LAB_004781cc:
        (*(code *)PTR_DebugPrintAssert_00568cd8)
                  (0,pppppppuVar7,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,uVar20,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf40,0);
LAB_004784d8:
        FUN_0046ee80(param_1);
        if ((*(int *)puVar3 < 0x3d) &&
           ((*(int *)puVar3 != -1 ||
            (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                               (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x3c), iVar6 != 0))))
        {
          (*(code *)PTR_LogPrintF_00568d20)
                    (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf40,0x3c,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x21e4,pppppppuVar7);
        }
      }
      local_80[0] = pppppppuVar7;
      if (pppppppuVar7 == (undefined4 *******)0x0) goto LAB_00478550;
      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
      uVar20 = 0x388;
      puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
    }
    else {
LAB_00478550:
      pppppppuVar7 = local_80;
      local_58 = pppppppuVar7;
      (*(code *)PTR_CFDictionaryGetCString_00568ce0)
                (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c90,auStack_c4,0x20,
                 pppppppuVar7);
      if (local_80[0] == (undefined4 *******)0x0) {
        (*(code *)PTR_strlcpy_00568d78)(param_1 + 0x48,auStack_c4,0x20);
        local_80[0] = (undefined4 *******)
                      AirPlayGetMinimumClientOSBuildVersion
                                (*(undefined4 *)(param_1 + 0xc),auStack_e4,0x20);
        if (local_80[0] == (undefined4 *******)0x0) {
          iVar6 = _CompareOSBuildVersionStrings(auStack_e4,auStack_c4);
          if (0 < iVar6) {
            local_80[0] = (undefined4 *******)0xffffe5c5;
            puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
            uVar20 = 0x395;
            puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
            goto LAB_0047aafc;
          }
        }
      }
      uVar20 = CFArrayGetTypeID();
      local_60 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                           (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d58,uVar20,
                            local_58);
      if (local_60 == 0) {
        local_6c = 0;
        cVar1 = *(char *)(param_1 + 0x3e9);
LAB_0047aa60:
        if (cVar1 == '\0') goto LAB_0047aa6c;
LAB_0047aaa4:
        local_80[0] = (undefined4 *******)
                      AirPlayReceiverSessionPlatformControl
                                (param_1,1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b9c,0
                                 ,param_2,0);
        puVar8 = PTR_DAT_00568d8c;
        if (local_80[0] == (undefined4 *******)0x0) {
          if (local_6c != 0) {
            *(int *)(param_1 + 0x1818) =
                 *(int *)(param_1 + 0x176c) + *(int *)(PTR_DAT_00568d8c + -0x423c);
            if (*(int *)puVar3 < 0x15) {
              if (*(int *)puVar3 == -1) {
                iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                  (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x14);
                if (iVar6 == 0) goto LAB_0047ab80;
              }
              (*(code *)PTR_LogPrintF_00568d20)
                        (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1288,0x14,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x20ec,
                         *(undefined4 *)(param_1 + 0x1818),*(undefined4 *)(param_1 + 0x176c),
                         *(undefined4 *)(puVar8 + -0x423c));
            }
          }
LAB_0047ab80:
          *param_3 = iVar4;
          *(int *)PTR_gAirTunes_00569be8 = param_1;
          return (undefined4 *******)0x0;
        }
        uVar20 = 0x3c7;
      }
      else {
        local_5c = CFArrayGetCount(local_60);
        local_68 = 0;
        local_4c = PTR_s_yController___p__0052fff0_0x10_00568cdc;
        local_6c = 0;
        uVar24 = *(undefined8 *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd20);
        local_40 = PTR_s__0051fff8_8_00568c5c;
        dVar25 = *(double *)(PTR_s__0051fff8_8_00568c5c + 0x1220);
        for (; local_68 < local_5c; local_68 = local_68 + 1) {
          uVar20 = CFDictionaryGetTypeID();
          uVar20 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)
                             (local_60,local_68,uVar20,local_58);
          if (local_80[0] != (undefined4 *******)0x0) {
            puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
            uVar20 = 0x3a0;
LAB_00479860:
            puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
            goto LAB_0047aafc;
          }
          pppppppuVar9 = (undefined4 *******)
                         (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar20,local_4c + -0x1d00,0);
          puVar17 = PTR_CFDictionaryGetInt64_00568d00;
          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
          local_50 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
          if (pppppppuVar9 == (undefined4 *******)0x66) {
            *(undefined4 *)(param_1 + 0xb34) = 0;
            if (*(int *)(param_1 + 0x40c) < 0) {
              iVar6 = CFDictionaryCreateMutable
                                (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                 PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
              if (iVar6 == 0) {
                pppppppuVar7 = (undefined4 *******)0x7f1;
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2530,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x7f1,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,0);
                local_88 = (undefined4 *******)0xffffe5b8;
              }
              else {
                lVar27 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                   (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c78,
                                    &local_88);
                if (local_88 == (undefined4 *******)0x0) {
                  *(longlong *)(param_1 + 0x400) = lVar27;
                }
                else {
                  (*(code *)PTR_UUIDGet_00569460)(local_170);
                  *(uint *)(param_1 + 0x400) =
                       local_16c >> 0x18 | local_16c << 0x18 | (local_16c >> 8 & 0xff) << 0x10 |
                       (local_16c >> 0x10 & 0xff) << 8;
                  *(uint *)(param_1 + 0x404) =
                       (int)local_170 << 0x18 | ((uint)local_170 >> 8 & 0xff) << 0x10 |
                       ((uint)local_170 >> 0x10 & 0xff) << 8 | (uint)local_170 >> 0x18;
                  local_88 = (undefined4 *******)0x0;
                }
                if ((*(int *)(param_1 + 0x3ec) == 0) || (lVar27 != 0)) {
                  for (puVar10 = (undefined1 *)(param_1 + 0x870);
                      puVar10 != (undefined1 *)(param_1 + 0x988); puVar10 = puVar10 + 1) {
                    *puVar10 = 0;
                  }
                  if ((lVar27 != 0) && (*(int *)(param_1 + 0x3ec) != 0)) {
                    local_88 = (undefined4 *******)FUN_00474254(param_1 + 0x3ec);
                    if (local_88 == (undefined4 *******)0x0) {
                      (*(code *)PTR_memset_0056a728)(param_1 + 0x980,0,8);
                      (*(code *)PTR_memcpy_0056aa64)(param_1 + 0x960,local_104,0x20);
                      *(undefined1 *)(param_1 + 0x870) = 1;
                      goto LAB_004789ac;
                    }
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                    pppppppuVar7 = (undefined4 *******)0x807;
                    goto LAB_004797b8;
                  }
LAB_004789ac:
                  *(undefined4 *)(param_1 + 0x3f4) = 0x66;
                  puVar8 = PTR_CFDictionaryGetInt64_00568d00;
                  puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c5c;
                  *(undefined **)(param_1 + 0x3f8) =
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2508;
                  uVar21 = (*(code *)puVar8)(uVar20,puVar17,0);
                  *(undefined4 *)(param_1 + 0xf0) = uVar21;
                  uVar26 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                     (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c50
                                      ,0);
                  if (uVar26 == 0) {
                    iVar13 = *(int *)(param_1 + 0xf0);
                    if (iVar13 == 1) {
                      uVar22 = 0x800;
LAB_00478a50:
                      uVar26 = (ulonglong)uVar22;
                      goto LAB_00478a54;
                    }
                    if (iVar13 == 4) {
                      uVar22 = 0x400000;
                      goto LAB_00478a50;
                    }
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x24fc;
                    pppppppuVar7 = (undefined4 *******)0x818;
LAB_004793e4:
                    (*(code *)PTR_DebugPrintAssert_00568cd8)
                              (0,0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,
                               pppppppuVar7,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,
                               puVar8,iVar13);
                    local_88 = (undefined4 *******)0xffffe5b1;
                  }
                  else {
LAB_00478a54:
                    local_88 = (undefined4 *******)
                               AirPlayAudioFormatToASBD
                                         ((int)uVar26,(int)(uVar26 >> 0x20),local_128,
                                          param_1 + 0x54c);
                    if (local_88 != (undefined4 *******)0x0) {
                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                      pppppppuVar7 = (undefined4 *******)0x81b;
                      goto LAB_004797b8;
                    }
                    iVar13 = *(int *)(param_1 + 0xf0);
                    if (iVar13 == 0) {
                      uVar21 = AudioFormatIDToAirPlayCompressionType(local_124);
                      *(undefined4 *)(param_1 + 0xf0) = uVar21;
                    }
                    else {
                      iVar11 = AudioFormatIDToAirPlayCompressionType(local_124);
                      if (iVar13 != iVar11) {
                        (*(code *)PTR_DebugPrintAssert_00568cd8)
                                  (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x24e0,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x823,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,0);
                      }
                    }
                    *(undefined1 (*) [4])(param_1 + 0x53c) = local_128;
                    *(int *)(param_1 + 0x540) = local_110;
                    *(int *)(param_1 + 0x544) = local_114;
                    if (local_114 == 0) {
                      *(uint *)(param_1 + 0x544) =
                           (*(int *)(param_1 + 0x54c) + 7U >> 3) * local_110 * 8 >> 3;
                    }
                    puVar8 = PTR_CFDictionaryGetInt64_00568d00;
                    puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c3c;
                    *(undefined1 *)(param_1 + 0x1338) = 0;
                    uVar21 = (*(code *)puVar8)(uVar20,puVar17,0);
                    puVar17 = PTR_CFDictionaryGetInt64_00568d00;
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
                    *(undefined4 *)(param_1 + 0x1334) = uVar21;
                    lVar27 = (*(code *)puVar17)(uVar20,puVar8 + -0x1c24,0);
                    puVar17 = PTR_CFDictionaryGetInt64_00568d00;
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
                    *(bool *)(param_1 + 0x3c0) = lVar27 != 0;
                    iVar13 = (*(code *)puVar17)(uVar20,puVar8 + -0x1c10,0);
                    puVar17 = PTR_CFDictionaryGetInt64_00568d00;
                    if (iVar13 < 1) {
                      iVar13 = 0x1771;
                    }
                    puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1bfc;
                    *(int *)(param_1 + 0x1744) = iVar13;
                    iVar13 = (*(code *)puVar17)(uVar20,puVar16,0);
                    iVar11 = (*(code *)PTR_prop_get_int_0056abb0)
                                       (PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2490,0);
                    if (iVar11 == 0) {
                      (*(code *)PTR_puts_0056a780)
                                (PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2470);
LAB_00478c38:
                      if (iVar13 != 0) goto LAB_00478c40;
                      uVar21 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                         (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                 -0x1be4,0);
                      *(undefined4 *)(param_1 + 0x176c) = uVar21;
                      uVar21 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                         (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                 -0x1bd0,0);
                      *(undefined4 *)(param_1 + 6000) = uVar21;
                    }
                    else {
                      if (700 < iVar11 - 300U) goto LAB_00478c38;
                      local_78 = iVar11;
                      (*(code *)PTR_printf_0056a7c8)
                                (PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2454,iVar11);
                      iVar13 = local_78;
LAB_00478c40:
                      uVar22 = (uint)(iVar13 * *(int *)(param_1 + 0x53c)) / 1000;
                      *(uint *)(param_1 + 0x176c) = uVar22;
                      *(uint *)(param_1 + 6000) = uVar22;
                    }
                    puVar17 = PTR_CFDictionaryGetInt64_00568d00;
                    uVar21 = 10;
                    if (*(char *)(param_1 + 0x3c0) != '\0') {
                      uVar21 = 0xb;
                    }
                    puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1bbc;
                    *(undefined4 *)(param_1 + 0x3c8) = uVar21;
                    uVar22 = (*(code *)puVar17)(uVar20,puVar16,0);
                    *(uint *)(param_1 + 0x3c4) = uVar22;
                    puVar17 = PTR_SecondsToUpTicks_00569c10;
                    uVar22 = (uVar22 / 0x1b9 + uVar22 + 0x10) * *(int *)(param_1 + 0x544);
                    *(undefined4 *)(param_1 + 0x17c8) = 0x200;
                    if (uVar22 < 0x5c0) {
                      uVar22 = 0x5c0;
                    }
                    *(uint *)(param_1 + 0x17cc) = uVar22 + 0xc;
                    *(undefined4 *)(param_1 + 0x550) = 0;
                    *(undefined4 *)(param_1 + 0x554) = 0;
                    uVar28 = (*(code *)puVar17)(1,0);
                    *(undefined8 *)(param_1 + 0x558) = uVar28;
                    *(undefined4 *)(param_1 + 0x830) = 0;
                    puVar17 = PTR_pthread_mutex_init_0056a8e0;
                    dVar23 = (double)*(int *)(param_1 + 0x53c);
                    if (*(int *)(param_1 + 0x53c) < 0) {
                      dVar23 = dVar23 + dVar25;
                    }
                    *(float *)(param_1 + 0x834) = (float)dVar23;
                    local_88 = (undefined4 *******)(*(code *)puVar17)(param_1 + 0x850,0);
                    puVar17 = PTR_pthread_mutex_init_0056a8e0;
                    if (local_88 == (undefined4 *******)0x0) {
                      *(int *)(param_1 + 0x868) = param_1 + 0x850;
                      *(undefined1 *)(param_1 + 0xb88) = 0;
                      local_88 = (undefined4 *******)(*(code *)puVar17)(param_1 + 0xb6c,0);
                      puVar17 = PTR_pthread_cond_init_0056a86c;
                      if (local_88 == (undefined4 *******)0x0) {
                        *(int *)(param_1 + 0xb84) = param_1 + 0xb6c;
                        local_88 = (undefined4 *******)(*(code *)puVar17)(param_1 + 0xb38,0);
                        puVar17 = PTR_ServerSocketOpen_00569348;
                        if (local_88 == (undefined4 *******)0x0) {
                          *(int *)(param_1 + 0xb68) = param_1 + 0xb38;
                          local_88 = (undefined4 *******)
                                     (*(code *)puVar17)(*(undefined2 *)(param_1 + 0x8c),1,0x11,0,
                                                        param_1 + 0x1330,0xfff80000,param_1 + 0x40c)
                          ;
                          if (local_88 == (undefined4 *******)0x0) {
                            (*(code *)PTR_SocketSetQoS_00569350)
                                      (*(undefined4 *)(param_1 + 0x40c),
                                       *(undefined4 *)(param_1 + 0x3c8));
                            local_88 = (undefined4 *******)
                                       (*(code *)PTR_OpenSelfConnectedLoopbackSocket_0056932c)
                                                 (param_1 + 0x408);
                            if (local_88 == (undefined4 *******)0x0) {
                              pppppppuVar9 = local_a4;
                              (*(code *)PTR_SockAddrCopy_00569280)(param_1 + 0x8c,pppppppuVar9);
                              pppppppuVar7 = (undefined4 *******)(param_1 + 0x1740);
                              local_88 = (undefined4 *******)
                                         (*(code *)PTR_ServerSocketOpen_00569348)
                                                   ((uint)local_a4[0] & 0xffff,1,0x11,0,pppppppuVar7
                                                    ,0xfff80000,param_1 + 0x173c);
                              if (local_88 == (undefined4 *******)0x0) {
                                (*(code *)PTR_SocketSetPacketTimestamps_0056934c)
                                          (*(undefined4 *)(param_1 + 0x173c),1);
                                (*(code *)PTR_SocketSetQoS_00569350)
                                          (*(undefined4 *)(param_1 + 0x173c),
                                           *(undefined4 *)(param_1 + 0x3c8));
                                (*(code *)PTR_SockAddrSetPort_0056928c)
                                          (pppppppuVar9,*(undefined4 *)(param_1 + 0x1744));
                                (*(code *)PTR_memcpy_0056aa64)(param_1 + 0x1748,pppppppuVar9,0x1c);
                                uVar20 = (*(code *)PTR_SockAddrGetSize_005692a4)(pppppppuVar9);
                                *(undefined4 *)(param_1 + 0x1764) = uVar20;
                                iVar13 = (*(code *)PTR_connect_0056aad0)
                                                   (*(undefined4 *)(param_1 + 0x173c),pppppppuVar9,
                                                    uVar20);
                                pppppppuVar12 = (undefined4 *******)0x0;
                                if (iVar13 != 0) {
                                  puVar15 = (undefined4 *)(*(code *)PTR___errno_location_0056a998)()
                                  ;
                                  pppppppuVar12 = (undefined4 *******)*puVar15;
                                  if (pppppppuVar12 == (undefined4 *******)0x0) {
                                    pppppppuVar12 = (undefined4 *******)0xffffe5d4;
                                  }
                                }
                                local_88 = pppppppuVar12;
                                if ((pppppppuVar12 != (undefined4 *******)0x0) &&
                                   (*(int *)PTR_gLogCategory_DebugServicesLogging_00568f40 < 0x33))
                                {
                                  if (*(int *)PTR_gLogCategory_DebugServicesLogging_00568f40 == -1)
                                  {
                                    iVar13 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                                       (
                                                  PTR_gLogCategory_DebugServicesLogging_00568f40,
                                                  0x32);
                                    if (iVar13 == 0) goto LAB_00478fe8;
                                  }
                                  (*(code *)PTR_LogPrintF_00568d20)
                                            (PTR_gLogCategory_DebugServicesLogging_00568f40,
                                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,
                                             0x32,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x21c4,pppppppuVar9,local_88);
                                  pppppppuVar7 = pppppppuVar9;
                                }
LAB_00478fe8:
                                *(bool *)(param_1 + 0x1768) = local_88 == (undefined4 *******)0x0;
                                if (*(int *)(param_1 + 0x1334) == 0) {
                                  iVar13 = (*(code *)PTR_malloc_00568eb4)(0xc000);
                                  *(int *)(param_1 + 0x340) = iVar13;
                                  if (iVar13 != 0) {
                                    iVar11 = iVar13 + 0x60;
                                    do {
                                      *(int *)(iVar11 + -0x60) = iVar11;
                                      iVar11 = iVar11 + 0x60;
                                    } while (iVar11 != iVar13 + 0xc000);
                                    *(int *)(param_1 + 0x344) = iVar13;
                                    *(undefined4 *)(param_1 + 0x350) = 0xffffffff;
                                    *(undefined4 *)(iVar13 + 0xbfa0) = 0;
                                    *(undefined4 *)(param_1 + 0x358) = 0;
                                    uVar22 = *(uint *)(param_1 + 0x3c4);
                                    *(undefined4 *)(param_1 + 0x354) = 0x7fffffff;
                                    *(undefined4 *)(param_1 + 0x360) = 100000000;
                                    *(undefined4 *)(param_1 + 0x370) = 100000000;
                                    *(undefined4 *)(param_1 + 0x35c) = 0x80000000;
                                    *(undefined4 *)(param_1 + 0x388) = 0xffffffff;
                                    *(undefined4 *)(param_1 + 0x3a0) = 0xffffffff;
                                    *(undefined4 *)(param_1 + 0x364) = 0;
                                    *(undefined4 *)(param_1 + 0x374) = 0;
                                    *(undefined4 *)(param_1 + 0x38c) = 0xffffffff;
                                    *(undefined4 *)(param_1 + 0x3a4) = 0xffffffff;
                                    if (uVar22 == 0) {
                                      trap(7);
                                    }
                                    *(undefined4 *)(param_1 + 0x348) = 0;
                                    *(undefined1 *)(param_1 + 0x34c) = 0;
                                    *(uint *)(param_1 + 0x3b0) =
                                         ((uVar22 >> 1) + *(int *)(param_1 + 0x176c)) / uVar22 >> 1;
                                    goto LAB_004790fc;
                                  }
                                  puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                                  pppppppuVar7 = (undefined4 *******)0x880;
                                  puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
                                  puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2438;
                                }
                                else {
                                  *(undefined1 *)(param_1 + 0x34c) = 1;
LAB_004790fc:
                                  iVar13 = *(int *)(param_1 + 0x17c8);
                                  piVar19 = (int *)(*(code *)PTR_malloc_00568eb4)(iVar13 * 0x1c);
                                  *(int **)(param_1 + 0x17d4) = piVar19;
                                  if (piVar19 == (int *)0x0) {
                                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                                    pppppppuVar7 = (undefined4 *******)0x8a1;
                                    puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                              -0x3f10;
                                    puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                              -0x2420;
                                  }
                                  else {
                                    local_74._0_4_ = *(int *)(param_1 + 0x17cc);
                                    local_78 = iVar13 * (int)local_74;
                                    local_74._4_4_ = piVar19;
                                    iVar11 = (*(code *)PTR_malloc_00568eb4)(local_78);
                                    *(int *)(param_1 + 0x17d0) = iVar11;
                                    if (iVar11 == 0) {
                                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                               -0xf88;
                                      pppppppuVar7 = (undefined4 *******)0x8a4;
                                      puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                -0x3f10;
                                      puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                -0x2408;
                                    }
                                    else {
                                      uVar22 = 0;
                                      iVar18 = iVar11;
                                      piVar19 = local_74._4_4_;
                                      while( true ) {
                                        bVar2 = iVar13 - 1U <= uVar22;
                                        uVar22 = uVar22 + 1;
                                        if (bVar2) break;
                                        piVar19[5] = iVar18;
                                        *piVar19 = (int)(piVar19 + 7);
                                        iVar18 = iVar18 + (int)local_74;
                                        piVar19 = piVar19 + 7;
                                      }
                                      iVar18 = iVar11 + (local_78 - (int)local_74);
                                      (local_74._4_4_ + iVar13 * 7 + -7)[5] = iVar18;
                                      local_74._4_4_[iVar13 * 7 + -7] = 0;
                                      if (iVar18 + (int)local_74 != iVar11 + local_78) {
                                        pppppppuVar7 = (undefined4 *******)0x8b1;
                                        (*(code *)PTR_DebugPrintAssert_00568cd8)
                                                  (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc
                                                       + -0x23f0,
                                                   PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0x3f10,0x8b1,
                                                   PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0xf88,0);
                                      }
                                      *(undefined4 *)(param_1 + 0x17fc) = 0;
                                      *(undefined4 *)(param_1 + 0x17f8) =
                                           *(undefined4 *)(param_1 + 0x17d4);
                                      iVar13 = param_1 + 0x17d8;
                                      *(int *)(param_1 + 0x17dc) = iVar13;
                                      *(int *)(param_1 + 0x17d8) = iVar13;
                                      *(int *)(param_1 + 0x17f4) = iVar13;
                                      iVar13 = *(int *)(param_1 + 0xf0);
                                      if (iVar13 == 4) {
                                        local_170 = *(undefined1 (*) [4])(param_1 + 0x53c);
                                        local_148 = 0x61616320;
                                        local_13c = 0x400;
                                        local_154 = *(uint *)(param_1 + 0x54c);
                                        local_158 = *(int *)(param_1 + 0x540);
                                        local_16c = 0x6c70636d;
                                        local_168 = 0xc;
                                        local_164 = (local_154 >> 3) * local_158;
                                        local_160 = 1;
                                        local_144 = 0;
                                        local_140 = 0;
                                        local_138 = 0;
                                        local_130 = 0;
                                        local_12c = 0;
                                        local_150 = 0;
                                        local_15c = local_164;
                                        local_14c = local_170;
                                        local_134 = local_158;
                                        pppppppuVar9 = (undefined4 *******)
                                                       (*(code *)PTR_AudioConverterNew_00569c14)
                                                                 (local_14c,local_170,
                                                                  param_1 + 0x183c);
                                        if (pppppppuVar9 != (undefined4 *******)0x0) {
                                          (*(code *)PTR_DebugPrintAssert_00568cd8)
                                                    (0,pppppppuVar9,0,
                                                     PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                     -0x3f10,0x128f,
                                                     PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                     -0x1100,0);
                                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0xf88;
                                          pppppppuVar7 = (undefined4 *******)0x8bf;
                                          local_88 = pppppppuVar9;
                                          goto LAB_004797b8;
                                        }
                                      }
                                      else {
                                        pppppppuVar9 = local_88;
                                        if (iVar13 != 1) {
                                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0x23a4;
                                          pppppppuVar7 = (undefined4 *******)0x8c9;
                                          goto LAB_004793e4;
                                        }
                                      }
                                      local_88 = pppppppuVar9;
                                      puVar17 = PTR_malloc_00568eb4;
                                      uVar20 = *(undefined4 *)(param_1 + 0x17cc);
                                      *(undefined4 *)(param_1 + 0x1804) = uVar20;
                                      iVar13 = (*(code *)puVar17)(uVar20);
                                      *(int *)(param_1 + 0x1800) = iVar13;
                                      puVar17 = PTR_malloc_00568eb4;
                                      if (iVar13 == 0) {
                                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                 -0xf88;
                                        pppppppuVar7 = (undefined4 *******)0x8d0;
                                        puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x3f10;
                                        puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2380;
                                      }
                                      else {
                                        *(undefined4 *)(param_1 + 0x180c) = uVar20;
                                        iVar13 = (*(code *)puVar17)(uVar20);
                                        *(int *)(param_1 + 0x1808) = iVar13;
                                        puVar17 = PTR_malloc_00568eb4;
                                        if (iVar13 == 0) {
                                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0xf88;
                                          pppppppuVar7 = (undefined4 *******)0x8d4;
                                          puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                    -0x3f10;
                                          puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                    -0x236c;
                                        }
                                        else {
                                          *(undefined4 *)(param_1 + 0x1814) = uVar20;
                                          iVar13 = (*(code *)puVar17)(uVar20);
                                          *(int *)(param_1 + 0x1810) = iVar13;
                                          puVar16 = PTR_gAirPlayAudioStats_00568f28;
                                          puVar17 = PTR_CFDictionarySetInt64_00568e20;
                                          if (iVar13 != 0) {
                                            uVar20 = *(undefined4 *)(param_1 + 0x3f4);
                                            *(undefined8 *)PTR_gAirPlayAudioStats_00568f28 = uVar24;
                                            *(undefined4 *)(puVar16 + 8) = 0;
                                            *(undefined4 *)(puVar16 + 0xc) = 0;
                                            puVar16[0x10] = 0;
                                            *(undefined4 *)(puVar16 + 0x18) = 0;
                                            *(undefined4 *)(puVar16 + 0x1c) = 0;
                                            *(undefined4 *)(puVar16 + 0x20) = 0;
                                            (*(code *)puVar17)(iVar6,local_4c + -0x1d00,uVar20,0);
                                            (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                                      (iVar6,
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x1bb0,*(int *)(param_1 + 0x1330),
                                                  *(int *)(param_1 + 0x1330) >> 0x1f);
                                            (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                                      (iVar6,puVar8 + -0x1c10,
                                                       *(int *)(param_1 + 0x1740),
                                                       *(int *)(param_1 + 0x1740) >> 0x1f);
                                            if (*(int *)(param_1 + 0x3f4) == 0x66) {
                                              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                                        (iVar6,
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x1c78,*(undefined4 *)(param_1 + 0x400),
                                                  *(undefined4 *)(param_1 + 0x404));
                                            }
                                            local_88 = (undefined4 *******)FUN_00472ba4(iVar4,iVar6)
                                            ;
                                            puVar8 = PTR_gLogCategory_AirPlayReceiverCore_00569b78;
                                            if (local_88 == (undefined4 *******)0x0) {
                                              *(int *)(param_1 + 0x3f0) = param_1;
                                              iVar13 = *(int *)puVar8;
                                              if ((iVar13 < 0x1f) &&
                                                 ((iVar13 != -1 ||
                                                  (iVar13 = (*(code *)
                                                  PTR__LogCategory_Initialize_00568d10)(puVar8,0x1e)
                                                  , iVar13 != 0)))) {
                                                pppppppuVar7 = *(undefined4 ********)
                                                                (param_1 + 0x3f8);
                                                if (uVar26 == 4) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2714;
                                                }
                                                else if (uVar26 == 8) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2704;
                                                }
                                                else if (uVar26 == 0x10) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26f4;
                                                }
                                                else if (uVar26 == 0x20) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26e4;
                                                }
                                                else if (uVar26 == 0x40) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26d4;
                                                }
                                                else if (uVar26 == 0x80) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26c4;
                                                }
                                                else if (uVar26 == 0x100) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26b4;
                                                }
                                                else if (uVar26 == 0x200) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x26a4;
                                                }
                                                else if (uVar26 == 0x400) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2694;
                                                }
                                                else if (uVar26 == 0x800) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2684;
                                                }
                                                else if (uVar26 == 0x1000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2674;
                                                }
                                                else if (uVar26 == 0x2000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2664;
                                                }
                                                else if (uVar26 == 0x4000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2654;
                                                }
                                                else if (uVar26 == 0x8000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2644;
                                                }
                                                else if (uVar26 == 0x10000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2634;
                                                }
                                                else if (uVar26 == 0x20000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2624;
                                                }
                                                else if (uVar26 == 0x400000) {
                                                  puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2d0c;
                                                }
                                                else if (uVar26 == 0x800000) {
                                                  puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2d1c;
                                                }
                                                else if (uVar26 == 0x1000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2614;
                                                }
                                                else if (uVar26 == 0x2000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2604;
                                                }
                                                else if (uVar26 == 0x4000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x25f4;
                                                }
                                                else if (uVar26 == 0x8000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x25e4;
                                                }
                                                else if (uVar26 == 0x10000000) {
                                                  puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cdc;
                                                }
                                                else if (uVar26 == 0x20000000) {
                                                  puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cfc;
                                                }
                                                else if (uVar26 == 0x40000000) {
                                                  puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cec;
                                                }
                                                else if (uVar26 == 0x80000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x25d4;
                                                }
                                                else if (uVar26 == 0x100000000) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x25c4;
                                                }
                                                else {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  0x5bdc;
                                                }
                                                (*(code *)PTR_LogPrintF_00568d20)
                                                          (
                                                  PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0xf88,0x1e,
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0x2344,pppppppuVar7,puVar8,
                                                  *(undefined4 *)(param_1 + 0x1330),
                                                  *(undefined4 *)(param_1 + 0x1740));
                                              }
                                              local_74 = CONCAT44(local_74._4_4_,(int)local_74);
                                              if ((*(char *)(param_1 + 0x3ce) != '\0') &&
                                                 (local_74 = CONCAT44(local_74._4_4_,(int)local_74),
                                                 *(int *)(param_1 + 0x414) == 0)) {
                                                local_88 = (undefined4 *******)
                                                           (*(code *)PTR_pthread_create_0056a868)
                                                                     (param_1 + 0x410,0,
                                                                      PTR_LAB_00568d28 + 0x3e18,
                                                                      param_1);
                                                if (local_88 != (undefined4 *******)0x0) {
                                                  puVar8 = 
                                                  PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                  -0xf88;
                                                  pppppppuVar7 = (undefined4 *******)0x8f3;
                                                  goto LAB_004797b8;
                                                }
                                                *(int *)(param_1 + 0x414) = param_1 + 0x410;
                                              }
                                              goto LAB_004797d4;
                                            }
                                            puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                     -0xf88;
                                            pppppppuVar7 = (undefined4 *******)0x8e8;
                                            goto LAB_004797b8;
                                          }
                                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                   -0xf88;
                                          pppppppuVar7 = (undefined4 *******)0x8d8;
                                          puVar16 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                    -0x3f10;
                                          puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                    -0x235c;
                                        }
                                      }
                                    }
                                  }
                                }
                                (*(code *)PTR_DebugPrintAssert_00568cd8)
                                          (0,0,puVar17,puVar16,pppppppuVar7,puVar8,0);
                                local_88 = (undefined4 *******)0xffffe5b8;
                                goto LAB_004797d4;
                              }
                              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                              pppppppuVar7 = (undefined4 *******)0x86a;
                            }
                            else {
                              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                              pppppppuVar7 = (undefined4 *******)0x863;
                            }
                          }
                          else {
                            puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                            pppppppuVar7 = (undefined4 *******)0x85e;
                          }
                        }
                        else {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                          pppppppuVar7 = (undefined4 *******)0x857;
                        }
                      }
                      else {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                        pppppppuVar7 = (undefined4 *******)0x853;
                      }
                    }
                    else {
                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88;
                      pppppppuVar7 = (undefined4 *******)0x84e;
                    }
LAB_004797b8:
                    (*(code *)PTR_DebugPrintAssert_00568cd8)
                              (0,local_88,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,
                               pppppppuVar7,puVar8,0);
                  }
                }
                else {
                  pppppppuVar7 = (undefined4 *******)0x801;
                  (*(code *)PTR_DebugPrintAssert_00568cd8)
                            (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x251c,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x801,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,0);
                  local_88 = (undefined4 *******)0xffffe5c5;
                }
LAB_004797d4:
                CFRelease(iVar6);
              }
              if (local_88 != (undefined4 *******)0x0) {
                FUN_0046e888(param_1,param_1 + 0x3f0,0);
              }
            }
            else {
              pppppppuVar7 = (undefined4 *******)0x7ee;
              (*(code *)PTR_DebugPrintAssert_00568cd8)
                        (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2550,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x7ee,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,0);
              local_88 = (undefined4 *******)0xffffe5c1;
            }
            if (local_88 != (undefined4 *******)0x0) {
              if (*(int *)puVar3 < 0x3d) {
                if (*(int *)puVar3 == -1) {
                  iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                    (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x3c);
                  if (iVar6 != 0) goto LAB_0047aed8;
                }
                else {
LAB_0047aed8:
                  pppppppuVar7 = local_88;
                  (*(code *)PTR_LogPrintF_00568d20)
                            (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf88,0x3c,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2180,local_88);
                }
                local_80[0] = local_88;
                if (local_88 == (undefined4 *******)0x0) goto LAB_0047aa30;
              }
              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
              uVar20 = 0x3a8;
              local_80[0] = local_88;
              goto LAB_00479860;
            }
            local_80[0] = (undefined4 *******)0x0;
LAB_0047aa30:
            local_6c = 1;
          }
          else if (pppppppuVar9 < (undefined4 *******)0x67) {
            if ((undefined4 *******)0x63 < pppppppuVar9) {
              if (pppppppuVar9 == (undefined4 *******)0x65) {
                piVar19 = (int *)(param_1 + 0xb90);
                local_64 = (undefined4 *******)
                           (PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1130);
              }
              else {
                piVar19 = (int *)(param_1 + 0x3f0);
                local_64 = (undefined4 *******)
                           (PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1100);
              }
              if (*piVar19 == 0) {
                piVar19[1] = (int)pppppppuVar9;
                piVar19[2] = (int)local_64;
                lVar27 = (*(code *)puVar17)(uVar20,puVar8 + -0x1c78,&local_84);
                local_44 = puVar8;
                if (local_84 == (undefined4 *******)0x0) {
                  *(longlong *)(piVar19 + 4) = lVar27;
                }
                else {
                  local_74 = lVar27;
                  (*(code *)PTR_UUIDGet_00569460)(local_170);
                  piVar19[4] = local_16c >> 0x18 | local_16c << 0x18 |
                               (local_16c >> 8 & 0xff) << 0x10 | (local_16c >> 0x10 & 0xff) << 8;
                  piVar19[5] = (int)local_170 << 0x18 | ((uint)local_170 >> 8 & 0xff) << 0x10 |
                               ((uint)local_170 >> 0x10 & 0xff) << 8 | (uint)local_170 >> 0x18;
                  local_84 = (undefined4 *******)0x0;
                  lVar27 = local_74;
                }
                local_74 = lVar27;
                if ((*(int *)(param_1 + 0x3ec) == 0) || (lVar27 != 0)) {
                  local_78 = CFDictionaryCreateMutable
                                       (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                        PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
                  if (local_78 == 0) {
                    pppppppuVar7 = (undefined4 *******)0xd8d;
                    (*(code *)PTR_DebugPrintAssert_00568cd8)
                              (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2530,
                               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xd8d,
                               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0);
                    local_84 = (undefined4 *******)0xffffe5b8;
                  }
                  else {
                    local_84 = (undefined4 *******)
                               (*(code *)PTR_OpenSelfConnectedLoopbackSocket_0056932c)(piVar19 + 6);
                    if (local_84 == (undefined4 *******)0x0) {
                      lVar27 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                         (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                 -0x1c50,0);
                      if (lVar27 == 0) {
                        lVar27 = 0x800;
                      }
                      uVar21 = (undefined4)((ulonglong)lVar27 >> 0x20);
                      local_54 = (undefined4 *)local_14c;
                      local_84 = (undefined4 *******)
                                 AirPlayAudioFormatToASBD
                                           ((int)lVar27,uVar21,local_54,piVar19 + 0x57);
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xd97;
                        goto LAB_0047a484;
                      }
                      AirPlayAudioFormatToPCM((int)lVar27,uVar21,local_170);
                      piVar19[0x53] = (int)local_170;
                      piVar19[0x54] = local_158;
                      piVar19[0x55] = local_15c;
                      if (local_15c == 0) {
                        piVar19[0x55] = (piVar19[0x57] + 7U >> 3) * local_158 * 8 >> 3;
                      }
                      puVar8 = PTR_SecondsToUpTicks_00569c10;
                      piVar19[0x56] = local_13c;
                      piVar19[0x58] = 0;
                      piVar19[0x59] = 0;
                      uVar28 = (*(code *)puVar8)(1,0);
                      *(undefined8 *)(piVar19 + 0x5a) = uVar28;
                      piVar19[0x110] = 0;
                      puVar8 = PTR_pthread_mutex_init_0056a8e0;
                      dVar23 = (double)piVar19[0x53];
                      if (piVar19[0x53] < 0) {
                        dVar23 = dVar23 + *(double *)(local_40 + 0x1220);
                      }
                      local_48 = piVar19 + 0x118;
                      piVar19[0x111] = (int)(float)dVar23;
                      local_84 = (undefined4 *******)(*(code *)puVar8)(local_48,0);
                      puVar17 = PTR_CFDictionaryGetInt64_00568d00;
                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xda6;
                        goto LAB_0047a484;
                      }
                      piVar19[0x11e] = (int)local_48;
                      piVar19[0x187] = 0;
                      lVar29 = (*(code *)puVar17)(uVar20,puVar8 + -0x1bfc,&local_84);
                      uVar22 = (uint)lVar29;
                      if ((local_84 == (undefined4 *******)0x0) && (-1 < lVar29)) {
                        if ((lVar29 < 0x100000000) &&
                           (((int)((ulonglong)lVar29 >> 0x20) != 0 || (uVar22 < 0x20)))) {
                          uVar22 = 0x20;
                        }
                      }
                      else {
                        uVar22 = 0x20;
                        if (*(int *)(param_1 + 0x88) != 0x10) {
                          uVar22 = 0x50;
                        }
                      }
                      iVar6 = AudioFormatIDToAirPlayCompressionType(local_148);
                      piVar19[0x52] = iVar6;
                      piVar14 = piVar19 + 0x120;
                      if (iVar6 == 0) {
                        pppppppuVar7 = (undefined4 *******)0xdbc;
                        (*(code *)PTR_DebugPrintAssert_00568cd8)
                                  (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2300,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xdbc,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0);
                        local_84 = (undefined4 *******)0xffffe5d4;
                        goto LAB_0047a4b4;
                      }
                      for (; piVar14 != piVar19 + 0x166; piVar14 = (int *)((int)piVar14 + 1)) {
                        *(undefined1 *)piVar14 = 0;
                      }
                      if (local_74 != 0) {
                        local_48 = (int *)local_104;
                        pppppppuVar7 = (undefined4 *******)0x20;
                        local_84 = (undefined4 *******)FUN_00474254(param_1 + 0x3ec);
                        if (local_84 != (undefined4 *******)0x0) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                          pppppppuVar7 = (undefined4 *******)0xdc2;
                          goto LAB_0047a484;
                        }
                        (*(code *)PTR_memset_0056a728)(piVar19 + 0x164,0,8);
                        (*(code *)PTR_memcpy_0056aa64)(piVar19 + 0x15c,local_48,0x20);
                        *(undefined1 *)(piVar19 + 0x120) = 1;
                      }
                      local_48 = (int *)local_170;
                      local_84 = (undefined4 *******)
                                 RTPJitterBufferInit(piVar19 + 10,local_54,local_48,uVar22,
                                                     pppppppuVar7);
                      puVar8 = PTR_ServerSocketOpen_00569348;
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xdca;
                        goto LAB_0047a484;
                      }
                      piVar19[0x4f] = (int)local_64;
                      pppppppuVar7 = &local_88;
                      local_84 = (undefined4 *******)
                                 (*(code *)puVar8)(*(undefined2 *)(param_1 + 0x8c),1,0x11,0,
                                                   pppppppuVar7,0xffffffff,piVar19 + 7);
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xdd0;
                        goto LAB_0047a484;
                      }
                      iVar6 = 0;
                      (*(code *)PTR_SocketSetQoS_00569350)(piVar19[7],3);
                      (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                (local_78,local_50 + -0x1d00,pppppppuVar9,0);
                      (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                (local_78,local_44 + -0x1c78,piVar19[4],piVar19[5]);
                      local_50 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
                      (*(code *)PTR_CFDictionarySetInt64_00568e20)
                                (local_78,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1bb0,
                                 local_88,(int)local_88 >> 0x1f);
                      if (pppppppuVar9 == (undefined4 *******)0x64) {
                        iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                          (uVar20,local_50 + -0x1bb0,0);
                        if (0 < iVar6) {
                          if (piVar19[0x52] == 1) {
LAB_00479ffc:
                            for (piVar14 = piVar19 + 0x188; piVar14 != piVar19 + 0x1ce;
                                piVar14 = (int *)((int)piVar14 + 1)) {
                              *(undefined1 *)piVar14 = 0;
                            }
                            if (local_74 != 0) {
                              (*(code *)PTR_memset_0056a728)(piVar19 + 0x1cc,0,8);
                              (*(code *)PTR_memcpy_0056aa64)(piVar19 + 0x1c4,local_128,0x20);
                              *(undefined1 *)(piVar19 + 0x188) = 1;
                            }
                            iVar13 = *(int *)(param_1 + 0x1898);
                            if (iVar13 == 0) {
                              local_84 = (undefined4 *******)
                                         (*(code *)PTR_MirroredRingBufferInit_005694c4)
                                                   (param_1 + 0x1880,0x10000,1);
                              if (local_84 != (undefined4 *******)0x0) {
                                puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                                pppppppuVar7 = (undefined4 *******)0xdfd;
                                goto LAB_0047a484;
                              }
                              *(int *)(param_1 + 0x1898) = param_1 + 0x1880;
                              local_84 = (undefined4 *******)0x0;
                            }
                            else {
                              *(undefined4 *)(iVar13 + 0x10) = *(undefined4 *)(iVar13 + 0x14);
                            }
                            puVar8 = PTR_pthread_mutex_init_0056a8e0;
                            piVar19[0x17d] = *(int *)(param_1 + 0x1898);
                            *(undefined1 *)(piVar19 + 0x17c) = 0;
                            local_84 = (undefined4 *******)(*(code *)puVar8)(piVar19 + 0x175,0);
                            puVar8 = PTR_pthread_cond_init_0056a86c;
                            if (local_84 == (undefined4 *******)0x0) {
                              piVar19[0x17b] = (int)(piVar19 + 0x175);
                              local_84 = (undefined4 *******)(*(code *)puVar8)(piVar19 + 0x168,0);
                              puVar17 = PTR_pthread_create_0056a868;
                              puVar8 = PTR_LAB_00569bf8;
                              if (local_84 == (undefined4 *******)0x0) {
                                piVar19[0x174] = (int)(piVar19 + 0x168);
                                local_84 = (undefined4 *******)
                                           (*(code *)puVar17)(piVar19 + 0x166,0,puVar8 + -0x40d4,
                                                              piVar19);
                                puVar8 = PTR_RandomBytes_00568e90;
                                if (local_84 == (undefined4 *******)0x0) {
                                  piVar19[0x167] = (int)(piVar19 + 0x166);
                                  (*(code *)puVar8)(piVar19 + 0x186,2);
                                  piVar14 = piVar19 + 0x17e;
                                  (*(code *)PTR_SockAddrCopy_00569280)(param_1 + 0x8c,piVar14);
                                  (*(code *)PTR_SockAddrSetPort_0056928c)(piVar14,iVar6);
                                  iVar13 = (*(code *)PTR_SockAddrGetSize_005692a4)(piVar14);
                                  piVar19[0x185] = iVar13;
                                  goto LAB_0047a1cc;
                                }
                                puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                                pppppppuVar7 = (undefined4 *******)0xe10;
                              }
                              else {
                                puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                                pppppppuVar7 = (undefined4 *******)0xe0c;
                              }
                            }
                            else {
                              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                              pppppppuVar7 = (undefined4 *******)0xe08;
                            }
                          }
                          else {
                            local_84 = (undefined4 *******)
                                       (*(code *)PTR_AudioConverterNew_00569c14)
                                                 (local_48,local_54,piVar19 + 0x1ce);
                            if (local_84 == (undefined4 *******)0x0) {
                              if (48000 < (uint)local_14c) {
                                pppppppuVar7 = (undefined4 *******)0xde7;
                                (*(code *)PTR_DebugPrintAssert_00568cd8)
                                          (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                               -0x22c4,
                                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,
                                           0xde7,PTR_s_yController___p__0052fff0_0x10_00568cdc +
                                                 -0x1128,0);
                              }
                              if (local_13c == 0) {
                                trap(7);
                              }
                              if ((uint)local_14c < 0x5dc1) {
                                uVar22 = 48000;
                              }
                              else {
                                uVar22 = 64000;
                                if (32000 < (uint)local_14c) {
                                  uVar22 = 96000;
                                }
                              }
                              local_a4[0] = (undefined4 ******)
                                            (uVar22 / ((uint)local_14c / local_13c));
                              if ((uint)local_14c / local_13c == 0) {
                                trap(7);
                              }
                              local_84 = (undefined4 *******)
                                         (*(code *)PTR_AudioConverterSetProperty_00569c1c)
                                                   (piVar19[0x1ce],0x70616b6c,4,local_a4);
                              if (local_84 == (undefined4 *******)0x0) goto LAB_00479ffc;
                              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                              pppppppuVar7 = (undefined4 *******)0xdf0;
                            }
                            else {
                              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                              pppppppuVar7 = (undefined4 *******)0xde4;
                            }
                          }
                          goto LAB_0047a484;
                        }
                      }
LAB_0047a1cc:
                      puVar8 = PTR_pthread_mutex_init_0056a8e0;
                      *(undefined1 *)(piVar19 + 0x1e6) = 0;
                      local_84 = (undefined4 *******)(*(code *)puVar8)(piVar19 + 0x1df,0);
                      puVar8 = PTR_pthread_cond_init_0056a86c;
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xe1d;
                        goto LAB_0047a484;
                      }
                      piVar19[0x1e5] = (int)(piVar19 + 0x1df);
                      local_84 = (undefined4 *******)(*(code *)puVar8)(piVar19 + 0x1d2,0);
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xe21;
                        goto LAB_0047a484;
                      }
                      piVar19[0x1de] = (int)(piVar19 + 0x1d2);
                      local_84 = (undefined4 *******)FUN_00472ba4(iVar4,local_78);
                      puVar8 = PTR_gLogCategory_AirPlayReceiverCore_00569b78;
                      if (local_84 != (undefined4 *******)0x0) {
                        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                        pppppppuVar7 = (undefined4 *******)0xe25;
                        goto LAB_0047a484;
                      }
                      *piVar19 = param_1;
                      iVar13 = *(int *)puVar8;
                      if (iVar13 < 0x1f) {
                        if (iVar13 == -1) {
                          iVar13 = (*(code *)PTR__LogCategory_Initialize_00568d10)(puVar8,0x1e);
                          if (iVar13 == 0) goto LAB_0047a430;
                        }
                        pppppppuVar7 = (undefined4 *******)piVar19[2];
                        if (lVar27 == 4) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2714;
                        }
                        else if (lVar27 == 8) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2704;
                        }
                        else if (lVar27 == 0x10) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26f4;
                        }
                        else if (lVar27 == 0x20) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26e4;
                        }
                        else if (lVar27 == 0x40) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26d4;
                        }
                        else if (lVar27 == 0x80) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26c4;
                        }
                        else if (lVar27 == 0x100) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26b4;
                        }
                        else if (lVar27 == 0x200) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x26a4;
                        }
                        else if (lVar27 == 0x400) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2694;
                        }
                        else if (lVar27 == 0x800) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2684;
                        }
                        else if (lVar27 == 0x1000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2674;
                        }
                        else if (lVar27 == 0x2000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2664;
                        }
                        else if (lVar27 == 0x4000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2654;
                        }
                        else if (lVar27 == 0x8000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2644;
                        }
                        else if (lVar27 == 0x10000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2634;
                        }
                        else if (lVar27 == 0x20000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2624;
                        }
                        else if (lVar27 == 0x400000) {
                          puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2d0c;
                        }
                        else if (lVar27 == 0x800000) {
                          puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2d1c;
                        }
                        else if (lVar27 == 0x1000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2614;
                        }
                        else if (lVar27 == 0x2000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2604;
                        }
                        else if (lVar27 == 0x4000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x25f4;
                        }
                        else if (lVar27 == 0x8000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x25e4;
                        }
                        else if (lVar27 == 0x10000000) {
                          puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cdc;
                        }
                        else if (lVar27 == 0x20000000) {
                          puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cfc;
                        }
                        else if (lVar27 == 0x40000000) {
                          puVar8 = PTR_s__0051fff8_8_00568c5c + 0x2cec;
                        }
                        else if (lVar27 == 0x80000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x25d4;
                        }
                        else if (lVar27 == 0x100000000) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x25c4;
                        }
                        else {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x5bdc;
                        }
                        (*(code *)PTR_LogPrintF_00568d20)
                                  (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0x1e,
                                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x22a0,
                                   pppppppuVar7,puVar8,local_88,iVar6);
                      }
LAB_0047a430:
                      if ((*(char *)(param_1 + 0x3ce) != '\0') && (piVar19[9] == 0)) {
                        local_84 = (undefined4 *******)
                                   (*(code *)PTR_pthread_create_0056a868)
                                             (piVar19 + 8,0,PTR_LAB_00569bf8 + -0x4cec,piVar19);
                        if (local_84 != (undefined4 *******)0x0) {
                          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                          pppppppuVar7 = (undefined4 *******)0xe30;
                          goto LAB_0047a484;
                        }
                        piVar19[9] = (int)(piVar19 + 8);
                      }
                    }
                    else {
                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128;
                      pppppppuVar7 = (undefined4 *******)0xd90;
LAB_0047a484:
                      (*(code *)PTR_DebugPrintAssert_00568cd8)
                                (0,local_84,0,
                                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,
                                 pppppppuVar7,puVar8,0);
                    }
LAB_0047a4b4:
                    CFRelease(local_78);
                    if (local_84 == (undefined4 *******)0x0) goto LAB_0047a4c8;
                  }
                }
                else {
                  pppppppuVar7 = (undefined4 *******)0xd8a;
                  (*(code *)PTR_DebugPrintAssert_00568cd8)
                            (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x251c,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xd8a,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0);
                  local_84 = (undefined4 *******)0xffffe5c5;
                }
                FUN_0046e888(param_1,piVar19,0);
              }
              else {
                pppppppuVar7 = (undefined4 *******)0xd78;
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2310,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0xd78,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0);
                local_84 = (undefined4 *******)0xffffe5c1;
              }
LAB_0047a4c8:
              iVar6 = 0;
              puVar15 = (undefined4 *)local_128;
              while (iVar6 = iVar6 + 1, iVar6 != 0x21) {
                *(undefined1 *)puVar15 = 0;
                puVar15 = (undefined4 *)((int)local_128 + iVar6);
              }
              iVar6 = 0;
              puVar15 = (undefined4 *)local_104;
              while (iVar6 = iVar6 + 1, iVar6 != 0x21) {
                *(undefined1 *)puVar15 = 0;
                puVar15 = (undefined4 *)((int)local_104 + iVar6);
              }
              if (local_84 == (undefined4 *******)0x0) goto LAB_0047b2a0;
              if (*(int *)puVar3 < 0x3d) {
                if (*(int *)puVar3 == -1) {
                  iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                    (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x3c);
                  if (iVar6 != 0) goto LAB_0047b120;
                }
                else {
LAB_0047b120:
                  pppppppuVar7 = local_64;
                  (*(code *)PTR_LogPrintF_00568d20)
                            (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1128,0x3c,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2158,local_64,
                             local_84);
                }
                local_80[0] = local_84;
                if (local_84 == (undefined4 *******)0x0) goto LAB_0047aa38;
              }
              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
              uVar20 = 0x3af;
              local_80[0] = local_84;
              goto LAB_00479860;
            }
            iVar6 = *(int *)puVar3;
LAB_0047a9fc:
            if (iVar6 < 0x33) {
              if (iVar6 == -1) {
                iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                  (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32);
                if (iVar6 == 0) goto LAB_0047aa38;
              }
              (*(code *)PTR_LogPrintF_00568d20)
                        (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30,0x32,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x31b8);
              pppppppuVar7 = pppppppuVar9;
            }
          }
          else {
            if (pppppppuVar9 != (undefined4 *******)0x6e) {
              iVar6 = *(int *)puVar3;
              goto LAB_0047a9fc;
            }
            if (*(char *)(param_1 + 0x189c) == '\0') {
              iVar6 = CFDictionaryCreateMutable
                                (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                                 PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
              if (iVar6 == 0) {
                pppppppuVar7 = (undefined4 *******)0x11a4;
                (*(code *)PTR_DebugPrintAssert_00568cd8)
                          (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2530,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x11a4,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184,0);
                pppppppuVar9 = (undefined4 *******)0xffffe5b8;
              }
              else {
                pppppppuVar9 = (undefined4 *******)
                               AirPlayReceiverSessionScreen_Setup
                                         (*(undefined4 *)(param_1 + 0x18a0),uVar20,
                                          *(undefined4 *)(param_1 + 0xd0));
                if (pppppppuVar9 != (undefined4 *******)0x0) {
                  puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                  pppppppuVar7 = (undefined4 *******)0x11a7;
                  goto LAB_0047a94c;
                }
                lVar27 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                                   (uVar20,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c78,0
                                   );
                if (lVar27 == 0) {
                  pppppppuVar7 = (undefined4 *******)0x11aa;
                  (*(code *)PTR_DebugPrintAssert_00568cd8)
                            (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x251c,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x11aa,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184,0);
                  pppppppuVar9 = (undefined4 *******)0xffffe5c5;
                  goto LAB_0047a974;
                }
                if (*(int *)(param_1 + 0x3ec) == 0) {
                  AirPlay_DeriveAESKeySHA512ForScreen
                            (param_1 + 0x200,0x10,(int)lVar27,(int)((ulonglong)lVar27 >> 0x20),
                             local_128,local_14c);
                  pppppppuVar9 = (undefined4 *******)
                                 AirPlayReceiverSessionScreen_SetSecurityInfo
                                           (*(undefined4 *)(param_1 + 0x18a0),local_128,local_14c);
                  iVar13 = 0;
                  puVar15 = (undefined4 *)local_128;
                  while (iVar13 = iVar13 + 1, iVar13 != 0x11) {
                    *(undefined1 *)puVar15 = 0;
                    puVar15 = (undefined4 *)((int)local_128 + iVar13);
                  }
                  iVar13 = 0;
                  puVar15 = (undefined4 *)local_14c;
                  while (iVar13 = iVar13 + 1, iVar13 != 0x11) {
                    *(undefined1 *)puVar15 = 0;
                    puVar15 = (undefined4 *)((int)local_14c + iVar13);
                  }
                  if (pppppppuVar9 != (undefined4 *******)0x0) {
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                    pppppppuVar7 = (undefined4 *******)0x11b9;
                    goto LAB_0047a94c;
                  }
LAB_0047a7f8:
                  pppppppuVar7 = (undefined4 *******)local_104;
                  pppppppuVar9 = (undefined4 *******)
                                 (*(code *)PTR_ServerSocketOpen_00569348)
                                           (*(undefined2 *)(param_1 + 0x8c),2,6,0,pppppppuVar7,
                                            0xfffd4000,param_1 + 0x18a4);
                  if (pppppppuVar9 != (undefined4 *******)0x0) {
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                    pppppppuVar7 = (undefined4 *******)0x11be;
                    goto LAB_0047a94c;
                  }
                  (*(code *)PTR_SocketSetQoS_00569350)(*(undefined4 *)(param_1 + 0x18a4),0xc);
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)(iVar6,local_50 + -0x1d00,0x6e,0);
                  (*(code *)PTR_CFDictionarySetInt64_00568e20)
                            (iVar6,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1bb0,
                             local_104._0_4_,(int)local_104._0_4_ >> 0x1f);
                  pppppppuVar9 = (undefined4 *******)FUN_00472ba4(iVar4,iVar6);
                  if (pppppppuVar9 != (undefined4 *******)0x0) {
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                    pppppppuVar7 = (undefined4 *******)0x11c6;
                    goto LAB_0047a94c;
                  }
                  *(undefined1 *)(param_1 + 0x189c) = 1;
                  if (*(int *)puVar3 < 0x1f) {
                    if (*(int *)puVar3 == -1) {
                      iVar13 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                         (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x1e);
                      if (iVar13 == 0) goto LAB_0047a910;
                    }
                    pppppppuVar7 = (undefined4 *******)local_104._0_4_;
                    (*(code *)PTR_LogPrintF_00568d20)
                              (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184,0x1e,
                               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2138,
                               local_104._0_4_);
                  }
LAB_0047a910:
                  if (*(char *)(param_1 + 0x3ce) != '\0') {
                    pppppppuVar9 = (undefined4 *******)FUN_0046fcb0(param_1);
                    if (pppppppuVar9 != (undefined4 *******)0x0) {
                      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                      pppppppuVar7 = (undefined4 *******)0x11d0;
                      goto LAB_0047a94c;
                    }
                  }
                }
                else {
                  pppppppuVar9 = (undefined4 *******)FUN_00474254(param_1 + 0x3ec);
                  if (pppppppuVar9 == (undefined4 *******)0x0) {
                    pppppppuVar9 = (undefined4 *******)
                                   AirPlayReceiverSessionScreen_SetChaChaSecurityInfo
                                             (*(undefined4 *)(param_1 + 0x18a0),local_170,0x20);
                    if (pppppppuVar9 == (undefined4 *******)0x0) goto LAB_0047a7f8;
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                    pppppppuVar7 = (undefined4 *******)0x11b1;
                  }
                  else {
                    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184;
                    pppppppuVar7 = (undefined4 *******)0x11af;
                  }
LAB_0047a94c:
                  (*(code *)PTR_DebugPrintAssert_00568cd8)
                            (0,pppppppuVar9,0,
                             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,pppppppuVar7,
                             puVar8,0);
                }
LAB_0047a974:
                CFRelease(iVar6);
                if (pppppppuVar9 == (undefined4 *******)0x0) goto LAB_0047a998;
              }
              FUN_0046e054(param_1);
            }
            else {
              pppppppuVar7 = (undefined4 *******)0x11a1;
              (*(code *)PTR_DebugPrintAssert_00568cd8)
                        (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2264,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x11a1,
                         PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184,0);
              pppppppuVar9 = (undefined4 *******)0xffffe5c1;
            }
LAB_0047a998:
            iVar6 = 0;
            puVar15 = (undefined4 *)local_170;
            while (iVar6 = iVar6 + 1, iVar6 != 0x21) {
              *(undefined1 *)puVar15 = 0;
              puVar15 = (undefined4 *)((int)local_170 + iVar6);
            }
            if (pppppppuVar9 != (undefined4 *******)0x0) {
              if (*(int *)puVar3 < 0x3d) {
                if (*(int *)puVar3 == -1) {
                  iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                    (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x3c);
                  if (iVar6 == 0) goto LAB_0047b2a8;
                }
                (*(code *)PTR_LogPrintF_00568d20)
                          (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1184,0x3c,
                           PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x2114,pppppppuVar9);
              }
LAB_0047b2a8:
              puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
              uVar20 = 0x3b4;
              puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
              local_80[0] = pppppppuVar9;
              goto LAB_0047aafc;
            }
LAB_0047b2a0:
            local_80[0] = (undefined4 *******)0x0;
          }
LAB_0047aa38:
        }
        if (local_5c < 1) {
          cVar1 = *(char *)(param_1 + 0x3e9);
          goto LAB_0047aa60;
        }
LAB_0047aa6c:
        local_80[0] = (undefined4 *******)FUN_00471228(param_1,iVar4);
        if (local_80[0] == (undefined4 *******)0x0) {
          local_80[0] = (undefined4 *******)0x0;
          goto LAB_0047aaa4;
        }
        uVar20 = 0x3c0;
      }
      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30;
      puVar17 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10;
    }
LAB_0047aafc:
    (*(code *)PTR_DebugPrintAssert_00568cd8)(0,local_80[0],0,puVar17,uVar20,puVar8,0);
    CFRelease(iVar4);
    if (local_80[0] == (undefined4 *******)0x0) {
      return (undefined4 *******)0x0;
    }
  }
  if (*(int *)puVar3 < 0x33) {
    if (*(int *)puVar3 == -1) {
      iVar4 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                        (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32);
      if (iVar4 == 0) goto LAB_0047abc0;
    }
    (*(code *)PTR_LogPrintF_00568d20)
              (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xf30,0x32,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x20b8,
               *(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4),param_1 + 0x8c,
               local_80[0],param_2);
  }
LAB_0047abc0:
  iVar4 = *(int *)(param_1 + 0xc);
  if (*(code **)(iVar4 + 0x28) != (code *)0x0) {
    (**(code **)(iVar4 + 0x28))(iVar4,local_80[0],*(undefined4 *)(iVar4 + 0x10));
  }
  AirPlayReceiverSessionTearDown(param_1,param_2,local_80[0],0);
  return local_80[0];
}



/* === AirPlayReceiverSessionMakeModeStateFromDictionary @ 0047c490 === */

int AirPlayReceiverSessionMakeModeStateFromDictionary
              (undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  int local_38 [2];
  undefined *local_30;
  
  (*(code *)PTR_memset_0056a728)(param_3,0,0x20);
  uVar2 = CFArrayGetTypeID();
  iVar3 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b60,uVar2,0);
  if (iVar3 != 0) {
    iVar4 = CFArrayGetCount(iVar3);
    puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
    local_30 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b38;
    puVar9 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b24;
    for (iVar8 = 0; iVar8 < iVar4; iVar8 = iVar8 + 1) {
      uVar2 = CFDictionaryGetTypeID();
      uVar2 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar3,iVar8,uVar2,local_38);
      if (local_38[0] != 0) {
        puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
        uVar2 = 0x14a5;
        goto LAB_0047c7f0;
      }
      iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,local_30,0);
      if (iVar6 == 1) {
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar9,local_38);
        puVar10 = PTR_CFDictionaryGetInt64_00568d00;
        if (local_38[0] != 0) {
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14b2;
          goto LAB_0047c7f0;
        }
        param_3[5] = uVar7;
        uVar2 = (*(code *)puVar10)(uVar2,puVar5 + -0x1b14,local_38);
        if (local_38[0] != 0) {
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14b6;
          goto LAB_0047c7f0;
        }
        param_3[6] = uVar2;
      }
      else if (iVar6 < 2) {
        if (iVar6 != 0) {
          iVar6 = *(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78;
LAB_0047c73c:
          if ((iVar6 < 0x33) &&
             ((iVar6 != -1 ||
              (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                 (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32), iVar6 != 0)))
             ) {
            (*(code *)PTR_LogPrintF_00568d20)
                      (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c,0x32,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1f58,uVar2);
          }
        }
      }
      else if (iVar6 == 2) {
        uVar2 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar9,local_38);
        if (local_38[0] != 0) {
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14ac;
          goto LAB_0047c7f0;
        }
        param_3[4] = uVar2;
      }
      else {
        if (iVar6 != 3) {
          iVar6 = *(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78;
          goto LAB_0047c73c;
        }
        uVar2 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar9,local_38);
        if (local_38[0] != 0) {
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14bc;
          goto LAB_0047c7f0;
        }
        param_3[7] = uVar2;
      }
    }
  }
  uVar2 = CFArrayGetTypeID();
  iVar3 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b4c,uVar2,0);
  if (iVar3 == 0) {
LAB_0047c9a0:
    local_38[0] = 0;
  }
  else {
    iVar8 = 0;
    iVar4 = CFArrayGetCount(iVar3);
    puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
    puVar10 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b00;
    puVar9 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1b24;
LAB_0047c794:
    if (iVar4 <= iVar8) goto LAB_0047c9a0;
    uVar2 = CFDictionaryGetTypeID();
    uVar2 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar3,iVar8,uVar2,local_38);
    if (local_38[0] == 0) {
      iVar6 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar10,0);
      if (iVar6 == 1) {
        uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar9,local_38);
        puVar1 = PTR_CFDictionaryGetInt64_00568d00;
        if (local_38[0] != 0) {
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14d7;
          goto LAB_0047c7f0;
        }
        *param_3 = uVar7;
        uVar2 = (*(code *)puVar1)(uVar2,puVar5 + -0x1aec,local_38);
        if (local_38[0] == 0) {
          param_3[1] = uVar2;
        }
LAB_0047c940:
        iVar8 = iVar8 + 1;
      }
      else {
        if (iVar6 == 2) {
          uVar7 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar2,puVar9,local_38);
          puVar1 = PTR_CFDictionaryGetInt64_00568d00;
          if (local_38[0] == 0) {
            param_3[2] = uVar7;
            uVar2 = (*(code *)puVar1)(uVar2,puVar5 + -0x1aec,local_38);
            if (local_38[0] == 0) {
              param_3[3] = uVar2;
            }
            goto LAB_0047c940;
          }
          puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
          uVar2 = 0x14e2;
          goto LAB_0047c7f0;
        }
        if (iVar6 != 0) {
          if ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 < 0x33) &&
             ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 != -1 ||
              (iVar6 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                 (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32), iVar6 != 0)))
             ) {
            (*(code *)PTR_LogPrintF_00568d20)
                      (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c,0x32,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1f34,uVar2);
          }
          goto LAB_0047c940;
        }
        iVar8 = iVar8 + 1;
      }
      goto LAB_0047c794;
    }
    puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x156c;
    uVar2 = 0x14d0;
LAB_0047c7f0:
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,local_38[0],0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,uVar2,puVar5,
               0);
  }
  return local_38[0];
}



/* === AirPlayReceiverSessionControl @ 0047c9d4 === */

int AirPlayReceiverSessionControl
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
              int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined1 auStack_50 [32];
  undefined4 local_30;
  undefined4 local_2c;
  
  if ((*(int *)(param_1 + 0x34) != 0) &&
     (iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1ad4), iVar1 != 0))
  {
    if (param_5 == 0) {
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1f0c,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x213,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe64,0);
      return -0x1a31;
    }
    iVar1 = AirPlayReceiverSessionMakeModeStateFromDictionary(param_1,param_5,auStack_50);
    if (iVar1 == 0) {
      (**(code **)(param_1 + 0x34))(param_1,auStack_50,*(undefined4 *)(param_1 + 0x18));
      return 0;
    }
    uVar2 = 0x215;
    goto LAB_0047cc2c;
  }
  if ((*(int *)(param_1 + 0x38) != 0) &&
     (iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1abc), iVar1 != 0))
  {
    uVar2 = 0;
    if (param_5 != 0) {
      uVar2 = CFDictionaryGetValue(param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1aa8);
    }
    if ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 < 0x33) &&
       ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 != -1 ||
        (iVar1 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                           (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32), iVar1 != 0)))) {
      (*(code *)PTR_LogPrintF_00568d20)
                (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe64,0x32,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1eec);
      pcVar7 = *(code **)(param_1 + 0x38);
    }
    else {
      pcVar7 = *(code **)(param_1 + 0x38);
    }
    (*pcVar7)(param_1,uVar2,*(undefined4 *)(param_1 + 0x18));
    return 0;
  }
  iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a9c);
  if (iVar1 != 0) {
    if ((*(int *)(param_1 + 0x3f0) == 0) && (*(int *)(param_1 + 0xb90) == 0)) {
      return 0;
    }
    if (param_6 == (int *)0x0) {
      return 0;
    }
    iVar3 = CFDictionaryCreateMutable
                      (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                       PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
    if (iVar3 == 0) {
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1f00,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x6c8,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe74,0);
      iVar1 = -0x1a48;
    }
    else {
      iVar4 = CFArrayCreateMutable(0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
      if (iVar4 == 0) {
        (*(code *)PTR_DebugPrintAssert_00568cd8)
                  (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1ef4,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,0x6cb,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe74,0);
        iVar1 = -0x1a48;
LAB_0047d12c:
        CFRelease(iVar3);
      }
      else {
        CFDictionarySetValue(iVar3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d58,iVar4);
        if (*(int *)(param_1 + 0x3f0) == 0) {
LAB_0047cf6c:
          if (*(int *)(param_1 + 0xb90) != 0) {
            iVar1 = CFDictionaryCreateMutable
                              (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                               PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
            if (iVar1 == 0) {
              uVar2 = 0x6ea;
              goto LAB_0047cfac;
            }
            (*(code *)PTR_pthread_mutex_lock_0056a8a4)(*(undefined4 *)(param_1 + 0x1008));
            local_2c = *(undefined4 *)(param_1 + 0xfe4);
            local_30 = *(undefined4 *)(param_1 + 0xfe0);
            uVar2 = *(undefined4 *)(param_1 + 0xfd8);
            uVar6 = *(undefined4 *)(param_1 + 0xfdc);
            uVar8 = *(undefined4 *)(param_1 + 0xfe8);
            (*(code *)PTR_pthread_mutex_unlock_0056a924)(*(undefined4 *)(param_1 + 0x1008));
            (*(code *)PTR_CFDictionarySetInt64_00568e20)
                      (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d00,0x65,0);
            (*(code *)PTR_CFDictionarySetDouble_00569320)
                      (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a84,
                       SUB84((double)*(float *)(param_1 + 0xfd4),0),
                       (int)((ulonglong)(double)*(float *)(param_1 + 0xfd4) >> 0x20));
            if (*(int *)(param_1 + 0xfd0) != 0) {
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c78,
                         *(undefined4 *)(param_1 + 0xba0),*(undefined4 *)(param_1 + 0xba4));
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a78,uVar2,uVar6);
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a64,local_30,
                         local_2c);
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a4c,uVar8,0);
            }
            CFArrayAppendValue(iVar4,iVar1);
            CFRelease(iVar1);
          }
          *param_6 = iVar3;
          iVar1 = 0;
          iVar3 = 0;
        }
        else {
          iVar1 = CFDictionaryCreateMutable
                            (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                             PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
          if (iVar1 != 0) {
            (*(code *)PTR_pthread_mutex_lock_0056a8a4)(*(undefined4 *)(param_1 + 0x868));
            local_2c = *(undefined4 *)(param_1 + 0x83c);
            local_30 = *(undefined4 *)(param_1 + 0x838);
            uVar2 = *(undefined4 *)(param_1 + 0x840);
            uVar6 = *(undefined4 *)(param_1 + 0x844);
            uVar8 = *(undefined4 *)(param_1 + 0x848);
            (*(code *)PTR_pthread_mutex_unlock_0056a924)(*(undefined4 *)(param_1 + 0x868));
            (*(code *)PTR_CFDictionarySetInt64_00568e20)
                      (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1d00,
                       *(undefined4 *)(param_1 + 0x3f4),0);
            (*(code *)PTR_CFDictionarySetDouble_00569320)
                      (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a84,
                       SUB84((double)*(float *)(param_1 + 0x834),0),
                       (int)((ulonglong)(double)*(float *)(param_1 + 0x834) >> 0x20));
            if (*(int *)(param_1 + 0x830) != 0) {
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1c78,
                         *(undefined4 *)(param_1 + 0x400),*(undefined4 *)(param_1 + 0x404));
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a78,local_30,
                         local_2c);
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a64,uVar2,uVar6);
              (*(code *)PTR_CFDictionarySetInt64_00568e20)
                        (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a4c,uVar8,0);
            }
            CFArrayAppendValue(iVar4,iVar1);
            CFRelease(iVar1);
            goto LAB_0047cf6c;
          }
          uVar2 = 0x6d1;
LAB_0047cfac:
          (*(code *)PTR_DebugPrintAssert_00568cd8)
                    (0,0,PTR_s__0051fff8_8_00568c5c + 0xf90,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,uVar2,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe74,0);
          iVar1 = -0x1a48;
        }
        CFRelease(iVar4);
        if (iVar3 != 0) goto LAB_0047d12c;
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 0x232;
LAB_0047cc2c:
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,iVar1,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,uVar2,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe64,0);
    return iVar1;
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
LAB_0047ccb0:
    if ((iVar1 == 0) ||
       (iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a20), iVar1 == 0
       )) {
      iVar1 = AirPlayReceiverSessionPlatformControl(param_1,param_2,param_3,param_4,param_5,param_6)
      ;
      return iVar1;
    }
    if ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 < 0x1f) &&
       ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 != -1 ||
        (iVar1 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                           (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x1e), iVar1 != 0)))) {
      uVar2 = 0x1e;
      puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1ec0;
LAB_0047d168:
      (*(code *)PTR_LogPrintF_00568d20)
                (PTR_gLogCategory_AirPlayReceiverCore_00569b78,
                 PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xe64,uVar2,puVar5);
      uVar2 = *(undefined4 *)(param_1 + 0x18);
      goto LAB_0047cd00;
    }
  }
  else {
    iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1a38);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x28);
      goto LAB_0047ccb0;
    }
    if ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 < 0x33) &&
       ((*(int *)PTR_gLogCategory_AirPlayReceiverCore_00569b78 != -1 ||
        (iVar1 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                           (PTR_gLogCategory_AirPlayReceiverCore_00569b78,0x32), iVar1 != 0)))) {
      uVar2 = 0x32;
      puVar5 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1ed4;
      goto LAB_0047d168;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x18);
LAB_0047cd00:
  (**(code **)(param_1 + 0x28))(param_1,param_3,param_4,param_5,param_6,uVar2);
  return 0;
}



/* === AirPlayInfoArrayAddScreenDisplay @ 0047e910 === */

undefined4
AirPlayInfoArrayAddScreenDisplay
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_40 [36];
  
  if (*param_1 == 0) {
    iVar1 = CFArrayCreateMutable(0,0,PTR_kCFLArrayCallBacksCFLTypes_00568e28);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      uVar4 = 0x16b7;
      puVar2 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1e70;
      goto LAB_0047e9f8;
    }
  }
  iVar3 = *param_1;
  iVar1 = CFDictionaryCreateMutable
                    (0,0,PTR_kCFLDictionaryKeyCallBacksCFLTypes_00568e18,
                     PTR_kCFLDictionaryValueCallBacksCFLTypes_00568e14);
  if (iVar1 != 0) {
    CFDictionarySetValue(iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x18fc,param_2);
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x17bc,param_3,0);
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x17a8,param_4,0);
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_40,0x20);
    puVar2 = PTR_stderr_0056a674;
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)PTR_stderr_0056a674,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1e50,auStack_40,param_5);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    if (param_5 != 0) {
      (*(code *)PTR_CFDictionarySetInt64_00568e20)
                (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x178c,param_5,0);
    }
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x177c,param_6,0);
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1768,param_7,0);
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1750,param_8,0);
    (*(code *)PTR_CFDictionarySetInt64_00568e20)
              (iVar1,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1738,param_9,0);
    CFArrayAppendValue(iVar3,iVar1);
    CFRelease(iVar1);
    return 0;
  }
  uVar4 = 0x16bc;
  puVar2 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4fbc;
LAB_0047e9f8:
  (*(code *)PTR_DebugPrintAssert_00568cd8)
            (0,0,puVar2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x3f10,uVar4,
             PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x1720,0);
  return 0xffffe5b8;
}



/* === AirPlayReceiverSessionScreen_Create @ 0047ece8 === */

undefined4 AirPlayReceiverSessionScreen_Create(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_calloc_0056aabc)(1,0x2f8);
  if (iVar1 == 0) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xc74,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd18,0xa2,
               PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x870,0);
    uVar2 = 0xffffe5b8;
  }
  else {
    *(undefined4 *)(iVar1 + 0x2ec) = 0xffffffff;
    *param_1 = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* === AirPlayReceiverSessionScreen_Setup @ 0047eee8 === */

undefined4 AirPlayReceiverSessionScreen_Setup(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int local_10 [2];
  
  uVar1 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                    (param_2,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x9e0,local_10);
  *param_1 = uVar1;
  if (local_10[0] != 0) {
    *(undefined4 *)param_1 = 0x46;
    *(undefined4 *)((int)param_1 + 4) = 0;
  }
  return 0;
}



/* === AirPlayReceiverSessionScreen_StartSession @ 0047fe40 === */

int AirPlayReceiverSessionScreen_StartSession(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_OpenSelfConnectedLoopbackSocket_0056932c;
  *(undefined8 *)(param_1 + 0x30) =
       *(undefined8 *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd50);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar1 = (*(code *)puVar2)(param_1 + 0x2ec);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_ScreenStreamCreate_00569c58)(param_1 + 0x2f0);
    if (iVar1 == 0) {
      (*(code *)PTR_ScreenStreamSetDelegateContext_00569c5c)
                (*(undefined4 *)(param_1 + 0x2f0),param_2);
      iVar1 = (*(code *)PTR_ScreenStreamStart_00569c60)(*(undefined4 *)(param_1 + 0x2f0));
      if (iVar1 == 0) {
        (*(code *)PTR_puts_0056a780)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xaf0);
        *(undefined4 *)(PTR_DAT_00568d8c + -0x420c) = 0;
        *(undefined4 *)(PTR_DAT_00568d8c + -0x4210) = 0;
        *(undefined4 *)(PTR_DAT_00568d8c + -0x4214) = 0;
        *(undefined4 *)(PTR_DAT_00568d8c + -0x4218) = 0;
        return 0;
      }
      puVar2 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x978;
      uVar3 = 0x1e5;
    }
    else {
      puVar2 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x978;
      uVar3 = 0x1e1;
    }
  }
  else {
    puVar2 = PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x978;
    uVar3 = 0x1dc;
  }
  (*(code *)PTR_DebugPrintAssert_00568cd8)
            (0,iVar1,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd18,uVar3,puVar2,0);
  AirPlayReceiverSessionScreen_StopSession(param_1);
  return iVar1;
}



