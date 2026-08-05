// =============================================================================
// FUN_0045c4b0  (== StdVector_Resize_Pod28)
// -----------------------------------------------------------------------------
// Stable ID: aa_0045c4b0
// Address:   0x0045c4b0–0x0045c552 exclusive (162 B)  autoassault.exe @ 0x400000
// Wave:      W35-M OWN-ONLY 2026-07-29
// Exactness: Twin of StdVector_Resize_Pod28.cpp (Ghidra name).
// =============================================================================

#include <cstdint>

struct Pod28 {
    uint32_t w[7];
};

struct StdVectorPod28 {
    void* unknown0;
    Pod28* begin;
    Pod28* end;
    Pod28* cap_end;
};

extern "C" void __fastcall StdVector_InsertN_Pod28(
    uint32_t count,
    StdVectorPod28* vec,
    Pod28* where,
    const Pod28* value);

extern "C" Pod28** FUN_0045cce0(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last);

// EBX=vec*, ECX=new_size, stack Pod28 by value; RET 0x1C
extern "C" void FUN_0045c4b0(
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
        StdVector_InsertN_Pod28(new_size - size, vec, vec->end, &value);
        return;
    }

    if (begin != nullptr && new_size < size) {
        Pod28* old_end = vec->end;
        Pod28* new_end = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(begin) + new_size * 0x1c);
        Pod28* tmp_it = nullptr;
        FUN_0045cce0(vec, &tmp_it, new_end, old_end);
    }
}
