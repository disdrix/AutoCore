// READABILITY (human dual residual 2026-07-29):
//  - Asm-sealed ABI RET 0xC: (this, owner, skill, chargeMs) — not 2-stack plate.
//  - Owner vs skill split: vehicle/pool/map/attach use owner; CD/category/skill store use skill.
//  - No-vehicle equip mod = g_flOne (1.0f), not decompiler unaff_EBX.
//  - Category insert pack sealed ≡ Skill_InsertCategoryCooldown.
//  - Notable callees: ceil, ROUND/fistp, CVOGHBBase_*, Vehicle_GetSkillCooldownModifier,
//    Skill_GetCategoryCooldownMap, Skill_CategoryCooldownMap_Insert.

// =============================================================================
// CVOGHBOKToCastAgain_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct type-8 "OK to cast again" heartbeat. Duration drives
//           hotbar cooldown overlay via category map / skill cast flags.
//
// Address:  0x0051e240  (autoassault.exe, image base 0x400000)
// Stable:   aa_0051e240
// System:   skills-abilities
//
// Convention: MSVC __thiscall (this = new HB object) — RET 0xC
//
// Parameters:
//   this           - cast-again HB (0x28 bytes from StartCastAgainHeartbeat)
//   pOwnerEntity   - character/owner (vtbl+0x210 vehicle path, +0x1dc pool,
//                    category map host +0x6c, AttachOwner target)
//   pSkillRuntime  - skill runtime (cooldown at +0x10, category at +0x5e8,
//                    stored at HB+0x24)
//   nChargeDelayMs - added after ROUND(ceil(cooldown * equipModifier))
//
// Formula (asm VERIFIED 2026-07-29):
//   equipMod = g_flOne if owner.vtbl+0x210()==0
//            else ST0 from Vehicle_GetSkillCooldownModifier(vehicle-or-ctx)
//   durationMs = ROUND(ceil(skill+0x10 * equipMod)) + nChargeDelayMs
//   if owner.vtbl+0x1dc() != 0 && *(pool+0x6b4) >= 1:
//     durationMs = min(durationMs, 500)
//   if skill+0x5e8 != -1:
//     insert {key, g_dwClientTickMs, duration} into GetCategoryCooldownMap(owner)
//   type field +0x1c = 8; AttachOwner(owner); skill @ +0x24
//
// Exactness: Behavior-preserving CF from bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined plate: 2026-07-23; dual residual ABI seal 2026-07-29
// =============================================================================

#include <cstdint>
#include <cmath>

extern "C" void* ExceptionList;
extern "C" void* LAB_009a3738;
extern "C" void* g_pVtbl_CVOGHBOKToCastAgain;
extern "C" std::uint32_t g_dwClientTickMs; // DAT_00b041cc
extern "C" float g_flOne;                  // DAT_00a0f2a0 = 1.0f

extern "C" void  CVOGHBBase_ctor(void* self);
extern "C" void  CVOGHBBase_SetPeriodAndCounter(void* self, int period, int flag);
extern "C" long double Vehicle_GetSkillCooldownModifier(/* ECX = resolve result */);
extern "C" void* Skill_GetCategoryCooldownMap(void* pMapOwner); // lazy map @ +0x6c
extern "C" void  Skill_CategoryCooldownMap_Insert(
    void* pMap, void* pOutPair, int* pEntry /* {key, start, duration} */);
extern "C" void  CVOGHBBase_AttachOwnerObject(void* hb, void* pOwner);

// FPU extraout stand-in when modifier path runs.
extern "C" long double g_extraout_ST0_SkillCdMod;

struct CategoryCdEntry {
    int           key;
    std::uint32_t startTick;
    int           durationMs;
};

void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb,
    void* pOwnerEntity,
    void* pSkillRuntime,
    int nChargeDelayMs)
{
    int nTemp;
    void* pResolve;
    std::uint32_t nDurationClamped;
    long double flEquipModifier;
    double dVar1;
    CategoryCdEntry entry;
    std::uint8_t outPair[8];
    void* local_1c;
    void* pvStack_10;
    void* pvStack_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    local_4 = 0xffffffff;
    puStack_8 = (std::uint8_t*)LAB_009a3738;
    pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    local_1c = thisHb;

    CVOGHBBase_ctor(thisHb);
    local_4 = 0;
    *(void***)thisHb = (void**)&g_pVtbl_CVOGHBOKToCastAgain;
    CVOGHBBase_SetPeriodAndCounter(thisHb, 1, 1);

    // owner.vtbl+0x210 — vehicle/equip resolve gate
    nTemp = (**(int(***)())(*(int*)pOwnerEntity + 0x210))();
    if (nTemp == 0) {
        flEquipModifier = (long double)g_flOne; // 1.0f — not polluted FPU
    } else {
        // Second +0x210 path (pushes involve skill+0x5ec); result → GetSkillCooldownModifier
        void* pScaleRelated = *(void**)((int)pSkillRuntime + 0x5ec);
        pResolve = (void*)(**(int(***)(int))(*(int*)pOwnerEntity + 0x210))(0);
        (void)pScaleRelated;
        (void)Vehicle_GetSkillCooldownModifier(/* ECX = pResolve */);
        flEquipModifier = g_extraout_ST0_SkillCdMod;
    }

    // durationMs = ROUND(ceil(cooldownMs * equipModifier)) + chargeDelay → HB+0x8
    dVar1 = std::ceil((double)((long double)*(int*)((int)pSkillRuntime + 0x10) * flEquipModifier));
    *(int*)((int)thisHb + 8) = (int)std::round((float)dVar1) + nChargeDelayMs;

    // If owner pool (vtbl+0x1dc) has +0x6b4 >= 1, clamp duration to 500 ms
    nTemp = (**(int(***)())(*(int*)pOwnerEntity + 0x1dc))();
    if (nTemp != 0) {
        nTemp = (**(int(***)())(*(int*)pOwnerEntity + 0x1dc))();
        if (0 < *(int*)(nTemp + 0x6b4)) {
            nDurationClamped = *(std::uint32_t*)((int)thisHb + 8);
            if (499 < nDurationClamped) {
                nDurationClamped = 500;
            }
            *(std::uint32_t*)((int)thisHb + 8) = nDurationClamped;
        }
    }

    // Category cooldown map insert unless category key is -1
    if (*(int*)((int)pSkillRuntime + 0x5e8) != -1) {
        entry.key = *(int*)((int)pSkillRuntime + 0x5e8);
        entry.startTick = g_dwClientTickMs;
        entry.durationMs = *(int*)((int)thisHb + 8);
        void* pMap = Skill_GetCategoryCooldownMap(pOwnerEntity);
        Skill_CategoryCooldownMap_Insert(pMap, outPair, &entry.key);
    }

    CVOGHBBase_AttachOwnerObject(thisHb, pOwnerEntity);
    *(void**)((int)thisHb + 0x24) = pSkillRuntime;
    *(std::uint32_t*)((int)thisHb + 0x1c) = 8; // heartbeat type

    ExceptionList = pvStack_10;
    (void)puStack_8;
    (void)local_4;
    (void)pvStack_c;
    return thisHb;
}
