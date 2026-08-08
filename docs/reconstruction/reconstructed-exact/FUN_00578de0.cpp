// =============================================================================
// FUN_00578de0  (scaffold alias → CVOGHBSkillBase_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578de0
// Address:   0x00578de0–0x00578dfe exclusive  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refined 2026-08-05 R11-006 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Preferred name: CVOGHBSkillBase_ScalarDeletingDtor
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);
extern "C" void __cdecl operator_delete(void *p);

// Scaffold symbol kept for path stability. Prefer CVOGHBSkillBase_ScalarDeletingDtor.
void *__thiscall FUN_00578de0(void *param_1 /* ECX */, uint8_t param_2 /* flags */)
{
    FUN_00578a60(param_1);

    if ((param_2 & 1u) != 0) {
        operator_delete(param_1);
    }

    return param_1;
}
