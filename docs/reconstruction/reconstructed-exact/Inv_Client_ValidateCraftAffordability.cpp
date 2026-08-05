// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, goto×4, do×1, while×1.
//  - Notable callees: FUN_007a6de0×3, CNDHash_LookupByKey, FUN_0051fc80, FUN_00522060, FUN_007a69d0, FUN_0089bf50, FUN_00977a30.
//  - Strings: "Cost: N/A"; "Cost: "; "You cannot afford to make this item!".
//  - Return sites: 5.

// =============================================================================
// Inv_Client_ValidateCraftAffordability
// -----------------------------------------------------------------------------
// Purpose:  Craft UI validation: looks up recipe cost, formats Cost line, and blocks craft when required components are missing from inventory or player cannot afford the credit cost.
//
// Address:  0x0089bf50  (autoassault.exe, image base 0x400000)
// Stable:   aa_0089bf50
// System:   inventory-transfer
//
// Evidence strings (from raw decompile):
//   - "Cost: N/A"
//   - "Cost: "
//   - "You cannot make this item with the components you currently have in your inventory!"
//   - "You cannot afford to make this item!"
//
// Notable callees:
//   - CNDHash_LookupByKey
//   - FUN_007a6de0
//   - FUN_0051fc80 / FUN_00977a30 / FUN_00522060
//
// Notes:    Companion of refinery remove path (callee of Inv_Client_HandleRefineryRemoveResponse).
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void Inv_Client_ValidateCraftAffordability(void)



{

  char cVar1;

  int in_EAX;

  uint uVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  char *pcStack_124;

  char acStack_110 [4];

  uint32_t /* width from decompiler */ local_10c;

  uint8_t auStack_108 [4];

  void *pvStack_104;

  char acStack_100 [128];

  uint8_t auStack_80 [128];

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(int *)(in_EAX + 0x54c) == 0) {

    return;

  }

  local_10c = FUN_007a69d0();

  (**(code **)(**(int **)(in_EAX + 0x54c) + 0x268))();

  pcStack_124 = (char *)0x89bfa6;

  pvStack_104 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),*(uint *)(in_EAX + 0x5ec));

  if (pvStack_104 == (void *)0x0) {

    iVar4 = **(int **)(in_EAX + 0x54c);

    pcStack_124 = "Cost: N/A";

    FUN_007a6de0();

    pcStack_124 = (char *)0x89bfd5;

    (**(code **)(iVar4 + 0x250))();

    pcStack_124 = (char *)0x89bfe3;

    (**(code **)(**(int **)(in_EAX + 0x54c) + 0x34c))();

    if (*(int *)(in_EAX + 0x554) != 0) {

      pcStack_124 = (char *)0x89bffa;

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x554) + 0xd8))();

      if (cVar1 != '\0') {

        pcStack_124 = (char *)0x0;

        (**(code **)(**(int **)(in_EAX + 0x554) + 0xd4))();

        (**(code **)(**(int **)(in_EAX + 0x554) + 0x34c))();

      }

    }

    if (*(int *)(in_EAX + 0x584) == 0) {

      return;

    }

    pcStack_124 = (char *)0x0;

    (**(code **)(**(int **)(in_EAX + 0x584) + 0xcc))();

    (**(code **)(**(int **)(in_EAX + 0x584) + 0x34c))();

    return;

  }

  iVar4 = *(int *)(in_EAX + 0x524);

  if (iVar4 < 1) {

    iVar4 = 1;

  }

  uVar2 = *(int *)(*(int *)((int)pvStack_104 + 0x3c) + 0x4c4) * iVar4;

  iVar4 = (int)uVar2 >> 0x1f;

  pcStack_124 = (char *)0x1;

  FUN_0051fc80(uVar2,iVar4,auStack_80);

  pcStack_124 = (char *)0xffffffff;

  pcVar3 = (char *)FUN_007a6de0("Cost: ");

  pcVar6 = acStack_100;

  do {

    cVar1 = *pcVar3;

    *pcVar6 = cVar1;

    pcVar3 = pcVar3 + 1;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  iVar5 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

          (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

  if ((iVar5 < iVar4) ||

     (((iVar5 <= iVar4 &&

       (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) < uVar2)) ||

      (*(int *)(in_EAX + 0x524) < 1)))) {

    pcStack_124 = acStack_110;

    acStack_110[2] = 0xff;

    acStack_110[1] = 0;

    acStack_110[0] = '\0';

    acStack_110[3] = 0xff;

    (**(code **)(**(int **)(in_EAX + 0x54c) + 0x15c))(1);

    uVar9 = 0;

    uVar8 = 0;

  }

  else {

    pcStack_124 = acStack_110;

    acStack_110[2] = 0;

    acStack_110[1] = 0xff;

    acStack_110[0] = '\0';

    acStack_110[3] = 0xff;

    (**(code **)(**(int **)(in_EAX + 0x54c) + 0x15c))(1);

    uVar9 = 0xff;

    uVar8 = 0xff;

  }

  (**(code **)(**(int **)(in_EAX + 0x54c) + 0x228))(auStack_108,0xff,uVar8,uVar9,0xff);

  FUN_00977a30(DAT_00d1ad30,uVar2,iVar4);

  pcStack_124 = (char *)0x0;

  if ((DAT_00d1b6d8 == 0) ||

     (cVar1 = FUN_00522060(unaff_EBP,&pcStack_124,*(uint8_t *)(in_EAX + 0x528),

                           *(uint8_t *)(in_EAX + 0x538)), cVar1 == '\0')) {

    if ((*(int *)(in_EAX + 0x554) != 0) &&

       (cVar1 = (**(code **)(**(int **)(in_EAX + 0x554) + 0xd8))(), cVar1 != '\0')) {

      (**(code **)(**(int **)(in_EAX + 0x554) + 0xd4))(0);

      (**(code **)(**(int **)(in_EAX + 0x554) + 0x34c))();

    }

    if (*(int *)(in_EAX + 0x584) == 0) goto LAB_0089c317;

    pcVar6 = "You cannot make this item with the components you currently have in your inventory!";

LAB_0089c2db:

    uVar7 = 1;

    uVar9 = 1;

    iVar4 = **(int **)(in_EAX + 0x584);

    uVar8 = FUN_007a6de0(pcVar6,0xffffffff);

    (**(code **)(iVar4 + 0x1d8))(uVar8,uVar9,uVar7);

    uVar8 = 1;

  }

  else {

    iVar5 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

            (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

    if ((iVar5 < iVar4) ||

       ((iVar5 <= iVar4 &&

        (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) < uVar2)))) {

      if ((*(int *)(in_EAX + 0x554) != 0) &&

         (cVar1 = (**(code **)(**(int **)(in_EAX + 0x554) + 0xd8))(), cVar1 != '\0')) {

        (**(code **)(**(int **)(in_EAX + 0x554) + 0xd4))(0);

        (**(code **)(**(int **)(in_EAX + 0x554) + 0x34c))();

      }

      if (*(int *)(in_EAX + 0x584) == 0) goto LAB_0089c317;

      pcVar6 = "You cannot afford to make this item!";

      goto LAB_0089c2db;

    }

    if ((*(int *)(in_EAX + 0x554) != 0) &&

       (cVar1 = (**(code **)(**(int **)(in_EAX + 0x554) + 0xd8))(), cVar1 == '\0')) {

      (**(code **)(**(int **)(in_EAX + 0x554) + 0xd4))(1);

      (**(code **)(**(int **)(in_EAX + 0x554) + 0x34c))();

    }

    if (*(int *)(in_EAX + 0x584) == 0) goto LAB_0089c317;

    (**(code **)(**(int **)(in_EAX + 0x584) + 0x1d8))(0,1,1);

    uVar8 = 0;

  }

  (**(code **)(**(int **)(in_EAX + 0x584) + 0xcc))(uVar8);

  (**(code **)(**(int **)(in_EAX + 0x584) + 0x34c))();

LAB_0089c317:

  (**(code **)(**(int **)(in_EAX + 0x54c) + 0x34c))();

  return;

}
