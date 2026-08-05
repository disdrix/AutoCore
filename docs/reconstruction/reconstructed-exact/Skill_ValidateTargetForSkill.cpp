// READABILITY (human CF notes):
//  - Body size: small wrapper (~0x60 bytes).
//  - Stages: handler vtbl+0x44 gate → optional HB list walk on target+0xB0.
//  - Callees: skill handler vtbl+0x44; CNDDoubleList_InvokePredicateAndRemove_Inferred; Skill_ValidateTarget_HBSkillListener.
//  - Return: AL 1=valid, 0=rejected (Confirmed 7/7 callers: TEST AL / (char)!=0).
//  - Callers: CVOGHBSkillBase_ctor (notify=1); CVOGReaction_Dispatch case 0xC (x2);
//             NPC_TryCastSkillFromSet; Outpost_CastSkillsForFaction; Outpost_CastSkillsForBeaconShare (x2).
//  - Does NOT write ResolveTargetList outFlags (orthogonal bool gate).
//  - Dual A/B: accept 2026-07-29 residual (assembly-backed).

// =============================================================================
// Skill_ValidateTargetForSkill
// -----------------------------------------------------------------------------
// Purpose:  Target legality gate for a skill runtime. Calls the skill handler
//           object at skill+0x5F0, vtable +0x44, with (target, skill, 0).
//           If the handler returns 1, reject (AL=0). Otherwise walk the target's
//           HB list (target+0xB0) via CNDDoubleList_InvokePredicateAndRemove_Inferred
//           + Skill_ValidateTarget_HBSkillListener, which may re-probe the handler
//           with an attached CVOGHBSkillBase and clear or keep the accept byte.
//
// Address:  0x00553650  (autoassault.exe, image base 0x400000)
// Stable:   aa_00553650
// System:   skills-abilities
//
// Convention: MSVC __thiscall (this = skill runtime in ECX); RET 8
//
// Parameters:
//   this              skill runtime (handler ptr at +0x5F0)
//   pTargetObj        target entity/object to validate
//   bNotifyHBFlag     low byte packed into listener ctx (+9); 0 or 1 at sites
//
// Returns: 1 if valid/accept, 0 if rejected (low AL).
//
// Handler vtbl+0x44 codes (as used by this unit + listener):
//   1 = reject
//   2 = accept (listener may call hb->vtbl+0x18(1,0) when flag set)
//
// Exactness: Assembly-corrected behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

// List walk / match-remove under critical section (this = list manager).
// Named 2026-07-29: CNDDoubleList family RTTI; method _Inferred.
extern "C" void __thiscall CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void* thisListMgr,
    void* predicateFn,
    void* matchCtx,
    int   flag);

// Predicate @ 0x005532E0 — RTTI CVOGHBSkillBase + string
// "Skill found with no base class: %d"
extern "C" std::uint32_t Skill_ValidateTarget_HBSkillListener(
    void* listNodeObj,
    void* validateCtx,
    char* continueFlag);

struct ValidateTargetCtx {
    void*         pTarget;     // +0
    void*         pSkill;      // +4
    std::uint8_t  result;      // +8  1=accept default; listener may set 0
    std::uint8_t  notifyHB;    // +9  from bNotifyHBFlag low byte
    // padding / further bytes as stack layout allows
};

int __thiscall Skill_ValidateTargetForSkill(
    void* thisSkill,
    void* pTargetObj,
    void* bNotifyHBFlag)
{
    // handler = *(thisSkill + 0x5F0)
    void** handler = *reinterpret_cast<void***>(
        reinterpret_cast<char*>(thisSkill) + 0x5F0);
    void** vtbl = *reinterpret_cast<void***>(handler);

    // handler->vtbl+0x44(pTargetObj, thisSkill, 0)
    using HandlerFn = int(__thiscall*)(void* self, void* target, void* skill, void* hbOrZero);
    // Note: Ghidra often drops the implicit this; call is virtual via [vtbl+0x44]
    // with three stack args after ECX=handler (MSVC member-function thiscall).
    auto fn = *reinterpret_cast<int(__stdcall**)(void*, void*, void*)>(
        reinterpret_cast<char*>(vtbl) + 0x44);

    // Virtual call sequence matches asm: ECX=handler, push 0, push skill, push target
    int handlerResult;
    {
        // Represent as: CALL [vtbl+0x44] with (target, skill, 0)
        using VCall = int(__thiscall*)(void* handlerThis, void* target, void* skill, void* zero);
        handlerResult = reinterpret_cast<VCall>(fn)(handler, pTargetObj, thisSkill, nullptr);
    }

    if (handlerResult == 1) {
        return 0; // reject
    }

    ValidateTargetCtx ctx{};
    ctx.pTarget  = pTargetObj;
    ctx.pSkill   = thisSkill;
    ctx.result   = 1;
    ctx.notifyHB = static_cast<std::uint8_t>(
        reinterpret_cast<std::uintptr_t>(bNotifyHBFlag) & 0xFF);

    void* listMgr = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(pTargetObj) + 0xB0);

    CNDDoubleList_InvokePredicateAndRemove_Inferred(
        listMgr,
        reinterpret_cast<void*>(&Skill_ValidateTarget_HBSkillListener),
        &ctx,
        0);

    return static_cast<int>(ctx.result);
}
