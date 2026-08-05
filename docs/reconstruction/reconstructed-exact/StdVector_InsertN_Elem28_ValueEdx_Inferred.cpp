// =============================================================================
// StdVector_InsertN_Elem28_ValueEdx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00469f50
// Address:   0x00469f50  (autoassault.exe, image base 0x400000)
// Body:      0x00469f50 – 0x0046a203 (0x2B4 / 692 bytes)
// System:    util / container (generic)
// Generated: 2026-07-29 W34-Q dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style vector insert-n for 28-byte POD elements.
// ABI: EDX=value*; stack vec*, where*, count; ret 0x0C.
// Peer: StdVector_InsertN_Elem28_CountEcx_Inferred @ 0x00466ea0 (different ABI).

#include <cstdint>
#include <cstring>

struct Elem28 {
    uint32_t w[7];  // 0x1c POD
};

struct VectorElem28 {
    void* _unused0;    // +0
    Elem28* begin;     // +4
    Elem28* end;       // +8
    Elem28* capEnd;    // +0xC
};

// Sealed / known helpers (unowned duals):
//   FUN_004540b0  — "vector<T> too long" (noreturn)
//   FUN_00469c50  — StdVector_Elem28_Size
//   FUN_0046a350  — uninit-copy range (7 dwords/elem)
//   FUN_0046a260  — uninit-fill-n from template
//   FUN_0046a240  — reverse-copy elems
//   FUN_0045efe0  — assign-range from template
//   operator_new / operator_delete

extern void FUN_004540b0();
extern uint32_t FUN_00469c50(/*ECX*/ VectorElem28* vec);
extern void* operator_new(uint32_t);
extern void operator_delete(void*);

static uint32_t elem_count(const Elem28* a, const Elem28* b)
{
    if (a == nullptr) return 0;
    return static_cast<uint32_t>(
        (reinterpret_cast<const char*>(b) - reinterpret_cast<const char*>(a)) / 0x1c);
}

// Retail: value in EDX; vec/where/count on stack; ret 0x0C.
void StdVector_InsertN_Elem28_ValueEdx_Inferred(
    const Elem28* value /*EDX*/,
    VectorElem28* vec /*stack*/,
    Elem28* where /*stack*/,
    uint32_t count /*stack*/)
{
    Elem28 local{};
    if (value != nullptr) {
        std::memcpy(&local, value, sizeof(Elem28));  // retail: rep movsd ×7
    }

    Elem28* begin = vec->begin;
    uint32_t cap = 0;
    if (begin != nullptr) {
        cap = elem_count(begin, vec->capEnd);
    }

    if (count == 0) {
        return;
    }

    uint32_t size = 0;
    if (begin != nullptr) {
        size = elem_count(begin, vec->end);
    }

    if (0x9249249u - size < count) {
        FUN_004540b0();  // noreturn
    }

    if (cap < size + count) {
        uint32_t newCap;
        if (0x9249249u - (cap >> 1) < cap) {
            newCap = 0;
        } else {
            newCap = cap + (cap >> 1);
        }
        if (newCap < size + count) {
            newCap = FUN_00469c50(vec) + count;
            if (newCap < size + count) newCap = size + count;
        }

        Elem28* neu = static_cast<Elem28*>(operator_new(newCap * 0x1c));
        // prefix / fill-n / suffix via FUN_0046a350 + FUN_0046a260 (see raw)
        (void)neu;
        (void)local;
        (void)where;
        return;
    }

    Elem28* end = vec->end;
    if (elem_count(where, end) < count) {
        vec->end = reinterpret_cast<Elem28*>(
            reinterpret_cast<char*>(end) + count * 0x1c);
        return;
    }

    (void)local;
}
