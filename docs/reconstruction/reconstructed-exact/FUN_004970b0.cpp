// =============================================================================
// FUN_004970b0  (named: Class_009c7a1c_CompleteDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004970b0
// Address:   0x004970b0  (autoassault.exe, image base 0x400000)
// System:    class complete-object destructor (vtbl PTR_FUN_009c7a1c)
// Generated: 2026-07-29 W28-M (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. See Class_009c7a1c_CompleteDtor.cpp.
// =============================================================================

// PURPOSE: Complete dtor body for vtbl PTR_FUN_009c7a1c.
// See docs/reconstruction/functions/aa_004970b0_Class_009c7a1c_CompleteDtor.md

#include <cstdint>

extern "C" void *__cdecl operator_delete(void *p);
extern "C" void *__cdecl operator_delete__(void *p);
extern "C" void __cdecl _eh_vector_destructor_iterator_(
    void *array, unsigned size, int count, void (__thiscall *dtor)(void *));
extern "C" void __thiscall FUN_005b8000(void *elem);
extern "C" void __thiscall FUN_00497360(void *list); // StdList_Destroy_FreeHead
extern "C" void *PTR_FUN_009c7a1c;

void __thiscall FUN_004970b0(void *param_1)
{
  auto *self = reinterpret_cast<uint8_t *>(param_1);

  *reinterpret_cast<void **>(self) = &PTR_FUN_009c7a1c;

  void *arr = *reinterpret_cast<void **>(self + 0x28);
  if (arr != nullptr) {
    int count = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(arr) - 4);
    _eh_vector_destructor_iterator_(arr, 0x28, count, FUN_005b8000);
    operator_delete__(reinterpret_cast<uint8_t *>(arr) - 4);
  }
  *reinterpret_cast<void **>(self + 0x28) = nullptr;
  *reinterpret_cast<void **>(self + 0x04) = nullptr;
  *reinterpret_cast<void **>(self + 0x08) = nullptr;

  auto free3 = [&](unsigned off) {
    void *b = *reinterpret_cast<void **>(self + off);
    if (b) operator_delete(b);
    *reinterpret_cast<void **>(self + off) = nullptr;
    *reinterpret_cast<void **>(self + off + 4) = nullptr;
    *reinterpret_cast<void **>(self + off + 8) = nullptr;
  };
  free3(0xBC);
  free3(0xAC);
  free3(0x9C);
  free3(0x40);
  free3(0x30);
  free3(0x1C);

  FUN_00497360(self + 0x0C); // lea ecx,[esi+0x0C] — decompiler incomplete
}
