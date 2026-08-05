// =============================================================================
// NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred
//   (named alias of FUN_0058e270)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e270
// Address:   0x0058e270–0x0058e2f1  (129 B)
// Dual A/B:  2026-07-29 accept (W26-K)
// Authoritative clean twin: FUN_0058e270.cpp
// =============================================================================

/*
 * Slot-filtered FX start/stop on an NDSpecialFX-owned child.
 * Wild slot_filter low-byte 0xFF matches any; child+0x25c must not be -1.
 *
 * thiscall; ret 0x0C.
 * Exclusive caller: NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred
 *   when use_slot_filter != 0.
 */

#include <stdint.h>

void __thiscall FUN_0096d550(void *effect, uint32_t handle_at_914);
int  __thiscall FUN_0096d460(void *effect, uint32_t key_at_258);
void __thiscall FUN_0096dc80(void *effect, uint32_t key_at_258,
                             uint32_t handle_at_914, uint32_t arg_at_254);

void __thiscall NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred(
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
      if (FUN_0096d460(effect_start,
                       *(uint32_t *)((char *)child + 0x258)) == 0) {
        FUN_0096dc80(
            effect_start,
            *(uint32_t *)((char *)child + 0x258),
            *(uint32_t *)((char *)child + 0x914),
            *(uint32_t *)((char *)child + 0x254));
        *(uint8_t *)((char *)child + 0x90f) |= 1u;
        return;
      }
    }
    *(uint8_t *)((char *)child + 0x90f) &= (uint8_t)~1u;
  }
}
