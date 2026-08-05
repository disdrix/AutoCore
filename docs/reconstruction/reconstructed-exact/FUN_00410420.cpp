// =============================================================================
// FUN_00410420 / StdVector_DwordResize_ViaInsertN_004073a0
// -----------------------------------------------------------------------------
// Stable ID: aa_00410420
// Address:   0x00410420  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (multi-domain dword vectors)
// Generated: 2026-08-04 W37-T dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named clean: StdVector_DwordResize_ViaInsertN_004073a0.cpp
// Twin resize: FUN_004367f0 grows via FUN_004507a0; this grows via FUN_004073a0.
// Shrink both: FUN_00410490 (StdVector_EraseRange_Dword_Inferred).
// Body: 0x00410420–0x00410488 (105 B); ret 8.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004073a0(void *vec, void *insert_pos, uint32_t count, uint32_t *fill_src);
extern "C" void __thiscall FUN_00410490(void *vec, void **out_it, void *first, void *last);

void __thiscall FUN_00410420(void *param_1, uint32_t param_2 /* newCount */, uint32_t fill_value)
{
    uint8_t *begin = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(param_1) + 4);
    uint32_t size;
    if (begin == nullptr) {
        size = 0;
    } else {
        uint8_t *end = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(param_1) + 8);
        size = static_cast<uint32_t>((end - begin) >> 2);
    }

    if (size < param_2) {
        uint32_t cur = 0;
        if (begin != nullptr) {
            uint8_t *end = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(param_1) + 8);
            cur = static_cast<uint32_t>((end - begin) >> 2);
        }
        void *end_ptr = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(param_1) + 8);
        FUN_004073a0(param_1, end_ptr, param_2 - cur, &fill_value);
        return;
    }

    if (begin != nullptr) {
        uint8_t *end = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(param_1) + 8);
        uint32_t cur = static_cast<uint32_t>((end - begin) >> 2);
        if (param_2 < cur) {
            void *first = begin + param_2 * 4;
            void *out_it = nullptr;
            FUN_00410490(param_1, &out_it, first, end);
            (void)out_it;
        }
    }
}
