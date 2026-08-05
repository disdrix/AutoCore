// =============================================================================
// FUN_00603f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00603f70
// Address:   0x00603f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00603f70 @ 0x00603f70
// Stable ID: aa_00603f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00603780×4, CONCAT31×2, FUN_006035d0×2, FUN_0040f840, FUN_0053c950, FUN_006026a0, FUN_006034d0, FUN_00603be0.
//  - Return sites: 3.

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

void __thiscall FUN_00603f70(void *param_1,int param_2,uint param_3,int param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_34 [4];

  void *local_30;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  void *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a7f08;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc0;

  ExceptionList = &local_10;

  local_18 = param_1;

  FUN_0040f840(param_4);

  local_24 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x10);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14);

  iVar2 = *(int *)((int)param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)((int)param_1 + 0xc) - iVar2) / 0x18;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)((int)param_1 + 8) - iVar2) / 0x18;

    }

    if (0xaaaaaaaU - iVar1 < param_3) {

      FUN_006026a0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)((int)param_1 + 8) - iVar2) / 0x18;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0xaaaaaaa - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)((int)param_1 + 8) - iVar2) / 0x18;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = SkillSet_GetEntryCount(param_1);

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x18);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar3;

      iVar2 = FUN_00603780(*(uint32_t /* width from decompiler */ *)((int)param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_00603be0(iVar2,param_3,local_34,param_1,param_2);

      FUN_00603780(param_2,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8),iVar2 + param_3 * 0x18,param_1,param_2)

      ;

      iVar2 = 0;

      if (*(int *)((int)param_1 + 4) != 0) {

        iVar2 = (*(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4)) / 0x18;

      }

      if (*(int *)((int)param_1 + 4) != 0) {

        FUN_0053c950(*(int *)((int)param_1 + 4),*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)param_1 + 4));

      }

      *(void **)((int)param_1 + 0xc) = (void *)(uVar5 * 0x18 + (int)pvVar3);

      *(void **)((int)param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x18);

      *(void **)((int)param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)((int)param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0x18) < param_3) {

        FUN_00603780(param_2,iVar2,param_3 * 0x18 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00603ed0(*(int *)((int)param_1 + 8),

                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x18,local_34);

        *(int *)((int)param_1 + 8) = *(int *)((int)param_1 + 8) + param_3 * 0x18;

        local_8 = 0;

        FUN_006035d0(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x18,local_34);

      }

      else {

        iVar1 = iVar2 + param_3 * -0x18;

        uVar4 = FUN_00603780(iVar1,iVar2,iVar2,param_1,iVar1);

        *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar4;

        FUN_006034d0(param_2,iVar1,iVar2,iVar1);

        FUN_006035d0(param_2,param_3 * 0x18 + param_2,local_34);

      }

    }

  }

  if (local_30 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_30);

  }

  ExceptionList = local_10;

  return;

}
