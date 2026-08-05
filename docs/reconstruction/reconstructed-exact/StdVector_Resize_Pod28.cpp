// =============================================================================
// StdVector_Resize_Pod28  (aa_0045c4b0)
// -----------------------------------------------------------------------------
// Address:   0x0045c4b0–0x0045c552 exclusive (162 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::resize(n, value) for POD elem size 0x1c
// Wave:      W35-M OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Pod28 {
    uint32_t w[7];  // 0x1c
};

struct StdVectorPod28 {
    void* unknown0;       // +0x00
    Pod28* begin;         // +0x04
    Pod28* end;           // +0x08
    Pod28* cap_end;       // +0x0C (unused here)
};

// Grow path: sealed W34-P InsertN (ECX=count, EDX=vec*, stack where+value*, RET 8)
extern "C" void __fastcall StdVector_InsertN_Pod28(
    uint32_t count,           /* ECX */
    StdVectorPod28* vec,      /* EDX */
    Pod28* where,             /* stack */
    const Pod28* value);      /* stack */

// Shrink path: erase [first, last) via POD 7-dword forward shift; publish end.
// Retail FUN_0045cce0 (unowned). Signature reconstructed from call site + decompile.
extern "C" Pod28** FUN_0045cce0(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last);

// ABI: EBX=vec*, ECX=new_size, stack Pod28 by value (0x1c); RET 0x1C
// Size: (end−begin)/0x1c via magic 0x92492493 when begin != 0.
extern "C" void StdVector_Resize_Pod28(
    StdVectorPod28* vec,   /* EBX */
    uint32_t new_size,     /* ECX */
    Pod28 value)           /* stack 0x1c */
{
    Pod28* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (size < new_size) {
        uint32_t count = new_size - size;
        Pod28* where = vec->end;
        // Retail: ECX=count, EDX=vec, stack where + &value
        StdVector_InsertN_Pod28(count, vec, where, &value);
        return;
    }

    if (begin != nullptr && new_size < size) {
        Pod28* old_end = vec->end;
        Pod28* new_end = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(begin) + new_size * 0x1c);
        Pod28* tmp_it = nullptr;
        FUN_0045cce0(vec, &tmp_it, new_end, old_end);
    }
    // equal size / empty: no-op
    // retail: RET 0x1C (callee cleans value blob)
}

// Ghidra twin
extern "C" void FUN_0045c4b0(
    StdVectorPod28* vec,
    uint32_t new_size,
    Pod28 value)
{
    StdVector_Resize_Pod28(vec, new_size, value);
}
