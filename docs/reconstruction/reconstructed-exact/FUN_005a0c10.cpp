// =============================================================================
// FUN_005a0c10
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0c10
// Address:   0x005a0c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0c10 @ 0x005a0c10
// Stable ID: aa_005a0c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×16, while×5, return×4, do×3, goto×2, for×2.
//  - Notable callees: block×8, FUN_0059ff60×2, FUN_005a0540×2, FUN_0076cef0×2, FUN_0042b250, FUN_004434e0, FUN_00443b40, FUN_005a0c10.
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x005a107b) */

/* WARNING: Removing unreachable block (ram,0x005a0fef) */

/* WARNING: Removing unreachable block (ram,0x005a0ffc) */

/* WARNING: Removing unreachable block (ram,0x005a106a) */

/* WARNING: Removing unreachable block (ram,0x005a0e16) */

/* WARNING: Removing unreachable block (ram,0x005a0e2e) */

/* WARNING: Removing unreachable block (ram,0x005a0e77) */

/* WARNING: Removing unreachable block (ram,0x005a0e8f) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005a0c10(int param_1,uint param_2,int *param_3)



{

  int *piVar1;

  ushort uVar2;

  ushort uVar3;

  int iVar4;

  float fVar5;

  ushort uVar6;

  int *piVar7;

  void *pvVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int local_44;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a60a2;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0076cf00();

  local_4._0_1_ = 1;

  if (*(int *)(param_1 + 0xb0) == 0) {

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_0076cef0();

    local_4 = 0xffffffff;

    if (param_3 != (int *)0x0) {

      piVar7 = param_3 + 2;

      *piVar7 = *piVar7 + -1;

      if (*piVar7 == 0) {

        (**(code **)(*param_3 + 8))();

        ExceptionList = local_c;

        return;

      }

    }

    ExceptionList = local_c;

    return;

  }

  uVar9 = (uint)*(ushort *)(*(int *)(param_1 + 0xb0) + 0xac);

  uVar10 = param_3[4];

  if (uVar9 < uVar10) {

    fVar5 = (float)(int)uVar10;

    local_44 = 0;

    uVar2 = 0;

    if ((int)uVar10 < 0) {

      fVar5 = fVar5 + _DAT_00aaa5dc;

    }

    ceil((double)(fVar5 / (float)uVar9));

    uVar6 = FUN_006a3db0();

    uVar10 = 0;

    local_4._0_1_ = 3;

    while ((iVar11 = *(int *)(param_2 + 4), iVar11 != 0 &&

           (uVar10 < (uint)(*(int *)(param_2 + 8) - iVar11 >> 2)))) {

      if (*(int *)(iVar11 + uVar10 * 4) == 0) {

        iVar11 = 0;

        if (*(int *)(*(int *)(param_1 + 0xb0) + 0xc) < 1) goto LAB_005a0f1d;

        do {

          FUN_005a3920();

          iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x14) + iVar11 * 4);

          *(int *)(iVar4 + 0x240) = *(int *)(iVar4 + 0x240) + 1;

          FUN_00443b40();

          iVar11 = iVar11 + 1;

        } while (iVar11 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc));

        uVar10 = uVar10 + 1;

      }

      else {

        iVar11 = FUN_005a0540();

        if (iVar11 != 0) {

          FUN_005a4240();

          *(int *)(iVar11 + 0x240) = *(int *)(iVar11 + 0x240) + 1;

          FUN_004434e0();

        }

LAB_005a0f1d:

        uVar10 = uVar10 + 1;

      }

    }

    if (uVar6 != 0) {

      do {

        uVar3 = *(ushort *)(*(int *)(param_1 + 0xb0) + 0xac);

        param_2 = (uint)uVar3;

        if ((uint)(param_3[4] - local_44) <= (uint)uVar3) {

          param_2 = param_3[4] - local_44;

        }

        piVar7 = operator_new(0x18);

        local_4._0_1_ = 4;

        if (piVar7 == (int *)0x0) {

          piVar7 = (int *)0x0;

        }

        else {

          FUN_0042b250();

          *piVar7 = (int)&PTR_LAB_009d7b00;

          piVar7[4] = param_2 & 0xffff;

          pvVar8 = malloc(param_2 & 0xffff);

          piVar7[3] = (int)pvVar8;

          *(uint8_t *)(piVar7 + 5) = 1;

        }

        if (piVar7 != (int *)0x0) {

          piVar7[2] = piVar7[2] + 1;

        }

        puVar12 = (uint32_t /* width from decompiler */ *)(local_44 + param_3[3]);

        puVar13 = (uint32_t /* width from decompiler */ *)piVar7[3];

        for (uVar10 = param_2 >> 2 & 0x3fff; uVar10 != 0; uVar10 = uVar10 - 1) {

          *puVar13 = *puVar12;

          puVar12 = puVar12 + 1;

          puVar13 = puVar13 + 1;

        }

        for (uVar10 = param_2 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint8_t *)puVar13 = *(uint8_t *)puVar12;

          puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

          puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

        }

        uVar2 = uVar2 + 1;

        piVar1 = piVar7 + 2;

        *piVar1 = *piVar1 + -1;

        local_4._0_1_ = 3;

        if (*piVar1 == 0) {

          (**(code **)(*piVar7 + 8))();

        }

        local_44 = local_44 + (param_2 & 0xffff);

      } while (uVar2 < uVar6);

    }

  }

  else {

    uVar10 = 0;

    while ((iVar11 = *(int *)(param_2 + 4), iVar11 != 0 &&

           (uVar10 < (uint)(*(int *)(param_2 + 8) - iVar11 >> 2)))) {

      if (*(int *)(uVar10 * 4 + iVar11) == 0) {

        iVar11 = 0;

        if (*(int *)(*(int *)(param_1 + 0xb0) + 0xc) < 1) goto LAB_005a0d65;

        do {

          param_3[2] = param_3[2] + 1;

          FUN_0059ff60();

          iVar11 = iVar11 + 1;

        } while (iVar11 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc));

        uVar10 = uVar10 + 1;

      }

      else {

        FUN_005a0540();

        param_3[2] = param_3[2] + 1;

        FUN_0059ff60();

LAB_005a0d65:

        uVar10 = uVar10 + 1;

      }

    }

  }

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0076cef0();

  piVar7 = param_3 + 2;

  *piVar7 = *piVar7 + -1;

  local_4 = 0xffffffff;

  if (*piVar7 != 0) {

    ExceptionList = local_c;

    return;

  }

  (**(code **)(*param_3 + 8))();

  ExceptionList = local_c;

  return;

}
