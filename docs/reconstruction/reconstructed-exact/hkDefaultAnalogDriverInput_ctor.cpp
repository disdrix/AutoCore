// =============================================================================
// hkDefaultAnalogDriverInput_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe020
// Address:   0x005fe020  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
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

void __thiscall hkDefaultAnalogDriverInput_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = g_flOne;
  *(uint8_t *)(param_1 + 6) = 0;
  *(uint8_t *)((int)param_1 + 0x19) = 0;
  *(uint8_t *)(param_1 + 9) = 0;
  *(uint8_t *)((int)param_1 + 0x25) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(uint16_t *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dd368;
  param_1[10] = *param_2;
  param_1[0xe] = param_2[2];
  param_1[0xb] = param_2[1];
  fVar2 = (float)param_1[0xb] * ((float)param_1[10] - (float)param_1[0xe]);
  *(uint8_t *)(param_1 + 0xf) = *(uint8_t *)(param_2 + 3);
  param_1[0xd] = fVar2;
  param_1[0xc] = (fVar1 - fVar2) /
                 ((fVar1 - (float)param_1[0xe]) - ((float)param_1[10] - (float)param_1[0xe]));
  return;
}
