// =============================================================================
// FUN_00523f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00523f50
// Address:   0x00523f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00523f50 @ 0x00523f50
// Stable ID: aa_00523f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×10, switch×1.
//  - Notable callees: FUN_00523f50.
//  - Return sites: 10.

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

void FUN_00523f50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  switch(param_2) {

  case 0:

    *param_1 = 0xff06ced5;

    return;

  case 1:

    *param_1 = 0xff007c1d;

    return;

  case 2:

    *param_1 = 0xff1f1401;

    return;

  case 3:

    *param_1 = 0xff0065b3;

    return;

  case 4:

    *param_1 = 0xff10480f;

    return;

  case 5:

    *param_1 = 0xff2f2801;

    return;

  case 6:

    *param_1 = 0xff2463f2;

    return;

  case 7:

    *param_1 = 0xff00310b;

    return;

  case 8:

    *param_1 = 0xff46482a;

    return;

  default:

    *param_1 = 0xffffffff;

    return;

  }

}
