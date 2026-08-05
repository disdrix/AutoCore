// =============================================================================
// FUN_004f4eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4eb0
// Address:   0x004f4eb0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f4eb0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(iVar1 + *(int *)(param_1 + 0x260)) != 0) {
      FUN_0056a260(0);
      FUN_0056b400(0);
      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x260)) + 0x18))(0);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  return;
}
