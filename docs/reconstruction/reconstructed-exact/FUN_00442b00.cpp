// =============================================================================
// FUN_00442b00  (scaffold twin of SkillSet_UninitializedCopy_0x18)
// -----------------------------------------------------------------------------
// Stable ID: aa_00442b00
// Address:   0x00442b00 – 0x00442b3e  (autoassault.exe, image base 0x400000)
// System:    skills-skillset
// Twin:      reconstructed-exact/SkillSet_UninitializedCopy_0x18.cpp
// Generated: 2026-07-29 W22-S dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Ghidra name retained. Register ABI: EAX=dest, ECX=begin, EDX=end; ret EAX=dest end.
void *__fastcall FUN_00442b00(uint32_t *param_1 /*ECX begin*/,
                              uint32_t *param_2 /*EDX end*/)
{
    // phantom dest in EAX on entry — modeled as return-value accumulation
    uint32_t *in_EAX; // dest cursor (caller-supplied)

    if (param_1 == param_2) {
        return in_EAX;
    }

    for (; param_1 != param_2; param_1 += 6) {
        if (in_EAX != nullptr) {
            in_EAX[0] = param_1[0];
            in_EAX[1] = param_1[1];
            in_EAX[2] = param_1[2];
            in_EAX[3] = param_1[3];
            in_EAX[4] = param_1[4];
            in_EAX[5] = param_1[5];
        }
        in_EAX += 6;
    }
    return in_EAX;
}
