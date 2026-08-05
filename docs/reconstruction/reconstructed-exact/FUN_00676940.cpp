// =============================================================================
// FUN_00676940
// -----------------------------------------------------------------------------
// Stable ID: aa_00676940
// Address:   0x00676940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00676940 @ 0x00676940
// Stable ID: aa_00676940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×1.
//  - Notable callees: FUN_00675860, FUN_006758c0, FUN_00676940.
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

void __thiscall

FUN_00676940(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,int param_6)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  

  iVar3 = *(int *)(param_1 + 0xc);

  uVar4 = param_4 - iVar3;

  iVar5 = param_6 - param_4;

  iVar2 = *(int *)(param_1 + 0x10) + iVar3;

  if (uVar4 < (uint)(iVar2 - param_6)) {

    FUN_00675860(&param_3,param_1,iVar3,param_3,param_4,param_5,param_6);

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      if (*(int *)(param_1 + 0x10) != 0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc) * 4))(0);

        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

        if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

        }

        piVar1 = (int *)(param_1 + 0x10);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

        }

      }

    }

  }

  else {

    FUN_006758c0(&param_3,param_5,param_6,param_1,iVar2,param_3,param_4,param_2);

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      if (*(int *)(param_1 + 0x10) != 0) {

        uVar6 = *(int *)(param_1 + 0x10) + -1 + *(int *)(param_1 + 0xc);

        if (*(uint *)(param_1 + 8) <= uVar6) {

          uVar6 = uVar6 - *(uint *)(param_1 + 8);

        }

        (**(code **)**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + uVar6 * 4))(0);

        piVar1 = (int *)(param_1 + 0x10);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

        }

      }

    }

  }

  iVar2 = *(int *)(param_1 + 0xc);

  *param_2 = param_1;

  param_2[1] = iVar2 + uVar4;

  return;

}
