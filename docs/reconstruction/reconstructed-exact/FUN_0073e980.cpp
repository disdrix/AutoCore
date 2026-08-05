// =============================================================================
// FUN_0073e980  — twin of Gfx_EffectMap_ReleaseAllEntries_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e980
// Address:   0x0073e980  (autoassault.exe, image base 0x400000)
// Body:      47 B (0x2F). Wave W38-W.
// Exactness: Ghidra-name twin; prefer named clean for ports.
// =============================================================================

#include <cstdint>

extern int* DAT_00d1ee68;
extern void FUN_0073e780(int payload);
extern void __fastcall FUN_004425f0(uint32_t unused_ecx, int** cur);

void FUN_0073e980(void)
{
    int* head = DAT_00d1ee68;
    int* cur = reinterpret_cast<int*>(*DAT_00d1ee68);

    while (cur != head) {
        FUN_0073e780(cur[3]);
        FUN_004425f0(0, &cur);
    }
}
