// =============================================================================
// FUN_0051b850  (alias → CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b850
// Address:   0x0051b850  (autoassault.exe, image base 0x400000)
// System:    heartbeat / targeting link / object combat-target
// Generated: 2026-08-05 gap-fill (live Ghidra + dual A/B 2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical named unit: CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.cpp
// Reviews: A/B_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md
// =============================================================================

#include <cstdint>

// __thiscall: ECX=this (HB), no stack args, bare ret.
// if (*(this+0x18) != 0) *(owner+0xA0) = 0;
extern "C" void __thiscall FUN_0051b850(void *param_1)
{
  void *owner = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x18);
  if (owner != nullptr) {
    *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(owner) + 0xA0) = 0;
  }
}
