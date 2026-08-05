// =============================================================================
// FUN_00538ea0 — Map_InsertNodeAndRebalance (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00538ea0
// Address:   0x00538ea0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seals.
//            Not modernization. Not bit-for-bit vs retail EXE (deferred).
// Dual:      reviews/A_aa_00538ea0_Map_InsertNodeAndRebalance.md
//            reviews/B_aa_00538ea0_Map_InsertNodeAndRebalance.md
// =============================================================================
//
// PURPOSE:
//   MSVC-like _Tree insert helper for the mission-staging map (0x50 nodes).
//   ALWAYS allocates + links + red-black rebalances. Not insert-or-find
//   (parent FUN_00539cb0 owns key walk / equal-key find-only).
//
// ABI: __thiscall; RET 0x10; ECX = MapShell*
//   args: Node** outIt, char addLeft, Node* where, const void* valuePair
// Sole static caller: FUN_00539cb0 (×2 sites).
//
// Layout (sealed dual 2026-07-29):
//   MapShell: +4 head*, +8 size (throw if size > 0x4924922)
//   head: [0] leftmost, [1] root, [2] rightmost
//   Node 0x50: L/P/R @0/4/8; value[14 dwords]@0x10; color@0x48 (0=red,1=black);
//              isnil@0x49
//   Ctor FUN_005380d0: new(0x50), copy 0xE dwords, color arg, isnil=0
//   Rotates: FUN_005681a0 right; FUN_00568b70 left (this=map); one L-rot inlined
// =============================================================================

#include <cstdint>

// Callees (Ghidra names retained):
//   FUN_005380d0 — node construct 0x50 (RET 0x14)
//   FUN_005681a0 — __thiscall Tree_RotateRight(map, node*)
//   FUN_00568b70 — __thiscall Tree_RotateLeft(map, node*)

extern "C" uint32_t* __cdecl FUN_005380d0(uint32_t left, uint32_t parent, uint32_t right,
                                          const void* valuePair, uint8_t color);
extern "C" void __thiscall FUN_005681a0(int mapThis, uint32_t* node);
extern "C" void __thiscall FUN_00568b70(int mapThis, uint32_t* node);

// Returns: *outIt written; EAX typically holds outIt* at epilogue (MSVC).
extern "C" uint32_t* __thiscall FUN_00538ea0(int mapThis,
                                             uint32_t* outIt,
                                             char addLeft,
                                             uint32_t* where,
                                             const void* valuePair)
{
  char parentColor;
  uint32_t* parent;
  uint32_t* uncle;
  uint32_t* node;
  uint32_t* pParentSlot;
  uint32_t* grand;
  int g;
  uint32_t* y;
  uint32_t* walk;

  // if (map->size > 0x4924922) throw "map/set<T> too long"
  if (0x4924922 < *(uint32_t*)(mapThis + 8)) {
    // std::basic_string / exception / _CxxThrowException path (raw)
    // does not return
    __builtin_unreachable();
  }

  // new node: left=head, parent=where, right=head, color=red(0)
  node = FUN_005380d0(*(uint32_t*)(mapThis + 4), (uint32_t)where,
                      *(uint32_t*)(mapThis + 4), valuePair, 0);

  *(int*)(mapThis + 8) = *(int*)(mapThis + 8) + 1;

  if (where == *(uint32_t**)(mapThis + 4)) {
    // empty tree: root = leftmost = rightmost = node
    (*(uint32_t**)(mapThis + 4))[1] = (uint32_t)node;
    **(uint32_t**)(mapThis + 4) = (uint32_t)node;
    *(uint32_t**)(*(int*)(mapThis + 4) + 8) = node;
  } else if (addLeft == '\0') {
    where[2] = (uint32_t)node; // right
    if (where == *(uint32_t**)(*(int*)(mapThis + 4) + 8)) {
      *(uint32_t**)(*(int*)(mapThis + 4) + 8) = node; // rightmost
    }
  } else {
    *where = (uint32_t)node; // left
    if (where == (uint32_t*)**(int**)(mapThis + 4)) {
      **(int**)(mapThis + 4) = (int)node; // leftmost
    }
  }

  parentColor = *(char*)(node[1] + 0x48);
  walk = node;
  do {
    if (parentColor != '\0') {
      // parent black (or head): stop; paint root black
      *(uint8_t*)(*(int*)(*(int*)(mapThis + 4) + 4) + 0x48) = 1;
      *outIt = (uint32_t)node;
      return outIt;
    }

    // parent red — classic RB insert fixup
    pParentSlot = walk + 1;           // &walk->parent
    parent = (uint32_t*)*pParentSlot;
    uncle = *(uint32_t**)parent[1];   // grandparent->left

    if (parent == uncle) {
      // parent is left child of grandparent
      uncle = (uint32_t*)((uint32_t*)parent[1])[2]; // grandparent->right
      if ((char)uncle[0x12] == '\0') {
        // uncle red → recolor
      LAB_recolor:
        *(uint8_t*)(*pParentSlot + 0x48) = 1;                 // parent black
        *(uint8_t*)(uncle + 0x12) = 1;                        // uncle black (+0x48)
        *(uint8_t*)(*(int*)(*pParentSlot + 4) + 0x48) = 0;    // grand red
        walk = *(uint32_t**)(*pParentSlot + 4);               // continue at grand
      } else {
        if (walk == (uint32_t*)parent[2]) {
          // node is right of parent → left-rotate parent
          FUN_00568b70(mapThis, parent);
          walk = parent;
        }
        *(uint8_t*)(walk[1] + 0x48) = 1;
        *(uint8_t*)(*(int*)(walk[1] + 4) + 0x48) = 0;
        FUN_005681a0(mapThis, *(uint32_t**)(walk[1] + 4)); // right-rotate grand
      }
    } else {
      // parent is right child of grandparent
      if ((char)uncle[0x12] == '\0')
        goto LAB_recolor;
      if (walk == (uint32_t*)*parent) {
        // node is left of parent → right-rotate parent
        FUN_005681a0(mapThis, parent);
        walk = parent;
      }
      *(uint8_t*)(walk[1] + 0x48) = 1;
      *(uint8_t*)(*(int*)(walk[1] + 4) + 0x48) = 0;
      // inlined left-rotate of grandparent (≡ FUN_00568b70)
      g = *(int*)(walk[1] + 4);
      y = *(uint32_t**)(g + 8);
      *(int*)(g + 8) = *y;
      if (*(char*)(*y + 0x49) == '\0') {
        *(int*)(*y + 4) = g;
      }
      y[1] = *(int*)(g + 4);
      if (g == *(int*)(*(int*)(mapThis + 4) + 4)) {
        *(uint32_t**)(*(int*)(mapThis + 4) + 4) = y;
      } else {
        grand = *(uint32_t**)(g + 4);
        if (g == (int)*grand) {
          *grand = (uint32_t)y;
        } else {
          grand[2] = (uint32_t)y;
        }
      }
      *y = g;
      *(uint32_t**)(g + 4) = y;
    }
    parentColor = *(char*)(walk[1] + 0x48);
  } while (true);
}
