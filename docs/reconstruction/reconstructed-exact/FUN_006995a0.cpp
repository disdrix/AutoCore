// =============================================================================
// FUN_006995a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006995a0
// Address:   0x006995a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006995a0 @ 0x006995a0
// Stable ID: aa_006995a0
// Embedded strings (evidence for future rename):
//   - "missing begin_file token"
//   - "not a valid SpeedTree SPT file"
//   - "malformed SpeedTree SPT file"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×1, while×1.
//  - Notable callees: FUN_00699ee0×4, FUN_006874b0×3, _CxxThrowException×3, CONCAT31×2, FUN_006974a0, FUN_00698700, FUN_006989d0, FUN_00699130.
//  - Strings: "missing begin_file token"; "not a valid SpeedTree SPT file"; "malformed SpeedTree SPT file".
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

uint32_t /* width from decompiler */ __thiscall FUN_006995a0(int param_1,uint *param_2)



{

  bool bVar1;

  int iVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_b0 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  uint8_t local_78 [40];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aad29;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_00699ee0();

  if (iVar2 != 1000) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_b0,"missing begin_file token");

    local_4 = 0;

    FUN_006874b0(local_b0,0);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

  }

  FUN_00699f00(local_94);

  local_4 = 1;

  pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

           basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                     (local_b0,PTR_s___IdvSpt_02__00af5558);

  local_4._0_1_ = 2;

  bVar1 = std::operator!=<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (local_94,pbVar3);

  local_4._0_1_ = 1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_b0);

  if (bVar1) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_b0,"not a valid SpeedTree SPT file");

    local_4 = CONCAT31(local_4._1_3_,3);

    FUN_006874b0(local_b0,0);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

  }

  iVar2 = FUN_00699ee0();

  do {

    if (iVar2 == 0x3ea) {

      FUN_006989d0(param_2);

    }

    else if (iVar2 == 0x3ec) {

      FUN_0069efb0(param_2);

    }

    else {

      if (iVar2 != 0x3f3) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"malformed SpeedTree SPT file");

        local_4 = CONCAT31(local_4._1_3_,4);

        FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      FUN_006a29f0(param_2);

    }

    iVar2 = FUN_00699ee0();

  } while (iVar2 != 0x3e9);

  if ((param_2[2] != 0) && (*param_2 < param_2[3] - param_2[2])) {

    iVar2 = FUN_0069a000();

    if (iVar2 == 7000) {

      FUN_00699ee0();

      FUN_00698700(param_2);

    }

  }

  FUN_006974a0(param_1 + 0x24);

  FUN_00699130(param_1 + 0x90);

  if (DAT_00aaa668 < *(float *)(param_1 + 0x18)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_94);

  ExceptionList = local_c;

  return 1;

}
