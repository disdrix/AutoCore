// =============================================================================
// Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005cd220
// -----------------------------------------------------------------------------
// Stable ID: aa_005cd220
// Callee of CVOGHBAICreatureBase_OnHeartBeat
// Address:   0x005cd220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAICreatureBase_OnHeartBeat: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, FUN_004e8bf0, FUN_0053e0b0, FUN_005cd220.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAICreatureBase_OnHeartBeat
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

uint __fastcall Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005cd220(int *param_1)



{

  ushort uVar1;

  ushort uVar2;

  float fVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  float local_34;

  float local_30 [3];

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [28];

  

  uVar6 = param_1[0x19];

  if ((*(char *)(uVar6 + 0x279) != '\0') && ((uint)param_1[0x1d] < g_dwClientTickMs - param_1[0x1c])

     ) {

    *(uint8_t *)(param_1 + 0x1e) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    uVar5 = (uint)uVar1;

    uVar6 = uVar5 / 3;

    if (uVar5 % 3 == 0) {

      local_34 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac +

                                             param_1[0x19]) + 0x3c) + 0x4d4);

      if (local_34 < g_flVehicleHpTechCoeff) {

        local_34 = local_34 + g_flVehicleHpTechCoeff;

      }

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      fVar3 = DAT_00aaa638;

      uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      local_30[0] = (float)uVar2 * local_34 * g_flLevelUpUiBase_Inferred * fVar3 - local_34;

      local_30[2] = (float)uVar1 * local_34 * g_flLevelUpUiBase_Inferred * fVar3 - local_34;

      local_30[1] = 0.0;

      local_24 = 0;

      uVar7 = FUN_0053e0b0();

      uVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 + param_1[0x19]) +

                          0x1a4))(local_30,local_20);

      FUN_004e8bf0(uVar7,uVar8);

      uVar6 = (**(code **)(*param_1 + 0x4c))(local_20,0);

    }

  }

  return uVar6;

}
