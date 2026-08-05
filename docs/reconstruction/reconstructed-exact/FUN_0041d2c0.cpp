// =============================================================================
// FUN_0041d2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d2c0
// Address:   0x0041d2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041d2c0 @ 0x0041d2c0
// Stable ID: aa_0041d2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00422a90×2, FUN_0041b9f0, FUN_0041d2c0, FUN_00422de0.
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

void FUN_0041d2c0(void)



{

  void *pvVar1;

  int *piVar2;

  int *unaff_EDI;

  

  if (unaff_EDI[4] != 0) {

    if (*unaff_EDI != 0) {

      FUN_00422a90(*unaff_EDI);

      FUN_00422de0();

    }

    pvVar1 = (void *)unaff_EDI[4];

    if (pvVar1 != (void *)0x0) {

      FUN_0041b9f0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_EDI[4] = 0;

  }

  if (*unaff_EDI != 0) {

    FUN_00422a90(*unaff_EDI);

    if (unaff_EDI[3] != 0) {

      (**(code **)(*(int *)*unaff_EDI + 0x18))((int *)*unaff_EDI,1,unaff_EDI + 3,0,0,0);

      unaff_EDI[3] = 0;

    }

    piVar2 = (int *)*unaff_EDI;

    if (piVar2 != (int *)0x0) {

      *unaff_EDI = 0;

      (**(code **)(*piVar2 + 8))(piVar2);

    }

    piVar2 = (int *)unaff_EDI[1];

    if (piVar2 != (int *)0x0) {

      unaff_EDI[1] = 0;

      (**(code **)(*piVar2 + 8))(piVar2);

    }

  }

  return;

}
