// =============================================================================
// StdTree_InsertAndRebalance_Val28_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00603c90
// Address:   0x00603c90  (autoassault.exe, image base 0x400000)
// Body:      0x00603c90 – 0x00603e7a exclusive (**490 B** / 0x1EA); pad CC
// System:    MSVC std::_Tree always-insert + RB rebalance (Val28 / isnil@+0x29)
// Generated: 2026-08-04 WQ9E-F dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Always-insert a Val28 red-black node under `where`, rebalance while parent
//   is red, paint root black, write *outIt = new node.
//   Throw "map/set<T> too long" if size > **0x9249247** (≈ 0xFFFFFFFF/0x1C).
//   Parent callers own key walk / uniqueness (sole caller FUN_00603f00).
//
// NODE / VALUE (from buynode FUN_00603b10 + ctor FUN_00603730):
//   operator_new(0x2C)
//   left@0 parent@4 right@8
//   key int @+0x0C; mapped vector-ish + trailing dwords through +0x27
//   color@+0x28 (0=red on insert); isnil@+0x29 = 0
//
// ABI:
//   __thiscall; ECX = MapShell* (head@+4, size@+8)
//   stack: (Node** outIt, char addLeft, Node* where, Val28* value)
//   **RET 0x10**
//
// CALLEES:
//   FUN_00603b10 — buynode (new 0x2C + FUN_00603730)
//   StdTree_Lrotate_Isnil29 — FUN_004192a0
//   StdTree_Rrotate_Isnil29_Inferred — FUN_004192f0
//   (one rebalance path inlines a right-rotate sequence instead of call)
//
// SOLE CALLER: FUN_00603f00 (lower-bound walk + always-insert) @ xref 0x00603f4a
//
// Dual: reviews/A|B_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md
// =============================================================================

#include <cstdint>

struct MapNode_Val28_Isnil29 {
  MapNode_Val28_Isnil29* left;    // +0x00
  MapNode_Val28_Isnil29* parent;  // +0x04
  MapNode_Val28_Isnil29* right;   // +0x08
  std::int32_t key;               // +0x0C
  std::uint32_t mapped[6];        // +0x10 .. +0x27  (24 B; + key = Val28)
  std::uint8_t color;             // +0x28  0=red, 1=black
  std::uint8_t isnil;             // +0x29
};

struct MapShell_Val28_Isnil29 {
  void* proxy;                      // +0x00
  MapNode_Val28_Isnil29* head;      // +0x04
  std::uint32_t size;               // +0x08
};

struct Val28 {
  std::int32_t key;
  std::uint32_t rest[6];
};

// Buynode: operator_new(0x2C) + FUN_00603730(left, parent, right, value*, color)
extern "C" MapNode_Val28_Isnil29* FUN_00603b10(
    MapNode_Val28_Isnil29* left,
    MapNode_Val28_Isnil29* parent,
    MapNode_Val28_Isnil29* right,
    Val28* value,
    std::uint8_t color);

extern "C" void __thiscall FUN_004192a0(void* tree, MapNode_Val28_Isnil29* x); // Lrotate
extern "C" void __thiscall FUN_004192f0(void* tree, MapNode_Val28_Isnil29* x); // Rrotate
extern "C" void _CxxThrowException(void*, void*);

// __thiscall
extern "C" void __thiscall StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(
    MapShell_Val28_Isnil29* map,       // ECX
    MapNode_Val28_Isnil29** outIt,     // stack
    char addLeft,                     // stack (nonzero = link as left child)
    MapNode_Val28_Isnil29* where,      // stack
    Val28* value)                     // stack
{
  // SEH frame (LAB_009a7ef2) for throw path — omitted here.

  if (map->size > 0x9249247u) {
    // basic_string("map/set<T> too long") + length_error → DAT_00acc388
    _CxxThrowException(nullptr, nullptr);
  }

  MapNode_Val28_Isnil29* head = map->head;
  // buynode: left=head, parent=where, right=head, value, color=red(0)
  MapNode_Val28_Isnil29* n = FUN_00603b10(head, where, head, value, 0);
  map->size = map->size + 1;

  if (where == head) {
    // empty tree: root = leftmost = rightmost = n
    head->parent = n;
    head->left = n;
    head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == head->right)
      head->right = n;
  } else {
    where->left = n;
    if (where == head->left)
      head->left = n;
  }

  // RB insert fixup while parent is red
  MapNode_Val28_Isnil29* cur = n;
  while (cur->parent->color == 0) {
    MapNode_Val28_Isnil29* parent = cur->parent;
    MapNode_Val28_Isnil29* grand = parent->parent;
    if (parent == grand->left) {
      MapNode_Val28_Isnil29* uncle = grand->right;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        cur = grand;
      } else {
        if (cur == parent->right) {
          FUN_004192a0(map, parent); // Lrotate
          cur = parent;
          parent = cur->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_004192f0(map, parent->parent); // Rrotate
      }
    } else {
      MapNode_Val28_Isnil29* uncle = grand->left;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        cur = grand;
      } else {
        if (cur == parent->left) {
          FUN_004192f0(map, parent); // Rrotate
          cur = parent;
          parent = cur->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        // One path inlines Lrotate about grand (same CF as FUN_004192a0)
        FUN_004192a0(map, parent->parent);
      }
    }
  }

  head->parent->color = 1; // root black
  *outIt = n;
}

// Legacy symbol alias.
extern "C" void __thiscall FUN_00603c90(
    MapShell_Val28_Isnil29* map,
    MapNode_Val28_Isnil29** outIt,
    char addLeft,
    MapNode_Val28_Isnil29* where,
    Val28* value)
{
  StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(map, outIt, addLeft, where, value);
}
