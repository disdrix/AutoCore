// =============================================================================
// thunk_FUN_005a6840
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6b60
// Address:   0x005e6b60  (autoassault.exe, image base 0x400000)
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

void __thiscall thunk_FUN_005a6840(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piStack_24;
  uint32_t /* width from decompiler */ uStack_20;
  int *piStack_1c;
  uint32_t /* width from decompiler */ uStack_18;
  
  uStack_18 = 4;
  piStack_1c = param_1 + 0x4d;
  uStack_20 = 0x5a685b;
  (**(code **)(*param_2 + 0x14))();
  uStack_20 = 0xc;
  piStack_24 = param_1 + 0x50;
  (**(code **)(*param_2 + 0x14))();
  (**(code **)(*param_2 + 0x14))(param_1 + 0xc,0x104);
  (**(code **)(*param_2 + 0x14))(&stack0xffffffec,4);
  FUN_00410420(0,0);
  FUN_005a6ae0(piStack_1c);
  iVar3 = 0;
  if (0 < (int)piStack_1c) {
    do {
      (**(code **)(*param_2 + 0x14))(&piStack_24,4);
      iVar1 = param_1[9];
      if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 2) <= (uint)(param_1[10] - iVar1 >> 2))) {
        FUN_004073a0(param_1[10],1,&piStack_24);
      }
      else {
        piVar2 = (int *)param_1[10];
        *piVar2 = (int)piStack_24;
        param_1[10] = (int)(piVar2 + 1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)piStack_1c);
  }
  (**(code **)(*param_1 + 0x74))(param_1 + 0xc);
  return;
}
