// =============================================================================
// CVOGHBSkill_PossessCreature_DefaultFactory_Inferred  (FUN_0054cbb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cbb0
// Address:   0x0054cbb0–0x0054cc02  (autoassault.exe, image base 0x400000)
// Body:      83 B / 0x53; terminal bare RET (C3); pad CC to 0x0054cc10
// System:    skills-abilities
// Generated: 2026-08-05 R12-023 dual seal (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// Class:     CVOGHBSkill_PossessCreature
//            RTTI Confirmed via parent dual aa_00626240 (COL/TD strings)
// Vtbl:      PTR_FUN_009d1ba4  (installed here after base default ctor)
// Size:      0x6f0
// Base:      CVOGHBSkillBase_DefaultCtor (0x00578830, dualed W23-S)
//
// PURPOSE:
//   Type default factory for PossessCreature skill HB:
//     1) operator_new(0x6f0)
//     2) CVOGHBSkillBase_DefaultCtor(this)   // base vtbl 0x009d3fdc temporarily
//     3) *this = subclass vtbl 0x009d1ba4
//     4) return this (or null if new failed)
//
//   Does NOT run CVOGHBSkill_PossessCreature_ctor (0x00626240):
//     no skill-blob args, no creature dyn_cast, no +0x6c0/6c4/6c8/6c9 clears.
//
// ABI: cdecl; 0 stack args; bare RET; EAX = object* or null
// Reachability: DATA dword @ 0x009d1bec → this entry (0 code CALL xrefs)
// =============================================================================

#include <stdint.h>

// External (sealed elsewhere / CRT):
// void *operator_new(uint32_t size);
// void *__fastcall CVOGHBSkillBase_DefaultCtor(void *self);  // FUN_00578830

extern void *PTR_FUN_009d1ba4; // CVOGHBSkill_PossessCreature vtbl

void *CVOGHBSkill_PossessCreature_DefaultFactory_Inferred(void)
{
  void *p;

  /* SEH frame: LAB_009a43fb; state -1 → 0 after operator_new — omitted in spirit */

  p = operator_new(0x6f0);
  if (p == 0) {
    return 0;
  }

  CVOGHBSkillBase_DefaultCtor(p);
  *(uint32_t *)p = (uint32_t)(uintptr_t)&PTR_FUN_009d1ba4;
  return p;
}
