// =============================================================================
// FUN_00461020
// -----------------------------------------------------------------------------
// Stable ID: aa_00461020
// Address:   0x00461020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00461020 @ 0x00461020
// Stable ID: aa_00461020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00461020, FUN_004613a0, FUN_00461400.
//  - Return sites: 1.

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

void __thiscall FUN_00461020(uint param_1,int *param_2)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int unaff_ESI;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdfb8;

  local_c = ExceptionList;

  local_4 = 0;

  iVar3 = *(int *)(unaff_ESI + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_ESI + 8) - iVar3) / 0xc;

  }

  local_10 = param_1;

  if (uVar2 < param_1) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(unaff_ESI + 8) - iVar3) / 0xc;

    }

    ExceptionList = &local_c;

    FUN_00461400(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),param_1 - iVar3);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar3 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_ESI + 8) - iVar3) / 0xc))) {

      ExceptionList = &local_c;

      FUN_004613a0(unaff_ESI,&local_10,iVar3 + param_1 * 0xc,*(int *)(unaff_ESI + 8));

    }

  }

  local_4 = 0xffffffff;

  if (param_2 != (int *)0x0) {

    piVar1 = param_2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_2 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
