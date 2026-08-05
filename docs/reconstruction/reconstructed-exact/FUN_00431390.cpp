// =============================================================================
// FUN_00431390
// -----------------------------------------------------------------------------
// Stable ID: aa_00431390
// Address:   0x00431390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00431390 @ 0x00431390
// Stable ID: aa_00431390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00431390×2, FUN_004933e0.
//  - Return sites: 2.

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

void FUN_00431390(void *param_1)



{

  if (*(char *)((int)param_1 + 0x2d) == '\0') {

    FUN_00431390(*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

    FUN_004933e0();

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return;

}
