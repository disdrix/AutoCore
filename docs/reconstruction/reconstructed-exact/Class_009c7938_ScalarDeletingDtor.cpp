// =============================================================================
// Class_009c7938_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d590
// Address:   0x0040d590–0x0040d5ad exclusive (29 B / 0x1D, autoassault.exe base 0x400000)
// System:    class / MSVC scalar-deleting destructor
// Generated: 2026-07-29 W31-E dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0040d590
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for vtbl family PTR_FUN_009c7938 (vtbl[0]).
//   Always runs complete dtor FUN_0040d820. If (flags & 1), operator_delete the
//   host heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS:
//   FUN_0040d820  — complete dtor (installs PTR_FUN_009c7938, clears tree, member)
//   FUN_0040d540  — ctor twin (same vtbl)
//   FUN_0040d5b0  — StdTree_Clear_PtrVal_Vtbl0C (W30-P; called from complete)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0040d820(void* self);  // complete dtor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_0040d590(void* this, uint8_t flags)
extern "C" void* __thiscall Class_009c7938_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_0040d820(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
