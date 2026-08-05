// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_00406f00×2, FUN_0040a600×2, FUN_00412a80×2, FUN_00409ed0, FUN_00412730, FUN_00418130, FUN_004426e0, SkillSet_GetEntryCount.
//  - Return sites: 3.

// =============================================================================
// Skill_Uses_SkillSet_GetEntryCount
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "SkillSet_GetEntryCount"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_00412730 clean capture (not modernized).
//
// Address:  0x00412730  (autoassault.exe, image base 0x400000)
// Stable:   aa_00412730
// Stable ID: aa_00412730
// System:   skills-abilities
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_00412730_*.md
//           Original Ghidra symbol: FUN_00412730
//
// Exactness: Body mirrors reconstructed-exact/FUN_00412730*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Skill_Uses_SkillSet_GetEntryCount
// -----------------------------------------------------------------------------
// Stable ID: aa_00412730
// Address:   0x00412730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "SkillSet_GetEntryCount"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_Uses_SkillSet_GetEntryCount(void *param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint extraout_ECX;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd100;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa8;

  local_4c = *param_4;

  local_48 = param_4[1];

  local_44 = param_4[2];

  local_40 = param_4[3];

  local_3c = param_4[4];

  local_38 = param_4[5];

  iVar4 = *(int *)((int)param_1 + 4);

  if (iVar4 == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = (*(int *)((int)param_1 + 0xc) - iVar4) / 0x18;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)((int)param_1 + 8) - iVar4) / 0x18;

    }

    uVar6 = param_3;

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffa8;

    if (0xaaaaaaaU - iVar3 < param_3) {

      ExceptionList = &local_10;

      FUN_00418130();

      uVar6 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)((int)param_1 + 8) - iVar4) / 0x18;

    }

    if (uVar7 < iVar3 + uVar6) {

      if (0xaaaaaaa - (uVar7 >> 1) < uVar7) {

        uVar7 = 0;

      }

      else {

        uVar7 = uVar7 + (uVar7 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)((int)param_1 + 8) - iVar4) / 0x18;

      }

      if (uVar7 < iVar4 + uVar6) {

        iVar4 = SkillSet_GetEntryCount(param_1);

        uVar7 = iVar4 + param_3;

      }

      local_24 = uVar7 * 0x18;

      local_1c = operator_new(local_24);

      local_8 = 0;

      local_20 = FUN_00412a80(*(uint32_t /* width from decompiler */ *)((int)param_1 + 4),param_2);

      local_20 = FUN_00406f00(&local_4c);

      FUN_00412a80(param_2,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

      local_8 = 0xffffffff;

      pvVar1 = *(void **)((int)param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)((int)param_1 + 8) - (int)pvVar1) / 0x18;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)((int)param_1 + 0xc) = local_24 + (int)local_1c;

      *(void **)((int)param_1 + 8) = (void *)((int)local_1c + (param_3 + iVar4) * 0x18);

      *(void **)((int)param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)((int)param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0x18) < uVar6) {

      local_18 = uVar6 * 0x18;

      FUN_0040a600(param_2,local_18 + param_2,param_1,local_2c);

      local_8 = 2;

      FUN_00406f00(&local_4c);

      local_8 = 0xffffffff;

      *(int *)((int)param_1 + 8) = *(int *)((int)param_1 + 8) + local_18;

    }

    else {

      local_18 = uVar6 * 0x18;

      local_28 = iVar4 + uVar6 * -0x18;

      uVar5 = FUN_0040a600(local_28,iVar4,param_1,local_30);

      *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

      FUN_00409ed0(local_34);

    }

    FUN_004426e0();

  }

  ExceptionList = local_10;

  return;

}
