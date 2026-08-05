// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattl_0041db90
// -----------------------------------------------------------------------------
// Stable ID: aa_0041db90
// Callee of Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1
// Address:   0x0041db90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, for×1.
//  - Notable callees: FUN_004225d0×4, FUN_00422040×2, FUN_0041db90, FUN_00421db0, FUN_00421dd0, FUN_004540b0, FUN_00690210.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1
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

void __fastcall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattl_0041db90(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4,uint param_5)



{

  void *pvVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_50 [14];

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bce80;

  local_10 = ExceptionList;

  puVar5 = local_50;

  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = *param_2;

    param_2 = param_2 + 1;

    puVar5 = puVar5 + 1;

  }

  iVar4 = *(int *)(param_3 + 4);

  if (iVar4 == 0) {

    local_18 = 0;

  }

  else {

    local_18 = (*(int *)(param_3 + 0xc) - iVar4) / 0x38;

  }

  if (param_5 != 0) {

    if (iVar4 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x38;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffffa4;

    if (0x4924924U - iVar4 < param_5) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffffa4;

      FUN_004540b0();

      local_18 = extraout_ECX;

    }

    if (*(int *)(param_3 + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x38;

    }

    if (local_18 < iVar4 + param_5) {

      if (0x4924924 - (local_18 >> 1) < local_18) {

        local_18 = 0;

      }

      else {

        local_18 = local_18 + (local_18 >> 1);

      }

      if (*(int *)(param_3 + 4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x38;

      }

      if (local_18 < iVar4 + param_5) {

        iVar4 = FUN_00690210();

        local_18 = iVar4 + param_5;

      }

      local_18 = local_18 * 0x38;

      pvVar2 = operator_new(local_18);

      local_8 = 0;

      FUN_004225d0(param_4);

      FUN_00422040(param_4);

      FUN_004225d0(param_4);

      pvVar1 = *(void **)(param_3 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_3 + 8) - (int)pvVar1) / 0x38;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_3 + 0xc) = local_18 + (int)pvVar2;

      *(void **)(param_3 + 8) = (void *)((int)pvVar2 + (param_5 + iVar4) * 0x38);

      *(void **)(param_3 + 4) = pvVar2;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_3 + 8) - param_4) / 0x38) < param_5) {

      FUN_004225d0(param_4);

      local_8 = 2;

      FUN_00422040(param_4);

      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + param_5 * 0x38;

    }

    else {

      uVar3 = FUN_004225d0(param_4);

      *(uint32_t /* width from decompiler */ *)(param_3 + 8) = uVar3;

      FUN_00421dd0();

    }

    FUN_00421db0();

  }

  ExceptionList = local_10;

  return;

}
