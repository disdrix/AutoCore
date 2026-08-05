// =============================================================================
// FUN_0041ecb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041ecb0
// Address:   0x0041ecb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041ecb0 @ 0x0041ecb0
// Stable ID: aa_0041ecb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, for×1.
//  - Notable callees: FUN_004226e0×4, FUN_00422460×2, FUN_0041ec40, FUN_0041ecb0, FUN_00421f00, FUN_00421f20, FUN_004540b0.
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

void __fastcall

FUN_0041ecb0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4,uint param_5)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_70 [22];

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bce20;

  local_10 = ExceptionList;

  puVar6 = local_70;

  for (iVar5 = 0x16; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = *param_2;

    param_2 = param_2 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar5 = *(int *)(param_3 + 4);

  if (iVar5 == 0) {

    local_18 = 0;

  }

  else {

    local_18 = (*(int *)(param_3 + 0xc) - iVar5) / 0x58;

  }

  if (param_5 != 0) {

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar5) / 0x58;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffff84;

    if (0x2e8ba2eU - iVar2 < param_5) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffff84;

      FUN_004540b0();

      local_18 = extraout_ECX;

    }

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar5) / 0x58;

    }

    if (local_18 < iVar2 + param_5) {

      if (0x2e8ba2e - (local_18 >> 1) < local_18) {

        local_18 = 0;

      }

      else {

        local_18 = local_18 + (local_18 >> 1);

      }

      if (iVar5 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_3 + 8) - iVar5) / 0x58;

      }

      if (local_18 < iVar5 + param_5) {

        iVar5 = FUN_0041ec40();

        local_18 = iVar5 + param_5;

      }

      local_18 = local_18 * 0x58;

      pvVar3 = operator_new(local_18);

      local_8 = 0;

      FUN_004226e0(param_4);

      FUN_00422460(param_4);

      FUN_004226e0(param_4);

      pvVar1 = *(void **)(param_3 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_3 + 8) - (int)pvVar1) / 0x58;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_3 + 0xc) = local_18 + (int)pvVar3;

      *(void **)(param_3 + 8) = (void *)((int)pvVar3 + (param_5 + iVar5) * 0x58);

      *(void **)(param_3 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_3 + 8) - param_4) / 0x58) < param_5) {

      FUN_004226e0(param_4);

      local_8 = 2;

      FUN_00422460(param_4);

      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + param_5 * 0x58;

    }

    else {

      uVar4 = FUN_004226e0(param_4);

      *(uint32_t /* width from decompiler */ *)(param_3 + 8) = uVar4;

      FUN_00421f20();

    }

    FUN_00421f00();

  }

  ExceptionList = local_10;

  return;

}
