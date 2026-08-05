// =============================================================================
// FUN_004f8e00
// -----------------------------------------------------------------------------
// Stable ID: aa_004f8e00
// Address:   0x004f8e00  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004f8e00(int param_1,uint param_2,uint param_3,char param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int local_8;
  uint32_t /* width from decompiler */ local_4;
  
  if ((param_2 == 0xffffffff) || (bVar2 = true, param_2 == *(uint *)(param_1 + 0x1a8))) {
    bVar2 = false;
  }
  if ((param_3 == 0xffffffff) || (bVar3 = true, param_3 == *(uint *)(param_1 + 0x1ac))) {
    bVar3 = false;
  }
  if ((!bVar2) && (!bVar3)) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x2b0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar7 = 0;
  iVar8 = 0;
  local_4 = 0;
  local_8 = 0;
  if (*(int *)(iVar1 + 0x50) != 0) {
    FUN_004294f0();
    iVar5 = FUN_004022a0(&local_4,&local_8);
    iVar4 = iVar7;
    while (iVar7 = iVar4, iVar5 == 0) {
      if ((local_8 != 0) && (*(short *)(*(int *)(*(int *)(local_8 + 0xa8) + 0x3c) + 0x3f4) == 8)) {
        uVar6 = *(uint *)(local_8 + 200) & ((int)*(uint *)(local_8 + 200) < 0) - 1;
        if ((((!bVar2) || ((iVar4 != 0 || (iVar7 = local_8, param_2 != uVar6)))) &&
            (iVar7 = iVar4, bVar3)) && ((iVar8 == 0 && (param_3 == uVar6)))) {
          iVar8 = local_8;
        }
        if (((!bVar2) || (iVar7 != 0)) && ((!bVar3 || (iVar8 != 0)))) break;
      }
      iVar5 = FUN_004022a0(&local_4,&local_8);
      iVar4 = iVar7;
    }
    if (*(char *)(iVar1 + 0x54) != '\0') {
      *(uint8_t *)(iVar1 + 0x54) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x30));
    }
  }
  if (((!bVar2) || (iVar7 != 0)) && ((!bVar3 || (iVar8 != 0)))) {
    if (param_4 != '\0') {
      if (iVar7 != 0) {
        FUN_00571d80(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x164),0);
        FUN_004d4790(iVar7);
      }
      if (iVar8 != 0) {
        FUN_00571d80(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x164),0);
        FUN_004d4790(iVar8);
      }
    }
    return 1;
  }
  return 0;
}
