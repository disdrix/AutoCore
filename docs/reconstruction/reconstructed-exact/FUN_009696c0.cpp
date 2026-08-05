// =============================================================================
// FUN_009696c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009696c0
// Address:   0x009696c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009696c0 @ 0x009696c0
// Stable ID: aa_009696c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0044d4e0, FUN_009694e0, FUN_009696c0.
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

void FUN_009696c0(uint32_t /* width from decompiler */ param_1)



{

  bool bVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  int unaff_EDI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac191;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_009694e0(local_28,param_1);

  local_4 = 0;

  pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

            (unaff_EDI + 4);

  if (pbVar2 != *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

                 (unaff_EDI + 8)) {

    do {

      bVar1 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (pbVar2,local_28);

      if (bVar1) break;

      pbVar2 = pbVar2 + 0x1c;

    } while (pbVar2 != *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                         **)(unaff_EDI + 8));

    if (pbVar2 != *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

                   (unaff_EDI + 8)) {

      FUN_0044d4e0(unaff_EDI,&param_1,pbVar2);

    }

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return;

}
