// =============================================================================
// FUN_00510360
// -----------------------------------------------------------------------------
// Stable ID: aa_00510360
// Address:   0x00510360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00510360 @ 0x00510360
// Stable ID: aa_00510360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_0050edc0×4, FUN_005088e0×2, FUN_0050fba0×2, FUN_005086d0, FUN_00508800, FUN_0050eb80, FUN_00510360.
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

void __thiscall FUN_00510360(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ local_140 [75];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a3240;

  local_10 = ExceptionList;

  puVar7 = local_140;

  for (iVar5 = 0x4b; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar7 = *param_4;

    param_4 = param_4 + 1;

    puVar7 = puVar7 + 1;

  }

  iVar5 = *(int *)(param_1 + 4);

  if (iVar5 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar5) / 300;

  }

  if (param_3 != 0) {

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 300;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xfffffeb4;

    if (0xda740dU - iVar2 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xfffffeb4;

      FUN_00508800();

      uVar6 = extraout_ECX;

    }

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 300;

    }

    if (uVar6 < iVar2 + param_3) {

      if (0xda740d - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar5 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - iVar5) / 300;

      }

      if (uVar6 < iVar5 + param_3) {

        iVar5 = FUN_005086d0();

        uVar6 = iVar5 + param_3;

      }

      pvVar3 = operator_new(uVar6 * 300);

      local_8 = 0;

      uVar4 = FUN_0050edc0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      uVar4 = FUN_0050fba0(uVar4,param_3,local_140);

      FUN_0050edc0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar4,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - (int)pvVar1) / 300;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 300 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar5) * 300);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar5 = *(int *)(param_1 + 8);

    if ((uint)((iVar5 - param_2) / 300) < param_3) {

      iVar2 = param_3 * 300;

      FUN_0050edc0(param_2,iVar5,iVar2 + param_2,param_1,iVar2);

      local_8 = 2;

      FUN_0050fba0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 300,local_140

                  );

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

      FUN_005088e0(param_2,*(int *)(param_1 + 8) + param_3 * -300,local_140);

      ExceptionList = local_10;

      return;

    }

    iVar2 = iVar5 + param_3 * -300;

    uVar4 = FUN_0050edc0(iVar2,iVar5,iVar5,param_1,iVar2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_0050eb80(param_2,iVar2,iVar5);

    FUN_005088e0(param_2,param_3 * 300 + param_2,local_140);

  }

  ExceptionList = local_10;

  return;

}
