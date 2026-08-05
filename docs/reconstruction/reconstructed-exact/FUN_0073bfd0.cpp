// =============================================================================
// FUN_0073bfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bfd0
// Address:   0x0073bfd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073bfd0 @ 0x0073bfd0
// Stable ID: aa_0073bfd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0073bfd0.
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

void FUN_0073bfd0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab51a;

  local_c = ExceptionList;

  local_4 = 0;

  DAT_00d1f62c = unaff_ESI;

  ExceptionList = &local_c;

  *unaff_ESI = 0;

  _eh_vector_constructor_iterator_

            (unaff_ESI + 1,0x2c,4,FUN_00462230,

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>);

  puVar2 = unaff_ESI + 1;

  for (iVar1 = 0x2c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  unaff_ESI[0x2d] = 0;

  unaff_ESI[0x2e] = 0;

  unaff_ESI[0x2f] = 0;

  unaff_ESI[0x30] = 0;

  ExceptionList = local_c;

  return;

}
