// =============================================================================
// FUN_0042a4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a4d0
// Address:   0x0042a4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a4d0 @ 0x0042a4d0
// Stable ID: aa_0042a4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0042a4d0.
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

void FUN_0042a4d0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009be1d3;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  if (-1 < (int)param_1[7]) {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[5],param_1[7] * 8,0x12);

  }

  local_4 = local_4 & 0xffffff00;

  if (-1 < (int)param_1[4]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],(param_1[4] & 0x7fffffff) * 0xc,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  ExceptionList = pvStack_c;

  return;

}
