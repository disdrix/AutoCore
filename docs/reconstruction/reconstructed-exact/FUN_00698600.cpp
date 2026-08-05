// =============================================================================
// FUN_00698600
// -----------------------------------------------------------------------------
// Stable ID: aa_00698600
// Address:   0x00698600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00698600 @ 0x00698600
// Stable ID: aa_00698600
// Embedded strings (evidence for future rename):
//   - "malformed branch data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00699ee0×2, FUN_006874b0, FUN_00697f60, FUN_00698600, FUN_006a1fc0, _CxxThrowException.
//  - Strings: "malformed branch data".
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

void __thiscall FUN_00698600(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_54;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaa79;

  local_c = ExceptionList;

  if (*(void **)(param_1 + 100) != (void *)0x0) {

    ExceptionList = &local_c;

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 100));

  }

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  param_2 = FUN_00699ee0();

  if (0 < param_2) {

    do {

      local_54 = FUN_006a1fc0(uVar2);

      iVar3 = *(int *)(param_1 + 100);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0x6c) - iVar3 >> 2) <=

          (uint)(*(int *)(param_1 + 0x68) - iVar3 >> 2))) {

        FUN_00697f60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x68),1,&local_54);

      }

      else {

        puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x68);

        *puVar1 = local_54;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x68) = puVar1 + 1;

      }

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  iVar3 = FUN_00699ee0();

  if (iVar3 != 0x3f7) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"malformed branch data");

    local_4 = 0;

    FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

  }

  ExceptionList = local_c;

  return;

}
