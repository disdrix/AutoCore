// =============================================================================
// FUN_00548990
// -----------------------------------------------------------------------------
// Stable ID: aa_00548990
// Address:   0x00548990  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refined 2026-08-05 R12-022 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Canonical named twin: CVOGHBSkill_XP_CreateDefaultInstance_Inferred.cpp
// =============================================================================

// PURPOSE:
//   CVOGHBSkill_XP default-instance factory:
//   operator_new(0x6c0) + CVOGHBSkillBase_DefaultCtor + vtbl PTR_FUN_009d119c.
//   DATA-only inbound at vtbl+0x48 (0x009d11e4). Class RTTI Confirmed.

// READABILITY:
//  - Body size: ~22 non-empty decompiler lines / 83 image bytes.
//  - Control keywords: if×1, return×1.
//  - Callees: operator_new, FUN_00578830 (CVOGHBSkillBase_DefaultCtor).
//  - Return sites: 1 (object* or null).

extern "C" void *operator_new(unsigned int size);
extern "C" void *FUN_00578830(void);
extern "C" void *ExceptionList;
extern "C" unsigned char LAB_009a43fb;
extern "C" void *PTR_FUN_009d119c;

uint32_t *FUN_00548990(void)
{
  uint32_t *puVar1;
  uint32_t *puVar2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a43fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (uint32_t *)operator_new(0x6c0);
  local_4 = 0;
  puVar2 = (uint32_t *)0x0;
  if (puVar1 != (uint32_t *)0x0) {
    // thiscall: ECX = puVar1 (bytes MOV ECX,ESI)
    FUN_00578830();
    *puVar1 = (uint32_t)&PTR_FUN_009d119c;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}
