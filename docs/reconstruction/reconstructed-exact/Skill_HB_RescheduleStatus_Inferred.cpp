// =============================================================================
// Skill_HB_RescheduleStatus_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005787a0
// Address:   0x005787a0 – 0x0057882d inclusive (142 B / 0x8E)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities
// Ghidra:    FUN_005787a0
// Generated: 2026-08-05 MEGA-004 dual seal (live decompile + assembly)
// Exactness: Behavior-preserving rewrite of assembly CF. Not modernization.
// Bit-for-bit / runtime / differential: OPEN (no Launcher; terminal false).
// =============================================================================
//
// PURPOSE
//   Shared skill-HB helper used as:
//     1) First step of CVOGHBSkill_SharedOnHeartBeat_Inferred (0x0061b6f0):
//        optional creature status gate + apply, then reschedule next delay.
//     2) Standalone OnHB body / vtbl method for thinner skill HB classes.
//
//   When short@this+0x2e != 0:
//     Resolve target TFID (+0x658/+0x65c/+0x660) via reaction ctx
//     [*(this+0x688)+0xe4e8], dynamic_cast to CVOGCreature.
//     If null or creature.short@+0x12c < required:
//       this->vtbl+0x40() (stop/cancel); *pOut = DAT_00af31e8 (0x10); return.
//     Else creature->vtbl+0xb0(required).
//   Always (non-fail): CVOGHBBase_RescheduleAfterFire(this, pOut).
//
// ABI (assembly-sealed)
//   __thiscall: ECX = this; stack uint32_t *pOutStatus; EAX = pOutStatus; RET 4.
//   Decompiler __fastcall + phantom EDX param is WRONG — ignore.
//
// Parent gate: SharedOnHB skips effect cascade when *pOut == DAT_00af4bd0 (0x10).
// =============================================================================

#include <cstdint>

struct TypeDescriptor; // MSVC RTTI

// External symbols (image)
extern "C" void *__thiscall CVOGReaction_ResolveObjectTarget(
    void *reactionCtx, std::uint8_t tfidFlags, std::uint32_t tfidLo, std::uint32_t tfidHi);
extern "C" void *__cdecl __RTDynamicCast(
    void *obj, std::int32_t vfDelta, TypeDescriptor *fromType,
    TypeDescriptor *toType, std::int32_t isReference);
extern "C" void __fastcall CVOGHBBase_RescheduleAfterFire(
    void *pThis, std::uint32_t * /*unused_edx_phantom*/, std::uint32_t *pOutNextDelayMs);
// True ABI for RescheduleAfterFire is thiscall(ECX, stack pOut); Ghidra may show fastcall.

extern TypeDescriptor CVOGClonedObjectBase_RTTI; // 0x00af8e10  .?AVCVOGClonedObjectBase@@
extern TypeDescriptor CVOGCreature_RTTI;         // 0x00af8d0c  .?AVCVOGCreature@@
extern std::uint32_t DAT_00af31e8;               // fail status dword = 0x10

// Vtable helpers (offsets sealed; method English open)
using VMethod0 = void(__thiscall *)(void *self);
using VMethod1s = void(__thiscall *)(void *self, std::int16_t arg);

std::uint32_t *__thiscall Skill_HB_RescheduleStatus_Inferred(
    void *self, std::uint32_t *pOutStatus)
{
  auto *base = static_cast<std::uint8_t *>(self);
  const std::int16_t required = *reinterpret_cast<std::int16_t *>(base + 0x2e);

  if (required != 0) {
    void *manager = *reinterpret_cast<void **>(base + 0x688);
    void *reactionCtx = *reinterpret_cast<void **>(static_cast<std::uint8_t *>(manager) + 0xe4e8);
    const std::uint32_t tfidLo = *reinterpret_cast<std::uint32_t *>(base + 0x658);
    const std::uint32_t tfidHi = *reinterpret_cast<std::uint32_t *>(base + 0x65c);
    const std::uint8_t tfidFlags = *reinterpret_cast<std::uint8_t *>(base + 0x660);

    void *obj = CVOGReaction_ResolveObjectTarget(reactionCtx, tfidFlags, tfidLo, tfidHi);
    void *creature = __RTDynamicCast(
        obj, 0, &CVOGClonedObjectBase_RTTI, &CVOGCreature_RTTI, 0);

    if (creature == nullptr ||
        *reinterpret_cast<std::int16_t *>(static_cast<std::uint8_t *>(creature) + 0x12c) <
            required) {
      // Fail: stop/cancel this HB, write 0x10 status, do NOT reschedule via AfterFire.
      auto **vtbl = *reinterpret_cast<VMethod0 **>(self);
      vtbl[0x40 / 4](self);
      *pOutStatus = DAT_00af31e8; // 0x10
      return pOutStatus;
    }

    // Apply/set status on creature (vtbl+0xb0).
    auto **cvt = *reinterpret_cast<VMethod1s **>(creature);
    cvt[0xb0 / 4](creature, required);
  }

  // Success / no-status path: write next delay (0 continue or 16 default period).
  CVOGHBBase_RescheduleAfterFire(self, nullptr, pOutStatus);
  return pOutStatus;
}

// Scaffold alias retained for address-keyed tooling.
std::uint32_t *__thiscall FUN_005787a0(void *self, std::uint32_t *pOutStatus)
{
  return Skill_HB_RescheduleStatus_Inferred(self, pOutStatus);
}
