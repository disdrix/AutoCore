// =============================================================================
// Client_Input_KeyDown_UiGateAndForward_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00790020
// Address:   0x00790020  (autoassault.exe, image base 0x400000)
// Body:      0x00790020–0x00790098 inclusive (121 B / 0x79)
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-094 dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Purpose:  Virtual key-down handler on client/UI host:
//           1) Gate on this->vtbl+0x3D8(); return 0 if blocked.
//           2) If focused UI at this+0x4BC, forward (key,lParam) via child vtbl+0x358.
//           3) ESC (0x1B): if UI present → this->vtbl+0x3BC(0); else if
//              secondary modal code at +0x49C >= 0 → this->vtbl+0x338(8, code).
//           4) Else return 1 (continue).
//
// Related:
//   Client_Input_OnKeyDown_MatchAction  0x00911030  (primary code caller)
//   Client_ShowModalPrompt / UF-009     +0x498/+0x49C dual-id, vtbl+0x338(8,…)
//   FUN_00866220 / FUN_008cc420         UI key handlers fall through here
//
// ABI: __thiscall; ECX=this; stack key,lParam; RET 8; AL return.
// =============================================================================

#include <cstdint>

// Vtable call helpers — product names open; offsets sealed.
using VGateFn = uint8_t(__thiscall *)(void *self);
using VKeyFn = void(__thiscall *)(void *self, int key, uint32_t lParam);
using VCancelFn = void(__thiscall *)(void *self, int arg0);
using VDispatchFn = uint32_t(__thiscall *)(void *self, int action, int code);

uint32_t __thiscall Client_Input_KeyDown_UiGateAndForward_Inferred(
    int *self, int key, uint32_t lParam)
{
  // --- gate: vtbl+0x3D8 ---
  auto **vtbl = reinterpret_cast<void **>(*self);
  auto gate = reinterpret_cast<VGateFn>(vtbl[0x3d8 / 4]);
  if (gate(self) == 0) {
    return 0;
  }

  // --- forward to focused UI at +0x4BC (param_1[0x12f]) ---
  int *focused = reinterpret_cast<int *>(self[0x12f]);
  if (focused != nullptr) {
    auto **fvt = reinterpret_cast<void **>(*focused);
    auto on_key = reinterpret_cast<VKeyFn>(fvt[0x358 / 4]);
    on_key(focused, key, lParam);
  }

  // --- ESC (VK 0x1B) ---
  if (key == 0x1b) {
    if (focused != nullptr) {
      auto cancel = reinterpret_cast<VCancelFn>(vtbl[0x3bc / 4]);
      cancel(self, 0);
      return 1;
    }
    // secondary modal code at +0x49C (param_1[0x127])
    int secondary = self[0x127];
    if (secondary >= 0) {
      auto dispatch = reinterpret_cast<VDispatchFn>(vtbl[0x338 / 4]);
      return dispatch(self, 8, secondary);
    }
  }

  return 1;
}
