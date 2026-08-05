// =============================================================================
// FUN_00636520
// -----------------------------------------------------------------------------
// Stable ID: aa_00636520
// Address:   0x00636520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636520 @ 0x00636520
// Stable ID: aa_00636520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d6ae0×2, FUN_00567ce0, FUN_00636520, FUN_006c2fb0, FUN_006c3160, SQRT.
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

void __thiscall FUN_00636520(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  iVar1 = *(int *)(param_1 + 0xc);

  iVar2 = *(int *)(param_1 + 0x10);

  FUN_006c2fb0(param_2,param_3,param_1 + 0x54,8);

  if (*(char *)(param_1 + 0x5c) != '\0') {

    FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x30);

    local_50 = *(float *)(param_1 + 0x44) * local_68 - *(float *)(param_1 + 0x48) * local_6c;

    local_4c = *(float *)(param_1 + 0x48) * local_70 - *(float *)(param_1 + 0x40) * local_68;

    local_48 = *(float *)(param_1 + 0x40) * local_6c - *(float *)(param_1 + 0x44) * local_70;

    fVar3 = local_48 * local_48 + local_4c * local_4c + local_50 * local_50;

    if (fVar3 == 0.0) {

      local_44 = 0.0;

    }

    else {

      local_44 = g_flOne / SQRT(fVar3);

    }

    local_50 = local_50 * local_44;

    local_4c = local_4c * local_44;

    local_48 = local_48 * local_44;

    local_44 = local_44 * 0.0;

    local_20 = local_50;

    local_1c = local_4c;

    local_18 = local_48;

    local_14 = local_44;

    FUN_00567ce0(&local_50,*(uint32_t /* width from decompiler */ *)(param_1 + 0x50));

    fVar3 = (local_5c * local_6c + local_58 * local_68 + local_70 * local_60) *

            g_flLevelUpUiBase_Inferred;

    fVar5 = local_54 * local_54 * g_flLevelUpUiBase_Inferred - g_flOne;

    fVar4 = local_54 * g_flLevelUpUiBase_Inferred;

    local_40 = 0.0 - ((local_5c * local_68 - local_58 * local_6c) * fVar4 +

                     local_60 * fVar3 + local_70 * fVar5);

    local_3c = 0.0 - ((local_58 * local_70 - local_60 * local_68) * fVar4 +

                     local_5c * fVar3 + local_6c * fVar5);

    local_38 = 0.0 - ((local_60 * local_6c - local_5c * local_70) * fVar4 +

                     local_58 * fVar3 + local_68 * fVar5);

    local_34 = 0.0 - (fVar4 * 0.0 + local_54 * fVar3 + local_64 * fVar5);

    FUN_005d6ae0(*(int *)(iVar2 + 0x3c) + 0x80,(float *)(param_1 + 0x40));

    FUN_006c3160(&local_40,param_2,param_3);

  }

  return;

}
