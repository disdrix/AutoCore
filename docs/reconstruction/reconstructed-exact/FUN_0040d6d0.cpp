// =============================================================================
// FUN_0040d6d0 — scaffold twin of StdTree_Tidy_FreeHead_Bare_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d6d0
// Address:   0x0040d6d0 – 0x0040d6fe exclusive (46 B / 0x2E)
// Wave:      W33-A 2026-07-29 (replaces 2026-07-23 scaffold; bytes seal epilogue)
// Canonical: StdTree_Tidy_FreeHead_Bare_Val12.cpp
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;
  StdTreeNode_Val12* parent;
  StdTreeNode_Val12* right;
};

struct StdTree_Val12 {
  void* _unused0;
  StdTreeNode_Val12* head;
  uint32_t size;
};

extern "C" void __thiscall FUN_0040d700(StdTree_Val12* tree,
                                        void* out_iter,
                                        StdTreeNode_Val12* first,
                                        StdTreeNode_Val12* last);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree*; bare RET; void. False noreturn after delete ignored.
extern "C" void __fastcall FUN_0040d6d0(StdTree_Val12* tree)
{
  void* out;
  StdTreeNode_Val12* head = tree->head;
  FUN_0040d700(tree, &out, head->left, head);
  operator_delete(head);
  tree->head = nullptr;
  tree->size = 0;
}
