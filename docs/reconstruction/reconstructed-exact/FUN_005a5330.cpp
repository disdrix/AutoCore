// =============================================================================
// FUN_005a5330
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5330
// Address:   0x005a5330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a5330 @ 0x005a5330
// Stable ID: aa_005a5330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ROUND×2, floor×2, FUN_005a5330.
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

int __fastcall FUN_005a5330(int param_1)



{

  double dVar1;

  

  if (*(char *)(param_1 + 0x14) != '\0') {

    dVar1 = floor((double)(*(float *)(param_1 + 8) - *(float *)(param_1 + 0xc)));

    return (int)ROUND((((double)*(float *)(param_1 + 8) - (double)*(float *)(param_1 + 0xc)) - dVar1

                      ) * (double)DAT_00aaa7ac);

  }

  dVar1 = floor((double)*(float *)(param_1 + 0xc));

  return (int)ROUND(((double)*(float *)(param_1 + 0xc) - dVar1) * (double)DAT_00aaa7ac);

}
