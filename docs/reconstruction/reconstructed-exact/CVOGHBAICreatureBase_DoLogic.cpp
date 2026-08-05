// =============================================================================
// CVOGHBAICreatureBase_DoLogic
// -----------------------------------------------------------------------------
// Purpose:  Main ground-creature HBAI combat tick. State machine on owner+0x26c
//           (0 idle / 1 engage / other combat): cast skill sets, slot timer,
//           leash/patrol helpers, HP-gated flee/promote, and creature pursue.
//           Structural twin of string-sealed CVOGHBAIDriver_DoLogic (no FireWeapons).
//
// Address:  0x005d7f70  (autoassault.exe, image base 0x400000)
// Body:     0x005d7f70 – 0x005d8328
// Stable:   aa_005d7f70
// System:   npc-ai / HBAI / creature
//
// Convention: MSVC __thiscall
//   this  CVOGHBAICreatureBase* (owner object chain at this+0x64 = index 0x19)
//   void  bare ret
//
// Key offsets (roles High from CF + Driver dual):
//   owner+0x26c  combat state byte (0 idle, 1 engage, else combat)
//   owner+0x279  one-shot face/path latch
//   owner+0x305  hard abort flag
//   this+0x18    path/mode byte (low)
//   this+0x2c    engage timer stamp (ms)
//   this+0x2d    engage attempt counter (byte)
//   this[6]+0xa0 target present gate
//
// Profile row (map lower_bound on def float +0x4dc via FUN_00540890/004cbd50):
//   [5] engage timeout, [6] HP promote, [7]/[10] combat RNG thresholds, [11] flee id
//
// Vtbl: DATA @ 0x009db19c; sibling slot 0x009db194 = DecideHeading (class string).
//
// Dual A/B: 2026-07-29 W25-J accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

extern uint32_t g_dwClientTickMs;
extern float DAT_00aaa638;  // ≈1/65536  (read_memory 80 00 80 37)
extern float _DAT_00aaa5dc; // 2^32       (read_memory 00 00 80 4f)

extern void NPC_TryCastSkillFromSet(void *self, int setIndex);
extern uint8_t __thiscall AI_CheckSlotTimerReady(void *self, uint32_t nSlotIndex);
extern int CVOGReaction_RandomUnitScalar(void);
extern void CVOGHBAICreatureBase_DoCreaturePursue(void *self); // FUN_005cf560

extern int FUN_00540890(char forceReset); // thiscall host = DAT_00b041fc
extern void FUN_004cbd50(int **outIt, float *key);
extern void FUN_005cedf0(void);
extern char FUN_005cc980(void);
extern char FUN_005cebd0(int arg);
extern void FUN_005cc450(void);
extern void FUN_005ccbd0(void);
extern void *FUN_0053e0b0(void);
extern char *FUN_00404e00(void *tmp);
extern void FUN_00638cd0(int fleeParam);

void __thiscall CVOGHBAICreatureBase_DoLogic(int *self)
{
  ushort uRand;
  float fElapsed;
  int *profile;
  char cBusy;
  int iTmp;
  uint32_t uReady;
  char *pcFlag;
  int *pHost;
  uint32_t *pPosDst;
  uint32_t *pPosSrc;
  int **ppiIt;
  uint32_t uArg;
  float *pfKey;
  float local_key;
  int *local_it;

  local_key = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(self[0x19] + 4) + 4) + 0xac +
                                           self[0x19]) +
                                  0x3c) +
                         0x4dc);
  pfKey = &local_key;
  ppiIt = &local_it;
  FUN_00540890(0);
  FUN_004cbd50(ppiIt, pfKey);
  iTmp = FUN_00540890(0);
  profile = local_it;
  if (local_it == *(int **)(iTmp + 4)) {
    return;
  }

  *(uint8_t *)(self[0x19] + 0x279) = 0;

  if (*(char *)(self[0x19] + 0x26c) == '\0') {
    // idle
    *(uint8_t *)(self + 0x2d) = 0;
    NPC_TryCastSkillFromSet(self, 0);
    uReady = AI_CheckSlotTimerReady(self, 0);
    if ((char)uReady != '\0') {
      (*(void (**)(void))(*self + 0x1c))();
    }
    if (*(int *)(self[6] + 0xa0) != 0) {
      (*(void (**)(int))(*self + 0x2c))(2);
    }
    if (*(char *)(self[0x19] + 0x305) != '\0') {
      return;
    }
    FUN_005cedf0();
    if ((char)self[0x18] == '\0') {
      cBusy = FUN_005cc980();
      if (cBusy != '\0') {
        return;
      }
      cBusy = FUN_005cebd0(0);
      if (cBusy != '\0') {
        return;
      }
      iTmp = self[0x19];
      if ((*(char *)(*(int *)(*(int *)(*(int *)(iTmp + 4) + 4) + 0xa8 + iTmp) + 0x7e) != '\0') &&
          (*(char *)(iTmp + 0x279) == '\0')) {
        pPosDst = (uint32_t *)FUN_0053e0b0();
        pPosSrc = (uint32_t *)(*(int (**)(void))(*(int *)self[6] + 0x1a0))();
        pPosDst[0] = pPosSrc[0];
        pPosDst[1] = pPosSrc[1];
        pPosDst[2] = pPosSrc[2];
        pPosDst[3] = pPosSrc[3];
        *(uint8_t *)(self[0x19] + 0x279) = 1;
      }
      iTmp = *self;
      uArg = (*(uint32_t(**)(int))(*(int *)self[6] + 0x1a0))(0);
      (*(void (**)(uint32_t))(iTmp + 0x4c))(uArg);
      return;
    }
    goto LAB_path_alt;
  }

  if (*(char *)(self[0x19] + 0x26c) != '\x01') {
    // combat
    NPC_TryCastSkillFromSet(self, 2);
    uReady = AI_CheckSlotTimerReady(self, 0);
    if ((char)uReady == '\0') {
      if (*(int *)(self[6] + 0xa0) == 0) {
        uArg = 0;
        goto LAB_set_state;
      }
    } else {
      pHost = (int *)self[6];
      local_it = pHost;
      iTmp = (*(int (**)(void))(*pHost + 0x1b0))();
      local_it = (int *)(float)iTmp;
      iTmp = (*(int (**)(void))(*pHost + 0x1ac))();
      local_key = (float)(int)local_it / (float)iTmp;

      iTmp = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iTmp + 0xc)) {
        *(uint32_t *)(iTmp + 0xc) = 0;
      }
      uRand = *(ushort *)(*(int *)(iTmp + 8) + *(int *)(iTmp + 0xc) * 2);
      *(int *)(iTmp + 0xc) = *(int *)(iTmp + 0xc) + 1;
      if (((float)uRand * DAT_00aaa638 < (float)profile[9]) &&
          (local_key <= (float)profile[10])) {
        FUN_00638cd0(profile[0xb]);
      }

      if ((*(int *)(self[0x19] + 8) != 0) &&
          (pcFlag = (char *)FUN_00404e00((void *)0), *pcFlag != '\0')) {
        iTmp = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iTmp + 0xc)) {
          *(uint32_t *)(iTmp + 0xc) = 0;
        }
        uRand = *(ushort *)(*(int *)(iTmp + 8) + *(int *)(iTmp + 0xc) * 2);
        *(int *)(iTmp + 0xc) = *(int *)(iTmp + 0xc) + 1;
        if (((float)uRand * DAT_00aaa638 <
             (float)profile[8] / (float)(*(uint8_t *)(self + 0x2d) + 1)) &&
            (local_key <= (float)profile[7])) {
          uArg = 1;
          goto LAB_set_state;
        }
      }
    }
    if (*(char *)(self[0x19] + 0x305) != '\0') {
      return;
    }
    FUN_005cedf0();
    if ((char)self[0x18] == '\0') {
      cBusy = FUN_005cc980();
      if (cBusy != '\0') {
        return;
      }
      cBusy = FUN_005cebd0(0);
      if (cBusy != '\0') {
        return;
      }
      if (*(int *)(self[6] + 0xa0) == 0) {
        return;
      }
      CVOGHBAICreatureBase_DoCreaturePursue(self);
      return;
    }
    goto LAB_path_alt;
  }

  // engage (state == 1)
  if (self[0x2c] == 0) {
    *(char *)(self + 0x2d) = (char)self[0x2d] + '\x01';
    self[0x2c] = (int)g_dwClientTickMs;
  }
  NPC_TryCastSkillFromSet(self, 1);
  pHost = (int *)(g_dwClientTickMs - self[0x2c]);
  fElapsed = (float)(int)pHost;
  if ((int)pHost < 0) {
    fElapsed = fElapsed + _DAT_00aaa5dc;
  }
  pfKey = (float *)(local_it /*profile*/ + 5);
  local_it = pHost;
  if (*pfKey < fElapsed) {
    goto LAB_engage_done;
  }
  pHost = (int *)self[6];
  local_it = pHost;
  iTmp = (*(int (**)(void))(*pHost + 0x1b0))();
  local_it = (int *)(float)iTmp;
  iTmp = (*(int (**)(void))(*pHost + 0x1ac))();
  if ((float)profile[6] <= (float)(int)local_it / (float)iTmp) {
    goto LAB_engage_done;
  }

  FUN_005cedf0();
  if ((char)self[0x18] == '\0') {
    cBusy = FUN_005cc980();
    if (cBusy != '\0') {
      return;
    }
    FUN_005ccbd0();
    return;
  }
  goto LAB_path_alt;

LAB_set_state:
  (*(void (**)(uint32_t))(*self + 0x2c))(uArg);
  if (*(char *)(self[0x19] + 0x305) != '\0') {
    return;
  }
  FUN_005cedf0();
  if ((char)self[0x18] == '\0') {
    cBusy = FUN_005cc980();
    if (cBusy != '\0') {
      return;
    }
    cBusy = FUN_005cebd0(0);
    if (cBusy != '\0') {
      return;
    }
    if (*(int *)(self[6] + 0xa0) == 0) {
      return;
    }
    CVOGHBAICreatureBase_DoCreaturePursue(self);
    return;
  }
  goto LAB_path_alt;

LAB_engage_done:
  self[0x2c] = 0;
  if (*(int *)(self[6] + 0xa0) == 0) {
    (*(void (**)(int))(*self + 0x2c))(0);
  } else {
    (*(void (**)(int))(*self + 0x2c))(2);
  }
  FUN_005cedf0();
  if ((char)self[0x18] == '\0') {
    cBusy = FUN_005cc980();
    if (cBusy != '\0') {
      return;
    }
    FUN_005ccbd0();
    return;
  }

LAB_path_alt:
  FUN_005cc450();
}
