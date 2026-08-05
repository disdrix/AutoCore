// =============================================================================
// FUN_00782de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00782de0
// Address:   0x00782de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782de0 @ 0x00782de0
// Stable ID: aa_00782de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×13, return×10.
//  - Notable callees: FUN_00782de0.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ FUN_00782de0(void)



{

  int *piVar1;

  int iVar2;

  int *unaff_ESI;

  

  piVar1 = (int *)unaff_ESI[3];

  if (piVar1 != (int *)0x0) {

    if (unaff_ESI == piVar1) {

      return 0;

    }

    iVar2 = (**(code **)(*unaff_ESI + 4))(piVar1[5]);

    if (iVar2 < 1) {

      return 0;

    }

  }

  piVar1 = (int *)unaff_ESI[2];

  if (piVar1 != (int *)0x0) {

    if (unaff_ESI == piVar1) {

      return 0;

    }

    iVar2 = (**(code **)(*unaff_ESI + 4))(piVar1[5]);

    if (-1 < iVar2) {

      return 0;

    }

  }

  piVar1 = (int *)unaff_ESI[4];

  if (piVar1 != (int *)0x0) {

    if (unaff_ESI == piVar1) {

      return 0;

    }

    if ((int *)piVar1[3] == unaff_ESI) {

      iVar2 = (**(code **)(*piVar1 + 4))(unaff_ESI[5]);

      if (iVar2 < 1) {

        return 0;

      }

    }

    else {

      if ((int *)piVar1[2] != unaff_ESI) {

        return 0;

      }

      iVar2 = (**(code **)(*piVar1 + 4))(unaff_ESI[5]);

      if (-1 < iVar2) {

        return 0;

      }

    }

    if ((*(int **)(unaff_ESI[4] + 0xc) == unaff_ESI) && (*(int **)(unaff_ESI[4] + 8) == unaff_ESI))

    {

      return 0;

    }

  }

  return 1;

}
