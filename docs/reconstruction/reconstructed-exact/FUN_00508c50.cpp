// =============================================================================
// FUN_00508c50  (scaffold alias → HandlerTable58_FindById6c)
// -----------------------------------------------------------------------------
// Stable ID: aa_00508c50
// Address:   0x00508c50  (autoassault.exe, image base 0x400000)
// System:    status/hook handler table family (slot +0x58)
// Generated: 2026-07-23 scaffold; W21-D dual A/B 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: HandlerTable58_FindById6c.cpp
// =============================================================================

#include <stdint.h>

extern int32_t DAT_00d02984;

// Scaffold name retained for Ghidra symbol parity.
// Structural: HandlerTable58_FindById6c — table @ +0x58, id @ entry+0x6c, count DAT_00d02984.
// ABI: __thiscall ret 4; leaf.

void *__thiscall FUN_00508c50(void *param_1, int32_t param_2)
{
  int32_t iVar1;
  int32_t *piVar2;

  iVar1 = 0;
  if ((param_2 != -1) && (DAT_00d02984 > 0)) {
    piVar2 = *(int32_t **)((char *)param_1 + 0x58);
    do {
      if (*(int32_t *)((char *)(*piVar2) + 0x6c) == param_2) {
        return (*(void ***)((char *)param_1 + 0x58))[iVar1];
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < DAT_00d02984);
  }
  return 0;
}
