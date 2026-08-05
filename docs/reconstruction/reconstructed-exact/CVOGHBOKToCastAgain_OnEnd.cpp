// READABILITY (auto CF):
//  - Body size: tiny (gate + optional flag clear + empty tail).
//  - Control keywords: if×1.
//  - Notable callees: Skill_SetIsCastingFlag, FUN_005081f0 (empty ret).
//  - Return sites: 1 (via tail jmp).

// =============================================================================
// CVOGHBOKToCastAgain_OnEnd
// -----------------------------------------------------------------------------
// Purpose:  Type-8 OK-to-cast-again HB end (vtbl+0x14): clear skill casting flag
//           when duration expires / HB is removed or aborted.
//
// Address:  0x0051e3b0  (autoassault.exe, image base 0x400000)
// Body:     0x0051e3b0 – 0x0051e3ca
// Stable:   aa_0051e3b0
// System:   skills-abilities
//
// Companion: OnStart 0x0051e390 (sets flag 1 + StampLastFireTime);
//            ctor 0x0051e240 (duration, category map insert, type 8, skill@+0x24).
//
// Exactness: CF sealed from machine bytes 2026-07-29 (reviews/a_0051e3b0.md).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23; residual strengthen 2026-07-29
// =============================================================================

/* CVOGHBOKToCastAgain_OnEnd (HB complete/abort, vtbl+0x14)
   If owner object attached (HB+0x18): Skill_SetIsCastingFlag(skill@HB+0x24, 0).
   Tail-jumps FUN_005081f0 — shared empty thiscall stub (single-byte RET).
   Does NOT erase category cooldown map (ctor insert may outlive this HB). */

// FUN_005081f0 @ 0x005081f0: bytes { C3 } — no-op; keep symbol until product name known.
extern "C" void __thiscall FUN_005081f0(void* /*thisHb*/);

// Skill_SetIsCastingFlag @ 0x005502d0: __thiscall(skill, char bIsCasting) RET 4
// false → skill+0x628 = 0 only (no +0x170/+0x178 clear).
extern "C" void __thiscall Skill_SetIsCastingFlag(void* pSkill, char bIsCasting);

void __thiscall CVOGHBOKToCastAgain_OnEnd(void* pHeartbeat)
{
    // Gate: CVOGHBBase owner object slot (AttachOwnerObject), not skill.
    if (*(int*)((char*)pHeartbeat + 0x18) != 0) {
        void* pSkill = *(void**)((char*)pHeartbeat + 0x24);
        Skill_SetIsCastingFlag(pSkill, /*bIsCasting=*/0);
    }
    // Machine: mov ecx, this; jmp FUN_005081f0
    FUN_005081f0(pHeartbeat);
}
