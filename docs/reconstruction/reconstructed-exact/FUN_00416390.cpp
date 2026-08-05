// =============================================================================
// FUN_00416390
// -----------------------------------------------------------------------------
// Stable ID: aa_00416390
// Address:   0x00416390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00416390 @ 0x00416390
// Stable ID: aa_00416390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00416390, InitializeCriticalSection.
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

uint32_t /* width from decompiler */ __fastcall FUN_00416390(LPCRITICAL_SECTION param_1)



{

  void *local_14;

  undefined *puStack_10;

  undefined *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &DAT_00aaa698;

  puStack_10 = &DAT_00489cb0;

  local_14 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_14;

  InitializeCriticalSection(param_1);

  ExceptionList = local_14;

  return 0;

}
