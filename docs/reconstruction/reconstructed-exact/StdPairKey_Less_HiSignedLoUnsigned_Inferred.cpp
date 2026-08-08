// =============================================================================
// StdPairKey_Less_HiSignedLoUnsigned_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401480
// Address:   0x00401480  (autoassault.exe, image base 0x400000)
// Body:      0x00401480 – 0x004014a5 exclusive (37 B / 0x25); pad CC
// System:    std 2-dword pair-key less-than (insert-hint / ordered map)
// Generated: 2026-08-04 WQ9G-B dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Strict less-than on a 2-dword key used by insert-hint shells
// (StdTree_InsertHint_Isnil29_Inferred @ 0x004cc220 and peer FUN_00406560).
// Order matches pair-key insert-or-find (hi signed primary, lo unsigned secondary).
//
// Algebra: (a.hi < b.hi) || (a.hi == b.hi && a.lo < b.lo)
//   hi @ +4: SIGNED (JG/JL)
//   lo @ +0: UNSIGNED (JAE)
//
// ABI: two stack pointers; RET 8; returns 0|1 in EAX. Leaf.

#include <cstdint>

extern "C" uint32_t __stdcall StdPairKey_Less_HiSignedLoUnsigned_Inferred(
    const uint32_t* a,
    const uint32_t* b)
{
    const int32_t aHi = static_cast<int32_t>(a[1]);
    const int32_t bHi = static_cast<int32_t>(b[1]);

    if (aHi > bHi) {
        return 0;
    }
    if (aHi < bHi) {
        return 1;
    }
    // hi equal — lo unsigned
    if (a[0] < b[0]) {
        return 1;
    }
    return 0;
}
