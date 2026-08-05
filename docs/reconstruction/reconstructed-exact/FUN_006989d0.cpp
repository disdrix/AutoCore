// =============================================================================
// FUN_006989d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006989d0
// Address:   0x006989d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006989d0 @ 0x006989d0
// Stable ID: aa_006989d0
// Embedded strings (evidence for future rename):
//   - "malformed general tree information"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×10, goto×2, return×2, do×1, switch×1, while×1.
//  - Notable callees: FUN_00699ed0×4, FUN_00699ee0×4, FUN_00685ee0, FUN_00685f40, FUN_006874b0, FUN_00698600, FUN_006989d0, FUN_00699f00.
//  - Strings: "malformed general tree information".
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

void __thiscall FUN_006989d0(int param_1,int *param_2)



{

  int iVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  uint32_t /* width from decompiler */ uVar3;

  float10 fVar4;

  uint8_t auStack_b8 [16];

  undefined *puStack_a8;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_88 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aac6c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00699ee0();

  do {

    if (iVar1 < 0x7d4) {

      if (iVar1 == 0x7d3) {

        fVar4 = (float10)FUN_00699ed0();

        *(float *)(param_1 + 0x44) = (float)fVar4;

      }

      else if (iVar1 < 0x7d2) {

        if (iVar1 == 0x7d1) {

          fVar4 = (float10)FUN_00699ed0();

          *(float *)(param_1 + 0x40) = (float)fVar4;

        }

        else if (iVar1 == 0x3f6) {

          FUN_00698600();

        }

        else {

          if (iVar1 != 2000) goto switchD_00698afb_default;

          FUN_00699f00(auStack_b8);

          FUN_00685ee0();

          local_4 = 0;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          operator=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                    (param_1 + 0x24),local_88);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_88);

          pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   FUN_00685f40();

          local_4 = 1;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          operator=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                    (param_1 + 0x24),pbVar2);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_6c);

        }

      }

      else {

        if (iVar1 != 0x7d2) goto switchD_00698afb_default;

        *param_2 = *param_2 + 1;

      }

    }

    else {

      switch(iVar1) {

      case 0x7d4:

        FUN_00699ee0();

        break;

      case 0x7d5:

        iVar1 = FUN_00699ee0();

        if (iVar1 == 0) {

          FUN_006a1c00();

          puStack_a8 = (undefined *)0x698b29;

          FUN_006a1be0();

          uVar3 = FUN_006a3db0();

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = uVar3;

        }

        else if (iVar1 != 1) {

          *(int *)(param_1 + 0x48) = iVar1;

        }

        break;

      case 0x7d6:

        fVar4 = (float10)FUN_00699ed0();

        *(float *)(param_1 + 0x4c) = (float)fVar4;

        break;

      case 0x7d7:

        fVar4 = (float10)FUN_00699ed0();

        *(float *)(param_1 + 0x50) = (float)fVar4;

        break;

      default:

switchD_00698afb_default:

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"malformed general tree information");

        local_4 = 2;

        puStack_a8 = (undefined *)0x698bb3;

        FUN_006874b0();

                    /* WARNING: Subroutine does not return */

        puStack_a8 = &UNK_00698bc2;

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

    }

    iVar1 = FUN_00699ee0();

    if (iVar1 == 0x3eb) {

      ExceptionList = local_c;

      return;

    }

  } while( true );

}
