// =============================================================================
// FUN_0096de80  — scaffold alias of phyBone_CopySharedQsTransformToLocal
// -----------------------------------------------------------------------------
// Stable ID: aa_0096de80
// Address:   0x0096de80  (autoassault.exe, image base 0x400000)
// Body:      0x0096de80 – 0x0096dedd (exclusive end; 93 bytes)
// System:    physics / phy (asset I/O)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-E)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/phyBone_CopySharedQsTransformToLocal.cpp
// =============================================================================
//
// ABI: EAX = phyBone* this. Bare ret. Leaf.
// Copy 10 floats shared qs → bone locals; bone+0x140 = -1.
//

#include <stdint.h>

// Decompiler-shaped CF (in_EAX = bone)
void FUN_0096de80(void)
{
    int iVar1;
    int in_EAX;

    iVar1 = *(int *)(in_EAX + 0xf4);
    *(uint32_t *)(in_EAX + 4) = *(uint32_t *)(iVar1 + 0xc);
    *(uint32_t *)(in_EAX + 8) = *(uint32_t *)(iVar1 + 0x10);
    *(uint32_t *)(in_EAX + 0xc) = *(uint32_t *)(iVar1 + 0x14);
    *(uint32_t *)(in_EAX + 0x10) = *(uint32_t *)(iVar1 + 0x18);
    *(uint32_t *)(in_EAX + 0x14) = *(uint32_t *)(iVar1 + 0x1c);
    *(uint32_t *)(in_EAX + 0x18) = *(uint32_t *)(iVar1 + 0x20);
    *(uint32_t *)(in_EAX + 0x1c) = *(uint32_t *)(iVar1 + 0x24);
    *(uint32_t *)(in_EAX + 0x20) = *(uint32_t *)(iVar1 + 0x28);
    *(uint32_t *)(in_EAX + 0x24) = *(uint32_t *)(iVar1 + 0x2c);
    *(uint32_t *)(in_EAX + 0x28) = *(uint32_t *)(iVar1 + 0x30);
    *(uint32_t *)(in_EAX + 0x140) = 0xffffffff;
    return;
}
