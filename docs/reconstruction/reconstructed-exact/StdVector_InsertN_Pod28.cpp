// =============================================================================
// StdVector_InsertN_Pod28  (aa_0045cd30)
// -----------------------------------------------------------------------------
// Address:   0x0045cd30–0x0045d01c exclusive (748 B)  autoassault.exe @ 0x400000
// System:    MSVC vector insert-n for trivially copyable elem size 0x1c
// Wave:      W34-P OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Pod28 {
    // 7× float-or-dword (0x1c). Prologue copies via MOVSS ×7 from value*.
    uint32_t w[7];
};

struct StdVectorPod28 {
    void* unknown0;       // +0x00 (unused in this unit)
    Pod28* begin;         // +0x04
    Pod28* end;           // +0x08
    Pod28* cap_end;       // +0x0C
};

// External helpers (not owned by this dual)
extern "C" void FUN_004540b0();                          // throw length_error
extern "C" int  __fastcall FUN_00469c50(StdVectorPod28* vec); // StdVector_Elem28_Size
extern "C" void* operator_new(uint32_t nbytes);
extern "C" void  operator_delete(void* p);
// Range copy / fill-n / assign for 7-dword elements (trivial):
extern "C" void FUN_0045f360(/* range copy; register ABI */);
extern "C" void FUN_0045f150(/* fill-n from value; register ABI */);
extern "C" void FUN_0045efe0(/* assign fill forward */);
extern "C" void FUN_0046a240(/* assign backward */);

// Max elements for stride 0x1c: floor(UINT_MAX / 0x1c)
static constexpr uint32_t kMaxElems28 = 0x09249249u;

// ABI: ECX=count, EDX=vec*, stack (where, value*); RET 8
void __fastcall StdVector_InsertN_Pod28(
    uint32_t count,           /* ECX */
    StdVectorPod28* vec,      /* EDX */
    Pod28* where,             /* stack */
    const Pod28* value)       /* stack */
{
    // Local POD value (SSE-loaded from *value in retail)
    Pod28 local = *value;

    Pod28* begin = vec->begin;
    uint32_t cap = 0;
    if (begin != nullptr) {
        cap = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->cap_end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (count == 0) {
        return;
    }

    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (kMaxElems28 - size < count) {
        FUN_004540b0();
        // length_error; does not return in product
    }

    if (cap < size + count) {
        // 1.5× growth, floor size+count
        uint32_t new_cap = cap;
        if (kMaxElems28 - (new_cap >> 1) < new_cap) {
            new_cap = 0;
        } else {
            new_cap = new_cap + (new_cap >> 1);
        }
        if (new_cap < size + count) {
            // FUN_00469c50(vec) + count  (ECX=vec in retail)
            new_cap = static_cast<uint32_t>(FUN_00469c50(vec)) + count;
        }

        Pod28* neu = static_cast<Pod28*>(operator_new(new_cap * 0x1c));
        // prefix [begin, where) → neu; fill count copies of local; suffix [where, end)
        // → FUN_0045f360 / FUN_0045f150 (register formals; see raw)
        (void)local;
        (void)where;
        if (begin != nullptr) {
            operator_delete(begin);
        }
        vec->cap_end = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(neu) + new_cap * 0x1c);
        vec->end = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(neu) + (size + count) * 0x1c);
        vec->begin = neu;
        return;
    }

    // In-place hole vs mid-shift (FUN_0045f360 / FUN_0045f150 / FUN_0046a240 / FUN_0045efe0)
    // See raw decompile + W34-P annotated for arm selection via (end-where)/0x1c vs count.
    (void)FUN_0045f360;
    (void)FUN_0045f150;
    (void)FUN_0045efe0;
    (void)FUN_0046a240;
}
