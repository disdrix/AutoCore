// =============================================================================
// StdVector_InsertOne_RebindIt_Elem28  (aa_0055c310)
// -----------------------------------------------------------------------------
// Address:   0x0055c310–0x0055c383 exclusive (115 B / 0x73)
// Module:    autoassault.exe @ image base 0x400000
// System:    MSVC vector insert-one + rebind iterator, POD elem stride 0x1c
// Wave:      W37-AF OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

// POD element stride 0x1c (7 dwords / movss ladder in InsertN). Product type open.
struct Elem28 {
    uint32_t w[7];
};

struct VectorElem28 {
    void* unknown0;   // +0x0  (allocator / cookie; unused here)
    Elem28* begin;    // +0x4
    Elem28* end;      // +0x8
    Elem28* cap_end;  // +0xC
};

// Sealed W34-R — insert count copies; may realloc; trivial dtor (delete only)
extern "C" void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,   /* ECX */
    Elem28* where,
    uint32_t count,
    const Elem28* value); // RET 0x0C

// ABI: ECX=vec*, stack (outIt*, where, value*); void; RET 0x0C
void __thiscall StdVector_InsertOne_RebindIt_Elem28(
    VectorElem28* vec,        /* ECX */
    Elem28** outIt,           /* stack0 */
    Elem28* where,            /* stack1 */
    const Elem28* value)      /* stack2 */
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

    StdVector_InsertN_Elem28(vec, where, 1, value);

    *outIt = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(vec->begin) + index * 0x1c);
}
