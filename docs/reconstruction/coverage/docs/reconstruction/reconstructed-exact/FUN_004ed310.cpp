// =============================================================================
// FUN_004ed310
// -----------------------------------------------------------------------------
// Stable ID: aa_004ed310
// Address:   0x004ed310  (autoassault.exe, image base 0x400000)
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

uint FUN_004ed310(int param_1,char *param_2,uint *param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int local_8;
  uint local_4;
  
  if (*(int *)(DAT_00d1f050 + 0x6c) == 0) {
    return CONCAT31((int3)((uint)DAT_00d1f050 >> 8),1);
  }
  if (((int)*param_3 < 0) || (*(uint *)(param_1 + 0x10) <= *param_3)) {
    *param_3 = 0;
  }
  iVar5 = param_1;
  uVar6 = *(int *)(param_1 + 0xc) + *param_3;
LAB_004ed348:
  do {
    while( true ) {
      uVar3 = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
      if ((iVar5 == param_1) && (uVar6 == uVar3)) {
        *param_3 = 0;
        *param_2 = '\0';
        return CONCAT31((int3)(uVar3 >> 8),1);
      }
      uVar3 = uVar6 >> 2;
      iVar1 = uVar3 * -4;
      if (*(uint *)(iVar5 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(iVar5 + 8);
      }
      iVar1 = *(int *)(*(int *)(iVar5 + 4) + uVar3 * 4) + (uVar6 + iVar1) * 4;
      cVar2 = FUN_00971900(iVar1,0);
      if (cVar2 == '\0') break;
      if (*param_2 != '\0') {
        FUN_00971030(iVar1);
      }
      FUN_0043df90(&local_8,iVar5,uVar6,iVar5,uVar6 + 1);
      iVar5 = local_8;
      uVar6 = local_4;
    }
    if (*param_2 == '\0') {
      cVar2 = FUN_0075d610(iVar1);
      if (cVar2 == '\0') {
        cVar2 = FUN_00971a20(iVar1,0);
        if (cVar2 == '\0') {
          FUN_009717a0(iVar1);
          *param_2 = '\x01';
          pcVar4 = param_2;
LAB_004ed447:
          return (uint)pcVar4 & 0xffffff00;
        }
      }
    }
    else {
      cVar2 = FUN_0075d610(iVar1);
      if (cVar2 == '\0') {
        pcVar4 = (char *)FUN_00971a20(iVar1,0);
        if ((char)pcVar4 == '\0') goto LAB_004ed447;
        *param_3 = *param_3 + 1;
        uVar6 = uVar6 + 1;
        goto LAB_004ed348;
      }
    }
    *param_3 = *param_3 + 1;
    uVar6 = uVar6 + 1;
  } while( true );
}
