// =============================================================================
// Gfx_EffectMap_ReleaseAllEntries_Inferred  (aa_0073e980)
// -----------------------------------------------------------------------------
// Address:   0x0073e980  (autoassault.exe, image base 0x400000)
// Body:      0x0073e980–0x0073e9af exclusive (47 B / 0x2F)
// System:    client / Palantir graphics — global effect tree, device-reset shutdown
// Wave:      W38-W OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   For each node in the global MSVC-style tree headed by DAT_00d1ee68, release
//   the payload at node+0xC via FUN_0073e780 (clears entry resource vector /
//   freelist / count). Advances with tree iterator++ (FUN_004425f0, EDX=&cur,
//   isnil@+0x11). Does not erase nodes — resource release only.
//
// ABI: no args; plain RET. Global DAT_00d1ee68 only.
// Sole caller: GfxDevice_Reset (FUN_0075eff0) @ 0x0075f145 (shutdown stage).
//
// Ghidra: FUN_0073e980. Reject Named_CalleeOf_Named_gfxDevice_0073e980 as sole name.

#include <cstdint>

extern int* DAT_00d1ee68;
extern void FUN_0073e780(int payload);
// __fastcall-ish: EDX = int** cur; advances *cur to tree successor
extern void __fastcall FUN_004425f0(uint32_t unused_ecx, int** cur);

void Gfx_EffectMap_ReleaseAllEntries_Inferred(void)
{
    int* head = DAT_00d1ee68;
    int* cur = reinterpret_cast<int*>(*DAT_00d1ee68);

    while (cur != head) {
        // node[+0xC] payload pointer
        FUN_0073e780(cur[3]);
        FUN_004425f0(0, &cur);
    }
}
