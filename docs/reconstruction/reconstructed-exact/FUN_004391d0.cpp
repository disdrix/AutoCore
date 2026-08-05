// =============================================================================
// FUN_004391d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004391d0
// Address:   0x004391d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004391d0 @ 0x004391d0
// Stable ID: aa_004391d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×14, return×4.
//  - Notable callees: FUN_0043ac80×4, CONCAT31×2, FUN_00439ec0×2, FUN_0043aa00×2, FUN_00437d80, FUN_004391b0, FUN_004391d0, FUN_00439570.
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

void FUN_004391d0(int param_1,int param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_40 [4];

  void *local_3c;

  void *local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be9f8;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffb4;

  ExceptionList = &local_10;

  FUN_00439570(local_40);

  uVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x28;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x28;

    }

    if (0x6666666U - iVar1 < param_3) {

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x28;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x6666666 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x28;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00437d80();

        uVar5 = iVar2 + param_3;

      }

      local_18 = uVar5 * 0x28;

      pvVar3 = operator_new(local_18);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_0043ac80(param_2,pvVar3,param_2);

      FUN_0043aa00(iVar2,param_3,param_2);

      FUN_0043ac80(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x28,param_2);

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x28;

      }

      if (iVar2 != 0) {

        FUN_004391b0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint *)(param_1 + 0xc) = local_18 + (int)pvVar3;

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar1) * 0x28);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      local_18 = *(uint *)(param_1 + 8);

      if ((uint)((int)(local_18 - param_2) / 0x28) < param_3) {

        FUN_0043ac80(local_18,param_3 * 0x28 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0043aa00(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x28,

                     param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x28;

        FUN_00439ec0(*(int *)(param_1 + 8) + param_3 * -0x28);

      }

      else {

        uVar4 = FUN_0043ac80(local_18,local_18,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_0043a880(param_2);

        FUN_00439ec0(param_3 * 0x28 + param_2);

      }

    }

  }

  if (local_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_24);

  }

  local_24 = (void *)0x0;

  local_20 = 0;

  local_1c = 0;

  if (local_3c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_3c);

  }

  ExceptionList = local_10;

  return;

}
