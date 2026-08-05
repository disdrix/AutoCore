// =============================================================================
// FUN_0075fc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0075fc40
// Address:   0x0075fc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075fc40 @ 0x0075fc40
// Stable ID: aa_0075fc40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: FUN_0040ead0, FUN_0043b800, FUN_007334a0, FUN_0073bf90, FUN_00746400, FUN_0075fc40, FUN_00962780, FUN_00966530.
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

uint32_t /* width from decompiler */ FUN_0075fc40(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *unaff_EDI;

  bool bVar7;

  int iStack_68;

  int iStack_64;

  int iStack_3c;

  int iStack_38;

  void *pvStack_34;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b317c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar4 = operator_new(0x540);

  local_4 = 0;

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_00966c10();

  }

  local_4 = 0xffffffff;

  unaff_EDI[0x1e7] = iVar5;

  puVar6 = operator_new(4);

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar6 = &PTR_FUN_00aa5e3c;

    FUN_00746400();

  }

  iVar5 = FUN_007334a0();

  if (-1 < iVar5) {

    FUN_00962780();

  }

  FUN_009674b0();

  FUN_00989e00();

  iVar5 = FUN_0096a440();

  if (iVar5 < 0) {

    vog_LogMessage();

    ExceptionList = local_c;

    return 0xffffffff;

  }

  (**(code **)(*(int *)*unaff_EDI + 0x48))();

  piVar1 = (int *)*unaff_EDI;

  (**(code **)(*piVar1 + 0xa0))();

  unaff_EDI[4] = unaff_EDI[0xb8];

  piVar2 = DAT_00d1f048;

  *DAT_00d1f048 = unaff_EDI[2];

  piVar2[2] = unaff_EDI[4];

  FUN_0073bf90();

  *(bool *)(DAT_00d1f048 + 0xb) = 1 < *(int *)(DAT_00d1f044 + 0x784);

  pvVar4 = operator_new(0x80);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_00966530();

  }

  iVar3 = DAT_00d1f614;

  bVar7 = DAT_00d1f614 != 0;

  unaff_EDI[0x1e8] = iVar5;

  if (bVar7) {

    *(int *)(iVar3 + 0x364) = *(int *)(iVar3 + 0x364) + unaff_EDI[0xb1] + 1;

    iVar5 = FUN_0040ead0();

    *(int *)(iVar3 + 0x3ac) =

         *(int *)(iVar3 + 0x3ac) +

         ((uint)(iVar5 * (unaff_EDI[0xb1] + 1) * unaff_EDI[0xaf] * unaff_EDI[0xae]) >> 3);

  }

  if ((unaff_EDI[0xb7] != 0) && (iVar3 != 0)) {

    *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + 1;

    iVar5 = FUN_0043b800();

    *(int *)(iVar3 + 0x3b0) =

         *(int *)(iVar3 + 0x3b0) + ((uint)(iVar5 * unaff_EDI[0xaf] * unaff_EDI[0xae]) >> 3);

  }

  *(uint8_t *)(unaff_EDI + 0x1ea) = 0;

  iVar5 = (**(code **)(*(int *)*unaff_EDI + 0x1d8))((int *)*unaff_EDI);

  if (-1 < iVar5) {

    (**(code **)(*piVar1 + 0x18))(piVar1,1);

    iVar5 = (**(code **)(iRam00000005 + 0x1c))(5,&stack0xfffffe64,0x160,0);

    if ((((-1 < iVar5) && (iStack_68 != 0)) && (iStack_3c != 0)) &&

       ((iStack_64 != 0 && (iStack_38 != 0)))) {

      *(uint8_t *)(unaff_EDI + 0x1ea) = 1;

    }

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 8))(piVar1);

    }

  }

  ExceptionList = pvStack_34;

  return 0;

}
