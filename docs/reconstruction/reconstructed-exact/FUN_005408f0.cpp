// =============================================================================
// FUN_005408f0  (scaffold alias → FxCache_EnsureMasterAndResolve)
// -----------------------------------------------------------------------------
// Stable ID: aa_005408f0
// Address:   0x005408f0  (autoassault.exe, image base 0x400000)
// System:    client-fx / skills-abilities
// Generated: 2026-07-29 W20-I dual A/B (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer clean: reconstructed-exact/FxCache_EnsureMasterAndResolve.cpp
// Ghidra name retained for xref continuity.
// =============================================================================

#include <cstdint>

extern "C" uint32_t FUN_0054b480(/* leaf SkillDefMap_GetGlobal — decompiler may invent args */);
extern "C" void FUN_00418890(void* outIt, void* pKey);
extern "C" void FUN_00540090(int nameSrc, uint8_t* dst, uint32_t cap);
extern "C" uint32_t FUN_004a6390(uint8_t* scriptBaseName);
extern "C" uint32_t FUN_004a16d0(uint32_t a, uint32_t b, int c);

// Decompiler-shaped body (authoritative CF from raw aa_005408f0).
uint32_t __thiscall FUN_005408f0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
  uint32_t uVar1;
  int iVar2;
  int* piVar3;
  uint32_t* puVar4;
  int local_404;
  uint8_t local_400[1024];

  iVar2 = *(int*)(*(int*)(*(int*)(*(int*)(param_1 + 0xf0c) + 0x10) +
                          (*(uint32_t*)(*(int*)(param_1 + 0xf0c) + 8) & param_2) * 4) + 4);
  if (iVar2 == 0) {
LAB_00540927:
    iVar2 = 0;
  } else {
    do {
      if (param_2 == *(uint32_t*)(iVar2 + 0x10)) {
        if (iVar2 == 0) goto LAB_00540927;
        iVar2 = *(int*)(iVar2 + 8);
        goto LAB_0054092e;
      }
      iVar2 = *(int*)(iVar2 + 0xc);
    } while (iVar2 != 0);
    iVar2 = 0;
  }
LAB_0054092e:
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char*)(iVar2 + 10) == '\0') {
    puVar4 = &param_2;
    piVar3 = &local_404;
    FUN_0054b480();
    FUN_00418890(piVar3, puVar4);
    iVar2 = (int)FUN_0054b480();
    if (local_404 != *(int*)(iVar2 + 4)) {
      FUN_00540090(local_404 + 0x10, local_400, 0x400);
      FUN_004a6390(local_400);
    }
  }
  uVar1 = FUN_004a16d0(param_3, param_4, 0xffffffff);
  return uVar1;
}
