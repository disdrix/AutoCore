// =============================================================================
// FUN_008a2d10
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2d10
// Address:   0x008a2d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2d10 @ 0x008a2d10
// Stable ID: aa_008a2d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00829fa0, FUN_008a2d10.
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

void FUN_008a2d10(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar1 = param_1;

  iVar3 = 0;

  if (*(int *)(param_1 + 0x5a4) == 0) {

    param_1 = 0;

  }

  else {

    param_1 = *(int *)(param_1 + 0x5a8) - *(int *)(param_1 + 0x5a4) >> 2;

  }

  if (0 < param_1) {

    do {

      piVar2 = (int *)(*(int *)(iVar1 + 0x5a4) + iVar3 * 4);

      if (*piVar2 != 0) {

        piVar2 = (int *)*piVar2;

        piVar2[0x140] = 0;

        piVar2[0x141] = 0;

        piVar2[0x142] = 0;

        *(uint8_t *)((int)piVar2 + 0x4fe) = 0;

        if ((int *)piVar2[0x14b] != (int *)0x0) {

          (**(code **)(*(int *)piVar2[0x14b] + 0x1d8))(&DAT_00a1419b,1,1);

          (**(code **)(*(int *)piVar2[0x14b] + 0xcc))(0);

        }

        (**(code **)(*piVar2 + 0xcc))(0);

        (**(code **)(*piVar2 + 0x34c))();

        FUN_00829fa0();

        (**(code **)(**(int **)(*(int *)(iVar1 + 0x5a4) + iVar3 * 4) + 0xcc))(0);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < param_1);

  }

  return;

}
