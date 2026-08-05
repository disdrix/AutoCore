// =============================================================================
// FUN_00446be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00446be0
// Address:   0x00446be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00446be0 @ 0x00446be0
// Stable ID: aa_00446be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_004488b0×4, CONCAT31×2, FUN_00448410×2, FUN_00446bc0, FUN_00446be0, FUN_004475e0, FUN_00447660, FUN_00447d90.
//  - Return sites: 2.

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

void FUN_00446be0(int param_1,int param_2,void *param_3,uint param_4)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  uint8_t local_20 [4];

  uint32_t /* width from decompiler */ *local_1c;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  uVar1 = (uint)param_3;

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be848;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xffffffd4;

  ExceptionList = &pvStack_10;

  FUN_004475e0(local_20,param_4);

  uVar6 = 0;

  local_8 = 0;

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 != 0) {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0xc;

  }

  if (uVar1 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

    }

    if (0x15555555U - iVar2 < uVar1) {

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

    }

    if (uVar6 < iVar2 + uVar1) {

      if (0x15555555 - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

      }

      if (uVar6 < iVar3 + uVar1) {

        iVar3 = FUN_00480c80();

        uVar6 = iVar3 + uVar1;

      }

      param_4 = uVar6 * 0xc;

      pvVar4 = operator_new(param_4);

      local_8 = CONCAT31(local_8._1_3_,1);

      param_3 = pvVar4;

      param_3 = (void *)FUN_004488b0(param_2,pvVar4,param_2);

      FUN_00448410(param_3,local_20,param_2);

      param_3 = (void *)((int)param_3 + uVar1 * 0xc);

      FUN_004488b0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3,param_2);

      iVar2 = 0;

      local_8 = 0;

      iVar3 = *(int *)(param_1 + 4);

      if (iVar3 != 0) {

        iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

      }

      if (iVar3 != 0) {

        FUN_00446bc0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint *)(param_1 + 0xc) = param_4 + (int)pvVar4;

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (uVar1 + iVar2) * 0xc);

      *(void **)(param_1 + 4) = pvVar4;

    }

    else {

      param_4 = *(uint *)(param_1 + 8);

      if ((uint)((int)(param_4 - param_2) / 0xc) < uVar1) {

        uVar6 = param_4;

        param_4 = uVar1 * 0xc;

        FUN_004488b0(uVar6,uVar1 * 0xc + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00448410(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_20,param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_4;

      }

      else {

        param_2 = param_4 + uVar1 * -0xc;

        uVar5 = FUN_004488b0(param_4,param_4,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        FUN_00448340(param_2);

      }

      FUN_00447d90();

    }

  }

  local_8 = 0xffffffff;

  FUN_00447660(&param_2,*local_1c,local_1c);

                    /* WARNING: Subroutine does not return */

  operator_delete(local_1c);

}
