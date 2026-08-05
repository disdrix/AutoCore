// =============================================================================
// FUN_00463e30  (scaffold alias → StdVector_InsertN_Dword_Via4ea70_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00463e30
// Address:   0x00463e30  (autoassault.exe, image base 0x400000)
// Body:      0x00463e30 – 0x00464070 inclusive (577 B / 0x241)
// System:    util / container (generic)
// Generated: 2026-08-04 W38-M (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct VectorDword {
    void*     _unused0;
    uint32_t* begin;
    uint32_t* end;
    uint32_t* capEnd;
};

extern void FUN_004540b0();
extern void* operator_new(uint32_t);
extern void operator_delete(void*);

// Retail: __thiscall; stack (where*, count, value*); ret 0x0C.
// Full relocate/fill detail: see StdVector_InsertN_Dword_Via4ea70_Inferred.cpp
// and raw W38-M append (helpers FUN_0044ea70 / FUN_00436ef0 / FUN_0044ea50).
extern "C" void __thiscall FUN_00463e30(
    VectorDword* self,
    uint32_t* where,
    uint32_t count,
    uint32_t* value)
{
    const uint32_t fill = *value;
    uint32_t* begin = self->begin;

    uint32_t cap = 0;
    if (begin != nullptr) {
        cap = static_cast<uint32_t>(self->capEnd - begin);
    }
    if (count == 0) {
        return;
    }

    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(self->end - begin);
    }
    if (0x3FFFFFFFu - size < count) {
        FUN_004540b0();
    }

    if (cap < size + count) {
        uint32_t newCap = (0x3FFFFFFFu - (cap >> 1) < cap) ? 0u : (cap + (cap >> 1));
        if (newCap < size + count) {
            newCap = size + count;
        }
        uint32_t* neu = static_cast<uint32_t*>(operator_new(newCap * 4));
        uint32_t* old = self->begin;
        self->capEnd = neu + newCap;
        self->end    = neu + (size + count);
        self->begin  = neu;
        if (old != nullptr) {
            operator_delete(old);
        }
        (void)where;
        (void)fill;
        return;
    }

    uint32_t* end = self->end;
    if (static_cast<uint32_t>(end - where) < count) {
        self->end = end + count;
        return;
    }
    for (uint32_t* p = where; p != where + count; ++p) {
        *p = fill;
    }
}
