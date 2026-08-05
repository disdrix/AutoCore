// =============================================================================
// FUN_00689fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00689fd0
// Address:   0x00689fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00689fd0 @ 0x00689fd0
// Stable ID: aa_00689fd0
// Embedded strings (evidence for future rename):
//   - "malformed texture coord info"
//   - "premature end of file reached parsing texture coordinate info"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, do×2, while×2, switch×1.
//  - Notable callees: FUN_006874b0×2, FUN_00699ee0×2, _CxxThrowException×2, FUN_00685ee0, FUN_00685f40, FUN_00689fd0, FUN_00699ed0, FUN_00699f00.
//  - Strings: "malformed texture coord info".
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

void __thiscall FUN_00689fd0(int param_1,uint *param_2)



{

  uint uVar1;

  int iVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  float10 fVar4;

  uint8_t auStack_fc [16];

  undefined *puStack_ec;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_cc [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_b0 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];

  uint8_t local_5c [40];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa15b;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x4c) != 0) {

    ExceptionList = &local_c;

    iVar2 = FUN_00699ee0();

    do {

      switch(iVar2) {

      case 0x4e22:

        FUN_00699f00(auStack_fc);

        FUN_00685ee0();

        local_4 = 0;

        pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 FUN_00685f40();

        local_4._0_1_ = 1;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   (*(int *)(param_1 + 0x4c) + 0x18),pbVar3);

        local_4 = (uint)local_4._1_3_ << 8;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_78);

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_cc);

        break;

      case 0x4e23:

        uVar1 = *param_2;

        *param_2 = uVar1 + 1;

        *(bool *)(param_1 + 0x69) = *(char *)(uVar1 + param_2[2]) != '\0';

        break;

      case 0x4e24:

        uVar1 = *param_2;

        *param_2 = uVar1 + 1;

        *(bool *)(param_1 + 0x68) = *(char *)(uVar1 + param_2[2]) != '\0';

        break;

      case 0x4e25:

        iVar2 = 0x34;

        do {

          fVar4 = (float10)FUN_00699ed0();

          *(float *)(iVar2 + *(int *)(param_1 + 0x4c)) = (float)fVar4;

          iVar2 = iVar2 + 4;

        } while (iVar2 < 0x54);

        break;

      default:

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_94,"malformed texture coord info");

        local_4 = 2;

        puStack_ec = (undefined *)0x68a17c;

        FUN_006874b0();

                    /* WARNING: Subroutine does not return */

        puStack_ec = &UNK_0068a18e;

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      if ((param_2[2] == 0) || (param_2[3] - param_2[2] <= *param_2)) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_b0,"premature end of file reached parsing texture coordinate info");

        local_4 = 3;

        puStack_ec = (undefined *)0x68a13e;

        FUN_006874b0();

                    /* WARNING: Subroutine does not return */

        puStack_ec = (undefined *)0x68a150;

        _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);

      }

      iVar2 = FUN_00699ee0();

    } while (iVar2 != 0x4e21);

  }

  ExceptionList = local_c;

  return;

}
