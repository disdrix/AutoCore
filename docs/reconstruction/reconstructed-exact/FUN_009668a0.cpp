// =============================================================================
// FUN_009668a0  (clean twin of PerfStatRings_CommitAndTrim_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009668a0
// Address:   0x009668a0  (autoassault.exe, image base 0x400000)
// System:    Palantir / frame perf stat rings
// Generated: 2026-07-29 W30-E dual
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Prefer named clean: PerfStatRings_CommitAndTrim_Inferred.cpp
// ABI: stdcall 1 stack arg; ret 4. PushBack via EAX container (0043c830).

#include <cstdint>

// See PerfStatRings_CommitAndTrim_Inferred.cpp for the full annotated port.
// This twin keeps the Ghidra symbol for inventory linkage.

void __stdcall FUN_009668a0(int param_1);

// Implementation is the named clean (same VA body). Link / include as needed.
// Body stages: tick +0x3D0; optional timer open (phase=3); push 4 rings + sum;
// trim short>500; trim long>3000; zero bins; snapshot 0x4C dwords; timer close.
