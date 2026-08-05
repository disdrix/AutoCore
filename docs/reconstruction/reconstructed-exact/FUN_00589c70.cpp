// =============================================================================
// FUN_00589c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00589c70
// Address:   0x00589c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589c70 @ 0x00589c70
// Stable ID: aa_00589c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, goto×1.
//  - Notable callees: FUN_004d7e30, FUN_00589c70.
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

int FUN_00589c70(int *param_1,int *param_2,float param_3,char param_4)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  piVar3 = param_1;

  if (param_2 != (int *)0x0) {

    iVar1 = (**(code **)(*param_2 + 0x19c))();

    if ((iVar1 != 0) &&

       (piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1), piVar3 != (int *)0x0))

    goto LAB_00589cce;

    piVar3 = (int *)param_2[0x2b];

  }

  if (piVar3 == (int *)0x0) {

    return 0;

  }

  iVar1 = (**(code **)(*piVar3 + 0x19c))();

  if (iVar1 == 0) {

    return 0;

  }

  piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

  if (piVar3 == (int *)0x0) {

    return 0;

  }

LAB_00589cce:

  iVar1 = -(int)param_3;

  if ((DAT_00aaa668 <= param_3) && (param_3 <= g_flOne)) {

    iVar1 = (**(code **)(*piVar3 + 0x244))();

    iVar1 = -(int)((float)iVar1 * param_3);

  }

  iVar2 = (**(code **)(*piVar3 + 0x23c))();

  iVar4 = iVar2 - iVar1;

  if ((param_4 == '\0') && (iVar4 < 1)) {

    iVar1 = iVar2 + -1;

  }

  FUN_004d7e30(0,iVar1,param_1,piVar3,1,1,0,DAT_009d4d28,DAT_009d4d2c,DAT_009d4d30,DAT_009d4d34,0);

  if (iVar2 == iVar4) {

    return 0;

  }

  return iVar4 - iVar2;

}
