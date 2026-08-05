// =============================================================================
// FUN_004c77b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c77b0
// Address:   0x004c77b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c77b0 @ 0x004c77b0
// Stable ID: aa_004c77b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006a3db0×2, FUN_004c77b0.
//  - Return sites: 3.

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

uint8_t * FUN_004c77b0(uint8_t *param_1,float param_2)



{

  uint8_t uVar1;

  

  if (DAT_00a0f71c <= param_2) {

    uVar1 = FUN_006a3db0();

    param_1[2] = uVar1;

    param_1[1] = 0xff;

    param_1[3] = 0xff;

    *param_1 = 0;

    return param_1;

  }

  if (DAT_00a0f70c <= param_2) {

    param_1[2] = 0xff;

    uVar1 = FUN_006a3db0();

    param_1[1] = uVar1;

    param_1[3] = 0xff;

    *param_1 = 0;

    return param_1;

  }

  param_1[2] = 0xff;

  param_1[3] = 0xff;

  param_1[1] = 0;

  *param_1 = 0;

  return param_1;

}
