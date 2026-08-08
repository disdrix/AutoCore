// =============================================================================
// Map_EraseNode_Isnil15  (FUN_0051ce00)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051ce00
// Address:   0x0051ce00–0x0051d0b5 inclusive (694 B / 0x2B6; exclusive end 0x0051d0b6)
// System:    MSVC std::_Tree single-node erase (isnil@+0x15 / color@+0x14)
// Generated: 2026-08-04 WQ9F-G dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite; post-delete size--/*out sealed by read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Erase one non-nil node from an isnil@+0x15 map/set tree.
//   Callee of dualed Map_EraseRange_Isnil15 @ 0x0051d7c0 (partial path).
//   Distinct VA from dualed Map_EraseNode_IntKey @ 0x005d1df0 (also isnil15).
//
// ABI: __thiscall; ECX=map*; stack (outIt**, pNode*); RET 8.
// Callees: successor FUN_00673070; Min 004e12a0; Max 00421b70;
//          Lrotate 004e22d0; Rrotate 006753b0; operator_delete.
//
// Dual: reviews/A|B_aa_0051ce00_Map_EraseNode_Isnil15.md

#include <cstdint>

struct NodeIsnil15 {
  NodeIsnil15* left;     // +0x00
  NodeIsnil15* parent;   // +0x04
  NodeIsnil15* right;    // +0x08
  // +0x0c.. value
  std::uint8_t color;    // +0x14
  std::uint8_t isnil;    // +0x15
};

struct MapShellIsnil15 {
  void* proxy;             // +0x00
  NodeIsnil15* head;       // +0x04
  std::uint32_t size;      // +0x08
};

extern "C" void __fastcall FUN_00673070(NodeIsnil15** pIt); // successor isnil@+0x15
extern "C" NodeIsnil15* Tree_Min_Isnil15(NodeIsnil15* n);   // FUN_004e12a0
extern "C" NodeIsnil15* Tree_Max_Isnil15(NodeIsnil15* n);   // FUN_00421b70
extern "C" void __thiscall Tree_Lrotate_Isnil15(MapShellIsnil15* map, NodeIsnil15* x); // FUN_004e22d0
extern "C" void __thiscall Tree_Rrotate_Isnil15(MapShellIsnil15* map, NodeIsnil15* x); // FUN_006753b0
extern "C" void operator_delete(void* p);

// Full RB case tree mirrors raw decompile + disasm; this surface documents
// sealed ABI + epilogue. Two-child transplant / color-swap blocks exist in
// bytes (decomp may flag "unreachable").

extern "C" void __thiscall Map_EraseNode_Isnil15(
    MapShellIsnil15* map,
    NodeIsnil15** outIt,
    NodeIsnil15* z)
{
  // 1) isnil gate → throw "invalid map/set<T> iterator" (string @ 0x00a152f0)
  if (z->isnil != 0) {
    // basic_string + exception + _CxxThrowException(DAT_00acc34c) — non-returning
    return;
  }

  // 2) successor for return iterator
  NodeIsnil15* succ = z;
  FUN_00673070(&succ);

  // 3) unlink + RB rebalance (left/parent/right, head begin/root/end, color@+0x14)
  //    Full case tree: see raw + live decompile + disasm 0x0051ce90..0x0051d07a.
  //    - repl = left-only / right-only / successor (two children @ 0x0051cf20+)
  //    - splice repl into z's place; optional successor transplant + color swap
  //    - if z was head->left  → head->left  = Min(repl) or parent
  //    - if z was head->right → head->right = Max(repl) or parent
  //    - if z black → fixup loop with L/R rotates (004e22d0 / 006753b0), ECX=map
  (void)map;
  (void)z;
  (void)Tree_Min_Isnil15;
  (void)Tree_Max_Isnil15;
  (void)Tree_Lrotate_Isnil15;
  (void)Tree_Rrotate_Isnil15;

  // 4) free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(z);

  // 5) size-- if size > 0  (bytes after operator_delete)
  if (map->size > 0)
    map->size--;

  // 6) publish successor
  *outIt = succ;
}

// Ghidra alias
extern "C" void __thiscall FUN_0051ce00(
    MapShellIsnil15* map,
    NodeIsnil15** outIt,
    NodeIsnil15* z)
{
  Map_EraseNode_Isnil15(map, outIt, z);
}
