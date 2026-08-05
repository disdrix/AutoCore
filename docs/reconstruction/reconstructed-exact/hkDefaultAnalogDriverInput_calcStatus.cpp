// =============================================================================
// hkDefaultAnalogDriverInput_calcStatus
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe520
// Address:   0x005fe520  (autoassault.exe, image base 0x400000)
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

/* WI-MOV-005: maps ctrl+0x20 raw pedal into status. Accel(-1)→+0xc |pedal|; positive→+0x10
   brake; +0x14 steer via FUN_005fdf20; +0x18=ctrl+0x24 handbrake; +0x19 reverse via FUN_005fe0b0.
   Same object as handle[8]/fw+0x14. Does NOT scale calcWheelTorque (AA has no engine consumer of
   +0xc). Live: brake_update reads +0x10/+0x18. */

void __fastcall hkDefaultAnalogDriverInput_calcStatus(int param_1)

{
  uint8_t *puVar1;
  float10 fVar2;
  float fVar3;
  uint32_t /* width from decompiler */ uStack_4;
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x14) == '\0') ||
     (*(char *)(param_1 + 0x3c) == '\0')) {
    fVar3 = *(float *)(param_1 + 0x20);
  }
  else {
    fVar3 = 0.0 - *(float *)(param_1 + 0x20);
  }
  if (fVar3 <= 0.0) {
    fVar3 = fVar3 * DAT_00aaa668;
  }
  else {
    fVar3 = 0.0;
  }
  *(float *)(param_1 + 0xc) = fVar3;
  if ((*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x14) == '\0') ||
     (*(char *)(param_1 + 0x3c) == '\0')) {
    fVar3 = *(float *)(param_1 + 0x20);
  }
  else {
    fVar3 = 0.0 - *(float *)(param_1 + 0x20);
  }
  if (fVar3 < 0.0) {
    fVar3 = 0.0;
  }
  *(float *)(param_1 + 0x10) = fVar3;
  uStack_4 = param_1;
  fVar2 = (float10)FUN_005fdf20();
  *(float *)(param_1 + 0x14) = (float)fVar2;
  *(uint8_t *)(param_1 + 0x18) = *(uint8_t *)(param_1 + 0x24);
  puVar1 = (uint8_t *)hkDefaultAnalogDriverInput_calcReverse((int)&uStack_4 + 3);
  *(uint8_t *)(param_1 + 0x19) = *puVar1;
  return;
}
