// =============================================================================
// FUN_009784f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009784f0
// Address:   0x009784f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009784f0 @ 0x009784f0
// Stable ID: aa_009784f0
// Embedded strings (evidence for future rename):
//   - "cptest.geo"
//   - "No 35 from INC provided"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\ClientSpecialEvent_TeleportOut.cpp"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, goto×1.
//  - Notable callees: FUN_0040d4b0×2, FUN_0044af00×2, FUN_005816a0×2, CVOGReaction_TeleportTarget, FUN_00439a80, FUN_004406e0, FUN_0044adc0, FUN_004e9530.
//  - Strings: "cptest.geo"; "No 35 from INC provided"; "VOG_DEBUG_STOP".
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_009784f0(int param_1,float param_2)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *pTeleportData;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  float fVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ *puStack_48;

  int *piStack_44;

  int local_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint8_t auStack_30 [20];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  iVar4 = DAT_00d09874;

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b2922;

  local_1c = ExceptionList;

  local_40 = param_1;

  if (*(char *)(param_1 + 8) == '\0') {

    ExceptionList = &local_1c;

    *(float *)(param_1 + 0x28) = param_2 + *(float *)(param_1 + 0x28);

    local_4c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x238);

    (**(code **)(**(int **)(param_1 + 0x10) + 0x28))(local_4c);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + 8) + 0x34))();

    if (*(char *)(param_1 + 0x30) != '\0') {

      iVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 0xc))();

      fStack_3c = *(float *)(iVar4 + 0x90) - *(float *)(param_1 + 0x18);

      fStack_38 = *(float *)(iVar4 + 0x94) - *(float *)(param_1 + 0x1c);

      fStack_34 = *(float *)(iVar4 + 0x98) - *(float *)(param_1 + 0x20);

      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 0x24)) + 0x19c))();

      if (iVar4 != 0) {

        iVar4 = *(int *)(param_1 + 0x24);

        iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

        pTeleportData = (uint32_t /* width from decompiler */ *)FUN_004e9530(auStack_30,&fStack_3c);

        pvVar5 = (void *)(**(code **)(*(int *)(iVar1 + 4 + iVar4) + 0x19c))();

        CVOGReaction_TeleportTarget(pvVar5,pTeleportData);

      }

    }

    fVar8 = *(float *)(param_1 + 0x2c) + DAT_00aaa690;

    uVar3 = 0;

    if ((fVar8 <= *(float *)(param_1 + 0x28)) && (*(char *)(param_1 + 0x31) == '\x02')) {

      *(uint8_t *)(param_1 + 0x31) = 3;

      *(float *)(param_1 + 0x2c) = fVar8;

      ExceptionList = local_1c;

      return 1;

    }

    fVar8 = *(float *)(param_1 + 0x2c) + _DAT_00aaab48;

    if ((*(float *)(param_1 + 0x28) < fVar8) || (*(char *)(param_1 + 0x31) != '\x01')) {

      if ((DAT_00aaa8b0 <= *(float *)(param_1 + 0x28)) && (*(char *)(param_1 + 0x31) == '\0')) {

        fVar8 = *(float *)(param_1 + 0x2c) + DAT_00aaa8b0;

        *(uint8_t *)(param_1 + 0x31) = 1;

        *(float *)(param_1 + 0x2c) = fVar8;

        FUN_005816a0(3,0x3dcccccd);

        *(uint8_t *)(param_1 + 0x30) = 1;

        piStack_44 = operator_new(0x14c);

        uStack_14 = 0;

        if (piStack_44 == (void *)0x0) {

          uVar6 = 0;

        }

        else {

          uVar6 = FUN_00764030();

        }

        uStack_14 = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = uVar6;

        FUN_00989e00(&local_4c,"cptest.geo");

        (**(code **)(**(int **)(param_1 + 0x14) + 0x5c))(&local_4c);

        piVar2 = *(int **)(*(int *)(param_1 + 0x10) + 8);

        local_4c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

        iVar4 = FUN_0040d4b0(0x23);

        if (iVar4 != 0) {

          iVar4 = FUN_0040d4b0(0);

          if (iVar4 != 0) {

            puStack_48 = operator_new(0x10);

            if (puStack_48 == (uint32_t /* width from decompiler */ *)0x0) {

              puStack_48 = (uint32_t /* width from decompiler */ *)0x0;

            }

            else {

              *puStack_48 = 0;

              puStack_48[1] = 0;

              puStack_48[2] = 0;

              puStack_48[3] = 0;

            }

            uStack_14 = 0xffffffff;

            piStack_44 = piVar2 + 0x1a;

            FUN_004406e0();

            pvVar5 = *(void **)(piVar2[0x1c] + -4);

            puStack_48 = (uint32_t /* width from decompiler */ *)FUN_0044af00();

            iVar4 = FUN_0044af00();

            if ((puStack_48 != (uint32_t /* width from decompiler */ *)0x0) || (iVar4 != 0)) {

              *(uint32_t /* width from decompiler */ *)((int)pvVar5 + 8) = 0;

              FUN_0044adc0(pvVar5);

                    /* WARNING: Subroutine does not return */

              operator_delete(pvVar5);

            }

            uVar9 = 3;

            (**(code **)(*piVar2 + 0x30))(3);

            (**(code **)(*piVar2 + 0x34))();

            FUN_00439a80();

            uVar6 = (**(code **)(*piVar2 + 0xc))();

            uVar7 = (**(code **)(*piVar2 + 0x48))();

            uVar7 = (**(code **)(*piVar2 + 0xc))(uVar7,uVar6);

            uVar3 = FUN_0074c9c0(uVar7,uVar6,uVar9);

            goto LAB_00978849;

          }

        }

        uVar6 = FUN_0076cec0(&local_40,"No 35 from INC provided");

        vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\ClientSpecialEvent_TeleportOut.cpp"

                       ,0x81,3,uVar6);

        uVar3 = FUN_007a4480(0,"VOG_DEBUG_STOP");

        if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x14) != (uint32_t /* width from decompiler */ *)0x0) {

          uVar3 = (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x14))(1);

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

      }

    }

    else {

      *(uint8_t *)(param_1 + 0x31) = 2;

      *(float *)(param_1 + 0x2c) = fVar8;

      uVar3 = FUN_005816a0(2,0x3dcccccd);

    }

  }

  else {

    ExceptionList = &local_1c;

    uVar3 = FUN_009780c0();

  }

LAB_00978849:

  ExceptionList = local_1c;

  return uVar3 & 0xffffff00;

}
