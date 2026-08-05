// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00686c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00686c00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x00686c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper. Evidence string: "SetFrondWindMethod() has no effect after Compute() has been called". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "SetFrondWindMethod() has no effect after Compute() has been called"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Compute, FUN_00686c00, FUN_0068b820, SetFrondWindMethod.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00686c00(int param_1,int param_2)



{

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9e22;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(char *)(param_1 + 0x45) == '\0') {

    if ((param_2 == 2) && (*(int *)(*(int *)(param_1 + 0x10) + 0xc) == 1)) {

      ExceptionList = &local_10;

      *(uint8_t *)(*(int *)(param_1 + 0x5c) + 0x12) = 0;

      FUN_0068b820(0);

    }

    *(int *)(*(int *)(param_1 + 0x10) + 0xc) = param_2;

    *(bool *)(*(int *)(param_1 + 0x5c) + 8) = param_2 != 2;

    *(int *)(*(int *)(param_1 + 0x5c) + 0x14) = param_2;

    ExceptionList = local_10;

    return;

  }

  ExceptionList = &local_10;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,"SetFrondWindMethod() has no effect after Compute() has been called");

  ExceptionList = local_10;

  return;

}
