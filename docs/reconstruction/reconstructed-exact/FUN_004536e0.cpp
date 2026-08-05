// =============================================================================
// FUN_004536e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004536e0
// Address:   0x004536e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004536e0 @ 0x004536e0
// Stable ID: aa_004536e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_0046b6a0×4, CONCAT31×2, FUN_0046b580×2, FUN_00426f20, FUN_004396a0, FUN_004536e0, FUN_004540b0, FUN_00455bc0.
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

void FUN_004536e0(int param_1,int param_2,uint param_3)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  int iVar6;

  uint8_t local_28 [4];

  void *local_24;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be738;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffcc;

  ExceptionList = &local_10;

  FUN_004396a0(local_28);

  iVar6 = 0;

  local_8 = 0;

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_1 + 0xc) - iVar3 >> 4;

  }

  if (param_3 != 0) {

    if (iVar3 != 0) {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    if (0xfffffffU - iVar6 < param_3) {

      uVar2 = FUN_004540b0();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    if (uVar2 < iVar6 + param_3) {

      if (0xfffffff - (uVar2 >> 1) < uVar2) {

        local_18 = 0;

      }

      else {

        local_18 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

      }

      if (local_18 < iVar6 + param_3) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_1 + 8) - iVar3 >> 4;

        }

        local_18 = iVar3 + param_3;

      }

      local_18 = local_18 << 4;

      pvVar4 = operator_new(local_18);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar3 = FUN_0046b6a0(param_2,pvVar4,param_1,param_2);

      FUN_0046b580(iVar3,local_28,param_1,param_2);

      FUN_0046b6a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar3 + param_3 * 0x10,param_1,param_2);

      iVar3 = *(int *)(param_1 + 4);

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

      }

      if (iVar3 != 0) {

        FUN_00426f20(param_2);

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint *)(param_1 + 0xc) = local_18 + (int)pvVar4;

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar6) * 0x10 + (int)pvVar4);

      *(void **)(param_1 + 4) = pvVar4;

    }

    else {

      local_18 = *(uint *)(param_1 + 8);

      if ((uint)((int)(local_18 - param_2) >> 4) < param_3) {

        uVar2 = param_3 * 0x10 + param_2;

        uVar1 = local_18;

        local_18 = uVar2;

        FUN_0046b6a0(uVar1,uVar2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0046b580(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_28,param_1,param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x10;

      }

      else {

        uVar5 = FUN_0046b6a0(local_18,local_18,param_1,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        FUN_00455bc0();

      }

      FUN_0046b510();

    }

  }

  if (local_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_24);

  }

  ExceptionList = local_10;

  return;

}
