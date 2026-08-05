// =============================================================================
// FUN_006a0ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a0ac0
// Address:   0x006a0ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a0ac0 @ 0x006a0ac0
// Stable ID: aa_006a0ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00422580×4, CONCAT31×2, FUN_0069a6a0×2, FUN_00422160, FUN_0056f570, FUN_00690330, FUN_00691590, FUN_0069ac30.
//  - Return sites: 2.

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

void __thiscall FUN_006a0ac0(void *param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint8_t *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  void *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009ab098;

  local_10 = ExceptionList;

  local_34 = *param_4;

  local_30 = param_4[1];

  local_2c = param_4[2];

  local_28 = param_4[3];

  local_24 = param_4[4];

  local_20 = param_4[5];

  local_14 = &stack0xffffffc0;

  iVar3 = *(int *)((int)param_1 + 4);

  uVar6 = 0;

  local_8 = 0;

  if (iVar3 != 0) {

    uVar6 = (*(int *)((int)param_1 + 0xc) - iVar3) / 0x18;

  }

  ExceptionList = &local_10;

  local_18 = param_1;

  puVar1 = &stack0xffffffc0;

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

    }

    ExceptionList = &local_10;

    puVar1 = &stack0xffffffc0;

    if (0xaaaaaaaU - iVar2 < param_3) {

      ExceptionList = &local_10;

      FUN_00690330();

      uVar6 = extraout_ECX;

      puVar1 = local_14;

    }

    local_14 = puVar1;

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

    }

    if (uVar6 < iVar2 + param_3) {

      if (0xaaaaaaa - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

      }

      if (uVar6 < iVar3 + param_3) {

        iVar3 = SkillSet_GetEntryCount(param_1);

        uVar6 = iVar3 + param_3;

      }

      pvVar4 = operator_new(uVar6 * 0x18);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar4;

      iVar3 = FUN_00422580(*(uint32_t /* width from decompiler */ *)((int)param_1 + 4),param_2,pvVar4,param_1,param_2);

      FUN_0069ac30(iVar3,param_3,&local_34,param_1,param_2);

      FUN_00422580(param_2,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8),iVar3 + param_3 * 0x18,param_1,param_2)

      ;

      local_8 = 0;

      iVar3 = 0;

      if (*(int *)((int)param_1 + 4) != 0) {

        iVar3 = (*(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4)) / 0x18;

      }

      if (*(int *)((int)param_1 + 4) != 0) {

        FUN_00691590(*(int *)((int)param_1 + 4),*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)param_1 + 4));

      }

      *(void **)((int)param_1 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);

      *(void **)((int)param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x18);

      *(void **)((int)param_1 + 4) = pvVar4;

      puVar1 = local_14;

    }

    else {

      iVar3 = *(int *)((int)param_1 + 8);

      if ((uint)((iVar3 - param_2) / 0x18) < param_3) {

        FUN_00422580(param_2,iVar3,param_3 * 0x18 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0069b340(*(int *)((int)param_1 + 8),

                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x18,&local_34);

        iVar3 = *(int *)((int)param_1 + 8) + param_3 * 0x18;

        *(int *)((int)param_1 + 8) = iVar3;

        FUN_0069a6a0(param_2,iVar3 + param_3 * -0x18,&local_34);

        puVar1 = local_14;

      }

      else {

        iVar2 = iVar3 + param_3 * -0x18;

        uVar5 = FUN_00422580(iVar2,iVar3,iVar3,param_1,iVar2);

        *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

        FUN_00422160(param_2,iVar2,iVar3,iVar2);

        FUN_0069a6a0(param_2,param_3 * 0x18 + param_2,&local_34);

        puVar1 = local_14;

      }

    }

  }

  local_14 = puVar1;

  local_8 = 0xffffffff;

  FUN_0056f570();

  ExceptionList = local_10;

  return;

}
