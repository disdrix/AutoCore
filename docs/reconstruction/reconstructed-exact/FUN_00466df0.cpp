// =============================================================================
// FUN_00466df0  — twin of StdVector_Resize_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00466df0
// Address:   0x00466df0–0x00466e92 exclusive (162 B)
// Wave:      W36-P OWN-ONLY 2026-07-29
// =============================================================================

#include <cstdint>

// Canonical implementation lives in StdVector_Resize_Elem28_Inferred.cpp
struct Elem28 {
    uint32_t w[7];
};

struct VectorElem28 {
    void* unknown0;
    Elem28* begin;
    Elem28* end;
    Elem28* cap_end;
};

extern "C" void StdVector_Resize_Elem28_Inferred(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value);

extern "C" void FUN_00466df0(
    VectorElem28* vec,   /* EBX */
    uint32_t new_size,   /* ECX */
    Elem28 value)        /* stack 0x1c; RET 0x1C */
{
    StdVector_Resize_Elem28_Inferred(vec, new_size, value);
}
