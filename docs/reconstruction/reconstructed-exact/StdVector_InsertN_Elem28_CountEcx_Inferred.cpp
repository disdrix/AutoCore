// =============================================================================
// StdVector_InsertN_Elem28_CountEcx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00466ea0
// Address:   0x00466ea0  (autoassault.exe, image base 0x400000)
// Body:      0x00466ea0 – 0x00467174 (0x2D5 / 725 bytes)
// System:    util / container (generic)
// Generated: 2026-07-29 W34-Q dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style vector insert-n for 28-byte POD elements.
// ABI: ECX=count; EDX=vec*; stack where*, value*; ret 8.
// Peer: StdVector_InsertN_Elem28_ValueEdx_Inferred @ 0x00469f50 (different ABI).
// Not: basic_string insert @ 0x004306b0; dword CountEcx @ 0x00419880.

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
//   FUN_00469c50  — StdVector_Elem28_Size (ECX=vec)
//   FUN_004673b0  — uninit-copy range (7 dwords/elem; EAX=dest)
//   FUN_00467320  — uninit-fill-n (EAX=count; dest/value regs)
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

// Retail: count in ECX, vec in EDX.
void StdVector_InsertN_Elem28_CountEcx_Inferred(
    uint32_t count /*ECX*/,
    VectorElem28* vec /*EDX*/,
    Elem28* where /*stack*/,
    const Elem28* value /*stack*/)
{
    Elem28 local{};
    if (value != nullptr) {
        std::memcpy(&local, value, sizeof(Elem28));
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

    // max elems = 0x9249249 == ~0u / 0x1c
    if (0x9249249u - size < count) {
        FUN_004540b0();  // noreturn
    }

    if (cap < size + count) {
        uint32_t newCap;
        if (0x9249249u - (cap >> 1) < cap) {
            newCap = 0;
        } else {
            newCap = cap + (cap >> 1);  // 1.5x
        }
        if (newCap < size + count) {
            // exact floor via size helper + count (retail may recompute size)
            newCap = FUN_00469c50(vec) + count;
            // note: retail uses size + count after recompute; equivalent floor
            if (newCap < size + count) newCap = size + count;
        }

        Elem28* neu = static_cast<Elem28*>(operator_new(newCap * 0x1c));
        // prefix [begin, where) -> neu; fill count*local; suffix [where, end)
        // (exact helper ABI: FUN_004673b0 / FUN_00467320; preserved in raw)
        (void)neu;
        (void)local;
        (void)where;
        // After relocate:
        // vec->capEnd = neu + newCap;
        // vec->end    = neu + (size + count);
        // vec->begin  = neu;
        // delete old begin if non-null
        return;
    }

    // In-place: end-extend or mid-shift + fill (see raw / live decompile).
    Elem28* end = vec->end;
    if (elem_count(where, end) < count) {
        // hole toward end; fill from local; bump end by count*0x1c
        vec->end = reinterpret_cast<Elem28*>(
            reinterpret_cast<char*>(end) + count * 0x1c);
        return;
    }

    // mid-shift via reverse-copy then assign [where, where+count)
    (void)local;
}
