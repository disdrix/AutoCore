// =============================================================================
// CVOGHBMoveVehicle_OnHeartBeat
// -----------------------------------------------------------------------------
// Stable ID: aa_00636cc0
// Address:   0x00636cc0  (autoassault.exe, image base 0x400000)
// Body:      0x00636cc0 – 0x00636d07 inclusive (72 B / 0x48)
// System:    input-drive-control / heartbeat OnHeartBeat
// Generated: 2026-08-05 R11-023 dual seal (live Ghidra + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow.
//            Decompiler mis-binds MoveToTarget this/args; assembly is authoritative.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE:
//   Virtual OnHeartBeat (vtbl+0x0c) for CVOGHBMoveVehicle
//   (RTTI .?AVCVOGHBMoveVehicle@@). Shared by CVOGHBMoveVehicleToMouse.
//
//   If bound vehicle entity (this+0x24) is null: write out-status 1 and return.
//   Else: call CVOGVehicle::MoveToTarget3DPoint(entity, acceptDist, cruiseScale,
//   aimUnused, allowReverse=1). On false return, CVOGHBBase_Stop(this) which may
//   run OnEnd (steer-park). Always write out-status 0 (Continue) on entity path.
//
// ABI:
//   MSVC __thiscall — this in ECX; one stack arg pOutStatus; RET 4.
//   EAX on exit = pOutStatus (TryFire may deref).
//
// CALLEES:
//   CVOGVehicle::MoveToTarget3DPoint  0x004fc650  (entity thiscall)
//   CVOGHBBase_Stop                   0x005081d0  (HB thiscall; fail path only)
//
// DISPATCH:
//   No direct code callers. DATA: vtbl slots 0x009e3b7c / 0x009d559c.
//   CVOGHBBase_TryFire → call [vtbl+0x0c].
//
// RELATED:
//   OnEnd 0x00636ba0 (MEGA-017 dual). Ctor FUN_00636bd0 binds entity + defaults.
// =============================================================================

#include <cstdint>

struct VehicleEntity; // MoveToTarget writes thr +0x614, steer +0x618, HB +0x61c

struct CVOGHBMoveVehicle {
  void *vtbl; // +0x00 → PTR_FUN_009e3b70 (or ToMouse 009d5590)
  // ... CVOGHBBase fields through +0x20 ...
  // VehicleEntity *entity;   // +0x24
  // float acceptDist;        // +0x2c  ctor default 2.5f
  // float cruiseScale;       // +0x30  ctor default 0.0f
  // uint32_t aimUnused;      // +0x34  ctor default 15.0f bits; MoveTo ignores
};

// Dualed / verified callees
extern uint32_t __thiscall MoveToTarget3DPoint(
    VehicleEntity *self,
    float acceptDist,
    float cruiseScale,
    void *aimUnused,
    char allowReverse); // returns AL bool (1 = drove, 0 = arrived/disabled)

extern void __fastcall CVOGHBBase_Stop(CVOGHBMoveVehicle *self);

// Image globals (read_memory 2026-08-05)
extern uint32_t DAT_00af4f84; // = 1  (no-entity status)
extern uint32_t DAT_00d02c60; // = 0  (Continue)

uint32_t *__thiscall CVOGHBMoveVehicle_OnHeartBeat(
    CVOGHBMoveVehicle *self,
    uint32_t *pOutStatus)
{
  auto *const base = reinterpret_cast<char *>(self);
  VehicleEntity *entity =
      *reinterpret_cast<VehicleEntity **>(base + 0x24);

  if (entity == nullptr) {
    *pOutStatus = DAT_00af4f84; // 1
    return pOutStatus;
  }

  // Machine: ECX still holds entity from the gate load; four stack pushes follow.
  const float acceptDist =
      *reinterpret_cast<float *>(base + 0x2c);
  const float cruiseScale =
      *reinterpret_cast<float *>(base + 0x30);
  void *const aimUnused =
      *reinterpret_cast<void **>(base + 0x34);

  const uint32_t ok = MoveToTarget3DPoint(
      entity,
      acceptDist,
      cruiseScale,
      aimUnused,
      /*allowReverse=*/1);

  if (ok == 0) {
    // Machine: mov ecx, esi; call CVOGHBBase_Stop
    CVOGHBBase_Stop(self);
  }

  *pOutStatus = DAT_00d02c60; // 0 = Continue
  return pOutStatus;
}
