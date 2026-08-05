// =============================================================================
// FUN_00918a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00918a70
// Address:   0x00918a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00918a70 @ 0x00918a70
// Stable ID: aa_00918a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: SQRT×2, FUN_004cd220, FUN_004e88e0, FUN_005a5970, FUN_00918a70.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00918a70(float *param_1,float *param_2)



{

  float fVar1;

  float *in_EAX;

  float *pfVar2;

  int iVar3;

  float *unaff_EDI;

  float10 fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  uint8_t local_50 [24];

  float local_38 [13];

  

  local_54 = g_flOne;

  local_60 = 0.0;

  local_5c = 0.0;

  local_58 = 0.0;

  local_64 = 0.0;

  local_38[0] = 0.0;

  local_38[1] = 0.0;

  local_38[2] = 0.0;

  local_38[3] = 0.0 - *in_EAX;

  local_38[4] = *in_EAX;

  local_38[5] = 0.0;

  local_38[6] = 0.0;

  local_38[7] = *in_EAX;

  local_38[8] = 0.0 - *in_EAX;

  local_38[9] = 0.0;

  iVar3 = 0;

  do {

    fVar4 = (float10)FUN_004cd220(*unaff_EDI + local_38[iVar3 * 2],

                                  local_38[iVar3 * 2 + 1] + unaff_EDI[2]);

    local_64 = (float)(fVar4 + (float10)local_64);

    pfVar2 = (float *)FUN_005a5970(local_50,*unaff_EDI + local_38[iVar3 * 2],

                                   local_38[iVar3 * 2 + 1] + unaff_EDI[2]);

    local_60 = *pfVar2 + local_60;

    local_5c = pfVar2[1] + local_5c;

    local_58 = pfVar2[2] + local_58;

    local_54 = pfVar2[3] + local_54;

    iVar3 = iVar3 + 1;

  } while (iVar3 < 5);

  unaff_EDI[1] = local_64 * DAT_00a0f70c + _DAT_009d8238 + g_flMultiKillCountBlend;

  pfVar2 = (float *)FUN_004e88e0(local_50,&local_60);

  *param_1 = *pfVar2;

  param_1[1] = pfVar2[1];

  param_1[2] = pfVar2[2];

  fVar1 = DAT_00aaa640;

  fVar6 = g_flOne;

  fVar5 = SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);

  if ((_DAT_00a240ec <= fVar5) || (fVar5 <= DAT_00aaa640)) {

    fVar5 = g_flOne / fVar5;

    *param_1 = *param_1 * fVar5;

    param_1[1] = param_1[1] * fVar5;

    param_1[2] = fVar5 * param_1[2];

  }

  fVar7 = *param_1 * DAT_00afdfdc;

  fVar9 = DAT_00afdfd4 * param_1[2];

  fVar8 = param_1[1] * DAT_00afdfd4;

  fVar5 = *param_1 * DAT_00afdfd8;

  *param_2 = DAT_00afdfd8 * param_1[2] - param_1[1] * DAT_00afdfdc;

  param_2[1] = fVar7 - fVar9;

  param_2[2] = fVar8 - fVar5;

  fVar5 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);

  if ((_DAT_00a240ec <= fVar5) || (fVar5 <= fVar1)) {

    fVar6 = fVar6 / fVar5;

    *param_2 = *param_2 * fVar6;

    param_2[1] = param_2[1] * fVar6;

    param_2[2] = param_2[2] * fVar6;

  }

  return;

}
