// =============================================================================
// FUN_00460d70  — twin of RcElem28_Release
// -----------------------------------------------------------------------------
// Stable ID: aa_00460d70
// Address:   0x00460d70–0x00460d83 exclusive (19 B / 0x13)
// Wave:      W36-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/RcElem28_Release.cpp
// =============================================================================

#include <cstdint>

struct RcElem28;

extern "C" void RcElem28_Release(RcElem28* elem /*EAX*/);

// Ghidra decompiler shows void FUN_00460d70(void) with in_EAX.
// Sealed retail ABI: EAX=elem*, RET 0 (or tail JMP vtbl+8 when refcount hits 0).
// Port via RcElem28_Release; this twin keeps the Ghidra name.
extern "C" void FUN_00460d70(RcElem28* elem /*EAX*/)
{
    RcElem28_Release(elem);
}
