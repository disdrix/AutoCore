// =============================================================================
// FUN_00608760
// -----------------------------------------------------------------------------
// Stable ID: aa_00608760
// Address:   0x00608760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00608760 @ 0x00608760
// Stable ID: aa_00608760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_005dd920×4, FUN_004cb2e0×2, CONCAT44, FUN_0041d5a0, FUN_0051b6e0, FUN_006086a0, FUN_00608720, FUN_00608760.
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

void __thiscall FUN_00608760(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  uint uVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  uint64_t uVar9;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a81e0;

  local_10 = ExceptionList;

  local_24 = *param_4;

  local_20 = param_4[1];

  local_1c = param_4[2];

  local_18 = param_4[3];

  iVar7 = *(int *)(param_1 + 4);

  local_14 = &stack0xffffffd0;

  if (iVar7 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_1 + 0xc) - iVar7 >> 4;

  }

  uVar9 = CONCAT44(iVar7,iVar3);

  if (param_3 != 0) {

    if (iVar7 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 4;

    }

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffd0;

    if (0xfffffffU - iVar7 < param_3) {

      ExceptionList = &local_10;

      uVar9 = FUN_006086a0();

      puVar2 = local_14;

    }

    local_14 = puVar2;

    iVar7 = (int)((ulonglong)uVar9 >> 0x20);

    uVar4 = (uint)uVar9;

    if (iVar7 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 8) - iVar7 >> 4;

    }

    if (uVar4 < iVar3 + param_3) {

      if (0xfffffff - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (iVar7 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - iVar7 >> 4;

      }

      if (uVar4 < iVar3 + param_3) {

        if (iVar7 == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 4;

        }

        uVar4 = iVar7 + param_3;

      }

      pvVar5 = operator_new(uVar4 * 0x10);

      local_8 = 0;

      iVar7 = FUN_005dd920(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar5,param_1,param_2);

      FUN_00608720(iVar7,param_3,&local_24,param_1,param_2);

      FUN_005dd920(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar7 + param_3 * 0x10,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - (int)pvVar1 >> 4;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar4 * 0x10 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar7) * 0x10 + (int)pvVar5);

      *(void **)(param_1 + 4) = pvVar5;

      ExceptionList = local_10;

      return;

    }

    iVar7 = *(int *)(param_1 + 8);

    if ((uint)(iVar7 - param_2 >> 4) < param_3) {

      iVar3 = param_3 * 0x10;

      FUN_005dd920(param_2,iVar7,iVar3 + param_2,param_1,iVar3);

      local_8 = 2;

      FUN_0041d5a0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 4),&local_24)

      ;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar3;

      FUN_004cb2e0(param_2,*(int *)(param_1 + 8) + param_3 * -0x10,&local_24);

      ExceptionList = local_10;

      return;

    }

    iVar3 = param_3 * 0x10;

    iVar8 = iVar7 + param_3 * -0x10;

    uVar6 = FUN_005dd920(iVar8,iVar7,iVar7,param_1,iVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

    FUN_0051b6e0(param_2,iVar8,iVar7,iVar3);

    FUN_004cb2e0(param_2,iVar3 + param_2,&local_24);

  }

  ExceptionList = local_10;

  return;

}
