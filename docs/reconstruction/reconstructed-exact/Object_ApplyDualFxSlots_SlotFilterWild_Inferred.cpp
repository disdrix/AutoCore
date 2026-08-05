// =============================================================================
// Object_ApplyDualFxSlots_SlotFilterWild_Inferred  (named alias of FUN_004c8110)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8110
// Address:   0x004c8110-0x004c81e5  (214 B)
// Dual A/B:  2026-07-29 accept (W25-D)
// Authoritative clean twin: FUN_004c8110.cpp
// =============================================================================

/*
 * Dual effect-slot apply: for each non-null effect at this-0x27c / this-0x280,
 * fan-out slot-filtered wild toggle (0, effect, 1, -1) via host-table pair helper
 * and a local host* vector, then tail-chain FUN_00584330 at this-0x430.
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

void __thiscall FUN_00584330(void *rebased_this);

void __thiscall Object_ApplyDualFxSlots_SlotFilterWild_Inferred(void *self)
{
  int effect;
  int vb;
  void **it;
  void **end;
  char *p = (char *)self;

  effect = *(int *)(p - 0x27c);
  if (effect != 0) {
    NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
        p - 0x4c0, 0, effect, 1, -1);
    vb = *(int *)(*(int *)(p - 0x4fc) + 4);
    it = *(void ***)(p + vb - 0x3c4);
    end = *(void ***)(p + vb - 0x3c0);
    if (it != end) {
      do {
        NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
            *it, 0, effect, 1, -1);
        it = (void **)((char *)it + 4);
      } while (it != *(void ***)(
                   *(int *)(*(int *)(p - 0x4fc) + 4) - 0x3c0 + p));
    }
  }

  effect = *(int *)(p - 0x280);
  if (effect != 0) {
    NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
        p - 0x4c0, 0, effect, 1, -1);
    vb = *(int *)(*(int *)(p - 0x4fc) + 4);
    it = *(void ***)(p + vb - 0x3c4);
    end = *(void ***)(p + vb - 0x3c0);
    if (it != end) {
      do {
        NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
            *it, 0, effect, 1, -1);
        it = (void **)((char *)it + 4);
      } while (it != *(void ***)(
                   *(int *)(*(int *)(p - 0x4fc) + 4) - 0x3c0 + p));
    }
  }

  FUN_00584330(p - 0x430);
}
