// =============================================================================
// FUN_00937150
// -----------------------------------------------------------------------------
// Stable ID: aa_00937150
// Address:   0x00937150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00937150 @ 0x00937150
// Stable ID: aa_00937150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007fca10×5, FUN_007fef20, FUN_00877c50, FUN_00937150.
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

void FUN_00937150(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  piVar1 = *(int **)(in_EAX + 0x10c0);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      FUN_007fef20(0x24,1,0);

    }

  }

  *(uint8_t *)(*(int *)(in_EAX + 0xe98) + 0x4fc) = 1;

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_00877c50();

      return;

    }

  }

  return;

}
