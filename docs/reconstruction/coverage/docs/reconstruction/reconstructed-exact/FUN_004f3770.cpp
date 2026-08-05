// =============================================================================
// FUN_004f3770
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3770
// Address:   0x004f3770  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f3770(int param_1)

{
  void *pvVar1;
  int iVar2;
  uint32_t /* width from decompiler */ uVar3;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2c4b;
  pvStack_c = ExceptionList;
  uVar3 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = param_1;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 700))(0);
  pvVar1 = operator_new(0xf8);
  puStack_8 = (uint8_t *)0x0;
  if (pvVar1 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f57e0(uVar3,pvVar1,iVar2);
  }
  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x658 + param_1) = uVar3;
  puStack_8 = (uint8_t *)0xffffffff;
  iVar2 = 0;
  if (param_1 != 0x670) {
    iVar2 = *(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1;
  }
  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x658 + param_1) + 0x2c))
            (iVar2);
  ExceptionList = pvVar1;
  return;
}
