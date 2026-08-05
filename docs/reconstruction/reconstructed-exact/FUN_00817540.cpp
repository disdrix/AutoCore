// =============================================================================
// FUN_00817540
// -----------------------------------------------------------------------------
// Stable ID: aa_00817540
// Address:   0x00817540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817540 @ 0x00817540
// Stable ID: aa_00817540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_004133c0×2, FUN_00817540.
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

void FUN_00817540(void)



{

  char cVar1;

  int *piVar2;

  int *unaff_EDI;

  

  piVar2 = *(int **)unaff_EDI[0x144];

  if (piVar2 != (int *)unaff_EDI[0x144]) {

    do {

      cVar1 = (**(code **)(*(int *)piVar2[2] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)piVar2[2] + 0x440))();

        (**(code **)(*unaff_EDI + 0xb0))(piVar2[2]);

      }

      if ((uint32_t /* width from decompiler */ *)piVar2[2] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar2[2])(1);

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)unaff_EDI[0x144]);

  }

  FUN_004133c0(0);

  piVar2 = *(int **)unaff_EDI[0x147];

  if (piVar2 != (int *)unaff_EDI[0x147]) {

    do {

      (**(code **)(*unaff_EDI + 0xb0))(piVar2[2]);

      if ((uint32_t /* width from decompiler */ *)piVar2[2] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar2[2])(1);

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)unaff_EDI[0x147]);

  }

  FUN_004133c0(0);

  return;

}
