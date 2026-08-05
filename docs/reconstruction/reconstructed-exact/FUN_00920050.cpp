// =============================================================================
// FUN_00920050
// -----------------------------------------------------------------------------
// Stable ID: aa_00920050
// Address:   0x00920050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00920050 @ 0x00920050
// Stable ID: aa_00920050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×18, return×2.
//  - Notable callees: FUN_007fca10×5, FUN_008bb180, FUN_008bc360, FUN_00920050, FUN_0092da70, FUN_0092f000, FUN_00934880.
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

void FUN_00920050(void)



{

  int *piVar1;

  char cVar2;

  void *pvVar3;

  int iVar4;

  int *unaff_EDI;

  bool bVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b7def;

  pvStack_c = ExceptionList;

  if (unaff_EDI[0x31e] != 0) {

    ExceptionList = &pvStack_c;

    FUN_008bb180();

    ExceptionList = pvStack_c;

    return;

  }

  ExceptionList = &pvStack_c;

  *(uint8_t *)((int)unaff_EDI + 0xc65) = 0;

  *(uint8_t *)((int)unaff_EDI + 0xc66) = 0;

  if (unaff_EDI[0x31a] != 0) {

    (**(code **)(*unaff_EDI + 0xb0))(unaff_EDI[0x31a]);

    if ((uint32_t /* width from decompiler */ *)unaff_EDI[0x31a] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_EDI[0x31a])(1);

    }

    unaff_EDI[0x31a] = 0;

  }

  if (unaff_EDI[0x31b] != 0) {

    (**(code **)(*unaff_EDI + 0xb0))(unaff_EDI[0x31b]);

    if ((uint32_t /* width from decompiler */ *)unaff_EDI[0x31b] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_EDI[0x31b])(1);

    }

    unaff_EDI[0x31b] = 0;

  }

  if ((int *)unaff_EDI[0x32d] != (int *)0x0) {

    cVar2 = (**(code **)(*(int *)unaff_EDI[0x32d] + 0x3d8))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*(int *)unaff_EDI[0x32d] + 0xd0))();

      if (cVar2 != '\0') {

        (**(code **)(*(int *)unaff_EDI[0x32d] + 4))(0);

      }

    }

  }

  if ((int *)unaff_EDI[0x32e] != (int *)0x0) {

    cVar2 = (**(code **)(*(int *)unaff_EDI[0x32e] + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(*(int *)unaff_EDI[0x32e] + 4))(0);

    }

  }

  piVar1 = (int *)unaff_EDI[0x330];

  if (piVar1 != (int *)0x0) {

    if (piVar1[0x158] != 0) {

      (**(code **)(*piVar1 + 0x444))(0);

    }

    cVar2 = (**(code **)(*(int *)unaff_EDI[0x330] + 0x3d8))();

    if (cVar2 != '\0') {

      (**(code **)(*(int *)unaff_EDI[0x330] + 0x440))();

    }

    (**(code **)(*unaff_EDI + 0xb0))(unaff_EDI[0x330]);

    if ((uint32_t /* width from decompiler */ *)unaff_EDI[0x330] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_EDI[0x330])(1);

    }

    unaff_EDI[0x330] = 0;

  }

  pvVar3 = operator_new(0x594);

  uStack_4 = 0;

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_008bc360(pvVar3);

  }

  uStack_4 = 0xffffffff;

  bVar5 = DAT_00afa140 != '\0';

  unaff_EDI[0x31e] = iVar4;

  if (bVar5) {

    FUN_0092da70(&DAT_00d1a840);

  }

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_00934880();

  (**(code **)(*unaff_EDI + 0x3ec))();

  unaff_EDI[0x1a] = unaff_EDI[0x1a] + 1;

  iVar4 = unaff_EDI[0x1a];

  unaff_EDI[0x1d] = (int)(float)-iVar4;

  if (unaff_EDI[0x1c] < iVar4) {

    unaff_EDI[0x1c] = iVar4;

  }

  pvVar3 = (void *)0x1;

  (**(code **)(*unaff_EDI + 0x3f4))();

  unaff_EDI[0x145] = unaff_EDI[0x126];

  unaff_EDI[0x146] = unaff_EDI[0x127];

  unaff_EDI[0x126] = 0x4e24;

  unaff_EDI[0x127] = 0x4e23;

  (**(code **)(*unaff_EDI + 0xa8))(unaff_EDI[0x31e]);

  (**(code **)(*(int *)unaff_EDI[0x31e] + 0x74))(0x4e61);

  (**(code **)(*(int *)unaff_EDI[0x31e] + 0x43c))();

  (**(code **)(*unaff_EDI + 0x3ec))();

  unaff_EDI[0x1a] = unaff_EDI[0x1a] + 1;

  iVar4 = unaff_EDI[0x1a];

  unaff_EDI[0x1d] = (int)(float)-iVar4;

  if (unaff_EDI[0x1c] < iVar4) {

    unaff_EDI[0x1c] = iVar4;

  }

  (**(code **)(*unaff_EDI + 0x3f4))(1);

  FUN_0092f000();

  ExceptionList = pvVar3;

  return;

}
