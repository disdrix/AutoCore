// =============================================================================
// StdMap_StringKey_InsertOrFind_Via401db0_Inferred  (Ghidra FUN_00401c50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401c50
// Address:   0x00401c50–0x00401d26 inclusive (215 B / 0xD7); exclusive 0x00401d27
// System:    MSVC std::map string-key insert-or-find (isnil@+0x2d)
// Agent:     MEGA-064 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================
//
// PURPOSE:
// Unique insert-or-find by basic_string key. Walk tree with operator<; on miss
// insert via undualed FUN_00401db0; on equal return existing node with
// inserted=0 (no mapped-value rewrite).
//
// ABI:
//   stack[0] = MapShell*  (head@+4, size@+8)
//   EAX      = const basic_string* key
//   EBX      = InsertPair* out  ({node* it @+0, uint8_t inserted @+4})
//   return   = EBX; RET 4
//
// Monomorph twin (do not merge):
//   StdMap_StringKey_InsertOrFind (0x004309c0) — same CF/ABI/isnil2D;
//   insert worker 0x00430b60 instead of 0x00401db0.
//
// Dual: reviews/A|B_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md
// Retire: Named_CalleeOf_*Mission_Attempting_to_open_null_dialog* scaffolds.

#include <cstdint>

struct MapNode_StringKey_Isnil2D {
  MapNode_StringKey_Isnil2D* left;    // +0x00
  MapNode_StringKey_Isnil2D* parent;  // +0x04
  MapNode_StringKey_Isnil2D* right;   // +0x08
  // +0x0C basic_string key (MSVC SSO layout; treat as opaque)
  // mapped value follows string (product open)
  // +0x2C color
  // +0x2D isnil
};

struct MapShell_StringKey_Isnil2D {
  // +0x00 allocator/comp
  MapNode_StringKey_Isnil2D* head;  // +0x04
  std::uint32_t size;               // +0x08
};

struct InsertPair_StringKey {
  MapNode_StringKey_Isnil2D* it;  // +0x00
  std::uint8_t inserted;          // +0x04
};

// Opaque MSVC basic_string; compare via IAT [0x009c62e8].
struct BasicString_Char;

// Dualed W22-O — EDX = Node**
extern "C" void StdTree_IteratorDecrement(
    MapNode_StringKey_Isnil2D** it /*EDX*/);

// Undualed insert+rebalance worker (ECX=where, EDI=map).
// Stack: outIt*, addLeft, key*. Returns Node**.
extern "C" MapNode_StringKey_Isnil2D** InsertHint_StringKey_Via00401db0_Undualed(
    MapShell_StringKey_Isnil2D* map /*EDI*/,
    MapNode_StringKey_Isnil2D** outIt,
    char addLeft,
    MapNode_StringKey_Isnil2D* where /*ECX*/,
    const BasicString_Char* key);

// IAT operator< for basic_string (cdecl, 2 stack args).
extern "C" bool basic_string_operator_lt(
    const BasicString_Char* a,
    const BasicString_Char* b);

static inline MapNode_StringKey_Isnil2D* NodeKeyPtr(
    MapNode_StringKey_Isnil2D* n)
{
  return reinterpret_cast<MapNode_StringKey_Isnil2D*>(
      reinterpret_cast<char*>(n) + 0x0C);
}

static inline std::uint8_t NodeIsnil(const MapNode_StringKey_Isnil2D* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x2D);
}

// Stack map + EAX key + EBX out; RET 4; returns out in EAX.
extern "C" InsertPair_StringKey* StdMap_StringKey_InsertOrFind_Via401db0_Inferred(
    MapShell_StringKey_Isnil2D* map /*stack*/,
    const BasicString_Char* key /*EAX*/,
    InsertPair_StringKey* out /*EBX*/)
{
  MapNode_StringKey_Isnil2D* header = map->head;
  MapNode_StringKey_Isnil2D* parent = header;
  bool goLeft = true;

  MapNode_StringKey_Isnil2D* cur = header->parent; // root
  while (NodeIsnil(cur) == 0) {
    goLeft = basic_string_operator_lt(
        key,
        reinterpret_cast<const BasicString_Char*>(NodeKeyPtr(cur)));
    parent = cur;
    if (goLeft) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }

  if (goLeft) {
    if (parent == header->left) {
      MapNode_StringKey_Isnil2D** r =
          InsertHint_StringKey_Via00401db0_Undualed(
              map, &parent, 1, parent, key);
      out->it = *r;
      out->inserted = 1;
      return out;
    }
    StdTree_IteratorDecrement(&parent);
  }

  if (basic_string_operator_lt(
          reinterpret_cast<const BasicString_Char*>(NodeKeyPtr(parent)),
          key)) {
    MapNode_StringKey_Isnil2D** r =
        InsertHint_StringKey_Via00401db0_Undualed(
            map, &parent, goLeft ? 1 : 0, parent, key);
    out->it = *r;
    out->inserted = 1;
    return out;
  }

  out->it = parent;
  out->inserted = 0;
  return out;
}
