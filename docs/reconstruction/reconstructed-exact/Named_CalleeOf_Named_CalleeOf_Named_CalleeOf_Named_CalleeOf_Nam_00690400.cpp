// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00690400
// -----------------------------------------------------------------------------
// Stable ID: aa_00690400
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00690400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00690400.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00690400(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  

  if (param_1 == param_2) {

    return param_3;

  }

  do {

    pbVar1 = param_2 + -0x2c;

    this = param_3 + -0x2c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (this,pbVar1);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0x10) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x10);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + -0xc);

    *(uint32_t /* width from decompiler */ *)(param_3 + -8) = *(uint32_t /* width from decompiler */ *)(param_2 + -8);

    *(uint32_t /* width from decompiler */ *)(param_3 + -4) = *(uint32_t /* width from decompiler */ *)(param_2 + -4);

    param_2 = pbVar1;

    param_3 = this;

  } while (pbVar1 != param_1);

  return this;

}
