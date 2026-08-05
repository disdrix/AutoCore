// =============================================================================
// FUN_0073c040
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c040
// Address:   0x0073c040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073c040 @ 0x0073c040
// Stable ID: aa_0073c040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0073bf60, FUN_0073c040.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0073c040(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ab78b;

  local_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &local_c;

  FUN_0073bf60();

  local_4 = local_4 & 0xffffff00;

  _eh_vector_destructor_iterator_

            ((void *)(param_1 + 4),0x2c,4,

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>);

  DAT_00d1f62c = 0;

  ExceptionList = local_c;

  return;

}
