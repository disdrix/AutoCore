// =============================================================================
// FUN_00548f90  (machine twin of CVOGHBSkillBase_dtor_Thunk_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00548f90
// Address:   0x00548f90  (autoassault.exe, image base 0x400000)
// Ghidra:    thunk_FUN_00578a60
// Dual:      R13-006 2026-08-05
// Exactness: Behavior-preserving twin; prefer named clean for port notes.
// =============================================================================

// Parent worker (dualed as CVOGHBSkillBase_dtor).
extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);

// 5-byte JMP thunk → FUN_00578a60
extern "C" void __fastcall FUN_00548f90(void *thisHb /* ECX */)
{
    // 00548f90: E9 CB FA 02 00   JMP 0x00578a60
    FUN_00578a60(thisHb);
}
