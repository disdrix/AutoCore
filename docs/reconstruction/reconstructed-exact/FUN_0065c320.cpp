// =============================================================================
// FUN_0065c320
// -----------------------------------------------------------------------------
// Stable ID: aa_0065c320
// Address:   0x0065c320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065c320 @ 0x0065c320
// Stable ID: aa_0065c320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005edf20, FUN_0065c320.
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

void FUN_0065c320(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_005edf20();

    uVar1 = DAT_00a0f718;

    param_1[2] = 0;

    param_1[3] = 0;

    param_1[4] = 0x80000000;

    *param_1 = uVar1;

    *(uint8_t *)(param_1 + 1) = 0;

  }

  return;

}
