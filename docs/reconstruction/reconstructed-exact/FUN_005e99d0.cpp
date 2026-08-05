// =============================================================================
// FUN_005e99d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e99d0
// Address:   0x005e99d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e99d0 @ 0x005e99d0
// Stable ID: aa_005e99d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_005e9840×4, FUN_004044e0×2, FUN_005e96c0, FUN_005e98d0, FUN_005e99a0, FUN_005e99d0, FUN_00690210, FUN_00690970.
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

void __thiscall FUN_005e99d0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint8_t *puVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  int iVar6;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

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

  puStack_c = &LAB_009a7790;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa8;

  local_4c = *param_4;

  local_48 = param_4[1];

  local_44 = param_4[2];

  local_40 = param_4[3];

  local_3c = param_4[4];

  local_38 = param_4[5];

  local_34 = param_4[6];

  local_30 = param_4[7];

  local_2c = param_4[8];

  local_28 = param_4[9];

  local_24 = param_4[10];

  local_20 = param_4[0xb];

  iVar2 = *(int *)(param_1 + 4);

  local_1c = param_4[0xc];

  local_18 = param_4[0xd];

  if (iVar2 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x38;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    ExceptionList = &local_10;

    puVar1 = &stack0xffffffa8;

    if (0x4924924U - iVar2 < param_3) {

      ExceptionList = &local_10;

      FUN_005e96c0();

      uVar5 = extraout_ECX;

      puVar1 = local_14;

    }

    local_14 = puVar1;

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    if (uVar5 < iVar2 + param_3) {

      if (0x4924924 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00690210();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x38);

      local_8 = 0;

      iVar2 = FUN_005e9840(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_005e98d0(iVar2,param_3,&local_4c,param_1,param_2);

      FUN_005e9840(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x38,param_1,param_2);

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x38 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x38);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar2 = *(int *)(param_1 + 8);

    if ((uint)((iVar2 - param_2) / 0x38) < param_3) {

      iVar6 = param_3 * 0x38;

      FUN_005e9840(param_2,iVar2,iVar6 + param_2,param_1,iVar6);

      local_8 = 2;

      FUN_005e99a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x38,

                   &local_4c);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar6;

      FUN_004044e0(param_2,*(int *)(param_1 + 8) + param_3 * -0x38,&local_4c);

      ExceptionList = local_10;

      return;

    }

    iVar6 = iVar2 + param_3 * -0x38;

    uVar4 = FUN_005e9840(iVar6,iVar2,iVar2,param_1,param_3 * 0x38);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_00690970(param_2,iVar6,iVar2);

    FUN_004044e0(param_2,param_3 * 0x38 + param_2,&local_4c);

  }

  ExceptionList = local_10;

  return;

}
