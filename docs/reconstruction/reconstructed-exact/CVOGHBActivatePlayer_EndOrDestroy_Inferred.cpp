// =============================================================================
// CVOGHBActivatePlayer_EndOrDestroy_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006261e0
// Address:   0x006261e0–0x00626202  (35 B / 0x23; autoassault.exe base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W29-P OWN-ONLY dual (from raw + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Activate-player HB virtual EndOrDestroy (vtbl 0x009e3168 +0x18).
// When flag_onEnd==0, pre-calls own OnEnd (vtbl+0x14) so host notify still runs;
// base EndOrDestroy skips OnEnd when flag0==0. Always chains to CVOGHBBase_EndOrDestroy.
//
// ABI: __thiscall ECX=this; stack (flag_onEnd, flag_hard); ret 8; void.

#include <cstdint>

// CVOGHBBase_EndOrDestroy — FUN_005083f0 (two stack flags; ret 8)
extern "C" void __thiscall FUN_005083f0(void *self, uint32_t flag_onEnd, uint32_t flag_hard);

using OnEnd_fn = void(__thiscall *)(void *self);

void __thiscall CVOGHBActivatePlayer_EndOrDestroy_Inferred(
    void *self, uint32_t flag_onEnd, uint32_t flag_hard)
{
  if (static_cast<char>(flag_onEnd) == 0) {
    void **vtbl = *reinterpret_cast<void ***>(self);
    auto onEnd = reinterpret_cast<OnEnd_fn>(vtbl[0x14 / sizeof(void *)]);
    onEnd(self);
  }
  FUN_005083f0(self, flag_onEnd, flag_hard);
}
