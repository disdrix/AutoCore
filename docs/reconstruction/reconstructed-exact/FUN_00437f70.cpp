// =============================================================================
// FUN_00437f70  (== StdVector_Resize_Elem20_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00437f70
// Address:   0x00437f70–0x00438040 exclusive (208 B)  autoassault.exe @ 0x400000
// Wave:      W38-F OWN-ONLY 2026-08-04
// Exactness: Twin of StdVector_Resize_Elem20_Inferred.cpp (Ghidra name).
// =============================================================================

#include <cstdint>

struct Elem20 {
    uint32_t w[5];
};

struct StdVectorElem20 {
    void* unknown0;
    Elem20* begin;
    Elem20* end;
    Elem20* cap_end;
};

extern "C" void FUN_004388b0(
    StdVectorElem20* vec,
    Elem20* where,
    uint32_t count,
    const Elem20* value);

extern "C" Elem20** FUN_00438850(
    StdVectorElem20* vec,
    Elem20** out_it,
    Elem20* first,
    Elem20* last);

extern "C" void __fastcall FUN_00437f20(void* ecx_target);

// ESI=vec*, ECX=new_size, stack Elem20 by value; RET 0x14
extern "C" void FUN_00437f70(
    StdVectorElem20* vec,   /* ESI */
    uint32_t new_size,      /* ECX */
    Elem20 value)           /* stack 0x14 */
{
    Elem20* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x14);
    }

    if (size < new_size) {
        FUN_004388b0(vec, vec->end, new_size - size, &value);
    } else if (begin != nullptr && new_size < size) {
        Elem20* old_end = vec->end;
        Elem20* new_end = reinterpret_cast<Elem20*>(
            reinterpret_cast<char*>(begin) + new_size * 0x14);
        Elem20* tmp_it = nullptr;
        FUN_00438850(vec, &tmp_it, new_end, old_end);
    }

    FUN_00437f20(&value);
}
