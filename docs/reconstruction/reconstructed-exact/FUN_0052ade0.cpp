// =============================================================================
// CVOGCharacter_SetMissionCounterMax_Inferred  (clean twin of FUN_0052ade0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ade0
// Address:   0x0052ade0–0x0052ae21 (66 B / 0x42); ret 8
// Dual:      2026-08-04 W37-P OWN-ONLY
// =============================================================================

#include <stdint.h>

extern "C" void __thiscall FUN_00418b80(int map, int *outNode, uint32_t *key);

extern "C" void __thiscall FUN_0052ade0(int character, uint32_t key, int32_t value)
{
  int node = character;

  FUN_00418b80(character + 0x584, &node, &key);

  if (node == *(int *)(character + 0x588))
    return;

  *(int32_t *)(node + 0x10) = value;
  if (*(int32_t *)(node + 0x14) < value)
    *(int32_t *)(node + 0x10) = *(int32_t *)(node + 0x14);

  *(uint32_t *)(character + 0x634) |= 0x40u;
}
