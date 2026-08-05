// =============================================================================
// FUN_00510be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00510be0
// Address:   0x00510be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00510be0 @ 0x00510be0
// Stable ID: aa_00510be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_0050ee80×4, FUN_00508970×2, FUN_0050fc50×2, FUN_00508740, FUN_00508800, FUN_0050ed00, FUN_00510be0.
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

void __thiscall FUN_00510be0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_12c [70];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a3270;

  local_10 = ExceptionList;

  puVar6 = local_12c;

  for (iVar4 = 0x46; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *param_4;

    param_4 = param_4 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar4) / 0x118;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x118;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xfffffec8;

    if (0xea0ea0U - iVar4 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xfffffec8;

      FUN_00508800();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x118;

    }

    if (uVar5 < iVar4 + param_3) {

      if (0xea0ea0 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x118;

      }

      if (uVar5 < iVar4 + param_3) {

        iVar4 = FUN_00508740();

        uVar5 = iVar4 + param_3;

      }

      pvVar1 = operator_new(uVar5 * 0x118);

      local_8 = 0;

      uVar2 = FUN_0050ee80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar1,param_1,param_2);

      uVar2 = FUN_0050fc50(uVar2,param_3,local_12c);

      FUN_0050ee80(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar2,param_1,param_2);

      iVar4 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x118;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x118 + (int)pvVar1);

      *(void **)(param_1 + 8) = (void *)((int)pvVar1 + (param_3 + iVar4) * 0x118);

      *(void **)(param_1 + 4) = pvVar1;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0x118) < param_3) {

      iVar3 = param_3 * 0x118;

      FUN_0050ee80(param_2,iVar4,iVar3 + param_2,param_1,iVar3);

      local_8 = 2;

      FUN_0050fc50(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x118,

                   local_12c);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar3;

      FUN_00508970(param_2,*(int *)(param_1 + 8) + param_3 * -0x118,local_12c);

      ExceptionList = local_10;

      return;

    }

    iVar3 = iVar4 + param_3 * -0x118;

    uVar2 = FUN_0050ee80(iVar3,iVar4,iVar4,param_1,iVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

    FUN_0050ed00(param_2,iVar3,iVar4);

    FUN_00508970(param_2,param_3 * 0x118 + param_2,local_12c);

  }

  ExceptionList = local_10;

  return;

}
