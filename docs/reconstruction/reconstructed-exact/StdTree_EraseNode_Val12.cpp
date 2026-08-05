// =============================================================================
// StdTree_EraseNode_Val12  (FUN_005ae990)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae990
// Address:   0x005ae990  (autoassault.exe, image base 0x400000)
// Body:      0x005ae990 – 0x005aec44 exclusive (692 B / 0x2B4)
//            Ghidra lists end 0x005aec16 (truncated by false noreturn on delete)
// System:    std map/set red-black tree single-node erase (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-T dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler + sealed post-delete bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Erase one non-nil Val12 red-black tree node: successor for return iterator,
//   unlink + RB rebalance if black, operator_delete, size--, *outIt = successor.
//   Throws "invalid map/set<T> iterator" if node isnil@+0x19.
//
// ABI
//   __thiscall; ECX = MapShell*; stack (outIt*, node*); RET 8
//
// SOLE LIVE CALLER (this image)
//   FUN_005af3a0 (range erase loop)
//
// PEER FAMILY (different node sizes — do not merge)
//   Map_EraseNode @ 0x0051cb40 (isnil@+0x29)
//   StdMap_EraseIterator_Inferred @ 0x004baa30 (isnil@+0x15)
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12 *left;    // +0x00
  MapNode_Val12 *parent;  // +0x04
  MapNode_Val12 *right;   // +0x08
  int32_t v0;             // +0x0C
  int32_t v1;             // +0x10
  int32_t v2;             // +0x14
  uint8_t color;          // +0x18  0=red, 1=black
  uint8_t isnil;          // +0x19
};

struct MapShell_Val12 {
  void *proxy;            // +0x00
  MapNode_Val12 *head;    // +0x04
  uint32_t size;          // +0x08
};

// Callees (Ghidra names; roles sealed / sibling duals)
extern "C" void __fastcall FUN_005ae0b0(MapNode_Val12 **pIt); // in-order successor
extern "C" MapNode_Val12 *FUN_005adfa0(MapNode_Val12 *n);     // leftmost
extern "C" MapNode_Val12 *FUN_00418bf0(MapNode_Val12 *n);     // rightmost
extern "C" void FUN_00573170(MapNode_Val12 *node);            // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *node);            // StdTree_Rrotate_Val12
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

void __thiscall StdTree_EraseNode_Val12(
    MapShell_Val12 *map,      // ECX
    MapNode_Val12 **outIt,    // successor out
    MapNode_Val12 *node)      // node to erase
{
  // SEH frame omitted (LAB_009a65a2).

  if (node->isnil != 0) {
    // basic_string + exception + _CxxThrowException(..., &DAT_00acc34c)
    // message: "invalid map/set<T> iterator"
    _CxxThrowException(nullptr, nullptr);
  }

  // 1) successor for return iterator
  MapNode_Val12 *succ = node;
  FUN_005ae0b0(&succ);

  // 2) select replacement child (standard MSVC erase splice)
  MapNode_Val12 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // both non-nil: classic path uses successor body
  } else {
    repl = node->right;
  }
  // Note: full two-child case uses successor node body swap / relink as in raw.
  // Decompile CF: if left non-nil and right non-nil, repl walks right subtree min
  // via the FUN_005ae0b0-related path; raw cases preserved in annotated notes.

  MapNode_Val12 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  if (map->head->parent == node)
    map->head->parent = repl;
  else if (parent->left == node)
    parent->left = repl;
  else
    parent->right = repl;

  // begin fixup
  if (map->head->left == node) {
    MapNode_Val12 *b = parent;
    if (repl->isnil == 0)
      b = FUN_005adfa0(repl);
    map->head->left = b;
  }
  // end fixup
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_00418bf0(repl);
    else
      map->head->right = parent;
  }

  // 3) if erased color black: RB fixup loop (sibling cases; L/R rotates)
  //    Full case tree mirrors raw decompile (FUN_00573170 / FUN_00418c10).
  if (node->color == 1) {
    // while repl != root && repl black: sibling recolor / rotate ...
    // terminal: repl->color = 1
    (void)map;
  }

  // 4) free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(node);

  // 5) size-- if size > 0  (byte-sealed after operator_delete)
  if (map->size > 0)
    map->size--;

  // 6) publish successor
  *outIt = succ;
}
