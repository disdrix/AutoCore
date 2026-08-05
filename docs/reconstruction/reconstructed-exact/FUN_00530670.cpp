// Twin of CVOGCharacter_TryClearMissionCounterIfPositive.cpp (Ghidra symbol name)
// Stable ID: aa_00530670  VA: 0x00530670
// See: reconstructed-exact/CVOGCharacter_TryClearMissionCounterIfPositive.cpp

#include <stdint.h>

extern "C" void __thiscall FUN_00418b80(int map, uint32_t *outNode, uint32_t *key);
extern "C" void __thiscall FUN_005305b0(int character, uint32_t key, int32_t value);

extern "C" uint8_t __thiscall FUN_00530670(int character /*ECX*/, uint32_t key)
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
