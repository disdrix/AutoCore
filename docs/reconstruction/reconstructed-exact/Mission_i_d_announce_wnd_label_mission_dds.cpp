// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×13, goto×7, return×4, switch×1.
//  - Notable callees: __RTDynamicCast×6, CONCAT31×4, FUN_0090b970, FUN_0090b9c0.
//  - Strings: "i_d_announce_wnd_label_mission.dds"; "i_d_announce_wnd_label_level.dds"; "i_d_announce_wnd_label_item.dds"; "i_d_announce_wnd_label_medal.dds".
//  - Return sites: 4.

// =============================================================================
// Mission_i_d_announce_wnd_label_mission_dds
// -----------------------------------------------------------------------------
// Stable ID: aa_0090b9c0
// Address:   0x0090b9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_announce_wnd_label_mission.dds"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_i_d_announce_wnd_label_mission_dds(int *param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  uint8_t *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int unaff_ESI;

  int iStack_48;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [32];

  

  if (in_EAX < 0) {

    return;

  }

  if (4 < in_EAX) {

    return;

  }

  if (DAT_00d1a8dd != '\0') {

    return;

  }

  param_1[0x150] = in_EAX;

  (**(code **)(*param_1 + 4))(1);

  iVar5 = (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * DAT_00a0f298);

  iVar6 = (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * DAT_00a0f704);

  switch(param_1[0x150]) {

  case 0:

    piVar4 = (int *)param_1[0x13f];

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 0x50))

                ("i_d_announce_wnd_label_mission.dds",

                 CONCAT31((int3)((uint)piVar4[0x86] >> 8),*(uint8_t *)((int)piVar4 + 0xcf)),

                 piVar4[0x86]);

    }

    if (((DAT_00d1b8c8 == (int *)0x0) ||

        (cVar1 = (**(code **)(*DAT_00d1b8c8 + 0x3d8))(), cVar1 == '\0')) ||

       (iVar2 = __RTDynamicCast(DAT_00d1b8c8,0,&CVOGDialog::RTTI_Type_Descriptor,

                                &CDlgObjective::RTTI_Type_Descriptor,0),

       *(int *)(iVar2 + 0x670) == 0)) goto switchD_0090ba34_default;

    (**(code **)(**(int **)(iVar2 + 0x670) + 0x120))(&stack0xffffffb4,1,1);

    (**(code **)(**(int **)(iVar2 + 0x670) + 0x140))(&stack0xffffffb0,1);

    piVar4 = *(int **)(iVar2 + 0x670);

    puVar3 = &stack0xffffffb0;

    break;

  case 1:

    piVar4 = (int *)param_1[0x13f];

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 0x50))

                ("i_d_announce_wnd_label_level.dds",

                 CONCAT31((int3)((uint)piVar4[0x86] >> 8),*(uint8_t *)((int)piVar4 + 0xcf)),

                 piVar4[0x86]);

    }

    if (((DAT_00d1b8ec == (int *)0x0) ||

        (cVar1 = (**(code **)(*DAT_00d1b8ec + 0x3d8))(), cVar1 == '\0')) ||

       (iVar2 = __RTDynamicCast(DAT_00d1b8ec,0,&CVOGDialog::RTTI_Type_Descriptor,

                                &CDlgGauges::RTTI_Type_Descriptor,0), *(int *)(iVar2 + 0x540) == 0))

    goto switchD_0090ba34_default;

    (**(code **)(**(int **)(iVar2 + 0x540) + 0x120))(&stack0xffffffb4,1,1);

    (**(code **)(**(int **)(iVar2 + 0x540) + 0x140))(auStack_40,1);

    piVar4 = *(int **)(iVar2 + 0x540);

    puVar3 = auStack_40;

    break;

  case 2:

    piVar4 = (int *)param_1[0x13f];

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 0x50))

                ("i_d_announce_wnd_label_item.dds",

                 CONCAT31((int3)((uint)piVar4[0x86] >> 8),*(uint8_t *)((int)piVar4 + 0xcf)),

                 piVar4[0x86]);

    }

    if ((DAT_00d1b8f0 == (int *)0x0) ||

       (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 == '\0'))

    goto switchD_0090ba34_default;

    iVar2 = __RTDynamicCast(DAT_00d1b8f0,0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgQuickBar::RTTI_Type_Descriptor,0);

    if ((*(int *)(iVar2 + 0x664) == 0) ||

       (iVar2 = __RTDynamicCast(*(int *)(iVar2 + 0x664),0,&CVOGMenu::RTTI_Type_Descriptor,

                                &CMenuQuickBar::RTTI_Type_Descriptor,0),

       *(int *)(iVar2 + 0x568) == 0)) goto switchD_0090ba34_default;

    (**(code **)(**(int **)(iVar2 + 0x568) + 0x120))(&stack0xffffffb4,1,1);

    (**(code **)(**(int **)(iVar2 + 0x568) + 0x140))(auStack_30,1);

    piVar4 = *(int **)(iVar2 + 0x568);

    puVar3 = auStack_30;

    break;

  case 3:

    piVar4 = (int *)param_1[0x13f];

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 0x50))

                ("i_d_announce_wnd_label_medal.dds",

                 CONCAT31((int3)((uint)piVar4[0x86] >> 8),*(uint8_t *)((int)piVar4 + 0xcf)),

                 piVar4[0x86]);

    }

    if ((DAT_00d1b8f0 == (int *)0x0) ||

       (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 == '\0'))

    goto switchD_0090ba34_default;

    iVar2 = __RTDynamicCast(DAT_00d1b8f0,0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgQuickBar::RTTI_Type_Descriptor,0);

    if ((*(int *)(iVar2 + 0x664) == 0) ||

       (iVar2 = __RTDynamicCast(*(int *)(iVar2 + 0x664),0,&CVOGMenu::RTTI_Type_Descriptor,

                                &CMenuQuickBar::RTTI_Type_Descriptor,0),

       *(int *)(iVar2 + 0x54c) == 0)) goto switchD_0090ba34_default;

    (**(code **)(**(int **)(iVar2 + 0x54c) + 0x120))(&stack0xffffffb4,1,1);

    (**(code **)(**(int **)(iVar2 + 0x54c) + 0x140))(auStack_20,1);

    piVar4 = *(int **)(iVar2 + 0x54c);

    puVar3 = auStack_20;

    break;

  default:

    goto switchD_0090ba34_default;

  }

  iVar5 = (**(code **)(*piVar4 + 0x140))(puVar3,1);

  iVar6 = *(int *)(iVar5 + 4) / 2 + iStack_48;

  iVar5 = unaff_ESI;

switchD_0090ba34_default:

  FUN_0090b970(iVar5,iVar6);

  return;

}
