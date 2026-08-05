// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00418e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00418e60
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00418e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_004190b0×4, FUN_00418dd0×2, FUN_00419110×2, FUN_00418130, FUN_00418e60, FUN_004190e0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00418e60(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  uint uVar6;

  int iVar7;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  void *local_24;

  uint local_20;

  uint32_t /* width from decompiler */ local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bced0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc4;

  local_30 = *param_4;

  local_2c = param_4[1];

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    local_20 = 0;

  }

  else {

    local_20 = *(int *)(param_1 + 0xc) - iVar3 >> 3;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar3 >> 3;

    }

    uVar6 = param_3;

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffc4;

    if (0x1fffffffU - iVar7 < param_3) {

      ExceptionList = &local_10;

      uVar8 = FUN_00418130();

      uVar6 = (uint)((ulonglong)uVar8 >> 0x20);

      local_20 = (uint)uVar8;

      iVar3 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar3 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar3 >> 3;

    }

    if (local_20 < iVar7 + uVar6) {

      if (0x1fffffff - (local_20 >> 1) < local_20) {

        local_20 = 0;

      }

      else {

        local_20 = local_20 + (local_20 >> 1);

      }

      if (iVar3 == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - iVar3 >> 3;

      }

      if (local_20 < iVar7 + uVar6) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_1 + 8) - iVar3 >> 3;

        }

        local_20 = iVar3 + uVar6;

      }

      local_20 = local_20 * 8;

      pvVar4 = operator_new(local_20);

      local_8 = 0;

      local_24 = pvVar4;

      local_1c = FUN_004190b0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4);

      local_1c = FUN_00418dd0(local_1c,param_3,&local_30);

      FUN_004190b0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_1c);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - (int)pvVar1 >> 3;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_20 + (int)pvVar4;

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 8);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_1 + 8);

    if ((uint)(iVar3 - param_2 >> 3) < uVar6) {

      local_18 = uVar6 * 8;

      FUN_004190b0(param_2,iVar3,local_18 + param_2);

      local_8 = 2;

      FUN_00418dd0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 3),&local_30)

      ;

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

      FUN_00419110(param_2,*(int *)(param_1 + 8) - local_18,&local_30);

      ExceptionList = local_10;

      return;

    }

    local_18 = uVar6 * 8;

    local_28 = iVar3 + uVar6 * -8;

    uVar5 = FUN_004190b0(local_28,iVar3,iVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_004190e0(param_2,local_28,iVar3);

    FUN_00419110(param_2,local_18 + param_2,&local_30);

  }

  ExceptionList = local_10;

  return;

}
