// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, FUN_0079c860, FUN_00829ac0, FUN_00829ce0.
//  - Strings: "i_d_npc_2d_btn_mselect_btn_mission.xml"; "i_d_npc_2d_btn_mselect_wnd_status.xml"; "i_d_npc_2d_btn_mselect_wnd_title.xml"; "i_d_npc_2d_btn_mselect_wnd_title_cat.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_npc_2d_btn_mselect_btn_mission_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ce0
// Address:   0x00829ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_npc_2d_btn_mselect_btn_mission.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_i_d_npc_2d_btn_mselect_btn_mission_xml(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *in_stack_ffffffd8;

  char *pcVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b430a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  if ((char)param_1[0x13f] == '\0') {

    pvVar1 = operator_new(0x4cc);

    local_4 = 0;

    iVar2 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_0079c860();

    }

    local_4 = 0xffffffff;

    param_1[0x141] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    pcVar4 = "i_d_npc_2d_btn_mselect_btn_mission.xml";

    (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_npc_2d_btn_mselect_btn_mission.xml");

    (**(code **)(*(int *)param_1[0x141] + 0x74))(60000);

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      in_stack_ffffffd8 = (void *)0x0;

    }

    else {

      in_stack_ffffffd8 = (void *)FUN_007b5dd0(pvVar1,0);

    }

    param_1[0x143] = (int)in_stack_ffffffd8;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_npc_2d_btn_mselect_wnd_status.xml");

    FUN_00829ac0();

    pvVar3 = operator_new(0x488);

    if (pvVar3 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0(pvVar3,0);

    }

    param_1[0x142] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2,in_stack_ffffffd8,pvVar3,pcVar4,pvVar1,0xffffffff);

    pcVar4 = "i_d_npc_2d_btn_mselect_wnd_title.xml";

  }

  else {

    pvVar1 = operator_new(0x488);

    local_4 = 3;

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0(pvVar1,0);

    }

    local_4 = 0xffffffff;

    param_1[0x142] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    pcVar4 = "i_d_npc_2d_btn_mselect_wnd_title_cat.xml";

  }

  (**(code **)(*(int *)param_1[0x142] + 0x28))(pcVar4);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = in_stack_ffffffd8;

  return;

}
