// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_0076a150
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a150
// Callee of Named_effDeviceEffect (+1 other named callers)
// Address:   0x0076a150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effDeviceEffect (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00769fd0, FUN_0076a150.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_effDeviceEffect_0076a150(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009afff1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  local_4 = 0;

  param_1[5] = param_2;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0x4000;

  param_1[10] = 0;

  uVar1 = (**(code **)(*param_2 + 0x1c))();

  param_1[10] = uVar1;

  param_1[0x100b] = 0;

  param_1[0x100d] = 0;

  param_1[0x100e] = 0;

  param_1[0x100f] = 0;

  param_1[0x1010] = 0;

  local_4._0_1_ = 1;

  *(uint8_t *)(param_1 + 0x1012) = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x1013),"");

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00769fd0();

  ExceptionList = pvStack_c;

  return param_1;

}
