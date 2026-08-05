// =============================================================================
// StdTree_Clear_PtrVal_Vtbl0C  (aa_0040d5b0)
// -----------------------------------------------------------------------------
// Address:   0x0040d5b0  (autoassault.exe, image base 0x400000)
// Wave:      W30-P OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Free path uses bytes (decompiler false-noreturn collapsed it).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // ... padding / color ...
  // isnil at +0x19
  // T* value at +0x14 (overlaps header layout of Val12 family)
};

// Host: head @ +0x08, size @ +0x0c (tree subobject effectively at +0x04).
struct TreeHost_Head8 {
  uint32_t _pad0;             // +0x00
  uint32_t _pad4;             // +0x04 (EDI = this+4 in free path)
  StdTreeNode_Val12* head;    // +0x08
  uint32_t size;              // +0x0c
};

extern "C" void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12** it); // 0x005ae0b0
extern "C" void __fastcall FUN_0040d630(void* tree_base /*ECX*/, StdTreeNode_Val12* node);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree host. Bare RET. void.
// Phase 1: for each in-order node, thiscall vtbl[+0x0c] on *(node+0x14).
// Phase 2: free all non-nil nodes (right-subtree helper + left walk).
// Phase 3: reset empty sentinel (parent/left/right = head, size = 0).
extern "C" void __fastcall StdTree_Clear_PtrVal_Vtbl0C(TreeHost_Head8* self)
{
  StdTreeNode_Val12* head = self->head;
  StdTreeNode_Val12* it = head->left;

  while (it != head) {
    void* obj = *reinterpret_cast<void**>(reinterpret_cast<char*>(it) + 0x14);
    auto** vtbl = *reinterpret_cast<void***>(obj);
    reinterpret_cast<void(__fastcall*)(void*)>(vtbl[3])(obj); // [eax+0x0c]
    StdTree_Inc_Val12(&it);
    head = self->head; // re-read as in decompile loop
  }

  StdTreeNode_Val12* root =
      *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(self->head) + 4);

  // tree_base = this+4 (bytes: lea edi,[esi+4])
  void* tree_base = reinterpret_cast<char*>(self) + 4;

  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(root) + 0x19) == 0) {
    StdTreeNode_Val12* node = root;
    while (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x19) == 0) {
      StdTreeNode_Val12* right =
          *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(node) + 8);
      FUN_0040d630(tree_base, right);
      StdTreeNode_Val12* left =
          *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(node) + 0);
      operator_delete(node);
      node = left;
    }
  }

  // empty reset
  StdTreeNode_Val12* h = self->head;
  *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(h) + 4) = h; // parent
  self->size = 0;
  *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(h) + 0) = h; // left
  *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(h) + 8) = h; // right
}

// Scaffold alias
extern "C" void __fastcall FUN_0040d5b0(TreeHost_Head8* self)
{
  StdTree_Clear_PtrVal_Vtbl0C(self);
}
