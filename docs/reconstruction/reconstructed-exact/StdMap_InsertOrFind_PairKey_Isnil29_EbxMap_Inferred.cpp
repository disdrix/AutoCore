// =============================================================================
// StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred  (Ghidra FUN_00405bd0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00405bd0
// Address:   0x00405bd0–0x00405c7e inclusive (175 B / 0xAF); exclusive 0x00405c7f
// System:    MSVC std::map insert-or-find (isnil@+0x29, pair key hi/lo)
// Agent:     WQ9K-D OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================
//
// PURPOSE:
// Unique insert-or-find by pair key: signed hi primary (node+0x14), unsigned lo
// secondary (node+0x10). Register ABI: EBX=map, EAX=value, ESI=out pair.
// Twin thiscall RET8 unit: StdMap_InsertOrFind_PairKey_Isnil29_Inferred (0x004cbee0).
//
// Dual: reviews/A|B_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md

#include <cstdint>

struct MapNode_PairKey_Isnil29 {
  MapNode_PairKey_Isnil29* left;    // +0x00
  MapNode_PairKey_Isnil29* parent;  // +0x04
  MapNode_PairKey_Isnil29* right;   // +0x08
  // +0x0C pad/align
  std::uint32_t key_lo;             // +0x10  unsigned secondary
  std::int32_t key_hi;              // +0x14  signed primary
  // mapped +0x18..+0x24 (product open; caller may pack TFID flags + tick)
  std::uint8_t color;               // +0x28
  std::uint8_t isnil;               // +0x29
};

struct MapShell_Isnil29_Pair {
  // +0x00 allocator/comp
  MapNode_PairKey_Isnil29* head;    // +0x04
  std::uint32_t size;               // +0x08
};

struct InsertPair_Isnil29 {
  MapNode_PairKey_Isnil29* it;      // +0x00
  std::uint8_t inserted;            // +0x04
};

struct Val_PairKey_Isnil29 {
  std::uint32_t key_lo;             // +0x00
  std::int32_t key_hi;              // +0x04
  // mapped tail for insert buynode (caller-filled)
};

// Dualed WQ9J-G — EDX = Node**
extern "C" void StdTree_Predecessor_Isnil29_Edx_Inferred(
    MapNode_PairKey_Isnil29** it /*EDX*/);

// Undualed insert+rebalance worker used by this unit (EDI=map, ECX=where).
// Stack: outIt*, addLeft, value*. Returns Node**.
extern "C" MapNode_PairKey_Isnil29** InsertHint_Isnil29_Via004069f0_Undualed(
    MapShell_Isnil29_Pair* map /*EDI*/,
    MapNode_PairKey_Isnil29** outIt,
    char addLeft,
    MapNode_PairKey_Isnil29* where /*ECX*/,
    const Val_PairKey_Isnil29* value);

// node <= key  (go right / not goLeft)
static inline bool NodeLeKey(const MapNode_PairKey_Isnil29* n,
                             const Val_PairKey_Isnil29* k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo <= k->key_lo; // unsigned
}

// node < key  (strict; after lower-bound + optional pred)
static inline bool NodeLtKey(const MapNode_PairKey_Isnil29* n,
                             const Val_PairKey_Isnil29* k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo < k->key_lo; // unsigned
}

// Register ABI: EBX=map, EAX=value, ESI=out; bare RET; returns out in EAX.
extern "C" InsertPair_Isnil29* StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred(
    MapShell_Isnil29_Pair* map /*EBX*/,
    InsertPair_Isnil29* out /*ESI*/,
    const Val_PairKey_Isnil29* value /*EAX*/)
{
  MapNode_PairKey_Isnil29* head = map->head;
  MapNode_PairKey_Isnil29* where = head;
  bool goLeft = true;
  char addLeft = 1;

  MapNode_PairKey_Isnil29* node = head->parent;
  if (node->isnil == 0) {
    MapNode_PairKey_Isnil29* child = node;
    do {
      where = child;
      if (NodeLeKey(where, value)) {
        child = where->right;
        goLeft = false;
        addLeft = 0;
      } else {
        child = where->left;
        goLeft = true;
        addLeft = 1;
      }
    } while (child->isnil == 0);
  }

  if (goLeft) {
    if (where == head->left) {
      addLeft = 1;
      goto do_insert;
    }
    StdTree_Predecessor_Isnil29_Edx_Inferred(&where);
  }

  if (!NodeLtKey(where, value)) {
    out->it = where;
    out->inserted = 0;
    return out;
  }

do_insert:
  {
    MapNode_PairKey_Isnil29* tryWhere = where;
    MapNode_PairKey_Isnil29** pNew =
        InsertHint_Isnil29_Via004069f0_Undualed(map, &tryWhere, addLeft, where, value);
    out->it = *pNew;
    out->inserted = 1;
    return out;
  }
}

// Scaffold alias (Ghidra void / unaff formals — register ABI only)
extern "C" InsertPair_Isnil29* FUN_00405bd0(
    MapShell_Isnil29_Pair* map /*EBX*/,
    InsertPair_Isnil29* out /*ESI*/,
    const Val_PairKey_Isnil29* value /*EAX*/)
{
  return StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred(map, out, value);
}
