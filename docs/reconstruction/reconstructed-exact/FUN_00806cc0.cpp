// =============================================================================
// FUN_00806cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00806cc0
// Address:   0x00806cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00806cc0 @ 0x00806cc0
// Stable ID: aa_00806cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: _eh_vector_destructor_iterator_×3, FUN_00803450, FUN_00803c20, FUN_00805030, FUN_00805300, FUN_00806cc0.
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

void __fastcall FUN_00806cc0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ad196;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a7f59c;

  local_4 = 7;

  if (*(char *)((int)param_1 + 0xd1d) != '\0') {

    (**(code **)(param_1[0x312] + 8))();

  }

  local_4._0_1_ = 6;

  FUN_00805030();

  local_4._0_1_ = 5;

  _eh_vector_destructor_iterator_(param_1 + 0x2d9,0x4c,3,FUN_00804970);

  local_4._0_1_ = 4;

  FUN_00803c20();

  param_1[0x1d8] = &PTR_FUN_00a7fed4;

  local_4._0_1_ = 3;

  FUN_00803450();

  local_4._0_1_ = 2;

  _eh_vector_destructor_iterator_(param_1 + 0x19c,0x3c,4,FUN_00805b30);

  param_1[0x18c] = &PTR_FUN_00a7fadc;

  param_1[0x18c] = &PTR_LAB_00a7f894;

  local_4 = (uint)local_4._1_3_ << 8;

  _eh_vector_destructor_iterator_(param_1 + 0x1c,0x170,4,FUN_00803450);

  local_4 = 0xffffffff;

  FUN_00805300();

  ExceptionList = pvStack_c;

  return;

}
