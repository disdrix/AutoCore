// =============================================================================
// FUN_00427040  (machine twin of StdVector_DestroyRuns_0x80_Thunk_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00427040
// Address:   0x00427040  (autoassault.exe, image base 0x400000)
// Ghidra:    thunk_FUN_004271c0
// Dual:      R10-003 2026-08-05
// Exactness: Behavior-preserving twin; prefer named clean for port notes.
// =============================================================================

// Parent worker (dualed as StdVector_DestroyRuns_0x80_Inferred).
extern "C" void FUN_004271c0(void /* EBX = vector* */);

// 5-byte JMP thunk → FUN_004271c0
extern "C" void FUN_00427040(void /* EBX = vector* */)
{
    // 00427040: E9 7B 01 00 00   JMP 0x004271c0
    FUN_004271c0();
}
