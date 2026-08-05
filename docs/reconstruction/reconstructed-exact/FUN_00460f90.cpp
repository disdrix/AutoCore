// =============================================================================
// FUN_00460f90  — twin of StdVector_PushBack_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_00460f90
// Address:   0x00460f90–0x00461011 exclusive (129 B / 0x81)
// Wave:      W36-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/StdVector_PushBack_RcElem28.cpp
// =============================================================================

#include <cstdint>

struct RcElem28;
struct StdVectorRc28;

extern "C" void StdVector_PushBack_RcElem28(
    StdVectorRc28* vec /*EAX*/,
    const RcElem28* value /*ECX*/);

// Ghidra decompiler shows void __fastcall FUN_00460f90(param_1) with in_EAX.
// Sealed retail ABI: EAX=vec*, ECX=value*, RET 0.
// Port via StdVector_PushBack_RcElem28; this twin keeps the Ghidra name.
extern "C" void FUN_00460f90(
    StdVectorRc28* vec /*EAX*/,
    const RcElem28* value /*ECX*/)
{
    StdVector_PushBack_RcElem28(vec, value);
}
