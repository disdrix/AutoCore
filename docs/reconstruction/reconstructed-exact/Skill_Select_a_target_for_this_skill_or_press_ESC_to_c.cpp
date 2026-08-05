// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×10, goto×7, switch×1, for×1, return×1.
//  - Notable callees: Client_RefreshOpenMissionUiWindows, FUN_007a69d0, FUN_007a6de0, FUN_007f9cc0, FUN_007f9df0, FUN_008f8200, FUN_0093bac0.
//  - Strings: "Select a target for this skill, or press ESC to cancel.".
//  - Return sites: 1.

// =============================================================================
// Skill_Select_a_target_for_this_skill_or_press_ESC_to_c
// -----------------------------------------------------------------------------
// Stable ID: aa_0093bac0
// Address:   0x0093bac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Select a target for this skill, or press ESC to cancel."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_Select_a_target_for_this_skill_or_press_ESC_to_c(int param_1,char param_2)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t local_8;

  uint8_t local_7;

  uint8_t local_6;

  uint8_t local_5;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(param_1 + 0x30c0);

  bVar3 = false;

  if ((in_EAX != iVar1) &&

     (((((iVar1 == 5 || (iVar1 == 4)) || (iVar1 == 0)) || ((in_EAX == 5 || (in_EAX == 4)))) ||

      (in_EAX == 0)))) {

    bVar3 = true;

  }

  FUN_007a69d0();

  *(char *)(param_1 + 0x30c4) = param_2;

  local_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30c4);

  *(int *)(param_1 + 0x30c0) = in_EAX;

  switch(in_EAX) {

  case 0:

    iVar1 = *(int *)(param_1 + 0x1168);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4e8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4ec) = 10;

    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0c0) goto LAB_0093bc9d;

    break;

  default:

    piVar2 = *(int **)(param_1 + 0x1168);

    if (*(char *)((int)piVar2 + 0x489) == '\0') {

      local_6 = 0xff;

      local_5 = 0xff;

      local_7 = 0;

      local_8 = 0;

      (**(code **)(*piVar2 + 0x15c))(0,&local_8);

      (**(code **)(*piVar2 + 0x34c))();

    }

    piVar2[0x13a] = 0;

    piVar2[0x13b] = 5;

    if (piVar2[0x13c] == DAT_00afa0ac) goto LAB_0093bc9d;

    break;

  case 2:

    iVar1 = *(int *)(param_1 + 0x1168);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4e8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4ec) = 6;

    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b0) goto LAB_0093bc9d;

    break;

  case 3:

    iVar1 = *(int *)(param_1 + 0x1168);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4e8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4ec) = 7;

    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b4) goto LAB_0093bc9d;

    break;

  case 4:

    iVar1 = *(int *)(param_1 + 0x1168);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4e8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4ec) = 8;

    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b8) goto LAB_0093bc9d;

    break;

  case 5:

    iVar1 = *(int *)(param_1 + 0x1168);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4e8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4ec) = 9;

    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0bc) goto LAB_0093bc9d;

    break;

  case -1:

    FUN_007f9df0();

    goto LAB_0093bc9d;

  }

  FUN_007f9cc0();

LAB_0093bc9d:

  if ((param_2 != '\0') && (*(int *)(param_1 + 0x109c) != 0)) {

    uVar5 = 0;

    uVar4 = FUN_007a6de0("Select a target for this skill, or press ESC to cancel.",0xffffffff);

    FUN_008f8200(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),6,&DAT_00a156cc,uVar4,uVar5);

  }

  if (bVar3) {

    Client_RefreshOpenMissionUiWindows(param_1);

  }

  return;

}
