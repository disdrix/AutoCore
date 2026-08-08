// =============================================================================
// FUN_005787a0  (scaffold twin → Skill_HB_RescheduleStatus_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005787a0
// Address:   0x005787a0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Canonical: Skill_HB_RescheduleStatus_Inferred
// Generated: 2026-08-05 MEGA-004 (retires 2026-07-23 auto scaffold)
// Exactness: Behavior-preserving; ABI corrected from assembly (thiscall RET 4).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Full plate + CF: Skill_HB_RescheduleStatus_Inferred.cpp
// This twin keeps the address-keyed FUN_* filename for tooling.

#include <cstdint>

extern "C" void *__thiscall CVOGReaction_ResolveObjectTarget(
    void *reactionCtx, std::uint8_t tfidFlags, std::uint32_t tfidLo, std::uint32_t tfidHi);
extern "C" void *__cdecl __RTDynamicCast(
    void *obj, std::int32_t vfDelta, void *fromType, void *toType, std::int32_t isReference);
extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(void *pThis, std::uint32_t *pOut);

extern void *CVOGClonedObjectBase_RTTI; // 0x00af8e10
extern void *CVOGCreature_RTTI;         // 0x00af8d0c
extern std::uint32_t DAT_00af31e8;      // = 0x10

using VMethod0 = void(__thiscall *)(void *);
using VMethod1s = void(__thiscall *)(void *, std::int16_t);

// ABI: __thiscall; ECX=this; stack pOutStatus; EAX=pOutStatus; RET 4.
// Body 0x005787a0–0x0057882d (142 B).
std::uint32_t *__thiscall FUN_005787a0(void *self, std::uint32_t *pOutStatus)
{
  auto *base = static_cast<std::uint8_t *>(self);
  const std::int16_t required = *reinterpret_cast<std::int16_t *>(base + 0x2e);

  if (required != 0) {
    void *manager = *reinterpret_cast<void **>(base + 0x688);
    void *ctx = *reinterpret_cast<void **>(static_cast<std::uint8_t *>(manager) + 0xe4e8);
    void *obj = CVOGReaction_ResolveObjectTarget(
        ctx,
        *reinterpret_cast<std::uint8_t *>(base + 0x660),
        *reinterpret_cast<std::uint32_t *>(base + 0x658),
        *reinterpret_cast<std::uint32_t *>(base + 0x65c));
    void *creature = __RTDynamicCast(obj, 0, CVOGClonedObjectBase_RTTI, CVOGCreature_RTTI, 0);

    if (creature == nullptr ||
        *reinterpret_cast<std::int16_t *>(static_cast<std::uint8_t *>(creature) + 0x12c) < required) {
      (*reinterpret_cast<VMethod0 **>(self))[0x40 / 4](self);
      *pOutStatus = DAT_00af31e8; // 0x10
      return pOutStatus;
    }
    (*reinterpret_cast<VMethod1s **>(creature))[0xb0 / 4](creature, required);
  }

  CVOGHBBase_RescheduleAfterFire(self, pOutStatus);
  return pOutStatus;
}
