// =============================================================================
// FUN_005973d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005973d0
// Address:   0x005973d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005973d0 @ 0x005973d0
// Stable ID: aa_005973d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_00596700×4, FUN_00596180×2, FUN_00437d80, FUN_00596100, FUN_00596680, FUN_00596980, FUN_005973a0, FUN_005973d0.
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

void __thiscall FUN_005973d0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint8_t *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

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

  puStack_c = &LAB_009a5aa0;

  local_10 = ExceptionList;

  local_30 = param_4[3];

  local_38 = param_4[1];

  local_3c = *param_4;

  iVar3 = *(int *)(param_1 + 4);

  local_2c = param_4[4];

  local_34 = param_4[2];

  local_28 = param_4[5];

  local_24 = param_4[6];

  local_20 = param_4[7];

  local_1c = param_4[8];

  local_18 = param_4[9];

  local_14 = &stack0xffffffb8;

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0x28;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0x28;

    }

    ExceptionList = &local_10;

    puVar1 = &stack0xffffffb8;

    if (0x6666666U - iVar2 < param_3) {

      ExceptionList = &local_10;

      FUN_00596100();

      uVar6 = extraout_ECX;

      puVar1 = local_14;

    }

    local_14 = puVar1;

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0x28;

    }

    if (uVar6 < iVar2 + param_3) {

      if (0x6666666 - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0x28;

      }

      if (uVar6 < iVar3 + param_3) {

        iVar3 = FUN_00437d80();

        uVar6 = iVar3 + param_3;

      }

      pvVar4 = operator_new(uVar6 * 0x28);

      local_8 = 0;

      iVar3 = FUN_00596700(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4,param_1,param_2);

      FUN_00596980(iVar3,param_3,&local_3c,param_1,param_2);

      FUN_00596700(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar3 + param_3 * 0x28,param_1,param_2);

      iVar3 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0x28 + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x28);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_1 + 8);

    if ((uint)((iVar3 - param_2) / 0x28) < param_3) {

      iVar2 = param_3 * 0x28;

      FUN_00596700(param_2,iVar3,iVar2 + param_2,param_1,iVar2);

      local_8 = 2;

      FUN_005973a0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x28,

                   &local_3c);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

      FUN_00596180(param_2,*(int *)(param_1 + 8) + param_3 * -0x28,&local_3c);

      ExceptionList = local_10;

      return;

    }

    iVar2 = iVar3 + param_3 * -0x28;

    uVar5 = FUN_00596700(iVar2,iVar3,iVar3,param_1,iVar2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_00596680(param_2,iVar2,iVar3);

    FUN_00596180(param_2,param_3 * 0x28 + param_2,&local_3c);

  }

  ExceptionList = local_10;

  return;

}
