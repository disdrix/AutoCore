// =============================================================================
// FUN_00603510
// -----------------------------------------------------------------------------
// Stable ID: aa_00603510
// Address:   0x00603510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00603510 @ 0x00603510
// Stable ID: aa_00603510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, goto×3, return×1, do×1, while×1.
//  - Notable callees: FUN_00468970, FUN_00603510.
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

void FUN_00603510(int *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar3 = param_1;

  if (param_1 != param_2) {

joined_r0x00603524:

    piVar2 = piVar3;

    piVar3 = piVar2 + 1;

    if (piVar3 != param_2) {

      iVar1 = *piVar3;

      piVar4 = param_1;

      if (*param_1 <= iVar1) goto LAB_00603540;

      goto joined_r0x00603553;

    }

  }

  return;

LAB_00603540:

  piVar5 = piVar2;

  if (iVar1 < *piVar2) {

    do {

      piVar4 = piVar5;

      piVar5 = piVar4 + -1;

    } while (iVar1 < *piVar5);

joined_r0x00603553:

    if ((piVar4 != piVar3) && (piVar3 != piVar2 + 2)) {

      FUN_00468970(piVar4,piVar3,piVar2 + 2,0,0);

    }

  }

  goto joined_r0x00603524;

}
