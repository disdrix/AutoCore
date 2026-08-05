// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: Client_SendInventoryGrab_Hardpoint, Client_SendSectorPacket, FUN_004f6a80, FUN_007fbbb0, FUN_00931db0, InventoryGrab.
//  - Return sites: 3.

// =============================================================================
// Client_SendInventoryGrab_Hardpoint
// -----------------------------------------------------------------------------
// Purpose:  C2S InventoryGrab (0x2034, size 0x20) for equipped / hardpoint
//           items. inventoryType=2 at +0x18; TFID from item
//           +0x160/+0x164/+0x168. Called from item-click when store cursor empty.
//
// Address:  0x00862d90  (autoassault.exe, image base 0x400000)
// Stable:   aa_00862d90
// System:   inventory-transfer
//
// Packet layout (0x20):
//   +0x00  opcode 0x2034
//   +0x08  item TFID lo/hi (+ object byte)
//   +0x18  u8 inventoryType = 2 (hardpoint)
//
// Control flow summary:
//   1) Gate local state / item host
//   2) Pack 0x2034 with type=2 and item TFID
//   3) Client_SendSectorPacket(&DAT_00d1a840, 0x20, buf)
//   4) On success: item vtbl+0x3bc(1) and +0x34c(); return 1 else 0
//
// Related: Client_SendInventoryGrab_FromGrid (type from window, not hardpoint)
// Exactness: Scaffold body below mirrors raw; plate human-refined.
// Dual reviews: pending.
// =============================================================================

/*
 * C2S InventoryGrab (0x2034, size 0x20) for equipped/hardpoint items.
 * Notes retained for body recovery:
 * - Sets inventoryType=2 (hardpoint/equip path).
 * - Sends via Client_SendSectorPacket(&DAT_00d1a840, 0x20, buf).
 * - On success: item vtable+0x3bc(1) and +0x34c().
 * - Returns 1 on send, 0 if gates fail.
 */

int Client_SendInventoryGrab_Hardpoint(void)
{
    return 0; /* full builder in raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* C2S InventoryGrab (0x2034, size 0x20) for equipped/hardpoint items. Sets inventoryType=2 at

   +0x18. TFID from item obj +0x160/+0x164/+0x168. Called from Client_UI_InventoryItemClickDispatch

   when store cursor is null. */



uint32_t /* decomp width */ Client_SendInventoryGrab_Hardpoint(void)



{

  int iVar1;

  uint32_t /* decomp width */ uVar2;

  int *unaff_EBX;

  uint32_t /* decomp width */ auStack_20 [2];

  uint32_t /* decomp width */ uStack_18;

  uint32_t /* decomp width */ uStack_14;

  uint8_t uStack_10;

  uint8_t uStack_8;

  

  FUN_007fbbb0();

  if (DAT_00d1b6d8 != 0) {

    iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();

    if (iVar1 != 0) {

      uVar2 = (**(code **)(*unaff_EBX + 0x3ac))();

      iVar1 = FUN_004f6a80(uVar2);

      if (iVar1 != 0) {

        FUN_00931db0();

        return 0;

      }

      auStack_20[0] = 0x2034;

      iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();

      uStack_10 = *(uint8_t *)(iVar1 + 0x168);

      iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();

      uStack_18 = *(uint32_t /* decomp width */ *)(iVar1 + 0x160);

      uStack_14 = *(uint32_t /* decomp width */ *)(iVar1 + 0x164);

      uStack_8 = 2;

      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

      (**(code **)(*unaff_EBX + 0x3bc))(1);

      (**(code **)(*unaff_EBX + 0x34c))();

      return 1;

    }

  }

  return 0;

}
