// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006863a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006863a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x006863a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper. Evidence string: "SetTreeSize() has no effect after DeleteTransientData() has been called". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "SetTreeSize() has no effect after DeleteTransientData() has been called"
//   - "SetTreeSize() is only valid for size values greater than 0.0"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: SetTreeSize×2, DeleteTransientData, FUN_006863a0, FUN_006971d0.
//  - Strings: "SetTreeSize() is only valid for size values greater than 0.0".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006863a0(int *param_1,float param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9d42;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(char *)(*param_1 + 0x21) == '\0') {

    pcVar1 = "SetTreeSize() has no effect after DeleteTransientData() has been called";

  }

  else {

    if (g_flZero < param_2) {

      ExceptionList = &local_10;

      FUN_006971d0(param_2,param_3);

      ExceptionList = local_10;

      return;

    }

    pcVar1 = "SetTreeSize() is only valid for size values greater than 0.0";

  }

  ExceptionList = &local_10;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,pcVar1);

  ExceptionList = local_10;

  return;

}
