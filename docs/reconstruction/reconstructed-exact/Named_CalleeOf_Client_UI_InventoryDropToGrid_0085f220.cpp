// =============================================================================
// Named_CalleeOf_Client_UI_InventoryDropToGrid_0085f220
// -----------------------------------------------------------------------------
// Stable ID: aa_0085f220
// Callee of Client_UI_InventoryDropToGrid
// Address:   0x0085f220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UI_InventoryDropToGrid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×17, return×8, goto×1.
//  - Notable callees: FUN_0085f1d0×4, FUN_0085f1f0×3, CONCAT31×2, FUN_0085e820×2, CONCAT22, FUN_00413b30, FUN_00570840, FUN_0085f220.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Client_UI_InventoryDropToGrid
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Named_CalleeOf_Client_UI_InventoryDropToGrid_0085f220(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  short sVar6;

  int *in_EAX;

  int *piVar7;

  int *piVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  byte bVar11;

  byte extraout_CL;

  char extraout_CL_00;

  int *extraout_ECX;

  char extraout_DL;

  char extraout_DL_00;

  byte bVar12;

  int *unaff_ESI;

  float fVar13;

  float fVar14;

  uint64_t uVar15;

  uint *puVar16;

  int **ppiVar17;

  uint uVar18;

  uint uVar19;

  int *piStack_60;

  uint uStack_5c;

  uint8_t *puStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  byte *pbStack_4c;

  byte *pbStack_48;

  int *piStack_44;

  uint8_t *puStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint8_t local_18 [24];

  

  if ((((in_EAX == (int *)0x0) || (param_1 == 0)) || (param_2 == 0)) || (unaff_ESI[0x15b] == 0)) {

    return 0;

  }

  uStack_38 = 1;

  uStack_3c = 1;

  puStack_40 = local_18;

  piStack_44 = (int *)0x85f266;

  piVar7 = (int *)(**(code **)(*unaff_ESI + 0x120))();

  piStack_44 = (int *)0x0;

  pbStack_48 = (byte *)0x1;

  pbStack_4c = &stack0xffffffd4;

  uStack_50 = 0x85f27b;

  piVar8 = (int *)(**(code **)(*in_EAX + 0x144))();

  iVar9 = *piVar8;

  iVar1 = *piVar7;

  uStack_50 = 1;

  iStack_54 = 1;

  puStack_58 = &stack0xffffffd0;

  uStack_5c = 0x85f29e;

  piVar7 = (int *)(**(code **)(*unaff_ESI + 0x120))();

  uStack_5c = 0;

  piStack_60 = (int *)0x1;

  piVar8 = (int *)(**(code **)(*in_EAX + 0x120))();

  iVar2 = *piVar8;

  iVar3 = *piVar7;

  piStack_44 = (int *)(piVar8[1] - piVar7[1]);

  if (iVar9 - iVar1 < 0) {

    return 0;

  }

  pbStack_48 = (byte *)(iVar2 - iVar3);

  piVar7 = (int *)(**(code **)(*unaff_ESI + 0x140))(&puStack_58,1);

  iVar4 = iStack_54;

  if (*piVar7 < iVar9 - iVar1) {

    return 0;

  }

  if (iStack_54 < 0) {

    return 0;

  }

  uVar10 = 0;

  iVar9 = (**(code **)(*unaff_ESI + 0x140))(&puStack_58,1);

  if (*(int *)(iVar9 + 4) < iVar4) {

    return 0;

  }

  uVar18 = 1;

  (**(code **)(*unaff_ESI + 0x140))(&piStack_60,1);

  iVar9 = FUN_0085f1f0();

  fVar13 = (float)(int)uStack_5c;

  bVar12 = (byte)(int)((float)iVar9 * ((float)(iVar2 - iVar3) / (float)*extraout_ECX));

  fVar14 = (float)CONCAT31((int3)((uint)uVar10 >> 8),bVar12);

  iVar9 = (**(code **)(*unaff_ESI + 0x140))(&uStack_50,1);

  fVar14 = fVar14 / (float)*(int *)(iVar9 + 4);

  iVar9 = FUN_0085f1d0();

  bVar11 = (byte)(int)(fVar14 * (float)iVar9);

  if ((char)bVar12 < '\0') {

    bVar12 = 0;

    uVar18 = 0;

  }

  if ((char)bVar11 < '\0') {

    bVar11 = 0;

  }

  if ((int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * DAT_00aaa67c) / 2 -

      (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * _DAT_00aaa6ac) * (int)(char)bVar12 <

      (int)fVar13) {

    bVar12 = bVar12 + 1;

    uVar18 = (uint)bVar12;

  }

  if ((int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * DAT_00aaa678) / 2 -

      (int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * _DAT_00aaa6a8) * (int)(char)bVar11 <

      (int)&pbStack_4c) {

    bVar11 = bVar11 + 1;

  }

  uVar19 = (uint)bVar11;

  uVar15 = FUN_0085f1f0();

  if ((int)uVar15 < (int)(char)bVar12 + (int)((ulonglong)uVar15 >> 0x20)) {

    cVar5 = FUN_0085f1f0();

    bVar12 = cVar5 - extraout_DL;

    uVar18 = (uint)bVar12;

  }

  uVar15 = FUN_0085f1d0();

  bVar11 = extraout_CL;

  if ((int)uVar15 < (int)(char)extraout_CL + (int)((ulonglong)uVar15 >> 0x20)) {

    cVar5 = FUN_0085f1d0();

    bVar11 = cVar5 - extraout_DL_00;

    uVar19 = (uint)bVar11;

  }

  *pbStack_4c = bVar12;

  *pbStack_48 = bVar11;

  iVar9 = in_EAX[0x129];

  ppiVar17 = &piStack_60;

  uVar15 = FUN_0085f1d0(ppiVar17);

  sVar6 = (short)(char)uVar15 * (short)(char)unaff_ESI[0x159];

  cVar5 = FUN_00570840((int)((ulonglong)uVar15 >> 0x20),iVar9,uVar18,

                       CONCAT31((int3)(CONCAT22((short)((ulonglong)uVar15 >> 0x10),sVar6) >> 8),

                                (char)sVar6 + extraout_CL_00),ppiVar17);

  piVar7 = piStack_44;

  if (cVar5 == '\0') {

    return 0;

  }

  if (piStack_44 != (int *)0x0) {

    if (((uint)piStack_60 & uStack_5c) == 0xffffffff) {

      *piStack_44 = 0;

    }

    else {

      iVar9 = FUN_00413b30(piStack_60,uStack_5c);

      *piVar7 = iVar9;

    }

  }

  if (unaff_ESI[0x15d] == 0) {

    return 1;

  }

  if ((piVar7 == (int *)0x0) || (iVar9 = *piVar7, iVar9 == 0)) {

    pbStack_4c = *(byte **)unaff_ESI[0x15d];

    uVar10 = FUN_0085e820(uVar19);

    (**(code **)(pbStack_4c + 0x11c))(uVar10);

    iVar9 = *(int *)unaff_ESI[0x15d];

    uVar10 = (**(code **)(*in_EAX + 0x140))(&uStack_5c,1);

    (**(code **)(iVar9 + 0x138))(uVar10);

    if ((*(int *)(unaff_ESI[0x15b] + 4) == 5) &&

       (iVar9 = (**(code **)(*in_EAX + 0x3ac))(), *(int *)(*(int *)(iVar9 + 0xa8) + 0x38) == 4)) {

      (**(code **)(*(int *)unaff_ESI[0x15d] + 0x15c))(0,&DAT_00afdad4);

      goto LAB_0085f625;

    }

    puVar16 = &uStack_5c;

    uStack_5c = 0xff828282;

  }

  else {

    puStack_58 = *(uint8_t **)(iVar9 + 0x498);

    iStack_54 = *(int *)(iVar9 + 0x49c);

    iVar9 = *(int *)unaff_ESI[0x15d];

    uVar10 = FUN_0085e820(iStack_54);

    (**(code **)(iVar9 + 0x11c))(uVar10);

    iVar9 = *(int *)unaff_ESI[0x15d];

    uVar10 = (**(code **)(*(int *)*piVar7 + 0x140))(&uStack_5c,1);

    (**(code **)(iVar9 + 0x138))(uVar10);

    puVar16 = (uint *)&DAT_00afdad8;

  }

  (**(code **)(*(int *)unaff_ESI[0x15d] + 0x15c))(0,puVar16);

LAB_0085f625:

  (**(code **)(*(int *)unaff_ESI[0x15d] + 0x34c))();

  return 1;

}
