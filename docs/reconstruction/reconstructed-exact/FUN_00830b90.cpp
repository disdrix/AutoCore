// =============================================================================
// FUN_00830b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00830b90
// Address:   0x00830b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00830b90 @ 0x00830b90
// Stable ID: aa_00830b90
// Embedded strings (evidence for future rename):
//   - "i_m_con_2d_btn_invite.xml"
//   - "i_m_con_2d_btn_kick.xml"
//   - "i_m_con_2d_btn_leave.xml"
//   - "i_m_con_2d_btn_loot.xml"
//   - "i_m_con_2d_btn_loot_killer.xml"
//   - "i_m_con_2d_btn_loot_distributed.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×17, return×5.
//  - Notable callees: FUN_00574880, FUN_0082d2b0, FUN_00830b90.
//  - Strings: "i_m_con_2d_btn_invite.xml"; "i_m_con_2d_btn_kick.xml"; "i_m_con_2d_btn_leave.xml"; "i_m_con_2d_btn_loot.xml".
//  - Return sites: 5.

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

void __fastcall FUN_00830b90(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  char **ppcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iStack_9c;

  uint32_t /* width from decompiler */ *puStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  char *pcStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  char *pcStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  char *pcStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  char *pcStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  char *pcStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  char *pcStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  

  if (param_1[0x130] != 0) {

    uStack_34 = 0x830baf;

    FUN_0082d2b0();

    uStack_34 = 0xffffffff;

    uStack_38 = 0x11171;

    uStack_3c = 0;

    pcStack_40 = "i_m_con_2d_btn_invite.xml";

    uStack_44 = 0x830bc7;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    uStack_44 = 0xffffffff;

    uStack_48 = 0x11172;

    uStack_4c = 0;

    pcStack_50 = "i_m_con_2d_btn_kick.xml";

    param_1[0x14f] = iVar2;

    uStack_54 = 0x830be5;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    uStack_54 = 0xffffffff;

    uStack_58 = 0x11173;

    uStack_5c = 0;

    param_1[0x150] = iVar2;

    pcStack_60 = "i_m_con_2d_btn_leave.xml";

    uStack_64 = 0x830c03;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    uStack_64 = 0xffffffff;

    uStack_68 = 0x11174;

    uStack_6c = 0;

    pcStack_70 = "i_m_con_2d_btn_loot.xml";

    param_1[0x151] = iVar2;

    uStack_74 = 0x830c21;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    uStack_74 = 0x11174;

    uStack_78 = 0x11175;

    uStack_7c = 1;

    param_1[0x152] = iVar2;

    pcStack_80 = "i_m_con_2d_btn_loot_killer.xml";

    uStack_84 = 0x830c42;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    uStack_84 = 0x11174;

    uStack_88 = 0x11176;

    uStack_8c = 1;

    pcStack_90 = "i_m_con_2d_btn_loot_distributed.xml";

    param_1[0x154] = iVar2;

    uStack_94 = 0x830c63;

    iVar2 = (**(code **)(*param_1 + 0x444))();

    param_1[0x153] = iVar2;

    if ((int *)param_1[0x152] != (int *)0x0) {

      uStack_94 = 1;

      puStack_98 = (uint32_t /* width from decompiler */ *)0x830c7d;

      (**(code **)(*(int *)param_1[0x152] + 0x3b4))();

    }

    if ((int *)param_1[0x154] != (int *)0x0) {

      uStack_94 = 1;

      puStack_98 = (uint32_t /* width from decompiler */ *)0x830c91;

      (**(code **)(*(int *)param_1[0x154] + 0x3b4))();

    }

    if ((int *)param_1[0x153] != (int *)0x0) {

      uStack_94 = 1;

      puStack_98 = (uint32_t /* width from decompiler */ *)0x830ca5;

      (**(code **)(*(int *)param_1[0x153] + 0x3b4))();

    }

    uStack_94 = 1;

    puStack_98 = &uStack_88;

    iStack_9c = 0x830cbc;

    (**(code **)(*(int *)*DAT_00d1b780 + 0x140))();

    if ((int *)param_1[0x14f] != (int *)0x0) {

      iStack_9c = 0;

      piVar3 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x120))(&uStack_88,1);

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x140))(&uStack_8c,1);

      if ((int)pcStack_90 < *piVar3 + *piVar4) {

        iStack_9c = 0;

        ppcVar5 = &pcStack_80;

        iVar2 = (**(code **)(*(int *)param_1[0x14f] + 0x120))(ppcVar5,1);

        puVar6 = *(uint32_t /* width from decompiler */ **)(iVar2 + 4);

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x140))(&uStack_84,1);

        iStack_9c = (int)ppcVar5 - *piVar3;

        puStack_98 = puVar6;

        (**(code **)(*(int *)param_1[0x14f] + 0x110))(&iStack_9c);

      }

    }

    if ((int *)param_1[0x150] != (int *)0x0) {

      iStack_9c = 0;

      piVar3 = (int *)(**(code **)(*(int *)param_1[0x150] + 0x120))(&uStack_78,1);

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x150] + 0x140))(&uStack_8c,1);

      if ((int)pcStack_90 < *piVar3 + *piVar4) {

        iStack_9c = 0;

        puVar6 = &uStack_78;

        iVar2 = (**(code **)(*(int *)param_1[0x150] + 0x120))(puVar6,1);

        puVar1 = *(uint32_t /* width from decompiler */ **)(iVar2 + 4);

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x150] + 0x140))(&uStack_8c,1);

        iStack_9c = (int)puVar6 - *piVar3;

        puStack_98 = puVar1;

        (**(code **)(*(int *)param_1[0x150] + 0x110))(&iStack_9c);

      }

    }

    if ((int *)param_1[0x151] != (int *)0x0) {

      iStack_9c = 0;

      piVar3 = (int *)(**(code **)(*(int *)param_1[0x151] + 0x120))(&uStack_78,1);

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x151] + 0x140))(&uStack_8c,1);

      if ((int)pcStack_90 < *piVar3 + *piVar4) {

        iStack_9c = 0;

        puVar6 = &uStack_78;

        iVar2 = (**(code **)(*(int *)param_1[0x151] + 0x120))(puVar6,1);

        puVar1 = *(uint32_t /* width from decompiler */ **)(iVar2 + 4);

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x151] + 0x140))(&uStack_8c,1);

        iStack_9c = (int)puVar6 - *piVar3;

        puStack_98 = puVar1;

        (**(code **)(*(int *)param_1[0x151] + 0x110))(&iStack_9c);

      }

    }

    if ((int *)param_1[0x152] != (int *)0x0) {

      iStack_9c = 0;

      piVar3 = (int *)(**(code **)(*(int *)param_1[0x152] + 0x120))(&uStack_78,1);

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x152] + 0x140))(&uStack_8c,1);

      if ((int)pcStack_90 < *piVar3 + *piVar4) {

        iStack_9c = 0;

        puVar6 = &uStack_78;

        iVar2 = (**(code **)(*(int *)param_1[0x152] + 0x120))(puVar6,1);

        puVar1 = *(uint32_t /* width from decompiler */ **)(iVar2 + 4);

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x152] + 0x140))(&uStack_8c,1);

        iStack_9c = (int)puVar6 - *piVar3;

        puStack_98 = puVar1;

        (**(code **)(*(int *)param_1[0x152] + 0x110))(&iStack_9c);

      }

    }

    if (DAT_00d1b6d8 != 0) {

      if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf6)

          != '\0') {

        iStack_9c = 0;

        (**(code **)(*(int *)param_1[0x14f] + 0xd4))();

        (**(code **)(*(int *)param_1[0x150] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x151] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x152] + 0xd4))(0);

        return;

      }

      iStack_9c = *(int *)(DAT_00d1b6d8 + 0xcb0);

      if (iStack_9c == 0) {

        (**(code **)(*(int *)param_1[0x150] + 0xd4))();

        (**(code **)(*(int *)param_1[0x151] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x152] + 0xd4))(0);

        return;

      }

      iStack_9c = 0x830fab;

      iVar2 = FUN_00574880();

      if (iVar2 != DAT_00d1b6d8) {

        iStack_9c = 0;

        (**(code **)(*(int *)param_1[0x14f] + 0xd4))();

        (**(code **)(*(int *)param_1[0x150] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x152] + 0xd4))(0);

        return;

      }

      iStack_9c = 1;

      if (*(int *)(*(int *)(DAT_00d1b6d8 + 0xcb0) + 400) == 0) {

        (**(code **)(*(int *)param_1[0x154] + 0x3c8))();

        return;

      }

      (**(code **)(*(int *)param_1[0x153] + 0x3c8))(1);

    }

  }

  return;

}
