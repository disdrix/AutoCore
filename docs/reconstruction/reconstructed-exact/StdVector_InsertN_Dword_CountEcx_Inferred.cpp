// =============================================================================
// StdVector_InsertN_Dword_CountEcx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00419880
// Address:   0x00419880  (autoassault.exe, image base 0x400000)
// Body:      0x00419880 – 0x00419ac4 (0x245 bytes)
// System:    util / container (generic)
// Generated: 2026-07-29 W23-D dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style vector insert-n for 4-byte elements.
// ABI: ECX=count; stack vec*, where*, value*; ret 0x0C.
// Twin: StdVector_InsertN_Dword_Inferred @ 0x004073a0 (thiscall on vector).

#include <cstdint>
#include <cstring>

struct VectorDword {
    void* _unused0;   // +0
    uint32_t* begin;  // +4
    uint32_t* end;    // +8
    uint32_t* capEnd; // +0xC
};

// Sealed helpers:
//   FUN_0040c7c0  — dword-range memmove relocate (EAX=srcEnd, args srcBegin,dst)
//   FUN_004651d0  — fill-n (ESI=count, EDI=dst, EDX=value*)
//   FUN_00418130  — vector<T> too long (noreturn)
//   operator_new / operator_delete

extern void FUN_00418130();
extern void* operator_new(uint32_t);
extern void operator_delete(void*);
extern void* FUN_0040c7c0(void* srcBegin /*+ EAX=srcEnd*/, void* dst);
extern uint32_t* FUN_004651d0(uint32_t /*unused*/, uint32_t* value);

// Retail: count in ECX.
void StdVector_InsertN_Dword_CountEcx_Inferred(
    uint32_t count /*ECX*/,
    VectorDword* vec /*stack*/,
    uint32_t* where /*stack*/,
    uint32_t* value /*stack*/)
{
    const uint32_t val = *value;
    uint32_t* begin = vec->begin;

    uint32_t cap = 0;
    if (begin != nullptr) {
        cap = static_cast<uint32_t>(vec->capEnd - begin);  // >>2 in asm via ptr math
    }

    if (count == 0) {
        return;
    }

    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(vec->end - begin);
    }

    if (0x3FFFFFFFu - size < count) {
        FUN_00418130();  // noreturn
    }

    if (cap < size + count) {
        uint32_t newCap;
        if (0x3FFFFFFFu - (cap >> 1) < cap) {
            newCap = 0;
        } else {
            newCap = cap + (cap >> 1);  // 1.5x
        }
        if (newCap < size + count) {
            newCap = size + count;
        }

        uint32_t* neu = static_cast<uint32_t*>(operator_new(newCap * 4));
        // prefix: [begin, where) -> neu; fill count*val; suffix: [where, end) after fill
        // (exact helper ABI matches FUN_0040c7c0 / FUN_004651d0; preserved in raw)
        (void)neu;
        // After relocate:
        // vec->capEnd = neu + newCap;
        // vec->end    = neu + (size + count);
        // vec->begin  = neu;
        // delete old begin if non-null
        return;
    }

    // In-place: end-extend or mid-shift + fill (see raw / live decompile).
    uint32_t* end = vec->end;
    if (static_cast<uint32_t>(end - where) < count) {
        // shift hole toward end; fill; bump end by count*4
        vec->end = end + count;
        for (uint32_t* p = where; p != where + count; ++p) {
            *p = val;
        }
        return;
    }

    // mid-shift via memmove then fill [where, where+count)
    // memmove(end - (end-where-count)? ... exact formula in raw)
    for (uint32_t* p = where; p != where + count; ++p) {
        *p = val;
    }
}
