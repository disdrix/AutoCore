// =============================================================================
// StdVector_Resize_Elem28  (aa_0055c250)
// -----------------------------------------------------------------------------
// Address:   0x0055c250–0x0055c306 exclusive (182 B / 0xB6)
// Module:    autoassault.exe @ image base 0x400000
// System:    MSVC vector::resize(n, value) for POD elem stride 0x1c
// Wave:      W37-AA OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory. Not modernization.
//            Bit-for-bit / runtime / differential: DEFERRED (no Launcher).
// =============================================================================

#include <cstdint>

struct Elem28 {
    uint32_t w[7];  // 0x1c — product type open (same residual as InsertN_Elem28)
};

struct VectorElem28 {
    void* unknown0;     // +0x00
    Elem28* begin;      // +0x04
    Elem28* end;        // +0x08
    Elem28* cap_end;    // +0x0C (unused in this body)
};

// W34-R sealed: thiscall InsertN; stack where*, count, value*; RET 0x0C
extern "C" void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,       /* ECX */
    Elem28* where,
    uint32_t count,
    const Elem28* value);

// Unowned POD range helper FUN_0055b470: cdecl copy [first,last) → dest.
// Entry loads dest into EAX; empty range returns dest unchanged.
// Caller of resize pushes a 4th unused dword and ADD ESP,0x10.
extern "C" Elem28* __cdecl FUN_0055b470(
    Elem28* src_first,
    Elem28* src_last,
    Elem28* dest);

// ABI: __thiscall ECX=vec*; stack new_size (4) + Elem28 by value (0x1c) = 0x20;
//      dual epilogues RET 0x20. Size via magic 0x92492493 when begin != 0.
extern "C" void __thiscall StdVector_Resize_Elem28(
    VectorElem28* vec,   /* ECX */
    uint32_t new_size,   /* stack */
    Elem28 value)        /* stack by value 0x1c */
{
    Elem28* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (new_size <= size) {
        if (begin != nullptr && new_size < size) {
            Elem28* old_end = vec->end;
            Elem28* new_end = reinterpret_cast<Elem28*>(
                reinterpret_cast<char*>(begin) + new_size * 0x1c);
            if (new_end != old_end) {
                // Retail: push unused, push new_end, push end, push end; ADD ESP,0x10
                // Empty source range → EAX remains dest (new_end)
                vec->end = FUN_0055b470(old_end, old_end, new_end);
            }
        }
        return;  // ret 0x20
    }

    uint32_t cur = (begin != nullptr) ? size : 0;
    // Grow: InsertN at end with (new_size - cur) copies of value
    StdVector_InsertN_Elem28(vec, vec->end, new_size - cur, &value);
    return;  // ret 0x20
}

// Ghidra twin
extern "C" void __thiscall FUN_0055c250(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value)
{
    StdVector_Resize_Elem28(vec, new_size, value);
}
