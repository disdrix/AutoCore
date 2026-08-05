// =============================================================================
// FUN_007988e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007988e0
// Address:   0x007988e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007988e0 @ 0x007988e0
// Stable ID: aa_007988e0
// Embedded strings (evidence for future rename):
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007988e0, swscanf.
//  - Strings: "%d;%d".
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

void FUN_007988e0(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,uint8_t *param_4)



{

  int iVar1;

  

  if (param_4 != (uint8_t *)0x0) {

    *param_4 = 0;

  }

  iVar1 = swscanf((wchar_t *)*param_1,L"%d;%d",param_2,param_3);

  if ((iVar1 == 2) && (*param_3 = *param_3 - *param_2, param_4 != (uint8_t *)0x0)) {

    *param_4 = 1;

  }

  return;

}
