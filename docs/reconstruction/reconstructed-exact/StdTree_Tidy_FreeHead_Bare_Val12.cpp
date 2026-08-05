// =============================================================================
// StdTree_Tidy_FreeHead_Bare_Val12  (aa_0040d6d0)
// -----------------------------------------------------------------------------
// Address:   0x0040d6d0 – 0x0040d6fe exclusive (46 B / 0x2E)
//            autoassault.exe, image base 0x400000
// Wave:      W33-A OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Post-delete epilogue from bytes (decompiler false
//            noreturn truncates after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=tree*; bare RET (C3); void. No SEH frame.
// Peer:      StdTree_Tidy_FreeHead_Val12 @ 0x0040d7c0 (W32-B; SEH + same tidy)
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // isnil at +0x19 (Val12)
};

// Tree facade (same offsets as W32-B tidy peer):
//   +0x04 head (_Myhead)
//   +0x08 size (_Mysize)
struct StdTree_Val12 {
  void* _unused0;             // +0x00
  StdTreeNode_Val12* head;    // +0x04
  uint32_t size;              // +0x08
};

// Nested (W32-C): full-range erase; when (first==*head && last==head)
// frees root via StdTree_FreeSubtree_Val12(head->parent) and resets sentinel/size.
// ECX=tree; stack out*, first*, last*; RET 0x0C.
extern "C" void __thiscall StdTree_EraseRange_Val12(StdTree_Val12* tree,
                                                    void* out_iter,
                                                    StdTreeNode_Val12* first,
                                                    StdTreeNode_Val12* last); // 0x0040d700
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree*. Bare RET. void.
// MSVC-style _Tree tidy without SEH: erase full content, free header, null head+size.
extern "C" void __fastcall StdTree_Tidy_FreeHead_Bare_Val12(StdTree_Val12* tree)
{
  void* out; // stack slot only (entry push ECX leaves garbage/this; unused as value)
  StdTreeNode_Val12* head = tree->head;
  // full range: begin = *head (left), end = head
  StdTree_EraseRange_Val12(tree, &out, head->left, head);
  operator_delete(head);
  tree->head = nullptr;
  tree->size = 0;
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0040d6d0(StdTree_Val12* tree)
{
  StdTree_Tidy_FreeHead_Bare_Val12(tree);
}
