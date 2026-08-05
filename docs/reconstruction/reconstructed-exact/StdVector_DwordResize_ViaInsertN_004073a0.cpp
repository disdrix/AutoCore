// =============================================================================
// StdVector_DwordResize_ViaInsertN_004073a0
// -----------------------------------------------------------------------------
// Stable ID: aa_00410420
// Address:   0x00410420  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (multi-domain dword vectors)
// Generated: 2026-08-04 W37-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Resize MSVC-style vector<uint32_t>-shaped control block:
//     begin @ +4, end @ +8 (capacity @ +0xC used only inside grow callee).
//   Grow: insert (newCount - size) filled dwords at end via FUN_004073a0.
//   Shrink: erase [begin+newCount, end) via FUN_00410490 (no element dtors).
//   Twin: FUN_004367f0 / StdVector_DwordResize grows via FUN_004507a0 instead.
//
// ABI: __thiscall; stack (newCount, fillValue); void; ret 8.
// Body: 0x00410420–0x00410488 inclusive (105 B).
// =============================================================================

#include <cstdint>

// External (not OWN this wave):
// void __thiscall FUN_004073a0(void *vec, void *insertPos, uint32_t count, uint32_t *fillSrc);
// void __thiscall FUN_00410490(void *vec, void **outIt, void *first, void *last);

extern "C" void __thiscall FUN_004073a0(void *vec, void *insert_pos, uint32_t count, uint32_t *fill_src);
extern "C" void __thiscall FUN_00410490(void *vec, void **out_it, void *first, void *last);

void __thiscall StdVector_DwordResize_ViaInsertN_004073a0(
    void *vec,
    uint32_t new_count,
    uint32_t fill_value)
{
    auto *const begin_slot = reinterpret_cast<uint8_t **>(
        reinterpret_cast<uint8_t *>(vec) + 4);
    auto *const end_slot = reinterpret_cast<uint8_t **>(
        reinterpret_cast<uint8_t *>(vec) + 8);

    uint8_t *begin = *begin_slot;
    uint32_t size = 0;
    if (begin != nullptr) {
        size = static_cast<uint32_t>(
            (reinterpret_cast<uint8_t *>(*end_slot) - begin) >> 2);
    }

    if (size < new_count) {
        // Grow: insert (new_count - size) copies of fill_value at end.
        FUN_004073a0(vec, *end_slot, new_count - size, &fill_value);
        return;
    }

    if (begin != nullptr && new_count < size) {
        // Shrink: erase [begin + new_count, end).
        void *first = begin + new_count * 4;
        void *last = *end_slot;
        void *out_it = nullptr;
        FUN_00410490(vec, &out_it, first, last);
        (void)out_it;
    }
    // size == new_count → no-op
}

// Ghidra export alias
void __thiscall FUN_00410420(void *vec, uint32_t new_count, uint32_t fill_value)
{
    StdVector_DwordResize_ViaInsertN_004073a0(vec, new_count, fill_value);
}
