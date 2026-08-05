// =============================================================================
// FUN_0068dfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068dfd0
// Address:   0x0068dfd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068dfd0 @ 0x0068dfd0
// Stable ID: aa_0068dfd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0068d240, FUN_0068d6c0, FUN_0068dfd0.
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

void __thiscall FUN_0068dfd0(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,void *param_4)



{

  uint uVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa528;

  local_c = ExceptionList;

  iVar2 = *(int *)(param_1 + 4);

  local_4 = 0;

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 4;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 4;

    }

    ExceptionList = &local_c;

    FUN_0068d6c0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&param_3);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &local_c, param_2 < (uint)(*(int *)(param_1 + 8) - iVar2 >> 4))) {

      ExceptionList = &local_c;

      FUN_0068d240(&param_2,param_2 * 0x10 + iVar2,*(int *)(param_1 + 8));

    }

  }

  if (param_4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_4);

  }

  ExceptionList = local_c;

  return;

}
