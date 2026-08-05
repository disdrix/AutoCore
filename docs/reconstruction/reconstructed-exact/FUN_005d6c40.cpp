// =============================================================================
// FUN_005d6c40
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6c40
// Address:   0x005d6c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d6c40 @ 0x005d6c40
// Stable ID: aa_005d6c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005d6c40, thunk_FUN_00508390.
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

void * __thiscall FUN_005d6c40(void *param_1,byte param_2)



{

  thunk_FUN_00508390();

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
