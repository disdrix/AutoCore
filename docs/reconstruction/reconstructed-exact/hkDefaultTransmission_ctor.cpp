// =============================================================================
// hkDefaultTransmission_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_0064f610
// Address:   0x0064f610  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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

uint32_t /* width from decompiler */ * __thiscall hkDefaultTransmission_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)

{
  uint32_t /* width from decompiler */ uVar1;
  
  FUN_0065e460(param_2);
  uVar1 = DAT_00aaa668;
  *param_1 = &PTR_FUN_009e4dac;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0x80000000;
  param_1[0x15] = 0x80000000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  *(uint8_t *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[0x17] = uVar1;
  *(uint8_t *)(param_1 + 0x16) = 0;
  FUN_0064f100(param_2);
  return param_1;
}
