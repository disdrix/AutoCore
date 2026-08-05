// READABILITY (auto CF):
//  - Body size: short worker; SEH + alloc + ctor + enqueue + start.
//  - Control keywords: if×1, return×1.
//  - Notable callees: operator_new, CVOGHBOKToCastAgain_ctor, CVOGHBList_Enqueue, CVOGHBBase_Start.
//  - Return sites: 1.

// =============================================================================
// Skill_StartCastAgainHeartbeat
// -----------------------------------------------------------------------------
// Purpose:  Allocate CVOGHBOKToCastAgain (type-8 HB, size 0x28), construct with
//           owner entity + skill runtime + charge delay, enqueue on world HB
//           list, and Start. Optimistic cooldown / cast-again overlay path.
//
// Address:  0x00519200  (autoassault.exe, image base 0x400000)
// Stable:   aa_00519200
// System:   skills-abilities
//
// Convention: MSVC __thiscall — epilogue RET 0x8 (exactly two stack dwords).
//
// Asm-sealed signature (2026-07-29 dual quality refresh):
//   ECX     pOwnerEntity   character/owner entity; this+0xa4 → world
//   stack0  pSkillRuntime  skill runtime (ctor skill / HB+0x24)
//   stack1  nChargeDelayMs charge delay ms (often skill+0x14; restart path 0)
//
// Ghidra plate names (pOwnerCtx, pSkill, nChargeDelayMs) as three stack formals
// are FALSIFIED: RET 0x8; names inverted vs body. Decomp ctor call also dropped
// the skill stack arg — ctor is RET 0xC (three stack args).
//
// Algorithm (asm ≡ CF):
//   operator_new(0x28)
//   → CVOGHBOKToCastAgain_ctor(new, owner, skill, chargeMs)  // type +0x1c = 8
//   → CVOGHBList_Enqueue(*( *(owner+0xa4) + 0xe4ec ), hb)
//   → CVOGHBBase_Start(hb)
//
// Duration formula / category map insert: CVOGHBOKToCastAgain_ctor only.
// Stacking: this unit always allocs — no in-body dedup.
//
// Callers — complete xref set (6); gates are caller-owned:
//   Client_RequestCastSkill @00941731 — charge skill+0x14; +0x61c==0
//   Client_QuickBarActivateSkillSlot @00921cfd — charge skill+0x14; +0x61c==0
//   Client_StanceOrGadgetActivatePath @0093a525 — charge skill+0x14; +0x61c==0
//   Skill_ClearCastBindingAndMaybeRestartCd @0051a77c — charge 0; +0x61c!=0
//   Skill_ApplyStatusEffectLocal @0051ac53 — charge packet+0x10; world+0x7e!=0
//   Skill_LocalRangeTargetCheck @005531ac — charge skill+0x10; accuracy-miss → 0x0f
//
// Null operator_new: retail still Enqueue(list,0) + Start(0).
//
// Exactness: Behavior-preserving; signature corrected from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Dual residual strengthen: 2026-07-29 (scratch reviews/a_00519200.md)
// =============================================================================

#include <cstdint>

struct CVOGHBBase;

extern "C" void* ExceptionList;
extern "C" void* LAB_009a3651;
extern "C" void* operator_new(std::uint32_t);
// Ctor: thiscall + RET 0xC (owner, skill, chargeMs)
extern "C" CVOGHBBase* CVOGHBOKToCastAgain_ctor(
    void* mem,
    void* pOwnerEntity,
    void* pSkillRuntime,
    int nChargeDelayMs);
extern "C" void CVOGHBList_Enqueue(void* list, CVOGHBBase* hb);
extern "C" void CVOGHBBase_Start(CVOGHBBase* hb);

void __thiscall Skill_StartCastAgainHeartbeat(
    void* pOwnerEntity,    // ECX: owner entity; +0xa4 → world
    void* pSkillRuntime,   // stack0: skill runtime
    int nChargeDelayMs)    // stack1: charge delay ms
{
    void* mem;
    CVOGHBBase* pAction;
    void* sehPrev;
    std::uint8_t* sehHandler;
    std::uint32_t sehState;

    sehState = 0xffffffff;
    sehHandler = (std::uint8_t*)LAB_009a3651;
    sehPrev = ExceptionList;
    ExceptionList = &sehPrev;

    mem = operator_new(0x28);
    pAction = nullptr;
    sehState = 0;
    if (mem != nullptr) {
        // Asm: push charge; push skill; push owner; ECX=mem; call ctor (RET 0xC)
        pAction = CVOGHBOKToCastAgain_ctor(
            mem, pOwnerEntity, pSkillRuntime, nChargeDelayMs);
    }
    sehState = 0xffffffff;

    // world HB list at *(owner+0xa4)+0xe4ec
    CVOGHBList_Enqueue(
        *(void**)(*(int*)((int)pOwnerEntity + 0xa4) + 0xe4ec),
        pAction);
    CVOGHBBase_Start(pAction);

    ExceptionList = sehPrev;
    (void)sehHandler;
    (void)sehState;
}
