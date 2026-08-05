// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007543b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007543b0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x007543b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, CoInitializeEx, FUN_007543b0, FUN_0075d470.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007543b0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009afd58;

  local_c = ExceptionList;

  DAT_00d1f058 = param_1;

  local_4 = 0;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a9f76c;

  *(uint8_t *)(param_1 + 1) = 0;

  *(uint8_t *)((int)param_1 + 5) = 1;

  *(uint8_t *)((int)param_1 + 6) = 0;

  param_1[2] = DAT_00d1f01c;

  param_1[3] = DAT_00d1f020;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  CoInitializeEx((LPVOID)0x0,2);

  local_4._0_1_ = 1;

  param_1[9] = 0xffffffff;

  param_1[10] = 0;

  param_1[0xb] = 0;

  FUN_0075d470(param_1 + 0xc);

  DAT_00d1f1fc = param_1 + 0x28;

  param_1[0x29] = 0;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  local_4 = CONCAT31(local_4._1_3_,4);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x2d),".");

  *(uint8_t *)((int)param_1 + 0xd1) = 0;

  param_1[0x35] = 0;

  *(uint8_t *)(param_1 + 0x34) = 1;

  ExceptionList = local_c;

  return param_1;

}
