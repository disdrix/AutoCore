// =============================================================================
// FUN_005e6fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6fd0
// Address:   0x005e6fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6fd0 @ 0x005e6fd0
// Stable ID: aa_005e6fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_005e6fd0.
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

void __thiscall FUN_005e6fd0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  

  if ((**(int **)(param_1 + 0x14) == 0) && ((*(int **)(param_1 + 0x14))[1] == 0)) {

    iVar2 = (**(code **)(*param_2 + 0x1c))();

    if (iVar2 != 0) {

      iVar2 = (**(code **)(*param_2 + 0x1c))();

      if (*(int *)(*(int *)(iVar2 + 0x14) + 4) != 0) {

        **(uint32_t /* width from decompiler */ **)(param_1 + 0x14) = param_2;

        return;

      }

    }

  }

  iVar2 = *(int *)(param_1 + 0x14);

  piVar1 = (int *)(iVar2 + (param_4 - 1U & 1) * 4);

  if (*(int *)(iVar2 + param_4 * 4) == 0) {

    if (param_2 != (int *)*piVar1) {

      *(int **)(iVar2 + param_4 * 4) = param_2;

      return;

    }

  }

  else if ((*piVar1 == 0) && (param_2 != *(int **)(iVar2 + param_4 * 4))) {

    *piVar1 = (int)param_2;

  }

  return;

}
