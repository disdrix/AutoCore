// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00699c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00699c50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00699c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_006999e0×2, FUN_0068bac0, FUN_0068ca30, FUN_00699c50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

int __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00699c50(float *param_1,int param_2,float param_3,float param_4,float param_5,float param_6,

            float *param_7)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  ushort uVar6;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  pfVar3 = param_7;

  local_c = param_6 * *param_1;

  uVar6 = 0;

  local_54 = param_3 - local_c;

  local_50 = param_4 - param_6 * param_1[1];

  local_4c = param_5 - param_6 * param_1[2];

  local_30 = local_c + param_3;

  local_2c = param_6 * param_1[1] + param_4;

  local_28 = param_6 * param_1[2] + param_5;

  local_48 = param_3 - param_6 * param_1[3];

  local_44 = param_4 - param_6 * param_1[4];

  local_40 = param_5 - param_6 * param_1[5];

  fVar1 = param_1[3];

  fVar2 = param_1[4];

  local_4 = param_6 * param_1[5];

  *(uint16_t *)(param_2 + 0x1a) = 0;

  local_18 = param_6 * fVar1 + param_3;

  local_14 = param_6 * fVar2 + param_4;

  local_10 = local_4 + param_5;

  while( true ) {

    if (*(int *)(param_2 + 100) == 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = *(int *)(param_2 + 0x68) - *(int *)(param_2 + 100) >> 2;

    }

    if ((ushort)(uVar5 / 3) <= uVar6) break;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0068bac0(uVar6);

    local_3c = *puVar4;

    local_38 = puVar4[1];

    local_34 = puVar4[2];

    FUN_006999e0(&local_24,&local_54,&local_30,&local_3c);

    param_7 = (float *)(((int)((local_1c - local_4c) * (local_1c - local_4c) +

                              (local_20 - local_50) * (local_20 - local_50) +

                              (local_24 - local_54) * (local_24 - local_54)) >> 1) + 0x1fc00000);

    fVar1 = g_flOne / (param_6 + param_6);

    param_3 = fVar1 * (float)param_7;

    if (pfVar3 != (float *)0x0) {

      param_3 = (*pfVar3 - pfVar3[2]) * param_3 + pfVar3[2];

    }

    FUN_006999e0(&local_c,&local_48,&local_18,&local_3c);

    param_7 = (float *)(((int)((local_4 - local_40) * (local_4 - local_40) +

                              (local_8 - local_44) * (local_8 - local_44) +

                              (local_c - local_48) * (local_c - local_48)) >> 1) + 0x1fc00000);

    param_4 = fVar1 * (float)param_7;

    if (pfVar3 != (float *)0x0) {

      param_4 = (pfVar3[1] - pfVar3[5]) * param_4 + pfVar3[5];

    }

    FUN_0068ca30(&param_3);

    uVar6 = uVar6 + 1;

  }

  return uVar5 * -0x55555555;

}
