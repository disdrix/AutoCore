// =============================================================================
// FUN_004e87d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e87d0
// Address:   0x004e87d0  (autoassault.exe, image base 0x400000)
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

void FUN_004e87d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)

{
  uint32_t /* width from decompiler */ uVar1;
  uint32_t /* width from decompiler */ uVar2;
  uint32_t /* width from decompiler */ uVar3;
  
  uVar1 = param_2[3];
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}
