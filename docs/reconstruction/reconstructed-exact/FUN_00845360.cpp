// =============================================================================
// FUN_00845360 / UI_AppendItemRequirements
// -----------------------------------------------------------------------------
// Stable ID: aa_00845360
// Address:   0x00845360  (autoassault.exe, image base 0x400000)
// Body:      0x00845360 – 0x00845871 (~1298 B; add esp,0x8c; plain ret)
// System:    UI / item tooltip requirements
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W23-J dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A_aa_00845360_UI_AppendItemRequirements.md + B_*.md
// Role name: UI_AppendItemRequirements.cpp
// Rejected:  Named_Combat_00845360 (Combat is one line of many)
// =============================================================================

// PURPOSE:
//   Append localized "Requires:" block (Level / race / class / Combat / Tech /
//   Theory / Perception) to a UI text object for an item row; color by local
//   player meet/fail. Returns line count (0 if suppressed or empty).
//
// ABI (sealed W23-J):
//   Item/template in **EAX** (mov esi,eax); stack: UI text* (param_1), char show (param_2).
// Embedded strings:
//   "Requires:"; "Level"; "Combat"; "Tech"@0x00a2e4fc; "Theory"; "Perception"
//   race via FUN_0051f8e0; class via FUN_0051f940

// READABILITY (auto CF):
//  - Body size: ~171 non-empty decompiler lines.
//  - Control keywords: if×19, return×4, goto×2.
//  - Notable callees: FUN_007a6de0×8, sprintf×7, FUN_0040f540×2,
//    Character_GetTechForPoolCalcs, FUN_004c4070, FUN_004c4140, FUN_004c41c0,
//    FUN_0051f8e0, FUN_0051f940, FUN_007a69d0.
//  - Return sites: 4.

/*
 * Behavioral notes (2026-07-29 W23-J dual):
 * - Early out: show==0 OR *( *(item+0xa8)+0x38 )==0x1a OR DAT_00d1b6d8==0.
 * - Empty-req out before header when all level/race/class/stat reqs inactive.
 * - Colors: header 0xffbbbbbb; met 0xffffffff; fail 0xffff2020; race/class met vfunc+0x250.
 * - Decomp hazard: Perception tail "return unaff_EBP+1" is lineCount+1.
 * - Callers: FUN_00843a60, FUN_0084b890, FUN_0088d980 ×2.
 * - Runtime / differential: OPEN.
 */

int FUN_00845360(int *param_1,char param_2)



{

  byte bVar1;

  int *piVar2;

  bool bVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  int in_EAX;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint uVar10;

  int unaff_EBP;

  uint32_t /* width from decompiler */ uVar11;

  char acStack_88 [132];

  int *piStack_4;

  

  FUN_007a69d0();

  if (((param_2 == '\0') || (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0x1a)) ||

     (DAT_00d1b6d8 == (void *)0x0)) {

    return 0;

  }

  iVar7 = (int)*(short *)(in_EAX + 0xea) + (int)*(short *)(in_EAX + 0xe8);

  if (((((iVar7 < 0x51) && ((short)iVar7 < 1)) &&

       ((iVar7 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))(), iVar7 == -1 &&

        ((*(int *)(*(int *)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x3e0) == -1 &&

         (*(short *)(in_EAX + 0xec) < 1)))))) && (*(short *)(in_EAX + 0xf0) < 1)) &&

     ((*(short *)(in_EAX + 0xf2) < 1 && (*(short *)(in_EAX + 0xee) < 1)))) {

    return 0;

  }

  iVar7 = *param_1;

  uVar11 = 0xffbbbbbb;

  uVar8 = FUN_007a6de0("Requires:",0xffffffff);

  (**(code **)(iVar7 + 0x224))(uVar8,uVar11);

  iVar9 = (int)*(short *)(in_EAX + 0xea) + (int)*(short *)(in_EAX + 0xe8);

  iVar7 = 1;

  if ((0x50 < iVar9) || (0 < (short)iVar9)) {

    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                 (int)DAT_00d1b6d8) + 0x27c))();

    sVar4 = FUN_0040f540();

    sVar5 = FUN_0040f540();

    iVar9 = (int)sVar5;

    uVar8 = FUN_007a6de0("Level",0xffffffff);

    sprintf(acStack_88,"\n%s %i",uVar8,iVar9);

    if (iVar7 < sVar4) {

      uVar8 = 0xffff2020;

    }

    else {

      uVar8 = 0xffffffff;

    }

    (**(code **)(*piStack_4 + 0x224))(acStack_88,uVar8);

    iVar7 = 2;

  }

  iVar9 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))();

  if (iVar9 != -1) {

    bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       (int)DAT_00d1b6d8) + 0x3c) + 0x532);

    uVar10 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))();

    uVar11 = 0xffffffff;

    uVar8 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))(0xffffffff);

    uVar8 = FUN_0051f8e0(uVar8);

    uVar8 = FUN_007a6de0(uVar8,uVar11);

    sprintf(acStack_88,"\n%s",uVar8);

    if (bVar1 == uVar10) {

      (**(code **)(*piStack_4 + 0x250))(acStack_88);

    }

    else {

      (**(code **)(*piStack_4 + 0x224))(acStack_88,0xffff2020);

    }

    iVar7 = iVar7 + 1;

  }

  piVar2 = *(int **)(*(int *)(in_EAX + 0xa8) + 0x3c);

  uVar10 = piVar2[0xf8];

  if (uVar10 == 0xffffffff) goto LAB_00845685;

  if (*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac +

                                 (int)DAT_00d1b6d8) + 0x3c) + 0x531) == uVar10) {

    bVar3 = false;

    iVar9 = (**(code **)(*piVar2 + 0x14))();

    if ((iVar9 != -1) &&

       (bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac +

                                           (int)DAT_00d1b6d8) + 0x3c) + 0x532),

       uVar10 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))(), bVar1 != uVar10)

       ) goto LAB_008455e6;

  }

  else {

LAB_008455e6:

    bVar3 = true;

  }

  iVar9 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))();

  if (iVar9 == -1) {

    uVar10 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac

                                              + (int)DAT_00d1b6d8) + 0x3c) + 0x532);

  }

  else {

    uVar10 = (**(code **)(**(int **)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x14))();

  }

  uVar11 = 0xffffffff;

  uVar8 = FUN_0051f940(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x3e0),uVar10,

                       0xffffffff);

  uVar8 = FUN_007a6de0(uVar8,uVar11);

  sprintf(acStack_88,"\n%s",uVar8);

  if (bVar3) {

    (**(code **)(*piStack_4 + 0x224))(acStack_88,0xffff2020);

  }

  else {

    (**(code **)(*piStack_4 + 0x250))(acStack_88);

  }

  iVar7 = iVar7 + 1;

LAB_00845685:

  sVar4 = *(short *)(in_EAX + 0xec);

  if (0 < sVar4) {

    sVar6 = FUN_004c4070();

    sVar5 = *(short *)(in_EAX + 0xec);

    uVar8 = FUN_007a6de0("Combat",0xffffffff);

    sprintf(acStack_88,"\n%i %s",(int)sVar5,uVar8);

    if (sVar6 < sVar4) {

      uVar8 = 0xffff2020;

    }

    else {

      uVar8 = 0xffffffff;

    }

    (**(code **)(*piStack_4 + 0x224))(acStack_88,uVar8);

    iVar7 = iVar7 + 1;

  }

  sVar4 = *(short *)(in_EAX + 0xf0);

  if (0 < sVar4) {

    iVar9 = Character_GetTechForPoolCalcs(DAT_00d1b6d8);

    sVar5 = *(short *)(in_EAX + 0xf0);

    uVar8 = FUN_007a6de0(&DAT_00a2e4fc,0xffffffff);

    sprintf(acStack_88,"\n%i %s",(int)sVar5,uVar8);

    if ((short)iVar9 < sVar4) {

      uVar8 = 0xffff2020;

    }

    else {

      uVar8 = 0xffffffff;

    }

    (**(code **)(*piStack_4 + 0x224))(acStack_88,uVar8);

    iVar7 = iVar7 + 1;

  }

  sVar4 = *(short *)(in_EAX + 0xf2);

  if (0 < sVar4) {

    sVar6 = FUN_004c4140();

    sVar5 = *(short *)(in_EAX + 0xf2);

    uVar8 = FUN_007a6de0("Theory",0xffffffff);

    sprintf(acStack_88,"\n%i %s",(int)sVar5,uVar8);

    if (sVar6 < sVar4) {

      uVar8 = 0xffff2020;

    }

    else {

      uVar8 = 0xffffffff;

    }

    (**(code **)(*piStack_4 + 0x224))(acStack_88,uVar8);

    iVar7 = iVar7 + 1;

  }

  sVar4 = *(short *)(in_EAX + 0xee);

  if (sVar4 < 1) {

    return iVar7;

  }

  sVar6 = FUN_004c41c0();

  sVar5 = *(short *)(in_EAX + 0xee);

  uVar8 = FUN_007a6de0("Perception",0xffffffff);

  sprintf(acStack_88,"\n%i %s",(int)sVar5,uVar8);

  if (sVar6 < sVar4) {

    uVar8 = 0xffff2020;

  }

  else {

    uVar8 = 0xffffffff;

  }

  (**(code **)(*piStack_4 + 0x224))(acStack_88,uVar8);

  return unaff_EBP + 1;

}
