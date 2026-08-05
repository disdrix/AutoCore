// =============================================================================
// FUN_0053a520
// -----------------------------------------------------------------------------
// Stable ID: aa_0053a520
// Address:   0x0053a520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053a520 @ 0x0053a520
// Stable ID: aa_0053a520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_00537ec0×4, FUN_005378a0×2, FUN_005373f0, FUN_00537590, FUN_00537e90, FUN_00538750, FUN_00539ec0, FUN_0053a520.
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

void __thiscall FUN_0053a520(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_5c [18];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a3ec0;

  local_10 = ExceptionList;

  puVar6 = local_5c;

  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *param_4;

    param_4 = param_4 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar4) / 0x48;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar4) / 0x48;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffff98;

    if (0x38e38e3U - iVar1 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffff98;

      FUN_00537590();

      uVar5 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar4) / 0x48;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x38e38e3 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 0x48;

      }

      if (uVar5 < iVar4 + param_3) {

        iVar4 = FUN_005373f0();

        uVar5 = iVar4 + param_3;

      }

      pvVar2 = operator_new(uVar5 * 0x48);

      local_8 = 0;

      iVar4 = FUN_00537ec0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar2,param_1,param_2);

      FUN_00538750(iVar4,param_3,local_5c,param_1,param_2);

      FUN_00537ec0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar4 + param_3 * 0x48,param_1,param_2);

      iVar4 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x48 + (int)pvVar2);

      *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar4) * 0x48);

      *(void **)(param_1 + 4) = pvVar2;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0x48) < param_3) {

      iVar1 = param_3 * 0x48;

      FUN_00537ec0(param_2,iVar4,iVar1 + param_2,param_1,iVar1);

      local_8 = 2;

      FUN_00539ec0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x48,local_5c

                  );

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

      FUN_005378a0(param_2,*(int *)(param_1 + 8) + param_3 * -0x48,local_5c);

      ExceptionList = local_10;

      return;

    }

    iVar1 = iVar4 + param_3 * -0x48;

    uVar3 = FUN_00537ec0(iVar1,iVar4,iVar4,param_1,iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00537e90(param_2,iVar1,iVar4);

    FUN_005378a0(param_2,param_3 * 0x48 + param_2,local_5c);

  }

  ExceptionList = local_10;

  return;

}
