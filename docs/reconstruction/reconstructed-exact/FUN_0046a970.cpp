// =============================================================================
// FUN_0046a970
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a970
// Address:   0x0046a970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046a970 @ 0x0046a970
// Stable ID: aa_0046a970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0046a970, FUN_0046ab80, FUN_0046abd0.
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

void FUN_0046a970(uint param_1,uint32_t /* width from decompiler */ param_2,void *param_3)



{

  uint uVar1;

  int iVar2;

  int unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be3f8;

  local_c = ExceptionList;

  local_4 = 0;

  iVar2 = *(int *)(unaff_ESI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(unaff_ESI + 8) - iVar2 >> 4;

  }

  if (uVar1 < param_1) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(unaff_ESI + 8) - iVar2 >> 4;

    }

    ExceptionList = &local_c;

    FUN_0046abd0(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),param_1 - iVar2);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)(*(int *)(unaff_ESI + 8) - iVar2 >> 4))) {

      ExceptionList = &local_c;

      FUN_0046ab80(unaff_ESI,&param_1,param_1 * 0x10 + iVar2,*(int *)(unaff_ESI + 8));

    }

  }

  if (param_3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_3);

  }

  ExceptionList = local_c;

  return;

}
