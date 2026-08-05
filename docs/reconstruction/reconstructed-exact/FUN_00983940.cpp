// =============================================================================
// FUN_00983940 — twin of AssResolverCore_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00983940
// Address:   0x00983940  (autoassault.exe, image base 0x400000)
// Wave:      W31-G 2026-07-29
// Canonical: AssResolverCore_Ctor_Inferred
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* FUN_00469db0(void* self);
extern "C" uint32_t DAT_00d1ef44;
extern "C" uint32_t DAT_00d1ef48;
extern "C" uint32_t DAT_00d1ef50;
extern "C" uint32_t DAT_00d1ef5c;
extern "C" uint16_t DAT_00d1ef58;

struct AssResolverCore {
  uint8_t member_head[0x2c];
  uint32_t tri_2c;
  uint32_t tri_30;
  uint32_t tri_34;
  CRITICAL_SECTION cs;
  uint8_t ready;
};

extern "C" AssResolverCore* FUN_00983940(AssResolverCore* self /*stack; RET 4*/)
{
  FUN_00469db0(self);
  self->tri_2c = 0;
  self->tri_30 = 0;
  self->tri_34 = 0;
  InitializeCriticalSection(&self->cs);
  self->ready = 1;
  DAT_00d1ef44 = 0;
  DAT_00d1ef48 = 0;
  DAT_00d1ef50 = 0;
  DAT_00d1ef5c = 0;
  DAT_00d1ef58 = 0; // retail WORD store
  return self;
}
