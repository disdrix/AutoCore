// =============================================================================
// FUN_00766fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00766fb0
// Address:   0x00766fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00766fb0 @ 0x00766fb0
// Stable ID: aa_00766fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00766fb0.
//  - Return sites: 3.

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

int FUN_00766fb0(void)



{

  char cVar1;

  int iVar2;

  int *unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  uint8_t auStack_4 [4];

  

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

            (unaff_EDI,0);

  cVar1 = (**(code **)(*unaff_ESI + 0x10))();

  while( true ) {

    if (cVar1 != '\0') {

      return -1;

    }

    cVar1 = (char)auStack_4;

    iVar2 = (**(code **)(*unaff_ESI + 0x14))(auStack_4,1);

    if (iVar2 < 0) break;

    if (cVar1 == '\0') {

      return 0;

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (unaff_EDI,cVar1);

    cVar1 = (**(code **)(*unaff_ESI + 0x10))();

  }

  return iVar2;

}
