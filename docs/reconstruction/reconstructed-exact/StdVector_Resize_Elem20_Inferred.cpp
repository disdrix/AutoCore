// =============================================================================
// StdVector_Resize_Elem20_Inferred  (aa_00437f70)
// -----------------------------------------------------------------------------
// Address:   0x00437f70–0x00438040 exclusive (208 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::resize(n, value) for elem size 0x14
// Wave:      W38-F OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Elem20 {
    uint32_t w[5];  // 0x14 — product lanes unknown
};

struct StdVectorElem20 {
    void* unknown0;         // +0x00
    Elem20* begin;          // +0x04
    Elem20* end;            // +0x08
    Elem20* cap_end;        // +0x0C (unused here)
};

// Grow: InsertN-class (unowned FUN_004388b0). Formals from call site pushes.
extern "C" void FUN_004388b0(
    StdVectorElem20* vec,
    Elem20* where,
    uint32_t count,
    const Elem20* value);

// Shrink: erase [first, last) (unowned FUN_00438850).
extern "C" Elem20** FUN_00438850(
    StdVectorElem20* vec,
    Elem20** out_it,
    Elem20* first,
    Elem20* last);

// Epilogue helper (unowned FUN_00437f20). Residual product role.
extern "C" void __fastcall FUN_00437f20(void* ecx_target);

// ABI: ESI=vec*, ECX=new_size, stack Elem20 by value (0x14); RET 0x14
// Size: (end−begin)/0x14 via magic 0x66666667 when begin != 0.
extern "C" void StdVector_Resize_Elem20_Inferred(
    StdVectorElem20* vec,   /* ESI */
    uint32_t new_size,      /* ECX */
    Elem20 value)           /* stack 0x14 */
{
    Elem20* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x14);
    }

    if (size < new_size) {
        uint32_t count = new_size - size;
        FUN_004388b0(vec, vec->end, count, &value);
    } else if (begin != nullptr && new_size < size) {
        Elem20* old_end = vec->end;
        Elem20* new_end = reinterpret_cast<Elem20*>(
            reinterpret_cast<char*>(begin) + new_size * 0x14);
        Elem20* tmp_it = nullptr;
        FUN_00438850(vec, &tmp_it, new_end, old_end);
    }

    // Retail epilogue helper then RET 0x14 (exact ECX target residual).
    FUN_00437f20(&value);
}
