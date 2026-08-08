// =============================================================================
// FUN_004166d0 — twin / Ghidra alias of CVOGMenu_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004166d0
// Address:   0x004166d0–0x004166ed inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Wave:      MEGA-138 OWN-ONLY dual 2026-08-05
// Canonical: CVOGMenu_ScalarDeletingDtor (see named plate)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_0082d540(void* self); // CVOGMenu_CompleteDtor
extern "C" void __cdecl operator_delete(void* p);

// ECX = this; stack flags; RET 4; returns this*.
// MSVC scalar-deleting destructor (vtbl[0] of PTR_FUN_00a72f6c / CVOGMenu).
extern "C" void* __thiscall FUN_004166d0(void* self, uint8_t flags)
{
  FUN_0082d540(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
