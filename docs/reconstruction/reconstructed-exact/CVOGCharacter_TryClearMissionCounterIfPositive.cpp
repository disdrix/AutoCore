// =============================================================================
// CVOGCharacter_TryClearMissionCounterIfPositive
// -----------------------------------------------------------------------------
// Stable ID: aa_00530670
// Address:   0x00530670–0x00530708 exclusive (152 B / 0x98); ret 4
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_00530670
// System:    missions-progression (Val12 map @ char+0x584)
// Dual:      2026-07-29 W31-S OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Character*; stack = (key); returns bool 0/1; ret 4
//
// CF (machine-sealed):
//   1. find = FUN_00418b80(map=char+0x584, &node, &key)
//   2. if node == *(char+0x588) OR *(node+0x14) <= 0: return 0
//   3. re-find same key
//   4. if still hit:
//        *(node+0x10) = 0
//        if *(node+0x14) < 0: *(node+0x10) = *(node+0x14)   // defensive
//        *(char+0x634) |= 0x40
//   5. CVOGCharacter_SetMissionCounter(key, 0)   // zeros +0x14
//   6. *(char+0x634) |= 0x40
//   7. return 1
//
// Family: Set 005305b0 (abs write +0x14); Add 00530610 (+= +0x14); Get 0052ada0 (read +0x10)
// Sole caller: FUN_00809dd0 packet success path (else "FAILED: Server reports failure.")

#include <stdint.h>

// Nested (sealed elsewhere)
extern "C" void __thiscall FUN_00418b80(int map, uint32_t *outNode, uint32_t *key);
extern "C" void __thiscall FUN_005305b0(int character /*ECX*/, uint32_t key, int32_t value);

extern "C" uint8_t __thiscall CVOGCharacter_TryClearMissionCounterIfPositive(
    int character /*ECX*/,
    uint32_t key)
{
  uint32_t saved_key = key;
  uint32_t node = static_cast<uint32_t>(character);
  int map = character + 0x584;

  FUN_00418b80(map, &node, &key);

  uint32_t head = *reinterpret_cast<uint32_t *>(character + 0x588);
  if (node == head || *reinterpret_cast<int32_t *>(node + 0x14) <= 0) {
    return 0;
  }

  key = saved_key;
  FUN_00418b80(map, &node, &key);

  if (node != head) {
    *reinterpret_cast<uint32_t *>(node + 0x10) = 0;
    if (*reinterpret_cast<int32_t *>(node + 0x14) < 0) {
      *reinterpret_cast<int32_t *>(node + 0x10) =
          *reinterpret_cast<int32_t *>(node + 0x14);
    }
    *reinterpret_cast<uint32_t *>(character + 0x634) |= 0x40u;
  }

  FUN_005305b0(character, saved_key, 0);
  *reinterpret_cast<uint32_t *>(character + 0x634) |= 0x40u;
  return 1;
}
