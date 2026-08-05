// =============================================================================
// FUN_00439770  —  alias plate for RbTree_AllocEmptyNode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00439770
// Address:   0x00439770  (autoassault.exe, image base 0x400000)
// Prefer:    RbTree_AllocEmptyNode_Inferred.cpp  (W18-S dual seal 2026-07-29)
// Exactness: Behavior-preserving. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *operator_new(unsigned int size);

// Decompiler prints void; callers use EAX return.
extern "C" void *FUN_00439770(void)
{
  std::uint32_t *puVar1 = static_cast<std::uint32_t *>(operator_new(0x18));

  if (puVar1 != nullptr) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != nullptr) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != nullptr) {
    puVar1[2] = 0;
  }
  *reinterpret_cast<std::uint8_t *>(puVar1 + 5) = 1;                 // +0x14
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(puVar1) + 0x15) = 0;

  return puVar1;
}
