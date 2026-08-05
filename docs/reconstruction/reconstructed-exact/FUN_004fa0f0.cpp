// =============================================================================
// FUN_004fa0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004fa0f0
// Address:   0x004fa0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004fa0f0 @ 0x004fa0f0
// Stable ID: aa_004fa0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040cf90, FUN_004e87d0, FUN_004e9530, FUN_004e96e0, FUN_004fa0f0.
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

void __fastcall FUN_004fa0f0(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  uint32_t /* width from decompiler */ uVar14;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_4c;

  float local_48;

  float local_40;

  float local_3c;

  float local_38;

  uint8_t auStack_34 [4];

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  

  if ((*(int *)(param_1 + 0x26c) != 0) && (*(int *)(*(int *)(param_1 + 0x26c) + 8) != 0)) {

    iVar4 = *(int *)(param_1 + 8);

    if (iVar4 == 0) {

      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

    }

    else {

      pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0xb0);

    }

    local_40 = *pfVar5;

    local_3c = pfVar5[1];

    local_38 = pfVar5[2];

    if (iVar4 == 0) {

      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);

    }

    else {

      pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0x30);

    }

    fVar1 = *pfVar5;

    fVar2 = pfVar5[1];

    fVar3 = pfVar5[2];

    fVar9 = pfVar5[3];

    local_60 = fVar1;

    local_5c = fVar2;

    local_58 = fVar3;

    local_54 = fVar9;

    pfVar5 = (float *)FUN_004e9530(&local_20,param_1 + 0x3bc);

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    fVar10 = *pfVar5;

    fVar8 = fVar9 * fVar9 * g_flLevelUpUiBase_Inferred - g_flOne;

    fVar9 = fVar9 * g_flLevelUpUiBase_Inferred;

    fVar7 = (local_48 * fVar3 + local_4c * fVar2 + fVar1 * fVar10) * g_flLevelUpUiBase_Inferred;

    local_1c = local_4c * fVar8;

    local_18 = local_48 * fVar8;

    local_6c = (local_48 * fVar2 - local_4c * fVar3) * fVar9 + fVar7 * fVar1 + fVar8 * fVar10 +

               local_40;

    local_68 = (fVar3 * fVar10 - local_48 * fVar1) * fVar9 + fVar2 * fVar7 + local_1c + local_3c;

    local_64 = (local_4c * fVar1 - fVar2 * fVar10) * fVar9 + fVar3 * fVar7 + local_18 + local_38;

    pfVar5 = (float *)FUN_004e96e0(&local_20,param_1 + 0x3c8);

    fVar1 = pfVar5[1];

    fVar2 = pfVar5[2];

    fVar3 = *pfVar5;

    fVar9 = pfVar5[3];

    fVar11 = fVar2 * local_60;

    fVar12 = fVar1 * local_60;

    fVar13 = local_5c * fVar3;

    fVar10 = fVar3 * local_60;

    fVar7 = fVar1 * local_5c;

    fVar8 = fVar2 * local_54;

    local_60 = fVar9 * local_60 + local_54 * fVar3 + (fVar2 * local_5c - fVar1 * local_58);

    local_5c = fVar9 * local_5c + fVar1 * local_54 + (local_58 * fVar3 - fVar11);

    local_54 = fVar9 * local_54 - (fVar2 * local_58 + fVar7 + fVar10);

    local_58 = fVar9 * local_58 + fVar8 + (fVar12 - fVar13);

    local_20 = local_60;

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_004e87d0(&local_20,&local_60);

    local_30 = *puVar6;

    local_2c = puVar6[1];

    local_28 = puVar6[2];

    local_24 = puVar6[3];

    uVar14 = 3;

    (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 8) + 0x10))(3,&local_6c);

    FUN_0040cf90(uVar14);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 8) + 0x14))(auStack_34);

  }

  return;

}
