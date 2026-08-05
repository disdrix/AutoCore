// =============================================================================
// FUN_004f3e40
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3e40
// Address:   0x004f3e40  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f3e40(int param_1,int *param_2)

{
  int iVar1;
  uint32_t /* width from decompiler */ uVar2;
  void *pvVar3;
  char acStack_64 [100];
  
  iVar1 = param_2[0x4a];
  FUN_004cf320(iVar1);
  iVar1 = FUN_00568640(iVar1);
  if ((iVar1 != 0) && (99 < *(short *)(iVar1 + 0x12))) {
    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x15c))();
    sprintf(acStack_64,"%S %s",iVar1 + 0x16,uVar2);
    FUN_00516720(acStack_64);
  }
  (**(code **)(param_2[0x10] + 0x18))(0);
  (**(code **)(*param_2 + 4))();
  if (*(int *)(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x38) != 0x14) {
    FUN_0053d970(1);
    if (*(char *)((int)param_2 + 0x30b) != '\0') {
      pvVar3 = NDSpecialFX_LoadFromScriptName("generic_elite",-1,0);
      if (pvVar3 != (void *)0x0) {
        (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xf8))
                  (pvVar3,1,0);
      }
    }
  }
  return;
}
