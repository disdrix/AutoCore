// =============================================================================
// FUN_0056d110
// -----------------------------------------------------------------------------
// Stable ID: aa_0056d110
// Address:   0x0056d110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056d110 @ 0x0056d110
// Stable ID: aa_0056d110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004b8dc0, FUN_0056d110.
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

int __fastcall FUN_0056d110(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  piVar3 = *(int **)(iVar1 + 0x128 + param_1);

  iVar2 = iVar1 + param_1;

  if (piVar3 != *(int **)(iVar1 + 300 + param_1)) {

    do {

      if (*(int *)(*piVar3 + 0x28) == 4) {

        FUN_004b8dc0(1,0);

      }

      iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

      piVar3 = piVar3 + 1;

    } while (piVar3 != *(int **)(iVar2 + 300 + param_1));

  }

  return iVar2;

}
