// =============================================================================
// FUN_006261e0  (alias → CVOGHBActivatePlayer_EndOrDestroy_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006261e0
// Address:   0x006261e0–0x00626202  (35 B / 0x23; autoassault.exe base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W29-P OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named clean: reconstructed-exact/CVOGHBActivatePlayer_EndOrDestroy_Inferred.cpp
// ABI: __thiscall; stack (flag_onEnd, flag_hard); ret 8.

#include <cstdint>

extern "C" void __thiscall FUN_005083f0(void *self, uint32_t flag_onEnd, uint32_t flag_hard);

using OnEnd_fn = void(__thiscall *)(void *self);

void __thiscall FUN_006261e0(void *param_1, uint32_t param_2, uint32_t param_3)
{
  if (static_cast<char>(param_2) == 0) {
    void **vtbl = *reinterpret_cast<void ***>(param_1);
    auto onEnd = reinterpret_cast<OnEnd_fn>(vtbl[0x14 / sizeof(void *)]);
    onEnd(param_1);
  }
  FUN_005083f0(param_1, param_2, param_3);
}
