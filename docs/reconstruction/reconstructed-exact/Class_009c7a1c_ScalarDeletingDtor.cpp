// =============================================================================
// Class_009c7a1c_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004975e0
// Address:   0x004975e0–0x004975fe  (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    class / MSVC scalar-deleting destructor
// Generated: 2026-07-29 W29-F dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004975e0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for vtbl family PTR_FUN_009c7a1c (vtbl[0]).
//   Always runs Class_009c7a1c_CompleteDtor (FUN_004970b0). If (flags & 1),
//   operator_delete the host heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS:
//   FUN_004970b0  — Class_009c7a1c_CompleteDtor (body; W28-M accept-with-gaps)
//   FUN_00496f70  — ctor twin (same vtbl; referenced from W28-M)
//   FUN_005b8000  — element dtor used inside complete body vector path (W29-F)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004970b0(void* self);  // Class_009c7a1c_CompleteDtor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004975e0(void* this, uint8_t flags)
extern "C" void* __thiscall Class_009c7a1c_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_004970b0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
