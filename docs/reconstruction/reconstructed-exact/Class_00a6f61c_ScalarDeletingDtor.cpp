// =============================================================================
// Class_00a6f61c_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004160b0
// Address:   0x004160b0–0x004160cd inclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    class / MSVC scalar-deleting destructor
// Generated: 2026-07-23 scaffold as FUN_004160b0; **sealed 2026-08-04** WQ9I-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      accept-with-gaps (A+B) — scalar CF/ABI/vtbl[0] High; product class open
// Ghidra:    FUN_004160b0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for vtbl family PTR_FUN_00a6f61c (vtbl[0]).
//   Always runs complete dtor FUN_0097a8a0. If (flags & 1), operator_delete the
//   host heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / related (not OWN):
//   FUN_0097a8a0  — complete dtor (installs PTR_FUN_00a6f61c, chains FUN_00792c20)
//   FUN_0097a8e0  — ctor twin (same vtbl; UI string i_w_tut_2d_wnd_highlight.dds)
//   FUN_004160d0  — neighbor scalar (WQ9I-F; different complete dtor)
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_0097a8a0(void* self);  // complete dtor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004160b0(void* this, uint8_t flags)
extern "C" void* __thiscall Class_00a6f61c_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_0097a8a0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);  // returns; decompiler "does not return" is false
  }

  return self;
}
