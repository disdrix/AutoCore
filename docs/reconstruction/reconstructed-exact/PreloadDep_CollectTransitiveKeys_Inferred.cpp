// =============================================================================
// PreloadDep_CollectTransitiveKeys_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00744360
// Address:   0x00744360–0x0074445c  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00744360
// System:    preload / asset dependency graph
// Dual:      W32-L 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX  = dependency-tree host (std tree at host+0x10; nil flag node+0x25)
//   stack = (const int* key, GuardedVectorHeader* out_ring)
//   RET 8; void
//
// For each map node in equal_range(key):
//   if ring already holds *node_key (dword scan, page-wrap): skip
//   else recurse(node_key, ring); GuardedVector_PushFront_Thiscall(ring, node_key)
//
// Name is structural (_Inferred). No plate string in body.
// Nested FUN_00426f60 / FUN_0044d960 not dual-owned here.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08
  uint32_t begin;     // +0x0c
  int32_t  size;      // +0x10
};

struct TreeNode {
  TreeNode* left;    // +0x00
  TreeNode* parent;  // +0x04
  TreeNode* right;   // +0x08
  // +0x0c..+0x14 value padding / color-adjacent
  // key dword at +0x18
  // is_nil at +0x25
};

// EAX-out: copy *key into iterator key view
extern "C" void __fastcall FUN_00426f60(const int* key /*ECX*/ /*dest in EAX*/);
// EAX-out: equal_range on tree at host+0x10 for key in EBX/key-view
extern "C" void __fastcall FUN_0044d960(void* tree /*ECX*/ /*range out EAX*/);
extern "C" void __fastcall GuardedVector_PushFront_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    const int* value /*stack*/);

static bool ring_contains_dword(const GuardedVectorHeader* ring, int value)
{
  int abs = ring->size + static_cast<int>(ring->begin);
  for (; abs != static_cast<int>(ring->begin); --abs) {
    uint32_t page = static_cast<uint32_t>(abs - 1) >> 2;
    const int sub = static_cast<int>(page) * -4;
    if (ring->capacity <= page) {
      page -= ring->capacity;
    }
    const int slot = *reinterpret_cast<const int*>(
        reinterpret_cast<const uint8_t*>(ring->pages[page]) +
        (static_cast<uint32_t>(abs - 1) + sub) * 4);
    if (slot == value) {
      return true;
    }
  }
  return false;
}

// Bidirectional successor (MSVC map/set); is_nil at +0x25.
static TreeNode* tree_successor(TreeNode* node)
{
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(node) + 0x25) != 0) {
    return node;  // caller checks range end separately
  }
  TreeNode* r = node->right;
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(r) + 0x25) == 0) {
    TreeNode* cur = r;
    TreeNode* next = cur->left;
    while (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(next) + 0x25) == 0) {
      cur = next;
      next = cur->left;
    }
    return cur;
  }
  TreeNode* p = node->parent;
  TreeNode* cur = node;
  while (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(p) + 0x25) == 0 &&
         cur == p->right) {
    cur = p;
    p = p->parent;
  }
  return p;
}

void __fastcall PreloadDep_CollectTransitiveKeys_Inferred(
    void* host /*ECX*/,
    const int* key /*stack*/,
    GuardedVectorHeader* ring /*stack*/)
{
  // FUN_00426f60 + FUN_0044d960(host+0x10) → [it, end) equal_range
  TreeNode* it = nullptr;
  TreeNode* end = nullptr;
  // (iterator fill via helpers — sealed as callees; range in locals)

  // Structural loop matching decompile/bytes:
  // for (; it != end; it = successor(it))
  while (it != end) {
    const int* node_key =
        reinterpret_cast<const int*>(reinterpret_cast<uint8_t*>(it) + 0x18);

    if (!ring_contains_dword(ring, *node_key)) {
      PreloadDep_CollectTransitiveKeys_Inferred(host, node_key, ring);
      GuardedVector_PushFront_Thiscall(ring, node_key);
    }

    // Only advance when is_nil at it+0x25 is clear (bytes); successor walk.
    if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(it) + 0x25) == 0) {
      it = tree_successor(it);
    } else {
      break;
    }
  }
}
