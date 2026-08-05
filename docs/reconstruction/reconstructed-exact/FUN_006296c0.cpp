// =============================================================================
// FUN_006296c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006296c0
// Address:   0x006296c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006296c0 @ 0x006296c0
// Stable ID: aa_006296c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_006296c0.
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

void __fastcall FUN_006296c0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e331c;

  param_1[7] = &PTR_LAB_009e3310;

  if (-1 < (int)param_1[0x25]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x23],param_1[0x25] * 8,0x12);

  }

  if (-1 < (int)param_1[0x22]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x20],param_1[0x22] * 8,0x12);

  }

  if (-1 < (int)param_1[0x1f]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1d],param_1[0x1f] * 8,0x12);

  }

  if (-1 < (int)param_1[0x1c]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1a],param_1[0x1c] << 4,0x12);

  }

  if (-1 < (int)param_1[0x18]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x16],param_1[0x18] * 4,0x12);

  }

  if (-1 < (int)param_1[0x15]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x13],param_1[0x15] * 4,0x12);

  }

  if (-1 < (int)param_1[0x11]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xf],param_1[0x11] * 4,0x12);

  }

  param_1[7] = &PTR_LAB_009d2794;

  *param_1 = &PTR_LAB_009cc290;

  return;

}
