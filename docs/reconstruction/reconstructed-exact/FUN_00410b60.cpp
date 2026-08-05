// =============================================================================
// FUN_00410b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00410b60
// Address:   0x00410b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00410b60 @ 0x00410b60
// Stable ID: aa_00410b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00410b60, FUN_0098cd60.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x00410b60; evidence only — no invented semantics):
//  - Entry: `void * __thiscall FUN_00410b60(void *param_1,byte param_2)`.
//  - Branches: if ((param_2 & 1) != 0).
//  - Calls: FUN_0098cd60(param_1); operator_delete(param_1).
//  - Returns (1 site(s)): `param_1`.




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

void * __thiscall FUN_00410b60(void *param_1,byte param_2)



{

  FUN_0098cd60(param_1);

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
