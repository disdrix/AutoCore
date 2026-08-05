// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00416410
// -----------------------------------------------------------------------------
// Stable ID: aa_00416410
// Callee of Named_effDeviceEffect
// Address:   0x00416410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00416410.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

Named_CalleeOf_Named_effDeviceEffect_00416410(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc093;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pbVar1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

           basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                     (local_28,param_2);

  local_4 = 1;

  pbVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

           operator+=(pbVar1,param_3);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,pbVar1);

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return param_1;

}
