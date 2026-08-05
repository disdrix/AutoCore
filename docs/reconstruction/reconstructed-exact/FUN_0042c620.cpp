// =============================================================================
// FUN_0042c620
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c620
// Address:   0x0042c620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c620 @ 0x0042c620
// Stable ID: aa_0042c620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, do×1.
//  - Notable callees: FUN_0042c620.
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

void __fastcall FUN_0042c620(short *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint uVar5;

  int unaff_EDI;

  

  uVar5 = 0;

  if (0 < *(int *)(unaff_EDI + 0x24)) {

    piVar4 = *(int **)(unaff_EDI + 0x2c);

    while ((((iVar2 = *piVar4, *param_1 != *(short *)(iVar2 + 0xf8) ||

             (param_1[1] != *(short *)(iVar2 + 0xfa))) ||

            (*(int *)(param_1 + 2) != *(int *)(iVar2 + 0xfc))) ||

           (((*(int *)(param_1 + 4) != *(int *)(iVar2 + 0x100) ||

             (*(int *)(param_1 + 6) != *(int *)(iVar2 + 0x104))) ||

            (*(int *)(param_1 + 8) != *(int *)(iVar2 + 0x108)))))) {

      uVar5 = uVar5 + 1;

      piVar4 = piVar4 + 1;

      if (*(int *)(unaff_EDI + 0x24) <= (int)uVar5) {

        return;

      }

    }

    piVar3 = *(int **)(*(int *)(unaff_EDI + 0x2c) + uVar5 * 4);

    piVar4 = piVar3 + 2;

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

    if (uVar5 < *(int *)(unaff_EDI + 0x24) - 1U) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x2c) + uVar5 * 4);

        *puVar1 = puVar1[1];

        uVar5 = uVar5 + 1;

      } while (uVar5 < *(int *)(unaff_EDI + 0x24) - 1U);

    }

    *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;

  }

  return;

}
