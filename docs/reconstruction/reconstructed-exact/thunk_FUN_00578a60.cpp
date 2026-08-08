// =============================================================================
// thunk_FUN_00578a60  (retired scaffold name; keep path for inventory links)
// -----------------------------------------------------------------------------
// Stable ID: aa_00548f90
// Address:   0x00548f90  (autoassault.exe, image base 0x400000)
// Dual:      R13-006 2026-08-05
// Prefer:    CVOGHBSkillBase_dtor_Thunk_Inferred.cpp / FUN_00548f90.cpp
// =============================================================================
// Scaffold 2026-07-23 printed Ghidra's expanded parent decompile as if it were
// local body. R13-006 seals: this VA is pure JMP E9 CB FA 02 00 → 0x00578a60.
// =============================================================================

extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);

// Ghidra symbol retained as alias of the 5-byte JMP.
extern "C" void __fastcall thunk_FUN_00578a60(void *thisHb /* ECX */)
{
    // 00548f90: E9 CB FA 02 00   JMP 0x00578a60
    FUN_00578a60(thisHb);
}
