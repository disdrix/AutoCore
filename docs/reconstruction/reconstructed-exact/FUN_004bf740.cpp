// =============================================================================
// FUN_004bf740  (canonical: OwningSList_ClearDestroy_ScalarDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf740
// Address:   0x004bf740  (autoassault.exe, image base 0x400000)
// System:    owning singly-linked list clear
// Generated: 2026-07-29 W31-B (twin of OwningSList_ClearDestroy_ScalarDtor_Inferred.cpp)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Twin entry: keep Ghidra symbol name for scaffold linkage. Prefer the named
// clean source for product English.

#include <cstdint>

void __fastcall FUN_004bf740(int param_1)
{
  int iVar1;
  uint32_t* puVar2;

  iVar1 = *(int*)(param_1 + 4);
  while (iVar1 != 0) {
    puVar2 = *(uint32_t**)(param_1 + 4);
    if (puVar2 != nullptr) {
      *(uint32_t*)(param_1 + 4) = puVar2[1];
      // vtbl[0](node, 1) — scalar deleting dtor
      (**(void(***)(int)) * puVar2)(1);
      *(int*)(param_1 + 0xc) = *(int*)(param_1 + 0xc) + -1;
    }
    iVar1 = *(int*)(param_1 + 4);
  }
  return;
}
