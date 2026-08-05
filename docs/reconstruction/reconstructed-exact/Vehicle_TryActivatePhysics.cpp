// =============================================================================
// Vehicle_TryActivatePhysics
// -----------------------------------------------------------------------------
// Stable ID: aa_00501420
// Address:   0x00501420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall
Vehicle_TryActivatePhysics(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)

{
  char cVar1;
  uint32_t /* width from decompiler */ uVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  float10 extraout_ST0;
  int iStack_160;
  float afStack_15c [5];
  uint32_t /* width from decompiler */ uStack_148;
  uint32_t /* width from decompiler */ uStack_144;
  uint32_t /* width from decompiler */ uStack_140;
  float fStack_13c;
  uint32_t /* width from decompiler */ uStack_138;
  uint32_t /* width from decompiler */ uStack_134;
  uint32_t /* width from decompiler */ uStack_130;
  float *pfStack_12c;
  uint32_t /* width from decompiler */ uStack_128;
  uint32_t /* width from decompiler */ uStack_124;
  uint16_t uStack_120;
  uint32_t /* width from decompiler */ uStack_11c;
  uint32_t /* width from decompiler */ uStack_118;
  uint32_t /* width from decompiler */ uStack_114;
  uint32_t /* width from decompiler */ uStack_110;
  int *piStack_10c;
  int *piStack_108;
  int *piStack_104;
  undefined **ppuStack_fc;
  uint32_t /* width from decompiler */ uStack_f8;
  float fStack_f4;
  uint32_t /* width from decompiler */ uStack_f0;
  uint32_t /* width from decompiler */ uStack_ec;
  uint32_t /* width from decompiler */ uStack_e8;
  float fStack_e4;
  uint32_t /* width from decompiler */ uStack_e0;
  uint32_t /* width from decompiler */ uStack_dc;
  uint32_t /* width from decompiler */ uStack_d8;
  float fStack_d4;
  uint32_t /* width from decompiler */ uStack_d0;
  uint32_t /* width from decompiler */ uStack_cc;
  uint32_t /* width from decompiler */ uStack_c8;
  uint32_t /* width from decompiler */ uStack_c4;
  uint16_t uStack_c0;
  uint16_t uStack_be;
  uint32_t /* width from decompiler */ uStack_bc;
  float fStack_b8;
  uint32_t /* width from decompiler */ uStack_b4;
  uint32_t /* width from decompiler */ uStack_b0;
  uint32_t /* width from decompiler */ uStack_ac;
  uint32_t /* width from decompiler */ uStack_a8;
  uint32_t /* width from decompiler */ uStack_a4;
  uint32_t /* width from decompiler */ uStack_a0;
  uint32_t /* width from decompiler */ uStack_9c;
  uint32_t /* width from decompiler */ uStack_98;
  uint32_t /* width from decompiler */ uStack_94;
  float afStack_90 [5];
  uint32_t /* width from decompiler */ uStack_7c;
  uint32_t /* width from decompiler */ uStack_78;
  uint32_t /* width from decompiler */ uStack_74;
  float fStack_70;
  uint32_t /* width from decompiler */ uStack_6c;
  uint32_t /* width from decompiler */ uStack_68;
  uint32_t /* width from decompiler */ uStack_64;
  uint32_t /* width from decompiler */ uStack_60;
  uint32_t /* width from decompiler */ uStack_5c;
  uint32_t /* width from decompiler */ uStack_58;
  uint32_t /* width from decompiler */ uStack_54;
  uint32_t /* width from decompiler */ uStack_50;
  uint32_t /* width from decompiler */ uStack_4c;
  uint32_t /* width from decompiler */ uStack_48;
  uint32_t /* width from decompiler */ uStack_44;
  uint32_t /* width from decompiler */ uStack_40;
  uint32_t /* width from decompiler */ uStack_3c;
  uint32_t /* width from decompiler */ uStack_38;
  uint32_t /* width from decompiler */ uStack_34;
  uint32_t /* width from decompiler */ uStack_30;
  uint32_t /* width from decompiler */ uStack_2c;
  uint32_t /* width from decompiler */ uStack_28;
  uint32_t /* width from decompiler */ uStack_24;
  uint32_t /* width from decompiler */ uStack_20;
  uint32_t /* width from decompiler */ uStack_1c;
  uint32_t /* width from decompiler */ uStack_18;
  uint32_t /* width from decompiler */ uStack_14;
  uint32_t /* width from decompiler */ uStack_10;
  void *local_c;
  undefined *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a2e31;
  local_c = ExceptionList;
  if (((char)param_1[0xab] == '\0') && ((char)param_1[0x45] != '\0')) {
    ExceptionList = &local_c;
    cVar1 = FUN_0053e270(param_2,param_3,param_4,1);
    if ((cVar1 != '\0') && ((**(code **)(*param_1 + 0x28))(), (float10)g_flZero < extraout_ST0)) {
      if (param_1[0x96] != 0) {
        *(uint8_t *)(param_1 + 0x41) = 1;
        Vehicle_createVehicleAction();
        VehicleEntity_PushDriveAxesToController();
        if (param_1[0xb] == 0) {
          pvVar3 = operator_new(0x40);
          param_1[0xb] = (int)pvVar3;
        }
        cVar1 = FUN_004a6910();
        if (cVar1 != '\0') {
          FUN_005066c0((int)*(char *)(param_1[0x96] + 0xb0),0);
          iStack_160 = 0;
          if ('\0' < *(char *)(param_1[0x96] + 0xb0)) {
            do {
              uStack_f8 = 1;
              ppuStack_fc = &PTR_FUN_009c7bb4;
              fStack_f4 = g_flOne;
              uStack_f0 = 0;
              uStack_ec = 0;
              uStack_e8 = 0;
              fStack_e4 = g_flOne;
              uStack_e0 = 0;
              uStack_dc = 0;
              uStack_d8 = 0;
              fStack_d4 = g_flOne;
              uStack_c4 = 8;
              uStack_be = 0;
              uStack_bc = 0;
              uStack_b0 = DAT_00aaa668;
              fStack_b8 = g_flOne;
              uStack_b4 = DAT_00aaa668;
              uStack_ac = 0;
              uStack_a8 = 0;
              uStack_a4 = 0;
              uStack_a0 = 0;
              uStack_9c = 0;
              uStack_98 = 0;
              uStack_94 = *(uint32_t /* width from decompiler */ *)
                           (*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c
                                    ) + 0x600 + (char)iStack_160 * 4);
              uStack_38 = DAT_009c7b84;
              uStack_2c = DAT_00aaa668;
              uStack_20 = DAT_00aaa668;
              uStack_1c = DAT_00aaa668;
              uStack_14 = DAT_00aaa668;
              uStack_4 = 0;
              uStack_c8 = 0;
              uStack_cc = 0;
              uStack_d0 = 0;
              uStack_c0 = 5;
              afStack_90[0] = g_flOne;
              afStack_90[1] = 0.0;
              afStack_90[2] = 0.0;
              afStack_90[3] = 0.0;
              afStack_90[4] = g_flOne;
              uStack_7c = 0;
              uStack_78 = 0;
              uStack_74 = 0;
              fStack_70 = g_flOne;
              uStack_64 = 0;
              uStack_68 = 0;
              uStack_6c = 0;
              uStack_58 = 0;
              uStack_5c = 0;
              uStack_60 = 0;
              uStack_48 = 0;
              uStack_4c = 0;
              uStack_50 = 0;
              uStack_3c = 0;
              uStack_40 = 0;
              uStack_44 = 0;
              uStack_34 = 0;
              uStack_30 = DAT_00a10e78;
              uStack_28 = 0;
              uStack_10 = 0;
              uStack_24 = 0x80;
              uStack_54 = DAT_00aaa7ac;
              uStack_18 = 1;
              piStack_10c = (int *)0x0;
              piStack_104 = (int *)0x0;
              pfVar8 = afStack_15c;
              for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
                *pfVar8 = 0.0;
                pfVar8 = pfVar8 + 1;
              }
              pfStack_12c = (float *)0x0;
              uStack_128 = 0;
              afStack_15c[0] = g_flOne;
              afStack_15c[1] = 0.0;
              afStack_15c[2] = 0.0;
              afStack_15c[3] = 0.0;
              afStack_15c[4] = g_flOne;
              uStack_148 = 0;
              uStack_144 = 0;
              uStack_140 = 0;
              fStack_13c = g_flOne;
              uStack_130 = 0;
              uStack_134 = 0;
              uStack_138 = 0;
              uStack_124 = 0;
              uStack_11c = 0;
              uStack_118 = 0;
              uStack_120 = 0;
              uStack_114 = 0;
              piStack_108 = piStack_10c;
              uStack_110 = 1;
              uStack_4 = CONCAT31(uStack_4._1_3_,1);
              if ((piStack_104 <= piStack_10c) &&
                 ((piStack_10c == (int *)0x0 ||
                  ((uint)((int)piStack_104 - (int)piStack_10c >> 2) < 2)))) {
                piVar4 = malloc(8);
                piVar7 = piVar4;
                for (piVar5 = piStack_10c; piVar5 != piStack_108; piVar5 = piVar5 + 1) {
                  *piVar7 = *piVar5;
                  piVar7 = piVar7 + 1;
                }
                if (piStack_10c != (int *)0x0) {
                  free(piStack_10c);
                }
                piStack_104 = piVar4 + 2;
                piStack_108 = piVar4 + ((int)piStack_108 - (int)piStack_10c >> 2);
                piStack_10c = piVar4;
              }
              *piStack_108 = (int)&ppuStack_fc;
              piStack_108 = piStack_108 + 1;
              pfStack_12c = afStack_90;
              uStack_130 = 0;
              uStack_134 = 0;
              uStack_138 = 0;
              *(uint32_t /* width from decompiler */ *)(iStack_160 * 4 + param_1[0xe5]) = 0;
              FUN_004b4b20(iStack_160 * 4 + param_1[0xe5],afStack_15c);
              FUN_0049c640();
              iStack_160 = iStack_160 + 1;
            } while (iStack_160 < *(char *)(param_1[0x96] + 0xb0));
          }
        }
        ExceptionList = local_c;
        return 1;
      }
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  ExceptionList = local_c;
  return uVar2;
}
