// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands_00402c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00402c70
// Callee of Named_CalleeOf_Client_RegisterDebugSlashCommands
// Address:   0x00402c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RegisterDebugSlashCommands: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00402c70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RegisterDebugSlashCommands
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands_00402c70(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,

            uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bbfb9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,param_2);

  pbVar2 = param_1 + 0x1c;

  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {

    *(uint32_t /* width from decompiler */ *)pbVar2 = *param_3;

    param_3 = param_3 + 1;

    pbVar2 = pbVar2 + 4;

  }

  ExceptionList = local_c;

  return param_1;

}
