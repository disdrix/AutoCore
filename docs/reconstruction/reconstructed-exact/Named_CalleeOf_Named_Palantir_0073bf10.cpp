// =============================================================================
// Named_CalleeOf_Named_Palantir_0073bf10
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bf10
// Callee of Named_Palantir
// Address:   0x0073bf10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0073bf10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_Palantir_0073bf10(int *param_1,char *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  int unaff_EBX;

  int unaff_EDI;

  

  if (((param_2 != (char *)0x0) && (unaff_EBX != 0)) && (unaff_EDI != 0)) {

    this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           (param_1 + *param_1 * 0xb + 1);

    *param_1 = *param_1 + 1;

    *(int *)(this + 0x1c) = unaff_EBX;

    *(int *)(this + 0x20) = unaff_EDI;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (this,param_2);

    *(uint32_t /* width from decompiler */ *)(this + 0x24) = param_3;

    *(uint32_t /* width from decompiler */ *)(this + 0x28) = param_4;

    return 0;

  }

  return 0xffffffff;

}
