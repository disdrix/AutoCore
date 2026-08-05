// =============================================================================
// FUN_00649600
// -----------------------------------------------------------------------------
// Stable ID: aa_00649600
// Address:   0x00649600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00649600 @ 0x00649600
// Stable ID: aa_00649600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005070d0, FUN_00635bd0, FUN_00649600, FUN_0065afe0.
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

void __thiscall FUN_00649600(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float local_250;

  float local_24c;

  float local_248;

  float local_244;

  float local_240;

  float local_23c;

  float local_238;

  float local_234;

  float local_230;

  float local_22c;

  float local_228;

  float local_224;

  int local_21c;

  char local_218;

  float local_214;

  float local_20c;

  uint8_t *local_200;

  int local_1fc;

  int local_1f8;

  uint8_t local_1f0 [492];

  

  local_200 = local_1f0;

  iVar5 = 0;

  local_1fc = 0;

  local_1f8 = -0x7ffffff1;

  local_21c = param_1;

  FUN_00635bd0(&local_200);

  local_218 = *(int *)(param_1 + 0x24) != 0;

  iVar6 = 0;

  if (0 < local_1fc) {

    do {

      local_250 = *(float *)(local_200 + iVar5);

      local_24c = *(float *)(local_200 + iVar5 + 4);

      local_248 = *(float *)(local_200 + iVar5 + 8);

      local_244 = *(float *)(local_200 + iVar5 + 0xc);

      pfVar1 = (float *)(local_200 + iVar5 + 0x10);

      fVar2 = *pfVar1;

      fVar3 = pfVar1[1];

      local_238 = pfVar1[2];

      local_234 = pfVar1[3];

      local_240 = fVar2;

      local_23c = fVar3;

      if (local_218 != '\0') {

        pfVar1 = (float *)(*(int *)(local_21c + 0x20) + iVar5);

        fVar9 = local_234 * local_234 * g_flLevelUpUiBase_Inferred - g_flOne;

        fVar8 = local_234 * g_flLevelUpUiBase_Inferred;

        fVar7 = (*(float *)(*(int *)(local_21c + 0x20) + iVar5) * fVar2 + fVar3 * pfVar1[1] +

                local_238 * pfVar1[2]) * g_flLevelUpUiBase_Inferred;

        local_20c = *pfVar1 * local_238 - fVar2 * pfVar1[2];

        local_228 = fVar9 * pfVar1[2];

        local_224 = pfVar1[3] * fVar9;

        local_230 = fVar2 * fVar7 + *pfVar1 * fVar9;

        local_22c = fVar3 * fVar7 + fVar9 * pfVar1[1];

        local_250 = (fVar3 * pfVar1[2] - local_238 * pfVar1[1]) * fVar8 + local_230 + local_250;

        local_24c = local_20c * fVar8 + local_22c + local_24c;

        local_248 = (fVar2 * pfVar1[1] - *pfVar1 * fVar3) * fVar8 + local_238 * fVar7 + local_228 +

                    local_248;

        local_244 = fVar8 * g_flZero + local_234 * fVar7 + local_224 + local_244;

        fVar7 = pfVar1[4];

        fVar8 = pfVar1[5];

        fVar9 = pfVar1[6];

        fVar4 = pfVar1[7];

        local_214 = fVar9 * fVar3;

        fVar10 = fVar9 * local_238;

        local_240 = fVar4 * fVar2 + local_234 * fVar7 + (local_214 - fVar8 * local_238);

        local_23c = fVar4 * fVar3 + fVar8 * local_234 + (local_238 * fVar7 - fVar9 * fVar2);

        local_238 = fVar4 * local_238 + fVar9 * local_234 + (fVar8 * fVar2 - fVar3 * fVar7);

        local_234 = fVar4 * local_234 - (fVar8 * fVar3 + fVar10 + fVar2 * fVar7);

      }

      FUN_0065afe0(&local_250,&local_240,param_3,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + iVar6 * 4))

      ;

      FUN_005070d0();

      iVar6 = iVar6 + 1;

      iVar5 = iVar5 + 0x20;

      param_1 = local_21c;

    } while (iVar6 < local_1fc);

  }

  if (-1 < local_1f8) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_200,local_1f8 << 5,0x12);

  }

  return;

}
