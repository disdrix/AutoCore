// =============================================================================
// FUN_005eddd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005eddd0
// Address:   0x005eddd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eddd0 @ 0x005eddd0
// Stable ID: aa_005eddd0
// Embedded strings (evidence for future rename):
//   - "Dividing Actor, please wait."
//   - " candidates considered."
//   - " divisions performed. "
//   - "Division complete. "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004f32d0, FUN_005ec6e0, FUN_005eced0, FUN_005eddd0.
//  - Strings: "Dividing Actor, please wait."; " candidates considered."; " divisions performed. "; "Division complete. ".
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ * __thiscall FUN_005eddd0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  basic_ostream<char,struct_std::char_traits<char>_> *pbVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  char *pcVar6;

  uint uVar7;

  char *pcVar8;

  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr

  *p_Var9;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a78b8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_004f32d0();

  local_4 = 0;

  p_Var9 = endl_exref;

  pbVar1 = std::operator<<<struct_std::char_traits<char>_>

                     ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,

                      "Dividing Actor, please wait.");

  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,p_Var9);

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0xc] = param_2[0xc];

  param_1[0xd] = param_2[0xd];

  puVar3 = param_2;

  puVar4 = param_1;

  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  param_1[9] = param_2[9];

  param_1[10] = param_2[10];

  param_1[0xb] = param_2[0xb];

  param_1[0xe] = param_2[0xe];

  *(uint16_t *)(param_1 + 0xf) = *(uint16_t *)(param_2 + 0xf);

  param_1[0x11] = param_2[0x11];

  param_1[0x10] = param_2[0x10];

  iVar2 = 0;

  param_2[0xc] = 0;

  param_2[0x11] = 0;

  param_2[0x10] = 0;

  if (0 < (int)(param_2[0x15] - param_2[0x14] & 0xfffffffc)) {

    do {

      FUN_005eced0(*(uint32_t /* width from decompiler */ *)(param_2[0x14] + iVar2 * 4),param_3);

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)(param_2[0x15] - param_2[0x14]) >> 2);

  }

  FUN_005ec6e0(param_2);

  uVar7 = param_1[0x19];

  uVar5 = param_1[0x1a];

  pcVar8 = " candidates considered.";

  pcVar6 = " divisions performed. ";

  p_Var9 = endl_exref;

  pbVar1 = std::operator<<<struct_std::char_traits<char>_>

                     ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,

                      "Division complete. ");

  pbVar1 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,uVar5);

  pbVar1 = std::operator<<<struct_std::char_traits<char>_>(pbVar1,pcVar6);

  pbVar1 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,uVar7);

  pbVar1 = std::operator<<<struct_std::char_traits<char>_>(pbVar1,pcVar8);

  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,p_Var9);

  ExceptionList = local_c;

  return param_1;

}
