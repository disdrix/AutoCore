// =============================================================================
// FUN_00494170  (clean twin of Host_ClearElem0x28Array_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00494170
// Address:   0x00494170–0x004941af  (64 B / 0x40, autoassault.exe base 0x400000)
// System:    host / cookie-vector free (stride 0x28)
// Generated: 2026-07-29 W30-Q dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: Host_ClearElem0x28Array_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void _eh_vector_destructor_iterator_(
    void* arr, uint32_t stride, int count, void* dtor);
extern "C" void operator_delete[](void* p);
extern "C" void __thiscall FUN_005b8000(void* elem);

// Ghidra signature preserved
extern "C" void __fastcall FUN_00494170(int param_1)
{
  void* pvVar1 = *reinterpret_cast<void**>(param_1 + 0x28);
  if (pvVar1 != nullptr) {
    _eh_vector_destructor_iterator_(
        pvVar1, 0x28,
        *reinterpret_cast<int*>(reinterpret_cast<int>(pvVar1) - 4),
        reinterpret_cast<void*>(&FUN_005b8000));
    operator_delete[](reinterpret_cast<void*>(reinterpret_cast<int>(pvVar1) - 4));
  }
  *reinterpret_cast<uint32_t*>(param_1 + 0x28) = 0;
  *reinterpret_cast<uint32_t*>(param_1 + 4) = 0;
  *reinterpret_cast<uint32_t*>(param_1 + 8) = 0;
}
