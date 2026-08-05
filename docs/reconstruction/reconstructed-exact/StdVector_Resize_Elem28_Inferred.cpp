// =============================================================================
// StdVector_Resize_Elem28_Inferred  (aa_00466df0)
// -----------------------------------------------------------------------------
// Address:   0x00466df0–0x00466e92 exclusive (162 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::resize(n, value) for POD elem size 0x1c (Elem28 family)
// Wave:      W36-P OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Elem28 {
    uint32_t w[7];  // 0x1c
};

struct VectorElem28 {
    void* unknown0;       // +0x00
    Elem28* begin;        // +0x04
    Elem28* end;          // +0x08
    Elem28* cap_end;      // +0x0C (unused here)
};

// Grow path: sealed W34-Q InsertN (ECX=count, EDX=vec*, stack where+value*, RET 8)
extern "C" void __fastcall StdVector_InsertN_Elem28_CountEcx_Inferred(
    uint32_t count,           /* ECX */
    VectorElem28* vec,        /* EDX */
    Elem28* where,            /* stack */
    const Elem28* value);     /* stack */

// Shrink path: erase [first, last) via POD forward shift; publish end.
// Retail FUN_0045cce0 (unowned). Signature from call site + sibling Pod28 resize.
extern "C" Elem28** FUN_0045cce0(
    VectorElem28* vec,
    Elem28** out_it,
    Elem28* first,
    Elem28* last);

// ABI: EBX=vec*, ECX=new_size, stack Elem28 by value (0x1c); RET 0x1C
// Size: (end−begin)/0x1c via magic 0x92492493 when begin != 0.
extern "C" void StdVector_Resize_Elem28_Inferred(
    VectorElem28* vec,   /* EBX */
    uint32_t new_size,   /* ECX */
    Elem28 value)        /* stack 0x1c */
{
    Elem28* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (size < new_size) {
        uint32_t count = new_size - size;
        Elem28* where = vec->end;
        // Retail: ECX=count, EDX=vec, stack where + &value
        StdVector_InsertN_Elem28_CountEcx_Inferred(count, vec, where, &value);
        return;
    }

    if (begin != nullptr && new_size < size) {
        Elem28* old_end = vec->end;
        Elem28* new_end = reinterpret_cast<Elem28*>(
            reinterpret_cast<char*>(begin) + new_size * 0x1c);
        Elem28* tmp_it = nullptr;
        FUN_0045cce0(vec, &tmp_it, new_end, old_end);
    }
    // equal size / empty: no-op
    // retail: RET 0x1C (callee cleans value blob)
}

// Ghidra twin
extern "C" void FUN_00466df0(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value)
{
    StdVector_Resize_Elem28_Inferred(vec, new_size, value);
}
