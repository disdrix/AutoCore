// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×18, return×12, goto×2, for×1.
//  - Notable callees: Skill_LocalCastValidate×2, FUN_005169c0, FUN_00518c20, Skill_GetCategoryCooldownRemaining, Skill_LocalRangeTargetCheck, Skill_LookupActiveCastBinding, TFID_NotEquals, eSkillResponses.
//  - Return sites: 12.

// =============================================================================
// Skill_LocalCastValidate
// -----------------------------------------------------------------------------
// Purpose:  Local pre-cast checks. Returns eSkillResponses (0 = ok).
//           Codes verified via Skill_FormatFailureMessage strings.
//
// Address:  0x0051a790  (autoassault.exe, image base 0x400000)
// Stable:   aa_0051a790
// System:   skills-abilities
//
// Convention: MSVC __thiscall (this in ECX = caster)
//
// Parameters (human; Ghidra stack *names* disagreed with body uses):
//   this           - caster entity
//   bSkipBusyCheck - when 0, run busy / alt-suppress gate (callers pass 0)
//   pSkill         - skill runtime; null = lightweight check only
//                    (Ghidra typed/named this slot wrong — body uses skill offsets)
//   pRangeExtra    - forwarded to Skill_LocalRangeTargetCheck (callers pass 0)
//
// Callers (RequestCast / QuickBar):
//   Skill_LocalCastValidate(casterEntity, 0, pSkillRuntime, 0)
//
// eSkillResponses (UX via Skill_FormatFailureMessage; residual 2026-07-29):
//   0 ok · 3 wrecked toast (plant/+0x6b4 gate) · 4 power · 5 status
//   6 busy · 7 recharge · 10 prevent · 11 must-hidden · 12 can't-while-hidden
//   else Skill_LocalRangeTargetCheck (13/14/15 downstream, not literals here)
//
// Ordered gates G0→G9 (early-exit; see reviews/a_0051a790.md):
//   suppress5 → vehicle plant3 → busy5/6 → null skill0 → free-bind deep:
//   power4 (only if plant+0x6b4 < 1) → cast/CD7 → prevent10 → hide12/11|range → 0
//   occupied bind skips deep → 0. Leave FUN_005169c0 / FUN_00518c20.
//
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Dual residual scratch: docs/reconstruction/reviews/a_0051a790.md
// =============================================================================

#include <cstdint>

extern "C" int  FUN_005169c0();
extern "C" int  FUN_00518c20();
extern "C" void Skill_LookupActiveCastBinding(void* outTfid16, int skillId);
extern "C" int  TFID_NotEquals(void* a, void* b);
extern "C" void Skill_GetCategoryCooldownRemaining(void* catMap, int one, char zero);
extern "C" int  Skill_LocalRangeTargetCheck(void* a, void* b, void* c, void* d);
extern "C" float g_flZero;
extern "C" std::uint8_t g_abTfidInvalid_9CDF88[];

// FPU result of Skill_GetCategoryCooldownRemaining (decomp float10 extraout_ST0).
// Opaque stand-in so the call-then-compare order is preserved in source form.
extern "C" long double g_extraout_ST0_SkillCdRemaining;

int __thiscall Skill_LocalCastValidate(
    void* thisCaster,
    void* bSkipBusyCheck,
    void* pSkill,
    void* pRangeExtra)
{
    // this+0xb4 bit 0x02 → suppressed (5)
    if ((*(std::uint8_t*)((int)thisCaster + 0xb4) & 2) != 0) {
        return 5;
    }

    char isVehicleLike = (**(char(***)())(*(int*)thisCaster + 0x198))();

    if (isVehicleLike != '\0') {
        int plant = (**(int(***)(int))(*(int*)thisCaster + 0x210))(0);
        if (plant == 0) {
            return 3;
        }
        plant = (**(int(***)(int))(*(int*)thisCaster + 0x210))(0);
        if (*(int*)(plant + 0x6b4) < 1) {
            return 3;
        }
    }

    // Busy gate when bSkipBusyCheck == 0
    if ((char)(std::uintptr_t)bSkipBusyCheck == '\0') {
        if (((*(std::uint8_t*)((int)thisCaster + 0xb4) & 8) != 0)
            && (*(int*)(*(int*)((int)thisCaster + 0xa8) + 0x38) == 0x14))
        {
            return 5;
        }

        int busyState = FUN_005169c0();
        if (*(int*)(busyState + 0x10) != 0) {
            return 6;
        }
    }

    // Skill-specific block (pSkill non-null).
    // Ghidra: slot named bSkipBusyCheck / typed char — body treats as skill*.
    if (pSkill != nullptr) {
        std::uint8_t activeBinding[16];
        std::uint8_t* invalidTfid = g_abTfidInvalid_9CDF88;

        Skill_LookupActiveCastBinding(activeBinding, *(int*)((int)pSkill + 0x5fc));

        // Decomp: TFID_NotEquals(pA=lookup_out_reg, pB=invalid)
        void* bindingOut = activeBinding;
        int notEq = TFID_NotEquals(bindingOut, invalidTfid);

        if ((char)notEq == '\0') {
            char cdZero = '\0';
            int plant = (**(int(***)())(*(int*)thisCaster + 0x210))();

            // plant+0x6b4 < 1 AND current power (plant+0x12c) < skill cost (+8) → 4
            if ((plant != 0)
                && (*(int*)(plant + 0x6b4) < 1)
                && (*(std::int16_t*)(plant + 300)
                    < *(std::int16_t*)((int)pSkill + 8)))
            {
                return 4;
            }

            // is-casting (+0x628) OR category CD remaining → 7
            if ((*(char*)((int)pSkill + 0x628) != '\0')
                || (Skill_GetCategoryCooldownRemaining(
                        *(void**)((int)pSkill + 0x5e8), 1, cdZero),
                    g_extraout_ST0_SkillCdRemaining != (long double)g_flZero))
            {
                return 7;
            }

            // no plant + active-skill map nonempty + skill+0x615 bit2 → 10 (prevent)
            if ((plant == 0)
                && ((*(int*)(FUN_00518c20() + 8) != 0)
                    && ((*(std::uint8_t*)((int)pSkill + 0x615) & 2) != 0)))
            {
                return 10;
            }

            int related = (**(int(***)())(*(int*)thisCaster + 0x19c))();

            if (related == 0) {
                if ((*(std::uint8_t*)((int)pSkill + 0x615) & 0x40) == 0) {
                    // LAB_0051a94e
                    return Skill_LocalRangeTargetCheck(
                        pSkill, thisCaster, pSkill, pRangeExtra);
                }
            } else {
                // hide/form flag at related-entity MSVC layout +0x29
                char formFlag =
                    *(char*)(*(int*)(*(int*)(related + 4) + 4) + 0x29 + related);

                if ((plant == 0) && (formFlag != '\0')) {
                    if ((*(std::uint32_t*)((int)pSkill + 0x614) & 0x4000) == 0) {
                        return 12; // can't while hidden
                    }
                } else if ((*(std::uint32_t*)((int)pSkill + 0x614) & 0x4000) == 0) {
                    // LAB_0051a94e
                    return Skill_LocalRangeTargetCheck(
                        pSkill, thisCaster, pSkill, pRangeExtra);
                }

                if (formFlag != '\0') {
                    // LAB_0051a94e
                    return Skill_LocalRangeTargetCheck(
                        pSkill, thisCaster, pSkill, pRangeExtra);
                }
            }

            return 11; // must be hidden
        }
    }

    return 0;
}
