// =============================================================================
// CVOGHBSkill_OnHit_ctor  (was FUN_00617ad0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00617ad0
// Address:   0x00617ad0  (autoassault.exe, image base 0x400000)
// Body:      0x00617ad0 – 0x00617b33 inclusive (100 B / 0x64)
// System:    skills-abilities
// Generated: 2026-08-05 R11-012 dual seal
//
// Class:     CVOGHBSkill_OnHit
// RTTI:      COL@0x00aadbc4 → type_info@0x00af1d60 ".?AVCVOGHBSkill_OnHit@@"
// Vtbl:      PTR_FUN_009d0f1c
// Size:      0x6d0 (operator_new from OnHit-family factories)
//
// Purpose: Construct CVOGHBSkill_OnHit heartbeat action:
//   1) CVOGHBSkillBase_ctor (ValidateTarget notify=1; attach=target; period)
//   2) Install OnHit vtbl
//   3) Seed optional int @ +0x6c0 from skillBlob float @ +0x4c (truncate);
//      enable byte @ +0x6c4 = 1 iff float != 0, else 0
//
// ABI:     __thiscall; 6 stack args; ret 0x18; EAX = this
// Exactness: Behavior-preserving CF (live decompile + disassemble_function +
//            read_memory RTTI). Not modernization.
// Bit-for-bit / runtime: OPEN (Terminal false).
// Dual: reviews/A|B_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self,
    void* pSourceObj,
    void* pSkillBlob,
    std::uint32_t arg4,
    void* pTarget,
    std::uint32_t* pTfid,
    std::uint32_t arg7);

// OnHit vtbl in .rdata; COL immediately before at 0x009d0f18
extern "C" void* PTR_FUN_009d0f1c;
// float 0.0f @ 0x00a0f518
extern "C" float g_flZero;

// Layout (beyond CVOGHBSkillBase tail):
//   [0]      pVTable → PTR_FUN_009d0f1c after this ctor
//   +0x6c0   int seed from skillBlob float@+0x4c (written only when float != 0)
//   +0x6c4   uint8 enable (1 if float != 0 else 0)

extern "C" void* __thiscall CVOGHBSkill_OnHit_ctor(
    void* thisHb,
    void* pSourceObj,
    void* pSkillBlob,
    std::uint32_t arg4,
    void* pTarget,
    std::uint32_t* pTfid,
    std::uint32_t arg7)
{
  auto* self = static_cast<std::uint32_t*>(thisHb);

  // ECX = thisHb; stack formals match base skill-HB ctor
  CVOGHBSkillBase_ctor(thisHb, pSourceObj, pSkillBlob, arg4, pTarget, pTfid,
                       arg7);

  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d0f1c);

  // skillBlob+0x4c float → optional int seed
  float f = *reinterpret_cast<float*>(static_cast<char*>(pSkillBlob) + 0x4c);
  if (f != g_flZero) {
    *reinterpret_cast<std::uint8_t*>(static_cast<char*>(thisHb) + 0x6c4) = 1;
    // CVTTSS2SI: truncate toward zero (matches (int)f on this path)
    *reinterpret_cast<int*>(static_cast<char*>(thisHb) + 0x6c0) =
        static_cast<int>(f);
    return thisHb;
  }
  *reinterpret_cast<std::uint8_t*>(static_cast<char*>(thisHb) + 0x6c4) = 0;
  // +0x6c0 not written when float == 0
  return thisHb;
}

// Ghidra alias
extern "C" void* __thiscall FUN_00617ad0(
    void* thisHb,
    void* pSourceObj,
    void* pSkillBlob,
    std::uint32_t arg4,
    void* pTarget,
    std::uint32_t* pTfid,
    std::uint32_t arg7)
{
  return CVOGHBSkill_OnHit_ctor(thisHb, pSourceObj, pSkillBlob, arg4, pTarget,
                                pTfid, arg7);
}
