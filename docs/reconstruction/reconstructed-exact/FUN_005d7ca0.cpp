// =============================================================================
// FUN_005d7ca0  (scaffold twin of CVOGHBAI_ProfileType4_DoLogic_Inferred)
// Stable ID: aa_005d7ca0
// Address:   0x005d7ca0
// Prefer:    CVOGHBAI_ProfileType4_DoLogic_Inferred.cpp
// W27-I:     2026-07-29 live re-verify; clean CF ≡ raw; uint32_t for undefined4.
// =============================================================================

#include <stdint.h>

extern int FUN_00540890(char);
extern void FUN_004cbd50(int *, uint32_t *);
extern void FUN_004c3c80(char);
extern void NPC_TryCastSkillFromSet(int *, int);
extern void FUN_005cedf0(void);
extern char FUN_005cc980(void);
extern char FUN_005cebd0(int);
extern void FUN_005cf560(void);
extern void FUN_005cc450(void);

void __fastcall FUN_005d7ca0(int *param_1)
{
  char cVar1;
  int iVar2;
  uint32_t uVar3;
  int *piVar4;
  uint32_t *puVar5;
  uint32_t local_8;
  int local_4;

  puVar5 = &local_8;
  local_8 = *(uint32_t *)(
      *(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac + param_1[0x19]) + 0x3c) +
      0x4dc);
  piVar4 = &local_4;
  FUN_00540890(0);
  FUN_004cbd50(piVar4, puVar5);
  iVar2 = FUN_00540890(0);
  if (local_4 == *(int *)(iVar2 + 4)) {
    return;
  }
  FUN_004c3c80(0);
  if (*(char *)(param_1[0x19] + 0x26c) == 0) {
    NPC_TryCastSkillFromSet(param_1, 0);
    FUN_005cedf0();
    if ((char)param_1[0x18] == 0) {
      cVar1 = FUN_005cc980();
      if (cVar1 != 0) {
        return;
      }
      ((void(*)(void))(*(uint32_t *)(*param_1 + 0x1c)))();
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        ((void(*)(int))(*(uint32_t *)(*param_1 + 0x2c)))(2);
      }
      cVar1 = FUN_005cebd0(0);
      if (cVar1 != 0) {
        return;
      }
      iVar2 = *param_1;
      uVar3 = ((uint32_t(*)(int))(*(uint32_t *)(*(int *)param_1[6] + 0x1a0)))(0);
      ((void(*)(uint32_t))(*(uint32_t *)(iVar2 + 0x4c)))(uVar3);
      return;
    }
  } else {
    NPC_TryCastSkillFromSet(param_1, 2);
    FUN_005cedf0();
    if ((char)param_1[0x18] == 0) {
      cVar1 = FUN_005cc980();
      if (cVar1 != 0) {
        return;
      }
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        FUN_005cf560();
      }
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        return;
      }
      ((void(*)(int))(*(uint32_t *)(*param_1 + 0x2c)))(0);
      return;
    }
  }
  FUN_005cc450();
  return;
}
