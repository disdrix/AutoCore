// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b630
// -----------------------------------------------------------------------------
// Stable ID: aa_0069b630
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069b630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_00422580×4, FUN_0069a6a0×2, FUN_00422160, FUN_0069a620, FUN_0069ac30, FUN_0069b340, FUN_0069b630, SkillSet_GetEntryCount.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b630(void *param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint8_t *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aae00;

  local_10 = ExceptionList;

  local_2c = *param_4;

  local_28 = param_4[1];

  iVar3 = *(int *)((int)param_1 + 4);

  local_24 = param_4[2];

  local_20 = param_4[3];

  local_1c = param_4[4];

  local_18 = param_4[5];

  local_14 = &stack0xffffffc8;

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)((int)param_1 + 0xc) - iVar3) / 0x18;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

    }

    ExceptionList = &local_10;

    puVar1 = &stack0xffffffc8;

    if (0xaaaaaaaU - iVar2 < param_3) {

      ExceptionList = &local_10;

      FUN_0069a620();

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

      local_8 = 0;

      iVar3 = FUN_00422580(*(uint32_t /* width from decompiler */ *)((int)param_1 + 4),param_2,pvVar4,param_1,param_2);

      FUN_0069ac30(iVar3,param_3,&local_2c,param_1,param_2);

      FUN_00422580(param_2,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8),iVar3 + param_3 * 0x18,param_1,param_2)

      ;

      iVar3 = 0;

      if (*(int *)((int)param_1 + 4) != 0) {

        iVar3 = (*(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4)) / 0x18;

      }

      if (*(void **)((int)param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)param_1 + 4));

      }

      *(void **)((int)param_1 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);

      *(void **)((int)param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x18);

      *(void **)((int)param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)((int)param_1 + 8);

    if ((uint)((iVar3 - param_2) / 0x18) < param_3) {

      iVar2 = param_3 * 0x18;

      FUN_00422580(param_2,iVar3,iVar2 + param_2,param_1,iVar2);

      local_8 = 2;

      FUN_0069b340(*(int *)((int)param_1 + 8),

                   param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x18,&local_2c);

      iVar2 = *(int *)((int)param_1 + 8) + iVar2;

      *(int *)((int)param_1 + 8) = iVar2;

      FUN_0069a6a0(param_2,iVar2 + param_3 * -0x18,&local_2c);

      ExceptionList = local_10;

      return;

    }

    iVar2 = iVar3 + param_3 * -0x18;

    uVar5 = FUN_00422580(iVar2,iVar3,iVar3,param_1,iVar2);

    *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

    FUN_00422160(param_2,iVar2,iVar3,iVar2);

    FUN_0069a6a0(param_2,param_3 * 0x18 + param_2,&local_2c);

  }

  ExceptionList = local_10;

  return;

}
