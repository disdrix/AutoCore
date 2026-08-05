// =============================================================================
// RbTree_AllocEmptyNode_0x30  (FUN_0044e100)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e100
// Address:   0x0044e100  (autoassault.exe, image base 0x400000)
// Body:      0x0044e100 – 0x0044e136
// System:    containers / RB-tree sentinel factory (0x30 node)
// Generated: 2026-07-29 W21-O dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   operator_new(0x30) a tree node; zero links at +0/+4/+8; seed flags
//   +0x2c=1, +0x2d=0; return node* in EAX.
//   Does not self-link or set size — callers (e.g. Profiler_Zone_Ctor) complete
//   empty-tree header setup (+0x2d=1, left/parent/right = self, size=0).
//
// ABI
//   cdecl, no args. Return: node pointer in EAX (decompiler often shows void).
//
// SIBLING
//   aa_00439770 RbTree_AllocEmptyNode_Inferred — same CF, size 0x18, flags at
//   +0x14/+0x15.
//

#include <cstdint>

// Ghidra: FUN_0044e100 / operator_new
extern "C" void *operator_new(unsigned int size);

extern "C" void *RbTree_AllocEmptyNode_0x30(void)
{
  std::uint32_t *node = static_cast<std::uint32_t *>(operator_new(0x30));

  if (node != nullptr) {
    node[0] = 0;
  }
  // Assembly always performs +4/+8 stores when the lea/test path runs.
  // For a non-null heap pointer both stores execute; match decompiler order:
  if (node + 1 != nullptr) {
    node[1] = 0;
  }
  if (node + 2 != nullptr) {
    node[2] = 0;
  }

  if (node != nullptr) {
    *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x2c) = 1;
    *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x2d) = 0;
  }

  return node;
}

// Historical scaffold name (same VA).
extern "C" void *FUN_0044e100(void)
{
  return RbTree_AllocEmptyNode_0x30();
}
