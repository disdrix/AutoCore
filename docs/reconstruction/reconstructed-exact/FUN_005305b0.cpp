// =============================================================================
// FUN_005305b0  (twin of CVOGCharacter_SetMissionCounter)
// -----------------------------------------------------------------------------
// Stable ID: aa_005305b0
// Address:   0x005305b0–0x00530603 (83 B / 0x53); ret 8
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression
// Dual:      2026-07-29 W30-I OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern "C" void __thiscall FUN_00418b80(int map, int *outNode, uint32_t *key);
extern "C" uint32_t *__thiscall FUN_0053af20(int map, uint32_t *key);

// Ghidra surface name; preferred: CVOGCharacter_SetMissionCounter
extern "C" void __thiscall FUN_005305b0(
    int character /*ECX*/,
    uint32_t key,
    int32_t value)
{
  int node = character;
  int map = character + 0x584;

  FUN_00418b80(map, &node, &key);

  if (node == *(int *)(character + 0x588)) {
    uint32_t *mapped = FUN_0053af20(map, &key);
    mapped[0] = 0;
    mapped[1] = (uint32_t)value;
    return;
  }

  *(int32_t *)(node + 0x14) = value;
}
