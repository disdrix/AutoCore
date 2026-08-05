// =============================================================================
// NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred  (named alias of FUN_004b7030)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7030
// Address:   0x004b7030
// Dual A/B:  2026-07-29 accept (W24-D)
// Authoritative clean twin: FUN_004b7030.cpp
// Rejected scaffold alias: Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030
// =============================================================================

/*
 * For each owned child on NDSpecialFX host list (+0x204) with +0x90e bit7 set,
 * apply FX start/stop toggle via slot-unrestricted or slot-filtered helper.
 *
 * thiscall; RET 0x10 (4 stack args).
 */

void __thiscall NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *fx_host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter)
{
  int *node;
  void *child;

  node = *(int **)(*(int *)((char *)fx_host + 0x204));
  if (node != *(int **)((char *)fx_host + 0x204)) {
    do {
      child = (void *)node[2];
      if ((*(unsigned char *)((char *)child + 0x90e) & 0x80) != 0) {
        if (use_slot_filter == 0) {
          FUN_0058e300(child, want_start, want_stop);
        } else {
          FUN_0058e270(child, want_start, want_stop, slot_filter);
        }
      }
      node = (int *)*node;
    } while (node != *(int **)((char *)fx_host + 0x204));
  }
}
