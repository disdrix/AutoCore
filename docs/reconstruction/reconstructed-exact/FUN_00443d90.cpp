// =============================================================================
// FUN_00443d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00443d90
// Address:   0x00443d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00443d90 @ 0x00443d90
// Stable ID: aa_00443d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00444560×4, CONCAT31×2, FUN_00444250×2, FUN_004444b0×2, FUN_00443d70, FUN_00443d90, FUN_004440a0, FUN_00444450.
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

void FUN_00443d90(int param_1,int param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_2c [8];

  void *local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be8c8;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc8;

  ExceptionList = &local_10;

  FUN_004440a0(local_2c);

  uVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x14;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

    }

    if (0xcccccccU - iVar1 < param_3) {

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0xccccccc - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_0045c230();

        uVar5 = iVar2 + param_3;

      }

      local_18 = uVar5 * 0x14;

      pvVar3 = operator_new(local_18);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_00444560(param_2,pvVar3,param_2);

      FUN_004444b0(iVar2,param_3,param_2);

      FUN_00444560(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x14,param_2);

      iVar1 = 0;

      local_8 = 0;

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 != 0) {

        iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

      }

      if (iVar2 != 0) {

        FUN_00443d70();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint *)(param_1 + 0xc) = local_18 + (int)pvVar3;

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar1) * 0x14);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      local_18 = *(uint *)(param_1 + 8);

      if ((uint)((int)(local_18 - param_2) / 0x14) < param_3) {

        uVar5 = local_18;

        local_18 = param_3 * 0x14;

        FUN_00444560(uVar5,param_3 * 0x14 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_004444b0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x14,

                     param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

        FUN_00444250(*(int *)(param_1 + 8) - local_18,local_2c);

      }

      else {

        iVar2 = local_18 + param_3 * -0x14;

        uVar4 = FUN_00444560(local_18,local_18,iVar2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_00444450(param_2,iVar2);

        FUN_00444250(param_3 * 0x14 + param_2,local_2c);

      }

    }

  }

  local_8 = 0xffffffff;

  if (local_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_24);

  }

  local_24 = (void *)0x0;

  local_20 = 0;

  local_1c = 0;

  FUN_0096efd0();

  ExceptionList = local_10;

  return;

}
