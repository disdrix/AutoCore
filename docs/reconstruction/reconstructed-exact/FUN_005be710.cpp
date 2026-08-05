// =============================================================================
// FUN_005be710
// -----------------------------------------------------------------------------
// Stable ID: aa_005be710
// Address:   0x005be710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005be710 @ 0x005be710
// Stable ID: aa_005be710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005be710.
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

void __fastcall FUN_005be710(int param_1)



{

  *(uint8_t *)(param_1 + 0xc4) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0;

  *(int *)(param_1 + 0xcc) = DAT_00b45510;

  if (DAT_00b45510 != 0) {

    *(int *)(DAT_00b45510 + 200) = param_1;

    DAT_00b45518 = DAT_00b45518 + 1;

    DAT_00b45510 = param_1;

    return;

  }

  DAT_00b45518 = DAT_00b45518 + 1;

  DAT_00b45514 = param_1;

  DAT_00b45510 = param_1;

  return;

}
