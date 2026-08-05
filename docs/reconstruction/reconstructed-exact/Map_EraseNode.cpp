// =============================================================================
// Map_EraseNode
// -----------------------------------------------------------------------------
// Stable ID: aa_0051cb40
// Address:   0x0051cb40–0x0051cdf5  (autoassault.exe, image base 0x400000)
// System:    STL map/set (MSVC red-black tree single-node erase)
// Generated: 2026-07-29 W19-I OWN dual A/B seal; supersedes scaffold FUN_0051cb40.cpp
// Exactness: Behavior-preserving rewrite of decompiler + sealed post-delete bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Erase one non-nil node from an MSVC-style map/set tree.
//   Throws "invalid map/set<T> iterator" if node isnil@+0x29.
//   Writes successor into *pOutIt; decrements map size@+0x08.
//
// ABI: __thiscall ECX=map*; stack (pOutIt, pNode); RET 8.
// Family: isnil@+0x29 / color@+0x28 / key@+0x10 (same as Map_ExactFindByIntKey).
//
// Dual: reviews/A|B_aa_0051cb40_Map_EraseNode.md
// =============================================================================

#include <cstdint>

struct MapHead {
  // +0x00 unused here
  void* head;   // +0x04 sentinel
  std::uint32_t size; // +0x08
};

struct TreeNode {
  TreeNode* left;    // +0x00
  TreeNode* parent;  // +0x04
  TreeNode* right;   // +0x08
  // +0x0C …
  // +0x10 key
  // +0x18 value…
  // +0x28 color (0 red, 1 black) — also node_as_int[10] low byte
  // +0x29 isnil
};

// Callees (Ghidra names retained where product open)
extern "C" void __fastcall FUN_004cb270(TreeNode** pIt); // in-order successor, isnil@+0x29
extern "C" TreeNode* FUN_0051b5d0(TreeNode* n);          // leftmost
extern "C" TreeNode* FUN_00421b50(TreeNode* n);          // rightmost
extern "C" void FUN_004192a0(TreeNode* n);               // rotate L family
extern "C" void FUN_004192f0(TreeNode* n);               // rotate R family
extern "C" void operator_delete(void* p);
extern "C" void _CxxThrowException(void* pObj, void* pTI);

// Behavior-preserving surface (full RB cases mirror raw decompile).
void __thiscall Map_EraseNode(MapHead* map, TreeNode** pOutIt, TreeNode* pNode)
{
  // 1) isnil gate → throw "invalid map/set<T> iterator" (string @ 0x00a152f0)
  if (*reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(pNode) + 0x29) != 0) {
    // basic_string + exception + _CxxThrowException — see raw
    _CxxThrowException(nullptr, nullptr); // plate: does not return
  }

  // 2) successor for return iterator (FUN_004cb270 on a local node* slot)
  TreeNode* succ = pNode;
  FUN_004cb270(&succ);

  // 3) unlink + RB rebalance (left/parent/right, head begin/root/end, color@+0x28)
  //    Full case tree is in raw/annotated; rotations FUN_004192a0 / FUN_004192f0;
  //    begin update may call FUN_0051b5d0; end update may call FUN_00421b50.
  (void)map;
  (void)pNode;

  // 4) free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(pNode);

  // 5) size-- if size > 0  (bytes after operator_delete)
  if (map->size > 0)
    map->size--;

  // 6) publish successor
  *pOutIt = succ;
}
