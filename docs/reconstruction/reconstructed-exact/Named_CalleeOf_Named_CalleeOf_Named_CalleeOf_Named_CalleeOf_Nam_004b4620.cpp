// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b4620
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4620
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x004b4620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×11, return×5.
//  - Notable callees: FUN_004b0f80×2, FUN_004cd220×2, ABS, FUN_004b1100, FUN_004b18f0, FUN_004b2b90, FUN_004b4620, FUN_0076f5f0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b4620(int *param_1,float param_2,float param_3)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  float10 fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  uint32_t /* width from decompiler */ local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar3 = (int)param_2;

  *(int *)(DAT_00d17958 + 0x13c) = *(int *)(DAT_00d17958 + 0x13c) + 1;

  iVar2 = *param_1;

  if (((*(byte *)(iVar2 + 0x98c) & 0x40) != 0) &&

     ((*(char *)(iVar2 + 0x7f9) != '\0' || (*(char *)(iVar2 + 0x7fa) != '\0')))) {

    return 0;

  }

  local_28 = 0;

  if ((*(float *)(iVar2 + 0x980) != g_flZero) &&

     (fVar8 = *(float *)(iVar2 + 0x840) - (float)param_1[0x60],

     fVar7 = *(float *)(iVar2 + 0x83c) - (float)param_1[0x5f],

     fVar6 = *(float *)(iVar2 + 0x838) - (float)param_1[0x5e], pfVar1 = (float *)(param_1 + 0x5e),

     *(float *)(iVar2 + 0x980) * *(float *)(iVar2 + 0x980) <

     fVar8 * fVar8 + fVar7 * fVar7 + fVar6 * fVar6)) {

    if ((*(byte *)(iVar2 + 0x989) & 2) != 0) {

      return 0;

    }

    local_14 = *(float *)(iVar2 + 0x884);

    local_18 = *(float *)(iVar2 + 0x880);

    local_10 = *(float *)(iVar2 + 0x888);

    local_8 = local_14 - (float)param_1[0x5f];

    local_24 = local_18 - *pfVar1;

    local_1c = local_10 - (float)param_1[0x60];

    local_20 = local_8;

    if (ABS(local_8) < *(float *)(iVar2 + 0x980) * DAT_00a0f720) {

      local_20 = local_8 * DAT_00aaa6cc;

    }

    FUN_0076f5f0(&local_24,&local_24);

    param_2 = 0.0;

    if (((*(byte *)(*param_1 + 0x989) & 4) != 0) && (iVar3 != 0)) {

      fVar5 = (float10)FUN_004cd220(*pfVar1,param_1[0x60]);

      param_2 = (float)((float10)(float)param_1[0x5f] - fVar5);

    }

    fVar7 = DAT_009c8354;

    fVar6 = *(float *)(*param_1 + 0x980);

    local_c = local_24 * fVar6 * DAT_009c8354 + local_18;

    local_8 = local_20 * fVar6 * DAT_009c8354 + local_14;

    *pfVar1 = local_c;

    local_4 = local_1c * fVar6 * fVar7 + local_10;

    param_1[0x5f] = (int)local_8;

    param_1[0x60] = (int)local_4;

    if (((*(byte *)(*param_1 + 0x989) & 4) != 0) && (iVar3 != 0)) {

      fVar5 = (float10)FUN_004cd220(*pfVar1,param_1[0x60]);

      param_1[0x5f] = (int)(float)(fVar5 + (float10)param_2);

    }

    param_1[1] = *(int *)(*param_1 + 0x304);

    FUN_004b0f80(0);

    local_28 = 1;

  }

  fVar6 = (float)param_1[0x5c];

  iVar2 = *(int *)(*param_1 + 0x308);

  param_1[0x5c] = (int)(fVar6 - param_3);

  if (fVar6 - param_3 <= 0.0) {

    local_28 = 1;

    cVar4 = FUN_004b0f80(1);

    if (cVar4 == '\0') {

      return 0;

    }

  }

  if (*(char *)(*param_1 + 0x7fb) != '\0') {

    fVar6 = (float)param_1[0x5b];

    param_1[0x5b] = (int)(fVar6 - param_3);

    if (fVar6 - param_3 <= 0.0) {

      return 0;

    }

    *(uint8_t *)(iVar2 + 0x2ee) = 0;

  }

  FUN_004b2b90(local_28,param_3);

  FUN_004b1100(iVar3,local_28,param_3);

  if (param_1[2] != 0) {

    FUN_004b18f0(iVar3);

  }

  *(uint8_t *)(param_1 + 0x90) = 0;

  return 1;

}
