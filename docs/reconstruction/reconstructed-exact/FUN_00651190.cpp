// =============================================================================
// FUN_00651190  (scaffold twin of CVOGHBSkill_SharedScalarDeletingDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00651190
// Address:   0x00651190  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R12-001 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// Canonical clean: CVOGHBSkill_SharedScalarDeletingDtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);
extern "C" void __cdecl operator_delete(void *p);

// Ghidra name retained for inventory linkage. Prefer the named clean unit.
void *__thiscall FUN_00651190(void *param_1 /* ECX this */, uint8_t param_2 /* flags */)
{
    // Retail: CALL 0x00548f90 (JMP thunk → FUN_00578a60)
    FUN_00578a60(param_1);

    if ((param_2 & 1u) != 0) {
        operator_delete(param_1);
    }

    return param_1;
}
