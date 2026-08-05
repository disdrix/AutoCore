// =============================================================================
// FUN_00516be0  (scaffold alias — prefer Object_DoFullInit_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00516be0
// Address:   0x00516be0 – 0x00516c30  (autoassault.exe, image base 0x400000)
// System:    object / load-init
// Generated: 2026-07-23 scaffold; Dual A/B sealed 2026-07-29 (W24-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Object this (ECX): optional vtbl+0x100 when related (vtbl+0x1d4) is null or
 *   related+0x2ac == 0; always vtbl+0x48; skill refresh FUN_00516a00(1) unless
 *   clonebase type is 0x12 or 0x14.
 * - Called from CLoadNode::_initFull and other DoFullInit-style paths.
 * - Runtime / differential verification: OPEN.
 */

void __fastcall FUN_00516be0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x1d4))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x1d4))();
    if (*(char *)(iVar1 + 0x2ac) != '\0') goto LAB_00516c0c;
  }
  (**(code **)(*param_1 + 0x100))();
LAB_00516c0c:
  (**(code **)(*param_1 + 0x48))();
  if ((*(int *)(param_1[0x2a] + 0x38) != 0x12) && (*(int *)(param_1[0x2a] + 0x38) != 0x14)) {
    FUN_00516a00(1);
  }
  return;
}
