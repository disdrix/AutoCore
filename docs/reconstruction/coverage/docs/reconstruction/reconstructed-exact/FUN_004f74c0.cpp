// =============================================================================
// FUN_004f74c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f74c0
// Address:   0x004f74c0  (autoassault.exe, image base 0x400000)
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

int __fastcall FUN_004f74c0(int param_1)

{
  float fVar1;
  byte bVar2;
  int *piVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  double dVar8;
  
  fVar7 = DAT_00a110d8;
  piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if (piVar3 == (int *)0x0) {
    return (int)DAT_00a110d8;
  }
  iVar5 = (**(code **)(*piVar3 + 0x1dc))();
  if (iVar5 != 0) {
    if (*(int *)(param_1 + 0x268) == 0) {
      fVar7 = 0.0;
    }
    else {
      fVar7 = (float)*(int *)(*(int *)(param_1 + 0x268) + 0xb4);
    }
    bVar2 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +
                     0x531);
    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x27c))();
    fVar1 = *(float *)(&DAT_009cd0c8 + (uint)bVar2 * 4);
    sVar4 = FUN_004c4140();
    fVar7 = (float)iVar6 * fVar1 + (float)(int)sVar4 * g_flLevelUpUiBase_Inferred + fVar7;
    dVar8 = ceil((double)(*(float *)(iVar5 + 0x134) * fVar7 + fVar7 + (float)*(int *)(iVar5 + 0x138)
                         + (float)*(int *)(param_1 + 0x1dc)));
    return (int)dVar8;
  }
  return (int)fVar7;
}
