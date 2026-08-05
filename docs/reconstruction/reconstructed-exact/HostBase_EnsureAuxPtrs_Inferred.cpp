// =============================================================================
// HostBase_EnsureAuxPtrs_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00756320
// Address:   0x00756320  (autoassault.exe, image base 0x400000)
// System:    client / host base (FUN_007560d0 family)
// Generated: 2026-07-29 W32-Q dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: One-shot ensure of host aux pointers:
//   +4 = optional object from FUN_00986070 when (flags & 1)
//   +8 = always new(0x14) + FUN_00442c80 (vtbl PTR_FUN_00a9f49c)
// Returns 0xFFFFFFFF if either slot already non-null; else 0.
//
// Prelude of PalantirEnv_InitPhases_Inferred and several phase enable methods.
// Base ctor FUN_007560d0 zeros +4/+8 first.

#include <cstdint>

extern "C" void *operator_new(uint32_t size);
extern "C" void *FUN_00986070(void);          // uses EBX = *DAT_00d1f624
extern "C" void *FUN_00442c80(void *self);    // small-object ctor; returns this
extern "C" void *DAT_00d1f624;                // EBX context for FUN_00986070

extern "C" uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(void *host, uint32_t flags)
{
  if (*reinterpret_cast<void **>(static_cast<char *>(host) + 4) != nullptr ||
      *reinterpret_cast<void **>(static_cast<char *>(host) + 8) != nullptr) {
    return 0xFFFFFFFFu;
  }

  if ((flags & 1u) != 0) {
    // Retail loads EBX from DAT_00d1f624 before call (implicit context).
    (void)DAT_00d1f624;
    *reinterpret_cast<void **>(static_cast<char *>(host) + 4) = FUN_00986070();
  }

  void *raw = operator_new(0x14);
  if (raw != nullptr) {
    *reinterpret_cast<void **>(static_cast<char *>(host) + 8) = FUN_00442c80(raw);
    return 0;
  }
  *reinterpret_cast<void **>(static_cast<char *>(host) + 8) = nullptr;
  return 0;
}
