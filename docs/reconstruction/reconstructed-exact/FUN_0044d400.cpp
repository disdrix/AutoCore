// =============================================================================
// FUN_0044d400
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d400
// Address:   0x0044d400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044d400 @ 0x0044d400
// Stable ID: aa_0044d400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_0044d400.
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

void FUN_0044d400(uint32_t /* width from decompiler */ *param_1,char *param_2,char *param_3,uint8_t *param_4,code *param_5)



{

  uint8_t uVar1;

  

  if (param_2 == param_3) {

    *param_1 = param_4;

    return;

  }

  do {

    uVar1 = (*param_5)((int)*param_2);

    *param_4 = uVar1;

    param_2 = param_2 + 1;

    param_4 = param_4 + 1;

  } while (param_2 != param_3);

  *param_1 = param_4;

  return;

}
