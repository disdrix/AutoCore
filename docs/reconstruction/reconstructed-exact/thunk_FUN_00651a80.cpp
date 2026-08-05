// =============================================================================
// thunk_FUN_00651a80
// -----------------------------------------------------------------------------
// Stable ID: aa_006368e0
// Address:   0x006368e0  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_00651a80(uint32_t /* width from decompiler */ *param_1)

{
  uint32_t /* width from decompiler */ *puVar1;
  
  *param_1 = &PTR_FUN_009e3a90;
  param_1[2] = &PTR_LAB_009e3a7c;
  if (param_1[3] != 0) {
    FUN_005071c0(param_1);
    puVar1 = (uint32_t /* width from decompiler */ *)param_1[3];
    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
    if (*(short *)((int)puVar1 + 6) == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  if (param_1[4] != 0) {
    FUN_005071c0(param_1);
    puVar1 = (uint32_t /* width from decompiler */ *)param_1[4];
    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
    if (*(short *)((int)puVar1 + 6) == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  param_1[2] = &PTR_LAB_009e3a68;
  *param_1 = &PTR_FUN_009d81e8;
  if ((short)*(ushort *)(param_1 + 1) < 0) {
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;
    FUN_005ffdb0(0);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
