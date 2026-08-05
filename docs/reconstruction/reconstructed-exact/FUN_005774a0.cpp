// =============================================================================
// FUN_005774a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005774a0
// Address:   0x005774a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005774a0 @ 0x005774a0
// Stable ID: aa_005774a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: return×9, switch×1.
//  - Notable callees: FUN_005774a0.
//  - Return sites: 9.

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

void FUN_005774a0(uint8_t *param_1,uint32_t /* width from decompiler */ param_2)



{

  switch(param_2) {

  case 1:

    param_1[2] = 0xcc;

    param_1[1] = 0;

    *param_1 = 0x33;

    param_1[3] = 0xfe;

    return;

  case 2:

    param_1[2] = 0xff;

    param_1[1] = 200;

    *param_1 = 100;

    param_1[3] = 0xfe;

    return;

  case 3:

    *param_1 = 0xa5;

    param_1[1] = 0xa5;

    param_1[2] = 0xa5;

    param_1[3] = 0xfe;

    return;

  case 4:

    param_1[1] = 0xff;

    *param_1 = 100;

    param_1[2] = 100;

    param_1[3] = 0xfe;

    return;

  case 5:

    param_1[2] = 0xd2;

    param_1[1] = 0xff;

    *param_1 = 0xd2;

    param_1[3] = 0xfe;

    return;

  case 6:

    param_1[1] = 0xd2;

    *param_1 = 0xff;

    param_1[2] = 0xff;

    param_1[3] = 0xfe;

    return;

  case 7:

    *param_1 = 0xff;

    param_1[1] = 100;

    param_1[2] = 100;

    param_1[3] = 0xfe;

    return;

  case 8:

    *param_1 = 0xff;

    param_1[1] = 0xff;

    param_1[2] = 0xff;

    param_1[3] = 0xfe;

    return;

  default:

    *param_1 = 200;

    param_1[1] = 0xff;

    param_1[2] = 0xff;

    param_1[3] = 0xfe;

    return;

  }

}
