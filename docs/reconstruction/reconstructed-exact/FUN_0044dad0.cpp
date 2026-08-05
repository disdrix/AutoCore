// =============================================================================
// FUN_0044dad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044dad0
// Address:   0x0044dad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044dad0 @ 0x0044dad0
// Stable ID: aa_0044dad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0044dad0, FUN_0044dfc0.
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

void FUN_0044dad0(void)



{

  bool bVar1;

  int iVar2;

  int *unaff_EBX;

  int unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  

  iVar2 = FUN_0044dfc0(unaff_EDI);

  if (iVar2 != *(int *)(unaff_ESI + 4)) {

    bVar1 = std::operator><char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (unaff_EDI,

                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)(iVar2 + 0xc));

    if (!bVar1) {

      *unaff_EBX = iVar2;

      return;

    }

  }

  *unaff_EBX = *(int *)(unaff_ESI + 4);

  return;

}
