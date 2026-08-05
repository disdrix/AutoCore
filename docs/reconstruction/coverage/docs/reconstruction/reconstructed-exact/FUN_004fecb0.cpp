// =============================================================================
// FUN_004fecb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004fecb0
// Address:   0x004fecb0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004fecb0(int param_1)

{
  int iVar1;
  int iVar2;
  uint32_t /* width from decompiler */ *puVar3;
  void *pvVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x3ac) != 0) {
    uVar5 = 0;
    while( true ) {
      iVar1 = *(int *)(param_1 + 0x3ac);
      iVar2 = *(int *)(iVar1 + 4);
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar2 >> 2) <= uVar5)) break;
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar2 >> 2) <= uVar5)) {
        FUN_005062a0();
        return;
      }
      puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + uVar5 * 4);
      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {
        (**(code **)*puVar3)(1);
      }
      uVar5 = uVar5 + 1;
    }
  }
  pvVar4 = *(void **)(param_1 + 0x3ac);
  if (pvVar4 == (void *)0x0) {
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ac) = 0;
    return;
  }
  if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)pvVar4 + 4));
  }
  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 4) = 0;
  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 8) = 0;
  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar4);
}
