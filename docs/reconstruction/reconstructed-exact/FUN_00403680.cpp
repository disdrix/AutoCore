// =============================================================================
// FUN_00403680
// -----------------------------------------------------------------------------
// Stable ID: aa_00403680
// Address:   0x00403680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00403680 @ 0x00403680
// Stable ID: aa_00403680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_004044c0×4, FUN_00402ea0×2, FUN_004044e0×2, FUN_00403680, FUN_00418130, FUN_00690210, FUN_00690970.
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

void __thiscall FUN_00403680(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_64 [14];

  int local_2c;

  int local_28;

  uint local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd200;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff90;

  puVar4 = local_64;

  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = *param_4;

    param_4 = param_4 + 1;

    puVar4 = puVar4 + 1;

  }

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    local_24 = 0;

  }

  else {

    local_24 = (*(int *)(param_1 + 0xc) - iVar3) / 0x38;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    ExceptionList = &local_10;

    if (0x4924924U - iVar3 < param_3) {

      ExceptionList = &local_10;

      FUN_00418130();

      local_24 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    if (local_24 < iVar3 + param_3) {

      if (0x4924924 - (local_24 >> 1) < local_24) {

        local_24 = 0;

      }

      else {

        local_24 = local_24 + (local_24 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

      }

      if (local_24 < iVar3 + param_3) {

        iVar3 = FUN_00690210();

        local_24 = iVar3 + param_3;

      }

      local_24 = local_24 * 0x38;

      local_1c = operator_new(local_24);

      local_8 = 0;

      local_20 = FUN_004044c0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,local_1c);

      local_20 = FUN_00402ea0(local_20,param_3,local_64);

      FUN_004044c0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_20);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x38;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_24 + (int)local_1c;

      *(void **)(param_1 + 8) = (void *)((int)local_1c + (param_3 + iVar3) * 0x38);

      *(void **)(param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    local_2c = *(int *)(param_1 + 8);

    local_28 = local_2c - param_2;

    if ((uint)(local_28 / 0x38) < param_3) {

      local_18 = param_3 * 0x38;

      FUN_004044c0(param_2,local_2c,local_18 + param_2);

      local_8 = 2;

      FUN_00402ea0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x38,

                   local_64);

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

      FUN_004044e0(param_2,*(int *)(param_1 + 8) - local_18,local_64);

      ExceptionList = local_10;

      return;

    }

    local_18 = param_3 * 0x38;

    iVar3 = local_2c + param_3 * -0x38;

    uVar2 = FUN_004044c0(iVar3,local_2c,local_2c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

    FUN_00690970(param_2,iVar3,local_2c);

    FUN_004044e0(param_2,local_18 + param_2,local_64);

  }

  ExceptionList = local_10;

  return;

}
