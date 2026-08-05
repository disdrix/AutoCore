// =============================================================================
// FUN_005b4600
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4600
// Address:   0x005b4600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4600 @ 0x005b4600
// Stable ID: aa_005b4600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, goto×1, return×1.
//  - Notable callees: FUN_005b4600.
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall

FUN_005b4600(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  char local_400 [1024];

  

  pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::c_str

                     (param_1);

  pcVar4 = local_400;

  do {

    cVar1 = *pcVar3;

    *pcVar4 = cVar1;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  uVar2 = *(uint *)(param_1 + 0x14);

  do {

    uVar2 = uVar2 - 1;

    if (((int)uVar2 < 0) ||

       (pcVar4 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 operator[](param_1,uVar2), *pcVar4 == '/')) goto LAB_005b467b;

    pcVar4 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             operator[](param_1,uVar2);

  } while (*pcVar4 != '.');

  uVar5 = 0;

  if (0 < (int)uVar2) {

    do {

      pcVar4 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               operator[](param_1,uVar5);

      local_400[uVar5] = *pcVar4;

      uVar5 = uVar5 + 1;

    } while ((int)uVar5 < (int)uVar2);

  }

  local_400[uVar5] = '\0';

LAB_005b467b:

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_2,local_400);

  return param_2;

}
