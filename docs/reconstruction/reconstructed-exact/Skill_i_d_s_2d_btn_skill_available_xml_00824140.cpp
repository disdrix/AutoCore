// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007b5dd0×2, FUN_00792600, FUN_0079c860, FUN_00824140.
//  - Strings: "i_d_s_2d_btn_skill_available.xml"; "i_d_s_2d_btn_skill_btn.xml".
//  - Return sites: 1.

// =============================================================================
// Skill_i_d_s_2d_btn_skill_available_xml_00824140
// -----------------------------------------------------------------------------
// Stable ID: aa_00824140
// Address:   0x00824140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_s_2d_btn_skill_available.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_i_d_s_2d_btn_skill_available_xml_00824140(int *param_1)



{

  int *piVar1;

  int iVar2;

  float *pfVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t **ppuStack_6c;

  uint32_t /* width from decompiler */ *puStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  void *pvStack_60;

  uint8_t *puStack_5c;

  char *pcStack_58;

  uint32_t /* width from decompiler */ uStack_50;

  char *pcStack_4c;

  void *pvStack_48;

  uint32_t /* width from decompiler */ uStack_40;

  char *pcStack_3c;

  void *pvStack_38;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4224;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvStack_38 = (void *)0x82416b;

  pvStack_38 = operator_new(0x488);

  local_4 = 0;

  if (pvStack_38 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    pcStack_3c = (char *)0x824186;

    piVar1 = (int *)FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  pvStack_38 = (void *)0x82419f;

  (**(code **)(*param_1 + 0xa8))();

  pvStack_38 = (void *)0xea61;

  pcStack_3c = (char *)0x8241ab;

  (**(code **)(*piVar1 + 0x74))();

  pcStack_3c = "i_d_s_2d_btn_skill_available.xml";

  uStack_40 = 0x8241b7;

  (**(code **)(*piVar1 + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x18b] = (int)piVar1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  uStack_40 = 1;

  (**(code **)(*param_1 + 0x3f4))();

  pvStack_48 = (void *)0x8241f1;

  pvStack_38 = operator_new(0x4cc);

  if (pvStack_38 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_0079c860();

  }

  pvStack_48 = (void *)0x824226;

  (**(code **)(*param_1 + 0xa8))();

  pvStack_48 = (void *)0xea60;

  pcStack_4c = (char *)0x824232;

  (**(code **)(*piVar1 + 0x74))();

  pcStack_4c = "i_d_s_2d_btn_skill_btn.xml";

  uStack_50 = 0x82423e;

  (**(code **)(*piVar1 + 0x28))();

  param_1[0x18a] = (int)piVar1;

  uStack_50 = 0;

  piVar1 = (int *)(**(code **)(*piVar1 + 0x164))();

  param_1[0x184] = *piVar1;

  pcStack_58 = (char *)0x824262;

  pcStack_58 = operator_new(0x488);

  pvStack_48 = pcStack_58;

  if (pcStack_58 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    puStack_5c = (uint8_t *)0x82427d;

    piVar1 = (int *)FUN_007b5dd0();

  }

  pcStack_58 = (char *)0x824296;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_58 = "i_d_s_2d_btn_skill_available.xml";

  puStack_5c = (uint8_t *)0x8242a2;

  (**(code **)(*piVar1 + 0x28))();

  puStack_5c = &stack0xffffffbc;

  param_1[0x18c] = (int)piVar1;

  pvStack_60 = (void *)0x8242b7;

  (**(code **)(*piVar1 + 0x124))();

  pvStack_60 = (void *)0x0;

  uStack_64 = 1;

  puStack_68 = &uStack_40;

  ppuStack_6c = (uint8_t **)0x8242f4;

  iVar2 = (**(code **)(*(int *)param_1[0x18c] + 0x120))();

  pcStack_58 = *(char **)(iVar2 + 4);

  puStack_5c = (uint8_t *)(int)(float)pvStack_60;

  ppuStack_6c = &puStack_5c;

  (**(code **)(*(int *)param_1[0x18c] + 0x110))();

  puVar4 = &uStack_50;

  pfVar3 = (float *)(**(code **)(*(int *)param_1[0x18c] + 0x134))(puVar4);

  puStack_68 = (uint32_t /* width from decompiler */ *)((float)DAT_00d1e818 * (*pfVar3 + DAT_00a1109c) * DAT_00aaa67c);

  iVar2 = (**(code **)(*(int *)param_1[0x18c] + 0x140))(&puStack_5c,1);

  puStack_68 = *(uint32_t /* width from decompiler */ **)(iVar2 + 4);

  ppuStack_6c = (uint8_t **)(int)(float)puVar4;

  (**(code **)(*(int *)param_1[0x18c] + 300))(&ppuStack_6c);

  iVar2 = (**(code **)(*(int *)param_1[0x18c] + 0x164))(0);

  *(uint8_t *)(iVar2 + 3) = 0;

  (**(code **)(*(int *)param_1[0x18c] + 0x300))(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_60;

  return;

}
