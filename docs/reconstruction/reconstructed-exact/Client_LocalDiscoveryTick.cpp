// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1, for×1.
//  - Notable callees: FUN_005cc630×2, CVOGCharacter_IsAreaExplored, CVOGCharacter_SetAreaExploredBit, CVOGHBAICreatureBase_OnHeartBeat, CVOGHBBase_RescheduleAfterFire, CVOGTerrain_SampleExploredAreaId, Client_LocalDiscoveryTick, driving.
//  - Return sites: 2.

// =============================================================================
// Client_LocalDiscoveryTick
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6c60
// Address:   0x005d6c60  (autoassault.exe, image base 0x400000)
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

/* Client-side discovery tick while driving (~5s). Samples CVOGTerrain_SampleExploredAreaId at

   player XZ;

   if area not yet explored, CVOGCharacter_SetAreaExploredBit. Server is authoritative for

   persistence (UnlockRegion / CreateCharacterExtended). */



uint32_t /* width from decompiler */ * __thiscall Client_LocalDiscoveryTick(void *this,uint32_t /* width from decompiler */ *pContext)



{

  int continentId;

  char cVar1;

  uchar areaId_00;

  bool bVar2;

  uint8_t areaId;

  int pObject;

  void *this_00;

  float *pfVar3;

  uint *pOutNextDelayMs;

  

  cVar1 = FUN_005cc630();

  if (cVar1 != '\0') {

    CVOGHBAICreatureBase_OnHeartBeat(this,pContext);

    return pContext;

  }

  pObject = *(int *)((int)this + 100);

  if (*(char *)(*(int *)(*(int *)(*(int *)(pObject + 4) + 4) + 0xa8 + pObject) + 0x7e) != '\0') {

    pObject = (**(code **)(*(int *)(*(int *)(*(int *)(pObject + 4) + 4) + 4 + pObject) + 0x1dc))();

    if (pObject != 0) {

      pObject = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +

                                     *(int *)((int)this + 100)) + 0x1dc))();

      if (*(char *)(pObject + 0x4f1) == '\0') {

        this_00 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4

                                                        ) + 4 + *(int *)((int)this + 100)) + 0x1dc))

                                    ();

        pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)((int)this_00 + 4) + 4) + 4 +

                                               (int)this_00) + 0x1a0))();

        pObject = *(int *)(*(int *)(*(int *)((int)this_00 + 4) + 4) + 0xa8 + (int)this_00);

        continentId = *(int *)(pObject + 0xfc);

        areaId_00 = CVOGTerrain_SampleExploredAreaId(*(void **)(pObject + 0xe4f8),*pfVar3,pfVar3[2])

        ;

        bVar2 = CVOGCharacter_IsAreaExplored(this_00,continentId,areaId_00);

        if (!bVar2) {

          CVOGCharacter_SetAreaExploredBit(this_00,continentId,areaId_00,'\x01');

        }

      }

    }

  }

  *(uint32_t /* width from decompiler */ *)((int)this + 8) = 5000;

  areaId = FUN_005cc630();

  *(uint8_t *)(*(int *)((int)this + 100) + 0x307) = areaId;

  CVOGHBBase_RescheduleAfterFire(this,pOutNextDelayMs);

  return pContext;

}
