// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0079dd50
// -----------------------------------------------------------------------------
// Stable ID: aa_0079dd50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0079dd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: FUN_00567ce0, FUN_0079dd50.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0079dd50(int param_1,int *param_2,float *param_3,int param_4)



{

  int iVar1;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  

  if (*unaff_EBX + 6 < *param_2) {

    local_4c = param_3[0xb] * DAT_00a0f298;

    local_48 = *(float *)(param_1 + 0x2a8) * local_4c;

    local_50 = local_4c * *(float *)(param_1 + 0x2a0);

    local_38 = param_3[0xc] * DAT_00a0f298;

    local_4c = local_4c * *(float *)(param_1 + 0x2a4);

    local_40 = local_38 * *(float *)(param_1 + 0x2ac);

    local_3c = *(float *)(param_1 + 0x2b0) * local_38;

    local_38 = *(float *)(param_1 + 0x2b4) * local_38;

    if (param_3[10] != 0.0) {

      local_60 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x294);

      local_5c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x298);

      local_58 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c);

      local_54 = 0;

      FUN_00567ce0(&local_60,param_3[10]);

      fVar4 = local_24 * local_24 * g_flLevelUpUiBase_Inferred - g_flOne;

      local_24 = local_24 * g_flLevelUpUiBase_Inferred;

      fVar5 = (local_28 * local_48 + local_2c * local_4c + local_30 * local_50) *

              g_flLevelUpUiBase_Inferred;

      fVar6 = local_28 * local_50;

      fVar8 = local_30 * local_4c;

      fVar7 = local_2c * local_50;

      local_50 = (local_2c * local_48 - local_28 * local_4c) * local_24 +

                 local_30 * fVar5 + fVar4 * local_50;

      local_4c = (fVar6 - local_48 * local_30) * local_24 + local_2c * fVar5 + fVar4 * local_4c;

      local_48 = (fVar8 - fVar7) * local_24 + local_28 * fVar5 + local_48 * fVar4;

      fVar5 = (local_2c * local_3c + local_30 * local_40 + local_28 * local_38) *

              g_flLevelUpUiBase_Inferred;

      fVar6 = local_28 * local_3c;

      fVar7 = local_3c * local_30;

      fVar8 = local_2c * local_40;

      local_3c = (local_28 * local_40 - local_38 * local_30) * local_24 +

                 local_2c * fVar5 + local_3c * fVar4;

      local_40 = (local_2c * local_38 - fVar6) * local_24 + local_30 * fVar5 + fVar4 * local_40;

      local_38 = (fVar7 - fVar8) * local_24 + local_28 * fVar5 + local_38 * fVar4;

    }

    *(float *)(param_4 + *unaff_EBX * 0x1c) = (*param_3 - local_50) + local_40;

    *(float *)(param_4 + 4 + *unaff_EBX * 0x1c) = (param_3[1] - local_4c) + local_3c;

    *(float *)(param_4 + 8 + *unaff_EBX * 0x1c) = (param_3[2] - local_48) + local_38;

    *(float *)(param_4 + 0x10 + *unaff_EBX * 0x1c) = param_3[4];

    *(float *)(param_4 + 0x14 + *unaff_EBX * 0x1c) = param_3[5];

    *(float *)(param_4 + 0x18 + *unaff_EBX * 0x1c) = param_3[9];

    *(float *)(param_4 + 0xc + *unaff_EBX * 0x1c) = param_3[8];

    *unaff_EBX = *unaff_EBX + 1;

    *(float *)(param_4 + *unaff_EBX * 0x1c) = *param_3 + local_40 + local_50;

    *(float *)(param_4 + 4 + *unaff_EBX * 0x1c) = param_3[1] + local_3c + local_4c;

    *(float *)(param_4 + 8 + *unaff_EBX * 0x1c) = local_38 + local_48 + param_3[2];

    *(float *)(param_4 + 0x10 + *unaff_EBX * 0x1c) = param_3[6];

    *(float *)(param_4 + 0x14 + *unaff_EBX * 0x1c) = param_3[5];

    *(float *)(param_4 + 0x18 + *unaff_EBX * 0x1c) = param_3[9];

    *(float *)(param_4 + 0xc + *unaff_EBX * 0x1c) = param_3[8];

    *unaff_EBX = *unaff_EBX + 1;

    *(float *)(param_4 + *unaff_EBX * 0x1c) = (*param_3 - local_50) - local_40;

    *(float *)(param_4 + 4 + *unaff_EBX * 0x1c) = (param_3[1] - local_4c) - local_3c;

    *(float *)(param_4 + 8 + *unaff_EBX * 0x1c) = (param_3[2] - local_48) - local_38;

    *(float *)(param_4 + 0x10 + *unaff_EBX * 0x1c) = param_3[4];

    *(float *)(param_4 + 0x14 + *unaff_EBX * 0x1c) = param_3[7];

    *(float *)(param_4 + 0x18 + *unaff_EBX * 0x1c) = param_3[9];

    *(float *)(param_4 + 0xc + *unaff_EBX * 0x1c) = param_3[8];

    *unaff_EBX = *unaff_EBX + 1;

    puVar2 = (uint32_t /* width from decompiler */ *)(param_4 + (*unaff_EBX + -2) * 0x1c);

    puVar3 = (uint32_t /* width from decompiler */ *)(param_4 + *unaff_EBX * 0x1c);

    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    *unaff_EBX = *unaff_EBX + 1;

    *(float *)(param_4 + *unaff_EBX * 0x1c) = (*param_3 + local_50) - local_40;

    *(float *)(param_4 + 4 + *unaff_EBX * 0x1c) = (param_3[1] + local_4c) - local_3c;

    *(float *)(param_4 + 8 + *unaff_EBX * 0x1c) = (local_48 + param_3[2]) - local_38;

    *(float *)(param_4 + 0x10 + *unaff_EBX * 0x1c) = param_3[6];

    *(float *)(param_4 + 0x14 + *unaff_EBX * 0x1c) = param_3[7];

    *(float *)(param_4 + 0x18 + *unaff_EBX * 0x1c) = param_3[9];

    *(float *)(param_4 + 0xc + *unaff_EBX * 0x1c) = param_3[8];

    *unaff_EBX = *unaff_EBX + 1;

    puVar2 = (uint32_t /* width from decompiler */ *)(param_4 + (*unaff_EBX + -3) * 0x1c);

    puVar3 = (uint32_t /* width from decompiler */ *)(param_4 + *unaff_EBX * 0x1c);

    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    *unaff_EBX = *unaff_EBX + 1;

    return 1;

  }

  return 0;

}
