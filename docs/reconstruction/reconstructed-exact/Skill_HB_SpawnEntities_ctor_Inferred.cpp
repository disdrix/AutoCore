// =============================================================================
// Skill_HB_SpawnEntities_ctor_Inferred  (FUN_00614dc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00614dc0
// Address:   0x00614dc0–0x00614e36  (autoassault.exe, image base 0x400000)
// Body size: 119 bytes (inclusive of ret 0x18)
// System:    skill / CVOGHB multi-entity spawn action
// Generated: 2026-07-23 scaffold as FUN_00614dc0; dual A/B seal 2026-07-29 (W25-N)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Construct a CVOGHBSkillBase subclass instance used as the per-spawn
//   "skill HB" action for multi-entity spawn execute:
//     1. CVOGHBSkillBase_ctor (base skill HB fields, validate, attach, period)
//     2. Install subclass vtbl PTR_FUN_009d0ec4
//     3. Cache skill vfunc(+0x27c) result as uint16 at this+0x6c4
//
// ABI (retail)
//   __thiscall this in ECX (object size 0x6d0 from sole caller)
//   stack: (skill*, a3, a4, target*, a6, a7)  → ret 0x18
//   return: this* in EAX
//
// VTABLE (PTR_FUN_009d0ec4) peer slots sealed elsewhere
//   +0x1c  Skill_HB_SpawnEntities_Precheck_Inferred  (0x006170b0)
//   +0x2c  Skill_HB_SpawnEntities_Execute_Inferred   (0x00615020)
//
// SOLE CALLER
//   Skill_HB_SpawnEntities_Execute_Inferred @ 0x00615b97
//     operator_new(0x6d0) → this ctor → Enqueue(map+0xe4ec) → Start
//
// READABILITY CF:
//   SEH; base ctor; *this=vtbl; ax=skill[+0x27c](); *(u16*)(this+0x6c4)=ax; ret this
//

#include <cstdint>

// Base ctor (sealed elsewhere as CVOGHBSkillBase_ctor)
extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self /*ECX*/,
    void* skill_or_source,
    void* a3,
    void* a4,
    void* target,
    void* a6,
    void* a7);

// Image data (vtbl)
extern "C" void* PTR_FUN_009d0ec4;

// Clean plate
void* Skill_HB_SpawnEntities_ctor_Inferred(
    void* self /*ECX*/,
    void* skill_or_source /*stack*/,
    void* a3,
    void* a4,
    void* target,
    void* a6,
    void* a7)
{
  CVOGHBSkillBase_ctor(self, skill_or_source, a3, a4, target, a6, a7);
  *reinterpret_cast<void**>(self) = &PTR_FUN_009d0ec4;

  // skill_or_source is object with vtbl; +0x27c virtual → uint16
  auto** vtbl = *reinterpret_cast<void***>(skill_or_source);
  using Vfunc027c = uint16_t(__thiscall*)(void*);
  auto fn = reinterpret_cast<Vfunc027c>(vtbl[0x27c / sizeof(void*)]);
  uint16_t cached = fn(skill_or_source);
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x6c4) = cached;

  return self;
}

// Legacy Ghidra name — see FUN_00614dc0.cpp
// undefined4* FUN_00614dc0(...); // matches thiscall + ret 0x18
