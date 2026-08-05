// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b9040
// -----------------------------------------------------------------------------
// Stable ID: aa_005b9040
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005b9040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×4, FUN_005b85a0, FUN_005b9040, FUN_0076f5f0, ROUND, SQRT.
//  - Return sites: 1.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b9040(int param_1)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_005b85a0();

  iVar2 = param_1 + 0x90;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  *(int *)iVar2 = iVar2;

  *(int *)(param_1 + 0x94) = iVar2;

  *(int *)(param_1 + 0xc4) = iVar2;

  if ((*(uint *)(param_1 + 0x178) & 2) == 0) {

    local_24 = *(float *)(param_1 + 0x144);

    local_20 = *(float *)(param_1 + 0x148);

    local_1c = *(float *)(param_1 + 0x14c);

  }

  else {

    local_24 = *(float *)(param_1 + 0x144) - *(float *)(param_1 + 0x134);

    local_20 = *(float *)(param_1 + 0x148) - *(float *)(param_1 + 0x138);

    local_1c = *(float *)(param_1 + 0x14c) - *(float *)(param_1 + 0x13c);

  }

  if ((*(uint *)(param_1 + 0x178) & 1) != 0) {

    fVar4 = *(float *)(param_1 + 0x100) * local_20;

    fVar5 = *(float *)(param_1 + 0xf0) * local_24;

    fVar6 = *(float *)(param_1 + 0xf4) * local_24;

    local_24 = *(float *)(param_1 + 0xec) * local_24 + *(float *)(param_1 + 0xf8) * local_20 +

               local_1c * *(float *)(param_1 + 0xe0);

    local_20 = fVar5 + *(float *)(param_1 + 0xfc) * local_20 + *(float *)(param_1 + 0xe4) * local_1c

    ;

    local_1c = fVar6 + fVar4 + *(float *)(param_1 + 0xe8) * local_1c;

  }

  iVar2 = (int)ROUND(SQRT(local_1c * local_1c + local_20 * local_20 + local_24 * local_24) *

                     *(float *)(param_1 + 0x164)) + 1;

  if (499 < iVar2) {

    iVar2 = 500;

  }

  *(int *)(param_1 + 0x88) = iVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 1;

  local_c = *(float *)(param_1 + 0x104) + local_24;

  local_8 = *(float *)(param_1 + 0x108) + local_20;

  local_4 = *(float *)(param_1 + 0x10c) + local_1c;

  *(float *)(param_1 + 0x98) = local_c;

  *(float *)(param_1 + 0x9c) = local_8;

  *(float *)(param_1 + 0xa0) = local_4;

  if (*(int *)(param_1 + 0x8c) < *(int *)(param_1 + 0x88)) {

    do {

      *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;

      puVar3 = operator_new(0x34);

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        *(uint8_t *)((int)puVar3 + 0x2e) = 0xff;

        *(uint8_t *)((int)puVar3 + 0x2d) = 0xff;

        *(uint8_t *)(puVar3 + 0xb) = 0xff;

        *(uint8_t *)((int)puVar3 + 0x2f) = 0xff;

      }

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      local_18 = ((float)uVar1 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      local_14 = ((float)uVar1 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      local_10 = ((float)uVar1 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

      FUN_0076f5f0(&local_18,&local_18);

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      fVar4 = (float)uVar1 * *(float *)(param_1 + 0x154) * DAT_00aaa638 +

              *(float *)(param_1 + 0x150);

      puVar3[0xc] = fVar4;

      local_18 = fVar4 * local_18;

      local_10 = fVar4 * local_10;

      local_14 = fVar4 * local_14;

      fVar6 = (float)(*(int *)(param_1 + 0x8c) + -1) / (float)(*(int *)(param_1 + 0x88) + 1);

      fVar4 = *(float *)(param_1 + 0x108);

      fVar5 = *(float *)(param_1 + 0x10c);

      local_c = *(float *)(param_1 + 0x104) + fVar6 * local_24 + local_18;

      puVar3[2] = local_c;

      local_8 = fVar6 * local_20 + fVar4 + local_14;

      puVar3[3] = local_8;

      local_4 = fVar6 * local_1c + fVar5 + local_10;

      puVar3[4] = local_4;

      *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4);

      puVar3[1] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc4) + 4);

      **(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xc4) + 4) = puVar3;

      *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xc4) + 4) = puVar3;

    } while (*(int *)(param_1 + 0x8c) < *(int *)(param_1 + 0x88));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = **(uint32_t /* width from decompiler */ **)(param_1 + 0xc4);

  return;

}
