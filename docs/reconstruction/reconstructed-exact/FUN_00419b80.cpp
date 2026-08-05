// =============================================================================
// FUN_00419b80  (scaffold alias — prefer CNDHash_BucketUnlinkByU64Key.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419b80
// Address:   0x00419b80  (autoassault.exe, image base 0x400000)
// Body:      0x00419b80–0x00419bc9  (73 bytes; ret 8)
// System:    container / CNDHash (u64-key family)
// Twin file: CNDHash_BucketUnlinkByU64Key.cpp
// Generated: 2026-07-29 W18-P dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <stdint.h>

// See CNDHash_BucketUnlinkByU64Key.cpp for machine ABI commentary.
// This file keeps Ghidra name as the linkable scaffold symbol.

// Decompiler-shaped signature (register fiction retained for raw CF match):
//   unaff_EBX = bucket header
//   param_1 after find is REALLY predecessor (keyLo slot reuse) — see named clean

extern "C" int FUN_00419b40(int param_1, uint32_t param_2);
extern "C" void FUN_00419ad0(void);

extern "C" int __stdcall FUN_00419b80(int param_1, uint32_t param_2)
{
    int iVar1;
    int unaff_EBX; // bucketHeader* in EBX
    int pred;      // machine: loaded from keyLo stack slot after find

    iVar1 = FUN_00419b40(param_1, param_2);
    if (iVar1 != 0) {
        // Machine: pred from *[esp+keyLo_slot], NOT the original keyLo value.
        pred = param_1; // decompiler conflation — interpret as predecessor Node*
        if (pred != 0) {
            *(uint32_t *)(pred + 0x10) = *(uint32_t *)(iVar1 + 0x10);
            FUN_00419ad0(); // EDI=bucket
            return iVar1;
        }
        *(uint32_t *)(unaff_EBX + 4) = *(uint32_t *)(iVar1 + 0x10);
    }
    FUN_00419ad0(); // EDI=bucket (hit head-case fallthrough or miss)
    return iVar1;
}
