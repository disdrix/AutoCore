// =============================================================================
// FUN_004272b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004272b0
// Address:   0x004272b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004272b0 @ 0x004272b0
// Stable ID: aa_004272b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_00427b40×4, FUN_00427ae0×2, FUN_00426f80, FUN_004270b0, FUN_004272b0, FUN_00427910, FUN_00427930, FUN_004540b0.
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

void __fastcall FUN_004272b0(uint32_t /* width from decompiler */ param_1,uint param_2,int param_3,int param_4)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd780;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  FUN_00426f80();

  iVar3 = *(int *)(param_3 + 4);

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_3 + 0xc) - iVar3) / 0x60;

  }

  if (param_2 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar3) / 0x60;

    }

    if (0x2aaaaaaU - iVar2 < param_2) {

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_3 + 8) - iVar3) / 0x60;

    }

    if (uVar6 < iVar2 + param_2) {

      if (0x2aaaaaa - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_3 + 8) - iVar3) / 0x60;

      }

      if (uVar6 < iVar3 + param_2) {

        iVar3 = FUN_004270b0();

        uVar6 = iVar3 + param_2;

      }

      pvVar4 = operator_new(uVar6 * 0x60);

      local_8 = 0;

      FUN_00427b40(param_4);

      FUN_00427ae0(param_4);

      FUN_00427b40(param_4);

      pvVar1 = *(void **)(param_3 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_3 + 8) - (int)pvVar1) / 0x60;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_3 + 0xc) = (void *)(uVar6 * 0x60 + (int)pvVar4);

      *(void **)(param_3 + 8) = (void *)((param_2 + iVar3) * 0x60 + (int)pvVar4);

      *(void **)(param_3 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_3 + 8) - param_4) / 0x60) < param_2) {

      FUN_00427b40(param_4);

      local_8 = 2;

      FUN_00427ae0(param_4);

      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + param_2 * 0x60;

    }

    else {

      uVar5 = FUN_00427b40(param_4);

      *(uint32_t /* width from decompiler */ *)(param_3 + 8) = uVar5;

      FUN_00427930();

    }

    FUN_00427910();

  }

  ExceptionList = local_10;

  return;

}
