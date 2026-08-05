// =============================================================================
// phyBone_CopySharedQsTransformToLocal  (FUN_0096de80)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096de80
// Address:   0x0096de80  (autoassault.exe, image base 0x400000)
// Body:      0x0096de80 – 0x0096dedd (exclusive end; 93 bytes)
// System:    physics / phy (asset I/O)
// Generated: dual A/B seal 2026-07-29 (W20-E)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Mirror phyBoneSharedData hkQsTransform (10 floats: quat4+trans3+scale3)
// from *(bone+0xf4) into bone local storage at +0x04..+0x28, then set bone+0x140
// to 0xffffffff (invalidate / dirty sentinel).
//
// ABI: EAX = phyBone* this. Bare ret (c3). Saves ESI/EDI. Leaf (no callees).
//
// Copy map:
//   shared+0x0c..+0x18 → bone+0x04..+0x10  (quat)
//   shared+0x1c..+0x24 → bone+0x14..+0x1c  (trans)
//   shared+0x28..+0x30 → bone+0x20..+0x28  (scale)
// Does NOT copy bind 4x4 at shared+0x40 or collision ptr at shared+0x80.
//
// RELATED:
//   - phyBone_unserialize @ 0x0096e280 (caller after BDAT)
//   - phyBoneSharedData_CreateDefaultAndInstall @ 0x00449dc0
//   - phyBoneSharedData_unserialize @ 0x00997540
//

#include <stdint.h>

// Register ABI: EAX = phyBone*. Modeled as explicit param for readability.
void phyBone_CopySharedQsTransformToLocal(void *bone /* EAX */)
{
    uint8_t *b = (uint8_t *)bone;
    uint8_t *shared = *(uint8_t **)(b + 0xf4);

    *(uint32_t *)(b + 0x04) = *(uint32_t *)(shared + 0x0c);
    *(uint32_t *)(b + 0x08) = *(uint32_t *)(shared + 0x10);
    *(uint32_t *)(b + 0x0c) = *(uint32_t *)(shared + 0x14);
    *(uint32_t *)(b + 0x10) = *(uint32_t *)(shared + 0x18);
    *(uint32_t *)(b + 0x14) = *(uint32_t *)(shared + 0x1c);
    *(uint32_t *)(b + 0x18) = *(uint32_t *)(shared + 0x20);
    *(uint32_t *)(b + 0x1c) = *(uint32_t *)(shared + 0x24);
    *(uint32_t *)(b + 0x20) = *(uint32_t *)(shared + 0x28);
    *(uint32_t *)(b + 0x24) = *(uint32_t *)(shared + 0x2c);
    *(uint32_t *)(b + 0x28) = *(uint32_t *)(shared + 0x30);
    *(uint32_t *)(b + 0x140) = 0xffffffff;
}
