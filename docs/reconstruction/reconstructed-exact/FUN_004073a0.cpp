// =============================================================================
// FUN_004073a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004073a0
// Address:   0x004073a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004073a0 @ 0x004073a0
// Stable ID: aa_004073a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_004e2e80×4, FUN_004e2f70×2, FUN_005739b0×2, FUN_004073a0, FUN_00418130, FUN_004e24d0.
//  - Return sites: 4.

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

void __thiscall FUN_004073a0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  uint uVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint uVar8;

  uint64_t uVar9;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd130;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc8;

  local_18 = *param_4;

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0xc) - iVar4 >> 2;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar4 >> 2;

    }

    uVar8 = param_3;

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffc8;

    if (0x3fffffffU - iVar7 < param_3) {

      ExceptionList = &local_10;

      uVar9 = FUN_00418130();

      uVar8 = (uint)((ulonglong)uVar9 >> 0x20);

      uVar3 = (uint)uVar9;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar4 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar4 >> 2;

    }

    if (uVar3 < iVar7 + uVar8) {

      if (0x3fffffff - (uVar3 >> 1) < uVar3) {

        uVar3 = 0;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

      }

      if (iVar4 == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - iVar4 >> 2;

      }

      if (uVar3 < iVar7 + uVar8) {

        if (iVar4 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(param_1 + 8) - iVar4 >> 2;

        }

        uVar3 = iVar4 + uVar8;

      }

      pvVar5 = operator_new(uVar3 * 4);

      local_8 = 0;

      uVar6 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar5);

      uVar6 = FUN_004e2f70(uVar6,param_3,&local_18);

      FUN_004e2e80(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar6);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((int)pvVar5 + (param_3 + iVar4) * 4);

      *(void **)(param_1 + 4) = pvVar5;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)(iVar4 - param_2 >> 2) < uVar8) {

      FUN_004e2e80(param_2,iVar4,uVar8 * 4 + param_2);

      local_8 = 2;

      FUN_004e2f70(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 2),&local_18)

      ;

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar8 * 4;

      FUN_005739b0(param_2,*(int *)(param_1 + 8) + uVar8 * -4,&local_18);

      ExceptionList = local_10;

      return;

    }

    iVar7 = iVar4 + uVar8 * -4;

    uVar6 = FUN_004e2e80(iVar7,iVar4,iVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

    FUN_004e24d0(param_2,iVar7,iVar4);

    FUN_005739b0(param_2,uVar8 * 4 + param_2,&local_18);

  }

  ExceptionList = local_10;

  return;

}
