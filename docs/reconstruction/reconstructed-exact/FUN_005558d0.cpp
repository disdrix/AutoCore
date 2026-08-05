// =============================================================================
// FUN_005558d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005558d0
// Address:   0x005558d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005558d0 @ 0x005558d0
// Stable ID: aa_005558d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_00553d20×6, FUN_004b8dc0×2, CVOGReaction_RandomUnitScalar, FUN_00553f50, FUN_005558d0, FUN_00558eb0, ROUND.
//  - Return sites: 1.

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



void __thiscall FUN_005558d0(int param_1,int param_2,char param_3)



{

  ushort uVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  int local_4;

  

  local_4 = param_1;

  FUN_00558eb0(&local_4,&param_3);

  iVar6 = local_4;

  if ((local_4 != *(int *)(param_1 + 0x174)) && (*(int *)(local_4 + 0x568) != param_2)) {

    iVar4 = 0;

    if (*(int *)(local_4 + 0x444) != 0) {

      iVar4 = (*(int *)(local_4 + 0x448) - *(int *)(local_4 + 0x444)) / 0x134;

    }

    if (param_2 <= iVar4 + -1) {

      *(uint *)(local_4 + 0x560) = g_dwClientTickMs;

      if ((((*(int *)(local_4 + 0x444) != 0) &&

           ((*(int *)(local_4 + 0x448) - *(int *)(local_4 + 0x444)) / 0x134 != 0)) &&

          (*(int *)(param_1 + 0x17c) != 0)) &&

         (*(char *)(*(int *)(param_1 + 0x17c) + 0x54c) == param_3)) {

        iVar4 = FUN_00553d20(0);

        if ((iVar4 != 0) && (iVar4 = FUN_00553d20(0), iVar4 != 0)) {

          FUN_004b8dc0(0,0);

        }

        if (((*(int *)(iVar6 + 0x56c) != *(int *)(iVar6 + 0x568)) &&

            (iVar4 = FUN_00553d20(0), iVar4 != 0)) && (iVar4 = FUN_00553d20(0), iVar4 != 0)) {

          FUN_004b8dc0(0,0);

        }

      }

      *(int *)(iVar6 + 0x56c) = param_2;

      *(int *)(iVar6 + 0x568) = param_2;

      if ((*(int *)(iVar6 + 0x444) != 0) &&

         ((*(int *)(iVar6 + 0x448) - *(int *)(iVar6 + 0x444)) / 0x134 != 0)) {

        iVar4 = *(int *)(iVar6 + 0x444) + param_2 * 0x134;

        iVar5 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar5 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

        *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

        iVar5 = *(int *)(iVar4 + 0x124) - *(int *)(iVar4 + 0x120);

        fVar2 = (float)iVar5;

        if (iVar5 < 0) {

          fVar2 = fVar2 + _DAT_00aaa5dc;

        }

        fVar3 = (float)*(int *)(iVar4 + 0x120);

        if (*(int *)(iVar4 + 0x120) < 0) {

          fVar3 = fVar3 + _DAT_00aaa5dc;

        }

        local_4 = (int)ROUND(fVar3 + fVar2 * (float)uVar1 * DAT_00aaa638);

        *(int *)(*(int *)(iVar6 + 0x444) + *(int *)(iVar6 + 0x568) * 0x134 + 0x128) = local_4;

        iVar6 = FUN_00553d20(0);

        if ((iVar6 != 0) &&

           (((*(int *)(param_1 + 0x17c) != 0 &&

             (*(char *)(*(int *)(param_1 + 0x17c) + 0x54c) == param_3)) ||

            ((*(int *)(param_1 + 0x180) != 0 &&

             (*(char *)(*(int *)(param_1 + 0x180) + 0x54c) == param_3)))))) {

          uVar8 = 0x3f800000;

          uVar7 = FUN_00553d20(0);

          FUN_00553f50(1,uVar7,uVar8);

        }

      }

    }

  }

  return;

}
