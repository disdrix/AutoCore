// =============================================================================
// FUN_006e6480
// -----------------------------------------------------------------------------
// Stable ID: aa_006e6480
// Address:   0x006e6480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e6480 @ 0x006e6480
// Stable ID: aa_006e6480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006e6480.
//  - Return sites: 2.

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

void __thiscall FUN_006e6480(int param_1,int param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  int local_1c;

  

  local_34 = param_3[5];

  local_20 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

  local_1c = param_2;

  iVar4 = *(int *)(param_2 + 8);

  fVar1 = *param_3;

  fVar2 = param_3[1];

  fVar3 = param_3[2];

  local_30 = fVar1 * *(float *)(iVar4 + 0x20) +

             fVar2 * *(float *)(iVar4 + 0x30) + fVar3 * *(float *)(iVar4 + 0x40);

  local_2c = fVar1 * *(float *)(iVar4 + 0x24) +

             fVar2 * *(float *)(iVar4 + 0x34) + fVar3 * *(float *)(iVar4 + 0x44);

  local_24 = 0;

  local_28 = fVar1 * *(float *)(iVar4 + 0x28) +

             fVar2 * *(float *)(iVar4 + 0x38) + fVar3 * *(float *)(iVar4 + 0x48);

  fVar1 = -*(float *)(param_1 + 0x20);

  local_40 = local_30 * fVar1 + local_34 * *(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x10);

  local_3c = local_2c * fVar1 + local_34 * *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x14);

  local_38 = local_28 * fVar1 + local_34 * *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x18);

  (**(code **)(**(int **)(param_1 + 0x44) + 4))(&local_40);

  fVar1 = *(float *)(*(int *)(param_1 + 0x44) + 4);

  if (fVar1 < *(float *)(param_1 + 4)) {

    *(float *)(param_1 + 4) = fVar1;

    return;

  }

  *(float *)(param_1 + 4) = *(float *)(param_1 + 4);

  return;

}
