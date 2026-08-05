// =============================================================================
// FUN_00419ad0  — scaffold alias of CNDHash_BucketChainTouchRepair
// -----------------------------------------------------------------------------
// Stable ID: aa_00419ad0
// Address:   0x00419ad0  (autoassault.exe, image base 0x400000)
// Body:      0x00419ad0 – 0x00419b30 (exclusive end; 96 bytes)
// System:    container / CNDHash u64-bucket integrity
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/CNDHash_BucketChainTouchRepair.cpp
// =============================================================================
//
// ABI: EDI = bucket header* (head at +4). Bare ret.
// Node: touch byte @ +8, next @ +0x10.
// String: 0x00a64710 "HashListError: Went to node we already touched! Attempting repair!"
//

#include <stdint.h>

extern void FUN_007a4480(int severity, const char *fmt, ...);

// Decompiler-shaped CF (unaff_EDI = bucket)
void FUN_00419ad0(void)
{
    int iVar1;
    int iVar2;
    int unaff_EDI; // bucket*

    iVar2 = *(int *)(unaff_EDI + 4);
    if (*(int *)(unaff_EDI + 4) != 0) {
        do {
            iVar1 = iVar2;
            *(uint8_t *)(iVar1 + 8) = 1;
            iVar2 = *(int *)(iVar1 + 0x10);
            if (iVar2 == 0) {
                for (iVar2 = *(int *)(unaff_EDI + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
                    *(uint8_t *)(iVar2 + 8) = 0;
                }
                return;
            }
        } while (*(char *)(iVar2 + 8) == '\0');
        FUN_007a4480(1, "HashListError: Went to node we already touched! Attempting repair!");
        *(uint32_t *)(iVar1 + 0x10) = 0;
        iVar2 = *(int *)(unaff_EDI + 4);
        if (iVar2 != 0) {
            do {
                *(uint8_t *)(iVar2 + 8) = 0;
                iVar2 = *(int *)(iVar2 + 0x10);
            } while (iVar2 != 0);
            return;
        }
    }
    return;
}
