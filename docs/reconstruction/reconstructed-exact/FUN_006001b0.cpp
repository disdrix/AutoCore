// =============================================================================
// FUN_006001b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006001b0
// Address:   0x006001b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006001b0 @ 0x006001b0
// Stable ID: aa_006001b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: ABS×8, FUN_005070b0, FUN_005070d0, FUN_006001b0, _CIacos.
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

void __thiscall FUN_006001b0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  float10 fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  uint8_t local_45;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30 [4];

  float local_20 [7];

  

  iVar1 = *(int *)(param_1 + 0x18);

  iVar2 = *(int *)(iVar1 + 0x3c);

  fVar6 = *(float *)(iVar2 + 0x3c) * *(float *)(iVar2 + 0x3c) * g_flLevelUpUiBase_Inferred - g_flOne

  ;

  fVar7 = (*(float *)(iVar2 + 0x30) * *(float *)(param_1 + 0x30) +

           *(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x38) +

          *(float *)(param_1 + 0x34) * *(float *)(iVar2 + 0x34)) * g_flLevelUpUiBase_Inferred;

  fVar8 = *(float *)(iVar2 + 0x3c) * g_flLevelUpUiBase_Inferred;

  local_3c = (*(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x30) -

             *(float *)(iVar2 + 0x30) * *(float *)(param_1 + 0x38)) * fVar8 +

             *(float *)(iVar2 + 0x34) * fVar7 + *(float *)(param_1 + 0x34) * fVar6;

  local_40 = (*(float *)(iVar2 + 0x34) * *(float *)(param_1 + 0x38) -

             *(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x34)) * fVar8 +

             *(float *)(iVar2 + 0x30) * fVar7 + *(float *)(param_1 + 0x30) * fVar6;

  local_38 = (*(float *)(param_1 + 0x34) * *(float *)(iVar2 + 0x30) -

             *(float *)(iVar2 + 0x34) * *(float *)(param_1 + 0x30)) * fVar8 +

             *(float *)(iVar2 + 0x38) * fVar7 + fVar6 * *(float *)(param_1 + 0x38);

  fVar8 = *(float *)(iVar2 + 0x3c) * *(float *)(iVar2 + 0x3c) * g_flLevelUpUiBase_Inferred - g_flOne

  ;

  fVar6 = (*(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x28) +

           *(float *)(param_1 + 0x24) * *(float *)(iVar2 + 0x34) +

          *(float *)(iVar2 + 0x30) * *(float *)(param_1 + 0x20)) * g_flLevelUpUiBase_Inferred;

  fVar7 = *(float *)(iVar2 + 0x3c) * g_flLevelUpUiBase_Inferred;

  local_44 = local_40 * *(float *)(param_1 + 0x30) +

             local_3c * *(float *)(param_1 + 0x34) + local_38 * *(float *)(param_1 + 0x38);

  local_30[3] = fVar7 * 0.0 + fVar6 * *(float *)(iVar2 + 0x3c) + *(float *)(param_1 + 0x2c) * fVar8;

  local_30[0] = (*(float *)(iVar2 + 0x34) * *(float *)(param_1 + 0x28) -

                *(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x24)) * fVar7 +

                *(float *)(iVar2 + 0x30) * fVar6 + *(float *)(param_1 + 0x20) * fVar8;

  local_30[1] = (*(float *)(iVar2 + 0x38) * *(float *)(param_1 + 0x20) -

                *(float *)(iVar2 + 0x30) * *(float *)(param_1 + 0x28)) * fVar7 +

                *(float *)(iVar2 + 0x34) * fVar6 + *(float *)(param_1 + 0x24) * fVar8;

  local_30[2] = (*(float *)(param_1 + 0x24) * *(float *)(iVar2 + 0x30) -

                *(float *)(iVar2 + 0x34) * *(float *)(param_1 + 0x20)) * fVar7 +

                *(float *)(iVar2 + 0x38) * fVar6 + fVar8 * *(float *)(param_1 + 0x28);

  if (ABS(local_44) < g_flOne) {

    fVar5 = (float10)_CIacos();

    fVar6 = (float)fVar5;

    local_44 = fVar6;

  }

  else {

    fVar6 = 0.0;

    if (local_44 <= 0.0) {

      fVar6 = DAT_009de0b0;

    }

  }

  local_20[0] = local_3c * *(float *)(param_1 + 0x38) - local_38 * *(float *)(param_1 + 0x34);

  local_20[1] = local_38 * *(float *)(param_1 + 0x30) - local_40 * *(float *)(param_1 + 0x38);

  local_20[2] = local_40 * *(float *)(param_1 + 0x34) - local_3c * *(float *)(param_1 + 0x30);

  local_20[0] = ABS(local_20[0]);

  local_20[1] = ABS(local_20[1]);

  local_20[2] = ABS(local_20[2]);

  if (local_20[1] <= local_20[0]) {

    if (local_20[2] <= local_20[0]) {

      iVar2 = 0;

    }

    else {

      iVar2 = 2;

    }

  }

  else if (local_20[2] <= local_20[1]) {

    iVar2 = 1;

  }

  else {

    iVar2 = 2;

  }

  local_40 = ABS(local_30[0]);

  local_3c = ABS(local_30[1]);

  if (local_3c <= local_40) {

    if (ABS(local_30[2]) <= local_40) {

      iVar3 = 0;

    }

    else {

      iVar3 = 2;

    }

  }

  else if (ABS(local_30[2]) <= local_3c) {

    iVar3 = 1;

  }

  else {

    iVar3 = 2;

  }

  if (0.0 <= local_20[iVar2]) {

    iVar2 = 0;

  }

  else {

    iVar2 = 8;

  }

  if (0.0 <= local_30[iVar3]) {

    iVar3 = 0;

  }

  else {

    iVar3 = 8;

  }

  if (iVar2 != iVar3) {

    fVar6 = 0.0 - fVar6;

  }

  iVar2 = *(int *)(iVar1 + 0x3c);

  fVar7 = *(float *)(param_1 + 0x44) * *(float *)(param_2 + 4);

  local_38 = *(float *)(iVar2 + 0x58) * fVar7;

  local_34 = *(float *)(iVar2 + 0x5c) * fVar7;

  fVar6 = *(float *)(param_1 + 0x40) * *(float *)(param_2 + 4) * fVar6;

  local_20[2] = local_30[2] * fVar6 - local_38;

  local_20[3] = local_30[3] * fVar6 - local_34;

  local_20[0] = fVar6 * local_30[0] - *(float *)(iVar2 + 0x50) * fVar7;

  local_20[1] = local_30[1] * fVar6 - *(float *)(iVar2 + 0x54) * fVar7;

  pcVar4 = (char *)FUN_005070b0(&local_45);

  if ((*pcVar4 == '\0') && (*(int *)(iVar1 + 0x44) != 0)) {

    FUN_005070d0();

  }

  (**(code **)(**(int **)(iVar1 + 0x3c) + 100))(local_20);

  return;

}
