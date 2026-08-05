// =============================================================================
// Outpost_PreRecastBankWalk
// -----------------------------------------------------------------------------
// Stable ID: aa_00606ff0
// Address:   0x00606ff0  (autoassault.exe, image base 0x400000)
// Body:      0x00606ff0 – 0x006070d6 (exclusive end; 230 B)
// System:    skills-abilities / outpost
// Generated: 2026-07-23 scaffold FUN_00606ff0; refined 2026-07-29 W20-C dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W20-C):
 * - __thiscall: ECX = outpost, stack factionIndex (0..3 else no-op), ret 4.
 * - factionBase = this + faction * 0x48.
 * - Skill bank @ factionBase+0xd4/0xd8, entry stride 0x10.
 * - Process only entries with flag@+0x0C == 0 (no ratio threshold gate).
 * - For each TFID @ factionBase+0xb4/0xb8 (stride 8):
 *     ResolveObjectTarget(mode=0, lo, hi)
 *     container = obj.vtbl[+0x1ec]()
 *     if container: MI-adjust; container.vtbl[+0x220](skillId, 1)
 * - Direct callee: CVOGReaction_ResolveObjectTarget only.
 * - Callers: Outpost_UpdateBeaconShareRatio (on ratio change, before BeaconShare);
 *   CaptureOutpost teardown with *old* faction before transfer.
 * - Distinct from Outpost_CastSkillsForBeaconShare (no ResolveSkillTargets,
 *   no ratio gate, no CastSkillOnTarget batch).
 *
 * Residual: product English for vfunc +0x220 (wire remove family uses +0x220(id,0)).
 */

#include <cstdint>

// External / virtual (names from sibling duals + Ghidra)
extern "C" void* CVOGReaction_ResolveObjectTarget(int mode, uint32_t lo, uint32_t hi);

struct VTable {
    // ...
    // +0x1ec → GetSkillHost / container
    // +0x220 → skill control (id, flag)
};

// Minimal structural types — offsets sealed; full layouts residual.
struct OutpostFactionSlot {
    // relative to this + faction*0x48
    // +0xb4 uint8_t* tfidBegin;  +0xb8 tfidEnd;  // stride 8
    // +0xd4 uint8_t* bankBegin;  +0xd8 bankEnd;  // stride 0x10
};

struct SkillBankEntry {
    uint32_t skillId;     // +0x00
    uint8_t  rank;        // +0x04 (unused here)
    uint8_t  pad[3];
    float    minRatio;    // +0x08 (unused here; BeaconShare only)
    char     flag;        // +0x0C — process iff 0
    char     pad2[3];
}; // 0x10

void __thiscall Outpost_PreRecastBankWalk(void* thisOutpost /* ECX */, uint32_t factionIndex)
{
    if ((int)factionIndex < 0 || (int)factionIndex >= 4) {
        return;
    }

    uint8_t* factionBase = static_cast<uint8_t*>(thisOutpost) + factionIndex * 0x48u;

    uint8_t* bankBegin = *reinterpret_cast<uint8_t**>(factionBase + 0xd4);
    uint8_t* bankEnd   = *reinterpret_cast<uint8_t**>(factionBase + 0xd8);

    if (bankBegin == nullptr) {
        return;
    }

    const uint32_t bankCount =
        static_cast<uint32_t>((bankEnd - bankBegin) >> 4);

    int entryOff = 0;
    for (uint32_t bi = 0; bi < bankCount; ++bi, entryOff += 0x10) {
        auto* entry = reinterpret_cast<SkillBankEntry*>(bankBegin + entryOff);
        if (entry->flag != 0) {
            continue;
        }

        uint8_t* tfidBegin = *reinterpret_cast<uint8_t**>(factionBase + 0xb4);
        uint8_t* tfidEnd   = *reinterpret_cast<uint8_t**>(factionBase + 0xb8);
        if (tfidBegin == nullptr) {
            continue;
        }

        const uint32_t tfidCount =
            static_cast<uint32_t>((tfidEnd - tfidBegin) >> 3);

        for (uint32_t ti = 0; ti < tfidCount; ++ti) {
            auto* tfid = reinterpret_cast<uint32_t*>(tfidBegin + ti * 8);
            void* obj = CVOGReaction_ResolveObjectTarget(0, tfid[0], tfid[1]);
            if (obj == nullptr) {
                continue;
            }

            // container = obj->vtbl[+0x1ec]()
            auto** vtbl = *reinterpret_cast<void***>(obj);
            using Vfn0 = void* (__thiscall*)(void*);
            void* container = reinterpret_cast<Vfn0>(vtbl[0x1ec / 4])(obj);
            if (container == nullptr) {
                continue;
            }

            // MI this-adjust: *( *(container+4) + 4 ) + container + 4
            int mid = *reinterpret_cast<int*>(static_cast<uint8_t*>(container) + 4);
            int adj = *reinterpret_cast<int*>(mid + 4);
            void* adjusted =
                reinterpret_cast<void*>(adj + reinterpret_cast<int>(container) + 4);

            auto** cvtbl = *reinterpret_cast<void***>(adjusted);
            using Vfn220 = void (__thiscall*)(void*, uint32_t, int);
            reinterpret_cast<Vfn220>(cvtbl[0x220 / 4])(adjusted, entry->skillId, 1);
        }
    }
}

// Legacy export name
void __thiscall FUN_00606ff0(void* thisOutpost, uint32_t factionIndex);
