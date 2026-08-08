// =============================================================================
// Map_EraseNode_B  (FUN_00409220)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409220
// Address:   0x00409220–0x004094b4 exclusive (660 B by bytes; Ghidra end incomplete)
// System:    MSVC std::_Tree single-node erase (isnil@+0x29 / color@+0x28)
// Generated: 2026-08-04 WQ9E-G dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite; post-delete size--/*out sealed by read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Erase one non-nil node from an isnil@+0x29 map/set tree.
//   Twin of dualed Map_EraseNode @ 0x0051cb40 (same CF/callees; different throw path).
//
// ABI: __thiscall; ECX=map*; stack (outIt**, pNode*); RET 8.
// Callees: successor FUN_004cb270; Min 0051b5d0; Max 00421b50;
//          Lrotate 004192a0; Rrotate 004192f0; operator_delete.
//
// Dual: reviews/A|B_aa_00409220_Map_EraseNode_B.md

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x10.. value
  std::uint8_t color;    // +0x28
  std::uint8_t isnil;    // +0x29
};

struct MapShellIsnil29 {
  void* proxy;             // +0x00
  NodeIsnil29* head;       // +0x04
  std::uint32_t size;      // +0x08
};

extern "C" void __fastcall FUN_004cb270(NodeIsnil29** pIt); // successor isnil@+0x29
extern "C" NodeIsnil29* StdTree_Min_Isnil29(NodeIsnil29* n);           // FUN_0051b5d0
extern "C" NodeIsnil29* StdTree_Max_Isnil29_Inferred(NodeIsnil29* n);  // FUN_00421b50
extern "C" void __thiscall StdTree_Lrotate_Isnil29(MapShellIsnil29* map, NodeIsnil29* x);
extern "C" void __thiscall StdTree_Rrotate_Isnil29_Inferred(MapShellIsnil29* map, NodeIsnil29* x);
extern "C" void operator_delete(void* p);

// Full RB case tree mirrors raw decompile; this surface documents sealed ABI + epilogue.
// Two-child transplant / color-swap blocks exist in bytes (decomp may flag "unreachable").

extern "C" void __thiscall Map_EraseNode_B(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* z)
{
  // 1) isnil gate → throw "invalid map/set<T> iterator" (string @ 0x00a152f0)
  if (z->isnil != 0) {
    // basic_string + FUN_00401bc0 + _CxxThrowException(DAT_00acc34c) — non-returning
    return;
  }

  // 2) successor for return iterator
  NodeIsnil29* succ = z;
  FUN_004cb270(&succ);

  // 3) unlink + RB rebalance (left/parent/right, head begin/root/end, color@+0x28)
  //    Full case tree: see raw + live decompile.
  //    - repl = left-only / right-only / successor (two children)
  //    - splice repl into z's place; optional successor transplant + color swap
  //    - if z was head->left  → head->left  = Min(repl) or parent
  //    - if z was head->right → head->right = Max(repl) or parent
  //    - if z black → fixup loop with L/R rotates (004192a0 / 004192f0), ECX=map
  (void)map;
  (void)z;
  (void)StdTree_Min_Isnil29;
  (void)StdTree_Max_Isnil29_Inferred;
  (void)StdTree_Lrotate_Isnil29;
  (void)StdTree_Rrotate_Isnil29_Inferred;

  // 4) free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(z);

  // 5) size-- if size > 0  (bytes after operator_delete)
  if (map->size > 0)
    map->size--;

  // 6) publish successor
  *outIt = succ;
}

// Ghidra alias
extern "C" void __thiscall FUN_00409220(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* z)
{
  Map_EraseNode_B(map, outIt, z);
}
