// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_0073e3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e3a0
// Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
// Address:   0x0073e3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0043bd40, FUN_0073e3a0, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_0073e3a0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009b2151;

  local_c = ExceptionList;

  DAT_00d1f61c = param_1;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  local_4 = 1;

  uStack_3 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x10));

  local_4 = 2;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x2c));

  _local_4 = CONCAT31(uStack_3,3);

  if ((_DAT_00d1f7e0 & 1) == 0) {

    _DAT_00d1f7e0 = _DAT_00d1f7e0 | 1;

    _DAT_00d1f7dc = &PTR_FUN_00a9f9a0;

    _atexit((_func_4879 *)&LAB_009c33f0);

  }

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0043bd40();

  *puVar1 = &LAB_0073e260;

  puVar1[1] = 0;

  ExceptionList = local_c;

  return param_1;

}
