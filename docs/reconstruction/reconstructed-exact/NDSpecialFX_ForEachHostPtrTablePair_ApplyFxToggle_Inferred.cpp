// =============================================================================
// NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred  (named alias of FUN_00583f10)
// -----------------------------------------------------------------------------
// Stable ID: aa_00583f10
// Address:   0x00583f10-0x00583f9e  (143 B)
// Dual A/B:  2026-07-29 accept (W25-D)
// Authoritative clean twin: FUN_00583f10.cpp
// Prior scaffold alias: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00583f10
// =============================================================================

/*
 * Fan-out sealed NDSpecialFX owned-bit7 FX toggle across two host-pointer
 * vectors on a vbase-adjusted table owner.
 *
 * thiscall; RET 0x10 (4 stack args passthrough).
 * Per entry: ECX = *it (host*); decompiler often omits this setup.
 */

void __thiscall NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *fx_host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);

void __thiscall NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
    void *table_owner,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter)
{
  int vb_delta;
  char *base;
  void **it;
  void **end;

  vb_delta = *(int *)(*(int *)((char *)table_owner + 4) + 4);
  base = (char *)table_owner + vb_delta;

  it = *(void ***)(base + 0x128);
  end = *(void ***)(base + 0x12c);
  if (it != end) {
    do {
      NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
          *it, want_start, want_stop, use_slot_filter, slot_filter);
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(
                 *(int *)(*(int *)((char *)table_owner + 4) + 4) + 0x12c
                 + (char *)table_owner));
  }

  vb_delta = *(int *)(*(int *)((char *)table_owner + 4) + 4);
  it = *(void ***)((char *)table_owner + vb_delta + 0x13c);
  end = *(void ***)((char *)table_owner + vb_delta + 0x140);
  if (it != end) {
    do {
      NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
          *it, want_start, want_stop, use_slot_filter, slot_filter);
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(
                 *(int *)(*(int *)((char *)table_owner + 4) + 4) + 0x140
                 + (char *)table_owner));
  }
}
