// =============================================================================
// FUN_004f79d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f79d0
// Address:   0x004f79d0  (autoassault.exe, image base 0x400000)
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

void FUN_004f79d0(int param_1,float param_2)

{
  short sVar1;
  uint uVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  
  uVar2 = *(uint *)((int)param_2 + 0xe6d8);
  iVar5 = *(int *)((int)param_2 + 0xe6dc);
  *(uint *)((int)param_2 + 0xe6dc) = iVar5 + (uint)(0xfffffffe < uVar2);
  *(uint *)((int)param_2 + 0xe6d8) = uVar2 + 1;
  FUN_00512160(uVar2,iVar5,0);
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x218))(param_2);
  psVar4 = (short *)(param_1 + 0x130);
  bVar3 = false;
  iVar5 = (param_1 + 0x124) - (int)psVar4;
  iVar6 = 6;
  do {
    *(short *)(iVar5 + (int)psVar4) =
         (short)(int)((float)(int)*(short *)(iVar5 + (int)psVar4) * param_2);
    sVar1 = *psVar4;
    sVar7 = (short)(int)((float)(int)sVar1 * param_2);
    *psVar4 = sVar7;
    if (0.0 < (float)(int)sVar1 * param_2) {
      bVar3 = true;
    }
    if ((sVar7 < 1) && (!bVar3)) {
      bVar3 = true;
      *psVar4 = 1;
    }
    psVar4 = psVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (param_2 < g_flOne) {
    iVar5 = FUN_0056a680(0);
    param_2 = g_flOne - param_2;
    iVar6 = FUN_0056a680(0);
    FUN_0056a1b0((int)((float)iVar5 * param_2 + (float)iVar6));
  }
  return;
}
