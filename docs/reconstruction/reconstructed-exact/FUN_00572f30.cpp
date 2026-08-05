// =============================================================================
// FUN_00572f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00572f30
// Address:   0x00572f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00572f30 @ 0x00572f30
// Stable ID: aa_00572f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_00572f30.
//  - Return sites: 2.

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

bool FUN_00572f30(char param_1,int *param_2,int *param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_2[0x2a] + 0x38);

  iVar3 = *(int *)(param_3[0x2a] + 0x38);

  if (iVar1 == iVar3) {

    iVar1 = (**(code **)(*param_2 + 0x1e0))();

    if (iVar1 != 0) {

      iVar1 = (**(code **)(*param_3 + 0x1e0))();

      if (iVar1 != 0) {

        piVar2 = (int *)(**(code **)(*param_2 + 0x1e0))();

        iVar1 = (**(code **)(*piVar2 + 0x60))();

        piVar2 = (int *)(**(code **)(*param_3 + 0x1e0))();

        iVar3 = (**(code **)(*piVar2 + 0x60))();

        goto LAB_00572fb3;

      }

    }

    iVar1 = (int)*(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4);

    iVar3 = (int)*(short *)(*(int *)(param_3[0x2a] + 0x3c) + 0x3f4);

  }

LAB_00572fb3:

  if (param_1 != '\0') {

    return iVar3 < iVar1;

  }

  return iVar1 < iVar3;

}
