// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00744a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00744a60
// Callee of Named_Client_InitInstance
// Address:   0x00744a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0044e060×2, FUN_0041c9d0, FUN_0044d9f0, FUN_0044e100, FUN_00744a60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_Client_InitInstance_00744a60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;

  undefined **ppuVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_68 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [28];

  undefined *local_30;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [28];

  undefined *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad839;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa1d94;

  param_1[1] = DAT_00d1ed24;

  param_1[2] = 0;

  param_1[3] = 0;

  iVar1 = FUN_0044e060();

  param_1[5] = iVar1;

  *(uint8_t *)(iVar1 + 0x25) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 4) = param_1[5];

  *(uint32_t /* width from decompiler */ *)param_1[5] = param_1[5];

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 8) = param_1[5];

  param_1[6] = 0;

  local_4 = 0;

  iVar1 = FUN_0044e060();

  param_1[8] = iVar1;

  *(uint8_t *)(iVar1 + 0x25) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[8] + 4) = param_1[8];

  *(uint32_t /* width from decompiler */ *)param_1[8] = param_1[8];

  *(uint32_t /* width from decompiler */ *)(param_1[8] + 8) = param_1[8];

  param_1[9] = 0;

  local_4._0_1_ = 1;

  param_1[10] = param_2;

  *(uint8_t *)(param_1 + 0xb) = 0;

  uVar2 = FUN_0041c9d0();

  param_1[0xd] = uVar2;

  param_1[0xe] = 0;

  local_4._0_1_ = 2;

  iVar1 = FUN_0044e100();

  param_1[0x10] = iVar1;

  *(uint8_t *)(iVar1 + 0x2d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 4) = param_1[0x10];

  *(uint32_t /* width from decompiler */ *)param_1[0x10] = param_1[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 8) = param_1[0x10];

  param_1[0x11] = 0;

  *(uint8_t *)(param_1 + 0x12) = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  local_4._0_1_ = 4;

  if (PTR_DAT_00afa300 != (undefined *)0x0) {

    ppuVar5 = &PTR_DAT_00afa300;

    pcVar3 = PTR_DAT_00afa300;

    do {

      pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                         (local_68,pcVar3);

      local_4._0_1_ = 5;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c,pbVar4);

      local_30 = ppuVar5[1];

      local_4._0_1_ = 6;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_2c,local_4c);

      local_10 = local_30;

      local_4._0_1_ = 7;

      FUN_0044d9f0(param_1 + 0xf);

      local_4._0_1_ = 6;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c);

      local_4._0_1_ = 5;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

      local_4._0_1_ = 4;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_68);

      pcVar3 = ppuVar5[2];

      ppuVar5 = ppuVar5 + 2;

    } while (pcVar3 != (char *)0x0);

  }

  ExceptionList = local_c;

  return param_1;

}
