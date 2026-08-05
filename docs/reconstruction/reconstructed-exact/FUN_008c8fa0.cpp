// =============================================================================
// FUN_008c8fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c8fa0
// Address:   0x008c8fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c8fa0 @ 0x008c8fa0
// Stable ID: aa_008c8fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_008c8fa0.
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

void FUN_008c8fa0(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar1 = *(int **)(unaff_ESI + 0x590);

  if (piVar1 != (int *)0x0) {

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

  }

  piVar1 = *(int **)(unaff_ESI + 0x594);

  if (piVar1 != (int *)0x0) {

    *(uint8_t *)((int)piVar1 + 0x489) = 0;

    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);

    piVar1[0x8b] = *piVar2;

  }

  if (*(int *)(unaff_ESI + 0x564) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x564) + 0xd4))(1);

  }

  if (*(int *)(unaff_ESI + 0x56c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x56c) + 0xd4))(1);

  }

  if (*(int *)(unaff_ESI + 0x570) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x570) + 0xd4))(1);

  }

  if (*(int *)(unaff_ESI + 0x568) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0xd4))(1);

  }

  return;

}
