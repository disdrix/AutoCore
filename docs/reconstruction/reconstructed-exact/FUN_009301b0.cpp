// =============================================================================
// FUN_009301b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009301b0
// Address:   0x009301b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009301b0 @ 0x009301b0
// Stable ID: aa_009301b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×14, return×1.
//  - Notable callees: FUN_007fca10×7, FUN_009301b0.
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

void FUN_009301b0(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  piVar1 = *(int **)(*(int *)(in_EAX + 0x1034) + 0x510);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  piVar1 = *(int **)(*(int *)(in_EAX + 0x1040) + 0x50c);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  if (*(int **)(in_EAX + 0x1078) != (int *)0x0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1078) + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  if (*(int **)(in_EAX + 0x1050) != (int *)0x0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1050) + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  if (*(int **)(in_EAX + 0x1068) != (int *)0x0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1068) + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  if (*(int **)(in_EAX + 0x10c0) != (int *)0x0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x10c0) + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  if (*(int **)(in_EAX + 0x10d0) != (int *)0x0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x10d0) + 0xd0))();

    if (cVar2 != '\0') {

      FUN_007fca10();

    }

  }

  return;

}
