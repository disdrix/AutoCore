// =============================================================================
// CVOGHBAI_ProfileType4_DoLogic_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Per-tick combat logic for HBAI subclass with vtbl PTR_FUN_009db08c
//           (factory profile type word == 4). Profile map lower_bound, clear
//           owner+0x278, binary branch on owner+0x26c with skill sets 0/2,
//           aim-offset update, busy/path gates, pursue, and vtbl tails.
//           Structural twin of CVOGHBAIDriver_DoLogic / CreatureBase_DoLogic
//           (simpler binary state; no engage middle state; no FireWeapons).
//
// Address:  0x005d7ca0  (autoassault.exe, image base 0x400000)
// Body:     0x005d7ca0 – 0x005d7dd0 (305 B)
// Stable:   aa_005d7ca0
// System:   npc-ai / HBAI / profile-type-4
// Ghidra:   FUN_005d7ca0
// Vtbl:     DATA @ 0x009db0dc (slot +0x50 of PTR_FUN_009db08c)
//
// Convention: MSVC __thiscall
//   this  HBAI* (owner object at this+0x64)
//   void  bare ret
//
// Dual A/B: 2026-07-29 W27-I accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

extern void *DAT_00b041fc;

extern uint32_t __thiscall Host_AIProfileMap_GetOrReset(void *host, char forceReset); // FUN_00540890
extern void __thiscall Map_LowerBoundFindByIntKey_Isnil65(void *map, int **pOutIt, uint32_t *pKey); // FUN_004cbd50
extern void __thiscall FUN_004c3c80(void *owner, char mode); // clear +0x278 when mode==0
extern void NPC_TryCastSkillFromSet(void *self, int setIndex);
extern void CVOGHBAI_UpdateAimOffset_Inferred(void); // FUN_005cedf0
extern char FUN_005cc980(void);
extern char FUN_005cebd0(int arg);
extern void FUN_005cf560(void); // DoCreaturePursue twin
extern void FUN_005cc450(void);

void __thiscall CVOGHBAI_ProfileType4_DoLogic_Inferred(int *self)
{
  char cBusy;
  int map;
  uint32_t uTmp;
  int *it;
  uint32_t *pKey;
  uint32_t local_key;
  int local_it;

  local_key = *(uint32_t *)(
      *(int *)(*(int *)(*(int *)(*(int *)(self[0x19] + 4) + 4) + 0xac + self[0x19]) + 0x3c) +
      0x4dc);
  pKey = &local_key;
  it = &local_it;

  Host_AIProfileMap_GetOrReset(DAT_00b041fc, 0);
  Map_LowerBoundFindByIntKey_Isnil65(/*map*/, &it, pKey);
  map = (int)Host_AIProfileMap_GetOrReset(DAT_00b041fc, 0);
  if (local_it == *(int *)(map + 4)) {
    return;
  }

  FUN_004c3c80((void *)self[0x19], 0);

  if (*(char *)(self[0x19] + 0x26c) == 0) {
    NPC_TryCastSkillFromSet(self, 0);
    CVOGHBAI_UpdateAimOffset_Inferred();
    if ((char)self[0x18] == 0) {
      cBusy = FUN_005cc980();
      if (cBusy != 0) {
        return;
      }
      ((void(__thiscall *)(int *))(*(uint32_t *)(*self + 0x1c)))(self);
      if (*(int *)(self[6] + 0xa0) != 0) {
        ((void(__thiscall *)(int *, int))(*(uint32_t *)(*self + 0x2c)))(self, 2);
      }
      cBusy = FUN_005cebd0(0);
      if (cBusy != 0) {
        return;
      }
      uTmp = ((uint32_t(__thiscall *)(int, int))(*(uint32_t *)(*(int *)self[6] + 0x1a0)))(
          self[6], 0);
      ((void(__thiscall *)(int *, uint32_t))(*(uint32_t *)(*self + 0x4c)))(self, uTmp);
      return;
    }
  } else {
    NPC_TryCastSkillFromSet(self, 2);
    CVOGHBAI_UpdateAimOffset_Inferred();
    if ((char)self[0x18] == 0) {
      cBusy = FUN_005cc980();
      if (cBusy != 0) {
        return;
      }
      if (*(int *)(self[6] + 0xa0) != 0) {
        FUN_005cf560();
      }
      if (*(int *)(self[6] + 0xa0) != 0) {
        return;
      }
      ((void(__thiscall *)(int *, int))(*(uint32_t *)(*self + 0x2c)))(self, 0);
      return;
    }
  }
  FUN_005cc450();
}
