// =============================================================================
// FUN_004f4f00 — scaffold twin of Vehicle_ActivateHardpointWeapons_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4f00
// Address:   0x004f4f00  (autoassault.exe, image base 0x400000)
// Body:      171 B (0x004f4f00–0x004f4faa); exclusive end 0x004f4fab
// System:    combat / vehicle hardpoint weapons
// Generated: 2026-07-29 W25-E dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: body hex sealed; package DEFERRED.
// Dual A/B: accept-with-gaps (see reviews/A|B_aa_004f4f00_*).
// Named clean: Vehicle_ActivateHardpointWeapons_Inferred.cpp
// =============================================================================

#include <cstdint>

extern float g_flOne;
void FUN_0056a260(int value);

// Decompiler-faithful twin (types from Ghidra). Prefer named clean for ports.
void __fastcall FUN_004f4f00(int param_1)
{
    int *piVar1;
    int iVar2;

    iVar2 = 0;
    do {
        if (*(int *)(iVar2 + *(int *)(param_1 + 0x260)) != 0) {
            FUN_0056a260(0);
            piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0x260));
            if (piVar1[2] == 0) {
                auto **vtbl = reinterpret_cast<void **>(*piVar1);
                using FullFn = void(__thiscall *)(int *, int, int, int, int, int, int, int, float, int);
                reinterpret_cast<FullFn>(vtbl[0])(piVar1, 1, 0, 0, 0, 0, 0, 0, g_flOne, 0);
            } else {
                auto **vtbl = reinterpret_cast<void **>(*piVar1);
                using ShortFn = void(__thiscall *)(int *, int);
                reinterpret_cast<ShortFn>(vtbl[0x18 / sizeof(void *)])(piVar1, 1);
            }
        }
        iVar2 = iVar2 + 4;
    } while (iVar2 < 0xc);
    return;
}
