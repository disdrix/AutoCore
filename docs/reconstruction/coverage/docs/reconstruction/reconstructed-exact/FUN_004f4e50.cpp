// =============================================================================
// FUN_004f4e50
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4e50
// Address:   0x004f4e50  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall FUN_004f4e50(int param_1)

{
  int *piVar1;
  int iVar2;
  uint32_t /* width from decompiler */ uVar3;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if (*(int *)(piVar1[0x2a] + 0x38) == 0x12) {
    iVar2 = (**(code **)(*piVar1 + 0x1d8))();
                    /* WARNING: Could not recover jumptable at 0x004f4e7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))();
    return uVar3;
  }
  if (*(int *)(piVar1[0x2a] + 0x38) == 0x14) {
    iVar2 = (**(code **)(*piVar1 + 0x1dc))();
                    /* WARNING: Could not recover jumptable at 0x004f4e9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))();
    return uVar3;
  }
  return 0;
}
