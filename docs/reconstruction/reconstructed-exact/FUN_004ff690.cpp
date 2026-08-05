// =============================================================================
// FUN_004ff690
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff690
// Address:   0x004ff690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ff690 @ 0x004ff690
// Stable ID: aa_004ff690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004b8dc0, FUN_004ff630, FUN_004ff690.
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

void __thiscall FUN_004ff690(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  if (((char)param_2 != '\0') &&

     ((*(int *)(param_1 + 0x330) == 0 ||

      (*(int *)(param_1 + 0x334) - *(int *)(param_1 + 0x330) >> 2 == 0)))) {

    FUN_004ff630();

  }

  piVar1 = *(int **)(param_1 + 0x330);

  if (piVar1 != *(int **)(param_1 + 0x334)) {

    do {

      if (*piVar1 != 0) {

        FUN_004b8dc0(param_2,0);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != *(int **)(param_1 + 0x334));

  }

  return;

}
