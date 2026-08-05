// =============================================================================
// FUN_008a04b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a04b0
// Address:   0x008a04b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a04b0 @ 0x008a04b0
// Stable ID: aa_008a04b0
// Embedded strings (evidence for future rename):
//   - "Hide Quick Menu"
//   - "Show Quick Menu"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_008a0370×2, FUN_008a04b0.
//  - Strings: "Hide Quick Menu"; "Show Quick Menu".
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

void FUN_008a04b0(void)



{

  int *piVar1;

  char cVar2;

  char unaff_BL;

  int *unaff_ESI;

  

  if (unaff_ESI[0xac] == 0) {

    return;

  }

  if ((int *)unaff_ESI[0x199] != (int *)0x0) {

    cVar2 = (**(code **)(*(int *)unaff_ESI[0x199] + 0x3d8))();

    if (cVar2 != unaff_BL) {

      cVar2 = (**(code **)(*(int *)unaff_ESI[0x199] + 0x3d8))();

      if (cVar2 == '\0') {

        (**(code **)(*unaff_ESI + 0xa8))(unaff_ESI[0x199]);

        (**(code **)(*(int *)unaff_ESI[0x199] + 0xcc))(1);

        (**(code **)(*(int *)unaff_ESI[0x199] + 0x43c))();

      }

      else {

        (**(code **)(*(int *)unaff_ESI[0x199] + 0xcc))(0);

        (**(code **)(*(int *)unaff_ESI[0x199] + 0x440))();

        (**(code **)(*unaff_ESI + 0xb0))(unaff_ESI[0x199]);

      }

      (**(code **)(*(int *)unaff_ESI[0x199] + 0x174))(unaff_ESI[0x89]);

    }

  }

  piVar1 = (int *)unaff_ESI[0x18e];

  *(char *)(unaff_ESI + 0x148) = unaff_BL;

  if (piVar1 != (int *)0x0) {

    if (unaff_BL != '\0') {

      (**(code **)(*piVar1 + 0x308))("Hide Quick Menu");

      FUN_008a0370();

      return;

    }

    (**(code **)(*piVar1 + 0x308))("Show Quick Menu");

  }

  FUN_008a0370();

  return;

}
