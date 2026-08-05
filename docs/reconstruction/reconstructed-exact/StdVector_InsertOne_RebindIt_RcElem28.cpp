// =============================================================================
// StdVector_InsertOne_RebindIt_RcElem28  (aa_004612d0)
// -----------------------------------------------------------------------------
// Address:   0x004612d0–0x00461342 exclusive (114 B)  autoassault.exe @ 0x400000
// System:    MSVC vector insert-one + rebind iterator, refcounted elem 0x1c
// Wave:      W35-Q OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;
    int32_t refcount;
};

struct RcElem28 {
    uint32_t d0, d1, d2, d3;
    RcShared* resource; // +0x10
    uint8_t b0, b1, b2, pad;
    uint32_t d6;
};

struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;
    RcElem28* end;
    RcElem28* cap_end;
};

// Sealed W34-P
extern "C" void StdVector_InsertN_RcElem28(
    const RcElem28* value, /* ECX */
    StdVectorRc28* vec,
    RcElem28* where,
    uint32_t count);

// ABI: EDI=vec*, stack (outIt*, where, value*); RET 0xC; returns outIt*
RcElem28** StdVector_InsertOne_RebindIt_RcElem28(
    StdVectorRc28* vec,        /* EDI */
    RcElem28** outIt,          /* stack0 */
    RcElem28* where,           /* stack1 */
    const RcElem28* value)     /* stack2 → ECX into InsertN */
{
    RcElem28* begin = vec->begin;
    uint32_t index = 0;

    if (begin != nullptr) {
        const uint32_t size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) -
             reinterpret_cast<char*>(begin)) / 0x1c);
        if (size != 0) {
            index = static_cast<uint32_t>(
                (reinterpret_cast<char*>(where) -
                 reinterpret_cast<char*>(begin)) / 0x1c);
        }
    }

    StdVector_InsertN_RcElem28(value, vec, where, 1);

    *outIt = reinterpret_cast<RcElem28*>(
        reinterpret_cast<char*>(vec->begin) + index * 0x1c);
    return outIt;
}
