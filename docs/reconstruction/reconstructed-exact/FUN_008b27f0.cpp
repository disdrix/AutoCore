// =============================================================================
// FUN_008b27f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b27f0
// Address:   0x008b27f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b27f0 @ 0x008b27f0
// Stable ID: aa_008b27f0
// Embedded strings (evidence for future rename):
//   - "i_d_map_2d_gauge_bg_large.xml"
//   - "i_d_map_2d_wnd_fx.xml"
//   - "i_d_map_2d_btn_close.xml"
//   - "i_d_map_2d_btn_world_map.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×15, do×1, while×1, return×1.
//  - Notable callees: FUN_0079c860×2, FUN_00792600, FUN_00837d50, FUN_00839d30, FUN_00864f20, FUN_008b27f0, FUN_0097ae30, FUN_0097af80.
//  - Strings: "i_d_map_2d_gauge_bg_large.xml"; "i_d_map_2d_wnd_fx.xml"; "i_d_map_2d_btn_close.xml"; "i_d_map_2d_btn_world_map.xml".
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

void __fastcall FUN_008b27f0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6584;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x56c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00839d30(pvVar1);

  }

  local_4 = 0xffffffff;

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x148] + 0x43c))();

  (**(code **)(*(int *)param_1[0x148] + 0xcc))(0);

  iVar2 = DAT_00d1d888;

  if (param_1[0x148] != 0) {

    FUN_00837d50();

    if (iVar2 == 0) {

      (**(code **)(*(int *)param_1[0x148] + 0xfc))(0,0x3f000000);

    }

    else {

      (**(code **)(*(int *)param_1[0x148] + 0xfc))(1);

    }

  }

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = UI_CooldownGaugeWidget_ctor(pvVar1);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_map_2d_gauge_bg_large.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c43);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x147] = (int)piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  if (param_1[0x146] != 0) {

    (**(code **)(*param_1 + 0xa8))(param_1[0x146]);

    (**(code **)(*(int *)param_1[0x146] + 0x43c))();

    (**(code **)(*(int *)param_1[0x146] + 0x74))(0x9c44);

    (**(code **)(*(int *)param_1[0x146] + 0xfc))(1,0x3f000000);

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

  }

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_00864f20(pvVar1);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_map_2d_wnd_fx.xml");

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_map_2d_btn_close.xml");

  (**(code **)(*piVar3 + 0x74))(40000);

  pvVar4 = (void *)0x1;

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x141] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_map_2d_btn_world_map.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c41);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x144] = (int)piVar3;

  if (param_1[0x14a] != 0) {

    (**(code **)(*param_1 + 0xa8))(param_1[0x14a]);

    (**(code **)(*(int *)param_1[0x14a] + 0xcc))(1);

    FUN_0097ae30();

    iVar2 = param_1[0x14a];

    piVar3 = (int *)**(int **)(iVar2 + 0x548);

    if (piVar3 != *(int **)(iVar2 + 0x548)) {

      do {

        FUN_0097af80(iVar2);

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)*(int *)(iVar2 + 0x548));

    }

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar4;

  return;

}
