// =============================================================================
// FUN_0059c8a0  (alias of FreelistSlabVector_dtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059c8a0
// Address:   0x0059c8a0  (autoassault.exe, image base 0x400000)
// Body:      0x0059c8a0–0x0059c8e1 (66 B), bare ret
// System:    container / CNDHash freelist slab vector
// Generated: 2026-07-29 W24-M dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving; machine-corrected CF vs decompiler.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept.
// Named plate: reconstructed-exact/FreelistSlabVector_dtor.cpp
// =============================================================================

#include <cstdint>

extern void _aligned_free(void *p);
extern void operator_delete(void *p);

void __fastcall FUN_0059c8a0(int param_1)
{
    void **it = *reinterpret_cast<void ***>(param_1 + 0x08);
    void **end = *reinterpret_cast<void ***>(param_1 + 0x0c);

    while (it != end) {
        _aligned_free(*it);
        ++it;
    }

    void *begin = *reinterpret_cast<void **>(param_1 + 0x08);
    if (begin != nullptr) {
        operator_delete(begin); // RETURNS
    }

    *reinterpret_cast<void **>(param_1 + 0x08) = nullptr;
    *reinterpret_cast<void **>(param_1 + 0x0c) = nullptr;
    *reinterpret_cast<void **>(param_1 + 0x10) = nullptr;
}
