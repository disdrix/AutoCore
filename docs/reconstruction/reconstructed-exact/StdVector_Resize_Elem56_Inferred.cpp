// =============================================================================
// StdVector_Resize_Elem56_Inferred  (aa_00437e40)
// -----------------------------------------------------------------------------
// Address:   0x00437e40–0x00437f1e exclusive (222 B)  autoassault.exe @ 0x400000
// System:    MSVC vector::resize(n, value) for elem size 0x38
//            T layout evidence: two basic_string at +0 and +0x1c (via FUN_00437da0)
// Wave:      W38-F OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC Dinkumware basic_string is typically 0x1c; dual-string element = 0x38.
// Opaque POD-shaped stand-in for layout size only (not a true string port).
struct BasicString28 {
    uint32_t storage[7];  // 0x1c
};

struct Elem56 {
    BasicString28 a;  // +0x00
    BasicString28 b;  // +0x1c
};

struct StdVectorElem56 {
    void* unknown0;         // +0x00
    Elem56* begin;          // +0x04
    Elem56* end;            // +0x08
    Elem56* cap_end;        // +0x0C (unused here)
};

// Grow: InsertN-class (unowned FUN_00438520). Formals from call site pushes.
extern "C" void FUN_00438520(
    StdVectorElem56* vec,
    Elem56* where,
    uint32_t count,
    const Elem56* value);

// Shrink: erase [first, last) (unowned FUN_00438430).
extern "C" Elem56** FUN_00438430(
    StdVectorElem56* vec,
    Elem56** out_it,
    Elem56* first,
    Elem56* last);

// Element / stack-value dtor: destroys two basic_string (ECX=this).
extern "C" void __fastcall FUN_00437da0(Elem56* elem);

// ABI: EDI=vec*, ECX=new_size, stack Elem56 by value (0x38); RET 0x38
// Size: (end−begin)/0x38 via magic 0x92492493 when begin != 0.
extern "C" void StdVector_Resize_Elem56_Inferred(
    StdVectorElem56* vec,   /* EDI */
    uint32_t new_size,      /* ECX */
    Elem56 value)           /* stack 0x38 */
{
    Elem56* begin = vec->begin;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x38);
    }

    if (size < new_size) {
        uint32_t count = new_size - size;
        FUN_00438520(vec, vec->end, count, &value);
    } else if (begin != nullptr && new_size < size) {
        Elem56* old_end = vec->end;
        Elem56* new_end = reinterpret_cast<Elem56*>(
            reinterpret_cast<char*>(begin) + new_size * 0x38);
        Elem56* tmp_it = nullptr;
        FUN_00438430(vec, &tmp_it, new_end, old_end);
    }

    // Retail epilogue: destroy by-value fill, then RET 0x38
    FUN_00437da0(&value);
}
