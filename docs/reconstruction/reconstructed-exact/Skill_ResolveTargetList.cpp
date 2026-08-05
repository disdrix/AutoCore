// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×13, goto×4, return×2, for×1, do×1, while×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget,
//      Skill_FilterTargetForResolveList_Inferred (0x0054ff00),
//      Skill_RangeCheckTargetForResolveList_Inferred (0x0058c0a0),
//      Skill_GatherTargetsInArea (0x0058d330).
//  - Return sites: 2.
//
// Dual residual 2026-07-29 (reviews/a_00550300.md):
//  - outFlags bit1/bit2 written here; bits 4/8/0x10 written only in Filter.
//  - DAT_009d1ca8 wipe sentinel == g_abTfidInvalid_A15870 image bytes.

// =============================================================================
// Skill_ResolveTargetList
// -----------------------------------------------------------------------------
// Purpose:  Build up to 100 TFID slots for a cast from skill targeting flags.
//           Optional primary object → filter → range check → optional area gather.
//           Sets *outFlags: bit1 no-target, bit2 out-of-range (INFERRED labels).
//           Filter (0x0054ff00) may OR bits 4 / 8 / 0x10 before return.
//
// Address:  0x00550300  (autoassault.exe, image base 0x400000)
// Stable:   aa_00550300
// System:   skills-abilities
//
// Convention: MSVC __thiscall (this in ECX = skill runtime)
//
// Returns: final target count written into outList (char promoted to int).
//
// Callers: Client_Skill_ResolveCastTarget; CVOGReaction_CastSkillOnTarget
//          (when no prebuilt TFID list); NPC_TryCastSkillFromSet.
//
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

// 16-byte TFID slot (coid lo/hi + global + pad) — stride used as 4 dwords.
struct TFID_16_dwords {
    std::uint32_t d0;
    std::uint32_t d1;
    std::uint32_t d2;
    std::uint32_t d3;
};

// Invalid TFID wipe source — image bytes match g_abTfidInvalid_A15870 @ 0x00a15870.
extern "C" std::uint32_t DAT_009d1ca8;
extern "C" std::uint32_t DAT_009d1cac;
extern "C" std::uint32_t DAT_009d1cb0;
extern "C" std::uint32_t DAT_009d1cb4;
extern "C" float g_flZero;

extern "C" std::uint32_t CVOGReaction_ResolveObjectTarget(
    std::uint32_t tfidGlobal, std::uint32_t tfidLo, std::uint32_t tfidHi);

// thiscall: skill in ECX; ORs *outFlags bits 4/8/0x10 on reject (sole writer).
int* __thiscall Skill_FilterTargetForResolveList_Inferred(
    void* thisSkill, void* resolvedObj, void* source, std::uint32_t* outFlags);

// Sole caller this function. Returns g_flZero → caller ORs outFlags bit2.
extern "C" long double Skill_RangeCheckTargetForResolveList_Inferred(
    int* obj, void* source,
    std::uint32_t minRange, std::uint32_t maxRange,
    std::uint32_t skillField34, std::uint8_t skillByte5e7);

extern "C" char Skill_GatherTargetsInArea(
    TFID_16_dwords* outList, char countSoFar, void* gatherCtx, void* source,
    int* centerPos4, std::uint32_t radiusOrRange, std::uint32_t maxAdd,
    std::uint32_t f1, std::uint32_t f2, std::uint32_t modeBit4000,
    std::uint32_t modeBit20, int one, std::uint32_t modeFlag, int zero,
    std::uint32_t radiusSentinel);

int __thiscall Skill_ResolveTargetList(
    int thisSkill,                 // ECX — skill runtime
    int* outList,                  // 100 TFID slots (4 dwords each)
    std::uint32_t gatherCtx,       // param_3 → GatherTargetsInArea
    int* pSourceObj,               // param_4 — caster/source
    std::uint32_t tfidLo,          // param_5
    std::uint32_t tfidHi,          // param_6
    std::uint32_t tfidGlobal,      // param_7 — low byte used as char
    std::uint32_t /*param_8 unused in body*/,
    int* pFallbackPos,             // param_9 — 4-dword position source
    std::uint32_t* outFlags)       // param_10
{
    bool bHasPrimary = true;
    std::uint32_t resolved;
    int* pPrimary;
    std::uint32_t mode;
    int i;
    int* pCursor;
    int* pWork;
    long double flRange;
    std::uint32_t gArg, rArg, f1, f2, bit20, bit4000, maxAdd, modeFlag;
    char count;
    int center[4];

    // 1. Invalidate all 100 slots
    i = 100;
    pCursor = outList;
    do {
        pCursor[0] = (int)DAT_009d1ca8;
        pCursor[1] = (int)DAT_009d1cac;
        pCursor[2] = (int)DAT_009d1cb0;
        i = i - 1;
        pCursor[3] = (int)DAT_009d1cb4;
        pCursor = pCursor + 4;
    } while (i != 0);

    count = 0;

    // 2. Primary TFID present?
    if (((tfidLo & tfidHi) == 0xffffffff) && ((char)tfidGlobal == '\0')) {
        bHasPrimary = false;
    }

    resolved = CVOGReaction_ResolveObjectTarget(tfidGlobal, tfidLo, tfidHi);
    // thiscall: ECX = thisSkill; may OR outFlags bits 4/8/0x10
    pPrimary = Skill_FilterTargetForResolveList_Inferred(
        (void*)thisSkill, (void*)(std::uintptr_t)resolved, pSourceObj, outFlags);

    if (pPrimary == nullptr) {
LAB_no_primary:
        // skill+0x614 bit0: self-position fallback allowed
        // skill+0x614 bit5 (0x20) = Ground (tooltip); clears no-target fail
        if ((*(std::uint32_t*)(thisSkill + 0x614) & 1) == 0) {
            if (bHasPrimary && ((*(std::uint32_t*)(thisSkill + 0x614) & 0x20) == 0)) {
                *outFlags = *outFlags | 1; // no target (writer = this body)
                return 0;
            }
        } else {
            // source.vtbl+0x1a0 → position provider
            pFallbackPos = (int*)(**(int*(***)())(*pSourceObj + 0x1a0))();
        }
LAB_copy_center:
        center[0] = pFallbackPos[0];
        center[1] = pFallbackPos[1];
        center[2] = pFallbackPos[2];
        center[3] = pFallbackPos[3];
    } else {
        pWork = pPrimary;

        // Creature/character types 0x12 / 0x14 → optional vehicle body remap
        if ((*(int*)(pPrimary[0x2a] + 0x38) == 0x12)
            || (*(int*)(pPrimary[0x2a] + 0x38) == 0x14))
        {
            i = (**(int(***)())(*pPrimary + 0x1d8))();
            i = *(int*)(i + 0x250);
            if ((i == 0)
                || ((pWork = (int*)(*(int*)(*(int*)(i + 4) + 4) + 4 + i),
                     pWork == nullptr)
                    || (i = (**(int(***)())(*pPrimary + 0x1d8))(),
                        *(char*)(i + 0x30c) == '\0')))
            {
                pWork = pPrimary;
            }
        } else {
            pWork = pPrimary;
        }

        flRange = Skill_RangeCheckTargetForResolveList_Inferred(
            pWork,
            pSourceObj,
            *(std::uint32_t*)(thisSkill + 0x2c),
            *(std::uint32_t*)(thisSkill + 0x28),
            *(std::uint32_t*)(thisSkill + 0x34),
            *(std::uint8_t*)(thisSkill + 0x5e7));

        if ((long double)g_flZero == flRange) {
            *outFlags = *outFlags | 2; // out of range (writer = this body)
            goto LAB_no_primary;
        }

        // Primary TFID into slot 0 (object +0x160 as dword indices 0x58..0x5b)
        outList[0] = pPrimary[0x58];
        outList[1] = pPrimary[0x59];
        outList[2] = pPrimary[0x5a];
        outList[3] = pPrimary[0x5b];
        count = 1;

        // Nested position if work-obj flag bit5 set
        if ((((std::uint32_t)pWork[0x5f] >> 5) & 1) != 0) {
            i = (**(int(***)())(*pWork + 0x1c8))();
            if (*(int*)(i + 8) == 0) {
                pFallbackPos = (int*)(*(int*)(*(int*)(i + 4) + 4) + 0x84 + i);
            } else {
                pFallbackPos = (int*)(*(int*)(*(int*)(i + 8) + 0x3c) + 0xb0);
            }
            goto LAB_copy_center;
        }

        center[0] = pWork[0x20];
        center[1] = pWork[0x21];
        center[2] = pWork[0x22];
        center[3] = pWork[0x23];
    }

    // 6. Targeting mode → optional area gather
    mode = *(std::uint32_t*)(thisSkill + 0x624);
    if (((mode & 0x20) == 0) && ((mode & 0x4000) == 0)) {
        if ((mode & 1) == 0) {
            goto LAB_done; // single / no gather
        }
        if ((std::uint32_t)*(std::uint8_t*)(thisSkill + 0xde) <= (std::uint32_t)(int)count) {
            goto LAB_done;
        }
        // Top-up remaining maxTargets - count
        rArg = *(std::uint32_t*)(thisSkill + 0x34);
        gArg = *(std::uint32_t*)(thisSkill + 0x28);
        f2 = *(std::uint32_t*)(thisSkill + 0x610);
        f1 = *(std::uint32_t*)(thisSkill + 0x60c);
        modeFlag = 0;
        bit20 = 0;
        bit4000 = 0;
        maxAdd = (std::uint32_t)*(std::uint8_t*)(thisSkill + 0xde) - (int)count;
    } else {
        if ((mode == 0) || (mode == 0x20)) {
            modeFlag = 1;
        } else {
            modeFlag = 0;
        }
        rArg = 0xbf800000; // -1.0f sentinel
        gArg = *(std::uint32_t*)(thisSkill + 0x38);
        bit20 = (*(std::uint32_t*)(thisSkill + 0x624) >> 5) & 0xffffff01;
        bit4000 = (*(std::uint32_t*)(thisSkill + 0x624) >> 0xe) & 0xffffff01;
        f1 = *(std::uint32_t*)(thisSkill + 0x60c);
        f2 = *(std::uint32_t*)(thisSkill + 0x610);
        maxAdd = (std::uint32_t)*(std::uint8_t*)(thisSkill + 0xde);
    }

    count = Skill_GatherTargetsInArea(
        (TFID_16_dwords*)outList,
        count,
        (void*)gatherCtx,
        pSourceObj,
        center,
        gArg,
        maxAdd,
        f1,
        f2,
        bit4000,
        bit20,
        1,
        modeFlag,
        0,
        rArg);

LAB_done:
    return (int)count;
}
