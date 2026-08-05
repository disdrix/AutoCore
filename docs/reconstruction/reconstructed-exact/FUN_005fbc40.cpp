// =============================================================================
// FUN_005fbc40
// -----------------------------------------------------------------------------
// Stable ID: aa_005fbc40
// Address:   0x005fbc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fbc40 @ 0x005fbc40
// Stable ID: aa_005fbc40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_005fbc40, FUN_005ffdb0.
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

void __fastcall FUN_005fbc40(uint32_t /* width from decompiler */ *param_1)



{

  if (-1 < (int)param_1[0x22]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x20],(param_1[0x22] & 0x7fffffff) * 0xc0,0x12);

  }

  if (-1 < (int)param_1[0x1c]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1a],param_1[0x1c] * 4,0x12);

  }

  if (-1 < (int)param_1[0x18]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x16],param_1[0x18] * 4,0x12);

  }

  if (-1 < (int)param_1[0x15]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x13],param_1[0x15] * 4,0x12);

  }

  if (-1 < (int)param_1[0x12]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x10],param_1[0x12] * 4,0x12);

  }

  if (-1 < (int)param_1[0xf]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xd],param_1[0xf] * 4,0x12);

  }

  if (-1 < (int)param_1[0xc]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],param_1[0xc] * 4,0x12);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);

  }

  if (-1 < (int)param_1[6]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],param_1[6] * 4,0x12);

  }

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
