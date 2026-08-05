// =============================================================================
// StdVector_Resize_RcElem28  (aa_004611e0)
// -----------------------------------------------------------------------------
// Address:   0x004611e0–0x004612c5 exclusive (229 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::resize(n, value) for refcounted elem size 0x1c
// Wave:      W35-Q OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;       // +0; +8 Release
    int32_t refcount; // +4
};

struct RcElem28 {
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    RcShared* resource; // +0x10
    uint8_t  b0;
    uint8_t  b1;
    uint8_t  b2;
    uint8_t  pad;
    uint32_t d6;        // +0x18
};

struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;    // +0x04
    RcElem28* end;      // +0x08
    RcElem28* cap_end;  // +0x0C
};

// Sealed W34-P: ECX=value*, stack (vec*, where, count); RET 0xC
extern "C" void StdVector_InsertN_RcElem28(
    const RcElem28* value,
    StdVectorRc28* vec,
    RcElem28* where,
    uint32_t count);

// Erase [first, last): assign-backward / destroy / publish end (unowned)
extern "C" RcElem28** FUN_00461720(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last);

static uint32_t ElemCount(const StdVectorRc28* vec) {
    if (vec->begin == nullptr) return 0;
    return static_cast<uint32_t>(
        (reinterpret_cast<const char*>(vec->end) -
         reinterpret_cast<const char*>(vec->begin)) / 0x1c);
}

static void ReleaseResource(RcShared* p) {
    if (p == nullptr) return;
    p->refcount -= 1;
    if (p->refcount == 0) {
        // (*p->vtbl)[2]();  // Release @ vtbl+8
    }
}

// ABI: EDI=vec*, ECX=new_size, stack RcElem28 by-value; RET 0x1C
void StdVector_Resize_RcElem28(
    StdVectorRc28* vec,   /* EDI */
    uint32_t new_size,    /* ECX */
    RcElem28 value)       /* stack by-value 0x1c — dtor Releases resource */
{
    const uint32_t size = ElemCount(vec);

    if (size < new_size) {
        // Grow: insert (new_size - size) copies of value at end
        StdVector_InsertN_RcElem28(
            &value,
            vec,
            vec->end,
            new_size - size);
    } else if (vec->begin != nullptr && new_size < size) {
        // Shrink: erase [begin + new_size, end)
        RcElem28* scratch = nullptr;
        RcElem28* first = reinterpret_cast<RcElem28*>(
            reinterpret_cast<char*>(vec->begin) + new_size * 0x1c);
        FUN_00461720(vec, &scratch, first, vec->end);
    }
    // else equal: no-op

    // MSVC by-value dtor of non-trivial T
    ReleaseResource(value.resource);
}
