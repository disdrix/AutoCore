// =============================================================================
// FUN_00912a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00912a50
// Address:   0x00912a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00912a50 @ 0x00912a50
// Stable ID: aa_00912a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0074e260×2, FUN_00912a50.
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

void FUN_00912a50(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  int *unaff_ESI;

  

  if (unaff_ESI[0x2bf] != 0) {

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x2bf] + 0x8c);

    (**(code **)(*unaff_ESI + 0x1a8))();

    FUN_0074e260(uVar2);

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x2bf] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x2bf])(1);

    }

    unaff_ESI[0x2bf] = 0;

  }

  if (unaff_ESI[0x2be] != 0) {

    iVar4 = (**(code **)(*unaff_ESI + 0x1a8))();

    iVar4 = *(int *)(iVar4 + 4);

    piVar3 = *(int **)(iVar4 + 0x3c);

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = 0;

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x2be] + 0x8c);

    (**(code **)(*unaff_ESI + 0x1a8))();

    FUN_0074e260(uVar2);

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x2be] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x2be])(1);

    }

    unaff_ESI[0x2be] = 0;

  }

  return;

}
