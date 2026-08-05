// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×24, goto×6, return×5.
//  - Notable callees: CONCAT31×6, FUN_005714e0×4, FUN_00571620×3, FUN_0040abf0×2, FUN_004ce5c0×2, FUN_00513e70×2, FUN_005715d0×2, FUN_00571830×2.
//  - Strings: "This equipment cannot be changed at this time."; "VOG_DEBUG_STOP".
//  - Return sites: 5.

// =============================================================================
// Inv_This_equipment_cannot_be_changed_at_this_time_008012f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008012f0
// Address:   0x008012f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "This equipment cannot be changed at this time."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */



void Inv_This_equipment_cannot_be_changed_at_this_time_008012f0(void)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  uint8_t uVar4;

  void *in_EAX;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  byte bVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  int local_24 [3];

  int local_18;

  int local_14;

  uint8_t local_10;

  uint8_t local_8;

  uint8_t local_7;

  byte local_6;

  

  iVar5 = *(int *)((int)in_EAX + 0xe98);

  bVar8 = 0;

  if (iVar5 == 0) {

    return;

  }

  local_2c = CONCAT31(local_2c._1_3_,0xff);

  local_28 = CONCAT31(local_28._1_3_,0xff);

  piVar1 = *(int **)(iVar5 + 0xcd0);

  iVar9 = 0;

  if (piVar1 == (int *)0x0) {

    return;

  }

  iVar2 = *(int *)(*(int *)((int)in_EAX + 0x9b8) + 0x494);

  if (iVar2 == 1) {

    iVar9 = *(int *)(*(int *)(iVar5 + 0x250) + 0x2b0);

    if (iVar9 != 0) {

      uVar4 = (**(code **)(*piVar1 + 0x250))();

      local_2c = CONCAT31(local_2c._1_3_,uVar4);

      uVar4 = (**(code **)(*piVar1 + 0x254))();

      local_28 = CONCAT31(local_28._1_3_,uVar4);

      cVar3 = FUN_005715d0(piVar1,local_2c,local_28,0);

      if ((cVar3 != '\0') ||

         (cVar3 = FUN_005714e0(piVar1,&local_2c,&local_28,1,0xffffffff), cVar3 != '\0')) {

        cVar3 = FUN_00513e70();

        if ((cVar3 == '\0') ||

           ((iVar5 = FUN_005719c0(local_2c,local_28), iVar5 == 0 ||

            (*(int *)(*(int *)(iVar5 + 0xa8) + 0x34) != *(int *)(piVar1[0x2a] + 0x34))))) {

LAB_008015cf:

          uVar6 = (**(code **)(*piVar1 + 0x25c))();

          cVar3 = FUN_00571620(piVar1,local_2c,local_28,uVar6);

          if (cVar3 == '\0') goto LAB_008015f0;

        }

        else {

          uVar6 = (**(code **)(*piVar1 + 0x25c))();

          cVar3 = FUN_0040abf0(uVar6);

          if (cVar3 == '\0') goto LAB_008015cf;

          uVar6 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x160);

          uVar10 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x164);

          uVar7 = (**(code **)(*piVar1 + 0x25c))(uVar6,uVar10);

          FUN_00571830(uVar7,uVar6,uVar10);

        }

        local_6 = 1;

        goto LAB_008016f8;

      }

    }

  }

  else if (iVar2 == 2) {

    local_24[0] = 0;

    iVar5 = FUN_004fabc0(piVar1,local_24);

    if ((iVar5 == 0) && (local_24[0] == 0)) {

      local_24[0] = FUN_00502e90(piVar1);

      if (*(int *)((int)in_EAX + 0x1078) != 0) {

        FUN_008801b0(*(int *)((int)in_EAX + 0x1078));

      }

      local_6 = 2;

      if (*(int *)((int)in_EAX + 0x104c) != 0) {

        FUN_008801b0(*(int *)((int)in_EAX + 0x104c));

      }

      goto LAB_008016f8;

    }

  }

  else if (((iVar2 == 3) && (cVar3 = FUN_004ce5c0(iVar5), cVar3 != '\0')) &&

          (iVar9 = *(int *)(*(int *)((int)in_EAX + 0xe98) + 0xcbc), iVar9 != 0)) {

    uVar4 = (**(code **)(*piVar1 + 0x250))();

    local_2c = CONCAT31(local_2c._1_3_,uVar4);

    uVar4 = (**(code **)(*piVar1 + 0x254))();

    local_28 = CONCAT31(local_28._1_3_,uVar4);

    cVar3 = FUN_005715d0(piVar1,local_2c,local_28,0);

    if ((cVar3 != '\0') ||

       (cVar3 = FUN_005714e0(piVar1,&local_2c,&local_28,1,0xffffffff), cVar3 != '\0')) {

      cVar3 = FUN_00513e70();

      if ((cVar3 == '\0') ||

         ((iVar5 = FUN_005719c0(local_2c,local_28), iVar5 == 0 ||

          (*(int *)(*(int *)(iVar5 + 0xa8) + 0x34) != *(int *)(piVar1[0x2a] + 0x34))))) {

LAB_00801439:

        uVar6 = (**(code **)(*piVar1 + 0x25c))();

        cVar3 = FUN_00571620(piVar1,local_2c,local_28,uVar6);

        if (cVar3 == '\0') {

          FUN_007a69d0();

          uVar11 = 0;

          uVar7 = 1;

          uVar10 = 0xffffffff;

          uVar6 = FUN_007a6de0("This equipment cannot be changed at this time.",0xffffffff);

          FUN_007fdfb0(in_EAX,uVar6,uVar10,uVar7,uVar11);

          return;

        }

      }

      else {

        uVar6 = (**(code **)(*piVar1 + 0x25c))();

        cVar3 = FUN_0040abf0(uVar6);

        if (cVar3 == '\0') goto LAB_00801439;

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x160);

        uVar10 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x164);

        uVar7 = (**(code **)(*piVar1 + 0x25c))(uVar6,uVar10);

        FUN_00571830(uVar7,uVar6,uVar10);

      }

      local_6 = 3;

      goto LAB_008016f8;

    }

  }

  cVar3 = FUN_005714e0(piVar1,&local_2c,&local_28,1,0xffffffff);

  if (cVar3 == '\0') {

    cVar3 = FUN_004ce5c0(*(uint32_t /* width from decompiler */ *)((int)in_EAX + 0xe98));

    if (cVar3 != '\0') {

      cVar3 = FUN_005714e0(piVar1,&local_2c,&local_28,1,0xffffffff);

      bVar8 = -(cVar3 != '\0') & 3;

    }

  }

  else {

    bVar8 = 1;

  }

  if (bVar8 != 0) {

    if (bVar8 == 1) {

      iVar9 = *(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 0x250) + 0x2b0);

    }

    else if (bVar8 == 3) {

      iVar9 = *(int *)(*(int *)((int)in_EAX + 0xe98) + 0xcbc);

    }

    else {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

  }

  local_6 = bVar8;

  if (iVar9 != 0) {

    uVar6 = (**(code **)(*piVar1 + 0x25c))();

    cVar3 = FUN_00571620(piVar1,local_2c,local_28,uVar6);

    if (cVar3 == '\0') {

LAB_008015f0:

      FUN_007a69d0();

      uVar11 = 0;

      uVar7 = 1;

      uVar10 = 0xffffffff;

      uVar6 = FUN_007a6de0("This equipment cannot be changed at this time.",0xffffffff);

      FUN_007fdfb0(in_EAX,uVar6,uVar10,uVar7,uVar11);

      return;

    }

  }

LAB_008016f8:

  local_10 = (uint8_t)piVar1[0x5a];

  local_18 = piVar1[0x58];

  local_14 = piVar1[0x59];

  local_8 = (uint8_t)local_2c;

  local_7 = (uint8_t)local_28;

  local_24[1] = 0x2036;

  Client_SendSectorPacket(in_EAX,0x20,local_24 + 1);

  FUN_007fc150();

  Client_RefreshOpenMissionUiWindows(in_EAX);

  return;

}
