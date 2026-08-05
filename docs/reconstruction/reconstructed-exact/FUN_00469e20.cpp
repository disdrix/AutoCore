// =============================================================================
// FUN_00469e20 — scaffold twin of StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00469e20
// Address:   0x00469e20–0x00469e92 exclusive (114 B)  autoassault.exe @ 0x400000
// System:    MSVC vector insert-one + rebind, POD elem 0x1c
// Wave:      W36-Q 2026-07-29
// Prefer named clean: StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// W34-Q sealed: EDX=value*, stack (vec*, where*, count); RET 0xC
extern "C" void FUN_00469f50(void* /*value@EDX*/, void* vec, void* where, uint32_t count);

// ABI (bytes): EDI=vec*, stack (outIt*, where, value*); RET 0xC; return outIt*
extern "C" uint32_t* FUN_00469e20(uint32_t* outIt, uint8_t* where)
{
    // unaff_EDI = vec* (register formal; not in C prototype)
    // value* is stack formal #3 → EDX into FUN_00469f50
    uint8_t* vec = nullptr; /* EDI — recovered by callers */
    uint8_t* begin = vec ? *reinterpret_cast<uint8_t**>(vec + 4) : nullptr;
    int32_t index = 0;

    if (begin != nullptr) {
        uint8_t* end = *reinterpret_cast<uint8_t**>(vec + 8);
        if ((end - begin) / 0x1c != 0) {
            index = static_cast<int32_t>((where - begin) / 0x1c);
        }
    }

    FUN_00469f50(/*value@EDX*/ nullptr, vec, where, 1);

    begin = *reinterpret_cast<uint8_t**>(vec + 4);
    *outIt = reinterpret_cast<uint32_t>(begin + index * 0x1c);
    return outIt;
}
