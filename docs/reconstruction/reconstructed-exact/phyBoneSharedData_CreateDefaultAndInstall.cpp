// =============================================================================
// phyBoneSharedData_CreateDefaultAndInstall  (FUN_00449dc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00449dc0
// Address:   0x00449dc0  (autoassault.exe, image base 0x400000)
// Body:      0x00449dc0 – 0x00449e72 (exclusive end; 178 bytes)
// System:    physics / phy (asset I/O)
// Generated: dual A/B seal 2026-07-29 (W20-E)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Allocate a default 0x90-byte phyBoneSharedData (identity hkQsTransform +
// identity bind 4x4 + null collision slot), AddRef it, Release any prior occupant of
// *(EBX+4), and install the new pointer.
//
// ABI: EBX = container* (callers LEA EBX,[bone+0xf0] → slot bone+0xf4). Bare ret (c3).
// Saves ESI. No stack args. Not ECX-thiscall.
//
// Layout defaults:
//   +0x00 vtbl PTR_FUN_00aa050c
//   +0x04 refcount 0→1
//   +0x08 DAT_00d1eac0
//   +0x0c..+0x18 quat (0,0,0,1)
//   +0x1c..+0x24 trans (0,0,0)
//   +0x28..+0x30 scale (1,1,1)
//   +0x40..+0x7f identity matrix from DAT_00afdf70 (16 dwords)
//   +0x80 collision shape* = 0
//
// Vtbl: [0]=scalar-dtor FUN_00449d80; [1]=empty FUN_0056f570; [2]=release 0x00464890
//
// RELATED:
//   - phyBone_unserialize @ 0x0096e280 (installs before BDAT)
//   - phyBoneSharedData_unserialize @ 0x00997540
//   - phyBone_CopySharedQsTransformToLocal @ 0x0096de80
//

#include <stdint.h>

extern void *operator_new(uint32_t size);
extern float g_flOne;                 // 0x00a0f2a0 = 1.0f
extern uint32_t DAT_00d1eac0;
extern uint32_t DAT_00afdf70[16];     // identity 4x4
extern void *PTR_FUN_00aa050c;        // vtbl base

// Register ABI: EBX = container. Modeled as explicit param for readability.
void phyBoneSharedData_CreateDefaultAndInstall(void *container /* EBX */)
{
    int *obj = (int *)operator_new(0x90);
    float one = g_flOne;

    if (obj == 0) {
        obj = 0;
    } else {
        obj[1] = 0;
        *obj = (int)&PTR_FUN_00aa050c;
        obj[2] = (int)DAT_00d1eac0;
        obj[3] = 0;
        obj[4] = 0;
        obj[5] = 0;
        obj[6] = *(int *)&one;          // quat.w
        obj[7] = 0;
        obj[8] = 0;
        obj[9] = 0;
        obj[10] = *(int *)&one;         // scale
        obj[11] = *(int *)&one;
        obj[12] = *(int *)&one;
        {
            uint32_t *src = (uint32_t *)DAT_00afdf70;
            uint32_t *dst = (uint32_t *)(obj + 0x10); // +0x40
            int n = 0x10;
            while (n != 0) {
                *dst = *src;
                src++;
                dst++;
                n--;
            }
        }
        obj[0x20] = 0;                  // +0x80
    }

    if (obj != 0) {
        obj[1] = obj[1] + 1;
        if (obj[1] == 1) {
            ((void (*)(void))(*(uint32_t *)(*obj + 4)))();
        }
    }

    int *old = *(int **)((uint8_t *)container + 4);
    if (old != 0) {
        int *pRef = old + 1;
        *pRef = *pRef - 1;
        if (*pRef == 0) {
            ((void (*)(void))(*(uint32_t *)(*old + 8)))();
        }
    }
    *(int **)((uint8_t *)container + 4) = obj;
}
