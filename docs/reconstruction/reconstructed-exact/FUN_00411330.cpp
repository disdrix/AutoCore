// =============================================================================
// FUN_00411330
// -----------------------------------------------------------------------------
// Stable ID: aa_00411330
// Address:   0x00411330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411330 @ 0x00411330
// Stable ID: aa_00411330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: DeleteCriticalSection, FUN_00411330, FUN_00416c90.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00411330; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00411330(undefined4 *param_1)`.
//  - Calls: FUN_00416c90().
//  - Writes: *param_1 = &PTR_FUN_00a4b0f8.
//  - Returns (1 site(s)): `void`.




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

void __fastcall FUN_00411330(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_00a4b0f8;

  FUN_00416c90();

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  return;

}
