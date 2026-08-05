// =============================================================================
// FUN_008c7c60
// -----------------------------------------------------------------------------
// Stable ID: aa_008c7c60
// Address:   0x008c7c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c7c60 @ 0x008c7c60
// Stable ID: aa_008c7c60
// Embedded strings (evidence for future rename):
//   - "i_d_g_2d_gauge_highlight_heat.xml"
//   - "i_d_g_2d_wnd_damage_health_%d.xml"
//   - "i_d_g_2d_wnd_text.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~458 non-empty decompiler lines.
//  - Control keywords: if×54, do×2, while×2, return×1.
//  - Notable callees: FUN_0097ffa0×10, FUN_007b5dd0×7, UI_CooldownGaugeWidget_ctor×3, FUN_004073a0, FUN_00410240, FUN_004b70c0, FUN_004b7e50, FUN_00792600.
//  - Strings: "i_d_g_2d_gauge_highlight_heat.xml"; "i_d_g_2d_wnd_damage_health_%d.xml"; "i_d_g_2d_wnd_text.xml".
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

void __fastcall FUN_008c7c60(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  char acStack_250 [4];

  char *pcStack_24c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6bb7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar3 = operator_new(0x548);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0083d3b0();

  }

  local_4 = 0xffffffff;

  param_1[0x164] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x164] + 0x43c))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  pvStack_c = (void *)0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x171] = (int)piVar5;

  if ((DAT_00d1b6d8 == 0) ||

     (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                        0x3c) + 0x532) != '\0')) {

    pvVar3 = operator_new(0x4f8);

    if (pvVar3 == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_0097ffa0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar5 + 0x28))();

    (**(code **)(*piVar5 + 0xfc))();

    param_1[0x157] = (int)piVar5;

  }

  else {

    pvVar3 = operator_new(0x4f8);

    if (pvVar3 == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_0097ffa0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar5 + 0x28))();

    (**(code **)(*piVar5 + 0xfc))();

    iVar4 = param_1[0x1a] + 1;

    param_1[0x157] = (int)piVar5;

    param_1[0x1a] = iVar4;

    param_1[0x1d] = (int)(float)-iVar4;

    if (param_1[0x1c] < iVar4) {

      param_1[0x1c] = iVar4;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar3 = operator_new(0x4f8);

    if (pvVar3 == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_0097ffa0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar5 + 0x28))();

    (**(code **)(*piVar5 + 0xfc))();

    param_1[0x158] = (int)piVar5;

  }

  *(uint8_t *)(param_1 + 0x147) = 0;

  *(uint8_t *)((int)param_1 + 0x51d) = 0;

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x159] = (int)piVar5;

  pvVar3 = operator_new(0x498);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0098c3f0();

  }

  param_1[0x169] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x169] + 0x28))();

  (**(code **)(*(int *)param_1[0x169] + 0xcc))();

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x160] = (int)piVar5;

  pvVar3 = operator_new(0x4bc);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = UI_CooldownGaugeWidget_ctor(pvVar3);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x15f] = (int)piVar5;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x15d] = (int)piVar5;

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x15e] = (int)piVar5;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x14f] = (int)piVar5;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0();

  }

  param_1[0x151] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x151] + 0x28))();

  (**(code **)(*(int *)param_1[0x151] + 0xfc))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0();

  }

  param_1[0x152] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x152] + 0x28))();

  (**(code **)(*(int *)param_1[0x152] + 0xfc))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x150] = (int)piVar5;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x4bc);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = UI_CooldownGaugeWidget_ctor(pvVar3);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  param_1[0x161] = (int)piVar5;

  pvVar3 = operator_new(0x4bc);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = UI_CooldownGaugeWidget_ctor(pvVar3);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0x3b0))();

  param_1[0x162] = (int)piVar5;

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  param_1[0x163] = (int)piVar5;

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x166] = (int)piVar5;

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0097ffa0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x167] = (int)piVar5;

  pcStack_24c = (char *)0x8c8530;

  pvVar3 = operator_new(0x4f8);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    pcStack_24c = (char *)0x8c854c;

    piVar5 = (int *)FUN_0097ffa0();

  }

  pcStack_24c = (char *)0x8c8564;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_24c = "i_d_g_2d_gauge_highlight_heat.xml";

  acStack_250[0] = 'p';

  acStack_250[1] = -0x7b;

  acStack_250[2] = -0x74;

  acStack_250[3] = '\0';

  (**(code **)(*piVar5 + 0x28))();

  acStack_250[0] = '\0';

  acStack_250[1] = '\0';

  acStack_250[2] = '\0';

  acStack_250[3] = '?';

  (**(code **)(*piVar5 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x168] = (int)piVar5;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x16a] = (int)piVar5;

  iVar4 = 0;

  piVar5 = param_1 + 0x16b;

  do {

    iVar4 = iVar4 + 1;

    sprintf(acStack_250,"i_d_g_2d_wnd_damage_health_%d.xml");

    (**(code **)(*param_1 + 0x404))();

    (**(code **)(*(int *)*piVar5 + 0xcc))();

    piVar5 = piVar5 + 1;

  } while (iVar4 < 3);

  if ((DAT_00d1b6d8 != 0) &&

     (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                        0x3c) + 0x532) == '\0')) {

    (**(code **)(*param_1 + 0x404))();

    (**(code **)(*(int *)param_1[0x16e] + 0xcc))();

  }

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*param_1 + 0x404))();

  pvVar3 = operator_new(0x494);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_00410240();

  }

  param_1[0x153] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_g_2d_wnd_text.xml");

  (**(code **)(*(int *)param_1[0x153] + 0xcc))(1);

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar4 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  if (param_1[0x165] != 0) {

    (**(code **)(*param_1 + 0xa8))(param_1[0x165]);

    FUN_0097ae30();

    iVar4 = param_1[0x165];

    piVar5 = (int *)**(int **)(iVar4 + 0x548);

    if (piVar5 != *(int **)(iVar4 + 0x548)) {

      do {

        pvVar3 = NDSpecialFX_LoadFromScriptName((char *)piVar5[2],-1,0);

        if (pvVar3 != (void *)0x0) {

          FUN_004b70c0(0,0,DAT_00a0f718);

          FUN_004b7e50(0,0,0,0,0,0);

          iVar1 = *(int *)(iVar4 + 0x554);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(iVar4 + 0x55c) - iVar1 >> 2) <=

              (uint)(*(int *)(iVar4 + 0x558) - iVar1 >> 2))) {

            FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x558),1,&stack0xfffffd7c);

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x558);

            *puVar2 = pvVar3;

            *(uint32_t /* width from decompiler */ **)(iVar4 + 0x558) = puVar2 + 1;

          }

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*(int *)(iVar4 + 0x548));

    }

    (**(code **)(*(int *)param_1[0x165] + 0xcc))(1);

  }

  if ((int *)param_1[0x157] != (int *)0x0) {

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x157] + 0x164))(1);

    param_1[0x148] = *piVar5;

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x157] + 0x164))(0);

    param_1[0x149] = *piVar5;

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x157] + 0x164))(2);

    param_1[0x14a] = *piVar5;

    if ((int *)param_1[0x151] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x151] + 0x15c))(0,param_1 + 0x148);

    }

  }

  if ((int *)param_1[0x159] != (int *)0x0) {

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x159] + 0x164))(1);

    param_1[0x14b] = *piVar5;

    if ((int *)param_1[0x152] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x152] + 0x15c))(0,param_1 + 0x14b);

    }

  }

  if ((int *)param_1[0x158] != (int *)0x0) {

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x158] + 0x164))(1);

    param_1[0x14c] = *piVar5;

  }

  if ((int *)param_1[0x15d] != (int *)0x0) {

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x15d] + 0x164))(1);

    param_1[0x14d] = *piVar5;

  }

  if ((int *)param_1[0x15f] != (int *)0x0) {

    piVar5 = (int *)(**(code **)(*(int *)param_1[0x15f] + 0x164))(1);

    param_1[0x14e] = *piVar5;

  }

  if ((int *)param_1[0x14f] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x14f] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x150] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x150] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x154] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x154] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x155] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x155] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x157] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x158] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x158] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x159] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x159] + 0x74))(0x9c42);

  }

  if ((int *)param_1[0x15d] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x15d] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x15f] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x15f] + 0x74))(0x9c41);

  }

  if ((int *)param_1[0x161] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x161] + 0x74))(0x9c41);

  }

  FUN_008c57a0(param_1);

  (**(code **)(*param_1 + 0x458))();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
