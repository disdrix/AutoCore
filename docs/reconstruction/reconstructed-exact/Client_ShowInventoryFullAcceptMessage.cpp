// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT22, Client_SendSectorPacket, FUN_00521e90, FUN_007fdfb0, FUN_0094caa0.
//  - Strings: "Your inventory is too full to accept.".
//  - Return sites: 2.

// =============================================================================
// Client_ShowInventoryFullAcceptMessage
// -----------------------------------------------------------------------------
// Purpose:  Toast when inventory cannot accept an offered/loot item.
//
// Address:  0x0094caa0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0094caa0
// System:   inventory-transfer
//
// String evidence: "Your inventory is too full to accept."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0094caa0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0094caa0 using string evidence: "Your inventory is too full to accept."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_ShowInventoryFullAcceptMessage(void)

{

  int *piVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  uint16_t extraout_var;

  char unaff_BL;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ auStack_18 [2];

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  if ((((*(int *)((int)unaff_ESI + 0xe98) != 0) &&

       (piVar1 = *(int **)((int)unaff_ESI + 0x1050), piVar1 != (int *)0x0)) &&

      (cVar4 = (**(code **)(*piVar1 + 0x3d8))(), cVar4 != '\0')) &&

     (*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250) != 0)) {

    if ((unaff_BL != '\0') &&

       (iVar2 = *(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250),

       cVar4 = FUN_00521e90(*(uint32_t /* width from decompiler */ *)(piVar1[0x144] + 0xce0),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x2b0),

                            CONCAT22(extraout_var,*(uint16_t *)(iVar2 + 0x1e6))), cVar4 == '\0'))

    {

      FUN_007fdfb0(unaff_ESI,"Your inventory is too full to accept.",0xffffffff,1,0);

      return;

    }

    iVar2 = *(int *)((int)unaff_ESI + 0xe98);

    auStack_18[0] = 0x208f;

    iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

    uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2);

    uStack_c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar2);

    Client_SendSectorPacket(unaff_ESI,0x18,auStack_18);

  }

  return;

}
