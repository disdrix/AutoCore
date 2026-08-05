// =============================================================================
// FUN_00443040
// -----------------------------------------------------------------------------
// Stable ID: aa_00443040
// Address:   0x00443040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00443040 @ 0x00443040
// Stable ID: aa_00443040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_0045f400×4, FUN_00436150×2, FUN_00443040, FUN_00443360, FUN_004433e0, FUN_004540b0, FUN_0045c230.
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

void __fastcall FUN_00443040(uint param_1,int param_2,int param_3)



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

  puStack_c = &LAB_009bcca0;

  local_10 = ExceptionList;

  iVar2 = *(int *)(param_2 + 4);

  if (iVar2 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_2 + 0xc) - iVar2) / 0x14;

  }

  if (param_1 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - iVar2) / 0x14;

    }

    ExceptionList = &local_10;

    if (0xcccccccU - iVar1 < param_1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - iVar2) / 0x14;

    }

    if (uVar5 < iVar1 + param_1) {

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

        iVar2 = (*(int *)(param_2 + 8) - iVar2) / 0x14;

      }

      if (uVar5 < iVar2 + param_1) {

        iVar2 = FUN_0045c230();

        uVar5 = iVar2 + param_1;

      }

      pvVar3 = operator_new(uVar5 * 0x14);

      local_8 = 0;

      FUN_0045f400(param_3);

      FUN_00436150(param_3);

      FUN_0045f400(param_3);

      iVar2 = 0;

      if (*(int *)(param_2 + 4) != 0) {

        iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x14;

      }

      if (*(void **)(param_2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 4));

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar5 * 0x14 + (int)pvVar3);

      *(void **)(param_2 + 8) = (void *)((int)pvVar3 + (param_1 + iVar2) * 0x14);

      *(void **)(param_2 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_2 + 8) - param_3) / 0x14) < param_1) {

      iVar2 = param_1 * 0x14;

      FUN_0045f400(iVar2);

      local_8 = 2;

      FUN_00436150(iVar2);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar2;

    }

    else {

      iVar2 = *(int *)(param_2 + 8) + param_1 * -0x14;

      uVar4 = FUN_0045f400(iVar2);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar4;

      FUN_004433e0(iVar2);

    }

    FUN_00443360();

  }

  ExceptionList = local_10;

  return;

}
