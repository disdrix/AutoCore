// =============================================================================
// FUN_0056fab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056fab0
// Address:   0x0056fab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056fab0 @ 0x0056fab0
// Stable ID: aa_0056fab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×13, return×4, for×1.
//  - Notable callees: FUN_0056f030×4, FUN_005df740×2, CONCAT44, FUN_0056eba0, FUN_0056f1e0, FUN_0056fab0, FUN_005dfff0, FUN_005e0020.
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

void __thiscall FUN_0056fab0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint uVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ local_34 [8];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a4ed0;

  local_10 = ExceptionList;

  iVar6 = *(int *)(param_1 + 4);

  local_14 = &stack0xffffffc0;

  puVar7 = local_34;

  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar7 = *param_4;

    param_4 = param_4 + 1;

    puVar7 = puVar7 + 1;

  }

  if (iVar6 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = *(int *)(param_1 + 0xc) - iVar6 >> 5;

  }

  uVar8 = CONCAT44(iVar6,iVar5);

  if (param_3 != 0) {

    if (iVar6 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 5;

    }

    ExceptionList = &local_10;

    if (0x7ffffffU - iVar6 < param_3) {

      ExceptionList = &local_10;

      uVar8 = FUN_0056eba0();

    }

    iVar6 = (int)((ulonglong)uVar8 >> 0x20);

    uVar2 = (uint)uVar8;

    if (iVar6 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar6 >> 5;

    }

    if (uVar2 < iVar5 + param_3) {

      if (0x7ffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar6 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar6 >> 5;

      }

      if (uVar2 < iVar5 + param_3) {

        if (iVar6 == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 5;

        }

        uVar2 = iVar6 + param_3;

      }

      pvVar3 = operator_new(uVar2 * 0x20);

      local_8 = 0;

      iVar6 = FUN_0056f030(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_0056f1e0(iVar6,param_3,local_34,param_1,param_2);

      FUN_0056f030(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar6 + param_3 * 0x20,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 5;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 0x20 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar6) * 0x20 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar6 = *(int *)(param_1 + 8);

    if ((uint)(iVar6 - param_2 >> 5) < param_3) {

      iVar5 = param_3 * 0x20;

      FUN_0056f030(param_2,iVar6,iVar5 + param_2,param_1,iVar5);

      local_8 = 2;

      FUN_005e0020(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 5),local_34);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar5;

      FUN_005df740(param_2,*(int *)(param_1 + 8) + param_3 * -0x20,local_34);

      ExceptionList = local_10;

      return;

    }

    iVar5 = iVar6 + param_3 * -0x20;

    uVar4 = FUN_0056f030(iVar5,iVar6,iVar6,param_1,param_3 * 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_005dfff0(param_2,iVar5,iVar6);

    FUN_005df740(param_2,param_3 * 0x20 + param_2,local_34);

  }

  ExceptionList = local_10;

  return;

}
