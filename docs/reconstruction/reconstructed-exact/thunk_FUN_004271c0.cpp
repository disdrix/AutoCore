// =============================================================================
// thunk_FUN_004271c0  (RETIRED scaffold name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00427040
// Address:   0x00427040  (autoassault.exe, image base 0x400000)
// Dual:      R10-003 2026-08-05
// Status:    Scaffold name retired → StdVector_DestroyRuns_0x80_Thunk_Inferred
// Exactness: Behavior-preserving. Prefer named clean.
// =============================================================================
//
// Prior scaffold printed the Ghidra-followed parent body at this VA.
// Bytes authority: this VA is ONLY JMP 0x004271c0 (E9 7B 01 00 00).
// =============================================================================

extern "C" void StdVector_DestroyRuns_0x80_Inferred(void /* EBX = vector* */);

// Alias kept for path stability; body is pure JMP to parent tidy.
extern "C" void thunk_FUN_004271c0(void /* EBX = vector* */)
{
    StdVector_DestroyRuns_0x80_Inferred();
}
