// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, while×1.
//  - Notable callees: CVOGReaction_CastSkillOnTarget, Object_ResolveFromTFID, Skill_ApplyStatusEffectLocal, skillId.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_CastSkillOnTarget
// -----------------------------------------------------------------------------
// Purpose:  Pack SkillStatusEffect 0x2031 buffer and optionally apply local
//           status via Skill_ApplyStatusEffectLocal. Reaction / NPC cast path.
//
// Address:  0x004d09a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004d09a0
// System:   skills-abilities
//
// Convention: MSVC __thiscall (this = world/context with +0x7e server-sim flag)
//
// Packet 0x2031 (VERIFIED size formula and field sources from packer body):
//   size = nTargets * 0x18 + 0x58
//     (base 0x58 = 0x40 header-to-targets + 0x18 terminator slot;
//      ApplyStatusEffectLocal uses (size-0x40)/0x18 → nTargets+1)
//   +0x00  msgId 0x2031
//   +0x04  size (u16)
//   +0x08  skillId          (skill+0x5FC)
//   +0x0C  level            (skill+0x5f6 + skill+0x174)
//   +0x10  remaining charge (skill+0x14 - param, clamped >= 0)  // lDelayTime
//   +0x14  status           0 or 'c' (99) from param_10 ONLY
//                           (ResolveTargetList 0xd/0xe map is local; not stored here)
//   +0x18  position float3  (param_7)
//   +0x28  source TFID      (param_3 +0x160)
//   +0x38  item flag        (param_5 == 0)
//   +0x3c  optional param_9 when param_8
//   targets @ +0x40 stride 0x18 {TFID16, s16 mana, s16 maxMana, pad}
//   terminator = g_abTfidInvalid (DAT_009cbf68..)
//
// Entry gate: this+0x7e != 0 && skill != 0 && source != 0
// Side effects: heap + optional Skill_ApplyStatusEffectLocal.
// NO network send in this unit (callees: resolve/apply/heap only; 2026-07-29 dual).
// Dual: reviews/A_aa_004d09a0_* + B_aa_004d09a0_*; chain CHAIN_2026-07-29_castskillontarget_0x2031_packer.md
//
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

// Minimal TFID_16 (session)
struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
    std::uint8_t  bGlobal;
    std::uint8_t  bPad[3];
    // decomp also reads bPad3 as dword with bGlobal - treat as 8B tail after coids
    std::uint8_t  bPad3[4];
};

extern "C" void* operator_new(std::uint32_t);
extern "C" void* operator_new__(std::uint32_t); // array new
extern "C" void  operator_delete(void*);
extern "C" void  operator_delete__(void*);
extern "C" void  Skill_ResolveTargetList(
    void* outList, int world, void* source,
    int t0, int t1, int t2, int t3, void* pos, std::uint32_t* errOut);
extern "C" int*  Object_ResolveFromTFID(TFID_16* tfid);
extern "C" int   Skill_ApplyStatusEffectLocal(void* source, int, void* packet, char);
extern "C" std::uint32_t DAT_009cbf68;
extern "C" std::uint32_t DAT_009cbf6c;
extern "C" std::uint32_t DAT_009cbf70;
extern "C" std::uint32_t DAT_009cbf74;

std::uint32_t __thiscall CVOGReaction_CastSkillOnTarget(
    int thisWorld,          // param_1 - world/context; gate at +0x7e
    int pSkill,             // param_2 - skill runtime
    void* pSource,          // param_3 - source object (TFID at +0x160)
    int* pTargetObj,        // param_4 - optional target object
    char bNotItemSkill,     // param_5 - inverted into packet item flag
    TFID_16* pTargetList,   // param_6 - null → allocate + Skill_ResolveTargetList
    std::uint32_t* pAimPos, // param_7 - float3 position
    char bHasExtra,         // param_8
    std::uint32_t extraVal, // param_9
    char bStatusC,          // param_10 - status 'c' (99) when nonzero
    int chargeConsumed)     // param_11 - subtracted from skill+0x14
{
    std::uint32_t* termSlot;
    bool ownedTargetList = false;
    int tmp;
    std::uint32_t* alloc;
    int* tfidSrc;
    void* nScratch;
    std::uint32_t* pPacket = nullptr;
    TFID_16* pTfid;
    std::uint32_t resolveFlags = 0;
    int worldSaved = thisWorld;
    int nTargets;

    if (!((*(char*)(thisWorld + 0x7e) != '\0') && (pSkill != 0) && (pSource != nullptr))) {
        return 0;
    }

    // Optional target-object rewrite for certain world types (0xe/0x12/0x14/3)
    if ((pTargetObj != nullptr)
        && (((tmp = *(int*)(pTargetObj[0x2a] + 0x38), tmp == 0xe || (tmp == 0x12))
             || ((tmp == 0x14 || (tmp == 3))))))
    {
        tmp = (**(int(***)())(*pTargetObj + 0x19c))();
        if (tmp == 0) {
            pTargetObj = nullptr;
        } else {
            pTargetObj = (int*)(*(int*)(*(int*)(tmp + 4) + 4) + 4 + tmp);
        }
    }

    // Allocate 0x9a0 status-effect buffer
    alloc = (std::uint32_t*)operator_new(0x9a0);
    pPacket = nullptr;
    if (alloc != nullptr) {
        alloc[8] = 0;
        alloc[7] = 0;
        alloc[6] = 0;
        pPacket = alloc;
    }

    *pPacket = 0x2031;
    *(bool*)(pPacket + 0xe) = (bNotItemSkill == '\0'); // +0x38 item flag
    pPacket[2] = *(std::uint32_t*)(pSkill + 0x5fc);    // skillId
    // Source TFID from pSource+0x160
    pPacket[10] = *(std::uint32_t*)((int)pSource + 0x160);
    pPacket[0xb] = *(std::uint32_t*)((int)pSource + 0x164);
    pPacket[0xc] = *(std::uint32_t*)((int)pSource + 0x168);
    pPacket[0xd] = *(std::uint32_t*)((int)pSource + 0x16c);
    // Level = rank + bonus
    *(std::int16_t*)(pPacket + 3) =
        (std::int16_t)(*(std::int16_t*)(pSkill + 0x5f6) + *(std::int16_t*)(pSkill + 0x174));
    // Status: 0 or 'c' (99)
    *(std::uint8_t*)(pPacket + 5) = (std::uint8_t)(-(bStatusC != '\0') & 99);

    // Remaining charge / lDelayTime
    chargeConsumed = *(std::int16_t*)(pSkill + 0x14) - chargeConsumed;
    pPacket[4] = (std::uint32_t)chargeConsumed;
    if (chargeConsumed < 0) {
        pPacket[4] = 0;
    }

    // Position
    pPacket[6] = pAimPos[0];
    pPacket[7] = pAimPos[1];
    pPacket[8] = pAimPos[2];

    if (bHasExtra != '\0') {
        pPacket[0xf] = extraVal;
    }

    ownedTargetList = false;
    if (pTargetList == nullptr) {
        ownedTargetList = true;
        pTargetList = (TFID_16*)operator_new__(0x640);

        tfidSrc = pTargetObj + 0x58;
        if (pTargetObj == nullptr) {
            tfidSrc = (int*)&DAT_009cbf68;
        }

        Skill_ResolveTargetList(
            pTargetList,
            worldSaved,
            pSource,
            *tfidSrc,
            tfidSrc[1],
            tfidSrc[2],
            tfidSrc[3],
            pAimPos,
            &resolveFlags);

        // Map resolve flags → eSkillResponses-ish codes
        if (resolveFlags != 0) {
            if ((resolveFlags & 2) == 0) {
                if ((resolveFlags & 4) == 0) {
                    resolveFlags = ((int)(char)resolveFlags & 8U | 4) >> 2;
                } else {
                    resolveFlags = 0xe; // wrong target
                }
            } else {
                resolveFlags = 0xd; // range
            }
        }
    }

    nTargets = 0;
    alloc = pPacket + 0x14; // first target slot write cursor (stride 6 dwords = 0x18)
    pTfid = pTargetList;

    // Walk TFID list until invalid terminator
    while (((pTfid->dwCoidLo & pTfid->dwCoidHi) != 0xffffffff) || (pTfid->bGlobal != 0)) {
        int* obj = Object_ResolveFromTFID(pTfid);

        if (obj == nullptr) {
            nTargets = nTargets + 1;
            alloc[-4] = DAT_009cbf68;
            alloc[-3] = DAT_009cbf6c;
            alloc[-2] = DAT_009cbf70;
            alloc[-1] = DAT_009cbf74;
            *(std::uint16_t*)alloc = 0;
            *(std::uint16_t*)((int)alloc + 2) = 0;
            pTfid = pTfid + 1;
            alloc = alloc + 6;
        } else {
            alloc[-4] = pTfid->dwCoidLo;
            alloc[-3] = pTfid->dwCoidHi;
            alloc[-2] = *(std::uint32_t*)&pTfid->bGlobal;
            alloc[-1] = *(std::uint32_t*)&pTfid->bPad3;

            tmp = (**(int(***)())(*obj + 0x214))();
            if (tmp != 0) {
                // mana / maxMana at plant +300 / +0x12e
                *(std::uint16_t*)alloc = *(std::uint16_t*)(tmp + 300);
                *(std::uint16_t*)((int)alloc + 2) = *(std::uint16_t*)(tmp + 0x12e);
            }

            nTargets = nTargets + 1;
            pTfid = pTfid + 1;
            alloc = alloc + 6;
        }
    }

    if (ownedTargetList) {
        operator_delete__(pTargetList);
    }

    // Terminator TFID after last target
    termSlot = pPacket + nTargets * 6 + 0x10;
    *termSlot = DAT_009cbf68;
    termSlot[1] = DAT_009cbf6c;
    termSlot[2] = DAT_009cbf70;
    termSlot[3] = DAT_009cbf74;

    // size = nTargets*0x18 + 0x58  (decomp: (nTargets*3)*8 + 0x58)
    nScratch = (void*)(nTargets * 3);
    *(std::int16_t*)(pPacket + 1) = (std::int16_t)((int)nScratch * 8 + 0x58);

    // Local apply when targets present or skill flags, and not bHasExtra
    if ((((((pPacket[0x10] & pPacket[0x11]) != 0xffffffff)
           || (*(char*)(pPacket + 0x12) != '\0'))
          || (*(int*)(pSkill + 0x614) == 1))
         || (((*(std::uint8_t*)(pSkill + 0x624) & 1) != 0
              && (nScratch = pSource,
                  *(int*)(*(int*)((int)pSource + 0xa8) + 0x38) == 0x12))))
        && (bHasExtra == '\0'))
    {
        resolveFlags =
            (std::uint32_t)Skill_ApplyStatusEffectLocal(pSource, (int)nScratch, pPacket, '\0');
    }

    // Decomp warns "does not return" on operator_delete - treat as normal free.
    operator_delete(pPacket);

    return 0;
}
