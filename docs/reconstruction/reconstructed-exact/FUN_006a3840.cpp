// =============================================================================
// FUN_006a3840
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3840
// Address:   0x006a3840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3840 @ 0x006a3840
// Stable ID: aa_006a3840
// Embedded strings (evidence for future rename):
//   - "Newran: area too small"
//   - "Newran: area too large"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: _CxxThrowException×2, exception::exception×2, CONCAT31, FUN_006a3840.
//  - Strings: "Newran: area too small"; "Newran: area too large".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006a3840(int *param_1,char param_2)



{

  float fVar1;

  void *pvVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  float local_9c;

  float local_98;

  undefined **appuStack_94 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_88 [28];

  undefined **appuStack_6c [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ab447;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(uint8_t *)(param_1 + 4) = 0;

  pvVar2 = operator_new__(0xf0);

  param_1[2] = (int)pvVar2;

  pvVar2 = operator_new__(0xf0);

  fVar4 = (float10)g_flZero;

  local_9c = g_flZero;

  param_1[3] = (int)pvVar2;

  local_98 = 0.01;

  if (param_2 == '\0') {

    local_98 = 0.02;

  }

  iVar3 = 0;

  do {

    *(float *)(param_1[2] + iVar3 * 4) = (float)fVar4;

    fVar5 = (float10)(**(code **)(*param_1 + 0xc))(local_9c);

    fVar4 = (float10)_DAT_00aaa608;

    *(float *)(param_1[3] + iVar3 * 4) = (float)fVar5;

    if (fVar5 < fVar4 != (fVar5 == fVar4)) {

      if (iVar3 < 0x32) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (abStack_44,"Newran: area too small");

        iStack_4 = 2;

        exception::exception((exception *)appuStack_6c);

        iStack_4._0_1_ = 3;

        appuStack_6c[0] = &PTR_FUN_009ea778;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (abStack_60,abStack_44);

        iStack_4 = CONCAT31(iStack_4._1_3_,2);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(appuStack_6c,(ThrowInfo *)&DAT_00acb3e8);

      }

      fVar1 = (float)iVar3;

      if (param_2 != '\0') {

        fVar1 = fVar1 + fVar1;

      }

      param_1[1] = (int)fVar1;

      ExceptionList = pvStack_c;

      return;

    }

    iVar3 = iVar3 + 1;

    fVar4 = (float10)local_98 / fVar5 + (float10)local_9c;

    local_9c = (float)fVar4;

  } while (iVar3 < 0x3c);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (abStack_28,"Newran: area too large");

  iStack_4 = 0;

  exception::exception((exception *)appuStack_94);

  iStack_4._0_1_ = 1;

  appuStack_94[0] = &PTR_FUN_009ea778;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (abStack_88,abStack_28);

  iStack_4 = (uint)iStack_4._1_3_ << 8;

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(appuStack_94,(ThrowInfo *)&DAT_00acb3e8);

}
