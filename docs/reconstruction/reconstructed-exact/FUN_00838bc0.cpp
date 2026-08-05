// =============================================================================
// FUN_00838bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00838bc0
// Address:   0x00838bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00838bc0 @ 0x00838bc0
// Stable ID: aa_00838bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×15, return×8, goto×4.
//  - Notable callees: FUN_004c77b0, FUN_00838ad0, FUN_00838bc0.
//  - Return sites: 8.

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

void FUN_00838bc0(void)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  char cVar4;

  int iVar5;

  int *unaff_ESI;

  float fStack_20;

  float fStack_8;

  float fStack_4;

  

  cVar4 = (**(code **)(*unaff_ESI + 0xd0))();

  if (cVar4 == '\0') {

    return;

  }

  if (unaff_ESI[0x146] == 0) {

    return;

  }

  iVar5 = *(int *)(unaff_ESI[0x146] + 0xa8);

  iVar1 = *(int *)(iVar5 + 0x34);

  if (iVar1 == 0) {

    return;

  }

  if (iVar1 == -1) {

    return;

  }

  if (iVar5 == 0) {

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (unaff_ESI[0x14f] == 0) {

    return;

  }

  fStack_8 = 0.0;

  fStack_20 = 1.2080752e-38;

  cVar4 = (**(code **)(*(int *)unaff_ESI[0x146] + 0x198))();

  if (cVar4 != '\0') goto LAB_00838ccb;

  if (*(char *)(DAT_00d1b644 + 0xf5) == '\0') {

LAB_00838c63:

    fStack_20 = 1.2080831e-38;

    iVar5 = (**(code **)(*(int *)unaff_ESI[0x146] + 0x1ac))();

    piVar2 = (int *)unaff_ESI[0x146];

    if (0 < iVar5) {

      fStack_20 = 1.2080859e-38;

      iVar5 = (**(code **)(*piVar2 + 0x1b0))();

      fStack_4 = (float)iVar5;

      fStack_20 = 1.2080887e-38;

      iVar5 = (**(code **)(*piVar2 + 0x1ac))();

      fStack_8 = fStack_4 / (float)iVar5;

      goto LAB_00838ccb;

    }

    if (((uint)piVar2[0x5f] >> 10 & 1) == 0) goto LAB_00838ccb;

  }

  else {

    fStack_20 = 0.0;

    iVar5 = (**(code **)(*(int *)unaff_ESI[0x146] + 0x210))();

    if (iVar5 == 0) goto LAB_00838c63;

  }

  fStack_8 = g_flOne;

LAB_00838ccb:

  fVar3 = fStack_8;

  fStack_20 = fStack_8;

  (**(code **)(*(int *)unaff_ESI[0x14f] + 0x3ac))();

  cVar4 = FUN_00838ad0();

  if (cVar4 == '\0') {

    FUN_004c77b0(&fStack_8,fVar3);

  }

  (**(code **)(*(int *)unaff_ESI[0x14f] + 0x15c))(1,&stack0xffffffec);

  (**(code **)(*(int *)unaff_ESI[0x14f] + 0x15c))(2,&stack0xffffffec);

  if (unaff_ESI[0x147] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x147] + 0x15c))(0,&fStack_20);

  }

  (**(code **)(*(int *)unaff_ESI[0x14f] + 0x34c))();

  if (unaff_ESI[0x147] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x147] + 0x34c))();

  }

  return;

}
