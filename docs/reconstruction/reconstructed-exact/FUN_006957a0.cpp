// =============================================================================
// FUN_006957a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006957a0
// Address:   0x006957a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006957a0 @ 0x006957a0
// Stable ID: aa_006957a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_006944c0×4, CONCAT31×2, FUN_00693b00×2, FUN_00690240, FUN_00690330, FUN_00691720, FUN_006934a0, FUN_00694720.
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

void __thiscall FUN_006957a0(int param_1,int param_2,uint param_3,int param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_4c [4];

  void *local_48;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint8_t local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa8a8;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa8;

  ExceptionList = &local_10;

  local_18 = param_1;

  FUN_00691720(param_4);

  local_3c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x10);

  local_38 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14);

  local_34 = *(uint8_t *)(param_4 + 0x18);

  local_30 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20);

  local_28 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x24);

  local_24 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x28);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x2c);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x30;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x30;

    }

    if (0x5555555U - iVar1 < param_3) {

      FUN_00690330();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x30;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x5555555 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x30;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00690240();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x30);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar3;

      iVar2 = FUN_006944c0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_00694720(iVar2,param_3,local_4c,param_1,param_2);

      FUN_006944c0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x30,param_1,param_2);

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x30;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_006954c0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x30 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x30 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0x30) < param_3) {

        FUN_006944c0(param_2,iVar2,param_3 * 0x30 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00695540(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x30,

                     local_4c);

        iVar2 = *(int *)(param_1 + 8) + param_3 * 0x30;

        *(int *)(param_1 + 8) = iVar2;

        local_8 = 0;

        FUN_00693b00(param_2,iVar2 + param_3 * -0x30,local_4c);

      }

      else {

        iVar1 = iVar2 + param_3 * -0x30;

        uVar4 = FUN_006944c0(iVar1,iVar2,iVar2,param_1,iVar1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_006934a0(param_2,iVar1,iVar2,iVar1);

        FUN_00693b00(param_2,param_3 * 0x30 + param_2,local_4c);

      }

    }

  }

  if (local_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_48);

  }

  ExceptionList = local_10;

  return;

}
