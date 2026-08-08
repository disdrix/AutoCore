// =============================================================================
// MatchTargetEval_DefaultReturnFalse_Inferred  (FUN_004cc820)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cc820
// Address:   0x004cc820  (autoassault.exe, image base 0x400000)
// Body:      0x004cc820–0x004cc824 inclusive (5 B): 32 C0 C2 08 00
// System:    missions-progression / MatchTarget evaluator default
// Generated: 2026-08-05 MEGA-030 OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of sealed body. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime Confirmed).
// =============================================================================
//
// PURPOSE
//   Shared default virtual for MatchTarget-style evaluator slots (commonly
//   vtbl+0x40 / pair +0x44). Always returns false (AL=0). Ignores this and
//   both stack formals. ABI matches dualed CVOGObjective_MatchTargetEvaluators
//   (0x0059d9c0) which pushes two args and CALL [vtbl+0x40], testing AL.
//
//   Collect/Kill/Deliver sample types install this stub at +0x40 (always no
//   match via ForInteract path). UseItem real MatchTarget is a different
//   method at +0x38 — do not merge.
//
// ABI (machine-sealed; decompiler under-types as void/no-args):
//   __thiscall  ECX = evaluator this (unused)
//   stack       argA, argB (unused; 8 bytes cleaned)
//   return      AL = 0
//   epilogue    RET 0x8
//
// XREFS
//   80 DATA vtbl installs; 6 MSVC MI adjustor JMP thunks rebasing ECX then
//   tail-jumping here. No direct CALL sites into the 5-byte body.
// =============================================================================

#include <cstdint>

// Formals named for the dualed walker contract; body does not read them.
std::uint8_t __thiscall MatchTargetEval_DefaultReturnFalse_Inferred(
    void* /*this*/,
    void* /*argA*/,
    void* /*argB*/)
{
    // 004cc820  XOR AL, AL
    // 004cc822  RET 0x8
    return 0;
}
