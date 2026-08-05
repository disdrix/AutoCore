// =============================================================================
// FUN_004bde80
// -----------------------------------------------------------------------------
// Stable ID: aa_004bde80
// Address:   0x004bde80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bde80 @ 0x004bde80
// Stable ID: aa_004bde80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_004bde80.
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

int FUN_004bde80(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  

  iVar1 = 0;

  if (*(int *)(param_1 + 0xc0) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;

  }

  if (0 < iVar2) {

    piVar4 = *(int **)(param_1 + 0xc0);

    do {

      iVar3 = *(int *)(*piVar4 + 0x14);

      if (iVar3 == 0) {

        iVar5 = 0;

LAB_004bded3:

        iVar3 = 0;

      }

      else {

        iVar5 = *(int *)(iVar3 + 0x18);

        if (*(int *)(iVar3 + 0x10) == 0) goto LAB_004bded3;

        iVar3 = *(int *)(*(int *)(iVar3 + 0x10) + 8);

      }

      iVar1 = iVar1 + iVar3 * iVar5;

      piVar4 = piVar4 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return iVar1;

}
