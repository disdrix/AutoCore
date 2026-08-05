// =============================================================================
// FUN_005c6550
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6550
// Address:   0x005c6550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6550 @ 0x005c6550
// Stable ID: aa_005c6550
// Embedded strings (evidence for future rename):
//   - ";

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005c6550, fopen.
//  - Strings: ";

  if (param_3 == '\0') {

    _Mode = ".
//  - Return sites: 1.

  if (param_3 == '\0') {

    _Mode = "
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ * __thiscall FUN_005c6550(uint32_t /* width from decompiler */ *param_1,char *param_2,char param_3)



{

  char *_Mode;

  FILE *pFVar1;

  

  *param_1 = &PTR_FUN_009d9ea4;

  param_1[1] = 0;

  _Mode = "rb";

  if (param_3 == '\0') {

    _Mode = "wb";

  }

  pFVar1 = fopen(param_2,_Mode);

  param_1[1] = pFVar1;

  return param_1;

}
