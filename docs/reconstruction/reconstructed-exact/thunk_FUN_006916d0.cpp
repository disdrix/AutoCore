// =============================================================================
// thunk_FUN_006916d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a0e90
// Address:   0x006a0e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __fastcall thunk_FUN_006916d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;
    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;
    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(param_1 + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    FUN_0056f570();
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
