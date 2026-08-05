// =============================================================================
// FUN_0073dff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073dff0
// Address:   0x0073dff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073dff0 @ 0x0073dff0
// Stable ID: aa_0073dff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: _snprintf×2, FUN_0073d640, FUN_0073dff0, FUN_0075d9c0, FUN_00766250.
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

void __thiscall FUN_0073dff0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  int iVar3;

  uint uVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];

  char local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b084c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(int *)(param_1 + 0x24) == 0) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

    local_4 = 0;

    FUN_0073d640(param_2);

    uVar1 = FUN_00766250();

    _snprintf(local_2c,0x20,"%u",uVar1);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (param_1 + 0x10),local_2c);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

  }

  this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

         (param_1 + 0x2c);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            (this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                  (param_1 + 0x10));

  for (uVar4 = 0;

      (iVar3 = *(int *)(param_3 + 4), iVar3 != 0 &&

      (uVar4 < (uint)(*(int *)(param_3 + 8) - iVar3 >> 2))); uVar4 = uVar4 + 1) {

    pcVar2 = *(char **)(iVar3 + uVar4 * 4);

    if (pcVar2 == (char *)0x0) {

      pcVar2 = PTR_DAT_00afa2bc;

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (this,pcVar2);

    uVar1 = FUN_0075d9c0(iVar3 + uVar4 * 4);

    _snprintf(local_2c,0x20,"%u",uVar1);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (this,local_2c);

  }

  for (iVar3 = *(int *)(param_1 + 0x40); iVar3 != 0; iVar3 = iVar3 + -1) {

  }

  ExceptionList = local_c;

  return;

}
