// =============================================================================
// FUN_00420290
// -----------------------------------------------------------------------------
// Stable ID: aa_00420290
// Address:   0x00420290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00420290 @ 0x00420290
// Stable ID: aa_00420290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_00480fe0×4, FUN_0042acc0×2, FUN_00420290, FUN_0042ac90, FUN_004540b0, FUN_00480c80, FUN_00480fb0.
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

void __fastcall FUN_00420290(uint param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bcdc0;

  local_10 = ExceptionList;

  iVar2 = *(int *)(param_2 + 4);

  if (iVar2 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_2 + 0xc) - iVar2) / 0xc;

  }

  if (param_1 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - iVar2) / 0xc;

    }

    ExceptionList = &local_10;

    if (0x15555555U - iVar1 < param_1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - iVar2) / 0xc;

    }

    if (uVar5 < iVar1 + param_1) {

      if (0x15555555 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_2 + 8) - iVar2) / 0xc;

      }

      if (uVar5 < iVar2 + param_1) {

        iVar2 = FUN_00480c80();

        uVar5 = iVar2 + param_1;

      }

      pvVar3 = operator_new(uVar5 * 0xc);

      local_8 = 0;

      FUN_00480fe0(param_3);

      FUN_0042acc0(param_3);

      FUN_00480fe0(param_3);

      iVar2 = 0;

      if (*(int *)(param_2 + 4) != 0) {

        iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0xc;

      }

      if (*(void **)(param_2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 4));

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar5 * 0xc + (int)pvVar3);

      *(void **)(param_2 + 8) = (void *)((int)pvVar3 + (param_1 + iVar2) * 0xc);

      *(void **)(param_2 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_2 + 8) - param_3) / 0xc) < param_1) {

      iVar2 = param_1 * 0xc;

      FUN_00480fe0(iVar2);

      local_8 = 2;

      FUN_0042acc0(iVar2);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar2;

    }

    else {

      uVar4 = FUN_00480fe0(*(int *)(param_2 + 8) + param_1 * -0xc);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar4;

      FUN_00480fb0();

    }

    FUN_0042ac90();

  }

  ExceptionList = local_10;

  return;

}
