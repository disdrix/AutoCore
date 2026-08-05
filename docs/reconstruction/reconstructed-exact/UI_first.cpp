// =============================================================================
// UI_first
// -----------------------------------------------------------------------------
// Stable ID: aa_008dd590
// Address:   0x008dd590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_first @ 0x008dd590
// Stable ID: aa_008dd590
// Embedded strings (evidence for future rename):
//   - "i_d_first.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CDlgFirstTime_ctor, CONCAT31, FUN_0040fb90, FUN_0087b890, FUN_008dc1f0, FUN_008dc970.
//  - Strings: "i_d_first.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_first.xml"
 * Domain alias of FUN_008dd590 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * CDlgFirstTime_ctor(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b709b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  *param_1 = &PTR_FUN_00a3d8b4;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  local_4._0_1_ = 2;

  local_4._1_3_ = 0;

  uVar1 = FUN_0040fb90();

  param_1[0x153] = uVar1;

  param_1[0x154] = 0;

  local_4 = CONCAT31(local_4._1_3_,3);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  param_1[0x14b] = 0xffffffff;

  param_1[0x14c] = 0;

  *(uint8_t *)(param_1 + 0x146) = 0;

  *(uint8_t *)((int)param_1 + 0x519) = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  FUN_008dc1f0();

  FUN_008dc970("i_d_first.xml");

  ExceptionList = local_c;

  return param_1;

}
