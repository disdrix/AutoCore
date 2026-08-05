// =============================================================================
// FreelistSlabVector_dtor
// -----------------------------------------------------------------------------
// Purpose:  Tear down the freelist slab pointer vector nested in CNDHash at
//           this+0x20 (when called with freelist subobject as ECX):
//             for each slot in [begin, end): _aligned_free(*slot)
//             if begin: operator_delete(begin)  // RETURNS
//             begin = end = capacity_end = null
//           Does NOT touch freelist head at subobject +0x00 (nodes already
//           reclaimed by FreeBuckets / ReclaimAll).
//
// Address:  0x0059c8a0  (autoassault.exe, image base 0x400000)
// Body:     0x0059c8a0–0x0059c8e1 (66 bytes / 0x42), bare ret
// Stable:   aa_0059c8a0
// System:   container / CNDHash freelist slab vector
// Ghidra:   FUN_0059c8a0
//
// ABI:      __thiscall  void (FreelistSlabVector *this)  — bare ret
//
// Exactness: CF machine-corrected vs raw decompiler (noreturn + zeroing).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-M seal).
//
// DECOMPILER GAPS sealed:
//   - operator_delete is NOT noreturn; body always zeros +0x08/+0x0c/+0x10.
//   - Zeroing is not exclusive to the null-begin branch.
// Callers: 38+ CNDHash dtors (e.g. 0053b920 lea ecx,[this+0x20]); thunk 0059cbc0.
// IAT _aligned_free: 0x009c6578.
// =============================================================================

#include <cstdint>

extern void _aligned_free(void *p);
extern void operator_delete(void *p);

// void __thiscall — bare ret
void __fastcall FreelistSlabVector_dtor(void *thisVec)
{
    void **it = *reinterpret_cast<void ***>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x08);
    void **end = *reinterpret_cast<void ***>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x0c);

    while (it != end) {
        _aligned_free(*it);
        ++it;
    }

    void *begin = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x08);
    if (begin != nullptr) {
        operator_delete(begin); // RETURNS — decompiler noreturn is false
    }

    // always:
    *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x08) = nullptr;
    *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x0c) = nullptr;
    *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(thisVec) + 0x10) = nullptr;
}
