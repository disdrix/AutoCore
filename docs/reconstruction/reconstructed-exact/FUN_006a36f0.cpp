// =============================================================================
// FUN_006a36f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a36f0
// Address:   0x006a36f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a36f0 @ 0x006a36f0
// Stable ID: aa_006a36f0
// Embedded strings (evidence for future rename):
//   - "Newran: seed out of range"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT44×3, FUN_006a3db0×2, FUN_00401aa0, FUN_006a36f0, _CxxThrowException.
//  - Strings: "Newran: seed out of range".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_006a36f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab3e9;

  local_c = ExceptionList;

  if (((double)CONCAT44(param_2,param_1) < _DAT_00aaa5f8) &&

     ((double)CONCAT44(param_2,param_1) < _DAT_00aaa608 ==

      ((double)CONCAT44(param_2,param_1) == _DAT_00aaa608))) {

    ExceptionList = &local_c;

    FUN_006a3db0();

    pfVar2 = (float *)&DAT_00d08fc8;

    do {

      iVar1 = FUN_006a3db0();

      param_1 = iVar1 * 0x41a7 + (iVar1 / 0x1f31d) * -0x7fffffff;

      if (param_1 < 1) {

        param_1 = param_1 + 0x7fffffff;

      }

      pfVar3 = pfVar2 + 1;

      *pfVar2 = _DAT_009e45b8 * (float)param_1;

      pfVar2 = pfVar3;

    } while ((int)pfVar3 < 0xd091c8);

    _DAT_00d091d0 = (double)param_1;

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_50,"Newran: seed out of range");

  local_4 = 0;

  FUN_00401aa0(local_50);

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc18c);

}
