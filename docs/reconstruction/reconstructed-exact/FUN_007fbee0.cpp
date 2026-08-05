// =============================================================================
// FUN_007fbee0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbee0
// Address:   0x007fbee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbee0 @ 0x007fbee0
// Stable ID: aa_007fbee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_007fbee0.
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

void FUN_007fbee0(void)



{

  bool bVar1;

  uint8_t uVar2;

  int *piVar3;

  int *unaff_ESI;

  char cStack_5;

  

  if (unaff_ESI != (int *)0x0) {

    piVar3 = (int *)(**(code **)(*unaff_ESI + 0x34))();

    if (piVar3 == (int *)0x0) {

      cStack_5 = '\0';

    }

    else {

      cStack_5 = (**(code **)(*piVar3 + 0x3d8))();

    }

    uVar2 = (**(code **)(*unaff_ESI + 0xd0))();

    bVar1 = false;

    if ((unaff_ESI[0x70] != DAT_00d1e818) || (unaff_ESI[0x71] != DAT_00d1e81c)) {

      bVar1 = true;

    }

    if (cStack_5 != '\0') {

      (**(code **)(*piVar3 + 0x440))();

    }

    if (bVar1) {

      (**(code **)(*unaff_ESI + 0x28))(0);

    }

    if (cStack_5 != '\0') {

      (**(code **)(*piVar3 + 0x43c))();

    }

    if (bVar1) {

      (**(code **)(*unaff_ESI + 0x10c))();

    }

    if ((piVar3 == (int *)0x0) || (cStack_5 != '\0')) {

      (**(code **)(*unaff_ESI + 0xcc))(uVar2);

    }

                    /* WARNING: Could not recover jumptable at 0x007fbf9d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_ESI + 0x34c))();

    return;

  }

  return;

}
