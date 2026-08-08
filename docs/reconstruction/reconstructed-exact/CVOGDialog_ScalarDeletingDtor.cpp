// =============================================================================
// CVOGDialog_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004130d0
// Address:   0x004130d0–0x004130ee exclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    missions-progression / CVOGDialog / MSVC scalar-deleting destructor
// Wave:      R12-010 OWN-ONLY dual 2026-08-05
// Generated: 2026-08-05 R12-010 dual A/B (decompile + read_memory + vtbl/RTTI)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004130d0
// Terminal:  false
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CVOGDialog (vtbl[0] of PTR_FUN_00a58c6c).
//   RTTI COL 0x00ab4984 → .?AVCVOGDialog@@ (sealed by parent dual R11-030).
//   Always runs complete dtor FUN_0087b7d0 (installs same vtbl, chains
//   CNDUIDialog_CompleteDtor 0x00792c20). If (flags & 1), operator_delete the
//   host. Returns this; ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags; ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / RELATED:
//   FUN_0087b7d0  — complete dtor (not dualed here)
//   FUN_0087b890  — CVOGDialog_Ctor (parent dual R11-030; installs same vtbl)
//   FUN_00792c20  — CNDUIDialog_CompleteDtor (dualed; chained from complete)
// =============================================================================

#include <cstdint>

// CVOGDialog complete dtor — installs PTR_FUN_00a58c6c then CNDUIDialog_CompleteDtor.
extern "C" void __thiscall FUN_0087b7d0(void* self);
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004130d0(void* this, uint8_t flags)
extern "C" void* __thiscall CVOGDialog_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_0087b7d0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Ghidra symbol alias
extern "C" void* __thiscall FUN_004130d0(void* self, uint8_t flags)
{
  return CVOGDialog_ScalarDeletingDtor(self, flags);
}
