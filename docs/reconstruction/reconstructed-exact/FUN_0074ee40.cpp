// =============================================================================
// FUN_0074ee40  (scaffold twin of AnimSlot_BindResourceFromPath)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ee40
// Address:   0x0074ee40  (autoassault.exe, image base 0x400000)
// System:    client::anim / ND resource bind
// Generated: 2026-07-29 W24-S dual A/B (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named plate: reconstructed-exact/AnimSlot_BindResourceFromPath.cpp
// =============================================================================

#include <cstdint>

extern "C" void* DAT_00d1f050;
extern "C" uint32_t /* width from decompiler */ FUN_00449070(void);
extern "C" int* NDResourceCache_LookupOrCreate(void*, void*, uint32_t, int, int);
extern "C" int NDResource_AcquireInnerObject(void /*ECX*/);
extern "C" int FUN_00963950(int);
extern "C" void FUN_0074eaa0(void);

uint32_t __thiscall FUN_0074ee40(int param_1, uint32_t param_2)
{
  char cVar1;
  uint32_t uVar2;
  int* piVar3;
  int iVar4;

  uVar2 = FUN_00449070();
  piVar3 = (int*)NDResourceCache_LookupOrCreate(DAT_00d1f050, (void*)(uintptr_t)param_2, uVar2, 0, 0);
  *(int**)(param_1 + 0x70) = piVar3;
  if (piVar3 != nullptr) {
    cVar1 = (**(code**)(*piVar3 + 4))();
    iVar4 = NDResource_AcquireInnerObject();
    *(int*)(param_1 + 0x74) = iVar4;
    if ((iVar4 != 0) && (iVar4 = FUN_00963950(iVar4), iVar4 != -1)) {
      FUN_0074eaa0();
      return (uint32_t)(cVar1 != '\0');
    }
  }
  return 0xFFFFFFFFu;
}
