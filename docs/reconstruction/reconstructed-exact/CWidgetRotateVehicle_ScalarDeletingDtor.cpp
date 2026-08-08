// =============================================================================
// CWidgetRotateVehicle_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004160f0
// Address:   0x004160f0–0x0041610f exclusive (31 B / 0x1F, autoassault.exe base 0x400000)
// System:    CWidgetRotateVehicle / MSVC scalar-deleting destructor
// Generated: 2026-08-05 WQ9I-F dual A/B (decompile + read_memory + RTTI)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004160f0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CWidgetRotateVehicle.
//   DATA slot PTR_LAB_00a6ff94[+0x0C] @ 0x00a6ffa0 = this VA.
//   RTTI COL 0x00ab5d8c → .?AVCWidgetRotateVehicle@@.
//   Always runs complete dtor FUN_00416110 (stack this → install base
//   PTR_LAB_00a9bbe8). If (flags & 1), operator_delete. Returns this; ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags; ret 4; returns this*.
//   Complete callee is stack-this + ret 4 (extra push ESI before CALL).
//
// TWINS / RELATED:
//   FUN_00416110  — complete dtor (WQ9I-G OWN)
//   FUN_00833500  — ctor installs PTR_LAB_00a6ff94
//   aa_004160d0   — CWndVehicle_ScalarDeletingDtor (sibling OWN WQ9I-F)
// =============================================================================

#include <cstdint>

// Complete dtor: stack this, ret 4 (bytes at 0x00416110)
extern "C" void __stdcall FUN_00416110(void* self);
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004160f0(void* this, uint8_t flags)
extern "C" void* __thiscall CWidgetRotateVehicle_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self; push self for stack-this complete dtor
  FUN_00416110(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
