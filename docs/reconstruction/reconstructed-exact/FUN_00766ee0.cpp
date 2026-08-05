// =============================================================================
// FUN_00766ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00766ee0
// Address:   0x00766ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00766ee0 @ 0x00766ee0
// Stable ID: aa_00766ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×2, while×1.
//  - Notable callees: FUN_00766ee0.
//  - Return sites: 2.

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

int FUN_00766ee0(void)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  int *unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  uint8_t auStack_4 [4];

  

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

            (unaff_EDI,0);

  bVar1 = false;

  cVar2 = (**(code **)(*unaff_ESI + 0x10))();

  if (cVar2 == '\0') {

    while( true ) {

      cVar2 = '\x01';

      iVar3 = (**(code **)(*unaff_ESI + 0x14))(auStack_4);

      if (iVar3 < 0) break;

      if (cVar2 == '\n') goto LAB_00766f4a;

      if (bVar1) {

        (**(code **)(*unaff_ESI + 4))(0xffffffff,1);

        goto LAB_00766f4a;

      }

      if (cVar2 == '\r') {

        bVar1 = true;

      }

      else {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        operator+=(unaff_EDI,cVar2);

      }

      cVar2 = (**(code **)(*unaff_ESI + 0x10))();

      if (cVar2 != '\0') {

        return 0;

      }

    }

  }

  else {

LAB_00766f4a:

    iVar3 = 0;

  }

  return iVar3;

}
