// =============================================================================
// FUN_007a4390
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4390
// Address:   0x007a4390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4390 @ 0x007a4390
// Stable ID: aa_007a4390
// Embedded strings (evidence for future rename):
//   - "(%f) %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT44, FUN_007a4390, OutputDebugStringA, QueryPerformanceCounter, sprintf.
//  - Strings: "(%f) %s\n".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_007a4390(uint *param_1)



{

  LARGE_INTEGER local_260;

  char local_258 [600];

  

  QueryPerformanceCounter(&local_260);

  sprintf(local_258,"(%f) %s\n",

          (double)((float)CONCAT44((local_260.s.HighPart - param_1[1]) -

                                   (uint)(local_260.s.LowPart < *param_1),

                                   local_260.s.LowPart - *param_1) * _DAT_00afa254),param_1 + 2);

  OutputDebugStringA(local_258);

  return;

}
