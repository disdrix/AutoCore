// =============================================================================
// CVOGCharacter_SetMissionCounterMax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ade0
// Address:   0x0052ade0–0x0052ae21 inclusive (66 B / 0x42); pad CC
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0052ade0
// System:    missions-progression (Val12 map @ char+0x584) — mission-adjacent
// Dual:      2026-08-04 W37-P OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Character*; stack = (key, value); void; ret 8
//
// CF (machine-sealed):
//   1. node = lower_bound(map=char+0x584, key) via FUN_00418b80
//   2. if node == *(char+0x588): return          // miss: NO insert
//   3. *(node+0x10) = value
//   4. if *(node+0x14) < value: *(node+0x10) = *(node+0x14)  // clamp
//   5. *(char+0x634) |= 0x40                     // dirty
//
// Contrast:
//   SetMissionCounter (005305b0): hit assigns +0x14; miss inserts {0,value}
//   AddMissionCounter (00530610): hit += +0x14; ret 0xC
//   GetResourceBalance (0052ada0): returns +0x10 or -1 on miss
//
// Name "Max" inferred from debug slash help "set max as well" (W31-T).

#include <stdint.h>

extern "C" void __thiscall FUN_00418b80(int map, int *outNode, uint32_t *key);

extern "C" void __thiscall CVOGCharacter_SetMissionCounterMax_Inferred(
    int character /*ECX*/,
    uint32_t key,
    int32_t value)
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
