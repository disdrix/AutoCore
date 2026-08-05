// =============================================================================
// Named_CalleeOf_Skill_skill_n_fixme_power_dump_0052ed80
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ed80
// Callee of Skill_skill_n_fixme_power_dump
// Address:   0x0052ed80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_skill_n_fixme_power_dump: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~198 non-empty decompiler lines.
//  - Control keywords: if×26, return×3, while×2, for×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×7, FUN_004022a0×4, FUN_004073a0×2, FUN_004294f0×2, LeaveCriticalSection×2, __RTDynamicCast×2, FUN_004c3720, FUN_0052ed80.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Skill_skill_n_fixme_power_dump
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

uint __thiscall Named_CalleeOf_Skill_skill_n_fixme_power_dump_0052ed80(int param_1,char param_2,uint param_3)



{

  ushort uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float fVar7;

  uint local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20 [2];

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3bb2;

  pvStack_c = ExceptionList;

  puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  local_2c = 0;

  if (param_2 == '\0') {

    local_2c = param_3;

    ExceptionList = &pvStack_c;

  }

  else {

    fVar7 = (float)(int)*(short *)(param_1 + 300) / (float)(int)*(short *)(param_1 + 0x12e);

    ExceptionList = &pvStack_c;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = 2;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 4;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 8;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 0x1000;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 0x200;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 0x40;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= fVar7) {

      local_2c = local_2c | 0x10;

    }

  }

  *(uint16_t *)(param_1 + 300) = 0;

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb4 + param_1);

  puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  local_4 = 0;

  _param_2 = 0;

  if (iVar3 != 0) {

    local_28 = 0;

    local_24 = 0;

    FUN_004294f0();

    iVar4 = FUN_004022a0(&local_24,&local_28);

    while (iVar4 == 0) {

      iVar4 = __RTDynamicCast(local_28,0,&CVOGHBBase::RTTI_Type_Descriptor,

                              &CVOGHBSkillBase::RTTI_Type_Descriptor,0);

      if (((iVar4 != 0) && (*(char *)(iVar4 + 0x16c) != '\0')) &&

         ((local_2c & ~*(uint *)(param_1 + 0x318) & *(uint *)(iVar4 + 0x644)) != 0)) {

        _param_2 = _param_2 | *(uint *)(iVar4 + 0x644);

        local_20[0] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x620);

        if ((puVar5 == (uint32_t /* width from decompiler */ *)0x0) ||

           ((uint)(local_10 - (int)puVar5 >> 2) <= (uint)((int)puVar6 - (int)puVar5 >> 2))) {

          FUN_004073a0(puVar6,1,local_20);

          puVar5 = local_18;

          puVar6 = local_14;

        }

        else {

          *puVar6 = local_20[0];

          local_14 = puVar6 + 1;

          puVar6 = local_14;

        }

      }

      iVar4 = FUN_004022a0(&local_24,&local_28);

    }

    puVar2 = puVar5;

    if (*(char *)(iVar3 + 0x28) != '\0') {

      *(uint8_t *)(iVar3 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

    }

    for (; puVar2 != puVar6; puVar2 = puVar2 + 1) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x220))(*puVar2,0);

    }

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar5);

    }

  }

  iVar3 = *(int *)(param_1 + 0x250);

  puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  if ((iVar3 == 0) || (*(char *)(param_1 + 0x30c) == '\0')) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb4 + iVar3);

  }

  if (iVar3 != 0) {

    local_28 = 0;

    local_24 = 0;

    FUN_004294f0();

    iVar4 = FUN_004022a0(&local_24,&local_28);

    while (iVar4 == 0) {

      iVar4 = __RTDynamicCast(local_28,0,&CVOGHBBase::RTTI_Type_Descriptor,

                              &CVOGHBSkillBase::RTTI_Type_Descriptor,0);

      if (((iVar4 != 0) && (*(char *)(iVar4 + 0x16c) != '\0')) &&

         ((local_2c & ~*(uint *)(param_1 + 0x318) & *(uint *)(iVar4 + 0x644)) != 0)) {

        _param_2 = _param_2 | *(uint *)(iVar4 + 0x644);

        local_20[0] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x620);

        if ((puVar6 == (uint32_t /* width from decompiler */ *)0x0) ||

           ((uint)(local_10 - (int)puVar6 >> 2) <= (uint)((int)puVar5 - (int)puVar6 >> 2))) {

          FUN_004073a0(puVar5,1,local_20);

          puVar6 = local_18;

          puVar5 = local_14;

        }

        else {

          *puVar5 = local_20[0];

          local_14 = puVar5 + 1;

          puVar5 = local_14;

        }

      }

      iVar4 = FUN_004022a0(&local_24,&local_28);

    }

    puVar2 = puVar6;

    if (*(char *)(iVar3 + 0x28) != '\0') {

      *(uint8_t *)(iVar3 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

    }

    for (; puVar2 != puVar5; puVar2 = puVar2 + 1) {

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 4 +

                           *(int *)(param_1 + 0x250)) + 0x220))(*puVar2,0);

    }

  }

  FUN_004c3720(_param_2);

  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = pvStack_c;

    return _param_2;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar6);

}
