// =============================================================================
// StdTree_InsertHint_Isnil21_Inferred  (FUN_00406560)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406560
// Address:   0x00406560–0x00406705 exclusive (421 B / 0x1A5)
// System:    MSVC std::_Tree unique insert-with-hint (isnil@+0x21; pair key)
// Dual A/B:  2026-08-04 WQ9H-F
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MSVC-style map/set insert(hint, value) for the isnil@+0x21 node family:
//   try local attachment via always-insert rebalance; else fall back to
//   insert-or-find. Key is a 2-dword ordered pair at value +0/+4 and
//   node +0x10/+0x14 (compare helper dualed StdPairKey_Less_HiSignedLoUnsigned
//   at 0x00401480; leftmost path inlines the same algebra).
//
// ABI
//   __thiscall; ECX = map*; stack (Node** outIt, Node* hint, Val* value);
//   returns outIt; RET 0x0c.
//
// Callers
//   FUN_004055c0 only (operator[]-style; returns node+0x18).
//
// Peer
//   StdTree_InsertHint_Isnil29_Inferred (0x004cc220) — same pair-key leaf,
//   different isnil/color/insert callees.
// =============================================================================

#include <cstdint>

struct NodeIsnil21 {
  NodeIsnil21* left;     // +0x00
  NodeIsnil21* parent;   // +0x04
  NodeIsnil21* right;    // +0x08
  // +0x0C
  std::uint32_t val_lo;  // +0x10  key lo (unsigned)
  std::int32_t  val_hi;  // +0x14  key hi (signed)
  // ... mapped ...
  // +0x20 color (callee family)
  // +0x21 isnil
};

static inline std::uint8_t node_isnil(const NodeIsnil21* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x21);
}

struct MapShellIsnil21 {
  void* proxy;           // +0x00
  NodeIsnil21* head;     // +0x04
  std::uint32_t size;    // +0x08
};

struct KeyPair {
  std::uint32_t lo;      // +0
  std::int32_t  hi;      // +4  signed primary
};

struct InsertOrFindPair {
  NodeIsnil21* node;
  char inserted;         // not consumed by this shell's *out write
};

// Always-insert + RB rebalance for this map family (undualed residual).
extern "C" NodeIsnil21** __thiscall FUN_00407200(
    MapShellIsnil21* map,
    NodeIsnil21** outIt,
    char addLeft,
    NodeIsnil21* where,
    const void* value);

// Insert-or-find fallback (undualed residual).
extern "C" InsertOrFindPair* __thiscall FUN_00407060(
    MapShellIsnil21* map,
    InsertOrFindPair* outPair,
    const void* value);

// Dualed pair-key less (hi signed, lo unsigned).
extern "C" char FUN_00401480(const void* a, const void* b);

// Predecessor / successor isnil@+0x21 (undualed residual).
extern "C" void __fastcall FUN_005adff0(NodeIsnil21** node);
extern "C" void __fastcall FUN_004e12c0(NodeIsnil21** node);

static inline const KeyPair* ValueKey(const void* value)
{
  return reinterpret_cast<const KeyPair*>(value);
}

static inline const KeyPair* NodeKey(const NodeIsnil21* n)
{
  return reinterpret_cast<const KeyPair*>(
      reinterpret_cast<const char*>(n) + 0x10);
}

static inline bool KeyLess(const void* a, const void* b)
{
  return FUN_00401480(a, b) != 0;
}

// Inlined leftmost compare (same algebra as FUN_00401480).
static inline bool ValueLessNodeInline(const KeyPair* v, const NodeIsnil21* n)
{
  const KeyPair* nk = NodeKey(n);
  return (v->hi < nk->hi) || (v->hi == nk->hi && v->lo < static_cast<std::uint32_t>(nk->lo));
}

extern "C" NodeIsnil21** __thiscall StdTree_InsertHint_Isnil21_Inferred(
    MapShellIsnil21* map,
    NodeIsnil21** outIt,
    NodeIsnil21* hint,
    const void* value)
{
  NodeIsnil21* head = map->head;

  if (map->size == 0) {
    FUN_00407200(map, outIt, /*addLeft*/ 1, head, value);
    return outIt;
  }

  if (hint == head->left) {
    // begin / leftmost: value < *begin → insert left of leftmost
    if (ValueLessNodeInline(ValueKey(value), hint)) {
      FUN_00407200(map, outIt, 1, hint, value);
      return outIt;
    }
  } else if (hint == head) {
    // end: *rightmost < value → insert right of rightmost
    NodeIsnil21* rightmost = head->right;
    if (KeyLess(NodeKey(rightmost), value)) {
      FUN_00407200(map, outIt, 0, rightmost, value);
      return outIt;
    }
  } else {
    // general neighbor paths
    if (KeyLess(value, NodeKey(hint))) {
      NodeIsnil21* pred = hint;
      FUN_005adff0(&pred);
      if (KeyLess(NodeKey(pred), value)) {
        // pred < value < hint — bytes: where=pred/addLeft=0 or where=hint/addLeft=1
        if (node_isnil(pred->right) != 0)
          FUN_00407200(map, outIt, 0, pred, value);
        else
          FUN_00407200(map, outIt, 1, hint, value);
        return outIt;
      }
    }
    if (KeyLess(NodeKey(hint), value)) {
      NodeIsnil21* succ = hint;
      FUN_004e12c0(&succ);
      if (hint == head || KeyLess(value, NodeKey(succ))) {
        // hint < value < succ (or succ is end)
        // bytes: where=hint/addLeft=0 or where=succ/addLeft=1
        // note: open-side test uses *hint->right* isnil (not succ)
        if (node_isnil(hint->right) != 0)
          FUN_00407200(map, outIt, 0, hint, value);
        else
          FUN_00407200(map, outIt, 1, succ, value);
        return outIt;
      }
    }
  }

  // Invalid / equal key hint → full insert-or-find; copy node only
  InsertOrFindPair local{};
  InsertOrFindPair* pair = FUN_00407060(map, &local, value);
  *outIt = pair->node;
  return outIt;
}