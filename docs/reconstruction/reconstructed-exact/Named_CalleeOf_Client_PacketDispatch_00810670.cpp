// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00810670
// -----------------------------------------------------------------------------
// Stable ID: aa_00810670
// Callee of Client_PacketDispatch
// Address:   0x00810670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Unable to sell item!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Unable to sell item!"
//   - "This item is no longer available!"
//   - "loot_credits"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: if×20, return×13, goto×3.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×4, FUN_00571d80×3, CONCAT31, Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, FUN_00513e70, FUN_005710c0, FUN_00571b60.
//  - Strings: "Unable to sell item!"; "This item is no longer available!"; "loot_credits".
//  - Return sites: 13.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_PacketDispatch_00810670(int param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar1 = param_1;

  *(uint8_t *)(param_1 + 0xb6) = 0;

  FUN_007a69d0();

  if (*(char *)(in_EAX + 0x28) == '\0') {

    uVar13 = 0;

    uVar12 = 1;

    uVar10 = 0xffffffff;

    if (*(char *)(in_EAX + 0x29) == '\0') {

      pcVar7 = "Unable to sell item!";

    }

    else {

      pcVar7 = "This item is no longer available!";

    }

    uVar3 = FUN_007a6de0(pcVar7,0xffffffff);

    FUN_007fdfb0(iVar1,uVar3,uVar10,uVar12,uVar13);

    return;

  }

  cVar2 = (**(code **)(**(int **)(iVar1 + 0x1060) + 0x3d8))();

  if (((cVar2 == '\0') || (*(int *)(*(int *)(iVar1 + 0x1060) + 0x5a0) == 0)) &&

     (*(int *)(*(int *)(iVar1 + 0x105c) + 0x588) == 0)) {

    return;

  }

  uVar11 = 0;

  uVar9 = 0x1e;

  uVar8 = 0;

  uVar3 = 0;

  uVar13 = 0xffffffff;

  uVar12 = 0xffffffff;

  uVar10 = 0;

  pcVar7 = "loot_credits";

  Client_GetMissionCompleteAudioTable("loot_credits",0,0xffffffff,0xffffffff,0,0,0x1e,0);

  Client_PlayNamedInterfaceSound(pcVar7,uVar10,uVar12,uVar13,uVar3,uVar8,uVar9,uVar11);

  if (*(char *)(in_EAX + 0x29) == '\0') {

    iVar4 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

    if (iVar4 == 0) {

      return;

    }

    cVar2 = FUN_00587970(*(uint32_t /* width from decompiler */ *)(iVar1 + 0xe98),iVar4);

    if (cVar2 == '\0') {

      return;

    }

    *(int *)(*(int *)(iVar1 + 0xe98) + 0x650) = iVar4;

    cVar2 = (**(code **)(**(int **)(iVar1 + 0x105c) + 0x3d8))();

    if (((cVar2 != '\0') && (*(int *)(iVar1 + 0x105c) != 0)) &&

       (*(int *)(*(int *)(iVar1 + 0x105c) + 0x5ac) != 0)) {

      FUN_0085e890();

    }

    iVar4 = *(int *)(iVar1 + 0xe98);

    uVar10 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x720) = uVar10;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x724) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24);

    iVar4 = *(int *)(*(int *)(iVar1 + 0xe98) + 0x250);

    if (iVar4 == 0) {

      return;

    }

    if (*(int *)(iVar4 + 0x2b0) == 0) {

      return;

    }

    iVar4 = FUN_00571d80(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),

                         CONCAT31((int3)((uint)uVar10 >> 8),*(int *)(in_EAX + 0x2c) != 0));

    if (iVar4 != 0) {

      FUN_007fee30();

      Client_RefreshOpenMissionUiWindows(iVar1);

      return;

    }

    iVar4 = FUN_00571d80(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),

                         *(int *)(in_EAX + 0x2c) != 0);

    if (iVar4 != 0) goto LAB_00810a6a;

  }

  else {

    iVar4 = *(int *)(iVar1 + 0xe98);

    iVar6 = *(int *)(*(int *)(iVar4 + 4) + 4);

    if ((*(int *)(in_EAX + 0x10) != *(int *)(iVar6 + 0x164 + iVar4)) ||

       (*(int *)(in_EAX + 0x14) != *(int *)(iVar6 + 0x168 + iVar4))) {

      cVar2 = (**(code **)(**(int **)(iVar1 + 0x105c) + 0x3d8))();

      if ((cVar2 == '\0') &&

         (cVar2 = (**(code **)(**(int **)(iVar1 + 0x1060) + 0x3d8))(), cVar2 == '\0')) {

        return;

      }

      piVar5 = (int *)CVOGReaction_ResolveObjectTarget

                                (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x18),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c));

      if (piVar5 == (int *)0x0) {

        return;

      }

      iVar4 = (**(code **)(*piVar5 + 0x25c))();

      if (1 < iVar4) {

        iVar4 = *piVar5;

        iVar6 = (**(code **)(iVar4 + 0x25c))();

        (**(code **)(iVar4 + 0x260))(iVar6 + -1);

        Client_RefreshOpenMissionUiWindows(iVar1);

        return;

      }

      FUN_00571d80(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x18),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c),0);

      piVar5 = *(int **)(iVar1 + 0x105c);

      if (((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x3d8))(), cVar2 != '\0')) &&

         (piVar5[0x16b] != 0)) {

        FUN_0085fd20();

        Client_RefreshOpenMissionUiWindows(iVar1);

        return;

      }

      goto LAB_00810a6a;

    }

    iVar4 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x18),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c));

    uStack_8 = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

    uStack_4 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

    cVar2 = FUN_00587c00(*(uint32_t /* width from decompiler */ *)(iVar1 + 0xe98),iVar4,&param_1,&uStack_8,

                         *(uint32_t /* width from decompiler */ *)(in_EAX + 0x2c));

    if (cVar2 == '\0') {

      return;

    }

    iVar6 = *(int *)(iVar1 + 0xe98);

    *(uint32_t /* width from decompiler */ *)(iVar6 + 0x720) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20);

    *(uint32_t /* width from decompiler */ *)(iVar6 + 0x724) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24);

    cVar2 = (**(code **)(**(int **)(iVar1 + 0x105c) + 0x3d8))();

    if (((cVar2 != '\0') &&

        ((cVar2 = FUN_00513e70(), cVar2 != '\0' || ((*(uint *)(iVar4 + 0x17c) >> 0xf & 1) != 0))))

       && ((*(uint *)(iVar4 + 0x17c) >> 0xf & 1) == 0)) {

      piVar5 = (int *)FUN_005710c0(*(uint32_t /* width from decompiler */ *)(in_EAX + 4),0,0);

      if ((piVar5 != (int *)0x0) && (iVar4 = (**(code **)(*piVar5 + 0x25c))(), iVar4 < 1)) {

        FUN_0085fcc0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

      }

      FUN_0088f790();

    }

    iVar4 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

    if ((iVar4 == 0) || (cVar2 = FUN_00571b60(iVar4), cVar2 == '\0')) goto LAB_00810a6a;

  }

  FUN_007fc150();

LAB_00810a6a:

  Client_RefreshOpenMissionUiWindows(iVar1);

  return;

}
