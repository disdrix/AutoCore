// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00439e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00439e00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x00439e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00439e00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00439e00(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *in_EAX;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EBX;

  

  if (in_EAX != param_1) {

    do {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                (in_EAX,unaff_EBX);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                (in_EAX + 0x1c,unaff_EBX + 0x1c);

      in_EAX = in_EAX + 0x38;

    } while (in_EAX != param_1);

  }

  return;

}
