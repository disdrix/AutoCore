// =============================================================================
// AssPreloader_PendingRemoveWithSideNotify_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971030
// Address:   0x00971030–0x0097104e  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971030
// System:    AssPreloader / client-fx preload pending ring
// Dual:      W36-D 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX=AssPreloader*; stack key*; RET 0x4.
// 1) SideHost_PushKeyFlag0(ECX=key*, stack=preloader)
// 2) GuardedVector_EraseFirstEqual_ThiscallRange(ESI=preloader+0x1C, key*)
// Name structural Inferred from W33-N + W35-A nested duals + sole caller 004ed310.
// =============================================================================

#include <cstdint>

// Nested sealed duals:
// 00970b20: ECX=keyHolder*; stack host*; RET 4; flag imm 0; push at host+0xAC
// 0043e630: ESI=container; stack key*; RET 4; AL=found
extern "C" void    FUN_00970b20(void* keyHolder /*ECX*/, void* host /*stack*/);
extern "C" uint8_t FUN_0043e630(const int* key /*stack*/, void* container /*ESI*/);

extern "C" void AssPreloader_PendingRemoveWithSideNotify_Inferred(
    void* preloader /*ECX*/,
    const int* key /*stack*/)
{
  // bytes: push esi/edi; edi=key; esi=ecx
  FUN_00970b20(const_cast<int*>(key), preloader);

  // ESI = preloader + 0x1C (pending ring); stack key*; RET 4 from callee
  void* pending = reinterpret_cast<uint8_t*>(preloader) + 0x1c;
  // MSVC: ESI established by caller of 0043e630 — model as explicit for clarity
  (void)FUN_0043e630(key, pending);
  // RET 0x4
}

extern "C" void FUN_00971030(void* preloader /*ECX*/, const int* key /*stack*/)
{
  AssPreloader_PendingRemoveWithSideNotify_Inferred(preloader, key);
}
