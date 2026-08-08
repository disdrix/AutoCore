// =============================================================================
// StdTree_InsertHint_Isnil29_Inferred  (FUN_004cc220)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cc220
// Address:   0x004cc220–0x004cc3c4 inclusive (421 B / 0x1A5)
// System:    MSVC std::_Tree unique insert-with-hint (isnil@+0x29)
// Dual A/B:  2026-08-04 WQ9F-E
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MSVC-style map/set insert(hint, value) for the large-node family:
//   try local attachment via always-insert rebalance; else fall back to
//   insert-or-find. Key is a 2-dword ordered pair at value +0/+4 and
//   node +0x10/+0x14 (compare helper FUN_00401480).
//
// ABI
//   __thiscall; ECX = map*; stack (Node** outIt, Node* hint, Val* value);
//   returns outIt; RET 0x0c.
//
// Callers
//   FUN_004cc400 only (stages value, returns node+0x20).
//
// Rejected aliases
//   Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cc220
// =============================================================================

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x0C
  std::uint32_t val[6];  // +0x10 .. +0x24  (key often val[0], val[1])
  std::uint8_t color;    // +0x28
  std::uint8_t isnil;    // +0x29
  // pad to 0x30
};

struct MapShellIsnil29 {
  void* proxy;           // +0x00
  NodeIsnil29* head;     // +0x04
  std::uint32_t size;    // +0x08
};

struct KeyPair {
  std::uint32_t lo;      // +0
  std::int32_t  hi;      // +4  (signed in decompiler compares)
};

struct InsertOrFindPair {
  NodeIsnil29* node;
  char inserted;         // not consumed by this shell's *out write
};

// Dualed WQ9E-E: always-insert + RB rebalance (RET 0x10)
extern "C" NodeIsnil29** __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    char addLeft,
    NodeIsnil29* where,
    const void* value);

// WQ9F-D residual: full insert-or-find for this key family
extern "C" InsertOrFindPair* __thiscall FUN_004cbee0(
    MapShellIsnil29* map,
    InsertOrFindPair* outPair,
    const void* value);

// Key less: true if a < b (hi then lo). Ghidra FUN_00401480.
extern "C" char FUN_00401480(const void* a, const void* b);

// Tree predecessor / successor (isnil@+0x29). Ghidra FUN_004cb4f0 / FUN_004cb270.
extern "C" void __fastcall FUN_004cb4f0(NodeIsnil29** node);
extern "C" void __fastcall FUN_004cb270(NodeIsnil29** node);

static inline const KeyPair* ValueKey(const void* value) {
  return reinterpret_cast<const KeyPair*>(value);
}

static inline const KeyPair* NodeKey(const NodeIsnil29* n) {
  return reinterpret_cast<const KeyPair*>(&n->val[0]);
}

static inline bool KeyLess(const void* a, const void* b) {
  return FUN_00401480(a, b) != 0;
}

extern "C" NodeIsnil29** __thiscall StdTree_InsertHint_Isnil29_Inferred(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* hint,
    const void* value)
{
  NodeIsnil29* head = map->head;

  if (map->size == 0) {
    StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, /*addLeft*/ 1, head, value);
    return outIt;
  }

  if (hint == head->left) {
    // begin / leftmost: value < *begin → insert left of leftmost
    if (KeyLess(value, NodeKey(hint))) {
      StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 1, hint, value);
      return outIt;
    }
  } else if (hint == head) {
    // end: *rightmost < value → insert right of rightmost
    NodeIsnil29* rightmost = head->right;
    if (KeyLess(NodeKey(rightmost), value)) {
      StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 0, rightmost, value);
      return outIt;
    }
  } else {
    // general neighbor paths
    if (KeyLess(value, NodeKey(hint))) {
      NodeIsnil29* pred = hint;
      FUN_004cb4f0(&pred);
      if (KeyLess(NodeKey(pred), value)) {
        // pred < value < hint
        if (pred->right->isnil != 0)
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 0, pred, value);
        else
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 1, hint, value);
        return outIt;
      }
    }
    if (KeyLess(NodeKey(hint), value)) {
      NodeIsnil29* succ = hint;
      FUN_004cb270(&succ);
      if (hint == head || KeyLess(value, NodeKey(succ))) {
        // hint < value < succ (or succ is end)
        if (hint->right->isnil != 0)
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 0, hint, value);
        else
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, outIt, 1, succ, value);
        return outIt;
      }
    }
  }

  // Invalid / equal key hint → full insert-or-find; copy node only
  InsertOrFindPair local{};
  InsertOrFindPair* pair = FUN_004cbee0(map, &local, value);
  *outIt = pair->node;
  return outIt;
}
