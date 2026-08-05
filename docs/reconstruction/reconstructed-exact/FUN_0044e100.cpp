// =============================================================================
// FUN_0044e100  (scaffold twin of RbTree_AllocEmptyNode_0x30)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e100
// Address:   0x0044e100  (autoassault.exe, image base 0x400000)
// Body:      0x0044e100 – 0x0044e136
// System:    containers / RB-tree
// Generated: 2026-07-29 W21-O dual seal
// Exactness: Behavior-preserving. Prefer named clean
//            RbTree_AllocEmptyNode_0x30.cpp for port contracts.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *operator_new(unsigned int size);

// Machine returns node* in EAX; decompiler surface was void.
extern "C" void *FUN_0044e100(void)
{
  std::uint32_t *puVar1 = static_cast<std::uint32_t *>(operator_new(0x30));

  if (puVar1 != nullptr) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != nullptr) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != nullptr) {
    puVar1[2] = 0;
  }

  if (puVar1 != nullptr) {
    *reinterpret_cast<std::uint8_t *>(puVar1 + 0xb) = 1;              // +0x2c
    *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(puVar1) + 0x2d) = 0;
  }

  return puVar1;
}
