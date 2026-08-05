// =============================================================================
// FUN_004f6940
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6940
// Address:   0x004f6940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_004f6940(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
switchD_004f6977_caseD_1:
    return 8;
  }
  switch(*(uint16_t *)
          (*(int *)(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x3c) + 0x3f4)) {
  case 0:
    return 0xc;
  default:
    goto switchD_004f6977_caseD_1;
  case 7:
  case 8:
    break;
  case 10:
    iVar1 = *(int *)(param_1 + 0x26c);
    if (((iVar1 != 0) && (param_3 != (int *)0x0)) &&
       (iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1, *param_3 = iVar1,
       iVar1 == *(int *)(param_2[1] + 4) + 4 + (int)param_2)) {
      return 3;
    }
    break;
  case 0xb:
    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
    if ((iVar1 != 0) &&
       (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))
                          (0), *(char *)(iVar1 + 0x6b8) != '\0')) {
      return 0xd;
    }
    iVar1 = *(int *)(param_1 + 0x270);
    if (((iVar1 != 0) && (param_2 != (int *)0x0)) &&
       (iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1, *param_2 = iVar1,
       iVar1 == *(int *)(param_2[1] + 4) + 4 + (int)param_2)) {
      return 3;
    }
  }
  return 0;
}
