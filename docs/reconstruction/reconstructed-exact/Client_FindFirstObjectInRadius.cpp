// =============================================================================
// Client_FindFirstObjectInRadius
// -----------------------------------------------------------------------------
// Stable ID: aa_009197a0
// Address:   0x009197a0  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-29 dual A/B (from raw 2026-07-23 + fresh decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Find a world object within `radius` of the local player.
//   Prefer in-range auto-patrol waypoint; else first VOG-hash object with
//   dist² < radius². NOT a min-distance nearest-neighbor.
//
// ABI: __stdcall, single float on stack, RET 4; returns Object* in EAX.
// All production callers push 0x41700000 (15.0f).
//
// Strings (hash lock asserts only — not function purpose):
//   "HashError:TraversalLock, already locked for traversal"
//   "HashError:TraverseToNext, not locked for traversal"
//   "VOG_DEBUG_STOP"
// =============================================================================

/* External symbols (Ghidra / prior plates) */
extern int DAT_00d1b6d8;   /* local character / identity */
extern void *DAT_00d1ad10; /* auto-patrol manager */
extern int DAT_00d1b644;   /* world / VOG manager */
struct TFID_16;
void *Object_ResolveFromTFID(TFID_16 *pTfid);
void Client_EvalAutoPatrolWaypoint(void *patrolMgr, TFID_16 *outTfid, float *outPos);
void FUN_004e88e0(float *dstXYZ, float *srcXYZW); /* copy 3 floats */
void FUN_007a4480(int level, const char *msg);

void *Client_FindFirstObjectInRadius(float radius)
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

  /* Local player float4 position via character adj + vtbl+0x1a0 */
  pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                         DAT_00d1b6d8) + 0x1a0))();
  fStack_30 = *pfVar2;
  fStack_2c = pfVar2[1];
  fStack_28 = pfVar2[2];
  fStack_24 = pfVar2[3];
  FUN_004e88e0(&fStack_3c, &fStack_30); /* xyz copy for waypoint compare */

  /* Prefer auto-patrol waypoint if list non-empty, in-range, and resolvable */
  if ((((*(int *)((int)DAT_00d1ad10 + 0x11c) == 0) ||
       (*(int *)((int)DAT_00d1ad10 + 0x120) - *(int *)((int)DAT_00d1ad10 + 0x11c) >> 2 < 1)) ||
      (Client_EvalAutoPatrolWaypoint(DAT_00d1ad10, &TStack_20, &fStack_48),
      radius * radius <=
      (fStack_40 - fStack_34) * (fStack_40 - fStack_34) +
      (fStack_44 - fStack_38) * (fStack_44 - fStack_38) +
      (fStack_48 - fStack_3c) * (fStack_48 - fStack_3c))) ||
     (pvVar3 = Object_ResolveFromTFID(&TStack_20), pvVar5 = pvVar3, pvVar3 == (void *)0x0)) {

    /* VOG hash scan under TraversalLock */
    iVar4 = *(int *)(DAT_00d1b644 + 0xe8f4);
    if (*(char *)(iVar4 + 0x1d) != '\0') {
      FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(unsigned char *)(iVar4 + 0x1d) = 1;

LAB_009198f0:
    do {
      iVar4 = *(int *)(DAT_00d1b644 + 0xe8f4);
      if (*(char *)(iVar4 + 0x1d) == '\0') {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      if (iVar6 == 0) {
        iVar6 = *(int *)(iVar4 + 0x14); /* first node */
      }
      else {
        iVar6 = *(int *)(iVar6 + 0x20); /* next */
      }
      if (iVar6 == 0) {
        pTfid = (TFID_16 *)0x0;
      }
      else {
        pTfid = *(TFID_16 **)(iVar6 + 0xc);
      }
      pvVar3 = pvVar5;
      if (pTfid == (TFID_16 *)0x0) break;

      /* Optional predicate (decompiler TFID overlay — field typing open) */
      if (pTfid[1].dwCoidHi != 0) {
        iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);
        if (iVar4 != 0) {
          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;
        }
        cVar1 = (**(code **)(*(int *)pTfid[1].dwCoidHi + 100))(iVar4);
        if (cVar1 == '\0') goto LAB_009198f0;
      }

      pvVar3 = Object_ResolveFromTFID(pTfid);
      /* Continue while unresolved OR outside radius (strict: need dist² < r²) */
    } while ((pvVar3 == (void *)0x0) ||
            (fVar9 = *(float *)((int)pvVar3 + 0x88) - fStack_28,
            fVar8 = *(float *)((int)pvVar3 + 0x84) - fStack_2c,
            fVar7 = *(float *)((int)pvVar3 + 0x80) - fStack_30,
            radius * radius <= fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7));

    *(unsigned char *)(*(int *)(DAT_00d1b644 + 0xe8f4) + 0x1d) = 0;
  }
  return pvVar3;
}
