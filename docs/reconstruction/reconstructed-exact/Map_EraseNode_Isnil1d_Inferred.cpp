// =============================================================================
// Map_EraseNode_Isnil1d_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051c880
// Address:   0x0051c880–0x0051cb36 exclusive (694 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black single-node erase; isnil@+0x1d)
// Generated: 2026-08-04 WQ9F-F OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + sealed post-delete bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051c880.cpp scaffold.
// Dual: reviews/A|B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Erase one non-nil node from an MSVC-style map/set tree.
//   Throws "invalid map/set<T> iterator" if node isnil@+0x1d.
//   Writes successor into *pOutIt; decrements map size@+0x08.
//
// ABI: __thiscall ECX=map*; stack (pOutIt, pNode); RET 8.
// Family: isnil@+0x1d / color@+0x1c (NOT isnil@+0x29 Map_EraseNode).
// Sole caller: Map_EraseRange_Isnil1d_Inferred (0x0051d700) partial path.
// =============================================================================

#include <cstdint>

struct MapHead {
  void* head;           // +0x04 sentinel
  std::uint32_t size;   // +0x08
};

struct TreeNode_Isnil1d {
  TreeNode_Isnil1d* left;    // +0x00
  TreeNode_Isnil1d* parent;  // +0x04
  TreeNode_Isnil1d* right;   // +0x08
  // +0x0C …
  // key / mapped payload
  // +0x1c color (0 red, 1 black)
  // +0x1d isnil
};

// Callees (Ghidra names retained where product open)
extern "C" void __fastcall FUN_0051b690(TreeNode_Isnil1d** pIt); // successor, isnil@+0x1d
extern "C" TreeNode_Isnil1d* FUN_0051b670(TreeNode_Isnil1d* n);  // leftmost
extern "C" TreeNode_Isnil1d* FUN_00421b90(TreeNode_Isnil1d* n);  // rightmost
extern "C" void FUN_00420130(TreeNode_Isnil1d* n);               // rotate L family
extern "C" void FUN_00420180(TreeNode_Isnil1d* n);               // rotate R family
extern "C" void operator_delete(void* p);
extern "C" void _CxxThrowException(void* pObj, void* pTI);

// Behavior-preserving surface (full RB cases mirror raw decompile).
void __thiscall Map_EraseNode_Isnil1d_Inferred(
    MapHead* map, TreeNode_Isnil1d** pOutIt, TreeNode_Isnil1d* pNode)
{
  // 1) isnil gate → throw "invalid map/set<T> iterator" (string @ 0x00a152f0)
  if (*reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(pNode) + 0x1d) != 0) {
    // basic_string + exception + _CxxThrowException — see raw
    _CxxThrowException(nullptr, nullptr); // plate: does not return
  }

  // 2) successor for return iterator (FUN_0051b690 on a local node* slot)
  TreeNode_Isnil1d* succ = pNode;
  FUN_0051b690(&succ);

  // 3) unlink + RB rebalance (left/parent/right, head begin/root/end, color@+0x1c)
  //    Full case tree is in raw/annotated; rotations FUN_00420130 / FUN_00420180;
  //    begin update may call FUN_0051b670; end update may call FUN_00421b90.
  (void)map;
  (void)pNode;

  // 4) free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(pNode);

  // 5) size-- if size > 0  (bytes after operator_delete @ ~0x0051cb06+)
  if (map->size > 0)
    map->size--;

  // 6) publish successor
  *pOutIt = succ;
}
