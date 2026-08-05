// =============================================================================
// FUN_0051e3d0  (scaffold alias → CNDHash_Insert_009ce0a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e3d0
// Address:   0x0051e3d0  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash insert family (node vtbl 0x009ce0a0)
// Generated: 2026-07-23 scaffold; W21-D dual A/B 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: CNDHash_Insert_009ce0a0.cpp
// =============================================================================

#include <stdint.h>

extern void * __thiscall CNDHash_LookupByKey(void *self, uint32_t key);
extern void * __thiscall FUN_0053ada0(void);
extern void FUN_00537d30(void);
extern void FUN_007a4480(int severity, const char *fmt, ...);
extern uint32_t PTR_FUN_009ce0a0;

// Scaffold name retained for Ghidra symbol parity.
// Structural: CNDHash_Insert_009ce0a0 — soft-skip-if-exists insert; ret 0xC.

uint32_t __thiscall FUN_0051e3d0(void *param_1, uint32_t param_2, int param_3, char param_4)
{
  int iVar1;
  void *pvVar2;
  uint32_t *puVar3;

  if (param_3 == 0) {
    return 0x80004003;
  }
  if (*(char *)((int)param_1 + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:insert, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (param_4 != 0) {
    pvVar2 = CNDHash_LookupByKey(param_1, param_2);
    if (pvVar2 != 0) {
      return 1;
    }
  }
  pvVar2 = CNDHash_LookupByKey(param_1, param_2);
  if (pvVar2 != 0) {
    FUN_007a4480(0, "Duplicate hash insert %u, failing out", param_2);
    return 0x80004005;
  }
  puVar3 = (uint32_t *)FUN_0053ada0();
  puVar3[3] = 0;
  *puVar3 = (uint32_t)&PTR_FUN_009ce0a0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  *(uint8_t *)(puVar3 + 1) = 0;
  puVar3[2] = (uint32_t)param_3;
  puVar3[4] = param_2;
  iVar1 = *(int *)(*(int *)((int)param_1 + 0x10)
                   + (*(uint32_t *)((int)param_1 + 8) & param_2) * 4);
  puVar3[3] = *(uint32_t *)(iVar1 + 4);
  *(uint32_t **)(iVar1 + 4) = puVar3;
  FUN_00537d30();
  if (*(int *)((int)param_1 + 0x18) != 0) {
    *(uint32_t **)(*(int *)((int)param_1 + 0x18) + 0x14) = puVar3;
    puVar3[5] = 0;
    puVar3[6] = *(uint32_t *)((int)param_1 + 0x18);
    *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;
    *(uint32_t **)((int)param_1 + 0x18) = puVar3;
    return 0;
  }
  *(uint32_t **)((int)param_1 + 0x18) = puVar3;
  *(uint32_t **)((int)param_1 + 0x14) = puVar3;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;
  return 0;
}
