// =============================================================================
// FUN_005ffff0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffff0
// Address:   0x005ffff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ffff0 @ 0x005ffff0
// Stable ID: aa_005ffff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×2, return×1.
//  - Notable callees: FUN_005ffff0.
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

void FUN_005ffff0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x80);

  while (iVar3 = iVar3 + -1, -1 < iVar3) {

    piVar1 = *(int **)(*(int *)(param_1 + 0x7c) + iVar3 * 4);

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 8))(param_1);

    }

  }

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    do {

      iVar2 = *(int *)(*(int *)(param_1 + 0x88) + iVar3 * 4);

      if (iVar2 != 0) {

        (**(code **)(*(int *)(iVar2 + 8) + 8))(param_1);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x8c));

  }

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x98)) {

    do {

      iVar2 = *(int *)(*(int *)(param_1 + 0x94) + iVar3 * 4);

      if (iVar2 != 0) {

        (**(code **)(*(int *)(iVar2 + 8) + 8))(param_1);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x98));

  }

  return;

}
