// =============================================================================
// FUN_0076c170
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c170
// Address:   0x0076c170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c170 @ 0x0076c170
// Stable ID: aa_0076c170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076c170, GetCurrentProcess, GetProcessAffinityMask, SetProcessAffinityMask.
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

ULONG_PTR FUN_0076c170(void)



{

  HANDLE hProcess;

  BOOL BVar1;

  ULONG_PTR local_8 [2];

  

  hProcess = GetCurrentProcess();

  local_8[0] = 0;

  local_8[1] = 0;

  BVar1 = GetProcessAffinityMask(hProcess,local_8,local_8 + 1);

  if (BVar1 != 0) {

    BVar1 = SetProcessAffinityMask(hProcess,1);

    if (BVar1 != 0) {

      return local_8[0];

    }

  }

  return 0;

}
