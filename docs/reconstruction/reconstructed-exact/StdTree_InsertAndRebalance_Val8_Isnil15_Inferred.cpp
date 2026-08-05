// =============================================================================
// StdTree_InsertAndRebalance_Val8_Isnil15_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00438140
// Address:   0x00438140  (autoassault.exe, image base 0x400000)
// System:    std map/set tree — Val8 / isnil@+0x15 always-insert + RB fixup
// Wave:      W38-L OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC _Tree always-insert helper for 0x18-byte value nodes:
//   left@0 parent@4 right@8 key@0x0C mapped@0x10 color@0x14 isnil@0x15.
//   Parent owns lower-bound / uniqueness (e.g. FUN_00458510 W37-K).
//
// ABI (bytes win over flat decompiler):
//   EDI = map shell (head@+4, size@+8)
//   stack: (Node** out, char addLeft, Node* where, Val8* value)
//   RET 0x10; writes *out = new node; void-ish side effect
//
// Max size: 0x1ffffffd → throw "map/set<T> too long" (DAT_00acc388).
// Buynode: FUN_00439110 (operator_new 0x18; color arg 0; isnil=0).
// Rotates: FUN_004219b0 (L) / FUN_0046f030 (R) — isnil15 family clones
//   (distinct VAs from sealed W24-O Tree_RotateLeft/Right_Isnil15).
//
// Reject: Named_CalleeOf_*Mission_bActiveObj scaffold product alias.
// Do not merge with Val12 InsertAndRebalance (max 0x15555553, color@+0x18).

#include <cstdint>

struct Val8 {
  uint32_t key;     // +0
  uint32_t mapped;  // +4
};

struct NodeVal8 {
  NodeVal8* left;    // +0
  NodeVal8* parent;  // +4
  NodeVal8* right;   // +8
  uint32_t key;      // +0x0C
  uint32_t mapped;   // +0x10
  uint8_t color;     // +0x14  (0=red, 1=black)
  uint8_t isnil;     // +0x15
};

struct MapShell {
  // +0 unused/pad in this ABI view
  NodeVal8* head;    // +4 sentinel (isnil=1); head->parent = root; head->left = leftmost; head->right = rightmost
  uint32_t size;     // +8
};

// External (unOWN)
extern "C" NodeVal8* FUN_00439110(NodeVal8* left, NodeVal8* parent, NodeVal8* right, uint8_t color);
// ESI = Val8* at call (key/mapped copied into node+0x0C/+0x10); isnil forced 0.

extern "C" void FUN_004219b0(NodeVal8* node, MapShell* map); // left rotate (isnil15)
extern "C" void FUN_0046f030(NodeVal8* node, MapShell* map); // right rotate (isnil15)

// Throw path uses basic_string("map/set<T> too long") + FUN_00401a40 + _CxxThrowException(DAT_00acc388).

// Register ABI: map in EDI. Not ECX-thiscall.
extern "C" void StdTree_InsertAndRebalance_Val8_Isnil15_Inferred(
    NodeVal8** out,
    char addLeft,
    NodeVal8* where,
    Val8* value)
{
  MapShell* map;
  __asm { mov map, edi }

  if (map->size > 0x1ffffffdu) {
    // throw "map/set<T> too long" — non-returning
    // (basic_string + FUN_00401a40 + _CxxThrowException)
    return; // unreachable in retail
  }

  // Buynode: left=head, parent=where, right=head, color=red(0); value via ESI
  NodeVal8* head = map->head;
  NodeVal8* n;
  {
    // Match call shape: ESI=value; push color=0, head, where, head
    __asm { mov esi, value }
    n = FUN_00439110(head, where, head, 0);
  }
  map->size += 1;

  if (where == head) {
    // empty tree: root = leftmost = rightmost = n
    head->parent = n;
    head->left = n;
    head->right = n;
  } else if (addLeft != 0) {
    where->left = n;
    if (where == head->left) {
      head->left = n; // new leftmost
    }
  } else {
    where->right = n;
    if (where == head->right) {
      head->right = n; // new rightmost
    }
  }

  // RB rebalance while parent is red (color@+0x14)
  NodeVal8* x = n;
  while (x->parent->color == 0) {
    NodeVal8* p = x->parent;
    NodeVal8* gp = p->parent;
    if (p == gp->left) {
      NodeVal8* uncle = gp->right;
      if (uncle->color == 0) {
        // recolor
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->right) {
          FUN_004219b0(p, map); // left rotate on parent
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_0046f030(p->parent, map); // right rotate on grandparent
      }
    } else {
      NodeVal8* uncle = gp->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->left) {
          FUN_0046f030(p, map); // right rotate on parent
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_004219b0(p->parent, map); // left rotate on grandparent
      }
    }
  }

  head->parent->color = 1; // root black
  *out = n;
}

// Ghidra twin — same body; stack form matches RET 0x10
extern "C" void FUN_00438140(NodeVal8** out, char addLeft, NodeVal8* where, Val8* value)
{
  StdTree_InsertAndRebalance_Val8_Isnil15_Inferred(out, addLeft, where, value);
}
