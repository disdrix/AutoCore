// =============================================================================
// FUN_0053b920  (alias of CNDHash_Dtor_009cfa7c)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053b920
// Address:   0x0053b920  (autoassault.exe, image base 0x400000)
// Body:      0x0053b920–0x0053b98a (107 B), bare ret
// System:    container / CNDHash (object vtbl PTR_FUN_009cfa7c, owning)
// Generated: 2026-07-29 W24-M dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving; machine-corrected freelist ECX = this+0x20.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept-with-gaps.
// Named plate: reconstructed-exact/CNDHash_Dtor_009cfa7c.cpp
// =============================================================================

#include <cstdint>

extern void *ExceptionList;
extern void *LAB_009a3edb;
extern void *PTR_FUN_009cfa7c;

extern void FUN_007a4480(int level, const char *msg);
extern void FUN_005390d0(void *hash);
extern void FUN_0059c8a0(void *freelistSubobject);

void __fastcall FUN_0053b920(void *param_1)
{
    void *local_c;
    void *puStack_8;
    std::uint32_t local_4;

    puStack_8 = &LAB_009a3edb;
    local_c = ExceptionList;
    ExceptionList = &local_c;

    *reinterpret_cast<void **>(param_1) = &PTR_FUN_009cfa7c;
    local_4 = 0;

    if (*reinterpret_cast<char *>(reinterpret_cast<std::uint8_t *>(param_1) + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    FUN_005390d0(param_1);
    FUN_0059c8a0(reinterpret_cast<std::uint8_t *>(param_1) + 0x20);

    ExceptionList = local_c;
}
