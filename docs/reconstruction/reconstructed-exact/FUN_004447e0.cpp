// =============================================================================
// FUN_004447e0 — twin of Palantir_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004447e0
// Address:   0x004447e0–0x004447FE exclusive (30 B)
// Wave:      W35-J 2026-07-29
// Prefer:    reconstructed-exact/Palantir_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

struct Palantir {
  void* vtbl;
};

extern "C" void __fastcall Palantir_CompleteDtor(Palantir* self);
extern "C" void __cdecl operator_delete(void* p);

extern "C" void* __thiscall FUN_004447e0(Palantir* self, unsigned char flags)
{
  Palantir_CompleteDtor(self);
  if ((flags & 1) != 0)
    operator_delete(self);
  return self;
}
