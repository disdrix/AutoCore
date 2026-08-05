// =============================================================================
// CVOGHBMissionPatrol_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00650d30
// Address:   0x00650d30  (autoassault.exe, image base 0x400000)
// Body:      0x00650d30–0x00650dd4 (164 bytes); ret 8
// System:    missions-progression / mission-patrol HB
// Generated: 2026-07-29 W23-T dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   In-place construct a 0x40-byte mission-patrol heartbeat on a pre-allocated
//   buffer (parent: CVOGObjectiveRequirement_Patrol_InitActive allocates, then
//   enqueues on continent HB list and Start).
//
// ALGORITHM:
//   1. CVOGHBBase_ctor(this)
//   2. Install MissionPatrol vftable PTR_FUN_009e52e4
//   3. Copy requirement-derived fields (vtbl+0x58, nested +0x10, dword pair, field 7)
//   4. Type token this+0x1C = 0xC
//   5. SetPeriodAndCounter(this, -1000, true)  // +0x0C and +0x10
//   6. MI-adjust optional owner complete-object pointer; AttachOwnerObject
//   7. this+0x08 = 1000 (pulse period ms)
//   8. return this
//
// CALLEES: CVOGHBBase_ctor, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_AttachOwnerObject
// CALLERS: CVOGObjectiveRequirement_Patrol_InitActive @ 0x0060e3d0
//
// Family: CVOGHBMissionPatrol_Fn3 (0x00650e50), Fn6 (0x00650de0), Tick (0x00650f90)
// =============================================================================

#include <cstdint>

// External symbols (retail / already sealed siblings)
extern "C" void *__thiscall CVOGHBBase_ctor(void *self);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *self, int period, bool alsoCounter);
extern "C" void __thiscall CVOGHBBase_AttachOwnerObject(void *self, void *owner);
extern "C" void *PTR_FUN_009e52e4;
extern "C" void *ExceptionList;
extern "C" void *LAB_009a8ec8;

using uint32_t = std::uint32_t;
using uint8_t = std::uint8_t;

void *__thiscall CVOGHBMissionPatrol_ctor(void *self, void *pOwnerOrNull, int *pRequirement)
{
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  uint32_t uFromReq;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009a8ec8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;

  CVOGHBBase_ctor(self);
  *(void **)self = &PTR_FUN_009e52e4;
  local_4 = 0;

  // requirement->vtbl[0x58/4]
  uFromReq = (*(uint32_t(__thiscall **)(int *))(*(uint32_t *)pRequirement + 0x58))(pRequirement);
  ((uint32_t *)self)[9] = uFromReq;
  ((uint32_t *)self)[10] = *(uint32_t *)(pRequirement[1] + 0x10);
  ((uint32_t *)self)[0xc] = (uint32_t)pRequirement[0xc];
  ((uint32_t *)self)[0xd] = (uint32_t)pRequirement[0xd];
  ((uint32_t *)self)[0xe] = (uint32_t)pRequirement[7];
  ((uint32_t *)self)[7] = 0xC;

  CVOGHBBase_SetPeriodAndCounter(self, -1000, true);

  if (pOwnerOrNull != nullptr) {
    pOwnerOrNull = (void *)(
        (int)pOwnerOrNull
      + *(int *)(*(int *)((int)pOwnerOrNull + 4) + 4)
      + 4);
  }
  CVOGHBBase_AttachOwnerObject(self, pOwnerOrNull);

  ((uint32_t *)self)[2] = 1000; // +0x08 pulse period

  ExceptionList = pvStack_c;
  return self;
}
