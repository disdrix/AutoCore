// =============================================================================
// StdTreeHost_PtrVal_CompleteDtor  (aa_0040d820)
// -----------------------------------------------------------------------------
// Address:   0x0040d820  (autoassault.exe, image base 0x400000)
// Wave:      W31-A OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            FUN_0040d7c0 target is this+4 (bytes LEA ECX,[ESI+4]).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Host layout hooks (partial): vtbl@+0, tree subobject base@+4, head@+8, size@+0xc.
struct TreeHost_Head8 {
  void* vtbl;                 // +0x00 → PTR_FUN_009c7938 after install
  uint32_t tree_sub_pad;      // +0x04 base for FUN_0040d7c0
  void* head;                 // +0x08
  uint32_t size;              // +0x0c
};

// Sealed clear (W30-P). ECX = host.
extern "C" void __fastcall StdTree_Clear_PtrVal_Vtbl0C(TreeHost_Head8* self); // 0x0040d5b0
// Nested head/subobject teardown (not owned this wave). ECX = this+4.
extern "C" void __fastcall FUN_0040d7c0(void* tree_sub);

// Retail vtbl symbol (Ghidra).
extern "C" void* PTR_FUN_009c7938;

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall StdTreeHost_PtrVal_CompleteDtor(TreeHost_Head8* self)
{
  // SEH: push -1; push LAB_009be2bb; link ExceptionList (omitted as runtime frame)
  self->vtbl = &PTR_FUN_009c7938;
  // EH state = 0
  StdTree_Clear_PtrVal_Vtbl0C(self);
  // EH state = -1
  FUN_0040d7c0(reinterpret_cast<char*>(self) + 4);
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0040d820(TreeHost_Head8* self)
{
  StdTreeHost_PtrVal_CompleteDtor(self);
}
