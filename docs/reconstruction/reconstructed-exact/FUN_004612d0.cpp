// =============================================================================
// FUN_004612d0  (canonical: StdVector_InsertOne_RebindIt_RcElem28)
// -----------------------------------------------------------------------------
// Stable ID: aa_004612d0
// Address:   0x004612d0–0x00461342 exclusive (114 B)
// System:    MSVC vector insert-one + rebind, refcounted elem 0x1c
// Wave:      W35-Q OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving. Bit-for-bit / runtime: DEFERRED.
// Named plate: reconstructed-exact/StdVector_InsertOne_RebindIt_RcElem28.cpp
// =============================================================================

#include <cstdint>

struct RcElem28;
struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;
    RcElem28* end;
    RcElem28* cap_end;
};

extern "C" void FUN_004617a0(
    const void* value /*ECX*/,
    StdVectorRc28* vec,
    void* where,
    uint32_t count);

// EDI=vec*, stack (outIt*, where, value*); RET 0xC
RcElem28** FUN_004612d0(
    StdVectorRc28* vec /*EDI*/,
    RcElem28** outIt,
    RcElem28* where,
    const void* value)
{
    RcElem28* begin = vec->begin;
    uint32_t index = 0;

    if (begin != nullptr) {
        const int size = static_cast<int>(
            (reinterpret_cast<char*>(vec->end) -
             reinterpret_cast<char*>(begin)) / 0x1c);
        if (size != 0) {
            index = static_cast<uint32_t>(
                (reinterpret_cast<char*>(where) -
                 reinterpret_cast<char*>(begin)) / 0x1c);
        }
    }

    FUN_004617a0(value, vec, where, 1);

    *outIt = reinterpret_cast<RcElem28*>(
        reinterpret_cast<char*>(vec->begin) + index * 0x1c);
    return outIt;
}
