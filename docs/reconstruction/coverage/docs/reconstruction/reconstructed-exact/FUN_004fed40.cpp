// =============================================================================
// FUN_004fed40
// -----------------------------------------------------------------------------
// Stable ID: aa_004fed40
// Address:   0x004fed40  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004fed40(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)

{
  int iVar1;
  uint32_t /* width from decompiler */ *puVar2;
  
  FUN_005cae70(param_2,param_3);
  FUN_004ce940();
  iVar1 = FUN_00404d70(param_2);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x3c) == 0) {
      FUN_004f1e20(1,1);
    }
    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x3c) + 0x4c0);
    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {
      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00508bb0(*puVar2);
      if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {
        (**(code **)*puVar2)(param_1 + -0x670,param_3,1);
        return 1;
      }
    }
  }
  return 0;
}
