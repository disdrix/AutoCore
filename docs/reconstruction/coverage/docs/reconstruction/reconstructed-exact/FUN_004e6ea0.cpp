// =============================================================================
// FUN_004e6ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e6ea0
// Address:   0x004e6ea0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004e6ea0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4) + 4);
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0xc);
      FUN_004e6ee0(iVar1);
      iVar1 = iVar2;
    }
    iVar1 = uVar3 * 4;
    uVar3 = uVar3 + 1;
    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar3 <= *(uint *)(param_1 + 8));
  return;
}
