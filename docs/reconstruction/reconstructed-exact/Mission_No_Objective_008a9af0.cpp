// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_0096f840×3, FUN_0078be40, FUN_0078caf0, FUN_00792600, FUN_008a9af0.
//  - Strings: "i_d_obj_exp_wnd_text.xml"; "No Objective"; "i_d_obj_exp_wnd_distance.xml"; "i_d_obj_exp_wnd_arrow.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_No_Objective_008a9af0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a9af0
// Address:   0x008a9af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "No Objective"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_No_Objective_008a9af0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  char *pcStack_3c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b639c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x19f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x19f] + 0x28))();

  (**(code **)(*(int *)param_1[0x19f] + 0xfc))();

  pcStack_3c = (char *)0x8a9b81;

  pcStack_3c = operator_new(0x488);

  if (pcStack_3c == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    uStack_40 = 0x8a9b9c;

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x1a2] = iVar2;

  pcStack_3c = (char *)0x8a9bb5;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_3c = "i_d_obj_exp_wnd_text.xml";

  uStack_40 = 0x8a9bc5;

  (**(code **)(*(int *)param_1[0x1a2] + 0x28))();

  uStack_40 = 0x3f000000;

  uStack_44 = 1;

  uStack_48 = 0x8a9bda;

  (**(code **)(*(int *)param_1[0x1a2] + 0xfc))();

  uStack_48 = 1;

  (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))("No Objective",1);

  uVar6 = 1;

  puVar5 = &uStack_48;

  piVar3 = (int *)(**(code **)(*(int *)param_1[0x1a2] + 0x120))(puVar5,1,0);

  param_1[399] = *piVar3;

  param_1[400] = piVar3[1];

  pvVar1 = operator_new(0x488);

  pcStack_3c = (char *)0x2;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pcStack_3c = (char *)0xffffffff;

  param_1[0x1a5] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,puVar5,uVar6,pvVar1);

  (**(code **)(*(int *)param_1[0x1a5] + 0x28))("i_d_obj_exp_wnd_distance.xml");

  (**(code **)(*(int *)param_1[0x1a5] + 0xfc))(1,0x3f000000);

  uVar6 = 0;

  (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  uVar4 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4fc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078caf0(pvVar1,0,1);

  }

  param_1[0x1a4] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar4,uVar6,pvVar1);

  (**(code **)(*(int *)param_1[0x1a4] + 0x28))("i_d_obj_exp_wnd_arrow.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x1a3] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x1a3] + 0x28))("i_d_obj_exp_wnd_context.xml");

  (**(code **)(*(int *)param_1[0x1a3] + 0xcc))(0);

  uVar6 = DAT_00aaa8e0;

  iVar2 = param_1[0x1a4];

  if (iVar2 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x490) = 0;

    uVar4 = DAT_00a0f698;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x494) = uVar6;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x498) = uVar4;

    FUN_0078be40();

    pvVar1 = (void *)g_flOne;

    iVar2 = param_1[0x1a4];

    *(float *)(iVar2 + 0x4b8) = g_flOne;

    *(void **)(iVar2 + 0x4bc) = pvVar1;

    *(void **)(iVar2 + 0x4c0) = pvVar1;

    *(void **)(iVar2 + 0x4c4) = pvVar1;

  }

  if ((int *)param_1[0x1a4] != (int *)0x0) {

    iVar2 = (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

    if (iVar2 != 0) {

      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

      FUN_0096f840("MatDiffuse",param_1 + 0x1ab);

      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

      FUN_0096f840("MatAmbient",param_1 + 0x1a7);

      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

      FUN_0096f840("MatEmissive",param_1 + 0x1af);

    }

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x450))(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
