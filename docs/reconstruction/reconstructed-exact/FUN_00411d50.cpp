// =============================================================================
// FUN_00411d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00411d50
// Address:   0x00411d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411d50 @ 0x00411d50
// Stable ID: aa_00411d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: DeleteCriticalSection, FUN_00411d50, FUN_00416c90.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x00411d50; evidence only — no invented semantics):
//  - Entry: `undefined4 * __thiscall FUN_00411d50(undefined4 *param_1,byte param_2)`.
//  - Branches: if ((param_2 & 1) != 0).
//  - Calls: FUN_00416c90(); operator_delete(param_1).
//  - Writes: *param_1 = &PTR_FUN_00a51ee0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00411d50(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  *param_1 = &PTR_FUN_00a51ee0;

  FUN_00416c90();

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
