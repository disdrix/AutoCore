// =============================================================================
// FUN_00584330
// -----------------------------------------------------------------------------
// Stable ID: aa_00584330
// Address:   0x00584330–0x005843af  (127 B)
// System:    client-fx / object single FX slot apply + teardown chain
// Dual A/B:  2026-07-29 accept (W26-K)
// Named twin: Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed ECX
//            for callees and tail jmp. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * If effect* at this-0x88 is non-null, apply FX toggle pack
 * (want_start=0, want_stop=effect, use_slot_filter=0, slot_filter=-1) via:
 *   - host-ptr table-pair fan-out at this-0x90 (FUN_00583f10)
 *   - local host* vector at vb(this-0x8c)+0xac..+0xb0 (FUN_004b7030 per *it)
 * Then tail-jmp FUN_005179e0 with vbase-adjusted this (list teardown).
 *
 * thiscall; no stack formals; epilogue is jmp (no ret).
 * use_slot_filter=0 selects FUN_0058e300 path inside sealed helpers
 * (distinct from dual-slot wild pack which uses filter char 1).
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

void __thiscall FUN_00584330(void *self)
{
  char *p = (char *)self;
  int effect;
  int vb;
  void **it;
  void **end;

  effect = *(int *)(p - 0x88);
  if (effect != 0) {
    /* lea ecx,[esi-0x90] */
    NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
        p - 0x90, 0, effect, 0, -1);

    vb = *(int *)(*(int *)(p - 0x8c) + 4);
    it = *(void ***)(p + vb + 0xac);
    end = *(void ***)(p + vb + 0xb0);
    if (it != end) {
      do {
        /* mov ecx,[edi] — host this = *it */
        NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
            *it, 0, effect, 0, -1);
        it = (void **)((char *)it + 4);
      } while (it != *(void ***)(
                   *(int *)(*(int *)(p - 0x8c) + 4) + 0xb0 + p));
    }
  }

  /* lea ecx,[(self-0x8c)+*(*(self-0x8c)+4)]; pop esi; jmp FUN_005179e0 */
  FUN_005179e0((void *)((p - 0x8c) + *(int *)(*(int *)(p - 0x8c) + 4)));
}
