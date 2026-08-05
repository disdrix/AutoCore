// =============================================================================
// FUN_004b7330  (twin: NDSpecialFX_LivenessDone_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7330
// Address:   0x004b7330 – 0x004b73bc  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W26-H dual seal (decompile + read_memory)
// Exactness: Line-faithful decompiler mirror. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Leaf liveness probe. ECX = fx host; AL 0|1; plain RET.
// Sole caller: NDSpecialFX_HostTick_Inferred (FUN_004b8ed0) @ 0x004b8f55.

uint8_t __fastcall FUN_004b7330(int param_1)
{
  uint32_t *puVar1;
  int *piVar2;
  uint8_t uVar3;
  int *piVar4;

  if ((((*(char *)(param_1 + 10) == '\0') && (*(char *)(param_1 + 9) == '\0')) &&
      (*(int *)(param_1 + 0x1e4) == 0)) && (*(int *)(param_1 + 0x214) == 0)) {
    for (puVar1 = (uint32_t *)**(uint32_t **)(param_1 + 0x204);
        puVar1 != *(uint32_t **)(param_1 + 0x204); puVar1 = (uint32_t *)*puVar1) {
      if (*(char *)(puVar1[2] + 0x795) == '\0') {
        return 0;
      }
    }
    uVar3 = 1;
    if (((*(int *)(param_1 + 0x1f0) != 0) && (*(char *)(param_1 + 6) == '\0')) &&
       ((*(char *)(param_1 + 7) == '\0' && (*(char *)(param_1 + 8) == '\0')))) {
      piVar2 = *(int **)(param_1 + 0x1ec);
      piVar4 = (int *)*piVar2;
      if (piVar4 != piVar2) {
        while (*(char *)(piVar4[2] + 0x10b) == '\0') {
          piVar4 = (int *)*piVar4;
          if (piVar4 == piVar2) {
            return uVar3;
          }
        }
        uVar3 = 0;
      }
    }
    return uVar3;
  }
  return 0;
}
