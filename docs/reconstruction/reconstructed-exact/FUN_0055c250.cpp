// =============================================================================
// FUN_0055c250  (scaffold twin → StdVector_Resize_Elem28)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055c250
// Address:   0x0055c250  (autoassault.exe, image base 0x400000)
// Wave:      W37-AA 2026-08-04 — prefer StdVector_Resize_Elem28.cpp
// =============================================================================

#include <cstdint>

// See StdVector_Resize_Elem28.cpp for bytes-corrected reconstruction.
// Scaffold retained as Ghidra-name twin.

struct Elem28 {
    uint32_t w[7];
};

struct VectorElem28 {
    void* unknown0;
    Elem28* begin;
    Elem28* end;
    Elem28* cap_end;
};

extern "C" void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec, Elem28* where, uint32_t count, const Elem28* value);
extern "C" Elem28* __cdecl FUN_0055b470(Elem28* a, Elem28* b, Elem28* dest);

extern "C" void __thiscall FUN_0055c250(
    VectorElem28* param_1,
    uint32_t param_2,
    Elem28 value)
{
    Elem28* begin = param_1->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(param_1->end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }
    if (param_2 <= size) {
        if (begin != nullptr && param_2 < size) {
            Elem28* old_end = param_1->end;
            Elem28* new_end = reinterpret_cast<Elem28*>(
                reinterpret_cast<char*>(begin) + param_2 * 0x1c);
            if (new_end != old_end) {
                param_1->end = FUN_0055b470(old_end, old_end, new_end);
            }
        }
        return;
    }
    uint32_t cur = (begin != nullptr) ? size : 0;
    StdVector_InsertN_Elem28(param_1, param_1->end, param_2 - cur, &value);
}
