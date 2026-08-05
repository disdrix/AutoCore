// =============================================================================
// FUN_004e7640
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7640
// Address:   0x004e7640  (autoassault.exe, image base 0x400000)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e7640(int param_1,uint param_2,uint param_3,uint16_t *param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint16_t uVar4;
  float10 fVar5;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if ((param_2 < *(uint *)(iVar1 + 0x14)) && (param_3 < *(uint *)(iVar1 + 0x10))) {
    fVar2 = (float)(int)param_3;
    if ((int)param_3 < 0) {
      fVar2 = fVar2 + _DAT_00aaa5dc;
    }
    fVar3 = (float)(int)param_2;
    if ((int)param_2 < 0) {
      fVar3 = fVar3 + _DAT_00aaa5dc;
    }
    fVar5 = (float10)VehicleEngine_torqueCurve2D
                               (fVar3 * *(float *)(iVar1 + 0x18),fVar2 * *(float *)(iVar1 + 0x18));
    uVar4 = FUN_005c5950((float)fVar5);
    *param_4 = uVar4;
    return;
  }
  *param_4 = 0;
  return;
}
