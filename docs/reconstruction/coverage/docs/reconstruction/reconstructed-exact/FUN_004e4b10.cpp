// =============================================================================
// FUN_004e4b10
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4b10
// Address:   0x004e4b10  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004e4b10(int param_1,uint param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_2) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 2;
    }
    FUN_004e39d0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);
    return;
  }
  if (((iVar2 != 0) &&
      (pvVar3 = *(void **)(param_1 + 8), param_2 < (uint)((int)pvVar3 - iVar2 >> 2))) &&
     (_Dst = (void *)(iVar2 + param_2 * 4), _Dst != pvVar3)) {
    pvVar3 = memmove(_Dst,pvVar3,0);
    *(void **)(param_1 + 8) = pvVar3;
  }
  return;
}
