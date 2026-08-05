// =============================================================================
// Object_DoFullInit_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00516be0
// Address:   0x00516be0 – 0x00516c30  (autoassault.exe, image base 0x400000)
// System:    object / load-init
// Generated: Dual A/B sealed 2026-07-29 (W24-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00516be0
// =============================================================================

/*
 * Role:
 *   Shared full-init epilogue for cloned objects (load node, create/init paths).
 *   1) Resolve related object via vtbl+0x1d4 (parent/vehicle/body handle).
 *   2) If related is null OR related+0x2ac == 0, call vtbl+0x100.
 *   3) Always call vtbl+0x48.
 *   4) If clonebase type (this[0x2a]+0x38) is not 0x12 and not 0x14,
 *      refresh active skill effects with param_2=1 (all active).
 *
 * Callers:
 *   CLoadNode::_initFull (FUN_005c78a0) when not special player-full path;
 *   FUN_0053e0d0 / FUN_00581b30 / FUN_005d5140 (DoFullInit family; latter logs
 *   "DoFullInit Anim" on a sibling stage).
 *   Also installed in multiple class vtables (DATA xrefs).
 *
 * ABI: object in ECX (thiscall); void; no stack args.
 */

void __thiscall Object_DoFullInit_Inferred(int *thisObj)

{
  int related;
  
  related = (**(code **)(*thisObj + 0x1d4))();
  if (related != 0) {
    related = (**(code **)(*thisObj + 0x1d4))();
    if (*(char *)(related + 0x2ac) != '\0') goto skip_vtbl_100;
  }
  (**(code **)(*thisObj + 0x100))();
skip_vtbl_100:
  (**(code **)(*thisObj + 0x48))();
  if ((*(int *)(thisObj[0x2a] + 0x38) != 0x12) &&
      (*(int *)(thisObj[0x2a] + 0x38) != 0x14)) {
    /* Object_RefreshActiveSkillEffects_Inferred(this, 1) */
    FUN_00516a00(1);
  }
  return;
}
