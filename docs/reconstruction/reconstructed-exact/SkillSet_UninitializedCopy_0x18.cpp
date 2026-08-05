// =============================================================================
// SkillSet_UninitializedCopy_0x18
// -----------------------------------------------------------------------------
// Stable ID: aa_00442b00
// Address:   0x00442b00 – 0x00442b3e  (autoassault.exe, image base 0x400000)
// System:    skills-skillset
// Twin:      reconstructed-exact/FUN_00442b00.cpp
// Parents:   FUN_00440f80, FUN_00442760 (SkillSet vector insert / reallocate)
// Generated: 2026-07-29 W22-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Copy [begin, end) of 0x18-byte POD elements into dest.
//   Return dest end (dest + n*0x18). Empty range returns dest unchanged.

#include <cstdint>

void *SkillSet_UninitializedCopy_0x18(void *dest /*EAX*/,
                                      void *begin /*ECX*/,
                                      void *end /*EDX*/)
{
    uint32_t *d = static_cast<uint32_t *>(dest);
    uint32_t *s = static_cast<uint32_t *>(begin);
    uint32_t *e = static_cast<uint32_t *>(end);

    if (s == e) {
        return d;
    }

    for (; s != e; s += 6, d += 6) {
        if (d != nullptr) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
            d[4] = s[4];
            d[5] = s[5];
        }
    }
    return d;
}
