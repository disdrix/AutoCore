// =============================================================================
// FUN_0049dab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049dab0
// Address:   0x0049dab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049dab0 @ 0x0049dab0
// Stable ID: aa_0049dab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: wcstok×2, FUN_0049cb20, FUN_0049dab0.
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

bool FUN_0049dab0(wchar_t *param_1,int param_2,int *param_3)



{

  wchar_t *pwVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *param_3 = 0;

  pwVar1 = wcstok(param_1,L", ");

  while ((pwVar1 != (wchar_t *)0x0 && (*param_3 < 8))) {

    uVar2 = FUN_0049cb20(pwVar1);

    *(uint32_t /* width from decompiler */ *)(param_2 + *param_3 * 4) = uVar2;

    pwVar1 = wcstok((wchar_t *)0x0,L", ");

    *param_3 = *param_3 + 1;

  }

  return 0 < *param_3;

}
