// =============================================================================
// FUN_00538a40 — Map find by signed int key (tree find)
// -----------------------------------------------------------------------------
// Stable ID: aa_00538a40
// Address:   0x00538a40  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B seal (raw CF 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler + body image.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   __thiscall leaf: exact-match find in an MSVC-style map/tree.
//   Domain callers pass the character mission-staging / reward-region map
//   (typically Character+0x508). This unit only walks nodes and writes *ppOut.
//
// ABI (sealed):
//   ECX      = map*
//   [ESP+4]  = Node** ppOut
//   [ESP+8]  = const int* pKey
//   return   = void  (*ppOut = matching node or head/end)
//   cleanup  = ret 8
//
// NODE (fields read by this function):
//   +0x00 left*, +0x04 parent*, +0x08 right*, +0x10 key (int32), +0x49 isnil
//
// CONTRACT:
//   Walk is lower_bound-shaped; final gate rejects first-greater, so public
//   contract is exact find (miss → head).
//
// Dual: reviews/A_aa_00538a40_Map_FindByIntKey.md
//       reviews/B_aa_00538a40_Map_FindByIntKey.md
// =============================================================================

#include <cstdint>

struct MapTreeNode {
  MapTreeNode *left;     // +0x00
  MapTreeNode *parent;   // +0x04
  MapTreeNode *right;    // +0x08
  std::uint32_t pad_0c;  // +0x0C (unread here; keeps key at +0x10)
  std::int32_t key;      // +0x10
  // value payload begins at +0x18 in sibling units (not accessed here)
  // char isnil at +0x49
};

struct MapHeader {
  std::uint32_t pad_00;  // +0x00 unread here
  MapTreeNode *head;     // +0x04  end sentinel / _Myhead
};

// isnil is at byte offset 0x49 from node base
static inline char node_isnil(const MapTreeNode *n) {
  return *reinterpret_cast<const char *>(reinterpret_cast<const char *>(n) + 0x49);
}

void __thiscall FUN_00538a40(MapHeader *map, MapTreeNode **ppOut, const std::int32_t *pKey)
{
  MapTreeNode *head = map->head;                 // *(map+4)
  MapTreeNode *candidate = head;
  MapTreeNode *node = head->parent;               // root

  if (node_isnil(node) == 0) {
    do {
      if (node->key < *pKey) {
        node = node->right;
      } else {
        candidate = node;
        node = node->left;
      }
    } while (node_isnil(node) == 0);
  }

  // Exact match only: (candidate != head) && !(*pKey < candidate->key)
  // Combined with lower_bound walk ⇒ candidate->key == *pKey on hit.
  if ((candidate != head) && (candidate->key <= *pKey)) {
    *ppOut = candidate;
    return;
  }

  *ppOut = head;
}
