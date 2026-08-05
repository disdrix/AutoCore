// =============================================================================
// StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred  (aa_00469e20)
// -----------------------------------------------------------------------------
// Address:   0x00469e20–0x00469e92 exclusive (114 B)  autoassault.exe @ 0x400000
// System:    MSVC vector insert-one + rebind iterator, POD elem 0x1c
// Wave:      W36-Q OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Elem28 {
    uint32_t d[7]; // 0x1c POD — product T English open
};

struct StdVectorElem28 {
    void* unknown0;
    Elem28* begin;    // +4
    Elem28* end;      // +8
    Elem28* cap_end;  // +0xC
};

// Sealed W34-Q: EDX=value*, stack (vec*, where*, count); RET 0xC
extern "C" void StdVector_InsertN_Elem28_ValueEdx_Inferred(
    const Elem28* value, /* EDX */
    StdVectorElem28* vec,
    Elem28* where,
    uint32_t count);

// ABI: EDI=vec*, stack (outIt*, where, value*); RET 0xC; returns outIt*
Elem28** StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
    StdVectorElem28* vec,      /* EDI */
    Elem28** outIt,            /* stack0 */
    Elem28* where,             /* stack1 */
    const Elem28* value)       /* stack2 → EDX into InsertN */
{
    Elem28* begin = vec->begin;
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

    StdVector_InsertN_Elem28_ValueEdx_Inferred(value, vec, where, 1);

    *outIt = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(vec->begin) + index * 0x1c);
    return outIt;
}
