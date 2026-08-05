// =============================================================================
// FUN_00756320  (canonical twin of HostBase_EnsureAuxPtrs_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00756320
// Address:   0x00756320  (autoassault.exe, image base 0x400000)
// System:    client / host base (FUN_007560d0 family)
// Generated: 2026-07-29 W32-Q dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See HostBase_EnsureAuxPtrs_Inferred.cpp for named clean source.

#include <cstdint>

extern "C" void *operator_new(uint32_t size);
extern "C" void *FUN_00986070(void);
extern "C" void *FUN_00442c80(void *self);
extern "C" void *DAT_00d1f624;

extern "C" uint32_t __thiscall FUN_00756320(void *param_1, uint32_t param_2)
{
  if (*reinterpret_cast<void **>(static_cast<char *>(param_1) + 4) != nullptr ||
      *reinterpret_cast<void **>(static_cast<char *>(param_1) + 8) != nullptr) {
    return 0xFFFFFFFFu;
  }

  if ((param_2 & 1u) != 0) {
    (void)DAT_00d1f624;
    *reinterpret_cast<void **>(static_cast<char *>(param_1) + 4) = FUN_00986070();
  }

  void *raw = operator_new(0x14);
  if (raw != nullptr) {
    *reinterpret_cast<void **>(static_cast<char *>(param_1) + 8) = FUN_00442c80(raw);
    return 0;
  }
  *reinterpret_cast<void **>(static_cast<char *>(param_1) + 8) = nullptr;
  return 0;
}
