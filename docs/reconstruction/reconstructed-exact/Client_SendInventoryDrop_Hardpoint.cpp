// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, return×7, goto×1.
//  - Notable callees: FUN_004ce5f0×2, Client_SendInventoryDrop_Hardpoint, Client_SendSectorPacket, FUN_004fabc0, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_008012f0.
//  - Strings: "This item can only be changed in town.".
//  - Return sites: 7.

// =============================================================================
// Client_SendInventoryDrop_Hardpoint
// -----------------------------------------------------------------------------
// Purpose:  C2S drop / equip-from-cursor onto a hardpoint. Blocks paint and
//           customize-only-in-town cases; toast "This item can only be changed
//           in town." when locked.
//
// Address:  0x00863430  (autoassault.exe, image base 0x400000)
// Stable:   aa_00863430
// System:   inventory-transfer
//
// Control flow summary:
//   1) Require DAT_00d1b6d8; cursor item via DAT_00d1b1f8 vtbl+0x3ac
//   2) FUN_00862860 gate; FUN_004fabc0 may force FUN_00931db0
//   3) Clone type 0x0E paint path: FUN_004ce5f0 / char+0x6b4 town checks
//   4) Build/send hardpoint drop packet; town-only toast on reject
//
// Related: Client_UI_InventoryItemClickDispatch (cursor held → this path)
// Exactness: Scaffold body below mirrors raw; plate human-refined.
// Dual reviews: pending.
// =============================================================================

/*
 * C2S drop/unequip-from-cursor for hardpoint items.
 * Notes retained for body recovery:
 * - Requires DAT_00d1b6d8; cursor item via DAT_00d1b1f8 vtable+0x3ac.
 * - FUN_00862860 gate; FUN_004fabc0 may force FUN_00931db0.
 * - Clone type 0x0E (vehicle paint path) with FUN_004ce5f0 / char+0x6b4 town checks.
 * - Town-only toast shared with other equip paths.
 */

uint8_t Client_SendInventoryDrop_Hardpoint(void)
{
    return 0; /* full body in raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
uint8_t Client_SendInventoryDrop_Hardpoint(void)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* decomp width */ uVar4;

  uint32_t /* decomp width */ uVar5;

  uint32_t /* decomp width */ uVar6;

  uint32_t /* decomp width */ uVar7;

  uint32_t /* decomp width */ auStack_20 [2];

  int iStack_18;

  int iStack_14;

  uint8_t uStack_10;

  uint8_t uStack_8;

  uint8_t uStack_7;

  uint8_t uStack_6;

  

  if (DAT_00d1b6d8 == 0) {

    return 0;

  }

  piVar2 = (int *)(**(code **)(*DAT_00d1b1f8 + 0x3ac))();

  if (piVar2 == (int *)0x0) {

    return 0;

  }

  cVar1 = FUN_00862860();

  if (cVar1 == '\0') {

    return 0;

  }

  uVar4 = *(uint32_t /* decomp width */ *)(DAT_00d1b6d8 + 0x250);

  iVar3 = FUN_004fabc0(piVar2,0);

  if (iVar3 != 0) {

    FUN_00931db0();

    return 1;

  }

  if (*(int *)(piVar2[0x2a] + 0x38) == 0xe) {

    cVar1 = FUN_004ce5f0(uVar4);

    if ((cVar1 != '\0') || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

      FUN_008012f0();

      FUN_00931440(1);

      return 1;

    }

LAB_0086351d:

    FUN_007a69d0();

    uVar7 = 0;

    uVar6 = 1;

    uVar5 = 0xffffffff;

    uVar4 = FUN_007a6de0("This item can only be changed in town.",0xffffffff);

    FUN_007fdfb0(&DAT_00d1a840,uVar4,uVar5,uVar6,uVar7);

    return 1;

  }

  cVar1 = FUN_004ce5f0(uVar4);

  if (cVar1 == '\0') {

    iVar3 = (**(code **)(*piVar2 + 0x1f0))();

    if ((iVar3 != 0) && (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) goto LAB_0086351d;

  }

  uStack_10 = (uint8_t)piVar2[0x5a];

  iStack_14 = piVar2[0x59];

  iStack_18 = piVar2[0x58];

  uStack_8 = 0xff;

  uStack_7 = 0xff;

  auStack_20[0] = 0x2036;

  uStack_6 = 2;

  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

  return 1;

}
