// =============================================================================
// FUN_00798880
// -----------------------------------------------------------------------------
// Stable ID: aa_00798880
// Address:   0x00798880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798880 @ 0x00798880
// Stable ID: aa_00798880
// Embedded strings (evidence for future rename):
//   - "%f,%f,%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: swscanf×2, FUN_00798880.
//  - Strings: "%f,%f,%f".
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

void FUN_00798880(int *param_1,int param_2,uint8_t *param_3)



{

  wchar_t wVar1;

  

  wVar1 = *(wchar_t *)*param_1;

  if ((wVar1 != L'R') && (wVar1 != L'r')) {

    swscanf((wchar_t *)*param_1,L"%f,%f,%f",param_2,param_2 + 4,param_2 + 8);

    return;

  }

  if (param_3 != (uint8_t *)0x0) {

    *param_3 = 1;

  }

  swscanf((wchar_t *)(*param_1 + 2),L"%f,%f,%f",param_2,param_2 + 4,param_2 + 8);

  return;

}
