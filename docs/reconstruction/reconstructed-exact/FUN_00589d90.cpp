// =============================================================================
// FUN_00589d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00589d90
// Address:   0x00589d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589d90 @ 0x00589d90
// Stable ID: aa_00589d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×11, return×5, goto×1.
//  - Notable callees: FUN_00589d90.
//  - Return sites: 5.

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

int FUN_00589d90(int *param_1,int *param_2,float param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  

  if (param_2 != (int *)0x0) {

    iVar3 = (**(code **)(*param_2 + 0x19c))();

    if ((iVar3 != 0) &&

       (piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3), piVar5 != (int *)0x0))

    goto LAB_00589de7;

    param_1 = (int *)param_2[0x2b];

  }

  if (param_1 == (int *)0x0) {

    return 0;

  }

  iVar3 = (**(code **)(*param_1 + 0x19c))();

  if (iVar3 == 0) {

    return 0;

  }

  piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

  if (piVar5 == (int *)0x0) {

    return 0;

  }

LAB_00589de7:

  iVar3 = (**(code **)(*piVar5 + 0x1d4))();

  if (iVar3 != 0) {

    iVar4 = (int)param_3;

    if ((DAT_00aaa668 <= param_3) && (param_3 <= g_flOne)) {

      iVar4 = (int)((float)*(int *)(iVar3 + 0x148) * param_3);

    }

    iVar1 = *(int *)(iVar3 + 0x144);

    iVar2 = *(int *)(iVar3 + 0x148);

    iVar4 = iVar4 + iVar1;

    iVar6 = iVar4;

    if (iVar2 <= iVar4) {

      iVar6 = iVar2;

    }

    if (iVar6 < 1) {

      iVar4 = 0;

    }

    else if (iVar2 <= iVar4) {

      iVar4 = iVar2;

    }

    *(int *)(iVar3 + 0x144) = iVar4;

    if (iVar1 != iVar4) {

      return iVar4 - iVar1;

    }

  }

  return 0;

}
