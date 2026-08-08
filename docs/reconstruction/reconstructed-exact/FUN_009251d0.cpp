// =============================================================================
// FUN_009251d0  (scaffold twin of Client_InteractClickPickDispatch_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009251d0
// Address:   0x009251d0–0x009253d6 inclusive (519 B)
// System:    interaction-activation
// Generated: 2026-07-23 scaffold; R11-038 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Prefer named clean: Client_InteractClickPickDispatch_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Virtual click entry → gates → Client_InteractClickPickTarget soft/commit.
// Install: client vtable @ 0x00a2f41c. Sibling hub Client_InteractWorldClickHub @ 0x00a2f420.
// ABI: thiscall ECX=client*; stack (arg1, packedMouse); RET 8; AL bool.
// Dual: reviews/A|B_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md

#include <cstdint>

extern std::uint32_t Client_InteractClickPickTarget(
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
extern void FUN_0093bac0(void*, int); // Client_PromptSkillTargetSelect
extern void FUN_007fb990(void);
extern char FUN_00914be0(void);
extern void CVOGHBBase_Start(void*);

extern int DAT_00d1b644;
extern int DAT_00d1d900;
extern int DAT_00d1b6d8;
extern int* DAT_00d1b958;
extern int* DAT_00d1b95c;
extern int* DAT_00d1b898;
extern int* DAT_00d1b89c;
extern int* DAT_00d1b894;
extern int* DAT_00d1b888;
extern int* DAT_00d1b88c;
extern unsigned char DAT_00d1a859;
extern unsigned char DAT_00d1a860;
extern unsigned char DAT_00d1b205;
extern int DAT_00d1a840;

std::uint32_t __thiscall FUN_009251d0(int* param_1, std::uint32_t param_2, std::uint32_t param_3)
{
  char cVar1;
  char cVar2;
  std::uint32_t uVar3;

  if (((param_1[0x331] == 6) && (*(char*)((int)param_1 + 0x493) == '\0')) &&
      (*(char*)(DAT_00d1b644 + 0xf5) == '\0')) {
    return 0;
  }
  (**(code**)(*param_1 + 0x3bc))(param_1[0x12e]);
  (**(code**)(*param_1 + 0x42c))(
      param_1[0x12e], (int)(short)param_3, (int)(short)((unsigned)param_3 >> 0x10));
  if (((int*)param_1[0x12e] != (int*)0x0) &&
      (cVar1 = (**(code**)(*(int*)param_1[0x12e] + 0x378))(param_2, param_3), cVar1 != '\0')) {
    return 1;
  }
  if (DAT_00d1d900 != -1) {
    FUN_0093bac0(&DAT_00d1a840, 0);
    FUN_007fb990();
    return 1;
  }
  if (DAT_00d1b6d8 == 0) {
    return 0;
  }
  cVar1 = (**(code**)(*(int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x194))();
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = (**(code**)(*DAT_00d1b958 + 0x3d8))();
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = (**(code**)(*DAT_00d1b95c + 0x3d8))();
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = FUN_00914be0();
  if ((((((cVar1 == '\0') || (*(int*)(DAT_00d1b6d8 + 0xcd0) != 0)) ||
         ((DAT_00d1b898 != (int*)0x0 &&
           (cVar2 = (**(code**)(*DAT_00d1b898 + 0x3d8))(), cVar2 != '\0')))) ||
        ((DAT_00d1b89c != (int*)0x0 &&
          (cVar2 = (**(code**)(*DAT_00d1b89c + 0x3d8))(), cVar2 != '\0')))) ||
       ((DAT_00d1b894 != (int*)0x0 &&
         (cVar2 = (**(code**)(*DAT_00d1b894 + 0x3d8))(), cVar2 != '\0')))) ||
      (((DAT_00d1b888 != (int*)0x0 &&
         (cVar2 = (**(code**)(*DAT_00d1b888 + 0x3d8))(), cVar2 != '\0')) ||
        ((DAT_00d1b88c != (int*)0x0 &&
          (cVar2 = (**(code**)(*DAT_00d1b88c + 0x3d8))(), cVar2 != '\0')))))) {
    DAT_00d1a859 = 0;
  } else {
    DAT_00d1a859 = 1;
  }
  if (DAT_00d1a860 != '\0') {
    Client_InteractClickPickTarget(param_2, param_3, 0, DAT_00d1b205);
    if ((param_1[0x31c] != 0) && (cVar1 != '\0')) {
      *(std::uint8_t*)((int)param_1 + 0xa35) = 1;
      CVOGHBBase_Start((void*)param_1[0x31c]);
    }
    return 0;
  }
  uVar3 = Client_InteractClickPickTarget(param_2, param_3, 1, DAT_00d1b205);
  return uVar3;
}
