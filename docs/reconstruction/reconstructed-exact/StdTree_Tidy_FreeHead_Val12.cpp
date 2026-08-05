// =============================================================================
// StdTree_Tidy_FreeHead_Val12  (aa_0040d7c0)
// -----------------------------------------------------------------------------
// Address:   0x0040d7c0  (autoassault.exe, image base 0x400000)
// Body:      0x0040d7c0 – 0x0040d81c exclusive (92 B / 0x5C); pad CC
// Wave:      W32-B OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Post-delete epilogue uses bytes (decompiler false-noreturn truncated).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // isnil at +0x19
};

// Tree subobject as seen by this unit (host complete-dtor passes this+4):
//   +0x04 head (_Myhead)
//   +0x08 size (_Mysize)
struct StdTree_Val12 {
  void* _unused0;             // +0x00 (aligns under host+4)
  StdTreeNode_Val12* head;    // +0x04
  uint32_t size;              // +0x08
};

// Nested (not owned here): full-range erase; when (first==*head && last==head)
// frees root via StdTree_FreeSubtree_Val12(head->parent) and resets sentinel/size.
extern "C" void __thiscall FUN_0040d700(StdTree_Val12* tree,
                                        void* out_iter,
                                        StdTreeNode_Val12* first,
                                        StdTreeNode_Val12* last);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree subobject*. Bare RET. void.
// MSVC-style _Tree tidy: erase full content, free header node, null head+size.
extern "C" void __fastcall StdTree_Tidy_FreeHead_Val12(StdTree_Val12* tree)
{
  // SEH: LAB_009bda78 (omitted in clean; present in retail)
  void* out = nullptr;
  StdTreeNode_Val12* head = tree->head;
  // full range: begin = *head (left), end = head
  FUN_0040d700(tree, &out, head->left, head);
  operator_delete(head);
  tree->head = nullptr;
  tree->size = 0;
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0040d7c0(StdTree_Val12* tree)
{
  StdTree_Tidy_FreeHead_Val12(tree);
}
