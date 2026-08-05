// =============================================================================
// FUN_0073ad80
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ad80
// Address:   0x0073ad80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ad80 @ 0x0073ad80
// Stable ID: aa_0073ad80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0073ad80, FUN_0073c0a0.
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

void FUN_0073ad80(void)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = DAT_00d1eea8;

  if (DAT_00d1eea8 == (int *)0x0) {

    piVar2 = (int *)FUN_0073c0a0();

    (**(code **)(*piVar2 + 0x4c))(0,&DAT_00afdf30);

    (**(code **)(*piVar2 + 0x4c))(1,&DAT_00afdf30);

    piVar2[1] = piVar2[1] + 1;

    if (piVar2[1] == 1) {

      (**(code **)(*piVar2 + 4))();

    }

    piVar1 = DAT_00d1eea8;

    if ((DAT_00d1eea8 != (int *)0x0) && (DAT_00d1eea8[1] = DAT_00d1eea8[1] + -1, piVar1[1] == 0)) {

      (**(code **)(*piVar1 + 8))();

    }

  }

  DAT_00d1eea8 = piVar2;

  return;

}
