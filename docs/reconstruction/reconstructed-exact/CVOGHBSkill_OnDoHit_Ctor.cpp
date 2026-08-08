// =============================================================================
// CVOGHBSkill_OnDoHit_Ctor  (FUN_00621350)
// -----------------------------------------------------------------------------
// Stable ID: aa_00621350
// Address:   0x00621350  (autoassault.exe, image base 0x400000)
// Body:      0x00621350 – 0x00621383 inclusive (52 B / 0x34)
// System:    skills-abilities
// Generated: 2026-08-05 R11-017 OWN-ONLY dual (decompile_function + read_memory)
//
// Class:     CVOGHBSkill_OnDoHit  (RTTI Confirmed ".?AVCVOGHBSkill_OnDoHit@@")
// Vtbl:      PTR_FUN_009d15c4
// Parent:    CVOGHBSkillBase_ctor @ 0x005788d0
//
// Purpose: Construct an OnDoHit skill heartbeat action:
//   1) CVOGHBSkillBase_ctor(pSource, pSkillBlob, arg4, pTarget, pTfid16, arg7)
//   2) Install OnDoHit vtbl PTR_FUN_009d15c4
//   3) return this
// No extra fields beyond SkillBase — pure vtbl specialization.
//
// ABI:     __thiscall; 6 stack args; ret 0x18; EAX = this
// Exactness: Behavior-preserving CF (live decompile + read_memory).
// Bit-for-bit / runtime: OPEN.
// =============================================================================

#include <cstdint>

// Parent dual-sealed @ 0x005788d0 (RTTI CVOGHBSkillBase).
// Ghidra call site lists stack args only (thiscall ECX = this).
extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, std::uint32_t arg4,
    void *pTarget, void *pTfid16, std::uint32_t arg7);

// OnDoHit vtbl in .rdata
extern "C" void *PTR_FUN_009d15c4;

// Layout: identical to CVOGHBSkillBase for fields written here.
//   [0]  pVTable → PTR_FUN_009d15c4 after this ctor
//   remaining fields owned by CVOGHBSkillBase_ctor (blob @ +0x24, TFIDs, etc.)

extern "C" void *__thiscall CVOGHBSkill_OnDoHit_Ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, std::uint32_t arg4,
    void *pTarget, void *pTfid16, std::uint32_t arg7)
{
  auto *self = static_cast<std::uint32_t *>(thisHb);

  // ECX = thisHb; stack args match Ghidra FUN_00621350 call list
  CVOGHBSkillBase_ctor(thisHb, pSourceObj, pSkillBlob, arg4, pTarget, pTfid16,
                       arg7);

  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d15c4);
  return thisHb;
}

// Ghidra alias
extern "C" void *__thiscall FUN_00621350(void *thisHb, void *p2, void *p3,
                                         std::uint32_t p4, void *p5, void *p6,
                                         std::uint32_t p7)
{
  return CVOGHBSkill_OnDoHit_Ctor(thisHb, p2, p3, p4, p5, p6, p7);
}
