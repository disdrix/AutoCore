// =============================================================================
// CVOGCharacter_SetMissionCounter
// -----------------------------------------------------------------------------
// Stable ID: aa_005305b0
// Address:   0x005305b0–0x00530603 (83 B / 0x53); ret 8
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_005305b0
// System:    missions-progression (Val12 map @ char+0x584)
// Dual:      2026-07-29 W30-I OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Character*; stack = (key, value); void; ret 8
//
// CF (machine-sealed):
//   1. find = FUN_00418b80(map=char+0x584, &node, &key)
//   2. if node == *(char+0x588):  // miss / end
//        mapped = FUN_0053af20(map, &key)   // operator[] get-or-insert
//        mapped[0] = 0; mapped[1] = value   // node+0x10 / +0x14
//   3. else:
//        *(node+0x14) = value               // absolute set (not +=)
//
// Sibling: CVOGCharacter_AddMissionCounter (0x00530610) hit += at +0x14; ret 0xC
// Get:     CVOGCharacter_GetResourceBalanceByType (0x0052ada0) reads +0x10
// Nested:  FUN_00418b80 find; StdTree_OperatorIndex_Val12 (0x0053af20, W29-Q)

#include <stdint.h>

// Nested (not dual-sealed here)
extern "C" void __thiscall FUN_00418b80(int map, int *outNode, uint32_t *key);
extern "C" uint32_t *__thiscall FUN_0053af20(int map, uint32_t *key);

extern "C" void __thiscall CVOGCharacter_SetMissionCounter(
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
