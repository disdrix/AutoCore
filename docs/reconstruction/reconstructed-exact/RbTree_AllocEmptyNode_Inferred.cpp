// =============================================================================
// RbTree_AllocEmptyNode_Inferred  (FUN_00439770)
// -----------------------------------------------------------------------------
// Stable ID: aa_00439770
// Address:   0x00439770  (autoassault.exe, image base 0x400000)
// Body:      0x00439770 – 0x004397a6
// System:    containers / RB-tree sentinel factory
// Generated: 2026-07-29 W18-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   operator_new(0x18) a tree node; zero links at +0/+4/+8; seed flags
//   +0x14=1, +0x15=0; return node* in EAX.
//   Does not self-link or set size — callers (e.g. FUN_004e7450) complete
//   empty-tree header setup (+0x15=1, left/parent/right = self, size=0).
//
// ABI
//   cdecl, no args. Return: node pointer in EAX (decompiler often shows void).
//
// READABILITY CF:
//   - push 0x18 → operator_new → optional zero of three dwords → two flag bytes → ret
//   - Callee: operator_new only
//

#include <cstdint>

// Ghidra: FUN_00439770 / operator_new
extern "C" void *operator_new(unsigned int size);

extern "C" void *RbTree_AllocEmptyNode_Inferred(void)
{
  std::uint32_t *node = static_cast<std::uint32_t *>(operator_new(0x18));

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
    *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x14) = 1;
    *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x15) = 0;
  }

  return node;
}

// Also available under historical scaffold name FUN_00439770 (same VA).
