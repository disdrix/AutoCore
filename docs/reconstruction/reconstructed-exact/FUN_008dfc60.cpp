// =============================================================================
// FUN_008dfc60
// -----------------------------------------------------------------------------
// Stable ID: aa_008dfc60
// Address:   0x008dfc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dfc60 @ 0x008dfc60
// Stable ID: aa_008dfc60
// Embedded strings (evidence for future rename):
//   - "i_d_dt_2d_wnd_tree_branch.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×11, goto×4, return×2.
//  - Notable callees: FUN_00415ed0×2, FUN_00416010×2, FUN_00415d80, FUN_00418700, FUN_00418790, FUN_00834940, FUN_008dfc60.
//  - Strings: "i_d_dt_2d_wnd_tree_branch.xml".
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

void FUN_008dfc60(int *param_1,int param_2,int param_3,char param_4)



{

  int iVar1;

  int iVar2;

  char cVar3;

  void *pvVar4;

  int iVar5;

  int *piVar6;

  int unaff_retaddr;

  int *piStack_28;

  int iStack_24;

  int *piStack_20;

  int iStack_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3a24;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 == '\0') {

    ExceptionList = pvStack_c;

    return;

  }

  pvVar4 = operator_new(0x4e0);

  piVar6 = (int *)0x0;

  iStack_4 = 0;

  if (pvVar4 != (void *)0x0) {

    piVar6 = (int *)FUN_00834940(pvVar4);

  }

  iStack_4 = 0xffffffff;

  piStack_28 = piVar6;

  (**(code **)(*param_1 + 0xa8))(piVar6);

  (**(code **)(*piVar6 + 0x28))("i_d_dt_2d_wnd_tree_branch.xml");

  iVar1 = param_1[0x146];

  iStack_18 = (((int)pvVar4 * 2 + 1) * param_1[0x147]) / 2 + param_1[0x145];

  iVar5 = param_1[0x144];

  piStack_28 = (int *)(((param_3 * 2 + 1) * param_1[0x147]) / 2 + param_1[0x145]);

  FUN_00415d80(0,0);

  iVar2 = piVar6[0x124];

  piStack_20 = (int *)iStack_18;

  iStack_24 = ((unaff_retaddr * 2 + 1) * iVar1) / 2 + iVar5;

  iStack_4 = FUN_00415ed0(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4));

  FUN_00416010();

  *(int *)(iVar2 + 4) = iStack_4;

  **(int **)(iStack_4 + 4) = iStack_4;

  iVar2 = piVar6[0x124];

  piStack_20 = piStack_28;

  iStack_24 = ((param_2 * 2 + 1) * iVar1) / 2 + iVar5;

  iStack_4 = FUN_00415ed0(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4));

  FUN_00416010();

  *(int *)(iVar2 + 4) = iStack_4;

  **(int **)(iStack_4 + 4) = iStack_4;

  if (DAT_00d1b6d8 == 0) {

LAB_008dfe42:

    iStack_4 = DAT_00afdf0c;

  }

  else {

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       DAT_00d1b6d8) + 0x3c) + 0x532);

    if (cVar3 == '\0') {

      iStack_4 = -0xe2af01;

    }

    else if (cVar3 == '\x01') {

      iStack_4 = -0x9400c0;

    }

    else {

      if (cVar3 != '\x02') goto LAB_008dfe42;

      iStack_4 = -0x482f6;

    }

  }

  piVar6[0x136] = iStack_4;

  if (DAT_00d1b6d8 != 0) {

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       DAT_00d1b6d8) + 0x3c) + 0x532);

    if (cVar3 == '\0') {

      iStack_4 = -0xf5e19e;

      goto LAB_008dfece;

    }

    if (cVar3 == '\x01') {

      iStack_4 = -0xd49be6;

      goto LAB_008dfece;

    }

    if (cVar3 == '\x02') {

      iStack_4 = -0x9bd5fb;

      goto LAB_008dfece;

    }

  }

  iStack_4 = DAT_00afdf00;

LAB_008dfece:

  piVar6[0x137] = iStack_4;

  *(char *)(piVar6 + 0x122) = param_4;

  if (param_4 == '\0') {

    (**(code **)(*piVar6 + 0x15c))(0,piVar6 + 0x137);

  }

  else {

    (**(code **)(*piVar6 + 0x15c))(0,piVar6 + 0x136);

  }

  (**(code **)(*piVar6 + 0x34c))();

  iVar1 = param_1[0x1ac];

  iVar5 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&piStack_28);

  FUN_00418790();

  *(int *)(iVar1 + 4) = iVar5;

  **(int **)(iVar5 + 4) = iVar5;

  ExceptionList = pvStack_c;

  return;

}
