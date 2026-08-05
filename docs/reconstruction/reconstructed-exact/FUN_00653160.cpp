// =============================================================================
// FUN_00653160
// -----------------------------------------------------------------------------
// Stable ID: aa_00653160
// Address:   0x00653160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653160 @ 0x00653160
// Stable ID: aa_00653160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006523f0, FUN_00652e20, FUN_00653160.
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

void __fastcall FUN_00653160(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e5c1c;

  param_1[2] = &PTR_LAB_009e5c14;

  param_1[5] = &PTR_FUN_009e5c08;

  param_1[6] = &PTR_LAB_009e5c00;

  if (param_1[3] != 0) {

    FUN_00652e20(0);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);

  }

  param_1[6] = &PTR_LAB_009db1d0;

  FUN_006523f0();

  return;

}
