// =============================================================================
// FUN_0058e270
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e270
// Address:   0x0058e270–0x0058e2f1  (129 B)
// System:    client-fx / NDSpecialFX child FX toggle (slot-filtered)
// Dual A/B:  2026-07-29 accept (W26-K)
// Named twin: NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed ECX
//            for 0096d* callees. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Slot-filtered child FX toggle. Gate on child+0x25c vs slot_filter (wild -1),
 * skip if child slot is -1. Optional stop (effect_stop) then optional start
 * (effect_start); set/clear +0x90f bit0.
 *
 * thiscall; ret 0x0C.
 * Exclusive caller: FUN_004b7030 (when use_slot_filter != 0).
 *
 * Sibling: FUN_0058e300 — same body without slot match; requires +0x25c < 0.
 */

#include <stdint.h>

/* Particle / attach helpers — signatures byte-sealed (thiscall). */
void __thiscall FUN_0096d550(void *effect, uint32_t handle_at_914);
int  __thiscall FUN_0096d460(void *effect, uint32_t key_at_258);
void __thiscall FUN_0096dc80(void *effect, uint32_t key_at_258,
                             uint32_t handle_at_914, uint32_t arg_at_254);

void __thiscall FUN_0058e270(
    void *child,
    void *effect_start,
    void *effect_stop,
    int slot_filter)
{
  unsigned char sf = (unsigned char)slot_filter;
  int child_slot = *(int *)((char *)child + 0x25c);

  if (((sf == 0xFF) || (child_slot == (int)(signed char)sf)) &&
      (child_slot != -1)) {
    if (effect_stop != 0) {
      FUN_0096d550(effect_stop, *(uint32_t *)((char *)child + 0x914));
    }
    if (effect_start != 0) {
      if (FUN_0096d460(effect_start, *(uint32_t *)((char *)child + 0x258)) == 0) {
        FUN_0096dc80(
            effect_start,
            *(uint32_t *)((char *)child + 0x258),
            *(uint32_t *)((char *)child + 0x914),
            *(uint32_t *)((char *)child + 0x254));
        *(uint8_t *)((char *)child + 0x90f) =
            (uint8_t)(*(uint8_t *)((char *)child + 0x90f) | 1);
        return;
      }
    }
    *(uint8_t *)((char *)child + 0x90f) =
        (uint8_t)(*(uint8_t *)((char *)child + 0x90f) & 0xFE);
  }
}
