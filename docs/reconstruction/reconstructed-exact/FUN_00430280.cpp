// =============================================================================
// FUN_00430280
// -----------------------------------------------------------------------------
// Stable ID: aa_00430280
// Address:   0x00430280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00430280 @ 0x00430280
// Stable ID: aa_00430280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00430280, FUN_004303c0, FUN_00430ce0.
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

int FUN_00430280(void)



{

  bool bVar1;

  int iVar2;

  int *piVar3;

  int unaff_EBX;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [28];

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bcd18;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_00430ce0(unaff_EDI);

  if (iVar2 != *(int *)(unaff_EBX + 4)) {

    bVar1 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (unaff_EDI,

                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(iVar2 + 0xc));

    if (!bVar1) goto LAB_004302f3;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c,unaff_EDI);

  local_10 = 0;

  local_4 = 0;

  piVar3 = (int *)FUN_004303c0(iVar2);

  iVar2 = *piVar3;

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c);

LAB_004302f3:

  ExceptionList = local_c;

  return iVar2 + 0x28;

}
