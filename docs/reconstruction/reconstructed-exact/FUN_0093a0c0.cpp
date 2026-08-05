// =============================================================================
// FUN_0093a0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093a0c0
// Address:   0x0093a0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093a0c0 @ 0x0093a0c0
// Stable ID: aa_0093a0c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_007fca10×5, FUN_007fef20, FUN_0086b3c0, FUN_00877c50, FUN_0093a0c0.
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

void FUN_0093a0c0(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  piVar1 = *(int **)(in_EAX + 0x10d0);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      FUN_007fef20(0x28,1,0);

    }

  }

  *(uint8_t *)(*(int *)(in_EAX + 0xe98) + 0x4fc) = 1;

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_0086b3c0();

    }

  }

  piVar1 = *(int **)(in_EAX + 0x10c0);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_00877c50();

      (**(code **)(*piVar1 + 0xcc))(0);

    }

  }

  return;

}
