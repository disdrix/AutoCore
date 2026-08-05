// =============================================================================
// FUN_009c3550
// -----------------------------------------------------------------------------
// Stable ID: aa_009c3550
// Address:   0x009c3550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c3550 @ 0x009c3550
// Stable ID: aa_009c3550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_009c3550.
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

void FUN_009c3550(void)



{

  int *piVar1;

  

  piVar1 = DAT_00d1eeb0;

  if ((DAT_00d1eeb0 != (int *)0x0) && (DAT_00d1eeb0[1] = DAT_00d1eeb0[1] + -1, piVar1[1] == 0)) {

                    /* WARNING: Could not recover jumptable at 0x009c3569. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*piVar1 + 8))();

    return;

  }

  return;

}
