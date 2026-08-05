// =============================================================================
// thunk_FUN_0065e1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065e2c0
// Address:   0x0065e2c0  (autoassault.exe, image base 0x400000)
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

void __thiscall thunk_FUN_0065e1e0(int param_1,char *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (int)*param_2;
  piVar1 = (int *)(param_1 + 0x10);
  *(int *)(param_1 + 0xc) = iVar5;
  iVar3 = *(int *)(param_1 + 0x14);
  if (iVar3 < iVar5) {
    uVar2 = *(uint *)(param_1 + 0x18) & 0x7fffffff;
    if ((int)uVar2 < iVar5) {
      iVar4 = uVar2 * 2;
      if (iVar4 <= iVar5) {
        iVar4 = iVar5;
      }
      FUN_005b3300(piVar1,iVar4,4);
    }
    if (3 < iVar5 - iVar3) {
      do {
        *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar3 * 4) = 0;
        *(uint32_t /* width from decompiler */ *)(*piVar1 + 4 + iVar3 * 4) = 0;
        *(uint32_t /* width from decompiler */ *)(*piVar1 + 8 + iVar3 * 4) = 0;
        *(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc + iVar3 * 4) = 0;
        iVar3 = iVar3 + 4;
      } while (iVar3 < iVar5 + -3);
    }
    for (; iVar3 < iVar5; iVar3 = iVar3 + 1) {
      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar3 * 4) = 0;
    }
  }
  *(int *)(param_1 + 0x14) = iVar5;
  iVar3 = *(int *)(param_1 + 0xc);
  iVar5 = *(int *)(param_1 + 0x20);
  if (iVar5 < iVar3) {
    uVar2 = *(uint *)(param_1 + 0x24) & 0x7fffffff;
    if ((int)uVar2 < iVar3) {
      iVar4 = uVar2 * 2;
      if (iVar4 <= iVar3) {
        iVar4 = iVar3;
      }
      FUN_005b3300((int *)(param_1 + 0x1c),iVar4,1);
    }
    for (; iVar5 < iVar3; iVar5 = iVar5 + 1) {
      *(uint8_t *)(iVar5 + *(int *)(param_1 + 0x1c)) = 0;
    }
  }
  *(int *)(param_1 + 0x20) = iVar3;
  return;
}
