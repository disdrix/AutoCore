// =============================================================================
// StdVector_PushBack_RcElem28  (aa_00460f90)
// -----------------------------------------------------------------------------
// Address:   0x00460f90–0x00461011 exclusive (129 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::push_back, refcounted elem 0x1c
// Wave:      W36-O OWN-ONLY 2026-07-29
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

static_assert(sizeof(RcElem28) == 0x1c, "RcElem28 stride");

struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;   // +0x04
    RcElem28* end;     // +0x08
    RcElem28* cap_end; // +0x0c
};

// Sealed W35-O: ECX=value*, EDX=count, stack dest*; RET 0
extern "C" void StdUninitFillN_RcElem28(
    const RcElem28* value, /* ECX */
    uint32_t count,        /* EDX */
    RcElem28* dest);       /* stack0 */

// Sealed W35-Q: EDI=vec*, stack (outIt*, where, value*); RET 0xC
extern "C" RcElem28** StdVector_InsertOne_RebindIt_RcElem28(
    StdVectorRc28* vec,        /* EDI */
    RcElem28** outIt,          /* stack0 */
    RcElem28* where,           /* stack1 */
    const RcElem28* value);    /* stack2 */

// ABI: EAX=vec*, ECX=value*, RET 0
extern "C" void StdVector_PushBack_RcElem28(
    StdVectorRc28* vec,      /* EAX → EDI */
    const RcElem28* value)   /* ECX */
{
    RcElem28* begin = vec->begin;
    uint32_t size = 0;

    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) -
             reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (begin != nullptr) {
        const uint32_t cap = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->cap_end) -
             reinterpret_cast<char*>(begin)) / 0x1c);
        if (size < cap) {
            RcElem28* dest = vec->end;
            // retail: push value*; push dest; mov edx,1; call fill-n; add esp,8
            StdUninitFillN_RcElem28(value, 1, dest);
            vec->end = reinterpret_cast<RcElem28*>(
                reinterpret_cast<char*>(dest) + 0x1c);
            return;
        }
    }

    // Slow path: insert-one at end; outIt written then discarded
    RcElem28* outIt = nullptr;
    // retail: EDI=vec (still), stack (outIt*, where=end, value*)
    StdVector_InsertOne_RebindIt_RcElem28(vec, &outIt, vec->end, value);
    (void)outIt;
}
