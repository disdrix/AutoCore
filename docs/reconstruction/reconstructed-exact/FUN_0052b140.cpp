// =============================================================================
// FUN_0052b140
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b140
// Address:   0x0052b140  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual re-seal 2026-08-05 R13-036
// Inferred:  CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NOT claimed.
// Dual:      A/B accept-with-gaps (dual start 2686). Terminal false.
// =============================================================================

// PURPOSE:
//   CVOGCharacter thiscall gate — meets Discipline learn requirements for id.
//   Map 0x00b045b0 / end DAT_00b045b4 / copy 0x1FC; level vtbl+0x27c vs +0x26;
//   OR of five prereq (id,thr) slots via FUN_0052b040 + FUN_0052ada0; all -1 pass.
// ABI: __thiscall ECX=this, stack0=id, RET 4, bool AL.

// Named clean twin:
//   CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.cpp

#include <stdint.h>

extern "C" int *FUN_00538ab0(void *outIt, int *key); // ECX = map 0x00b045b0
extern "C" char FUN_0052b040(int id, void *out0x1FC); // cdecl
extern "C" int FUN_0052ada0(int resourceTypeId);      // thiscall ECX=character
extern int DAT_00b045b4;

uint8_t /* bool AL */ __thiscall FUN_0052b140(int param_1 /* this */, int param_2 /* disciplineId */)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_410;
  int local_40c;
  int local_408[4];
  int iStack_3f8;
  int iStack_3f4;
  int iStack_3f0;
  short sStack_3ec;
  short sStack_3ea;
  short sStack_3e8;
  short sStack_3e6;
  short sStack_3e4;
  short sStack_3e2;
  uint8_t auStack_208[516];

  local_410 = param_2;
  // live: MOV ECX,0xb045b0 before CALL
  piVar2 = (int *)FUN_00538ab0(&local_40c, &local_410);
  if (*piVar2 != DAT_00b045b4) {
    iVar3 = *(int *)(param_1 + 4);
    piVar2 = (int *)(*piVar2 + 0x10);
    piVar5 = local_408;
    for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar5 = piVar5 + 1;
    }
    // nested vtbl +0x27c level-like
    iVar4 = (**(code **)(*(int *)(*(int *)(iVar3 + 4) + 4 + param_1) + 0x27c))();
    iVar3 = local_408[2];
    if ((sStack_3e2 <= iVar4) &&
       (((((local_408[2] != -1 && (cVar1 = FUN_0052b040(local_408[2], auStack_208), cVar1 != '\0'))
          && (iVar3 = FUN_0052ada0(iVar3), sStack_3ec <= iVar3)) ||
         ((((((iVar3 = local_408[3], local_408[3] != -1 &&
              (cVar1 = FUN_0052b040(local_408[3], auStack_208), cVar1 != '\0')) &&
             (iVar3 = FUN_0052ada0(iVar3), sStack_3ea <= iVar3)) ||
            (((iVar3 = iStack_3f8, iStack_3f8 != -1 &&
              (cVar1 = FUN_0052b040(iStack_3f8, auStack_208), cVar1 != '\0')) &&
             (iVar3 = FUN_0052ada0(iVar3), sStack_3e8 <= iVar3)))) ||
           (((iStack_3f4 != -1 && (cVar1 = FUN_0052b040(iStack_3f4, auStack_208), cVar1 != '\0')) &&
            (iVar3 = FUN_0052ada0(iStack_3f4), sStack_3e6 <= iVar3)))) ||
          (((iStack_3f0 != -1 && (cVar1 = FUN_0052b040(iStack_3f0, auStack_208), cVar1 != '\0')) &&
           (iVar3 = FUN_0052ada0(iStack_3f0), sStack_3e4 <= iVar3)))))) ||
        (((local_408[2] == -1 && (local_408[3] == -1)) &&
         ((iStack_3f8 == -1 && ((iStack_3f4 == -1 && (iStack_3f0 == -1)))))))))) {
      return 1;
    }
  }
  return 0;
}
