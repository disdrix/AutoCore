// =============================================================================
// Named_char_h_c_f_r_1_0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a3f0
// Address:   0x0052a3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_char_h_c_f_r_1_0 @ 0x0052a3f0
// Stable ID: aa_0052a3f0
// Embedded strings (evidence for future rename):
//   - "char_h_c_f_r_1_0%i.dds"
//   - "char_m_c_f_r_1_0%i.dds"
//   - "char_b_c_f_r_1_0%i.dds"
//   - "char_h_c_f_e_1_0%i.dds"
//   - "char_m_c_f_e_1_0%i.dds"
//   - "char_b_c_f_e_1_0%i.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×14, return×5, goto×3, for×1, switch×1.
//  - Notable callees: FUN_0096efd0×2, FUN_00970140×2, sprintf×2, FUN_004101e0, Named_char_h_c_f_r_1_0, FUN_0096ef70, FUN_0096f3e0, FUN_00989e00.
//  - Strings: "char_h_c_f_r_1_0%i.dds"; "char_m_c_f_r_1_0%i.dds"; "char_b_c_f_r_1_0%i.dds"; "char_h_c_f_e_1_0%i.dds".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "char_h_c_f_r_1_0%i.dds"
 * Domain alias of FUN_0052a3f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_char_h_c_f_r_1_0(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *_Format;

  uint32_t /* width from decompiler */ local_128;

  uint8_t local_124 [4];

  char local_120 [2];

  uint32_t /* width from decompiler */ local_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a3b68;

  local_14 = ExceptionList;

  local_120[0] = '\0';

  local_120[1] = '\0';

  puVar4 = local_11e;

  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  iVar3 = *(int *)(param_1 + 0x67c + param_2 * 4);

  if (iVar3 == 0) {

    ExceptionList = local_14;

    return 0;

  }

  if (param_3 == 0) {

    ExceptionList = local_14;

    return 0;

  }

  if (param_4 < 1) {

    ExceptionList = local_14;

    return 0;

  }

  if ((param_2 == 1) || (param_2 == 4)) {

    cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c

                              ) + 0x532);

    if (cVar1 == '\0') {

      _Format = "char_h_c_f_r_1_0%i.dds";

    }

    else if (cVar1 == '\x01') {

      _Format = "char_m_c_f_r_1_0%i.dds";

    }

    else {

      ExceptionList = &local_14;

      if (cVar1 != '\x02') goto LAB_0052a51e;

      _Format = "char_b_c_f_r_1_0%i.dds";

    }

LAB_0052a515:

    ExceptionList = &local_14;

    sprintf(local_120,_Format,param_4);

  }

  else {

    if (param_2 == 6) {

      cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                0x3c) + 0x532);

      if (cVar1 == '\0') {

        _Format = "char_h_c_f_e_1_0%i.dds";

      }

      else if (cVar1 == '\x01') {

        _Format = "char_m_c_f_e_1_0%i.dds";

      }

      else {

        ExceptionList = &local_14;

        if (cVar1 != '\x02') goto LAB_0052a51e;

        _Format = "char_b_c_f_e_1_0%i.dds";

      }

      goto LAB_0052a515;

    }

    ExceptionList = &local_14;

    sprintf(local_120,"%S_0%i.dds",param_3 + 0xc,param_4);

  }

LAB_0052a51e:

  FUN_0096ef70();

  local_c = 0;

  FUN_00989e00(local_124,local_120);

  iVar2 = FUN_0096f3e0(local_124,0);

  if ((iVar2 < 0) || (iVar2 = FUN_00970140("DiffuseTexture",local_128), iVar2 < 0)) {

    local_c = 0xffffffff;

    FUN_0096efd0();

    ExceptionList = local_14;

    return 0;

  }

  switch(param_2) {

  case 4:

    cVar1 = FUN_004101e0();

    if (cVar1 != '\x01') break;

  case 1:

    *(int *)(param_1 + 0x674) = param_4;

    break;

  case 6:

    if (*(int *)(*(int *)(iVar3 + 0xc0) + 4) != 0) {

      FUN_00970140("DiffuseTexture",local_128);

    }

    *(int *)(param_1 + 0x670) = param_4;

    break;

  case 7:

    *(int *)(param_1 + 0x678) = param_4;

  }

  local_c = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_14;

  return 1;

}
