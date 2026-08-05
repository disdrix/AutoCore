// =============================================================================
// FUN_008cb070
// -----------------------------------------------------------------------------
// Stable ID: aa_008cb070
// Address:   0x008cb070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cb070 @ 0x008cb070
// Stable ID: aa_008cb070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_00912820×2, FUN_008cb070.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008cb070(int param_1)



{

  int iVar1;

  int *piVar2;

  

  if (*(int *)(param_1 + 0x948) == 0) {

    _DAT_00d1b6a4 = -1;

  }

  else {

    _DAT_00d1b6a4 = (**(code **)(**(int **)(param_1 + 0x948) + 0x44c))();

  }

  if (DAT_00d1b77c != 0) {

    if (_DAT_00d1b6a4 == -1) {

      FUN_00912820();

      return;

    }

    iVar1 = 0;

    if (0 < *(int *)(param_1 + 0x558)) {

      piVar2 = (int *)(param_1 + 0x564);

      do {

        if (*piVar2 == _DAT_00d1b6a4) {

          FUN_00912820();

          return;

        }

        iVar1 = iVar1 + 1;

        piVar2 = piVar2 + 0xf;

      } while (iVar1 < *(int *)(param_1 + 0x558));

    }

  }

  return;

}
