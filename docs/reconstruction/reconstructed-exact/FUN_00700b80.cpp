// =============================================================================
// FUN_00700b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00700b80
// Address:   0x00700b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700b80 @ 0x00700b80
// Stable ID: aa_00700b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00700810, FUN_00700940, FUN_00700b80, SQRT.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00700b80(int param_1,uint8_t *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  

  local_50 = -*(float *)(param_1 + 0x30);

  local_4c = -*(float *)(param_1 + 0x34);

  local_48 = -*(float *)(param_1 + 0x38);

  local_44 = -*(float *)(param_1 + 0x3c);

  fVar1 = local_50 * local_50 + local_4c * local_4c + local_48 * local_48;

  if (fVar1 < g_flMsToSeconds_Inferred != (fVar1 == g_flMsToSeconds_Inferred)) {

    local_50 = 0.0;

    local_4c = 1.0;

    local_48 = 0.0;

    local_44 = 0.0;

  }

  FUN_00700940(&local_50,&local_40);

  FUN_00700810(&local_40);

  pfVar4 = *(float **)(param_1 + 0x50);

  fVar1 = pfVar4[2] * pfVar4[2] + pfVar4[1] * pfVar4[1] + *pfVar4 * *pfVar4;

  if (fVar1 < _DAT_00a0f010 != (fVar1 == _DAT_00a0f010)) {

    fVar1 = pfVar4[2];

    fVar2 = pfVar4[1];

    fVar3 = *pfVar4;

    *param_3 = local_50;

    param_3[1] = local_4c;

    param_3[2] = local_48;

    param_3[3] = local_44;

    param_3[8] = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);

    param_3[4] = local_40;

    param_3[5] = local_3c;

    param_3[6] = local_38;

    param_3[7] = local_34;

    param_3[9] = 0.5;

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
