// =============================================================================
// FUN_00962530
// -----------------------------------------------------------------------------
// Stable ID: aa_00962530
// Address:   0x00962530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962530 @ 0x00962530
// Stable ID: aa_00962530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00456780, FUN_00456960, FUN_00469270, FUN_00729bb0, FUN_00962530.
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

uint32_t /* width from decompiler */ __fastcall FUN_00962530(int param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  int unaff_EDI;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad578;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar3 = operator_new(0x1c);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_00729bb0(pvVar3,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4));

  }

  local_4 = 0xffffffff;

  *(int *)(iVar4 + 0x18) = param_1;

  *(int *)(*(int *)(unaff_EDI + 0xc) + *(int *)(param_1 + 0x1c) * 4) = iVar4;

  FUN_00456780(0);

  piVar1 = *(int **)(unaff_EDI + 0x10);

  for (piVar5 = *(int **)(unaff_EDI + 0xc); piVar5 != piVar1; piVar5 = piVar5 + 1) {

    if (*piVar5 != 0) {

      iVar4 = *(int *)(unaff_EDI + 0x1c);

      if ((iVar4 == 0) ||

         ((uint)(*(int *)(unaff_EDI + 0x24) - iVar4 >> 2) <=

          (uint)(*(int *)(unaff_EDI + 0x20) - iVar4 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20));

      }

      else {

        piVar2 = *(int **)(unaff_EDI + 0x20);

        *piVar2 = *piVar5;

        *(int **)(unaff_EDI + 0x20) = piVar2 + 1;

      }

    }

  }

  local_10 = (uint)piVar1 & 0xffffff00;

  FUN_00469270(*(int *)(unaff_EDI + 0x1c),*(int *)(unaff_EDI + 0x20),

               *(int *)(unaff_EDI + 0x20) - *(int *)(unaff_EDI + 0x1c) >> 2,local_10);

  ExceptionList = local_c;

  return 0;

}
