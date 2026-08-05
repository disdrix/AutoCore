// =============================================================================
// FUN_004611e0  (canonical: StdVector_Resize_RcElem28)
// -----------------------------------------------------------------------------
// Stable ID: aa_004611e0
// Address:   0x004611e0–0x004612c5 exclusive (229 B)
// System:    MSVC vector resize, refcounted elem 0x1c
// Wave:      W35-Q OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving. Bit-for-bit / runtime: DEFERRED.
// Named plate: reconstructed-exact/StdVector_Resize_RcElem28.cpp
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;
    int32_t refcount;
};

struct RcElem28 {
    uint32_t d0, d1, d2, d3;
    RcShared* resource;
    uint8_t b0, b1, b2, pad;
    uint32_t d6;
};

struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;
    RcElem28* end;
    RcElem28* cap_end;
};

extern "C" void FUN_004617a0(
    const RcElem28* value /*ECX*/,
    StdVectorRc28* vec,
    RcElem28* where,
    uint32_t count);

extern "C" RcElem28** FUN_00461720(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last);

// EDI=vec*, ECX=new_size, stack value[0x1c] by-value; RET 0x1C
void FUN_004611e0(StdVectorRc28* vec /*EDI*/, uint32_t new_size /*ECX*/,
                  RcElem28 value /*stack*/)
{
    uint32_t size = 0;
    if (vec->begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) -
             reinterpret_cast<char*>(vec->begin)) / 0x1c);
    }

    if (size < new_size) {
        FUN_004617a0(&value, vec, vec->end, new_size - size);
    } else if (vec->begin != nullptr && new_size < size) {
        RcElem28* scratch = nullptr;
        RcElem28* first = reinterpret_cast<RcElem28*>(
            reinterpret_cast<char*>(vec->begin) + new_size * 0x1c);
        FUN_00461720(vec, &scratch, first, vec->end);
    }

    if (value.resource != nullptr) {
        value.resource->refcount -= 1;
        if (value.resource->refcount == 0) {
            // (**code**)(*resource + 8)();
        }
    }
}
