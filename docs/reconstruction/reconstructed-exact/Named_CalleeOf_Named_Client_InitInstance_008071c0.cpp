// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_008071c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008071c0
// Callee of Named_Client_InitInstance
// Address:   0x008071c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "Auto Assault". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Auto Assault"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: _eh_vector_constructor_iterator_×3, GetTickCount×2, CONCAT31, FUN_00411180, FUN_00803c90, FUN_008043d0, FUN_008050a0, FUN_00805140.
//  - Strings: "Auto Assault".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_Client_InitInstance_008071c0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  DWORD DVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0258;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00805370(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a7f59c;

  _eh_vector_constructor_iterator_(param_1 + 0x1c,0x170,4,FUN_008034c0,FUN_00803450);

  local_4._0_1_ = 1;

  FUN_00805560(param_1 + 0x18c);

  local_4._0_1_ = 2;

  _eh_vector_constructor_iterator_(param_1 + 0x19c,0x3c,4,FUN_00805b70,FUN_00805b30);

  local_4._0_1_ = 3;

  FUN_008043d0(param_1 + 0x1d8);

  local_4._0_1_ = 4;

  FUN_00803c90(param_1 + 0x23e);

  local_4._0_1_ = 5;

  _eh_vector_constructor_iterator_(param_1 + 0x2d9,0x4c,3,FUN_008049b0,FUN_00804970);

  local_4._0_1_ = 6;

  FUN_008050a0(param_1 + 0x312);

  local_4 = CONCAT31(local_4._1_3_,7);

  *(uint8_t *)(param_1 + 0x347) = 5;

  *(uint8_t *)((int)param_1 + 0xd1e) = 5;

  param_1[0x346] = 0;

  *(uint8_t *)((int)param_1 + 0xd1d) = 1;

  param_1[0x33f] = 0;

  param_1[0x340] = 0;

  param_1[0x341] = 0;

  param_1[0x342] = 0;

  param_1[0x343] = 0;

  param_1[0x344] = 0;

  param_1[0x341] = 0;

  param_1[0x340] = 0;

  param_1[0x33f] = "Auto Assault";

  iVar1 = FUN_00805140();

  if ((iVar1 == 0) && (iVar1 = FUN_00806de0(), iVar1 == 0)) {

    DVar2 = GetTickCount();

    param_1[0x19] = DVar2;

    param_1[0x1a] = 0;

    param_1[0x1b] = 0xffffffff;

    FUN_00411180();

    if (param_1[0x336] == 0) {

      param_1[0x32e] = param_1;

      param_1[0x336] = 1;

    }

    DVar2 = GetTickCount();

    param_1[0x345] = DVar2;

    FUN_00806b90(0,5);

    ExceptionList = local_c;

    return param_1;

  }

  *(uint8_t *)((int)param_1 + 0xd1d) = 0;

  ExceptionList = local_c;

  return param_1;

}
