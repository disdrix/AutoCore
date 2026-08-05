// =============================================================================
// FUN_004f6560
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6560
// Address:   0x004f6560  (autoassault.exe, image base 0x400000)
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

uint __fastcall FUN_004f6560(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if (*(char *)(uVar1 + 0x7e) != '\0') {
    return uVar1 & 0xffffff00;
  }
  piVar3 = *(int **)(param_1 + 0x260);
  iVar2 = 0;
  do {
    if (*piVar3 != 0) goto LAB_004f65d2;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 3);
  if (((*(int *)(param_1 + 0x264) == 0) &&
      (((iVar2 = *(int *)(param_1 + 600), iVar2 == 0 || (*(char *)(iVar2 + 0xcc) != '\0')) &&
       (*(int *)(param_1 + 0x254) == 0)))) &&
     ((*(int *)(param_1 + 0x268) == 0 && (*(int *)(param_1 + 0x270) == 0)))) {
    return CONCAT31((int3)((uint)iVar2 >> 8),*(int *)(param_1 + 0x26c) != 0);
  }
LAB_004f65d2:
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}
