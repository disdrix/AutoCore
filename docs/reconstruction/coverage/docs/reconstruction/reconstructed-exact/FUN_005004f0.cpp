// =============================================================================
// FUN_005004f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005004f0
// Address:   0x005004f0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_005004f0(int param_1)

{
  uint uVar1;
  
  if ((DAT_00b036d4 != (int *)0x0) && (*DAT_00b036d4 != 0)) {
    for (uVar1 = 0;
        (*(int *)(param_1 + 0x394) != 0 &&
        (uVar1 < (uint)(*(int *)(param_1 + 0x398) - *(int *)(param_1 + 0x394) >> 2)));
        uVar1 = uVar1 + 1) {
      FUN_004b4b60(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x394) + uVar1 * 4));
    }
    FUN_005066c0(0,0);
  }
  FUN_004f7d60();
  FUN_0053e330();
  return;
}
