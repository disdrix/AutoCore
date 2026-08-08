// =============================================================================
// CVOGHBSkill_XP_CreateDefaultInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00548990
// Address:   0x00548990–0x005489e2  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R12-022 dual seal (from raw + live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================

// PURPOSE:
//   Allocate a default CVOGHBSkill_XP heartbeat shell:
//     operator_new(0x6c0) → CVOGHBSkillBase_DefaultCtor → install XP vtbl.
//   Distinct from ApplyToTargetList (0x0061c590) which uses the full skill base
//   ctor (0x005788d0), copies pulse, SetPeriod(-1000,true), Enqueue/Start.

// CALLEES:
//   operator_new @ 0x00489892
//   CVOGHBSkillBase_DefaultCtor (FUN_00578830) @ 0x00578830
// XREFS:
//   DATA only: CVOGHBSkill_XP vtbl+0x48 @ 0x009d11e4
// RTTI:
//   COL 0x00aade00 → type_info 0x00af29ec → .?AVCVOGHBSkill_XP@@

extern "C" void *operator_new(unsigned int size);
extern "C" void *FUN_00578830(void); // CVOGHBSkillBase_DefaultCtor (thiscall ECX)
extern "C" void *ExceptionList;
extern "C" unsigned char LAB_009a43fb;
extern "C" void *PTR_FUN_009d119c; // CVOGHBSkill_XP vtbl

// Named entry (inferred method English; class RTTI Confirmed)
void *CVOGHBSkill_XP_CreateDefaultInstance_Inferred(void)
{
  void *local_c;
  unsigned char *puStack_8;
  unsigned int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a43fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  void *puVar1 = operator_new(0x6c0);
  local_4 = 0;
  void *puVar2 = 0;
  if (puVar1 != 0) {
    // bytes: MOV ECX, ESI; CALL 0x00578830
    // Ghidra decompile drops ECX; thiscall this = newly allocated object.
#ifdef _MSC_VER
    __asm { mov ecx, puVar1 }
#endif
    FUN_00578830();
    *(void **)puVar1 = &PTR_FUN_009d119c;
    puVar2 = puVar1;
  }

  ExceptionList = local_c;
  return puVar2;
}

// Scaffold twin name retained for tooling that keys on FUN_*
void *FUN_00548990(void)
{
  return CVOGHBSkill_XP_CreateDefaultInstance_Inferred();
}
