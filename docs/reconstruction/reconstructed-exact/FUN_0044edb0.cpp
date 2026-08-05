// =============================================================================
// FUN_0044edb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044edb0
// Address:   0x0044edb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044edb0 @ 0x0044edb0
// Stable ID: aa_0044edb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×14, return×2.
//  - Notable callees: FUN_0044f1f0×4, CONCAT31×2, FUN_0044f060×2, FUN_0044f120×2, FUN_0040aef0, FUN_004247c0, FUN_0044edb0, FUN_0044f0c0.
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

void __thiscall FUN_0044edb0(int param_1,int param_2,int param_3,uint param_4)



{

  uint uVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int extraout_ECX;

  int iVar5;

  int *local_24;

  uint16_t local_20;

  uint16_t local_1e;

  int local_1c;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be798;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd0;

  ExceptionList = &local_10;

  FUN_0040aef0(&local_24);

  local_20 = *(uint16_t *)(param_1 + 4);

  local_1e = *(uint16_t *)(param_1 + 6);

  iVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_2 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_2 + 0xc) - iVar2 >> 3;

  }

  if (param_4 != 0) {

    if (iVar2 != 0) {

      iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;

    }

    if (0x1fffffffU - iVar5 < param_4) {

      uVar1 = FUN_004540b0();

      iVar2 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;

    }

    if (uVar1 < iVar5 + param_4) {

      if (0x1fffffff - (uVar1 >> 1) < uVar1) {

        uVar1 = 0;

      }

      else {

        uVar1 = uVar1 + (uVar1 >> 1);

      }

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;

      }

      if (uVar1 < iVar5 + param_4) {

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_2 + 8) - iVar2 >> 3;

        }

        uVar1 = iVar2 + param_4;

      }

      local_18 = uVar1 * 8;

      pvVar3 = operator_new(local_18);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_0044f1f0(param_3,pvVar3,param_3);

      FUN_0044f120(iVar2,param_3);

      FUN_0044f1f0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),iVar2 + param_4 * 8,param_3);

      local_8 = 0;

      iVar2 = *(int *)(param_2 + 4);

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;

      }

      if (iVar2 != 0) {

        FUN_004247c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 4));

      }

      *(uint *)(param_2 + 0xc) = local_18 + (int)pvVar3;

      *(void **)(param_2 + 8) = (void *)((int)pvVar3 + (param_4 + iVar5) * 8);

      *(void **)(param_2 + 4) = pvVar3;

    }

    else {

      local_1c = *(int *)(param_2 + 8);

      local_18 = param_4 * 8;

      if ((uint)(local_1c - param_3 >> 3) < param_4) {

        FUN_0044f1f0(local_1c,local_18 + param_3,param_3);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0044f120(*(uint32_t /* width from decompiler */ *)(param_2 + 8),param_3);

        local_8 = 0;

        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_18;

        FUN_0044f060(*(int *)(param_2 + 8) - local_18);

      }

      else {

        uVar4 = FUN_0044f1f0(local_1c,local_1c,param_3);

        *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar4;

        FUN_0044f0c0(param_3,param_3);

        FUN_0044f060(local_18 + param_3);

      }

    }

  }

  local_8 = 0xffffffff;

  if ((local_24 != (int *)0x0) && (local_24[1] = local_24[1] + -1, local_24[1] == 0)) {

    (**(code **)(*local_24 + 8))();

  }

  ExceptionList = local_10;

  return;

}
