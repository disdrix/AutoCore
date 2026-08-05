// =============================================================================
// FUN_00745a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00745a30
// Address:   0x00745a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00745a30 @ 0x00745a30
// Stable ID: aa_00745a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: begin×2, FUN_00436ef0, FUN_00436f10, FUN_00437050, FUN_0043bfb0, FUN_0044d400, FUN_00745a30, FUN_0075d530.
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

void __thiscall FUN_00745a30(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ ****ppppuVar6;

  int local_3c [4];

  uint8_t local_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ ***local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1a1c;

  local_c = ExceptionList;

  local_3c[0] = 0;

  if (*(int *)(param_1 + 0x4044) == 0) {

    ExceptionList = &local_c;

    FUN_00437050(local_3c);

  }

  else {

    ExceptionList = &local_c;

    FUN_00768760(local_3c);

  }

  iVar2 = param_2;

  if (0 < local_3c[0]) {

    do {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = 0;

      if (*(int *)(param_1 + 0x4044) == 0) {

        FUN_00436f10();

      }

      else {

        FUN_0076a200();

      }

      puVar3 = (uint32_t /* width from decompiler */ *)

               std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               begin(local_28);

      puVar4 = (uint32_t /* width from decompiler */ *)

               std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               end(local_28);

      puVar5 = (uint32_t /* width from decompiler */ *)

               std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               begin(local_28);

      FUN_0044d400(local_2c,*puVar5,*puVar4,*puVar3,tolower_exref);

      ppppuVar6 = (uint32_t /* width from decompiler */ ****)local_24[0];

      if (local_10 < 0x10) {

        ppppuVar6 = local_24;

      }

      FUN_00989e00(&param_2,ppppuVar6);

      iVar1 = *(int *)(iVar2 + 0x50);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(iVar2 + 0x58) - iVar1 >> 2) <= (uint)(*(int *)(iVar2 + 0x54) - iVar1 >> 2)

         )) {

        FUN_0043bfb0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x54),1,&param_2);

      }

      else {

        iVar1 = *(int *)(iVar2 + 0x54);

        FUN_00436ef0(param_2);

        *(int *)(iVar2 + 0x54) = iVar1 + 4;

      }

      if (DAT_00d1f050 != 0) {

        FUN_0075d530();

      }

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_3c[0] = local_3c[0] + -1;

    } while (local_3c[0] != 0);

  }

  ExceptionList = local_c;

  return;

}
