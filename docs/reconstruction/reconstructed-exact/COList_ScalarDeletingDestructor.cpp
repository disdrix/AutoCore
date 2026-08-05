// =============================================================================
// COList_ScalarDeletingDestructor
// -----------------------------------------------------------------------------
// Stable ID: aa_004bd1b0
// Address:   0x004bd1b0–0x004bd1cd  (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    client / COList
// Generated: 2026-07-29 W27-L dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004bd1b0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for COList (vtbl[0] of PTR_FUN_009cb448).
//   Always runs COList_Destructor (FUN_004bbc70). If (flags & 1), operator_delete
//   the host heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS:
//   FUN_004bbc70  — COList_Destructor (body)
//   FUN_004bbfb0  — COList_Constructor (same vtbl; DAT_00b04830)
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_004bbc70(void* self);  // COList_Destructor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004bd1b0(void* this, uint8_t flags)
extern "C" void* __thiscall COList_ScalarDeletingDestructor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_004bbc70(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Ghidra twin symbol
extern "C" void* __thiscall FUN_004bd1b0(void* param_1, uint8_t param_2)
{
  return COList_ScalarDeletingDestructor(param_1, param_2);
}
