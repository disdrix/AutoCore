// =============================================================================
// FUN_00457c60  (clean twin of StdList_AllocSentinel_0x18_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00457c60
// Address:   0x00457c60  (autoassault.exe, image base 0x400000)
// System:    shared std::list-style sentinel factory
// Generated: 2026-07-29 W30-E dual
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern void* operator_new(uint32_t size);

// Retail: EAX out = node*; bare RET. Decompiler void is wrong.
void* FUN_00457c60(void)
{
  void* pvVar1 = operator_new(0x18);

  if (pvVar1 != nullptr) {
    *static_cast<void**>(pvVar1) = pvVar1;
  }

  uint32_t* prev = reinterpret_cast<uint32_t*>(
      static_cast<uint8_t*>(pvVar1) + 4);
  if (prev != nullptr) {
    *prev = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pvVar1));
  }

  return pvVar1;
}
