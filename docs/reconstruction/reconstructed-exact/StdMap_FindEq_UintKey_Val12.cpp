// =============================================================================
// StdMap_FindEq_UintKey_Val12  (was FUN_0043d5e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d5e0
// Address:   0x0043d5e0  (autoassault.exe, image base 0x400000)
// Body:      0x0043d5e0–0x0043d63a exclusive (90 bytes / 0x5A)
// System:    STL / MSVC _Tree Val12 uint-key map
// Generated: 2026-08-04 W37-M dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Dual: reviews/A|B_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md
// =============================================================================

#include <cstdint>

// Val12 tree node (partial): isnil@+0x19, uint key@+0x0C, L/P/R @0/4/8.
struct StdTreeNode_Val12_UintKey {
  StdTreeNode_Val12_UintKey* left;    // +0x00
  StdTreeNode_Val12_UintKey* parent;  // +0x04
  StdTreeNode_Val12_UintKey* right;   // +0x08
  std::uint32_t key;                 // +0x0C
  // ... value / color ...
  // char isnil @ +0x19
};

struct StdMap_Val12_UintKey {
  void* _unused0;                    // +0x00 (comparator / pad — not read)
  StdTreeNode_Val12_UintKey* head;   // +0x04 sentinel
};

// Register ABI (bytes authority; not cdecl stack):
//   ECX = map*
//   EBX = const uint32_t* key
//   EAX = StdTreeNode_Val12_UintKey** out_it
//   plain RET (C3)
// Exact find: lower_bound walk + (cand != end && cand->key <= key).
void StdMap_FindEq_UintKey_Val12(
    StdMap_Val12_UintKey* map /*ECX*/,
    StdTreeNode_Val12_UintKey** out_it /*EAX*/,
    const std::uint32_t* key /*EBX*/)
{
  StdTreeNode_Val12_UintKey* head = map->head;
  StdTreeNode_Val12_UintKey* cand = head;
  StdTreeNode_Val12_UintKey* node = head->parent; // root

  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(node) + 0x19) == 0) {
    const std::uint32_t k = *key;
    do {
      if (node->key < k) {
        node = node->right;
      } else {
        cand = node;
        node = node->left;
      }
    } while (*reinterpret_cast<char*>(reinterpret_cast<char*>(node) + 0x19) == 0);
  }

  if (cand != head && cand->key <= *key) {
    *out_it = cand;
  } else {
    *out_it = head;
  }
}
