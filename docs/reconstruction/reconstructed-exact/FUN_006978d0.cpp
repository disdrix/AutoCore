// =============================================================================
// FUN_006978d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006978d0
// Address:   0x006978d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006978d0 @ 0x006978d0
// Stable ID: aa_006978d0
// Embedded strings (evidence for future rename):
//   - "malformed flare info"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~181 non-empty decompiler lines.
//  - Control keywords: if×13, return×13, while×1.
//  - Notable callees: FUN_00699ee0×13, FUN_006874b0×12, _CxxThrowException×12, FUN_00699ed0×10, FUN_006978d0.
//  - Strings: "malformed flare info".
//  - Return sites: 13.

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

void __fastcall FUN_006978d0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float10 fVar4;

  uint local_98;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  uint8_t local_78 [40];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aab4d;

  local_c = ExceptionList;

  local_98 = 0;

  ExceptionList = &local_c;

  while( true ) {

    if ((*(int *)(param_1 + 100) == 0) ||

       ((uint)(*(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2) <= local_98)) {

      iVar1 = FUN_00699ee0();

      if (iVar1 != 0x3e81) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"malformed flare info");

        local_4 = 0xb;

        FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      ExceptionList = local_c;

      return;

    }

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e82) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 0;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    iVar3 = local_98 * 4;

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x24) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e83) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 1;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    uVar2 = FUN_00699ee0();

    *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + iVar1) + 0x28) = uVar2;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e84) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 2;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x2c) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e85) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 3;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x30) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e86) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 4;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x34) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e87) break;

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x38) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e88) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 6;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x3c) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e89) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 7;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x40) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e8a) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 8;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x44) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e8b) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 9;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    *(float *)(*(int *)(iVar3 + iVar1) + 0x48) = (float)fVar4;

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3e8c) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed flare info");

      local_4 = 10;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *(int *)(param_1 + 100);

    fVar4 = (float10)FUN_00699ed0();

    local_98 = local_98 + 1;

    *(float *)(*(int *)(iVar1 + iVar3) + 0x4c) = (float)fVar4;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_94,"malformed flare info");

  local_4 = 5;

  FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

}
