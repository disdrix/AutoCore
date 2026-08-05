// =============================================================================
// FUN_00438040  (alias of StdVector_Resize_Elem8_ViaInsertN_00438d80)
// -----------------------------------------------------------------------------
// Stable ID: aa_00438040
// Address:   0x00438040  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (8-byte element vectors)
// Generated: 2026-08-04 W38-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical clean: StdVector_Resize_Elem8_ViaInsertN_00438d80.cpp
// This twin keeps the Ghidra FUN_* name for tooling that keys on it.
// =============================================================================

#include <cstdint>

extern "C" void FUN_00438d80(void *vec, void *insert_pos, uint32_t count, void *fill_src);
extern "C" void FUN_00438d00(void *vec, void *out_it, void *first, void *last);

struct Elem8Fill {
    uint32_t lo;
    int *rep;
};

void __fastcall FUN_00438040(uint32_t new_count, void *vec, Elem8Fill fill)
{
    auto *const begin_slot = reinterpret_cast<uint8_t **>(
        reinterpret_cast<uint8_t *>(vec) + 4);
    auto *const end_slot = reinterpret_cast<uint8_t **>(
        reinterpret_cast<uint8_t *>(vec) + 8);

    uint8_t *begin = *begin_slot;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<uint8_t *>(*end_slot) - begin) >> 3);
    }

    if (size < new_count) {
        FUN_00438d80(vec, *end_slot, new_count - size, &fill);
    } else if (begin != nullptr && new_count < size) {
        void *first = begin + new_count * 8;
        void *last = *end_slot;
        uint32_t out_it = new_count;
        FUN_00438d00(vec, &out_it, first, last);
        (void)out_it;
    }

    if (fill.rep != nullptr) {
        int *refcount = fill.rep + 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            auto **vtbl = reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(fill.rep));
            vtbl[2]();
        }
    }
}
