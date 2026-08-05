// =============================================================================
// FUN_00614dc0  (scaffold twin of Skill_HB_SpawnEntities_ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00614dc0
// Address:   0x00614dc0–0x00614e36  (autoassault.exe, image base 0x400000)
// Dual A/B:  2026-07-29 W25-N — prefer Skill_HB_SpawnEntities_ctor_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
extern "C" void* PTR_FUN_009d0ec4;

// Ghidra surface name preserved for xref continuity.
void* __thiscall FUN_00614dc0(
    void* param_1 /*this ECX*/,
    void* param_2,
    void* param_3,
    void* param_4,
    void* param_5,
    void* param_6,
    void* param_7)
{
  CVOGHBSkillBase_ctor(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
  *reinterpret_cast<void**>(param_1) = &PTR_FUN_009d0ec4;
  auto** vtbl = *reinterpret_cast<void***>(param_2);
  using Vfn = uint16_t(__thiscall*)(void*);
  uint16_t u = reinterpret_cast<Vfn>(vtbl[0x27c / 4])(param_2);
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x6c4) = u;
  return param_1;
}
