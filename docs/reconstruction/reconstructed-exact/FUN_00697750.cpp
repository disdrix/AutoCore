// =============================================================================
// FUN_00697750
// -----------------------------------------------------------------------------
// Stable ID: aa_00697750
// Address:   0x00697750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00697750 @ 0x00697750
// Stable ID: aa_00697750
// Embedded strings (evidence for future rename):
//   - "malformed texture controls"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, while×1.
//  - Notable callees: FUN_006874b0×3, FUN_00699ee0×3, _CxxThrowException×3, FUN_00697750, FUN_00699ed0.
//  - Strings: "malformed texture controls".
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

void __thiscall FUN_00697750(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  uint local_98;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  uint8_t local_78 [40];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaab1;

  local_c = ExceptionList;

  local_98 = 0;

  ExceptionList = &local_c;

  while( true ) {

    if ((*(int *)(param_1 + 100) == 0) ||

       ((uint)(*(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2) <= local_98)) {

      iVar1 = FUN_00699ee0();

      if (iVar1 != 0x3a99) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"malformed texture controls");

        local_4 = 2;

        FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      ExceptionList = local_c;

      return;

    }

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3a9a) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed texture controls");

      local_4 = 0;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = *param_2;

    *param_2 = iVar1 + 1;

    iVar2 = local_98 * 4;

    *(bool *)(*(int *)(iVar2 + *(int *)(param_1 + 100)) + 0x1e) =

         *(char *)(iVar1 + param_2[2]) != '\0';

    iVar1 = FUN_00699ee0();

    if (iVar1 != 0x3a9b) break;

    iVar1 = *(int *)(param_1 + 100);

    fVar3 = (float10)FUN_00699ed0();

    local_98 = local_98 + 1;

    *(float *)(*(int *)(iVar1 + iVar2) + 0x20) = (float)fVar3;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_94,"malformed texture controls");

  local_4 = 1;

  FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_78,(ThrowInfo *)&DAT_00ac9e00);

}
