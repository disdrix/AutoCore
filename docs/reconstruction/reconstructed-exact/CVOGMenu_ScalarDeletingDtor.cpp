// =============================================================================
// CVOGMenu_ScalarDeletingDtor  (aa_004166d0)
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar-deleting destructor for CVOGMenu (vtbl[0] of
//           PTR_FUN_00a72f6c): always run complete dtor, then optionally
//           operator_delete when (flags & 1).
//
// Address:  0x004166d0–0x004166ed inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Stable:   aa_004166d0
// Ghidra:   FUN_004166d0
// System:   skills-abilities (partition) / UI menu intermediate
// Wave:     MEGA-138 OWN-ONLY dual 2026-08-05
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Complete: CVOGMenu_CompleteDtor @ 0x0082d540 (dualed WQ9K-G)
// RTTI:     .?AVCVOGMenu@@  (type_info @ 0x00afe39c)
// Exactness: CF ≡ raw ≡ live decompile ≡ full-body read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (MEGA-138).
// =============================================================================

#include <cstdint>

// Dual-sealed complete dtor: install PTR_FUN_00a72f6c, menu hash teardown,
// chain CNDUIDialog_CompleteDtor. Does not free this.
extern "C" void __fastcall CVOGMenu_CompleteDtor(void* self); // 0x0082d540
// alias: FUN_0082d540

extern "C" void __cdecl operator_delete(void* p);

/* CVOGMenu_ScalarDeletingDtor — vtbl[0] scalar deleting dtor.

   Parameters:
     self:  CVOGMenu* in ECX
     flags: bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) CVOGMenu_CompleteDtor(self)
     2) if (flags & 1): operator_delete(self)
     3) return self

   Returns: this pointer (EAX) */

extern "C" void* __thiscall CVOGMenu_ScalarDeletingDtor(void* self /* ECX */, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  CVOGMenu_CompleteDtor(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Scaffold / Ghidra alias
extern "C" void* __thiscall FUN_004166d0(void* self, uint8_t flags)
{
  return CVOGMenu_ScalarDeletingDtor(self, flags);
}
