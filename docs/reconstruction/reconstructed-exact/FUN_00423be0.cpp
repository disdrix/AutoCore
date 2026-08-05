// =============================================================================
// FUN_00423be0 — twin of AssManager_ResolverA_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00423be0
// Address:   0x00423be0  (autoassault.exe, image base 0x400000)
// Wave:      W31-G 2026-07-29
// Canonical: AssManager_ResolverA_Ctor_Inferred
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* FUN_00423cf0(void* member);

struct AssResolverA {
  void* vtbl;
  uint32_t pad04;
  uint8_t member_at_08[0x28];
  CRITICAL_SECTION cs;
  uint8_t ready;
};

extern "C" AssResolverA* FUN_00423be0(AssResolverA* self /*stack; RET 4*/)
{
  self->pad04 = 0;
  self->vtbl = reinterpret_cast<void*>(0x00a95acc);
  FUN_00423cf0(&self->member_at_08);
  InitializeCriticalSection(&self->cs);
  self->ready = 1;
  return self;
}
