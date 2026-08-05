// =============================================================================
// Named_CalleeOf_Named_gfxBody_0096a630
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a630
// Callee of Named_gfxBody (+10 other named callers)
// Address:   0x0096a630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper. Evidence string: "assId: [%s]". Supports parent flow (not a free-standing entry point). Named_gfxBody (+10 other named callers).
// Embedded strings (evidence):
//   - "assId: [%s]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0096a630, sprintf.
//  - Strings: "assId: [%s]".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody (+10 other named callers)
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall

Named_CalleeOf_Named_gfxBody_0096a630(int *param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  undefined *puVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_12c [28];

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab872;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_12c);

  local_4 = 1;

  puVar1 = (undefined *)*param_1;

  if ((undefined *)*param_1 == (undefined *)0x0) {

    puVar1 = PTR_DAT_00afa2bc;

  }

  sprintf(local_110,"assId: [%s]",puVar1);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            (local_12c,local_110);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_2,local_12c);

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_12c);

  ExceptionList = local_c;

  return param_2;

}
