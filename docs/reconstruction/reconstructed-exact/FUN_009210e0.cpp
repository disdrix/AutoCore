// =============================================================================
// FUN_009210e0  (scaffold alias → Client_RefreshInteractPromptTarget_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009210e0
// Address:   0x009210e0–0x00921355  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-23 scaffold; dual A/B sealed 2026-07-29 W18-L
// Prefer:    Client_RefreshInteractPromptTarget_Inferred.cpp
// Dual:      accept-with-gaps
// =============================================================================

// PURPOSE: Proximity interact prompt target refresh (15f cascade); not UseObject send.
// ABI: RET 4 (unused stack formal from timer parent); ESI = selected object for UI.

// READABILITY (auto CF):
//  - Control keywords: if×11, return×3, goto×2.
//  - Callees: Object_ResolveFromTFID×3, Client_MaybeShowFirstTimeTip,
//             FUN_0058cd60 (mode 6), Skill_GatherTargetsInArea (3 / 7),
//             FUN_009197a0, FUN_008a81a0.

/*
 * Behavioral notes:
 * - Live decompile 2026-07-29 ≡ raw 2026-07-23.
 * - DAT_00aaaca4 = 225.0f; gather r = 15.0f (0x41700000).
 * - Runtime / differential verification: OPEN.
 */

void FUN_009210e0(void)
{
  char cVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  TFID_16 aTStack_40 [3];

  if (DAT_00d1b8c8 == (int *)0x0) {
    return;
  }
  cVar1 = (**(code **)(*DAT_00d1b8c8 + 0x3d8))();
  if (cVar1 == '\0') {
    return;
  }
  aTStack_40[0].dwCoidLo = DAT_00a158b8;
  aTStack_40[0].bGlobal = (byte)DAT_00a158c0;
  aTStack_40[0].bPad0 = DAT_00a158c0._1_1_;
  aTStack_40[0].bPad1 = DAT_00a158c0._2_1_;
  aTStack_40[0].bPad2 = DAT_00a158c0._3_1_;
  aTStack_40[0].bPad3 = (byte)DAT_00a158c4;
  aTStack_40[0].bPad4 = DAT_00a158c4._1_1_;
  aTStack_40[0].bPad5 = DAT_00a158c4._2_1_;
  aTStack_40[0].bPad6 = DAT_00a158c4._3_1_;
  aTStack_40[0].dwCoidHi = DAT_00a158bc;
  pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                         DAT_00d1b6d8) + 0x1a0))();
  fStack_50 = *pfVar2;
  fStack_4c = pfVar2[1];
  fStack_48 = pfVar2[2];
  fStack_44 = pfVar2[3];
  if ((((DAT_00d1d888 == (int *)0x0) ||
       (iVar3 = (**(code **)(*DAT_00d1d888 + 0x210))(0), iVar3 == DAT_00d1b6d8)) ||
      (pfVar2 = (float *)(**(code **)(*DAT_00d1d888 + 0x1a0))(),
      DAT_00aaaca4 <
      (pfVar2[2] - fStack_48) * (pfVar2[2] - fStack_48) +
      (pfVar2[1] - fStack_4c) * (pfVar2[1] - fStack_4c) +
      (*pfVar2 - fStack_50) * (*pfVar2 - fStack_50))) ||
     (piVar4 = DAT_00d1d888, DAT_00d1d888 == (int *)0x0)) {
    if (DAT_00d1b6d8 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
    }
    FUN_0058cd60(aTStack_40,0,DAT_00d1b644,iVar3,&fStack_50,0x41700000,1,6,0,0,0);
    piVar4 = Object_ResolveFromTFID(aTStack_40);
    if (piVar4 != (int *)0x0) goto LAB_00921252;
  }
  else {
LAB_00921252:
    Client_MaybeShowFirstTimeTip(3);
    if (piVar4 != (int *)0x0) goto LAB_00921344;
  }
  iVar3 = DAT_00d1b6d8;
  if (DAT_00d1b6d8 != 0) {
    iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
  }
  Skill_GatherTargetsInArea
            (aTStack_40,0,DAT_00d1b644,iVar3,&fStack_50,0x41700000,1,3,0,0,0,1,0,0,0xbf800000);
  pvVar5 = Object_ResolveFromTFID(aTStack_40);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
    if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
      iVar3 = DAT_00d1b6d8;
      if (DAT_00d1b6d8 != 0) {
        iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
      }
      Skill_GatherTargetsInArea
                (aTStack_40,0,DAT_00d1b644,iVar3,&fStack_50,0x41700000,1,7,0x14,0,0,1,0,0,0xbf800000
                );
      pvVar5 = Object_ResolveFromTFID(aTStack_40);
    }
    if (pvVar5 == (void *)0x0) {
      FUN_009197a0(0x41700000);
    }
  }
LAB_00921344:
  FUN_008a81a0(DAT_00d1b8c8);
  return;
}
