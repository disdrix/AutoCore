// =============================================================================
// FUN_0051de60  (scaffold twin of SkillCNDHash_ScalarDeletingDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051de60
// Address:   0x0051de60–0x0051de7d inclusive (30 B)
// Wave:      2026-08-04 WQ9F-H OWN dual A/B
// Named:     reconstructed-exact/SkillCNDHash_ScalarDeletingDtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0051de80(void* self);
extern "C" void __cdecl operator_delete(void* p);

extern "C" void* __thiscall FUN_0051de60(void* self, uint8_t flags)
{
  FUN_0051de80(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
