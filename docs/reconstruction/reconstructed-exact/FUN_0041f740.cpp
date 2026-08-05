// =============================================================================
// FUN_0041f740
// -----------------------------------------------------------------------------
// Stable ID: aa_0041f740
// Address:   0x0041f740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041f740 @ 0x0041f740
// Stable ID: aa_0041f740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, for×1.
//  - Notable callees: FUN_00422740×4, FUN_0041c900, FUN_0041c9a0, FUN_0041f740, FUN_00421980, FUN_00421f80, FUN_004220c0, FUN_004222c0.
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

FUN_0041f740(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4,uint param_5)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int extraout_ECX;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_94c [589];

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bce00;

  local_10 = ExceptionList;

  puVar6 = local_94c;

  for (iVar4 = 0x24d; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *param_2;

    param_2 = param_2 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar4 = *(int *)(param_3 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_3 + 0xc) - iVar4) / 0x934;

    local_18 = uVar5;

  }

  if (param_5 != 0) {

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar4) / 0x934;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xfffff6a8;

    if (0x1bd10fU - iVar2 < param_5) {

      ExceptionList = &local_10;

      local_14 = &stack0xfffff6a8;

      FUN_004540b0();

      iVar4 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar4) / 0x934;

    }

    if (uVar5 < iVar2 + param_5) {

      if (0x1bd10f - (uVar5 >> 1) < uVar5) {

        local_18 = 0;

      }

      else {

        local_18 = uVar5 + (uVar5 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_3 + 8) - iVar4) / 0x934;

      }

      if (local_18 < iVar4 + param_5) {

        iVar4 = FUN_0041c900();

        local_18 = iVar4 + param_5;

      }

      iVar4 = FUN_00421980(local_18);

      local_8 = 0;

      FUN_00422740(param_4);

      FUN_004220c0(param_4);

      FUN_00422740(param_4);

      pvVar1 = *(void **)(param_3 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_3 + 8) - (int)pvVar1) / 0x934;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_3 + 0xc) = iVar4 + local_18 * 0x934;

      *(uint *)(param_3 + 8) = iVar4 + (param_5 + iVar2) * 0x934;

      *(int *)(param_3 + 4) = iVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_3 + 8) - param_4) / 0x934) < param_5) {

      FUN_00422740(param_4);

      local_8 = 2;

      FUN_0041c9a0(param_3);

      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + param_5 * 0x934;

    }

    else {

      uVar3 = FUN_00422740(param_4);

      *(uint32_t /* width from decompiler */ *)(param_3 + 8) = uVar3;

      FUN_004222c0(param_4);

    }

    FUN_00421f80();

  }

  ExceptionList = local_10;

  return;

}
