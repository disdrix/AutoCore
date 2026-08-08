// =============================================================================
// CVOGHBSkillBase_dtor_Thunk_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00548f90
// Address:   0x00548f90–0x00548f94  (autoassault.exe, image base 0x400000)
// Ghidra:    thunk_FUN_00578a60
// System:    skills-abilities / CVOGHBSkillBase lifecycle
// Dual:      R13-006 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Pure JMP thunk (5 B: E9 CB FA 02 00) to dualed parent
//   CVOGHBSkillBase_dtor @ 0x00578a60 (aa_00578a60 / R12-026 accept-with-gaps).
//
// Retail body at this VA is ONLY the JMP — Ghidra decompiler follows the
// thunk and prints the parent complete-dtor CF (vtbl restore PTR_FUN_009d3fdc,
// delete[] +0x6a0, delete buffer +0x6b0 triad, tail JMP CVOGHBBase_dtor).
// Do not invent local instructions here.
//
// Callers:
//   FUN_00651190 CVOGHBSkill_SharedScalarDeletingDtor_Inferred @ 00651193 CALL
//   Unwind@009a89d0 @ 009a89d3 CALL
//   Unwind@009a8a00 @ 009a8a03 CALL
//   Unwind@009a8a30 @ 009a8a33 CALL
// Base-class scalar dtor 0x00578de0 CALLs parent 0x00578a60 directly (not this VA).
//
// ABI (inherited): __thiscall ECX=this; no stack formals; parent tails base dtor.
// REJECT: treating expanded decompile as local body; free-this; OnEnd element walk;
// inventing product demangle of the thunk beyond parent family + _Inferred.
// Terminal: false (no Runtime Confirmed).
// =============================================================================

#include <cstdint>

// Parent (dualed R12-026) — real complete destructor body.
// __thiscall ECX=this; restores PTR_FUN_009d3fdc; frees +0x6a0/+0x6b0; JMP base.
extern "C" void __fastcall CVOGHBSkillBase_dtor(void *thisHb /* ECX */);

// Clean name for the 5-byte JMP alias at 0x00548f90.
// Retail: JMP rel32 → 0x00578a60 (does not fall through).
extern "C" void __fastcall CVOGHBSkillBase_dtor_Thunk_Inferred(void *thisHb /* ECX */)
{
    // Bytes: E9 CB FA 02 00
    // Equivalent control transfer (registers preserved by JMP):
    CVOGHBSkillBase_dtor(thisHb);
}
