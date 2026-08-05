// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×1, for×1.
//  - Notable callees: FUN_005714e0×2, Client_SendInventoryUnequip, Client_SendSectorPacket, FUN_004ce5c0, FUN_004f6a80, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0.
//  - Return sites: 4.

// =============================================================================
// Client_SendInventoryUnequip
// -----------------------------------------------------------------------------
// Purpose:  C2S InventoryUnequip (0x203E, size 0x30). Builds packet with item
//           TFID and free-slot destination X/Y; rejects when inventory has no
//           space (toast). Bidirectional opcode with S2C UnequipNotify.
//
// Address:  0x00862c00  (autoassault.exe, image base 0x400000)
// Stable:   aa_00862c00
// System:   inventory-transfer
//
// Packet layout (0x30):
//   +0x08  item TFID
//   +0x28  u8 destX  (from free-slot search)
//   +0x29  u8 destY
//   Vehicle TFID fields not filled by this builder (raw plate).
//
// Control flow summary:
//   1) Require DAT_00d1b6d8 and char+0x250
//   2) Item vtbl+0x3ac → inventory root; FUN_004f6a80 may force FUN_00931db0
//   3) FUN_005714e0 free-slot → dest X/Y; town fallback FUN_004ce5c0
//   4) no space → toast "There is not enough space…"; else send 0x203E
//
// Related: Client_RecvInventoryUnequipNotify (S2C apply)
// Exactness: Scaffold body below mirrors raw; plate human-refined.
// Dual reviews: pending.
// =============================================================================

/*
 * C2S InventoryUnequip (0x203E, size 0x30).
 * Notes retained for body recovery:
 * - Requires DAT_00d1b6d8 and char+0x250.
 * - Item vtable+0x3ac → inventory root; FUN_004f6a80 may force FUN_00931db0 path.
 * - FUN_005714e0 free-slot search writes dest X/Y; town fallback FUN_004ce5c0.
 * - Fail toast: 'There is not enough space in your inventory for this equipment.'
 * - Vehicle TFID fields not filled by this builder (raw plate).
 */

// C2S unequip builder - free-slot dest; space check toast on failure.
uint32_t Client_SendInventoryUnequip(void)
{
    return 0; /* full builder in raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* C2S InventoryUnequip request 0x203E size 0x30. item TFID@+8/+10, dest grid X/Y@+0x28/+0x29 from

   free-slot search. Vehicle TFID fields not filled by this builder. */



uint32_t /* decomp width */ Client_SendInventoryUnequip(void)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  uint32_t /* decomp width */ uVar3;

  uint8_t *puVar4;

  uint8_t *puVar5;

  uint32_t /* decomp width */ uVar6;

  uint32_t /* decomp width */ uVar7;

  uint32_t /* decomp width */ uVar8;

  uint8_t uStack_32;

  uint8_t uStack_31;

  uint32_t /* decomp width */ auStack_30 [2];

  uint32_t /* decomp width */ uStack_28;

  uint32_t /* decomp width */ uStack_24;

  uint8_t uStack_20;

  uint8_t uStack_8;

  uint8_t uStack_7;

  

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

    iVar2 = (**(code **)(*in_EAX + 0x3ac))();

    if (iVar2 != 0) {

      uVar3 = (**(code **)(*in_EAX + 0x3ac))();

      iVar2 = FUN_004f6a80(uVar3);

      if (iVar2 != 0) {

        FUN_00931db0();

        return 0;

      }

      uVar7 = 0xffffffff;

      uVar6 = 1;

      puVar5 = &uStack_31;

      puVar4 = &uStack_32;

      uVar3 = (**(code **)(*in_EAX + 0x3ac))(puVar4,puVar5,1,0xffffffff);

      cVar1 = FUN_005714e0(uVar3,puVar4,puVar5,uVar6,uVar7);

      if (cVar1 == '\0') {

        cVar1 = FUN_004ce5c0(DAT_00d1b6d8);

        if (cVar1 != '\0') {

          uVar7 = 0xffffffff;

          uVar6 = 1;

          puVar5 = &uStack_31;

          puVar4 = &uStack_32;

          uVar3 = (**(code **)(*in_EAX + 0x3ac))(puVar4,puVar5,1,0xffffffff);

          cVar1 = FUN_005714e0(uVar3,puVar4,puVar5,uVar6,uVar7);

          if (cVar1 != '\0') goto LAB_00862d14;

        }

        FUN_007a69d0();

        uVar8 = 0;

        uVar7 = 1;

        uVar6 = 0xffffffff;

        uVar3 = FUN_007a6de0("There is not enough space in your inventory for this equipment.",

                             0xffffffff);

        FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar6,uVar7,uVar8);

        return 0;

      }

LAB_00862d14:

      (**(code **)(*in_EAX + 0x34c))();

      auStack_30[0] = 0x203e;

      iVar2 = (**(code **)(*in_EAX + 0x3ac))();

      uStack_20 = *(uint8_t *)(iVar2 + 0x168);

      iVar2 = (**(code **)(*in_EAX + 0x3ac))();

      uStack_28 = *(uint32_t /* decomp width */ *)(iVar2 + 0x160);

      uStack_24 = *(uint32_t /* decomp width */ *)(iVar2 + 0x164);

      uStack_8 = uStack_32;

      uStack_7 = uStack_31;

      Client_SendSectorPacket(&DAT_00d1a840,0x30,auStack_30);

      return 1;

    }

  }

  return 0;

}
