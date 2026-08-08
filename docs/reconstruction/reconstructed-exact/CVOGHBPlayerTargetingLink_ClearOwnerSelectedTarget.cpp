// =============================================================================
// CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b850
// Address:   0x0051b850  (autoassault.exe, image base 0x400000)
// Body:      0x0051b850 – 0x0051b861  (bare ret; int3 pad @ 0x0051b862+)
// System:    heartbeat / targeting link / object combat-target
// Generated: 2026-08-05 gap-fill from live Ghidra + dual A/B (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Derived vtbl slot 7 override for CVOGHBPlayerTargetingLink
//   (PTR_FUN_009cdfd4 + 0x1C).
//   If this->pOwnerObject (+0x18) is non-null, clear the owner's selected-
//   target pointer at owner+0xA0 (same field as Object_SetSelectedTarget).
//
//   Base family slot 7 is FUN_0056f570 (empty ret / nop). Only the player
//   targeting self-side HB clears the selector's selected target when this
//   virtual runs.
//
// ABI: __thiscall, ECX=this (HB object), no stack args, bare ret.
// Name: INFERRED (field role + class family; no product virtual string).
//
// ASM SEALS (read_memory 2026-08-05):
//   8B 41 18              mov eax, [ecx+0x18]
//   85 C0                 test eax, eax
//   74 0A                 jz ret
//   C7 80 A0 00 00 00 00 00 00 00
//                         mov dword ptr [eax+0xA0], 0
//   C3                    ret
//
// XREFS: DATA only from 0x009cdff0 (vtbl slot 7). No code callers / callees.
// Reviews: A/B_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md
// =============================================================================

#include <cstdint>

// Retail: FUN_0051b850
// this = CVOGHBPlayerTargetingLink / CVOGHBBase-derived HB (size 0x28 at new).
extern "C" void __thiscall CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget(void *self)
{
  void *owner = *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x18);
  if (owner != nullptr) {
    *reinterpret_cast<void **>(reinterpret_cast<char *>(owner) + 0xA0) = nullptr;
  }
}
