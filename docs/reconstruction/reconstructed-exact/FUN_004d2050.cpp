// =============================================================================
// FUN_004d2050
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2050
// Address:   0x004d2050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2050 @ 0x004d2050
// Stable ID: aa_004d2050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004d2050.
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

void __fastcall FUN_004d2050(int param_1)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = *(int **)(*(int *)(param_1 + 0xe894) + 0x144);

  iVar1 = 1;

  if (piVar2 != *(int **)(*(int *)(param_1 + 0xe894) + 0x148)) {

    do {

      *(int *)(*piVar2 + 0x134) = iVar1;

      piVar2 = piVar2 + 1;

      iVar1 = iVar1 + 1;

    } while (piVar2 != *(int **)(*(int *)(param_1 + 0xe894) + 0x148));

  }

  piVar2 = *(int **)(*(int *)(param_1 + 0xe894) + 0x154);

  if (piVar2 != *(int **)(*(int *)(param_1 + 0xe894) + 0x158)) {

    do {

      *(int *)(*piVar2 + 0x134) = iVar1;

      piVar2 = piVar2 + 1;

      iVar1 = iVar1 + 1;

    } while (piVar2 != *(int **)(*(int *)(param_1 + 0xe894) + 0x158));

  }

  return;

}
