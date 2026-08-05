// =============================================================================
// Outpost_CaptureOutpost  (was FUN_006082e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006082e0
// Address:   0x006082e0  (autoassault.exe, image base 0x400000)
// Body:      0x006082e0–0x00608614
// System:    skills-abilities / outpost
// Dual A/B:  2026-07-29 W20-D  accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Capture an outpost for the capturer's root race/faction.
//   Product string: "Invalid faction in CaptureOutpost = %d"
//
// SIGNATURE
//   void __thiscall Outpost_CaptureOutpost(void* thisOutpost, void* capturerCtx);
//   // ECX = outpost; stack capturerCtx (may be null); RET 4
//
// KEY OFFSETS (this)
//   +0x218  float capture radius
//   +0x220  char schedule-bank select
//   +0x234  int faction
//   +0x238  int schedule count (out)
//   +0x23c  int schedule cursor (cleared)
//   +0x248  timer blob* (+8 float, +0x14 tick)
//
// GATES
//   newFaction != oldFaction AND timerBlob != null
//   newFaction in [0, 3] else log + return
//   world+0x7e non-zero for transfer block
//
// SUCCESS CHAIN (after world gate)
//   clear old bank helpers → cast for new faction → store faction
//   → UpdateBeaconShareRatio → arm timer/schedule → notify helper
//
// SIBLINGS (dual-sealed elsewhere)
//   Outpost_CastSkillsForFaction   @ 0x00606d70
//   Outpost_UpdateBeaconShareRatio @ 0x006078e0
//   Object_GetRootRaceId           @ 0x00512440
// =============================================================================

#include <stdint.h>

/* Named dual-sealed helpers */
extern int  Object_GetRootRaceId(void *objectBase);
extern void Outpost_CastSkillsForFaction(int factionIndex);      /* thiscall ECX=outpost */
extern void Outpost_UpdateBeaconShareRatio(void);                /* thiscall ECX=outpost */
extern void FUN_007a4480(int level, const char *fmt, ...);

/* Unresolved callees (thiscall ECX=outpost unless noted) */
extern void FUN_004cd5f0(int oldFaction);
extern void FUN_004cd5d0(unsigned char raceByte);
extern void FUN_005743e0(int a, int b, int c);
extern void FUN_00418d70(void *tfidPair);
extern void FUN_00606820(int oldFaction);
extern void FUN_00606890(int oldFaction);
extern void FUN_00606ff0(int oldFaction);
extern void FUN_00606900(int newFaction);
extern void FUN_00606a00(int newFaction);
extern void FUN_00606a70(int newFaction, int capturerBase);
extern float FUN_00607550(void);
extern void FUN_006081b0(int capturerRoot);
extern uint32_t GetTickCount(void);

extern int DAT_00d029f4;
extern int DAT_00d029f8;
extern int DAT_00d029e4;
extern int DAT_00d029e8;

void __thiscall Outpost_CaptureOutpost(int thisOutpost, int *capturerCtx)
{
  unsigned char raceByte;
  int iVar2;
  int neighborRace;
  float *neighborPos;
  int iVar5;
  uint32_t tick;
  int capturer;          /* root object from capturerCtx vtbl+0x210 */
  float fVar8, fVar9, fVar10;
  int newFaction;        /* decompiler RACE_ID_INFERRED local_28 */
  unsigned int idx;
  float radiusSq;
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;

  capturer = 0;
  newFaction = 3;  /* RACE_TRIBE | RACE_BIOMEK seed */

  if ((capturerCtx != (int *)0x0) &&
      (capturer = (**(int (**)(int))(*capturerCtx + 0x210))(0), capturer != 0)) {
    newFaction = Object_GetRootRaceId(
        (void *)(*(int *)(*(int *)(capturer + 4) + 4) + 4 + capturer));
  }

  iVar5 = *(int *)(thisOutpost + 0x234);
  if ((-1 < iVar5) && (iVar5 < 3)) {
    FUN_004cd5f0(iVar5);
  }

  if ((capturer != 0) &&
      (raceByte = *(unsigned char *)(
           *(int *)(*(int *)(*(int *)(*(int *)(capturer + 4) + 4) + 0xac + capturer) + 0x3c)
           + 0x532),
       raceByte < 3)) {
    FUN_004cd5d0(raceByte);
  }

  if ((newFaction != *(int *)(thisOutpost + 0x234)) &&
      (*(int *)(thisOutpost + 0x248) != 0)) {
    if (((int)newFaction < 0) || (3 < (int)newFaction)) {
      FUN_007a4480(0, "Invalid faction in CaptureOutpost = %d", newFaction);
    }
    else {
      FUN_005743e0(0, 0, 0);

      if (capturer != 0) {
        iVar5 = *(int *)(*(int *)(capturer + 4) + 4);
        radiusSq = *(float *)(iVar5 + 0x164 + capturer);
        uStack_1c = *(uint32_t *)(iVar5 + 0x168 + capturer);
        FUN_00418d70(&radiusSq);

        radiusSq = *(float *)(thisOutpost + 0x218) * *(float *)(thisOutpost + 0x218);
        idx = 0;
        while (1) {
          iVar5 = *(int *)(*(int *)(*(int *)(capturer + 4) + 4) + 0xa8 + capturer);
          iVar2 = *(int *)(iVar5 + 0xe75c);
          if ((iVar2 == 0) ||
              ((unsigned int)(*(int *)(iVar5 + 0xe760) - iVar2 >> 2) <= idx))
            break;
          iVar5 = *(int *)(iVar2 + idx * 4);
          if ((iVar5 != capturer) &&
              (neighborRace = Object_GetRootRaceId(
                   (void *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5)),
               neighborRace == newFaction)) {
            neighborPos = (float *)(**(int (**)(void))(
                *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1a0))();
            iVar2 = *(int *)(*(int *)(thisOutpost + 4) + 4);
            fVar10 = neighborPos[2] - *(float *)(iVar2 + 0x8c + thisOutpost);
            fVar9  = neighborPos[1] - *(float *)(iVar2 + 0x88 + thisOutpost);
            fVar8  = *neighborPos     - *(float *)(iVar2 + 0x84 + thisOutpost);
            if (fVar10 * fVar10 + fVar9 * fVar9 + fVar8 * fVar8 < radiusSq) {
              iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);
              uStack_18 = *(uint32_t *)(iVar2 + 0x164 + iVar5);
              uStack_14 = *(uint32_t *)(iVar2 + 0x168 + iVar5);
              FUN_00418d70(&uStack_18);
            }
          }
          idx = idx + 1;
        }
      }

      if (*(char *)(*(int *)(*(int *)(*(int *)(thisOutpost + 4) + 4) + 0xa8 + thisOutpost) +
                    0x7e) != '\0') {
        FUN_00606820(*(uint32_t *)(thisOutpost + 0x234));
        FUN_00606890(*(uint32_t *)(thisOutpost + 0x234));
        FUN_00606ff0(*(uint32_t *)(thisOutpost + 0x234));
        FUN_00606900(newFaction);
        FUN_00606a00(newFaction);
        Outpost_CastSkillsForFaction(newFaction);

        if (capturer == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*(int *)(capturer + 4) + 4) + 4 + capturer;
        }
        FUN_00606a70(newFaction, iVar5);

        *(int *)(thisOutpost + 0x234) = newFaction;
        Outpost_UpdateBeaconShareRatio();

        iVar5 = DAT_00d029f4;
        iVar2 = DAT_00d029f8;
        if (*(char *)(thisOutpost + 0x220) != '\0') {
          iVar5 = DAT_00d029e4;
          iVar2 = DAT_00d029e8;
        }
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = iVar2 - iVar5 >> 4;
        }
        *(int *)(thisOutpost + 0x238) = iVar5;
        *(uint32_t *)(thisOutpost + 0x23c) = 0;

        radiusSq = FUN_00607550();
        iVar5 = *(int *)(thisOutpost + 0x248);
        tick = GetTickCount();
        *(float *)(iVar5 + 8) = radiusSq;
        *(uint32_t *)(iVar5 + 0x14) = tick;

        FUN_006081b0(capturer);
        return;
      }
    }
  }
  return;
}
