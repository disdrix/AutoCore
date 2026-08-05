// =============================================================================
// FUN_0073bc50
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bc50
// Address:   0x0073bc50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold twin for FUN_0073bc50 @ 0x0073bc50
// Stable ID: aa_0073bc50
// Named plate (W37-AE): GlyphCache_GetOrCreate_ByFontKey_Inferred.cpp
// Dual-sealed 2026-08-04: GlyphCache map get-or-create; Arial fallback; RET 12.
// Embedded string: "Arial"

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00754a10×2, FUN_004638c0, FUN_00463c40, FUN_0073bc50, FUN_00754ee0.
//  - Strings: "Arial".
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

int * __thiscall FUN_0073bc50(uint32_t /* width from decompiler */ param_1,int param_2,char *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int iVar2;

  void *local_88 [2];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_80 [28];

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_5c [28];

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  int *piStack_38;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_34 [28];

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  int *piStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b11c0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_80);

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            (local_80,param_3);

  local_60 = param_4;

  local_64 = param_1;

  FUN_00463c40(param_2,local_88);

  if (local_88[0] == *(void **)(param_2 + 8)) {

    local_88[0] = operator_new(0xb8);

    local_4._0_1_ = 1;

    if (local_88[0] == (void *)0x0) {

      piVar1 = (int *)0x0;

    }

    else {

      piVar1 = (int *)FUN_00754ee0(local_88[0]);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    iVar2 = FUN_00754a10(param_3,param_1);

    if ((iVar2 < 0) && (iVar2 = FUN_00754a10("Arial",param_1), iVar2 < 0)) {

      if (piVar1 != (int *)0x0) {

        (**(code **)*piVar1)(1);

      }

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_80);

      ExceptionList = local_c;

      return (int *)0x0;

    }

    piVar1[1] = piVar1[1] + 1;

    if (piVar1[1] == 1) {

      (**(code **)(*piVar1 + 4))();

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5c,local_80);

    uStack_40 = local_64;

    uStack_3c = local_60;

    local_4._0_1_ = 2;

    piStack_38 = piVar1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (abStack_34,local_5c);

    uStack_18 = uStack_40;

    uStack_14 = uStack_3c;

    piStack_10 = piStack_38;

    local_4._0_1_ = 3;

    FUN_004638c0(local_88,abStack_34);

    local_4._0_1_ = 2;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_34);

    local_4 = (uint)local_4._1_3_ << 8;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5c);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_80);

  }

  else {

    piVar1 = *(int **)((int)local_88[0] + 0x2c);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_80);

  }

  ExceptionList = local_c;

  return piVar1;

}
