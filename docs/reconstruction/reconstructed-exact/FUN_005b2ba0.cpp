// =============================================================================
// FUN_005b2ba0  (twin of GuardedVector_Dtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2ba0
// Address:   0x005b2ba0–0x005b2c05  (autoassault.exe, image base 0x400000)
// Dual:      W37-D 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Prefer GuardedVector_Dtor_Inferred.cpp for named surface.
// This twin keeps the Ghidra symbol for searchability.

struct GuardedVectorHeader {
  uint32_t  _unk00;
  uint32_t** pages;     // +0x04
  int32_t   capacity;   // +0x08
  int32_t   begin;      // +0x0c
  int32_t   size;       // +0x10
};

extern "C" void __cdecl operator_delete(void* p);

void __fastcall FUN_005b2ba0(GuardedVectorHeader* param_1 /*ECX*/)
{
  int32_t iVar2;
  void* pvVar1;

  iVar2 = param_1->size;
  while (iVar2 != 0) {
    if (param_1->size != 0) {
      iVar2 = param_1->size - 1;
      param_1->size = iVar2;
      if (iVar2 == 0) {
        param_1->begin = 0;
      }
    }
    iVar2 = param_1->size;
  }

  iVar2 = param_1->capacity;
  while (iVar2 != 0) {
    pvVar1 = param_1->pages[iVar2 - 1];
    iVar2 = iVar2 - 1;
    if (pvVar1 != nullptr) {
      operator_delete(pvVar1);
    }
  }

  // Bytes always clear capacity/pages after optional map free.
  if (param_1->pages != nullptr) {
    operator_delete(param_1->pages);
  }
  param_1->capacity = 0;
  param_1->pages = nullptr;
}
