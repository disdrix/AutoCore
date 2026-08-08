// =============================================================================
// StdVector_DestroyRuns_0x80_Thunk_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00427040
// Address:   0x00427040–0x00427044  (autoassault.exe, image base 0x400000)
// Ghidra:    thunk_FUN_004271c0
// System:    skills-abilities / UI text-layout SEH alias
// Dual:      R10-003 2026-08-05
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Pure JMP thunk (5 B: E9 7B 01 00 00) to dualed parent
//   StdVector_DestroyRuns_0x80_Inferred @ 0x004271c0 (aa_004271c0 / MEGA-128).
//
// Retail body at this VA is ONLY the JMP — Ghidra decompiler follows the
// thunk and prints the parent tidy CF (EBX-this, stride 0x80, ~wstring@+0x0C,
// operator_delete, zero triple). Do not invent local instructions here.
//
// Callers (SEH Unwind JMP only):
//   Unwind@009ac2fc @ 009ac305: MOV EBX,[EBP+4]; ADD EBX,0x80; JMP here
//   Unwind@009add3e @ 009add47: same EBX setup
// Direct CALL sites go to parent (UiTextLayout_CompleteDtor LEA EBX,[+0x80]).
//
// ABI (inherited): EBX = vector shell*; no stack formals; void; bare RET in parent.
// REJECT: treating expanded decompile as local body; thiscall-ECX=vector;
// inventing product element demangle beyond parent _Inferred.
// =============================================================================

#include <cstdint>

// Parent (dualed MEGA-128) — real tidy implementation.
// begin@+4 end@+8 cap@+0xC; elem stride 0x80; FUN_00426f70 per elem.
extern "C" void StdVector_DestroyRuns_0x80_Inferred(/* EBX = Vec80Shell* */);

// Clean name for the 5-byte JMP alias at 0x00427040.
// Retail: JMP rel32 → 0x004271c0 (does not fall through).
extern "C" void StdVector_DestroyRuns_0x80_Thunk_Inferred(/* EBX = Vec80Shell* */)
{
    // Bytes: E9 7B 01 00 00
    // Equivalent control transfer:
    StdVector_DestroyRuns_0x80_Inferred();
}
