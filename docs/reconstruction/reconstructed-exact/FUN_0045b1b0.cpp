// =============================================================================
// FUN_0045b1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045b1b0
// Address:   0x0045b1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045b1b0 @ 0x0045b1b0
// Stable ID: aa_0045b1b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×16, return×3, goto×1.
//  - Notable callees: CONCAT31×3, FUN_00437050×3, FUN_00769e40×3, FUN_00436f10×2, FUN_007689e0×2, FUN_0076a200×2, FUN_00989e00×2, FUN_0044c340.
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

uint32_t /* width from decompiler */ __thiscall FUN_0045b1b0(int *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  char local_50;

  int local_4c;

  int local_48;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befca;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if ((local_4c == 0x5042414d) || (local_4c == 0x5452414b)) {

    if (2 < local_48) {

      if (*(int *)(param_2 + 0x4044) == 0) {

        iVar1 = FUN_00468aa0();

      }

      else {

        iVar1 = FUN_007684e0();

      }

      if (iVar1 < 0) goto LAB_0045b469;

      iVar1 = FUN_0044c370();

      if (iVar1 != 0) {

        local_4 = 0xffffffff;

        if (local_50 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0xfffffffe;

      }

      FUN_0044c340();

    }

    if (local_48 < 2) {

      iVar1 = (**(code **)(*param_1 + 0x10))();

      param_1[4] = (-(uint)(iVar1 != 0x4b455556) & 0xe0501f8) + 0x45464354;

    }

    else if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437050();

    }

    else {

      FUN_007689e0();

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00436f10();

    }

    else {

      FUN_0076a200();

    }

    piVar2 = (int *)FUN_00989e00();

    param_1[5] = *piVar2;

    if (0 < local_48) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = CONCAT31(local_4._1_3_,2);

      if (*(int *)(param_2 + 0x4044) == 0) {

        FUN_00436f10();

      }

      else {

        FUN_0076a200();

      }

      piVar2 = (int *)FUN_00989e00();

      param_1[6] = *piVar2;

      local_4 = CONCAT31(local_4._1_3_,1);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437050();

    }

    else {

      FUN_007689e0();

    }

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437050();

    }

    else {

      FUN_00768760();

    }

    FUN_0045c5e0();

    if ((0 < param_2) && (iVar1 = FUN_0045e710(), iVar1 == 0)) {

      local_4 = local_4 & 0xffffff00;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

      local_4 = 0xffffffff;

      if (local_50 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0;

    }

    local_4 = local_4 & 0xffffff00;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  }

  else {

    vog_LogMessage();

  }

LAB_0045b469:

  local_4 = 0xffffffff;

  if (local_50 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
