// =============================================================================
// FUN_00510080
// -----------------------------------------------------------------------------
// Stable ID: aa_00510080
// Address:   0x00510080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00510080 @ 0x00510080
// Stable ID: aa_00510080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_0050ed80×4, FUN_005088b0×2, FUN_0050fb60×2, FUN_005086a0, FUN_00508800, FUN_0050eb00, FUN_00510080.
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

void __thiscall FUN_00510080(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint extraout_ECX;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ local_130 [71];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a3230;

  local_10 = ExceptionList;

  puVar7 = local_130;

  for (iVar4 = 0x47; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar7 = *param_4;

    param_4 = param_4 + 1;

    puVar7 = puVar7 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar4) / 0x11c;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x11c;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xfffffec4;

    if (0xe6c2b4U - iVar4 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xfffffec4;

      FUN_00508800();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x11c;

    }

    if (uVar5 < iVar4 + param_3) {

      if (0xe6c2b4 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x11c;

      }

      if (uVar5 < iVar4 + param_3) {

        iVar4 = FUN_005086a0();

        uVar5 = iVar4 + param_3;

      }

      pvVar2 = operator_new(uVar5 * 0x11c);

      local_8 = 0;

      uVar3 = FUN_0050ed80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar2,param_1,param_2);

      uVar3 = FUN_0050fb60(uVar3,param_3,local_130);

      FUN_0050ed80(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar3,param_1,param_2);

      iVar4 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x11c;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x11c + (int)pvVar2);

      *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar4) * 0x11c);

      *(void **)(param_1 + 4) = pvVar2;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    iVar1 = param_3 * 0x11c;

    if ((uint)((iVar4 - param_2) / 0x11c) < param_3) {

      FUN_0050ed80(param_2,iVar4,iVar1 + param_2,param_1,param_2);

      local_8 = 2;

      FUN_0050fb60(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x11c,

                   local_130);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

      FUN_005088b0(param_2,*(int *)(param_1 + 8) + param_3 * -0x11c,local_130);

      ExceptionList = local_10;

      return;

    }

    iVar6 = iVar4 + param_3 * -0x11c;

    uVar3 = FUN_0050ed80(iVar6,iVar4,iVar4,param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_0050eb00(param_2,iVar6,iVar4);

    FUN_005088b0(param_2,iVar1 + param_2,local_130);

  }

  ExceptionList = local_10;

  return;

}
