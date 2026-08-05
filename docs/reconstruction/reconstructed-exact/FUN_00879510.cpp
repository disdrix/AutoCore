// =============================================================================
// FUN_00879510
// -----------------------------------------------------------------------------
// Stable ID: aa_00879510
// Address:   0x00879510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00879510 @ 0x00879510
// Stable ID: aa_00879510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00794090×2, FUN_00878d50, FUN_00879510.
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

void FUN_00879510(void)



{

  int *piVar1;

  char cVar2;

  int *unaff_EDI;

  

  cVar2 = (**(code **)(*unaff_EDI + 0x3d8))();

  if (cVar2 != '\0') {

    FUN_00878d50(0);

    if ((unaff_EDI[0x162] != 0) &&

       (cVar2 = (**(code **)(*(int *)unaff_EDI[0x162] + 0xd8))(), cVar2 != '\0')) {

      (**(code **)(*(int *)unaff_EDI[0x162] + 0xd4))(0);

      (**(code **)(*(int *)unaff_EDI[0x162] + 0x34c))();

    }

    if ((unaff_EDI[0x161] != 0) &&

       (cVar2 = (**(code **)(*(int *)unaff_EDI[0x161] + 0xd8))(), cVar2 != '\0')) {

      (**(code **)(*(int *)unaff_EDI[0x161] + 0xd4))(0);

      (**(code **)(*(int *)unaff_EDI[0x161] + 0x34c))();

    }

    piVar1 = (int *)unaff_EDI[0x169];

    if ((piVar1 != (int *)0x0) && (*(char *)((int)piVar1 + 0x489) == '\0')) {

      (**(code **)(*piVar1 + 0x3ac))(&DAT_00a1419b);

      FUN_00794090();

      (**(code **)(*(int *)unaff_EDI[0x169] + 0x34c))();

    }

    piVar1 = (int *)unaff_EDI[0x16a];

    if ((piVar1 != (int *)0x0) && (*(char *)((int)piVar1 + 0x489) == '\0')) {

      (**(code **)(*piVar1 + 0x3ac))(&DAT_00a1419b);

      FUN_00794090();

                    /* WARNING: Could not recover jumptable at 0x00879613. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)unaff_EDI[0x16a] + 0x34c))();

      return;

    }

  }

  return;

}
