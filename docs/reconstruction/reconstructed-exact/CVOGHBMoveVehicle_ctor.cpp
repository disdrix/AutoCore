// =============================================================================
// CVOGHBMoveVehicle_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00636bd0
// Address:   0x00636bd0  (autoassault.exe, image base 0x400000)
// Body:      0x00636bd0 – 0x00636c49 inclusive (122 B / 0x7A)
// System:    input-drive-control / CVOGHBMoveVehicle constructor
// Generated: 2026-08-05 R12-006 dual seal (live Ghidra + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE:
//   Construct CVOGHBMoveVehicle (RTTI .?AVCVOGHBMoveVehicle@@):
//     1) CVOGHBBase_ctor
//     2) Install vtbl PTR_FUN_009e3b70
//     3) SetPeriodAndCounter(-1000, true) then pulse period +0x08 = 50 ms
//     4) Drive defaults: acceptDist 2.5f, cruise 0, aim 15.0f bits
//     5) Bind entity* at +0x24; flag +0x29 = 0
//     6) AttachOwner null or MSVC MI this-adjusted owner
//
// ABI:
//   MSVC __thiscall — this in ECX; one stack arg pEntity; RET 4; EAX = this.
//
// CALLEES:
//   CVOGHBBase_ctor                 0x00508200
//   CVOGHBBase_SetPeriodAndCounter  0x005081a0
//   CVOGHBBase_AttachOwnerObject    0x005083b0
//
// CALLERS:
//   FUN_00599550 @ 0x00599558 (ToMouse subclass ctor; overrides vtbl after)
//
// RELATED:
//   OnHeartBeat 0x00636cc0 (parent dual R11-023)
//   OnEnd       0x00636ba0 (MEGA-017)
//   ScalarDtor  0x00636d10 (R11-024)
// =============================================================================

#include <cstdint>

struct VehicleEntity;

struct CVOGHBMoveVehicle {
  void *vtbl; // +0x00 → PTR_FUN_009e3b70
  // CVOGHBBase fields through +0x23 (sizeof base 0x28)
  // VehicleEntity *entity; // +0x24
  // uint8_t flag;          // +0x29
  // float acceptDist;      // +0x2c  default 2.5f
  // float cruiseScale;     // +0x30  default 0.0f
  // float aimDefault;      // +0x34  default 15.0f bits
};

extern void __thiscall CVOGHBBase_ctor(void *self);
extern void __thiscall CVOGHBBase_SetPeriodAndCounter(
    void *self, int nPeriodSentinel, bool bAlsoSetCounter);
extern void __thiscall CVOGHBBase_AttachOwnerObject(
    void *self, void *pOwnerObject);

// Image float globals (read_memory 2026-08-05)
extern float DAT_00aaa6c4; // 2.5f
extern float DAT_00aaa7a4; // 15.0f

// Subclass vtbl (read_memory @ 0x009e3b70)
extern void *PTR_FUN_009e3b70;

CVOGHBMoveVehicle *__thiscall CVOGHBMoveVehicle_ctor(
    CVOGHBMoveVehicle *self,
    VehicleEntity *pEntity)
{
  auto *const base = reinterpret_cast<char *>(self);

  CVOGHBBase_ctor(self);

  *reinterpret_cast<void **>(base + 0x00) = &PTR_FUN_009e3b70;

  // Sentinel/counter -1000 (always-ready reschedule); not the fire interval.
  CVOGHBBase_SetPeriodAndCounter(self, /*nPeriodSentinel=*/-1000,
                                 /*bAlsoSetCounter=*/true);

  *reinterpret_cast<float *>(base + 0x2c) = DAT_00aaa6c4; // acceptDist 2.5f
  *reinterpret_cast<float *>(base + 0x30) = 0.0f;         // cruiseScale
  *reinterpret_cast<float *>(base + 0x34) = DAT_00aaa7a4; // aim default 15.0f
  *reinterpret_cast<uint32_t *>(base + 0x08) = 0x32;      // pulse 50 ms
  *reinterpret_cast<VehicleEntity **>(base + 0x24) = pEntity;
  *reinterpret_cast<uint8_t *>(base + 0x29) = 0;

  if (pEntity == nullptr) {
    CVOGHBBase_AttachOwnerObject(self, nullptr);
    return self;
  }

  // MSVC MI this-adjust: pEntity + 4 + *(*(pEntity+4)+4)
  auto *const pEntityBytes = reinterpret_cast<char *>(pEntity);
  auto *const mid = *reinterpret_cast<char **>(pEntityBytes + 4);
  const int adjust = *reinterpret_cast<int *>(mid + 4);
  void *const pOwner = pEntityBytes + 4 + adjust;
  CVOGHBBase_AttachOwnerObject(self, pOwner);
  return self;
}
