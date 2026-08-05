// READABILITY (human CF notes):
//  - Body ~0xA5 bytes; stdcall RET 0x0C.
//  - Stages: type tag → RTTI cast → +0x20 gate → handler re-probe → result/stop/remove.
//  - Sole consumer: Skill_ValidateTargetForSkill list walk on target+0xB0.
//  - Type tag +0x1c==1 sealed with CVOGHBSkillBase_ctor.
//  - RTTI: CVOGHBBase (0x00af8d98) → CVOGHBSkillBase (0x00af8cec).
//  - Dual A/B: accept 2026-07-29 (three-rep: decompile / force_decompile / raw bytes).

// =============================================================================
// Skill_ValidateTarget_HBSkillListener
// -----------------------------------------------------------------------------
// Purpose:  CNDDoubleList match predicate for ValidateTarget. Considers only
//           skill-base HBs (type tag +0x1c == 1, RTTI CVOGHBSkillBase, +0x20==0).
//           Re-calls skill handler skill+0x5F0 vtbl+0x44(target, skill, hb):
//             1 → ctx.result=0, stop walk, keep node
//             2 → ctx.result=1, stop walk; if notifyHB: hb.vtbl+0x18(1,0), remove
//
// Address:  0x005532e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005532e0
// System:   skills-abilities
//
// Convention: MSVC __stdcall; RET 0x0C
//
// Parameters:
//   hbPayload   list node payload (CVOGHBBase* expected when tag==1)
//   ctx         ValidateTargetCtx {pTarget+0, pSkill+4, result+8, notifyHB+9}
//   stopFlag    out: set to 1 to halt list walk
//
// Returns: AL 0 = keep node; 1 = unlink+destroy node (list util)
//
// Exactness: Assembly-corrected behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

struct ValidateTargetCtx {
    void*        pTarget;   // +0
    void*        pSkill;    // +4
    std::uint8_t result;    // +8
    std::uint8_t notifyHB;  // +9
};

// MSVC RTTI dynamic_cast helper (binary import/helper).
extern "C" void* __cdecl __RTDynamicCast(
    void* inptr,
    long  VfDelta,
    void* srcType,
    void* targetType,
    int   isReference);

// Log helper.
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// type_info objects (RTTI Type Descriptors) — sealed addresses
extern "C" void* CVOGHBBase_RTTI_Type_Descriptor;       // 0x00af8d98 ".?AVCVOGHBBase@@"
extern "C" void* CVOGHBSkillBase_RTTI_Type_Descriptor;  // 0x00af8cec ".?AVCVOGHBSkillBase@@"

extern "C" std::uint8_t __stdcall Skill_ValidateTarget_HBSkillListener(
    void* hbPayload,
    ValidateTargetCtx* ctx,
    char* stopFlag)
{
    // Gate: HB type tag must be skill-base (1). Written by CVOGHBSkillBase_ctor.
    if (*reinterpret_cast<std::int32_t*>(
            reinterpret_cast<char*>(hbPayload) + 0x1c) != 1) {
        return 0;
    }

    // dynamic_cast<CVOGHBSkillBase*>(static_cast<CVOGHBBase*>(hbPayload))
    void* hb = __RTDynamicCast(
        hbPayload,
        /*VfDelta=*/0,
        &CVOGHBBase_RTTI_Type_Descriptor,
        &CVOGHBSkillBase_RTTI_Type_Descriptor,
        /*isReference=*/0);
    // Binary has no null check; tag==1 expected to make cast succeed.

    // Skip when base +0x20 (cStopped / skip flag) nonzero
    if (*reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<char*>(hb) + 0x20) != 0) {
        return 0;
    }

    void* skill = ctx->pSkill;
    void** handler = *reinterpret_cast<void***>(
        reinterpret_cast<char*>(skill) + 0x5F0);

    if (handler == nullptr) {
        // skill id at HB +0x620 (dword index 0x188)
        int skillId = *reinterpret_cast<int*>(
            reinterpret_cast<char*>(hb) + 0x620);
        FUN_007a4480(1, "Skill found with no base class: %d", skillId);
        return 0;
    }

    // handler->vtbl+0x44(target, skill, hb); ECX = handler
    void** hVtbl = *reinterpret_cast<void***>(handler);
    using HandlerProbe = int(__thiscall*)(void* self, void* target, void* sk, void* hbObj);
    auto probe = *reinterpret_cast<HandlerProbe*>(
        reinterpret_cast<char*>(hVtbl) + 0x44);
    int rc = probe(handler, ctx->pTarget, skill, hb);

    if (rc == 1) {
        ctx->result = 0;
        *stopFlag = 1;
        return 0; // stop; keep node
    }

    if (rc == 2) {
        ctx->result = 1;
        *stopFlag = 1;
        if (ctx->notifyHB != 0) {
            // hb->vtbl+0x18(1, 0); ECX = hb
            void** hbVtbl = *reinterpret_cast<void***>(hb);
            using HbNotify = void(__thiscall*)(void* self, int a, int b);
            auto notify = *reinterpret_cast<HbNotify*>(
                reinterpret_cast<char*>(hbVtbl) + 0x18);
            notify(hb, 1, 0);
            return 1; // stop; remove node
        }
        return 0; // stop already; keep node
    }

    return 0;
}
