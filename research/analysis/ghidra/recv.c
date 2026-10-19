// strref 0x531468 <- 0x0048b06c  in AirPlayReceiverSessionPlatformControl @0048ad58
// strref 0x531468 <- 0x0048b110  in AirPlayReceiverSessionPlatformControl @0048ad58
// strref 0x531468 <- 0x0048b600  in AirPlayReceiverSessionPlatformControl @0048ad58
// strref 0x550564 <- 0x0050cf74  in ScreenStreamProcessData @0050cc28

// ==== decompiling 6 functions ====


/* ===== AirPlayReceiverSessionPlatformControl @ 0048ad58 ===== */

int AirPlayReceiverSessionPlatformControl
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined *puVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  double in_f0_1;
  double dVar13;
  double dVar14;
  double dVar15;
  longlong lVar16;
  undefined8 uVar17;
  ulonglong in_stack_ffffff98;
  int local_58 [2];
  int local_50 [2];
  undefined *local_48;
  undefined *local_44;
  undefined *local_40;
  uint local_3c;
  
  iVar10 = *(int *)(param_1 + 0x14);
  iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1334);
  if (iVar1 != 0) {
    CFDictionaryGetDouble(param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1348,local_50);
    if ((local_50[0] != 0) || (in_f0_1 < 0.0)) {
      in_f0_1 = *(double *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1570);
    }
    dVar15 = in_f0_1 / *(double *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd58);
    CFDictionaryGetDouble(param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x135c,local_50);
    puVar8 = PTR_s__0051fff8_8_00568c5c;
    if (local_50[0] == 0) {
      fVar12 = (float)in_f0_1;
      dVar14 = 0.0;
      if (*(float *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1580) < fVar12) {
        if (0.0 <= fVar12) {
          dVar14 = *(double *)(PTR_s__0051fff8_8_00568c5c + 0x36e0);
        }
        else {
          (*(code *)PTR_powf_0056aae0)
                    (*(undefined4 *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1588),
                     fVar12 / *(float *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1584));
          dVar14 = *(double *)(puVar8 + 0x36e0);
          dVar13 = (double)fVar12;
          if (dVar13 <= dVar14) {
            if (dVar13 < 0.0) {
              dVar14 = 0.0;
            }
            else if (dVar13 <= dVar14) {
              iVar1 = *(int *)(param_1 + 0x3c);
              goto LAB_0048aed4;
            }
          }
        }
      }
    }
    else {
      dVar14 = *(double *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1578);
    }
    iVar1 = *(int *)(param_1 + 0x3c);
    dVar13 = dVar14;
LAB_0048aed4:
    if (iVar1 != 0) {
      if ((*(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc < 0x33) &&
         ((*(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc != -1 ||
          (iVar1 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                             (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,0x32), iVar1 != 0)))
         ) {
        (*(code *)PTR_LogPrintF_00568d20)
                  (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478,0x32,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x11e4,dVar13,dVar15);
      }
      (**(code **)(param_1 + 0x3c))(param_1);
      return 0;
    }
    return 0;
  }
  iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x136c);
  if (iVar1 != 0) {
    CFDictionaryGetDouble(param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1348,local_50);
    if ((local_50[0] != 0) || (in_f0_1 < 0.0)) {
      in_f0_1 = *(double *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1570);
    }
    in_f0_1 = in_f0_1 / *(double *)(PTR_s_yController___p__0052fff0_0x10_00568cdc + -0xd58);
    if (*(int *)(param_1 + 0x40) != 0) {
      if ((*(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc < 0x33) &&
         ((*(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc != -1 ||
          (iVar1 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                             (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,0x32), iVar1 != 0)))
         ) {
        (*(code *)PTR_LogPrintF_00568d20)
                  (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478,0x32,
                   PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x121c,in_f0_1);
      }
      (**(code **)(param_1 + 0x40))(param_1);
      return 0;
    }
    return 0;
  }
  iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1380);
  if (iVar1 == 0) {
    iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x13ec);
    if (iVar1 != 0) {
      FUN_0048a664(param_1,param_5);
      return 0;
    }
    iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1404);
    uVar4 = (uint)(in_stack_ffffff98 >> 0x20);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar10 + 0x68) = 1;
      local_50[0] = FUN_00489724(param_1);
      if (local_50[0] == 0) {
        return 0;
      }
      in_stack_ffffff98 = (ulonglong)uVar4 << 0x20;
      uVar17 = CONCAT44(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478,0x1bb);
      goto LAB_0048b4d0;
    }
    iVar1 = CFEqual(param_3,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x141c);
    if (iVar1 == 0) {
      if (*(code **)(param_1 + 0x28) != (code *)0x0) {
        iVar1 = (**(code **)(param_1 + 0x28))
                          (param_1,param_3,param_4,param_5,param_6,*(undefined4 *)(param_1 + 0x18));
        return iVar1;
      }
      return -0x1a3a;
    }
    if (*(int *)(param_1 + 0x44) == 0) {
      return 0;
    }
    uVar17 = CFDictionaryGetInt64
                       (param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x143c,local_50);
    if (local_50[0] == 0) {
      CFDictionaryGetCString
                (param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1458,local_58,8,local_50)
      ;
      uVar4 = (uint)(in_stack_ffffff98 >> 0x20);
      if (local_50[0] == 0) {
        uVar2 = (*(code *)PTR_strtoul_0056a72c)(local_58,0,0x10);
        if (local_50[0] == 0) {
          (**(code **)(param_1 + 0x44))
                    (param_1,0,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,
                     *(undefined4 *)(param_1 + 0x18));
          return 0;
        }
        in_stack_ffffff98 = (ulonglong)uVar4 << 0x20;
        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478;
        uVar2 = 0x1cd;
      }
      else {
        in_stack_ffffff98 = in_stack_ffffff98 & 0xffffffff00000000;
        puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478;
        uVar2 = 0x1c9;
      }
    }
    else {
      in_stack_ffffff98 = in_stack_ffffff98 & 0xffffffff00000000;
      puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478;
      uVar2 = 0x1c3;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x14);
    uVar2 = CFArrayGetTypeID();
    iVar1 = CFDictionaryGetTypedValue
                      (param_5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1300,uVar2,0);
    if (iVar1 != 0) {
      iVar3 = CFArrayGetCount(iVar1);
      local_48 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1310;
      local_44 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1398;
      local_40 = PTR_s_yController___p__0052fff0_0x10_00568cdc;
      for (iVar11 = 0; iVar11 < iVar3; iVar11 = iVar11 + 1) {
        uVar2 = CFDictionaryGetTypeID();
        uVar2 = CFArrayGetTypedValueAtIndex(iVar1,iVar11,uVar2,local_58);
        if (local_58[0] != 0) {
          uVar17 = CONCAT44(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1468,0x25c);
          goto LAB_0048b314;
        }
        uVar4 = CFDictionaryGetInt64(uVar2,local_48,0);
        if (uVar4 == 0x65) {
          puVar9 = (uint *)(iVar10 + 0x38);
LAB_0048b1cc:
          *puVar9 = uVar4;
          lVar16 = CFDictionaryGetInt64(uVar2,local_44,0);
          if (lVar16 == 0) {
            lVar16 = 0x800;
          }
          *(longlong *)(puVar9 + 2) = lVar16;
          lVar16 = CFDictionaryGetInt64(uVar2,local_40 + 0x12c0,local_58);
          puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x13ac;
          *(bool *)(puVar9 + 4) = lVar16 != 0;
          lVar16 = CFDictionaryGetInt64(uVar2,puVar8,0);
          *(bool *)((int)puVar9 + 0x11) = lVar16 != 0;
          uVar6 = CFStringGetTypeID();
          uVar7 = CFDictionaryGetTypedValue
                            (uVar2,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x12d0,uVar6,0);
          uVar4 = puVar9[5];
          if (uVar7 != 0) {
            local_3c = puVar9[5];
            CFRetain(uVar7);
            uVar4 = local_3c;
          }
          puVar9[5] = uVar7;
          if (uVar4 != 0) {
            CFRelease(uVar4);
          }
          uVar6 = CFDictionaryGetTypeID();
          iVar5 = CFDictionaryGetTypedValue
                            (uVar2,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x13c4,uVar6,0);
          if (iVar5 != 0) {
            CFDictionaryGetDouble(iVar5,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x13d8,0);
            *(double *)(puVar9 + 6) = in_f0_1;
          }
        }
        else if (uVar4 < 0x66) {
          puVar9 = (uint *)(iVar10 + 8);
          if (uVar4 == 100) goto LAB_0048b1cc;
          iVar5 = *(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc;
LAB_0048b198:
          if ((iVar5 < 0x33) &&
             ((iVar5 != -1 ||
              (local_3c = uVar4,
              iVar5 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                                (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,0x32),
              uVar4 = local_3c, iVar5 != 0)))) {
            (*(code *)PTR_LogPrintF_00568d20)
                      (PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1468,0x32,
                       PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x11ac,uVar4);
          }
        }
        else {
          if (uVar4 == 0x66) {
            puVar9 = (uint *)(iVar10 + 8);
            goto LAB_0048b1cc;
          }
          if (uVar4 != 0x6e) {
            iVar5 = *(int *)PTR_gLogCategory_AirPlayReceiverPlatform_00569cdc;
            goto LAB_0048b198;
          }
        }
      }
    }
    local_58[0] = FUN_00489724(param_1);
    if (local_58[0] != 0) {
      uVar17 = CONCAT44(PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1468,0x278);
LAB_0048b314:
      in_stack_ffffff98 = in_stack_ffffff98 & 0xffffffff00000000;
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,local_58[0],0,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1040,uVar17,
                 in_stack_ffffff98);
    }
    if (local_58[0] != 0) {
      FUN_0048a664(param_1,param_5);
    }
    local_50[0] = local_58[0];
    if (local_58[0] == 0) {
      return 0;
    }
    in_stack_ffffff98 = in_stack_ffffff98 & 0xffffffff00000000;
    puVar8 = PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1478;
    uVar2 = 0x1ab;
  }
  uVar17 = CONCAT44(puVar8,uVar2);
LAB_0048b4d0:
  (*(code *)PTR_DebugPrintAssert_00568cd8)
            (0,local_50[0],0,PTR_s_yController___p__0052fff0_0x10_00568cdc + 0x1040,uVar17,
             in_stack_ffffff98);
  return local_50[0];
}



/* ===== ScreenStreamProcessData @ 0050cc28 ===== */

int ScreenStreamProcessData(int param_1,undefined1 *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *in_stack_0000001c;
  undefined4 in_stack_00000020;
  int local_40;
  int local_3c;
  undefined1 *local_38 [2];
  int *local_30;
  int *local_2c;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar6 = FUN_0050c55c(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
      if (iVar6 == 0) {
        *(undefined1 *)(param_1 + 0x14) = 1;
        goto LAB_0050ccfc;
      }
      uVar3 = 0x268;
      goto LAB_0050cedc;
    }
    (*(code *)PTR_DebugPrintAssert_00568cd8)
              (0,0,PTR_DAT_0056a4b0 + 0x548,PTR_DAT_0056a4b0 + 0x3e0,0x266,PTR_DAT_0056a4b0 + 0x5a0,
               0);
    iVar6 = -0x1a59;
LAB_0050cf24:
    if (in_stack_0000001c != (code *)0x0) {
LAB_0050cf0c:
      (*in_stack_0000001c)(in_stack_00000020);
      if (iVar6 == 0) goto LAB_0050cf1c;
    }
    if ((*(int *)PTR_gLogCategory_ScreenStream_0056a5e8 < 0x5b) &&
       ((*(int *)PTR_gLogCategory_ScreenStream_0056a5e8 != -1 ||
        (iVar5 = (*(code *)PTR__LogCategory_Initialize_00568d10)
                           (PTR_gLogCategory_ScreenStream_0056a5e8,0x5a), iVar5 != 0)))) {
      (*(code *)PTR_LogPrintF_00568d20)
                (PTR_gLogCategory_ScreenStream_0056a5e8,PTR_DAT_0056a4b0 + 0x5a0,0x5a,
                 PTR_DAT_0056a4b0 + 0x564,iVar6);
    }
  }
  else {
LAB_0050ccfc:
    if (*(int *)(param_1 + 0x18) == 4) {
      local_30 = &local_40;
      local_38[0] = param_2;
      while (puVar4 = local_38[0],
            iVar6 = (*(code *)PTR_H264GetNextNALUnit_0056a5ec)
                              (local_38[0],param_2 + param_3,*(undefined4 *)(param_1 + 0x18),
                               &local_3c,local_30,local_38), iVar6 == 0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 1;
      }
      if (iVar6 == -0x1a60) {
        iVar6 = FUN_0050c55c(param_2,param_3);
        goto LAB_0050cec0;
      }
LAB_0050cecc:
      uVar3 = 0x28c;
LAB_0050cedc:
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,iVar6,0,PTR_DAT_0056a4b0 + 0x3e0,uVar3,PTR_DAT_0056a4b0 + 0x5a0,0);
      goto LAB_0050cf24;
    }
    iVar5 = (*(code *)PTR_malloc_00568eb4)(param_3 << 2);
    if (iVar5 == 0) {
      (*(code *)PTR_DebugPrintAssert_00568cd8)
                (0,0,PTR_DAT_0056a4b0 + 0x55c,PTR_DAT_0056a4b0 + 0x3e0,0x27c,
                 PTR_DAT_0056a4b0 + 0x5a0,0);
      iVar6 = -0x1a48;
      goto LAB_0050cf24;
    }
    local_30 = &local_3c;
    local_2c = &local_40;
    iVar7 = 0;
    local_38[0] = param_2;
    while (iVar6 = (*(code *)PTR_H264GetNextNALUnit_0056a5ec)
                             (local_38[0],param_2 + param_3,*(undefined4 *)(param_1 + 0x18),local_30
                              ,local_2c,local_38), iVar2 = local_40, puVar1 = PTR_memcpy_0056aa64,
          iVar6 == 0) {
      puVar4 = (undefined1 *)(iVar5 + iVar7);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 1;
      (*(code *)puVar1)(iVar5 + iVar7 + 4,local_3c,local_40);
      iVar7 = iVar7 + 4 + iVar2;
    }
    if (iVar6 == -0x1a60) {
      iVar6 = FUN_0050c55c(param_2,param_3);
    }
    (*(code *)PTR_free_00568d70)(iVar5);
LAB_0050cec0:
    if (iVar6 != 0) goto LAB_0050cecc;
    if (in_stack_0000001c != (code *)0x0) goto LAB_0050cf0c;
LAB_0050cf1c:
    iVar6 = 0;
  }
  return iVar6;
}



/* ===== airPlayGetProperty @ 0043e968 ===== */

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



/* ===== airPlayGetPropertyFromNativeHU @ 0043e208 ===== */

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



/* ===== AirPlayGetFeatures @ 00467708 ===== */

ulonglong AirPlayGetFeatures(undefined4 param_1)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)PTR_CFObjectGetPropertyInt64Sync_00568da4)
                    (param_1,0,PTR_AirPlayReceiverServerPlatformCopyProperty_00568cf4,1,
                     PTR_s_yController___p__0052fff0_0x10_00568cdc + -0x4968,0,0);
  return uVar1 | 0x6104040280;
}



/* ===== AirPlayCopyServerInfo @ 00468afc ===== */

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


