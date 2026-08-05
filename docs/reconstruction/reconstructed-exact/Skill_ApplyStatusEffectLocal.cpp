// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×25, return×4, goto×1, do×1, while×1.
//  - Notable callees: CONCAT22×3, FUN_004e2600×2, Skill_ApplyStatusEffectLocal×2, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGReaction_RandomUnitScalar, CVOGReaction_ResolveObjectTarget, FUN_00514e00.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 4.

// =============================================================================
// Skill_ApplyStatusEffectLocal
// -----------------------------------------------------------------------------
// Purpose:  Apply a SkillStatusEffect (0x2031) buffer locally: load/create skill,
//           cancel optimistic cast binding when needed, start cast-again HB on
//           sim, then apply effects now or spawn delayed CVOGHBWakeupSkill HB.
//
// Address:  0x0051aa00  (autoassault.exe, image base 0x400000)
// Stable:   aa_0051aa00
// System:   skills-abilities
//
// Convention: decompiler surface is __fastcall
//   (pCasterObj ECX, nInferred EDX unused, pPacket, bIsLocalCaster)
// Callers: Client_RecvSkillStatusEffect, CVOGReaction_CastSkillOnTarget.
//
// Packet offsets (PACKET STRUCTURES SMSG_Sector_SkillStatusEffect + dual residual):
//   +0x04 uiSize u16 · +0x08 lSkillID · +0x0c iSkillLevel · +0x10 lDelayTime
//   +0x14 eSkillResponses (not read here) · +0x18 pos float3 · +0x28 fidSource
//   +0x38 bIsItemSkill · +0x3c lDiceSeed · +0x40 sSkillTargetInfo[] stride 0x18
//
// Returns: local_4f8 — 2 fail; 0 ok; 0x11 binding-present (early skip apply or
//          after apply). Wire 0x11 CANCELLED_ACTIVE is handled in Recv only.
//          Recv discards this return.
//
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Dual residual 2026-07-29: sizeof(CVOGHBBase)==0x28 converts HB mis-type
// overlays → skill +0x174/+0x5f6 rank, +0x5fc id, +0x614 flags, +0x61c skip-CD,
// +0x5e8 category, +0x10 cooldown. FUN_005538a0→Skill_ApplyEffectsOnTarget_Inferred;
// FUN_006061e0→CVOGHBWakeupSkill_ctor (RTTI).
// =============================================================================

#include <cstdint>

struct CVOGHBBase; // decompiler mis-type only

extern "C" void* ExceptionList;
extern "C" void* LAB_009a36d2;
extern "C" void* LAB_00512eb0;
extern "C" std::uint8_t g_abTfidInvalid_9CDF88[];

extern "C" void  Skill_EnsureLoadedInTree(void* caster, int skillId, int zero);
extern "C" void  Skill_SetRankAndReevaluate(void* skill, void* rankPack, short tail);
extern "C" void* CVOGReaction_ResolveSkillTargets(void* skillId, int rankPack);
extern "C" void  CVOGReaction_RandomUnitScalar(int n, void* buf);
extern "C" std::uint32_t FUN_0051b720(std::uint32_t n, void* buf);
extern "C" void  Skill_LookupActiveCastBinding(void* outTfid16, int skillId);
extern "C" int   CVOGReaction_ResolveObjectTarget(int g, std::uint32_t lo, std::uint32_t hi);
extern "C" void  FUN_00514e20(int a, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, int);
extern "C" void  Skill_ClearCastBindingAndMaybeRestartCd(
    void* caster, void* a, std::uint32_t, std::uint32_t, int, char);
extern "C" int   TFID_EqualsObjectId(void* a, void* b);
extern "C" void  Skill_StartCastAgainHeartbeat(void* caster, void* skill, void* delay, int);
extern "C" void  Skill_ClearActiveCastCounterAndQueueId(int skillId);
extern "C" void  Skill_InsertCategoryCooldown(int category, int untilTick);
extern "C" void* operator_new__(std::uint32_t);
extern "C" void  operator_delete__(void*);
extern "C" void* operator_new(std::uint32_t);
extern "C" void  operator_delete(void*);
extern "C" void  CNDDoubleList_InvokePredicateAndRemove_Inferred(void* fn, void* flag, int);
extern "C" void  FUN_00514ff0(int);
// Skill thiscall — residual-named 2026-07-29
extern "C" unsigned  Skill_ApplyEffectsOnTarget_Inferred(
    void* skill, void* caster, void* world, void* tfidList, void* pos, std::uint32_t extra);
// RTTI Confirmed: CVOGHBWakeupSkill
extern "C" void* CVOGHBWakeupSkill_ctor(
    void* self, std::uint32_t delay, void* caster, void* skill, void* world,
    void* tfidList, void* pos, std::uint32_t extra, std::uint8_t itemFlag);
extern "C" void  CVOGHBList_Enqueue(void* list, void* hb);
extern "C" void  CVOGHBBase_Start(void* hb);
extern "C" void  FUN_007a4480(int, const char*);
// Role High: caster+0x64 active-cast counter --
extern "C" void  Skill_DecActiveCastCounter(void* caster /* ECX */);

int __fastcall Skill_ApplyStatusEffectLocal(
    void* pCasterObj,
    int nInferred,
    void* pPacket,
    char bIsLocalCaster)
{
    std::uint32_t* puVar1;
    std::uint32_t* puVar2;
    CVOGHBBase* thisSkill; // raw name: this — skill runtime, NOT heartbeat
    int iVar3;
    std::uint32_t* puVar4;
    void* pvVar5;
    int iVar6;
    std::uint16_t extraout_var = 0;
    int unaff_EDI = 0; // decompiler hole — preserved
    std::uint32_t uVar7;
    std::uint8_t* puVar8;

    std::uint32_t uStack_510;
    std::uint8_t auStack_50c[4];
    CVOGHBBase* local_508;
    std::uint8_t auStack_504[4];
    std::uint32_t* puStack_500;
    std::uint32_t local_4fc;
    int local_4f8;
    std::uint32_t* puStack_4f4;
    std::uint32_t uStack_4f0;
    std::uint32_t uStack_4ec;
    int iStack_4e8;
    char cStack_4e4;
    std::uint32_t uStack_4e0;
    std::uint32_t uStack_4dc;
    std::uint32_t uStack_4d8;
    std::uint32_t uStack_4d4;
    std::uint8_t local_4d0[1204];
    void* pvStack_1c;
    std::uint8_t* puStack_18;
    std::uint32_t uStack_14;

    uStack_14 = 0xffffffff;
    puStack_18 = (std::uint8_t*)LAB_009a36d2;
    pvStack_1c = ExceptionList;
    local_4f8 = 2;

    if (*(char*)((int)pPacket + 0x38) == '\0') {
        ExceptionList = &pvStack_1c;
        thisSkill = (CVOGHBBase*)(**(int(***)(std::uint32_t))(*(int*)pCasterObj + 0x234))(
            *(std::uint32_t*)((int)pPacket + 8));
        local_508 = thisSkill;
        if (thisSkill == nullptr) {
            Skill_EnsureLoadedInTree(pCasterObj, *(int*)((int)pPacket + 8), 0);
            thisSkill = (CVOGHBBase*)(**(int(***)(std::uint32_t))(*(int*)pCasterObj + 0x234))(
                *(std::uint32_t*)((int)pPacket + 8));
            local_508 = thisSkill;
            if (thisSkill == nullptr) {
                goto LAB_0051ae9e;
            }
            Skill_SetRankAndReevaluate(
                thisSkill,
                (void*)(((std::uint32_t)extraout_var << 16)
                        | *(std::uint16_t*)((int)pPacket + 0xc)),
                (short)unaff_EDI);
        } else {
            // Raw HB overlay (sizeof CVOGHBBase==0x28):
            //   this[9].nPeriodSentinel → +0x174
            //   &this[0x26].nRefOrFlags+2 → +0x5f6
            // Rank sum sealed High (CastSkillOnTarget / ApplyEffectsOnTarget).
            int left = (int)*(std::int16_t*)((int)thisSkill + 0x5f6)
                     + (int)*(std::int16_t*)((int)thisSkill + 0x174);
            if (left != (int)*(std::int16_t*)((int)pPacket + 0xc)) {
                Skill_SetRankAndReevaluate(
                    thisSkill,
                    (void*)(((std::uint32_t)((std::uintptr_t)thisSkill >> 16) << 16)
                            | (std::uint16_t)*(std::int16_t*)((int)pPacket + 0xc)),
                    (short)unaff_EDI);
            }
        }
    } else {
        ExceptionList = &pvStack_1c;
        thisSkill = (CVOGHBBase*)CVOGReaction_ResolveSkillTargets(
            *(void**)((int)pPacket + 8),
            (int)*(std::uint16_t*)((int)pPacket + 0xc));
        local_508 = thisSkill;
        (void)nInferred;
    }

    if (thisSkill != nullptr) {
        local_4fc = *(std::uint32_t*)((int)pPacket + 0x3c);
        local_4f8 = 0;

        if (*(char*)(*(int*)((int)pCasterObj + 0xa4) + 0x7e) != '\0') {
            puVar8 = local_4d0;
            uVar7 = 600;
            CVOGReaction_RandomUnitScalar(600, puVar8);
            local_4fc = FUN_0051b720(uVar7, puVar8);
            *(std::uint32_t*)((int)pPacket + 0x3c) = local_4fc;
        }

        if (*(char*)((int)pPacket + 0x38) == '\0') {
            // Active cast binding — 16B out-param
            Skill_LookupActiveCastBinding(&uStack_4f0, *(int*)((int)pPacket + 8));
            if (((uStack_4f0 & uStack_4ec) != 0xffffffff) || ((char)iStack_4e8 != '\0')) {
                local_4f8 = 0x11;
                iVar3 = CVOGReaction_ResolveObjectTarget(iStack_4e8, uStack_4f0, uStack_4ec);
                if (iVar3 != 0) {
                    // skill+0x5fc skillId (raw this[0x26].nPeriodSentinel)
                    FUN_00514e20(
                        *(int*)((int)thisSkill + 0x5fc),
                        *(std::uint32_t*)((int)pCasterObj + 0x160),
                        *(std::uint32_t*)((int)pCasterObj + 0x164),
                        *(std::uint32_t*)((int)pCasterObj + 0x168),
                        *(std::uint32_t*)((int)pCasterObj + 0x16c),
                        0);
                }
                Skill_ClearCastBindingAndMaybeRestartCd(
                    pCasterObj,
                    (void*)(std::uintptr_t)*(int*)((int)thisSkill + 0x5fc),
                    uStack_4f0,
                    uStack_4ec,
                    iStack_4e8,
                    cStack_4e4);
                if (*(char*)(*(int*)((int)pCasterObj + 0xa4) + 0x7e) == '\0') {
                    Skill_DecActiveCastCounter(pCasterObj); // FUN_00514e00
                }
                // Early cancel: binding TFID == packet first target OR skill+0x614 bit0
                // OR invalid packet target. (bit0 appears twice in raw || chain)
                if (((((uStack_4f0 == *(std::uint32_t*)((int)pPacket + 0x40))
                       && (uStack_4ec == *(std::uint32_t*)((int)pPacket + 0x44)))
                      && ((char)iStack_4e8 == *(char*)((int)pPacket + 0x48)))
                     || (((*(std::uint8_t*)((int)thisSkill + 0x614) & 1) != 0)
                         || (iVar3 = TFID_EqualsObjectId(
                                 (void*)((int)pPacket + 0x40), g_abTfidInvalid_9CDF88),
                             (char)iVar3 != '\0')))
                    || ((*(std::uint8_t*)((int)thisSkill + 0x614) & 1) != 0))
                {
                    ExceptionList = pvStack_1c;
                    return 0x11;
                }
            }
            if (*(char*)(*(int*)((int)pCasterObj + 0xa4) + 0x7e) != '\0') {
                // skill+0x61c == 0 → start cast-again (InitRuntime defer flag)
                if (*(char*)((int)thisSkill + 0x61c) == '\0') {
                    Skill_StartCastAgainHeartbeat(
                        pCasterObj,
                        thisSkill,
                        *(void**)((int)pPacket + 0x10),
                        unaff_EDI);
                }
                Skill_ClearActiveCastCounterAndQueueId(*(int*)((int)pPacket + 8));
            }
        } else {
            // Item skill: category @ +0x5e8; until = delay + cooldown@+0x10
            iVar3 = *(int*)((int)thisSkill + 0x5e8);
            Skill_InsertCategoryCooldown(
                iVar3,
                *(int*)((int)pPacket + 0x10) + *(int*)((int)thisSkill + 0x10));
        }

        // Position float3 from packet +0x18..+0x20
        uStack_4d8 = *(std::uint32_t*)((int)pPacket + 0x20);
        uStack_4dc = *(std::uint32_t*)((int)pPacket + 0x1c);
        uStack_4e0 = *(std::uint32_t*)((int)pPacket + 0x18);
        uStack_510 = (*(std::uint16_t*)((int)pPacket + 4) - 0x40) / 0x18;
        uStack_4d4 = 0;
        puStack_500 = (std::uint32_t*)operator_new__(uStack_510 << 4);
        if (uStack_510 != 0) {
            puVar4 = (std::uint32_t*)((int)pPacket + 0x40);
            puStack_4f4 = puStack_500;
            do {
                puVar2 = puStack_4f4 + 4;
                *puStack_4f4 = *puVar4;
                puStack_4f4[1] = puVar4[1];
                puStack_4f4[2] = puVar4[2];
                puVar1 = puVar4 + 3;
                puVar4 = puVar4 + 6; // 0x18 stride
                uStack_510 = uStack_510 - 1;
                puStack_4f4[3] = *puVar1;
                thisSkill = local_508;
                puStack_4f4 = puVar2;
            } while (uStack_510 != 0);
        }

        iVar3 = (**(int(***)())(*(int*)pCasterObj + 0x19c))();
        if (iVar3 == 0) {
            auStack_50c[0] = 0;
            if (*(char*)((int)pCasterObj + 0x25) != '\0') {
                CNDDoubleList_InvokePredicateAndRemove_Inferred(LAB_00512eb0, auStack_50c, 0);
            }
            iVar3 = *(int*)((int)pCasterObj + 0xac);
        } else {
            iVar6 = *(int*)(*(int*)(iVar3 + 4) + 4);
            auStack_504[0] = 0;
            if (*(char*)(iVar6 + 0x29 + iVar3) != '\0') {
                CNDDoubleList_InvokePredicateAndRemove_Inferred(LAB_00512eb0, auStack_504, 0);
            }
            iVar3 = *(int*)(iVar6 + iVar3 + 0xb0);
        }
        if (iVar3 != 0) {
            FUN_00514ff0(0);
        }

        if (*(int*)((int)pPacket + 0x10) < 1) {
            // skill thiscall; delay==0 path (server success often sends 0)
            Skill_ApplyEffectsOnTarget_Inferred(
                thisSkill,
                pCasterObj,
                *(void**)((int)pCasterObj + 0xa4),
                puStack_500,
                &uStack_4e0,
                local_4fc);
            if (((*(char*)((int)pPacket + 0x38) == '\0')
                 && (iVar3 = *(int*)((int)pCasterObj + 100), iVar3 != 0))
                && ((*(int*)(iVar3 + 0x10) != 0
                     && (iVar6 = *(int*)(iVar3 + 0x10) - 1,
                         *(int*)(iVar3 + 0x10) = iVar6,
                         iVar6 == 0))))
            {
                *(std::uint32_t*)(iVar3 + 0xc) = 0;
            }
        } else {
            if (bIsLocalCaster == '\0') {
                (**(void(***)(
                    int, std::uint32_t, int, int, int, int, int, int))(*(int*)pCasterObj + 0x238))(
                    3,
                    *(std::uint32_t*)((int)pPacket + 8),
                    (int)*(short*)((int)pPacket + 0xc),
                    *(int*)((int)pPacket + 0x10),
                    0,
                    0,
                    0,
                    0);
            }
            pvVar5 = operator_new(0x674);
            uStack_14 = 0;
            if (pvVar5 == nullptr) {
                local_508 = nullptr;
            } else {
                local_508 = (CVOGHBBase*)CVOGHBWakeupSkill_ctor(
                    pvVar5,
                    *(std::uint32_t*)((int)pPacket + 0x10),
                    pCasterObj,
                    thisSkill,
                    *(void**)((int)pCasterObj + 0xa4),
                    puStack_500,
                    &uStack_4e0,
                    local_4fc,
                    *(std::uint8_t*)((int)pPacket + 0x38));
            }
            uStack_14 = 0xffffffff;
            CVOGHBList_Enqueue(
                *(void**)(*(int*)((int)pCasterObj + 0xa4) + 0xe4ec),
                local_508);
            CVOGHBBase_Start(local_508);
        }

        operator_delete__(puStack_500);
        if (*(char*)((int)pPacket + 0x38) == '\0') {
            ExceptionList = pvStack_1c;
            return local_4f8;
        }
        // Raw warns "does not return" on operator_delete — treat as free of temp skill
        operator_delete(thisSkill);
    }

LAB_0051ae9e:
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    ExceptionList = pvStack_1c;
    return local_4f8;
}
