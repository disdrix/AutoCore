// =============================================================================
// FUN_00404930
// -----------------------------------------------------------------------------
// Stable ID: aa_00404930
// Address:   0x00404930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404930 @ 0x00404930
// Stable ID: aa_00404930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00404930, GetVersionExA, InterlockedExchange.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00404930; evidence only — no invented semantics):
//  - Entry: `void FUN_00404930(void)`.
//  - Branches: if ((local_94.dwPlatformId != 2) || (Value = (code *)&LAB_00668cc0, local...).
//  - Indirect code-pointer call(s) present.
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

void FUN_00404930(void)



{

  code *Value;

  _OSVERSIONINFOA local_94;

  

  local_94.dwOSVersionInfoSize = 0x94;

  GetVersionExA(&local_94);

  if ((local_94.dwPlatformId != 2) || (Value = (code *)&LAB_00668cc0, local_94.dwMajorVersion < 5))

  {

    Value = FUN_00404980;

  }

  InterlockedExchange((LONG *)&PTR_FUN_00af8c9c,(LONG)Value);

  (*(code *)PTR_FUN_00af8c9c)();

  return;

}
