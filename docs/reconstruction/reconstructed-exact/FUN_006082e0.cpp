// =============================================================================
// FUN_006082e0  (alias scaffold → Outpost_CaptureOutpost)
// -----------------------------------------------------------------------------
// Stable ID: aa_006082e0
// Address:   0x006082e0  (autoassault.exe, image base 0x400000)
// Body:      0x006082e0–0x00608614
// System:    skills-abilities / outpost
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W20-D dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named plate: Outpost_CaptureOutpost.cpp
// =============================================================================
//
// PURPOSE: Capture outpost for capturer root race.
// String:  "Invalid faction in CaptureOutpost = %d" @ 0x009dec4c
// Dual A/B: accept-with-gaps (W20-D)
// =============================================================================

#include <stdint.h>

extern int  Object_GetRootRaceId(void *objectBase);
extern void Outpost_CastSkillsForFaction(int factionIndex);
extern void Outpost_UpdateBeaconShareRatio(void);
extern void FUN_007a4480(int level, const char *fmt, ...);
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
extern int DAT_00d029f4, DAT_00d029f8, DAT_00d029e4, DAT_00d029e8;

void __thiscall FUN_006082e0(int param_1, int *param_2)
{
  unsigned char bVar1;
  int iVar2;
  int RVar3;
  float *pfVar4;
  int iVar5;
  uint32_t DVar6;
  int iVar7;
  float fVar8, fVar9, fVar10;
  int local_28;
  unsigned int uStack_24;
  float fStack_20;
  uint32_t uStack_1c, uStack_18, uStack_14;

  iVar7 = 0;
  local_28 = 3;
  if ((param_2 != (int *)0x0) &&
      (iVar7 = (**(int (**)(int))(*param_2 + 0x210))(0), iVar7 != 0)) {
    local_28 = Object_GetRootRaceId(
        (void *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7));
  }
  iVar5 = *(int *)(param_1 + 0x234);
  if ((-1 < iVar5) && (iVar5 < 3)) {
    FUN_004cd5f0(iVar5);
  }
  if ((iVar7 != 0) &&
      (bVar1 = *(unsigned char *)(
           *(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) + 0x532),
       bVar1 < 3)) {
    FUN_004cd5d0(bVar1);
  }
  if ((local_28 != *(int *)(param_1 + 0x234)) && (*(int *)(param_1 + 0x248) != 0)) {
    if (((int)local_28 < 0) || (3 < (int)local_28)) {
      FUN_007a4480(0, "Invalid faction in CaptureOutpost = %d", local_28);
    }
    else {
      FUN_005743e0(0, 0, 0);
      if (iVar7 != 0) {
        iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4);
        fStack_20 = *(float *)(iVar5 + 0x164 + iVar7);
        uStack_1c = *(uint32_t *)(iVar5 + 0x168 + iVar7);
        FUN_00418d70(&fStack_20);
        fStack_20 = *(float *)(param_1 + 0x218) * *(float *)(param_1 + 0x218);
        uStack_24 = 0;
        while (1) {
          iVar5 = *(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xa8 + iVar7);
          iVar2 = *(int *)(iVar5 + 0xe75c);
          if ((iVar2 == 0) ||
              ((unsigned int)(*(int *)(iVar5 + 0xe760) - iVar2 >> 2) <= uStack_24))
            break;
          iVar5 = *(int *)(iVar2 + uStack_24 * 4);
          if ((iVar5 != iVar7) &&
              (RVar3 = Object_GetRootRaceId(
                   (void *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5)),
               RVar3 == local_28)) {
            pfVar4 = (float *)(**(int (**)(void))(
                *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1a0))();
            iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
            fVar10 = pfVar4[2] - *(float *)(iVar2 + 0x8c + param_1);
            fVar9  = pfVar4[1] - *(float *)(iVar2 + 0x88 + param_1);
            fVar8  = *pfVar4     - *(float *)(iVar2 + 0x84 + param_1);
            if (fVar10 * fVar10 + fVar9 * fVar9 + fVar8 * fVar8 < fStack_20) {
              iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);
              uStack_18 = *(uint32_t *)(iVar2 + 0x164 + iVar5);
              uStack_14 = *(uint32_t *)(iVar2 + 0x168 + iVar5);
              FUN_00418d70(&uStack_18);
            }
          }
          uStack_24 = uStack_24 + 1;
        }
      }
      if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0x7e) !=
          '\0') {
        FUN_00606820(*(uint32_t *)(param_1 + 0x234));
        FUN_00606890(*(uint32_t *)(param_1 + 0x234));
        FUN_00606ff0(*(uint32_t *)(param_1 + 0x234));
        FUN_00606900(local_28);
        FUN_00606a00(local_28);
        Outpost_CastSkillsForFaction(local_28);
        if (iVar7 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;
        }
        FUN_00606a70(local_28, iVar5);
        *(int *)(param_1 + 0x234) = local_28;
        Outpost_UpdateBeaconShareRatio();
        iVar5 = DAT_00d029f4;
        iVar2 = DAT_00d029f8;
        if (*(char *)(param_1 + 0x220) != '\0') {
          iVar5 = DAT_00d029e4;
          iVar2 = DAT_00d029e8;
        }
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = iVar2 - iVar5 >> 4;
        }
        *(int *)(param_1 + 0x238) = iVar5;
        *(uint32_t *)(param_1 + 0x23c) = 0;
        fStack_20 = FUN_00607550();
        iVar5 = *(int *)(param_1 + 0x248);
        DVar6 = GetTickCount();
        *(float *)(iVar5 + 8) = fStack_20;
        *(uint32_t *)(iVar5 + 0x14) = DVar6;
        FUN_006081b0(iVar7);
        return;
      }
    }
  }
  return;
}
