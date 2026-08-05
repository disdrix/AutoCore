// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00464080
// -----------------------------------------------------------------------------
// Stable ID: aa_00464080
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxFont
// Address:   0x00464080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxFont: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00464080.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxFont
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00464080(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc8f1;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x30);

  local_8 = 1;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = param_3;

    *puVar1 = param_2;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (puVar1 + 2),param_1);

    puVar1[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    puVar1[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    puVar1[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  }

  ExceptionList = local_10;

  return puVar1;

}
