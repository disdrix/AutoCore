// =============================================================================
// FUN_00408640
// -----------------------------------------------------------------------------
// Stable ID: aa_00408640
// Address:   0x00408640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00408640 @ 0x00408640
// Stable ID: aa_00408640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00407000×2, FUN_00409b60×2, FUN_0040a670×2, FUN_00408640, FUN_00418130, FUN_0045f050, FUN_00465bc0.
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

void __fastcall FUN_00408640(uint param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int extraout_ECX;

  int iVar5;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd0f0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffb4;

  local_40 = *param_4;

  local_3c = param_4[1];

  local_38 = param_4[2];

  local_34 = param_4[3];

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    local_24 = 0;

  }

  else {

    local_24 = *(int *)(param_2 + 0xc) - iVar3 >> 4;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_2 + 8) - iVar3 >> 4;

    }

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffb4;

    if (0xfffffffU - iVar5 < param_1) {

      ExceptionList = &local_10;

      local_24 = FUN_00418130();

      iVar3 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar3 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_2 + 8) - iVar3 >> 4;

    }

    if (local_24 < iVar5 + param_1) {

      if (0xfffffff - (local_24 >> 1) < local_24) {

        local_24 = 0;

      }

      else {

        local_24 = local_24 + (local_24 >> 1);

      }

      if (iVar3 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_2 + 8) - iVar3 >> 4;

      }

      if (local_24 < iVar5 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 4;

        }

        local_24 = iVar3 + param_1;

      }

      local_24 = local_24 << 4;

      local_1c = operator_new(local_24);

      local_8 = 0;

      local_20 = FUN_00409b60(*(uint32_t /* width from decompiler */ *)(param_2 + 4),param_3);

      local_20 = FUN_00407000(&local_40);

      FUN_00409b60(param_3,*(uint32_t /* width from decompiler */ *)(param_2 + 8));

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 8) - (int)pvVar1 >> 4;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_2 + 0xc) = local_24 + (int)local_1c;

      *(void **)(param_2 + 8) = (void *)((param_1 + iVar3) * 0x10 + (int)local_1c);

      *(void **)(param_2 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_2 + 8);

    if ((uint)(iVar3 - param_3 >> 4) < param_1) {

      local_18 = param_1 * 0x10;

      FUN_0040a670(param_3,local_18 + param_3,param_2,local_28);

      local_8 = 2;

      FUN_00407000(&local_40);

      local_8 = 0xffffffff;

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_18;

    }

    else {

      local_18 = param_1 * 0x10;

      uVar4 = FUN_0040a670(iVar3 + param_1 * -0x10,iVar3,param_2,local_2c);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar4;

      FUN_0045f050(local_30);

    }

    FUN_00465bc0();

  }

  ExceptionList = local_10;

  return;

}
