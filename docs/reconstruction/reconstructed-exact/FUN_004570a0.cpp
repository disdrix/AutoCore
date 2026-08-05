// =============================================================================
// FUN_004570a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004570a0
// Address:   0x004570a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004570a0 @ 0x004570a0
// Stable ID: aa_004570a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_004574e0×4, CONCAT31×2, FUN_004573a0×2, FUN_00457400×2, FUN_004396a0, FUN_004540b0, FUN_00456fe0, FUN_004570a0.
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

void FUN_004570a0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_2c;

  uint8_t local_28 [4];

  void *local_24;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be698;

  local_10 = ExceptionList;

  local_2c = *param_4;

  local_14 = &stack0xffffffc8;

  ExceptionList = &local_10;

  FUN_004396a0(local_28);

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

      pvVar3 = operator_new(uVar5 * 0x14);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_004574e0(param_2,pvVar3,param_2);

      FUN_00457400(iVar2,&local_2c,param_2);

      FUN_004574e0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x14,param_2);

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

      }

      if (iVar2 != 0) {

        FUN_00456fe0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x14 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar1) * 0x14);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      local_18 = *(int *)(param_1 + 8);

      if ((uint)((local_18 - param_2) / 0x14) < param_3) {

        FUN_004574e0(local_18,param_3 * 0x14 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00457400(*(uint32_t /* width from decompiler */ *)(param_1 + 8),&local_2c,param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x14;

        FUN_004573a0(*(int *)(param_1 + 8) + param_3 * -0x14);

      }

      else {

        uVar4 = FUN_004574e0(local_18,local_18,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_004574b0(param_2);

        FUN_004573a0(param_3 * 0x14 + param_2);

      }

    }

  }

  if (local_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_24);

  }

  ExceptionList = local_10;

  return;

}
