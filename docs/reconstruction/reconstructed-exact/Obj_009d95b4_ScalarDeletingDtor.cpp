// =============================================================================
// Obj_009d95b4_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005b44d0
// Address:   0x005b44d0–0x005b44ee  (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    host object / MSVC scalar-deleting destructor
// Generated: 2026-07-29 W30-N dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_005b44d0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for vtbl family PTR_FUN_009d95b4 (vtbl[0]).
//   Always runs Obj_BodyDtor_SetVtbl_DestroyStdListAt10 (FUN_005b3b20). If
//   (flags & 1), operator_delete the host heap block. Returns this in EAX.
//   Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS:
//   FUN_005b3b20  — Obj_BodyDtor_SetVtbl_DestroyStdListAt10 (body; W28-N accept-with-gaps)
//   FUN_005b3f60 / FUN_005b4260 — ctors installing same vtbl + list at +0x10
// =============================================================================

#include <cstdint>

extern "C" void __fastcall Obj_BodyDtor_SetVtbl_DestroyStdListAt10(void* self);
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_005b44d0(void* this, uint8_t flags)
extern "C" void* __thiscall Obj_009d95b4_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  Obj_BodyDtor_SetVtbl_DestroyStdListAt10(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Scaffold alias
extern "C" void* __thiscall FUN_005b44d0(void* self, uint8_t flags)
{
  return Obj_009d95b4_ScalarDeletingDtor(self, flags);
}
