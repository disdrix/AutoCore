// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, Object_ResolveFromTFID×2, Client_EvalAutoPatrolWaypoint, FUN_004e88e0, FUN_009197a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_009197a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009197a0
// Address:   0x009197a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void * Named_VOG_DEBUG_STOP_009197a0(float param_1)



{

  char cVar1;

  float *pfVar2;

  void *pvVar3;

  int iVar4;

  void *pvVar5;

  TFID_16 *pTfid;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  TFID_16 TStack_20;

  

  iVar6 = 0;

  pvVar5 = (void *)0x0;

  pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x1a0))();

  fStack_30 = *pfVar2;

  fStack_2c = pfVar2[1];

  fStack_28 = pfVar2[2];

  fStack_24 = pfVar2[3];

  FUN_004e88e0(&fStack_3c,&fStack_30);

  if ((((*(int *)((int)DAT_00d1ad10 + 0x11c) == 0) ||

       (*(int *)((int)DAT_00d1ad10 + 0x120) - *(int *)((int)DAT_00d1ad10 + 0x11c) >> 2 < 1)) ||

      (Client_EvalAutoPatrolWaypoint(DAT_00d1ad10,&TStack_20,&fStack_48),

      param_1 * param_1 <=

      (fStack_40 - fStack_34) * (fStack_40 - fStack_34) +

      (fStack_44 - fStack_38) * (fStack_44 - fStack_38) +

      (fStack_48 - fStack_3c) * (fStack_48 - fStack_3c))) ||

     (pvVar3 = Object_ResolveFromTFID(&TStack_20), pvVar5 = pvVar3, pvVar3 == (void *)0x0)) {

    iVar4 = *(int *)(DAT_00d1b644 + 0xe8f4);

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

LAB_009198f0:

    do {

      iVar4 = *(int *)(DAT_00d1b644 + 0xe8f4);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar6 == 0) {

        iVar6 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar6 = *(int *)(iVar6 + 0x20);

      }

      if (iVar6 == 0) {

        pTfid = (TFID_16 *)0x0;

      }

      else {

        pTfid = *(TFID_16 **)(iVar6 + 0xc);

      }

      pvVar3 = pvVar5;

      if (pTfid == (TFID_16 *)0x0) break;

      if (pTfid[1].dwCoidHi != 0) {

        iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

        if (iVar4 != 0) {

          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

        }

        cVar1 = (**(code **)(*(int *)pTfid[1].dwCoidHi + 100))(iVar4);

        if (cVar1 == '\0') goto LAB_009198f0;

      }

      pvVar3 = Object_ResolveFromTFID(pTfid);

    } while ((pvVar3 == (void *)0x0) ||

            (fVar9 = *(float *)((int)pvVar3 + 0x88) - fStack_28,

            fVar8 = *(float *)((int)pvVar3 + 0x84) - fStack_2c,

            fVar7 = *(float *)((int)pvVar3 + 0x80) - fStack_30,

            param_1 * param_1 <= fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7));

    *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe8f4) + 0x1d) = 0;

  }

  return pvVar3;

}
