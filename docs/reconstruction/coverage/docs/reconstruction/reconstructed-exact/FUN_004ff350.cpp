// =============================================================================
// FUN_004ff350
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff350
// Address:   0x004ff350  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004ff350(int param_1,uint32_t /* width from decompiler */ param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    cVar2 = (char)param_2;
    if (*(int *)(iVar3 + *(int *)(param_1 + 0x260)) != 0) {
      if (cVar2 == '\0') {
        iVar1 = *(int *)(iVar3 + *(int *)(param_1 + 0x260));
        FUN_004fbb50(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);
      }
      else {
        iVar1 = *(int *)(iVar3 + *(int *)(param_1 + 0x260));
        FUN_004fdcb0(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);
      }
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0xc);
  if (cVar2 == '\0') {
    FUN_004fbb50(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
  }
  else {
    FUN_004fdcb0(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
  }
  if (*(int *)(param_1 + 0x254) != 0) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x254) + 4) + 4) + 4 + *(int *)(param_1 + 0x254);
    if (cVar2 == '\0') {
      FUN_004fbb50(iVar3);
    }
    else {
      FUN_004fdcb0(iVar3);
    }
  }
  if (*(int *)(param_1 + 0x268) != 0) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x268) + 4) + 4) + 4 + *(int *)(param_1 + 0x268);
    if (cVar2 == '\0') {
      FUN_004fbb50(iVar3);
    }
    else {
      FUN_004fdcb0(iVar3);
    }
  }
  if (*(int *)(param_1 + 0x26c) != 0) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x26c) + 4) + 4) + 4 + *(int *)(param_1 + 0x26c);
    if (cVar2 == '\0') {
      FUN_004fbb50(iVar3);
    }
    else {
      FUN_004fdcb0(iVar3);
    }
    if (*(int *)(param_1 + 0x26c) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x26c) + 4) + 4) + 4 + *(int *)(param_1 + 0x26c);
    }
    FUN_004fe380(iVar3,param_2);
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x270) + 4) + 4) + 4 + *(int *)(param_1 + 0x270);
    if (cVar2 == '\0') {
      FUN_004fbb50(iVar3);
    }
    else {
      FUN_004fdcb0(iVar3);
    }
    if (*(int *)(param_1 + 0x270) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x270) + 4) + 4) + 4 + *(int *)(param_1 + 0x270);
    }
    FUN_004fe380(iVar3,param_2);
  }
  iVar3 = *(int *)(param_1 + 0x264);
  if (iVar3 != 0) {
    iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;
    if (cVar2 != '\0') {
      FUN_004fdcb0(iVar3);
      return;
    }
    FUN_004fbb50(iVar3);
  }
  return;
}
