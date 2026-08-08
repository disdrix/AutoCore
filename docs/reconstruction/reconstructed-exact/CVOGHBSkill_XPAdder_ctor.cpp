// =============================================================================
// CVOGHBSkill_XPAdder_ctor  (was FUN_00650f50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00650f50
// Address:   0x00650f50 – 0x00650f8e  (autoassault.exe, image base 0x400000)
// Body size: 63 bytes (0x3F), inclusive of ret 0x18
// System:    skills-abilities / CVOGHB skill heartbeat
// Generated: 2026-07-23 scaffold as FUN_00650f50; R11-025 OWN dual A/B seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disassemble_function + read_memory.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Class:     CVOGHBSkill_XPAdder (RTTI Confirmed ".?AVCVOGHBSkill_XPAdder@@" @ 0x00af5178)
// Vtbl:      PTR_FUN_009e5304 (install at +0x00 after base)
// Size:      0x6d0 (operator_new at sole caller FUN_0061c940)
// =============================================================================
//
// PURPOSE
//   Subclass constructor for XP-adder skill heartbeat:
//     1. CVOGHBSkillBase_ctor — base skill HB fields, ValidateTarget, attach, period
//     2. Install subclass vtbl PTR_FUN_009e5304 (CVOGHBSkill_XPAdder)
//     3. Zero float residual at this+0x6c0 (MOVSS from xorps xmm0)
//
// ABI (retail)
//   __thiscall  this in ECX (pre-allocated object size 0x6d0)
//   stack: (pSourceObj, pSkillBlob, arg4, pTarget, pTfid16, arg7)  → ret 0x18
//   return: this* in EAX
//
// SOLE CALLER
//   FUN_0061c940 @ 0x0061c9f3 / 0x0061ca93
//     operator_new(0x6d0) → this ctor → Enqueue/Start or vtbl delete-on-reject
//
// PEER Vtbl slots (not dualled here; evidence only)
//   +0x00  FUN_00651190  scalar deleting dtor
//   +0x04  FUN_00650f90  tick — accumulates XP into character+0xc54 via this+0x6c0
//   +0x14  FUN_006510b0  on-end — subtracts this+0x6c0 from character+0xc54
//

#include <cstdint>

// Base ctor (sealed elsewhere as CVOGHBSkillBase_ctor / aa_005788d0)
extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self /*ECX*/,
    void* pSourceObj,
    void* pSkillBlob,
    uint32_t arg4,
    void* pTarget,
    void* pTfid16,
    uint32_t arg7);

// Image data (subclass vtbl)
extern "C" void* PTR_FUN_009e5304[];

// Clean plate
void* /*CVOGHBSkill_XPAdder**/ __thiscall CVOGHBSkill_XPAdder_ctor(
    void* self /*ECX*/,
    void* pSourceObj /*stack+4*/,
    void* pSkillBlob,
    uint32_t arg4,
    void* pTarget,
    void* pTfid16,
    uint32_t arg7)
{
  CVOGHBSkillBase_ctor(self, pSourceObj, pSkillBlob, arg4, pTarget, pTfid16, arg7);

  // C7 06 04 53 9E 00
  *reinterpret_cast<void**>(self) = &PTR_FUN_009e5304[0];

  // F3 0F 11 86 C0 06 00 00  — MOVSS [this+0x6c0], 0.0f  (after XORPS XMM0,XMM0)
  *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(self) + 0x6c0) = 0.0f;

  return self;
}

// Legacy Ghidra name — see FUN_00650f50.cpp twin
// undefined4* FUN_00650f50(...); // matches thiscall + ret 0x18
