// =============================================================================
// FUN_00748260
// -----------------------------------------------------------------------------
// Stable ID: aa_00748260
// Address:   0x00748260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748260 @ 0x00748260
// Stable ID: aa_00748260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00748260.
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

void FUN_00748260(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar2 = *(int **)(unaff_ESI + 0x14);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  }

  piVar2 = *(int **)(unaff_ESI + 0x1c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  }

  piVar2 = *(int **)(unaff_ESI + 0xc);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb0) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc0) = 0;

  *(uint *)(unaff_ESI + 0xbc) = *(uint *)(unaff_ESI + 0xbc) | 1;

  return;

}
