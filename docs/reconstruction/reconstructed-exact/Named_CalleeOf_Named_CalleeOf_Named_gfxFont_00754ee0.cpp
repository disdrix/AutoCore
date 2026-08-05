// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00754ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00754ee0
// Callee of Named_CalleeOf_Named_gfxFont
// Address:   0x00754ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxFont: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_004438c0, FUN_00754ee0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxFont
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00754ee0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009b0971;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = 0;

  *param_1 = &PTR_FUN_00a9f584;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  local_4 = 1;

  uStack_3 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 6));

  _local_4 = CONCAT31(uStack_3,2);

  param_1[0xe] = DAT_00d1f01c;

  param_1[0xf] = DAT_00d1f020;

  param_1[0x10] = 0;

  FUN_004438c0(param_1 + 0x11);

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = DAT_00d1f01c;

  param_1[0x2d] = DAT_00d1f020;

  ExceptionList = local_c;

  return param_1;

}
