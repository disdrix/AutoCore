// =============================================================================
// FUN_005a05a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a05a0
// Address:   0x005a05a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a05a0 @ 0x005a05a0
// Stable ID: aa_005a05a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×18, return×3, goto×2, for×2, do×1, while×1.
//  - Notable callees: FUN_0076cef0×3, FUN_007a4480×3, FUN_0042b250, FUN_0059ff60, FUN_005a0020, FUN_005a0540, FUN_005a05a0, FUN_006a3db0.
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



void __thiscall FUN_005a05a0(int *param_1,int param_2,int *param_3)



{

  int *piVar1;

  float fVar2;

  ushort uVar3;

  int iVar4;

  int *piVar5;

  void *pvVar6;

  uint uVar7;

  int iVar8;

  ushort uVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a6065;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0076cf00();

  local_4._0_1_ = 1;

  if ((char)param_1[3] == '\0') {

    iVar8 = param_1[0x2c];

    if (iVar8 == 0) {

      FUN_007a4480();

      FUN_007a4480();

    }

    else if (*(int *)(iVar8 + 0xc) != 0) {

      iVar4 = **(int **)(iVar8 + 0x14);

      goto LAB_005a06ab;

    }

LAB_005a06af:

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_0076cef0();

    local_4 = 0xffffffff;

    if (param_3 != (int *)0x0) {

      piVar5 = param_3 + 2;

      *piVar5 = *piVar5 + -1;

      if (*piVar5 == 0) {

        (**(code **)(*param_3 + 8))();

        ExceptionList = local_c;

        return;

      }

    }

  }

  else {

    if (param_2 == 0) {

      if (DAT_00b04ec0 != '\0') {

        FUN_007a4480();

      }

      if (param_3 != (int *)0x0) {

        param_3[2] = param_3[2] + 1;

      }

      (**(code **)(*param_1 + 0x74))();

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0076cef0();

      if (param_3 == (int *)0x0) {

        ExceptionList = local_c;

        return;

      }

    }

    else {

      iVar8 = param_1[0x2c];

      iVar4 = FUN_005a0540();

LAB_005a06ab:

      if (iVar4 == 0) goto LAB_005a06af;

      if ((uint)*(ushort *)(iVar8 + 0xac) < (uint)param_3[4]) {

        *(int *)(iVar4 + 0x240) = *(int *)(iVar4 + 0x240) + 1;

        fVar2 = (float)param_3[4];

        iVar8 = 0;

        uVar9 = 0;

        if (param_3[4] < 0) {

          fVar2 = fVar2 + _DAT_00aaa5dc;

        }

        ceil((double)(fVar2 / (float)*(ushort *)(param_1[0x2c] + 0xac)));

        uVar3 = FUN_006a3db0();

        if (uVar3 != 0) {

          do {

            uVar10 = (uint)*(ushort *)(param_1[0x2c] + 0xac);

            if ((uint)(param_3[4] - iVar8) <= uVar10) {

              uVar10 = param_3[4] - iVar8;

            }

            piVar5 = operator_new(0x18);

            local_4._0_1_ = 2;

            if (piVar5 == (int *)0x0) {

              piVar5 = (int *)0x0;

            }

            else {

              FUN_0042b250();

              *piVar5 = (int)&PTR_LAB_009d7b00;

              piVar5[4] = uVar10 & 0xffff;

              pvVar6 = malloc(uVar10 & 0xffff);

              piVar5[3] = (int)pvVar6;

              *(uint8_t *)(piVar5 + 5) = 1;

            }

            if (piVar5 != (int *)0x0) {

              piVar5[2] = piVar5[2] + 1;

            }

            puVar11 = (uint32_t /* width from decompiler */ *)(param_3[3] + iVar8);

            puVar12 = (uint32_t /* width from decompiler */ *)piVar5[3];

            for (uVar7 = (uVar10 & 0xffff) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

              *puVar12 = *puVar11;

              puVar11 = puVar11 + 1;

              puVar12 = puVar12 + 1;

            }

            for (uVar7 = uVar10 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

              *(uint8_t *)puVar12 = *(uint8_t *)puVar11;

              puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

              puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

            }

            iVar8 = iVar8 + (uVar10 & 0xffff);

            piVar5[2] = piVar5[2] + 1;

            local_4._0_1_ = 3;

            FUN_005a0020(iVar4);

            uVar9 = uVar9 + 1;

            piVar1 = piVar5 + 2;

            *piVar1 = *piVar1 + -1;

            local_4._0_1_ = 1;

            if (*piVar1 == 0) {

              (**(code **)(*piVar5 + 8))();

            }

          } while (uVar9 < uVar3);

        }

      }

      else {

        param_3[2] = param_3[2] + 1;

        FUN_0059ff60();

      }

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0076cef0();

    }

    local_4 = 0xffffffff;

    piVar5 = param_3 + 2;

    *piVar5 = *piVar5 + -1;

    if (*piVar5 == 0) {

      (**(code **)(*param_3 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
