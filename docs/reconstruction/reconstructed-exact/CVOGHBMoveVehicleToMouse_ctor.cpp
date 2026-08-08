// =============================================================================
// CVOGHBMoveVehicleToMouse_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00599550
// Address:   0x00599550  (autoassault.exe, image base 0x400000)
// Body:      0x00599550 – 0x0059956f inclusive (32 B / 0x20)
// System:    input-drive-control / CVOGHBMoveVehicleToMouse constructor
// Generated: 2026-08-05 R13-007 dual seal (live Ghidra + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE:
//   Construct CVOGHBMoveVehicleToMouse (RTTI .?AVCVOGHBMoveVehicleToMouse@@):
//     1) CVOGHBMoveVehicle_ctor(pEntity)  — base HB + MoveVehicle vtbl + defaults
//     2) Override vtbl to PTR_FUN_009d5590 (ToMouse)
//     3) Store host/world-sim context at +0x40
//     4) Return this
//
// ABI:
//   MSVC __thiscall — this in ECX; stack pEntity, pHostCtx; RET 8; EAX = this.
//   Object size 0x44 (operator_new at all four call sites).
//
// CALLEES:
//   CVOGHBMoveVehicle_ctor  0x00636bd0  (R12-006 dualed)
//
// CALLERS (4):
//   Client_CreateVehicleObjectApply @ 0x0081299a
//   FUN_00810360                    @ 0x0081057a
//   FUN_009147a0                    @ 0x009147e5
//   FUN_0094b3a0                    @ 0x0094b47f
//
// RELATED:
//   ScalarDeletingDtor 0x005996a0 (parent dual R12-028, vtbl[0])
//   Complete/body      0x00599570 (residual)
//   Base ctor          0x00636bd0 (R12-006)
//   Shared OnHeartBeat 0x00636cc0 / OnEnd 0x00636ba0
// =============================================================================

#include <cstdint>

struct VehicleEntity;
struct HostWorldSimCtx; // product type English open; role = client+0xe04 world/sim

struct CVOGHBMoveVehicleToMouse {
  void *vtbl; // +0x00 → PTR_FUN_009d5590 after this ctor
  // CVOGHBMoveVehicle / CVOGHBBase fields through ~+0x34 (base ctor)
  // void *entity;              // +0x24  (base)
  // float acceptDist;          // +0x2c
  // float cruiseScale;         // +0x30
  // float aimDefault;          // +0x34
  // ...
  // HostWorldSimCtx *hostCtx;  // +0x40  (this unit)
  // size 0x44
};

extern CVOGHBMoveVehicleToMouse *__thiscall CVOGHBMoveVehicle_ctor(
    CVOGHBMoveVehicleToMouse *self,
    VehicleEntity *pEntity);

// ToMouse subclass vtbl (read_memory @ 0x009d5590; dword0 = ScalarDeletingDtor)
extern void *PTR_FUN_009d5590;

CVOGHBMoveVehicleToMouse *__thiscall CVOGHBMoveVehicleToMouse_ctor(
    CVOGHBMoveVehicleToMouse *self,
    VehicleEntity *pEntity,
    HostWorldSimCtx *pHostCtx)
{
  auto *const base = reinterpret_cast<char *>(self);

  CVOGHBMoveVehicle_ctor(self, pEntity);

  *reinterpret_cast<void **>(base + 0x00) = &PTR_FUN_009d5590;
  *reinterpret_cast<HostWorldSimCtx **>(base + 0x40) = pHostCtx;

  return self;
}
