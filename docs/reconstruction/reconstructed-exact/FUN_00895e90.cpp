// =============================================================================
// FUN_00895e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00895e90
// Address:   0x00895e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00895e90 @ 0x00895e90
// Stable ID: aa_00895e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00895e90.
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

void FUN_00895e90(void)



{

  int iVar1;

  int *piVar2;

  int *unaff_EDI;

  

  piVar2 = unaff_EDI + 0x199;

  iVar1 = 0x36;

  do {

    if ((int *)*piVar2 != (int *)0x0) {

      (**(code **)(*(int *)*piVar2 + 0x440))();

      (**(code **)(*unaff_EDI + 0xbc))(*piVar2);

      *piVar2 = 0;

    }

    if (piVar2[-0x36] != 0) {

      (**(code **)(*unaff_EDI + 0xbc))(piVar2[-0x36]);

      piVar2[-0x36] = 0;

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
