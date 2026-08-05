// =============================================================================
// Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred
//   (named alias of FUN_00584330)
// -----------------------------------------------------------------------------
// Stable ID: aa_00584330
// Address:   0x00584330–0x005843af  (127 B)
// Dual A/B:  2026-07-29 accept (W26-K)
// Authoritative clean twin: FUN_00584330.cpp
// =============================================================================

/*
 * Single effect-slot apply with no slot filter (filter char 0 → e300 path),
 * then tail-chain container teardown FUN_005179e0.
 *
 * Chain peer of Object_ApplyDualFxSlots_SlotFilterWild_Inferred (004c8110),
 * which tail-jmps here at self-0x430.
 *
 * thiscall; no stack formals; tail jmp (no ret).
 */

void __thiscall NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
    void *table_owner,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);

void __thiscall NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *fx_host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);

void __fastcall FUN_005179e0(void *adjusted_this);

void __thiscall Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred(void *self)
{
  char *p = (char *)self;
  int effect = *(int *)(p - 0x88);

  if (effect != 0) {
    NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
        p - 0x90, 0, effect, 0, -1);

    {
      int vb = *(int *)(*(int *)(p - 0x8c) + 4);
      void **it = *(void ***)(p + vb + 0xac);
      void **end = *(void ***)(p + vb + 0xb0);
      if (it != end) {
        do {
          NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
              *it, 0, effect, 0, -1);
          it = (void **)((char *)it + 4);
        } while (it != *(void ***)(
                     *(int *)(*(int *)(p - 0x8c) + 4) + 0xb0 + p));
      }
    }
  }

  FUN_005179e0((void *)((p - 0x8c) + *(int *)(*(int *)(p - 0x8c) + 4)));
}
