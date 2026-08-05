// =============================================================================
// FUN_004941b0  (clean twin of Host_RebuildElem0x28ArrayFromMap_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004941b0
// Address:   0x004941b0–0x00494304  (341 B / 0x155, autoassault.exe base 0x400000)
// System:    host / cookie-vector rebuild from map dims (stride 0x28)
// Generated: 2026-07-29 W30-Q dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: Host_RebuildElem0x28ArrayFromMap_Inferred.cpp
// Reject: Named_VOG_DEBUG_STOP_004941b0 (scaffold assert-string alias)
// =============================================================================

#include <cstdint>
#include <cmath>

extern "C" void _eh_vector_destructor_iterator_(
    void* arr, uint32_t stride, int count, void* dtor);
extern "C" void _eh_vector_constructor_iterator_(
    void* arr, uint32_t stride, int count, void* ctor, void* dtor);
extern "C" void operator_delete[](void* p);
extern "C" void* operator_new[](uint32_t size);
extern "C" void FUN_007a4480(int a, const char* msg);
extern "C" void __thiscall FUN_005b8000(void* elem);
extern "C" void __fastcall FUN_005b7db0(void* elem);
extern "C" float DAT_00a11088;
extern "C" float DAT_00aaa8a4;
extern "C" float DAT_00aefa50;

// Ghidra signature preserved
extern "C" void __thiscall FUN_004941b0(int param_1, int param_2)
{
  void* pvVar1 = *reinterpret_cast<void**>(param_1 + 0x28);
  int* piVar5 = nullptr;

  if (pvVar1 != nullptr) {
    _eh_vector_destructor_iterator_(
        pvVar1, 0x28,
        *reinterpret_cast<int*>(reinterpret_cast<int>(pvVar1) - 4),
        reinterpret_cast<void*>(&FUN_005b8000));
    operator_delete[](reinterpret_cast<void*>(reinterpret_cast<int>(pvVar1) - 4));
  }
  *reinterpret_cast<uint32_t*>(param_1 + 0x28) = 0;

  if (*reinterpret_cast<int*>(param_2 + 0xe4f8) == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    return;
  }

  DAT_00aefa50 = DAT_00a11088;
  if (*reinterpret_cast<char*>(param_2 + 0xf5) == '\0') {
    DAT_00aefa50 = DAT_00aaa8a4;
  }

  int mapBase = *reinterpret_cast<int*>(param_2 + 0xe4f8);
  int iVar4 = static_cast<int>(
                  std::round((static_cast<float>(*reinterpret_cast<int*>(mapBase + 0x10)) /
                              DAT_00aefa50) *
                             *reinterpret_cast<float*>(mapBase + 0x18))) +
              1;
  *reinterpret_cast<int*>(param_1 + 4) = iVar4;

  int iVar2 = static_cast<int>(
                  std::round((static_cast<float>(*reinterpret_cast<int*>(mapBase + 0x14)) /
                              DAT_00aefa50) *
                             *reinterpret_cast<float*>(mapBase + 0x18))) +
              1;
  *reinterpret_cast<int*>(param_1 + 8) = iVar2;

  iVar2 = iVar2 * iVar4;
  int* piVar3 = static_cast<int*>(
      operator_new[](static_cast<uint32_t>(iVar2 * 0x28 + 4)));
  if (piVar3 != nullptr) {
    piVar5 = piVar3 + 1;
    *piVar3 = iVar2;
    _eh_vector_constructor_iterator_(
        piVar5, 0x28, iVar2,
        reinterpret_cast<void*>(&FUN_005b7db0),
        reinterpret_cast<void*>(&FUN_005b8000));
  }
  *reinterpret_cast<int**>(param_1 + 0x28) = piVar5;
}
