// =============================================================================
// CVOGHBSkill_KillCharge_Ctor  (FUN_006223c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006223c0
// Address:   0x006223c0  (autoassault.exe, image base 0x400000)
// Body:      0x006223c0 – 0x006223f3 inclusive (52 B / 0x34)
// System:    skills-abilities
// Generated: 2026-08-05 R11-019 dual seal (decompile_function + read_memory)
//
// Class:     CVOGHBSkill_KillCharge  (RTTI Confirmed ".?AVCVOGHBSkill_KillCharge@@")
// Vtbl:      PTR_FUN_009d16e4  (COL @ 0x00aae2d8 → type_info @ 0x00af2b70)
// Size:      0x6c0 for pure KillCharge (peer factory FUN_006226a0 operator_new);
//            sole CALL site FUN_00622f70 allocates 0x6d0 then overrides vtbl to
//            CVOGHBSkill_CommonCastOnDeath (PTR_FUN_009d1744) — subclass path.
//
// Purpose: Construct a KillCharge skill heartbeat action:
//   1) CVOGHBSkillBase_ctor(this, 6 stack args)   [thiscall ECX=this]
//   2) Install KillCharge vtbl PTR_FUN_009d16e4
//   3) Return this
//
// ABI:     __thiscall; 6 stack args; ret 0x18; EAX = this
// Exactness: Behavior-preserving CF (live decompile + read_memory).
// Bit-for-bit / runtime: OPEN.
// =============================================================================

#include <cstdint>

// Parent skill HB base (RTTI Confirmed CVOGHBSkillBase @ 0x005788d0).
// Signature matches partition parent dual; six stack args after this.
extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *pCaster, void *pSkillBlob, void *pWorldOrCtx,
    void *pTarget, void *pTfidBlob, std::uint32_t arg7);

// KillCharge vtbl in .rdata
extern "C" void *PTR_FUN_009d16e4;

// Layout notes:
//   [0]  pVTable → PTR_FUN_009d16e4 after this ctor (may be overwritten by subclass)
//   remaining fields initialized exclusively inside CVOGHBSkillBase_ctor

extern "C" void *__thiscall CVOGHBSkill_KillCharge_Ctor(
    void *thisHb, void *pCaster, void *pSkillBlob, void *pWorldOrCtx,
    void *pTarget, void *pTfidBlob, std::uint32_t arg7)
{
  // ECX = thisHb; stack args forwarded 1:1 into base
  CVOGHBSkillBase_ctor(thisHb, pCaster, pSkillBlob, pWorldOrCtx, pTarget,
                       pTfidBlob, arg7);

  *static_cast<void **>(thisHb) = &PTR_FUN_009d16e4;
  return thisHb;
}

// Ghidra alias
extern "C" void *__thiscall FUN_006223c0(
    void *thisHb, void *p2, void *p3, void *p4, void *p5, void *p6,
    std::uint32_t p7)
{
  return CVOGHBSkill_KillCharge_Ctor(thisHb, p2, p3, p4, p5, p6, p7);
}
