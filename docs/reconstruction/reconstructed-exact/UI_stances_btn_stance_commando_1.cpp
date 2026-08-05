// =============================================================================
// UI_stances_btn_stance_commando_1
// -----------------------------------------------------------------------------
// Stable ID: aa_00892ed0
// Address:   0x00892ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_stances_btn_stance_commando_1 @ 0x00892ed0
// Stable ID: aa_00892ed0
// Embedded strings (evidence for future rename):
//   - "i_d_stances_2d_wnd_frame.xml"
//   - "i_d_stances_2d_btn_stance_commando_1.xml"
//   - "i_d_stances_2d_btn_stance_commando_2.xml"
//   - "i_d_stances_2d_btn_stance_commando_3.xml"
//   - "i_d_stances_2d_btn_stance_engineer_1.xml"
//   - "i_d_stances_2d_btn_stance_engineer_2.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, switch×1, goto×1, return×1.
//  - Notable callees: UI_CooldownGaugeWidget_ctor×3, FUN_00792600, UI_stances_btn_stance_commando_1.
//  - Strings: "i_d_stances_2d_wnd_frame.xml"; "i_d_stances_2d_btn_stance_commando_1.xml"; "i_d_stances_2d_btn_stance_commando_2.xml"; "i_d_stances_2d_btn_stance_commando_3.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_stances_2d_btn_stance_commando_1.xml"
 * Domain alias of FUN_00892ed0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_stances_btn_stance_commando_1(int *param_1)



{

  void *pvVar1;

  void *pvVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int *piVar6;

  char *pcVar7;

  char *pcVar8;

  int *piVar9;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b5bef;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  piVar9 = param_1 + 0x14b;

  (**(code **)(*param_1 + 0x404))(piVar9,"i_d_stances_2d_wnd_frame.xml",0xffffffff);

  if (DAT_00d1b6d8 != 0) {

    switch(*(uint8_t *)

            (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                     0x3c) + 0x531)) {

    case 0:

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14c,"i_d_stances_2d_btn_stance_commando_1.xml",0x9c41,0x9c42);

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14d,"i_d_stances_2d_btn_stance_commando_2.xml",0x9c41,0x9c43);

      pcVar8 = "i_d_stances_2d_btn_stance_commando_3.xml";

      break;

    case 1:

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14c,"i_d_stances_2d_btn_stance_engineer_1.xml",0x9c41,0x9c42);

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14d,"i_d_stances_2d_btn_stance_engineer_2.xml",0x9c41,0x9c43);

      pcVar8 = "i_d_stances_2d_btn_stance_engineer_3.xml";

      break;

    case 2:

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14c,"i_d_stances_2d_btn_stance_officer_1.xml",0x9c41,0x9c42);

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14d,"i_d_stances_2d_btn_stance_officer_2.xml",0x9c41,0x9c43);

      pcVar8 = "i_d_stances_2d_btn_stance_officer_3.xml";

      break;

    case 3:

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14c,"i_d_stances_2d_btn_stance_ranger_1.xml",0x9c41,0x9c42);

      (**(code **)(*param_1 + 0x40c))

                (param_1 + 0x14d,"i_d_stances_2d_btn_stance_ranger_2.xml",0x9c41,0x9c43);

      pcVar8 = "i_d_stances_2d_btn_stance_ranger_3.xml";

      break;

    default:

      goto LAB_00893093;

    }

    (**(code **)(*param_1 + 0x40c))(param_1 + 0x14e,pcVar8,0x9c41,0x9c44);

  }

LAB_00893093:

  piVar6 = param_1 + 0x14c;

  iVar5 = 3;

  do {

    if (*piVar6 != 0) {

      (**(code **)(*(int *)*piVar6 + 0x3b4))(1);

    }

    piVar6 = piVar6 + 1;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else {

    pvVar2 = UI_CooldownGaugeWidget_ctor(pvVar1);

  }

  param_1[0x152] = (int)pvVar2;

  (**(code **)(*param_1 + 0xa8))(pvVar2,piVar9,pvVar1);

  pcVar8 = "i_d_stances_2d_wnd_gauge_cooldown_1.xml";

  (**(code **)(*(int *)param_1[0x152] + 0x28))("i_d_stances_2d_wnd_gauge_cooldown_1.xml");

  pvVar2 = operator_new(0x4bc);

  if (pvVar2 == (void *)0x0) {

    pvVar3 = (void *)0x0;

  }

  else {

    pvVar3 = UI_CooldownGaugeWidget_ctor(pvVar2);

  }

  param_1[0x153] = (int)pvVar3;

  (**(code **)(*param_1 + 0xa8))(pvVar3,pcVar8,pvVar2,piVar9,pvVar1,0xffffffff);

  pcVar7 = "i_d_stances_2d_wnd_gauge_cooldown_2.xml";

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_stances_2d_wnd_gauge_cooldown_2.xml");

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    pvVar3 = (void *)0x0;

  }

  else {

    pvVar3 = UI_CooldownGaugeWidget_ctor(pvVar1);

  }

  param_1[0x154] = (int)pvVar3;

  (**(code **)(*param_1 + 0xa8))(pvVar3,pcVar7,pvVar1,pcVar8,pvVar2,0xffffffff);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_stances_2d_wnd_gauge_cooldown_3.xml");

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14f,"i_d_stances_2d_wnd_glow_1.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x150,"i_d_stances_2d_wnd_glow_2.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x151,"i_d_stances_2d_wnd_glow_3.xml");

  if (DAT_00d1b6d8 != 0) {

    iVar5 = 0xd58;

    do {

      if ((iVar5 < 0xd55) || (0xd63 < iVar5)) {

        uVar4 = 0xffffffff;

      }

      else {

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + DAT_00d1b6d8);

      }

      *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar5 + -0x83c) = uVar4;

      iVar5 = iVar5 + 4;

    } while (iVar5 < 0xd64);

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0xffffffff;

  return;

}
