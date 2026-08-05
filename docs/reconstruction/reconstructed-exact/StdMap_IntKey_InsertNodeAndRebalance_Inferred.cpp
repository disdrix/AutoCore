// =============================================================================
// StdMap_IntKey_InsertNodeAndRebalance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005690a0
// Address:   0x005690a0  (autoassault.exe, image base 0x400000)
// System:    stl-map / MSVC _Tree insert + red-black rebalance
// Generated: 2026-07-29 W22-E from live decompile + read_memory
// Exactness: Behavior-preserving reconstruction of sealed CF / ABI / offsets.
// Bit-for-bit vs retail EXE: DEFERRED
// Ghidra:    FUN_005690a0
// =============================================================================
//
// PURPOSE
//   Always-allocate insert + RB rebalance for the 0x4C-node specialization
//   (15-dword value @ +0x0C, color +0x48, isnil +0x49). Parents
//   StdMap_InsertOrFindByIntKey / InsertWithHint own key compare.
//
// ABI (byte-sealed)
//   __thiscall: ECX = MapShell*
//   stack: Node** outIt, char addLeft, Node* where, const void* value15
//   RET 0x10
//
// Plate: "map/set<T> too long" → length_error → DAT_00acc388
// =============================================================================

#include <cstdint>
#include <cstring>

struct MapShell;
struct IntKeyMapNode;

// Node ctor FUN_00568f60 — operator_new(0x4C), 15 dwords → +0x0C, color +0x48, isnil +0x49
extern IntKeyMapNode *Node_Construct0x4c(
    IntKeyMapNode *left,
    IntKeyMapNode *parent,
    IntKeyMapNode *right,
    const uint32_t *value15,
    uint8_t color);

// Shared rotates (isnil @ +0x49) — same helpers as aa_00538ea0
extern void Tree_RotateLeft_Color48(MapShell *map, IntKeyMapNode *node);   // FUN_00568b70
extern void Tree_RotateRight_Color48(MapShell *map, IntKeyMapNode *node);  // FUN_005681a0

extern void Std_LengthError_ThrowFromCString(const char *msg);

struct IntKeyMapNode {
  IntKeyMapNode *left;    // +0x00
  IntKeyMapNode *parent;  // +0x04
  IntKeyMapNode *right;  // +0x08
  uint32_t value[15];    // +0x0C  (key int at value[0] / +0x0C)
  // color +0x48, isnil +0x49 packed after value
};

struct MapShell {
  void *proxy;
  IntKeyMapNode *head;  // +0x04
  uint32_t size;       // +0x08
};

static inline uint8_t *NodeColor(IntKeyMapNode *n) {
  return reinterpret_cast<uint8_t *>(n) + 0x48;
}
static inline uint8_t *NodeIsnil(IntKeyMapNode *n) {
  return reinterpret_cast<uint8_t *>(n) + 0x49;
}

// Inlined grandparent left-rotate (matches body else-branch; isnil @ +0x49)
static void InlineRotateLeft(MapShell *map, IntKeyMapNode *x)
{
  IntKeyMapNode *y = x->right;
  x->right = y->left;
  if (*NodeIsnil(y->left) == 0) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x == map->head->parent) {
    map->head->parent = y;
  } else {
    IntKeyMapNode *xp = x->parent;
    if (x == xp->left) {
      xp->left = y;
    } else {
      xp->right = y;
    }
  }
  y->left = x;
  x->parent = y;
}

void __thiscall StdMap_IntKey_InsertNodeAndRebalance_Inferred(
    MapShell *map,
    IntKeyMapNode **outIt,
    char addLeft,
    IntKeyMapNode *where,
    const uint32_t *value15)
{
  // cmp [edi+8], 0x04444443 / jb  → throw if size >= 0x4444443
  if (map->size > 0x4444442u) {
    Std_LengthError_ThrowFromCString("map/set<T> too long");
  }

  IntKeyMapNode *head = map->head;
  IntKeyMapNode *node =
      Node_Construct0x4c(head, where, head, value15, /*red*/ 0);

  map->size += 1;

  if (where == head) {
    head->parent = node;
    head->left = node;
    head->right = node;
  } else if (addLeft == 0) {
    where->right = node;
    if (where == head->right) {
      head->right = node;
    }
  } else {
    where->left = node;
    if (where == head->left) {
      head->left = node;
    }
  }

  IntKeyMapNode *cur = node;
  while (*NodeColor(cur->parent) == 0) {
    IntKeyMapNode *parent = cur->parent;
    IntKeyMapNode *grand = parent->parent;
    IntKeyMapNode *uncle = grand->left;

    if (parent == uncle) {
      uncle = grand->right;
      if (*NodeColor(uncle) == 0) {
        *NodeColor(parent) = 1;
        *NodeColor(uncle) = 1;
        *NodeColor(grand) = 0;
        cur = grand;
      } else {
        if (cur == parent->right) {
          Tree_RotateLeft_Color48(map, parent);  // FUN_00568b70
          cur = parent;
          parent = cur->parent;
        }
        *NodeColor(cur->parent) = 1;
        *NodeColor(cur->parent->parent) = 0;
        Tree_RotateRight_Color48(map, cur->parent->parent);  // FUN_005681a0
      }
    } else {
      if (*NodeColor(uncle) == 0) {
        *NodeColor(parent) = 1;
        *NodeColor(uncle) = 1;
        *NodeColor(grand) = 0;
        cur = grand;
      } else {
        if (cur == parent->left) {
          Tree_RotateRight_Color48(map, parent);
          cur = parent;
          parent = cur->parent;
        }
        *NodeColor(cur->parent) = 1;
        *NodeColor(cur->parent->parent) = 0;
        // Inlined left-rotate of grandparent (body uses isnil +0x49)
        InlineRotateLeft(map, cur->parent->parent);
      }
    }
  }

  *NodeColor(map->head->parent) = 1;
  *outIt = node;
}

void __thiscall FUN_005690a0(MapShell *map, IntKeyMapNode **outIt, char addLeft,
                             IntKeyMapNode *where, const uint32_t *value15)
{
  StdMap_IntKey_InsertNodeAndRebalance_Inferred(map, outIt, addLeft, where, value15);
}
