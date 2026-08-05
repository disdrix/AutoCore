// =============================================================================
// FUN_0062b640
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b640
// Address:   0x0062b640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b640 @ 0x0062b640
// Stable ID: aa_0062b640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: while×3, if×2, for×1, do×1, return×1.
//  - Notable callees: FUN_0062b640.
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

void __fastcall FUN_0062b640(int *param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  piVar3 = *(int **)*param_1;

  piVar1 = piVar3 + ((int *)*param_1)[1];

  piVar4 = piVar3;

  for (; piVar3 != piVar1; piVar3 = piVar3 + 1) {

    if (-1 < *piVar3) {

      iVar5 = piVar4[*piVar3];

      while (-1 < iVar5) {

        *piVar3 = piVar4[*piVar3];

        piVar4 = *(int **)*param_1;

        iVar5 = piVar4[*piVar3];

      }

    }

  }

  piVar3 = *(int **)param_1[1];

  piVar1 = piVar3 + ((int *)param_1[1])[1];

  if (piVar3 != piVar1) {

    iVar5 = *(int *)*param_1;

    do {

      iVar2 = *(int *)(iVar5 + *piVar3 * 4);

      while (-1 < iVar2) {

        *piVar3 = *(int *)(iVar5 + *piVar3 * 4);

        iVar5 = *(int *)*param_1;

        iVar2 = *(int *)(iVar5 + *piVar3 * 4);

      }

      piVar3 = piVar3 + 1;

    } while (piVar3 != piVar1);

  }

  return;

}
