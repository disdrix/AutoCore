// =============================================================================
// CNDUIDialog_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004280d0
// Address:   0x004280d0–0x004280ee exclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    CNDUIDialog / MSVC scalar-deleting destructor (skills-abilities partition)
// Generated: 2026-08-05 MEGA-140 dual A/B (decompile + read_memory + RTTI + xrefs)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004280d0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CNDUIDialog (vtbl[0] of PTR_FUN_00a98f44).
//   RTTI COL 0x00ab7e6c → .?AVCNDUIDialog@@. Always runs complete dtor
//   FUN_00792c20 (CNDUIDialog_CompleteDtor). If (flags & 1), operator_delete
//   the host. Returns this; ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags; ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / RELATED:
//   FUN_00792c20  — complete dtor (installs PTR_FUN_00a98f44 + teardown) [WQ9K-G]
//   FUN_00792d20  — ctor peer (same vtbl install)
//   Parent dual WQ9K-G already sealed complete-vs-scalar split
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00792c20(void* self);  // CNDUIDialog_CompleteDtor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004280d0(void* this, uint8_t flags)
extern "C" void* __thiscall CNDUIDialog_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_00792c20(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
