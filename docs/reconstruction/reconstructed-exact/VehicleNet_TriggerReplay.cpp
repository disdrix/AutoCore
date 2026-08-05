// =============================================================================
// VehicleNet_TriggerReplay
// -----------------------------------------------------------------------------
// Stable ID: aa_005f9ed0
// Address:   0x005f9ed0  (autoassault.exe, image base 0x400000)
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

void VehicleNet_TriggerReplay(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint param_3)

{
  uint32_t /* width from decompiler */ *puVar1;
  uint uVar2;
  uint32_t /* width from decompiler */ *puVar3;
  
  puVar1 = malloc(param_3);
  puVar3 = puVar1;
  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(uint8_t *)puVar3 = *(uint8_t *)param_1;
    param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);
    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);
  }
  VehicleNet_PostCorrectionEvent(puVar1,param_2,param_3);
  return;
}
