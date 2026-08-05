// =============================================================================
// FUN_00437e40  (== StdVector_Resize_Elem56_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00437e40
// Address:   0x00437e40–0x00437f1e exclusive (222 B)  autoassault.exe @ 0x400000
// Wave:      W38-F OWN-ONLY 2026-08-04
// Exactness: Twin of StdVector_Resize_Elem56_Inferred.cpp (Ghidra name).
// =============================================================================

#include <cstdint>

struct BasicString28 {
    uint32_t storage[7];
};

struct Elem56 {
    BasicString28 a;
    BasicString28 b;
};

struct StdVectorElem56 {
    void* unknown0;
    Elem56* begin;
    Elem56* end;
    Elem56* cap_end;
};

extern "C" void FUN_00438520(
    StdVectorElem56* vec,
    Elem56* where,
    uint32_t count,
    const Elem56* value);

extern "C" Elem56** FUN_00438430(
    StdVectorElem56* vec,
    Elem56** out_it,
    Elem56* first,
    Elem56* last);

extern "C" void __fastcall FUN_00437da0(Elem56* elem);

// EDI=vec*, ECX=new_size, stack Elem56 by value; RET 0x38
extern "C" void FUN_00437e40(
    StdVectorElem56* vec,   /* EDI */
    uint32_t new_size,      /* ECX */
    Elem56 value)           /* stack 0x38 */
{
    Elem56* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x38);
    }

    if (size < new_size) {
        FUN_00438520(vec, vec->end, new_size - size, &value);
    } else if (begin != nullptr && new_size < size) {
        Elem56* old_end = vec->end;
        Elem56* new_end = reinterpret_cast<Elem56*>(
            reinterpret_cast<char*>(begin) + new_size * 0x38);
        Elem56* tmp_it = nullptr;
        FUN_00438430(vec, &tmp_it, new_end, old_end);
    }

    FUN_00437da0(&value);
}
