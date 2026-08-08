// =============================================================================
// CVOGHBSkill_Virus_Ctor  (FUN_0061f940)
// -----------------------------------------------------------------------------
// Stable ID: aa_0061f940
// Address:   0x0061f940  (autoassault.exe, image base 0x400000)
// Body:      0x0061f940 – 0x0061f998 inclusive (89 B / 0x59)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9D-B dual seal (decompile_function + read_memory)
//
// Class:     CVOGHBSkill_Virus  (RTTI Confirmed ".?AVCVOGHBSkill_Virus@@")
// Vtbl:      PTR_FUN_009d14bc (OnHeartBeat @ +0x0c = 0x0061fdf0)
// Size:      0x6e0 (operator_new from CVOGHBSkill_Virus_OnHeartBeat)
//
// Purpose: Construct a Virus skill heartbeat action:
//   1) Intermediate base ctor FUN_00618180(... , 0, 1.0f)  [thiscall ECX=this]
//   2) Store multi-spread budget @ +0x6d0
//   3) Install Virus vtbl
//   4) Store period seed @ +0x6d4; CVOGHBBase_SetPeriodAndCounter(period, true)
//
// ABI:     __thiscall; 8 stack args; ret 0x20; EAX = this
// Exactness: Behavior-preserving CF (live decompile + read_memory).
// Bit-for-bit / runtime: OPEN.
// =============================================================================

#include <cstdint>

// Intermediate base ctor is __thiscall (ECX = this). Ghidra call site lists
// only the stack args (param_2..param_7 of Virus ctor + 0 + 1.0f).
extern "C" void *__thiscall FUN_00618180(
    void *thisHb, void *p2, void *p3, void *p4, void *p5, void *p6,
    std::uint32_t p7, std::uint8_t flag0, float fOne);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *thisHb,
                                                          int period,
                                                          bool reset);

// Virus vtbl in .rdata
extern "C" void *PTR_FUN_009d14bc;

// Layout notes (dword indices):
//   [0]      pVTable → PTR_FUN_009d14bc after this ctor
//   [0x1b4]  +0x6d0  remain multi-spread budget (OnHeartBeat decrements)
//   [0x1b5]  +0x6d4  period seed

extern "C" void *__thiscall CVOGHBSkill_Virus_Ctor(
    void *thisHb, void *pPrimaryTarget, void *pSkillBlob, void *pWorld,
    void *pNewTarget, void *pTfidArg, std::uint32_t arg7, int remainBudget,
    int remainPeriod)
{
  auto *self = static_cast<std::uint32_t *>(thisHb);

  // ECX = thisHb; stack args match Ghidra FUN_0061f940 call list
  FUN_00618180(thisHb, pPrimaryTarget, pSkillBlob, pWorld, pNewTarget, pTfidArg,
               arg7, /*flag*/ 0, /*1.0f*/ 1.0f);

  self[0x1b4] = static_cast<std::uint32_t>(remainBudget); // +0x6d0
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d14bc);
  self[0x1b5] = static_cast<std::uint32_t>(remainPeriod); // +0x6d4
  CVOGHBBase_SetPeriodAndCounter(thisHb, remainPeriod, true);
  return thisHb;
}

// Ghidra alias
extern "C" void *__thiscall FUN_0061f940(
    void *thisHb, void *p2, void *p3, void *p4, void *p5, void *p6,
    std::uint32_t p7, int p8, int p9)
{
  return CVOGHBSkill_Virus_Ctor(thisHb, p2, p3, p4, p5, p6, p7, p8, p9);
}
