// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, goto×1, while×1.
//  - Notable callees: CNDHash_Insert, CVOGReaction_UnlockContinentObject, Client_RecvUnlockRegion, FUN_004d1d00, FUN_004d9ec0, UnlockContObj.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_UnlockContinentObject
// -----------------------------------------------------------------------------
// Stable ID: aa_00531c80
// Address:   0x00531c80  (autoassault.exe, image base 0x400000)
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
 */

/* CVOGReaction_UnlockContinentObject: exploration/continent unlock hash at char+0x534.

   Also called from Client_RecvUnlockRegion (0x205B fog) and GiveMission/CompleteObjective.

   Distinct from reaction type 32 UnlockContObj (map object unlock via 0x206C GroupReactionCall). */



void __thiscall CVOGReaction_UnlockContinentObject(void *this,uint continentId)



{

  int iVar1;

  uint *value;

  uint8_t local_138 [28];

  uint32_t /* or float bits */ local_11c;

  int pHashNode;

  

  pHashNode = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x534) + 0x10) +

                               (*(uint *)(*(int *)((int)this + 0x534) + 8) & continentId) * 4) + 4);

  do {

    if (pHashNode == 0) {

LAB_00531cc8:

      value = operator_new(0xc);

      *value = continentId;

      *(uint8_t *)(value + 1) = 1;

      value[2] = 0;

      CNDHash_Insert(*(void **)((int)this + 0x534),continentId,value,'\0');

      pHashNode = *(int *)(*(int *)((int)this + 4) + 4);

      iVar1 = *(int *)((int)this + pHashNode + 0xa8);

      if ((iVar1 != 0) && ((int)this + pHashNode + 4 == *(int *)(iVar1 + 0xe8a0))) {

        FUN_004d1d00();

        local_11c = 0x2a;

        FUN_004d9ec0(local_138,1);

      }

      return;

    }

    if (continentId == *(uint *)(pHashNode + 0x10)) {

      if ((pHashNode != 0) && (*(int *)(pHashNode + 8) != 0)) {

        return;

      }

      goto LAB_00531cc8;

    }

    pHashNode = *(int *)(pHashNode + 0xc);

  } while( true );

}
