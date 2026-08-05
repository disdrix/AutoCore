// =============================================================================
// FUN_007698e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007698e0
// Address:   0x007698e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007698e0 @ 0x007698e0
// Stable ID: aa_007698e0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"
//   - "Cannot seek outside current chunk frame"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_007698e0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Cannot seek outside current chunk frame".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_007698e0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint uVar3;

  int unaff_ESI;

  

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_ESI + 0x404c),"");

  if (*(int *)(unaff_ESI + 0x4044) == 0) {

    uVar3 = (*(int *)(unaff_ESI + 0x4040) + *(int *)(unaff_ESI + 0x403c)) - 1;

    if (*(uint *)(unaff_ESI + 0x4038) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(unaff_ESI + 0x4038);

    }

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x4034) + uVar3 * 4);

    iVar2 = *(int *)(iVar1 + 0x10);

    if ((in_EAX < iVar2 - *(int *)(iVar1 + 4)) || (iVar2 < in_EAX)) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x36d,3,

                     "Cannot seek outside current chunk frame");

      return 0xffffffff;

    }

  }

  if ((in_EAX < 0) || (*(int *)(unaff_ESI + 0x28) < in_EAX)) {

    return 0xffffffff;

  }

  iVar1 = *(int *)(unaff_ESI + 0x1c);

  if ((iVar1 <= in_EAX) && (in_EAX < *(int *)(unaff_ESI + 0x20) + iVar1)) {

    *(int *)(unaff_ESI + 0x18) = in_EAX - iVar1;

    return 0;

  }

  *(int *)(unaff_ESI + 0x1c) = in_EAX;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  return 0;

}
