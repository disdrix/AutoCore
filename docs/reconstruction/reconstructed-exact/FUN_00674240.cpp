// =============================================================================
// FUN_00674240
// -----------------------------------------------------------------------------
// Stable ID: aa_00674240
// Address:   0x00674240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00674240 @ 0x00674240
// Stable ID: aa_00674240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00674240, FUN_006793b0.
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

void __thiscall FUN_00674240(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  

  if ((*(int *)(param_1 + 0x158) != 0) &&

     (piVar1 = *(int **)(param_1 + 0x128), piVar1 != *(int **)(param_1 + 300))) {

    do {

      if (*piVar1 != 0) {

        FUN_006793b0(*param_2,param_2[1]);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != *(int **)(param_1 + 300));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_2);

}
