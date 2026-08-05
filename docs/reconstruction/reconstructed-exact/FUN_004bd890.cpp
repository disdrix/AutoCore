// =============================================================================
// FUN_004bd890
// -----------------------------------------------------------------------------
// Stable ID: aa_004bd890
// Address:   0x004bd890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bd890 @ 0x004bd890
// Stable ID: aa_004bd890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004cd220×4, FUN_004bd890, FUN_0074b590, FUN_0074b700, FUN_0074b8f0.
//  - Return sites: 1.

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

void __thiscall FUN_004bd890(int param_1,int param_2,float param_3)



{

  float *pfVar1;

  float10 fVar2;

  float10 fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_2c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  *(float *)(param_1 + 0x5ac) = param_3;

  *(int *)(param_1 + 0x5a8) = param_2;

  fVar4 = DAT_00aefa50 * DAT_00a0f298;

  fVar5 = (float)(int)param_3;

  pfVar1 = (float *)(param_1 + 0x598);

  fVar6 = fVar5 * DAT_00aefa50;

  *pfVar1 = (float)param_2 * DAT_00aefa50;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c) = 0;

  *(float *)(param_1 + 0x5a0) = fVar6;

  fVar2 = (float10)FUN_004cd220(*pfVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0));

  fVar3 = (float10)FUN_004cd220(*pfVar1,*(float *)(param_1 + 0x5a0) + DAT_00aefa50);

  fVar6 = (float)fVar3;

  local_2c = (float)fVar2;

  if (fVar6 <= (float)fVar2) {

    local_2c = fVar6;

  }

  param_3 = (float)fVar2;

  if ((float)fVar2 <= fVar6) {

    param_3 = fVar6;

  }

  fVar2 = (float10)FUN_004cd220(*pfVar1 + DAT_00aefa50,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0));

  fVar6 = (float)fVar2;

  if (fVar6 <= local_2c) {

    local_2c = fVar6;

  }

  if (param_3 <= fVar6) {

    param_3 = fVar6;

  }

  fVar2 = (float10)FUN_004cd220(*pfVar1 + DAT_00aefa50,*(float *)(param_1 + 0x5a0) + DAT_00aefa50);

  local_10 = DAT_00aaa688;

  fVar6 = (float)fVar2;

  if (fVar6 <= local_2c) {

    local_2c = fVar6;

  }

  if (param_3 <= fVar6) {

    param_3 = fVar6;

  }

  local_14 = param_3 + (float)g_nInferredThreatDefault;

  *pfVar1 = *pfVar1 + fVar4;

  *(float *)(param_1 + 0x5a0) = *(float *)(param_1 + 0x5a0) + fVar4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c);

  fVar6 = (float)*(int *)(param_1 + 0x5a8) * DAT_00aefa50;

  fVar5 = fVar5 * DAT_00aefa50;

  local_18 = fVar6 + fVar4 + local_10;

  local_c = (fVar6 - fVar4) - local_10;

  local_4 = (fVar5 - fVar4) - local_10;

  local_10 = fVar5 + fVar4 + local_10;

  local_8 = local_2c;

  FUN_0074b8f0(&local_c,&local_18);

  FUN_0074b590(pfVar1,0x3c23d70a);

  FUN_0074b700(param_1 + 0x474);

  return;

}
