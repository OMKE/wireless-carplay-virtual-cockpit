/* === FUN_00428594 @ 00428594 === */

void FUN_00428594(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  int iVar13;
  undefined *puVar14;
  undefined4 *puVar15;
  float fVar16;
  longlong lVar17;
  undefined1 auStack_330 [80];
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2b8;
  undefined4 local_2b4;
  uint local_2b0;
  uint local_2ac;
  uint local_2a8;
  undefined1 auStack_2a4 [128];
  undefined1 auStack_224 [96];
  undefined1 auStack_1c4 [64];
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_15c;
  undefined4 local_158;
  undefined1 *local_154 [8];
  undefined1 auStack_134 [32];
  undefined1 auStack_114 [32];
  undefined1 auStack_f4 [32];
  undefined1 auStack_d4 [32];
  undefined1 auStack_b4 [32];
  undefined1 auStack_94 [32];
  int local_74;
  undefined1 *local_70;
  int *local_6c;
  undefined1 *local_68;
  undefined4 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined8 local_58;
  undefined1 *local_50;
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined1 *local_44;
  undefined1 **local_40;
  undefined *local_3c;
  undefined4 *local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  
  local_50 = auStack_94;
  (*(code *)PTR_memset_0056a728)(local_50,0,0x20);
  local_68 = auStack_b4;
  (*(code *)PTR_memset_0056a728)(local_68,0,0x20);
  local_4c = auStack_d4;
  (*(code *)PTR_memset_0056a728)(local_4c,0,0x20);
  local_5c = auStack_f4;
  (*(code *)PTR_memset_0056a728)(local_5c,0,0x20);
  local_48 = auStack_2a4;
  (*(code *)PTR_memset_0056a728)(local_48,0,0x80);
  local_70 = auStack_114;
  (*(code *)PTR_memset_0056a728)(local_70,0,0x20);
  (*(code *)PTR_memset_0056a728)(auStack_1c4,0,0x40);
  local_44 = auStack_134;
  (*(code *)PTR_memset_0056a728)(local_44,0,0x20);
  local_64 = &local_184;
  (*(code *)PTR_memset_0056a728)(local_64,0,0x30);
  puVar2 = PTR_stderr_0056a674;
  local_74 = *(int *)(param_1 + 0x8e8);
  if (local_74 != 0) {
LAB_00428778:
    (*(code *)PTR_exit_0056a7cc)(0);
    return;
  }
  local_60 = auStack_330;
  if (99 < *(int *)(param_1 + 0x478) - 200U) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(local_60,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1d68,local_60,
               *(undefined4 *)(param_1 + 0x478));
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    iVar5 = *(int *)(PTR_DAT_00568d8c + -0x4de8);
    *(int *)(PTR_DAT_00568d8c + -0x4de8) = iVar5 + 1;
    if (iVar5 + 1 < 2) {
LAB_00428f9c:
      FUN_004256c8();
      return;
    }
    goto LAB_00428778;
  }
  (*(code *)PTR_memset_0056a728)(local_60,0,0x8c);
  if (*(int *)(param_1 + 0x4a0) == 0) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x11d0,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    return;
  }
  (*(code *)PTR_timestamp_ext_0056a7b0)();
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1d38,auStack_224,
             *(undefined4 *)(param_1 + 0x4a0));
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  local_6c = &local_74;
  iVar5 = (*(code *)PTR_CFBinaryPlistV0CreateWithData_00568e44)
                    (*(undefined4 *)(param_1 + 0x49c),*(undefined4 *)(param_1 + 0x4a0),local_6c);
  if (local_74 != 0) {
    uVar6 = 0x41f;
LAB_00429084:
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,local_74,0,PTR_s__0051fff8_8_00568c5c + -0x2a00,uVar6,
               PTR_s__0051fff8_8_00568c5c + -0x6d0,0);
    goto LAB_0042a6c0;
  }
  iVar7 = (*(code *)PTR_CFGetTypeID_00568cc0)(iVar5);
  iVar8 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
  puVar1 = PTR_s__0051fff8_8_00568c5c;
  if (iVar7 != iVar8) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s__0051fff8_8_00568c5c + -0x1d14,PTR_s__0051fff8_8_00568c5c + -0x2a00,0x420,
               PTR_s__0051fff8_8_00568c5c + -0x6d0,0);
    local_74 = -0x1a64;
    goto LAB_0042a6c0;
  }
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xa44,auStack_1c4,0x40,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xad0,local_68,0x20,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xa84,local_70,0x20,0);
  (*(code *)PTR_ark_set_info_0056a850)(PTR_s__0051fff8_8_00568c5c + -0x1ce0,local_70);
  local_40 = local_154;
  local_154[0] = (undefined1 *)0x0;
  fVar16 = (float)(*(code *)PTR_strtof_0056aab0)(local_70,local_40);
  if (local_154[0] == local_70) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1cd0,auStack_224);
  }
  else {
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x1ca4,(int)fVar16);
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1c88,auStack_224,(int)fVar16);
  }
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_ark_set_info_0056a850)(PTR_s__0051fff8_8_00568c5c + -0x20ac,local_68);
  (*(code *)PTR_ark_set_info_0056a850)(PTR_s__0051fff8_8_00568c5c + -0x2094,auStack_1c4);
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  uVar6 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (iVar5,PTR_s__0051fff8_8_00568c5c + -0xa2c,uVar6,0);
  parseAudioFormats(uVar6,local_64);
  local_38 = &local_2e0;
  (*(code *)PTR_memcpy_0056aa64)(local_38,local_64,0x30);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1c6c,auStack_224,local_2dc,
             local_2e0);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1c3c,auStack_224,local_2d4,
             local_2d8);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1c0c,auStack_224,local_2cc,
             local_2d0);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1bdc,auStack_224,local_2b4,
             local_2b8);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1bac,auStack_224,local_2c4,
             local_2c8);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  resetAudioFormats(local_184,local_180,local_17c,local_178,local_174,local_170,local_16c,local_168,
                    local_15c,local_158);
  (*(code *)PTR_memcpy_0056aa64)(PTR_gCarAudioInfo_00569390,local_64,0x30);
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xa14,uVar6,0);
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  iVar7 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (iVar5,PTR_s__0051fff8_8_00568c5c + -0x9fc,uVar6,0);
  if (iVar7 != 0) {
    iVar8 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar7);
    local_58._0_4_ = PTR_s__0051fff8_8_00568c5c + -0x1b68;
    for (iVar13 = 0; iVar13 < iVar8; iVar13 = iVar13 + 1) {
      local_34 = (undefined *)(*(code *)PTR_CFArrayGetValueAtIndex_00568fc8)(iVar7,iVar13);
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      local_3c = *(undefined **)puVar2;
      uVar6 = (*(code *)PTR_CFStringGetCStringPtr_005691e4)(local_34,0x8000100);
      (*(code *)PTR_fprintf_0056aa28)(local_3c,(undefined *)local_58,auStack_224,iVar13,uVar6);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    }
  }
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xb9c,local_50,0x20,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xae4,local_44,0x20,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)(iVar5,puVar1 + -0xa44,auStack_1c4,0x40,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0x9e4,local_48,0x80,0);
  iVar8 = 0;
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  iVar7 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (iVar5,PTR_s__0051fff8_8_00568c5c + -0x9d8,uVar6,0);
  (*(code *)PTR_ark_set_info_int_0056a788)(PTR_s__0051fff8_8_00568c5c + -0x1b7c,1);
  if (iVar7 != 0) {
    iVar8 = (*(code *)PTR_CFArrayGetCount_00568e30)(iVar7);
  }
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  puVar12 = PTR_stderr_0056a674;
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1b4c,auStack_224,iVar8);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  puVar1 = PTR_DAT_00568d8c;
  if (iVar8 == 0) {
    *(undefined2 *)PTR_gVideoWidth_00569394 = 0;
    puVar11 = PTR_timestamp_ext_0056a7b0;
    *(undefined2 *)PTR_gVideoHeight_00569398 = 0;
    iVar7 = *(int *)(puVar1 + -0x4db8);
    *(int *)(puVar1 + -0x4db8) = iVar7 + 1;
    if (iVar7 < 3) {
      (*(code *)puVar11)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar12,PTR_s__0051fff8_8_00568c5c + -0x1ae4,auStack_224,
                 *(undefined4 *)(puVar1 + -0x4db8));
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar12);
      goto LAB_00428f9c;
    }
    (*(code *)puVar11)();
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar12,PTR_s__0051fff8_8_00568c5c + -0x1b28,auStack_224,
               *(undefined4 *)(puVar1 + -0x4db8));
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar12);
  }
  else {
    iVar13 = 0;
    local_58._0_4_ = PTR_s__0051fff8_8_00568c5c + -0xdc0;
    local_3c = PTR_s__0051fff8_8_00568c5c + -0x1ab0;
    local_34 = (undefined *)(uint)(iVar8 < 2);
    while( true ) {
      if (iVar8 <= iVar13) goto LAB_004293f0;
      uVar6 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
      uVar6 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar7,iVar13,uVar6,local_6c);
      if (local_74 != 0) {
        uVar6 = 0x474;
        goto LAB_00429084;
      }
      sVar3 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(uVar6,(undefined *)local_58,local_6c);
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,local_3c,auStack_224,(int)sVar3,local_74);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      if (local_74 != 0) break;
      if ((sVar3 == 0x6e) || (iVar13 = iVar13 + 1, local_34 != (undefined *)0x0)) goto LAB_00429178;
    }
    if (iVar8 != 1) goto LAB_004290b4;
LAB_00429178:
    iVar7 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)(uVar6,PTR_s__0051fff8_8_00568c5c + -0xc74);
    puVar12 = PTR_timestamp_ext_0056a7b0;
    puVar1 = PTR_gSupportsViewAreas_005693a8;
    if (iVar7 != 0) {
      *PTR_gSupportsViewAreas_005693a8 = 1;
      (*(code *)puVar12)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1a8c,auStack_224,*puVar1);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      local_58._0_4_ = (undefined *)(*(code *)PTR_CFArrayGetCount_00568e30)(iVar7);
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1a5c,auStack_224,
                 PTR_s__0051fff8_8_00568c5c + -0x1a68,0x484,(undefined *)local_58);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      local_3c = (undefined *)
                 (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                           (uVar6,PTR_s__0051fff8_8_00568c5c + -0x9c4,local_6c);
      local_34 = PTR_s__0051fff8_8_00568c5c + -0x9ac;
      local_30 = PTR_s__0051fff8_8_00568c5c + -0x998;
      local_2c = PTR_s__0051fff8_8_00568c5c;
      puVar15 = (undefined4 *)PTR_gInViewAreas_005693ac;
      for (iVar8 = 0; iVar8 < (int)(undefined *)local_58; iVar8 = iVar8 + 1) {
        uVar9 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
        iVar13 = (*(code *)PTR_CFArrayGetTypedValueAtIndex_00569270)(iVar7,iVar8,uVar9,local_6c);
        if (iVar8 == 0x20) break;
        if (iVar13 != 0) {
          uVar9 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar13,local_34,local_6c);
          puVar1 = PTR_CFDictionaryGetInt64_00568d00;
          puVar15[1] = uVar9;
          uVar9 = (*(code *)puVar1)(iVar13,local_30,local_6c);
          *puVar15 = uVar9;
          uVar9 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar13,local_2c + -0x980,local_6c);
          puVar12 = PTR_CFDictionaryGetInt64_00568d00;
          puVar1 = PTR_s__0051fff8_8_00568c5c;
          puVar15[2] = uVar9;
          uVar9 = (*(code *)puVar12)(iVar13,puVar1 + -0x968,local_6c);
          puVar15[3] = uVar9;
          (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
          (*(code *)PTR_fprintf_0056aa28)
                    (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1a34,auStack_224,iVar8,
                     puVar15[1],*puVar15,puVar15[2],puVar15[3]);
          (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
        }
        puVar15 = puVar15 + 4;
      }
      *(undefined **)PTR_gInitialViewArea_005693b0 = local_3c;
      *(undefined **)PTR_gActiveViewArea_005692f0 = local_3c;
    }
LAB_004290b4:
    iVar7 = (*(code *)PTR_CFDictionaryGetValue_00568cfc)(uVar6,PTR_s__0051fff8_8_00568c5c + -0xc04);
    puVar1 = PTR_gMainScreenUUID_0056939c;
    if (iVar7 == 0) {
      *(undefined4 *)PTR_gMainScreenUUID_0056939c = 0;
    }
    else {
      uVar9 = (*(code *)PTR_CFStringCreateCopy_005693a0)(0,iVar7);
      *(undefined4 *)puVar1 = uVar9;
    }
    uVar4 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                      (uVar6,PTR_s__0051fff8_8_00568c5c + -0x9ac,0);
    puVar12 = PTR_CFDictionaryGetInt64_00568d00;
    puVar1 = PTR_s__0051fff8_8_00568c5c;
    *(undefined2 *)PTR_gVideoWidth_00569394 = uVar4;
    uVar4 = (*(code *)puVar12)(uVar6,puVar1 + -0x998,0);
    puVar12 = PTR_CFDictionaryGetInt64_00568d00;
    puVar1 = PTR_s__0051fff8_8_00568c5c;
    puVar11 = PTR_s__0051fff8_8_00568c5c + -0x950;
    *(undefined2 *)PTR_gVideoHeight_00569398 = uVar4;
    uVar4 = (*(code *)puVar12)(uVar6,puVar11,0);
    puVar12 = PTR_CFDictionaryGetInt64_00568d00;
    *(undefined2 *)PTR_gFps_005693a4 = uVar4;
    (*(code *)puVar12)(uVar6,puVar1 + -0x950,0);
  }
LAB_004293f0:
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0x940,uVar6,0);
  local_58 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                       (iVar5,PTR_s__0051fff8_8_00568c5c + -0xa6c,0);
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  uVar6 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (iVar5,PTR_s__0051fff8_8_00568c5c + -0x924,uVar6,0);
  parseHidDevicesInfo(uVar6);
  (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar5,PTR_s__0051fff8_8_00568c5c + -0x910,0);
  (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar5,PTR_s__0051fff8_8_00568c5c + -0x8f4,0);
  uVar6 = (*(code *)PTR_CFDictionaryGetTypeID_00568cc4)();
  uVar6 = (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
                    (iVar5,PTR_s__0051fff8_8_00568c5c + -0x8d0,uVar6,0);
  MakeModeStateFromDictionary(uVar6,PTR_gClientInitialModes_00569308);
  puVar12 = PTR_DAT_00568d8c;
  MakeModeStateFromDictionary(uVar6,PTR_DAT_00568d8c + -0x4da0);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  puVar10 = PTR_stderr_0056a674;
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x19f0,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  puVar11 = PTR_gClientInitialModes_00569308;
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x19cc,auStack_224,
             *(undefined4 *)(PTR_gClientInitialModes_00569308 + 0x14),
             *(undefined4 *)(PTR_gClientInitialModes_00569308 + 0x18),
             *(undefined4 *)(PTR_gClientInitialModes_00569308 + 0x1c),
             *(undefined4 *)(PTR_gClientInitialModes_00569308 + 0x20));
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  puVar14 = PTR_strcasestr_0056a9cc;
  puVar1 = PTR_s__0051fff8_8_00568c5c;
  *(undefined4 *)(puVar11 + 0x14) = 1;
  *(undefined4 *)(puVar12 + -0x4d8c) = 1;
  *(undefined4 *)(puVar11 + 0x18) = 100;
  *(undefined4 *)(puVar11 + 0x1c) = 100;
  *(undefined4 *)(puVar11 + 0x20) = 100;
  *(undefined4 *)(puVar12 + -0x4d88) = 100;
  *(undefined4 *)(puVar12 + -0x4d84) = 100;
  *(undefined4 *)(puVar12 + -0x4d80) = 100;
  local_3c = (undefined *)0x64;
  iVar7 = (*(code *)puVar14)(local_70,puVar1 + -0x1990);
  if (iVar7 != 0) {
    if ((((*(int *)puVar11 == 1) && (*(int *)(puVar11 + 4) == 500)) &&
        (*(int *)(puVar11 + 8) == 500)) &&
       (puVar14 = *(undefined **)(puVar11 + 0xc), puVar14 == local_3c)) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar10,PTR_s__0051fff8_8_00568c5c + -0x1988,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar10);
      *(undefined **)(puVar11 + 4) = puVar14;
      *(undefined **)(puVar11 + 8) = puVar14;
      *(undefined **)(puVar12 + -0x4d9c) = puVar14;
      *(undefined **)(puVar12 + -0x4d98) = puVar14;
    }
    puVar10 = PTR_gClientInitialModes_00569308;
    if (((*(int *)puVar11 == 3) && (*(int *)(PTR_gClientInitialModes_00569308 + 4) == 500)) &&
       (*(int *)(PTR_gClientInitialModes_00569308 + 0xc) == 500)) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1940,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      *(undefined4 *)(puVar10 + 4) = 100;
      *(undefined4 *)(puVar10 + 0xc) = 100;
      *(undefined4 *)(puVar12 + -0x4d9c) = 100;
      *(undefined4 *)(puVar12 + -0x4d94) = 100;
    }
    if (((*(int *)(puVar11 + 0x14) == 1) &&
        (*(int *)(PTR_gClientInitialModes_00569308 + 0x18) == 500)) &&
       ((*(int *)(PTR_gClientInitialModes_00569308 + 0x1c) == 500 ||
        (*(int *)(PTR_gClientInitialModes_00569308 + 0x1c) == 100)))) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x18f8,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      *(undefined4 *)(puVar11 + 0x18) = 100;
      *(undefined4 *)(puVar11 + 0x1c) = 100;
      *(undefined4 *)(puVar11 + 0x20) = 100;
      *(undefined4 *)(puVar12 + -0x4d88) = 100;
      *(undefined4 *)(puVar12 + -0x4d84) = 100;
      *(undefined4 *)(puVar12 + -0x4d80) = 100;
    }
  }
  iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(local_70,puVar1 + -0x1990);
  puVar12 = PTR_s__0051fff8_8_00568c5c;
  if (iVar7 != 0) {
    iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x18ac,6);
    if (iVar7 != 0) {
      iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(local_68,PTR_s__0051fff8_8_00568c5c + -0x18a4,6);
      if (iVar7 != 0) {
        iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x1898)
        ;
        if (iVar7 == 0) {
          iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)
                            (auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x1894,10);
          if (iVar7 != 0) {
            iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,puVar12 + -0x1884,6);
            if (iVar7 != 0) goto LAB_00429898;
          }
        }
      }
    }
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x1878,1);
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1854,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  }
LAB_00429898:
  iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(local_70,puVar1 + -0x1990);
  if (iVar7 != 0) {
    iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(local_68,PTR_s__0051fff8_8_00568c5c + -0x1814);
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(local_68,PTR_s__0051fff8_8_00568c5c + -0x1808);
      if (iVar7 == 0) goto LAB_00429940;
    }
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1800,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,2);
  }
LAB_00429940:
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x17a4,6);
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(local_70,PTR_s__0051fff8_8_00568c5c + -0x179c,9);
    if (iVar7 == 0) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1790,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,2);
    }
  }
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,puVar12 + -0x18ac,6);
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(local_70,PTR_s__0051fff8_8_00568c5c + -0x179c,9);
    if (iVar7 == 0) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x175c,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,2);
    }
  }
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,puVar12 + -0x1884,6);
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(local_70,PTR_s__0051fff8_8_00568c5c + -0x1728,8);
    if (iVar7 == 0) {
      (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
      (*(code *)PTR_fprintf_0056aa28)
                (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x171c,auStack_224);
      (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
      (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,1);
    }
  }
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x16e4,6);
  if (iVar7 == 0) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x16d0,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,1);
  }
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x168c,6);
  if (iVar7 == 0) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1684,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,1);
  }
  iVar7 = (*(code *)PTR_strncasecmp_0056aaf0)(auStack_1c4,PTR_s__0051fff8_8_00568c5c + -0x47ec,5);
  if (iVar7 == 0) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1640,auStack_224);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x17cc,1);
  }
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0xac0,local_4c,0x20,0);
  (*(code *)PTR_CFDictionaryGetCString_00568ce0)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0x8c0,local_5c,0x20,0);
  uVar6 = (*(code *)PTR_CFArrayGetTypeID_00568e24)();
  (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0x8a8,uVar6,0);
  uVar6 = (*(code *)PTR_CFDataGetTypeID_00568fcc)();
  (*(code *)PTR_CFDictionaryGetTypedValue_00568e48)
            (iVar5,PTR_s__0051fff8_8_00568c5c + -0x894,uVar6,0);
  (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar5,PTR_s__0051fff8_8_00568c5c + -0x884,0);
  saveNativeVehicleSettings(iVar5,PTR_s__0051fff8_8_00568c5c + -0x1608);
  lVar17 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                     (iVar5,PTR_s__0051fff8_8_00568c5c + -0x870,local_6c);
  puVar1 = PTR_s__0051fff8_8_00568c5c;
  local_2b0 = (uint)(lVar17 != 0);
  lVar17 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                     (iVar5,PTR_s__0051fff8_8_00568c5c + -0x858,local_6c);
  local_2ac = (uint)(lVar17 != 0);
  lVar17 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)
                     (iVar5,PTR_s__0051fff8_8_00568c5c + -0x844,local_6c);
  local_2a8 = (uint)(lVar17 != 0);
  (*(code *)PTR_memcpy_0056aa64)(local_38,local_64,0x30);
  (*(code *)PTR_cfg_do_set_int_0056a68c)(PTR_s__0051fff8_8_00568c5c + -0x43f0,(uint)(lVar17 != 0));
  (*(code *)PTR_memset_0056a728)(auStack_224,0,0x60);
  (*(code *)PTR_prop_get_string_0056a97c)(PTR_s__0051fff8_8_00568c5c + -0x48b0,auStack_224);
  iVar7 = (*(code *)PTR_strcasestr_0056a9cc)(auStack_224,PTR_s__0051fff8_8_00568c5c + -0x15f0);
  if (iVar7 != 0) {
    (*(code *)PTR_timestamp_ext_0056a7b0)(local_40,0x20);
    (*(code *)PTR_fprintf_0056aa28)
              (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x15e8,local_40,local_5c);
    (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
    (*(code *)PTR_prop_set_int_0056a9e4)(PTR_s__0051fff8_8_00568c5c + -0x4cf8,1);
  }
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x15a8,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1588,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  puVar12 = PTR_s__0051fff8_8_00568c5c;
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1568,auStack_224,
             *(undefined4 *)puVar11,*(undefined4 *)(puVar11 + 4),*(undefined4 *)(puVar11 + 8),
             *(undefined4 *)(puVar11 + 0xc));
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1538,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,puVar12 + -0x1568,auStack_224,*(undefined4 *)(puVar11 + 0x14),
             *(undefined4 *)(puVar11 + 0x18),*(undefined4 *)(puVar11 + 0x1c),
             *(undefined4 *)(puVar11 + 0x20));
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1518,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  iVar7 = *(int *)(puVar11 + 0x2c);
  if (iVar7 == 0) {
    puVar12 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
  }
  else if (iVar7 == -1) {
    puVar12 = PTR_s__0051fff8_8_00568c5c + -0x1d78;
  }
  else if (iVar7 == 1) {
    puVar12 = PTR_s__0051fff8_8_00568c5c + -0x1d70;
  }
  else {
    puVar12 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
  }
  iVar7 = *(int *)(puVar11 + 0x28);
  if (iVar7 == 0) {
    puVar10 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
  }
  else if (iVar7 == -1) {
    puVar10 = PTR_s__0051fff8_8_00568c5c + -0x21b8;
  }
  else if (iVar7 == 1) {
    puVar10 = PTR_s__0051fff8_8_00568c5c + -0x21b0;
  }
  else if (iVar7 == 2) {
    puVar10 = PTR_s__0051fff8_8_00568c5c + -0x21a4;
  }
  else {
    puVar10 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
  }
  iVar7 = *(int *)(puVar11 + 0x30);
  if (iVar7 == 0) {
    puVar11 = PTR_s__0051fff8_8_00568c5c + -0x21cc;
  }
  else if (iVar7 == -1) {
    puVar11 = PTR_s__0051fff8_8_00568c5c + -0x1d78;
  }
  else if (iVar7 == 1) {
    puVar11 = PTR_s__0051fff8_8_00568c5c + -0x1d70;
  }
  else {
    puVar11 = PTR_s__0051fff8_8_00568c5c + -0x21c8;
  }
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x14f4,auStack_224,puVar12,puVar10,
             puVar11);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x14c0,auStack_224,local_50);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1498,auStack_224,local_4c);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1470,auStack_224,local_5c);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1448,auStack_224,local_48);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1420,auStack_224,local_70);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x13f8,auStack_224,local_44);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x13d0,auStack_224,auStack_1c4);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x13a8,auStack_224,local_68);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1380,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1354,auStack_224);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1328,auStack_224,
             (int)*(short *)PTR_gVideoWidth_00569394);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1300,auStack_224,
             (int)*(short *)PTR_gVideoHeight_00569398);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x12d8,auStack_224,
             (int)*(short *)PTR_gFps_005693a4);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  uVar6 = *(undefined4 *)puVar2;
  lVar17 = (*(code *)PTR_CFDictionaryGetInt64_00568d00)(iVar5,puVar1 + -0x858,local_6c);
  (*(code *)PTR_fprintf_0056aa28)
            (uVar6,PTR_s__0051fff8_8_00568c5c + -0x12b0,auStack_224,lVar17 != 0);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1288,auStack_224,local_2a8);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_timestamp_ext_0056a7b0)(auStack_224,0x20);
  (*(code *)PTR_fprintf_0056aa28)
            (*(undefined4 *)puVar2,PTR_s__0051fff8_8_00568c5c + -0x1260,auStack_224,local_2b0);
  (*(code *)PTR_fflush_0056a984)(*(undefined4 *)puVar2);
  (*(code *)PTR_prop_set_string_0056a7f0)(PTR_s__0051fff8_8_00568c5c + -0x1238,auStack_1c4);
  (*(code *)PTR_prop_set_string_0056a7f0)(PTR_s__0051fff8_8_00568c5c + -0x1214,local_68);
  (*(code *)PTR_prop_set_string_0056a7f0)(PTR_s__0051fff8_8_00568c5c + -0x11f4,local_70);
  if (*(code **)(PTR_gReverseSessionDelegate_005691ac + 0x18) != (code *)0x0) {
    (**(code **)(PTR_gReverseSessionDelegate_005691ac + 0x18))
              (local_60,*(undefined4 *)PTR_gReverseSessionDelegate_005691ac);
  }
  *(undefined4 *)(PTR_DAT_00568d8c + -0x4de8) = 0;
  AirplayClientSendCmdRecord();
LAB_0042a6c0:
  if (iVar5 != 0) {
    (*(code *)PTR_CFRelease_00568d1c)(iVar5);
  }
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



/* === saveNativeVehicleSettings @ 0042f82c === */

int saveNativeVehicleSettings(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  (*(code *)PTR_CFDictionaryRemoveValue_00569430)(param_1,PTR_s__0051fff8_8_00568c5c + 0x7d4);
  (*(code *)PTR_CFDictionaryRemoveValue_00569430)(param_1,PTR_s__0051fff8_8_00568c5c + 0x880);
  (*(code *)PTR_CFDictionaryRemoveValue_00569430)(param_1,PTR_s__0051fff8_8_00568c5c + 0x898);
  iVar1 = (*(code *)PTR_CFPropertyListCreateData_00569434)(0,param_1,200,0,0);
  if (iVar1 == 0) {
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x3088,
               PTR_s__0051fff8_8_00568c5c + -0x418,0x4ce,PTR_s__0051fff8_8_00568c5c + 0x8f0,0);
    iVar6 = -0x1a2c;
  }
  else {
    iVar2 = (*(code *)PTR_open_0056abb4)(param_2,0x301,0x180);
    if (iVar2 < 0) {
      piVar3 = (int *)(*(code *)PTR___errno_location_0056a998)();
      iVar6 = *piVar3;
      if (iVar6 == 0) {
        iVar6 = -0x1a2c;
      }
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,iVar6,0,PTR_s__0051fff8_8_00568c5c + -0x418,0x4d2,
                 PTR_s__0051fff8_8_00568c5c + 0x8f0,0);
    }
    else {
      iVar6 = (*(code *)PTR_CFDataGetBytePtr_00568e84)(iVar1);
      iVar4 = (*(code *)PTR_CFDataGetLength_00568e88)(iVar1);
      iVar4 = iVar6 + iVar4;
      for (; iVar6 != iVar4; iVar6 = iVar6 + iVar5) {
        iVar5 = (*(code *)PTR_write_00569438)(iVar2,iVar6,iVar4 - iVar6);
        if (iVar5 < 1) {
          piVar3 = (int *)(*(code *)PTR___errno_location_0056a998)();
          iVar6 = *piVar3;
          if (iVar6 == 0) {
            iVar6 = -0x1a2c;
          }
          (*(code *)PTR_DebugPrintAssert_00568cd8)
                    (0,iVar6,0,PTR_s__0051fff8_8_00568c5c + -0x418,0x4da,
                     PTR_s__0051fff8_8_00568c5c + 0x8f0,0);
          goto LAB_0042fa30;
        }
      }
      iVar6 = 0;
LAB_0042fa30:
      (*(code *)PTR_close_0056a6e4)(iVar2);
    }
    (*(code *)PTR_CFRelease_00568d1c)(iVar1);
  }
  return iVar6;
}



