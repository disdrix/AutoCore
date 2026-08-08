// =============================================================================
// CVOGHBMoveVehicle_OnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_00636ba0
// Address:   0x00636ba0  (autoassault.exe, image base 0x400000)
// Body:      0x00636ba0 – 0x00636bbf inclusive (32 B / 0x20)
// System:    input-drive-control / heartbeat OnEnd
// Generated: 2026-08-05 MEGA-017 dual seal (live Ghidra + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow.
//            Decompiler omits empty-ret tail; assembly is authoritative.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE:
//   Virtual OnEnd (vtbl+0x10) for CVOGHBMoveVehicle (RTTI .?AVCVOGHBMoveVehicle@@).
//   When Stop arms dormant and tails here: if bound vehicle entity (this+0x24)
//   is non-null, park steer to 0 via gated SetSteerInput, then PushDriveAxes
//   (thr/HB → controller). Does NOT zero throttle or set handbrake.
//
// ABI:
//   MSVC __thiscall — this in ECX; no stack args; ends JMP 0x005081e0 (C3).
//
// CALLEES:
//   VehicleEntity_SetSteerInput          0x004f5620  (entity, 0.0f)
//   VehicleEntity_PushDriveAxesToController 0x004fbc10
//   empty ret stub                        0x005081e0  (tail only)
//
// DISPATCH:
//   No direct code callers. DATA: vtbl slots 0x009e3b80 / 0x009d55a0.
//   CVOGHBBase_Stop → jmp [vtbl+0x10].
//
// RELATED:
//   Ctor FUN_00636bd0 binds entity at +0x24; fire FUN_00636cc0 may Stop on
//   MoveToTarget failure. Contrast full AI park pack 0x005d73a0 (thr0/steer0/HB1).
// =============================================================================

#include <cstdint>

struct VehicleEntity; // layout: steer f32 @ +0x618; thr @ +0x614; HB u8 @ +0x61c

struct CVOGHBMoveVehicle {
  void *vtbl;                 // +0x00 → PTR_FUN_009e3b70 (or ToMouse 009d5590)
  // ... CVOGHBBase fields through +0x20 ...
  // VehicleEntity *entity;  // +0x24  (param_1[9] in ctor)
};

// Dual-sealed callees (see aa_004f5620 / aa_004fbc10)
extern void __thiscall VehicleEntity_SetSteerInput(VehicleEntity *self, float steerInput);
extern void __fastcall VehicleEntity_PushDriveAxesToController(VehicleEntity *self);

// Empty leaf at 0x005081e0 (distinct from CVOGHBBase_EmptyVFunc 0x005081f0)
extern void EmptyRet_005081e0(void);

void __thiscall CVOGHBMoveVehicle_OnEnd(CVOGHBMoveVehicle *self)
{
  VehicleEntity *entity =
      *reinterpret_cast<VehicleEntity **>(reinterpret_cast<char *>(self) + 0x24);

  if (entity != nullptr) {
    VehicleEntity_SetSteerInput(entity, 0.0f);
    VehicleEntity_PushDriveAxesToController(entity);
  }

  // Machine: MOV ECX,self; POP ESI; JMP 0x005081e0
  EmptyRet_005081e0();
}
