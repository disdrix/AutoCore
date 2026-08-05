// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×2, do×1, while×1.
//  - Notable callees: CNDHash_LookupByKey, CVOGReaction_RelockContinentObject, CVOGReaction_UnlockContinentObject, Client_RecvUnlockRegion, ContinentId, EMSG_Sector_UnlockRegion, ExploredBits, USContinentUnlocked.
//  - Return sites: 3.

// =============================================================================
// Client_RecvUnlockRegion
// -----------------------------------------------------------------------------
// Stable ID: aa_00809550
// Address:   0x00809550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* S2C EMSG_Sector_UnlockRegion (0x205B).

   Packet: opcode, ContinentId(int), UnlockFlag(byte)+pad3, ExploredBits(uint).

   If UnlockFlag==0: relock continent.

   If no local USContinentUnlocked entry: UnlockContinentObject only (bits=0; ignores packet bits).

   If entry exists and bits differ: per-bit CVOGCharacter_SetAreaExploredBit for areas 1..32.

   AutoCore: UnlockRegionPacket; send twice after login to bootstrap then apply bits. */



void __fastcall Client_RecvUnlockRegion(void *gameState)



{

  void *this;

  void *pvVar1;

  uint uVar2;

  uint bitMask;

  int iVar3;

  int pPacket;

  int in_stack_00000004;

  

  this = *(void **)(in_stack_00000004 + 0xe98);

  if (this != (void *)0x0) {

    if (*(char *)(pPacket + 8) == '\0') {

      CVOGReaction_RelockContinentObject(*(uint32_t /* width from decompiler */ *)(pPacket + 4));

      return;

    }

    uVar2 = *(uint *)(pPacket + 4);

    pvVar1 = CNDHash_LookupByKey(*(void **)((int)this + 0x534),uVar2);

                    /* UnlockFlag==0 -> relock continent */

    if (pvVar1 == (void *)0x0) {

      CVOGReaction_UnlockContinentObject(this,uVar2);

    }

    else if (*(int *)((int)pvVar1 + 8) != *(int *)(pPacket + 0xc)) {

      iVar3 = 0;

      do {

                    /* No entry: create empty USContinentUnlocked (bits=0); packet ExploredBits

                       IGNORED */

        uVar2 = 1 << ((byte)iVar3 & 0x1f);

        bitMask = *(uint *)(pPacket + 0xc) & uVar2;

                    /* Bits differ: apply per-area SetAreaExploredBit for 1..32 */

        if (bitMask != (*(uint *)((int)pvVar1 + 8) & uVar2)) {

          CVOGCharacter_SetAreaExploredBit

                    (*(void **)(in_stack_00000004 + 0xe98),*(int *)(pPacket + 4),(byte)iVar3 + 1,

                     bitMask != 0);

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < 0x20);

      return;

    }

  }

  return;

}
