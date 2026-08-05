// =============================================================================
// StdMap_StringKey_InsertNodeAndRebalance
// -----------------------------------------------------------------------------
// Stable ID: aa_00430b60
// Address:   0x00430b60  (autoassault.exe, image base 0x400000)
// System:    stl-map / MSVC _Tree insert + red-black rebalance
// Generated: 2026-07-29 W22-E from live decompile + read_memory
// Exactness: Behavior-preserving reconstruction of sealed CF / ABI / offsets.
// Bit-for-bit vs retail EXE: DEFERRED
// Ghidra:    FUN_00430b60
// =============================================================================
//
// PURPOSE
//   Always-allocate map/set node insert + RB rebalance for the string-key
//   specialization (node size 0x30, color +0x2C, isnil +0x2D). Parents perform
//   insert-or-find; this unit never compares keys.
//
// ABI (byte-sealed — not ECX-thiscall for the map)
//   EDI = MapShell*  (head @ +4, size @ +8)
//   ECX = Node* where
//   stack: Node** outIt, char addLeft, const void* valuePair
//   RET 0x0C
//
// Plate: "map/set<T> too long" → length_error (FUN_00401a40) → DAT_00acc388
// =============================================================================

#include <cstdint>

struct MapShell;
struct StringKeyMapNode;

// Node ctor FUN_0042a890 — operator_new(0x30), string @ +0x0C, value @ +0x28,
// color @ +0x2C, isnil @ +0x2D.
extern StringKeyMapNode *Node_Construct0x30_StringKey(
    const void *valuePair,
    StringKeyMapNode *left,
    StringKeyMapNode *parent,
    StringKeyMapNode *right,
    uint8_t color);

// Rotates (isnil guard @ +0x2D)
extern void Tree_RotateLeft_Color2C(MapShell *map, StringKeyMapNode *node);   // FUN_0044e010
extern void Tree_RotateRight_Color2C(MapShell *map, StringKeyMapNode *node);  // FUN_0042a840

extern void Std_LengthError_ThrowFromCString(const char *msg);  // FUN_00401a40 path

struct StringKeyMapNode {
  StringKeyMapNode *left;    // +0x00
  StringKeyMapNode *parent;  // +0x04
  StringKeyMapNode *right;   // +0x08
  // +0x0C: std::string key (0x1C)
  // +0x28: uint32_t mapped
  uint8_t color;             // +0x2C  (0=red, 1=black) — conceptual; real layout packed
  uint8_t isnil;             // +0x2D
};

struct MapShell {
  void *proxy;                 // +0x00 (unused here)
  StringKeyMapNode *head;      // +0x04
  uint32_t size;               // +0x08
};

// Offsets used as in binary (color/isnil are absolute byte offsets on the node).
static inline uint8_t *NodeColor(StringKeyMapNode *n) {
  return reinterpret_cast<uint8_t *>(n) + 0x2C;
}
static inline uint8_t *NodeIsnil(StringKeyMapNode *n) {
  return reinterpret_cast<uint8_t *>(n) + 0x2D;
}

// Custom register ABI: map in EDI, where in ECX (documented; portable C uses params).
void StdMap_StringKey_InsertNodeAndRebalance(
    MapShell *map,             // EDI
    StringKeyMapNode *where,   // ECX
    StringKeyMapNode **outIt,
    char addLeft,
    const void *valuePair)
{
  // cmp [edi+8], 0x07FFFFFE / jb  →  throw if size >= 0x7FFFFFE
  if (map->size > 0x7FFFFFDu) {
    Std_LengthError_ThrowFromCString("map/set<T> too long");
  }

  StringKeyMapNode *head = map->head;
  // FUN_0042a890: left=head, parent=where, right=head, color=0 (red)
  StringKeyMapNode *node =
      Node_Construct0x30_StringKey(valuePair, head, where, head, /*red*/ 0);

  map->size += 1;

  if (where == head) {
    head->parent = node;
    head->left = node;
    head->right = node;
  } else if (addLeft != 0) {
    where->left = node;
    if (where == head->left) {
      head->left = node;
    }
  } else {
    where->right = node;
    if (where == head->right) {
      head->right = node;
    }
  }

  // RB fixup: while parent is red
  StringKeyMapNode *cur = node;
  while (*NodeColor(cur->parent) == 0) {
    StringKeyMapNode *parent = cur->parent;
    StringKeyMapNode *grand = parent->parent;
    StringKeyMapNode *uncle = grand->left;

    if (parent == uncle) {
      // parent is left child
      uncle = grand->right;
      if (*NodeColor(uncle) == 0) {
        *NodeColor(parent) = 1;
        *NodeColor(uncle) = 1;
        *NodeColor(grand) = 0;
        cur = grand;
      } else {
        if (cur == parent->right) {
          Tree_RotateLeft_Color2C(map, parent);
          cur = parent;
          parent = cur->parent;
        }
        *NodeColor(cur->parent) = 1;
        *NodeColor(cur->parent->parent) = 0;
        Tree_RotateRight_Color2C(map, cur->parent->parent);
      }
    } else {
      // parent is right child
      if (*NodeColor(uncle) == 0) {
        *NodeColor(parent) = 1;
        *NodeColor(uncle) = 1;
        *NodeColor(grand) = 0;
        cur = grand;
      } else {
        if (cur == parent->left) {
          Tree_RotateRight_Color2C(map, parent);
          cur = parent;
          parent = cur->parent;
        }
        *NodeColor(cur->parent) = 1;
        *NodeColor(cur->parent->parent) = 0;
        Tree_RotateLeft_Color2C(map, cur->parent->parent);
      }
    }
  }

  // root black
  *NodeColor(map->head->parent) = 1;
  *outIt = node;
}

// Alias for Ghidra name consumers
void FUN_00430b60(MapShell *map, StringKeyMapNode *where, StringKeyMapNode **outIt,
                  char addLeft, const void *valuePair)
{
  StdMap_StringKey_InsertNodeAndRebalance(map, where, outIt, addLeft, valuePair);
}
