// =============================================================================
// FUN_00602f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00602f10
// Address:   0x00602f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602f10 @ 0x00602f10
// Stable ID: aa_00602f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, while×3, do×1.
//  - Notable callees: FUN_00602f10, FUN_00603660, memmove.
//  - Return sites: 6.

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

int __thiscall FUN_00602f10(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  

  while( true ) {

    iVar1 = *(int *)(param_2 + 4);

    if (iVar1 == 0) {

      return 0;

    }

    iVar2 = *(int *)(param_2 + 8);

    if (iVar2 - iVar1 >> 2 == 0) {

      return 0;

    }

    FUN_00603660(iVar1,iVar2,iVar2 - iVar1 >> 2);

    piVar3 = *(int **)(param_2 + 4);

    if (piVar3 == (int *)0x0) break;

    uVar4 = *(int *)(param_2 + 8) - (int)piVar3 >> 2;

    if (uVar4 < 2) break;

    piVar5 = *(int **)(param_1 + 0x14);

    while( true ) {

      if (piVar5 == *(int **)(param_1 + 0x18)) {

        return 0;

      }

      if (*(int *)(*piVar5 + 0xc) == *piVar3) break;

      piVar5 = piVar5 + 1;

    }

    if (1 < uVar4) {

      memmove(piVar3,piVar3 + 1,(*(int *)(param_2 + 8) - (int)(piVar3 + 1) >> 2) * 4);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -4;

    }

    param_1 = *piVar5;

  }

  piVar3 = *(int **)(param_1 + 0x14);

  if (piVar3 == *(int **)(param_1 + 0x18)) {

    return 0;

  }

  do {

    if (*(int *)(*piVar3 + 0xc) == **(int **)(param_2 + 4)) {

      return *piVar3 + 0x20;

    }

    piVar3 = piVar3 + 1;

  } while (piVar3 != *(int **)(param_1 + 0x18));

  return 0;

}
