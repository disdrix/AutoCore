// =============================================================================
// FUN_0079a1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a1c0
// Address:   0x0079a1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a1c0 @ 0x0079a1c0
// Stable ID: aa_0079a1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0079a1c0, QueryPerformanceCounter.
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

void __thiscall FUN_0079a1c0(int param_1,int param_2)



{

  char *pcVar1;

  

  if (*(char *)(param_2 + 0x20 + param_1) == '\0') {

    QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0x148 + param_2 * 8));

  }

  pcVar1 = (char *)(param_2 + 0x20 + param_1);

  *pcVar1 = *pcVar1 + '\x01';

  return;

}
