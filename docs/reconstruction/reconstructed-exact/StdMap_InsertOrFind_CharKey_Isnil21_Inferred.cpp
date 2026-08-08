// =============================================================================
// StdMap_InsertOrFind_CharKey_Isnil21_Inferred  (Ghidra FUN_0041a570)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a570
// Address:   0x0041a570–0x0041a628 exclusive (184 B / 0xB8)
// System:    MSVC std::map unique insert-or-find
//            (isnil@+0x21, char key @+0x0C, node 0x24 family)
// Dual A/B:  2026-08-05 R13-021
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// Terminal:  false
// =============================================================================
// PURPOSE
//   Unique insert-or-find for the char-key isnil@+0x21 map family. Walks from
//   root comparing *value (char) against node key @+0x0C. On miss inserts via
//   dualed always-insert/rebalance FUN_0041ba30; on equal returns {it,0}
//   without rewriting mapped payload. Non-begin left-walk uses predecessor
//   FUN_005adff0 before the strict miss check.
//
// ABI: __thiscall; ECX=map*; stack (out*, value*); RET 0x8.
// Insert: StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30) — R12-011.
// Pred:   FUN_005adff0 (isnil21 residual).
//
// Peers (do not merge):
//   StdMap_InsertOrFind_PairKey_Isnil21_Inferred (0x00407060) — pair key / Val16 insert 00407200
//   StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30) — always-insert child only
// Dual: reviews/A|B_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeCharKeyIsnil21 {
  NodeCharKeyIsnil21* left;    // +0x00
  NodeCharKeyIsnil21* parent;  // +0x04
  NodeCharKeyIsnil21* right;   // +0x08
  char key;                    // +0x0C  (char-key map; residual value follows)
  // ... value payload through +0x1F (via buynode / FUN_0041c140 path)
  std::uint8_t color;          // +0x20  (0=red, 1=black)
  std::uint8_t isnil;          // +0x21
  // pad to 0x24
};

struct MapShellCharKeyIsnil21 {
  void* proxy;                      // +0x00
  NodeCharKeyIsnil21* head;         // +0x04 sentinel (isnil=1)
  std::uint32_t size;               // +0x08
};

struct InsertPairCharKeyIsnil21 {
  NodeCharKeyIsnil21* it;           // +0x00
  std::uint8_t inserted;            // +0x04  (written as byte; out+4)
};

// Value type: char key at +0, residual payload after (copied by buynode).
struct ValCharKeyIsnil21 {
  char key;                         // +0x00
  // residual payload...
};

// Dualed R12-011 always-insert + rebalance. RET 0x10; EAX = out.
extern "C" NodeCharKeyIsnil21** __thiscall
StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred(
    MapShellCharKeyIsnil21* map,
    NodeCharKeyIsnil21** out,
    char addLeft,
    NodeCharKeyIsnil21* where,
    const void* value);

// Residual isnil21 tree predecessor (iterator--). Updates *pNode.
extern "C" void __fastcall FUN_005adff0(NodeCharKeyIsnil21** pNode);

// __thiscall RET 0x8
void __thiscall StdMap_InsertOrFind_CharKey_Isnil21_Inferred(
    MapShellCharKeyIsnil21* map,
    InsertPairCharKeyIsnil21* out,
    const ValCharKeyIsnil21* value)
{
  const char key = value->key;
  NodeCharKeyIsnil21* head = map->head;
  NodeCharKeyIsnil21* where = head;
  bool goLeft = true;

  NodeCharKeyIsnil21* child = head->parent; // root
  if (child->isnil == 0) {
    do {
      where = child;
      goLeft = (key < where->key);
      if (goLeft)
        child = where->left;
      else
        child = where->right;
    } while (child->isnil == 0);
  }

  NodeCharKeyIsnil21* where_slot = where;

  if (goLeft) {
    if (where == head->left) {
      // insert before begin
      NodeCharKeyIsnil21** p =
          StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred(
              map, &where_slot, /*addLeft*/ 1, where, value);
      out->inserted = 1;
      out->it = *p;
      return;
    }
    FUN_005adff0(&where_slot); // predecessor
    where = where_slot;
  }

  // strict miss: where.key < key → insert; else equal hit
  if (where->key < key) {
    NodeCharKeyIsnil21** p =
        StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred(
            map, &where_slot, static_cast<char>(goLeft), where, value);
    out->it = *p;
    out->inserted = 1;
    return;
  }

  out->inserted = 0;
  out->it = where;
}
