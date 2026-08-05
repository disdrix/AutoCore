// =============================================================================
// hkAngularVelocityDamper_update
// -----------------------------------------------------------------------------
// Stable ID: aa_0064d810
// Address:   0x0064d810  (autoassault.exe, image base 0x400000)
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

void __thiscall hkAngularVelocityDamper_update(int param_1,float *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint8_t local_21;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar1 = *(int *)(param_3 + 0x30);
  iVar2 = *(int *)(iVar1 + 0x3c);
  local_1c = *(float *)(iVar2 + 0x54);
  local_18 = *(float *)(iVar2 + 0x58);
  local_20 = *(float *)(iVar2 + 0x50);
  if (local_18 * local_18 + local_1c * local_1c + local_20 * local_20 <=
      *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10)) {
    local_14 = *(float *)(param_1 + 8) * *param_2;
  }
  else {
    local_14 = *(float *)(param_1 + 0xc) * *param_2;
  }
  local_14 = g_flOne - local_14;
  if (local_14 < 0.0) {
    local_14 = 0.0;
  }
  local_20 = local_20 * local_14;
  local_1c = local_1c * local_14;
  local_18 = local_18 * local_14;
  local_14 = *(float *)(iVar2 + 0x5c) * local_14;
  pcVar3 = (char *)FUN_005070b0(&local_21);
  if ((*pcVar3 == '\0') && (*(int *)(iVar1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(iVar1 + 0x3c) + 0x54))(&local_20);
  return;
}
