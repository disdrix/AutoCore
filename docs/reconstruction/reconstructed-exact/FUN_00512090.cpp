// =============================================================================
// FUN_00512090  (alias → CVOGHBPlayerTargetingLink_ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00512090
// Address:   0x00512090  (autoassault.exe, image base 0x400000)
// System:    object / combat-target / HB
// Generated: 2026-07-23 scaffold; refined 2026-07-29 OWN-ONLY dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical named unit: CVOGHBPlayerTargetingLink_ctor.cpp
// Reviews: A/B_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall FUN_00604d40(void *self, void *attachOwner);

// Image constant: subclass vtbl PTR_FUN_009cdfd4
static void *const PTR_FUN_009cdfd4 = reinterpret_cast<void *>(0x009cdfd4);

// __thiscall: ECX=this (0x28 HB object), stack attachOwner, ret 4, returns this.
extern "C" void *__thiscall FUN_00512090(void *param_1, void *param_2)
{
  FUN_00604d40(param_1, param_2);
  *reinterpret_cast<void **>(param_1) = PTR_FUN_009cdfd4;
  return param_1;
}
