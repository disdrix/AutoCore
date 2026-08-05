// =============================================================================
// FUN_00969210
// -----------------------------------------------------------------------------
// Stable ID: aa_00969210
// Address:   0x00969210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969210 @ 0x00969210
// Stable ID: aa_00969210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, return×1.
//  - Notable callees: block×15, FUN_00456960×2, FUN_007321d0×2, FUN_00968c00, FUN_00969210.
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

/* WARNING: Removing unreachable block (ram,0x00969491) */

/* WARNING: Removing unreachable block (ram,0x009692e3) */

/* WARNING: Removing unreachable block (ram,0x009692f9) */

/* WARNING: Removing unreachable block (ram,0x0096939f) */

/* WARNING: Removing unreachable block (ram,0x009693b3) */

/* WARNING: Removing unreachable block (ram,0x0096947c) */

/* WARNING: Removing unreachable block (ram,0x009693f7) */

/* WARNING: Removing unreachable block (ram,0x00969410) */

/* WARNING: Removing unreachable block (ram,0x00969416) */

/* WARNING: Removing unreachable block (ram,0x00969428) */

/* WARNING: Removing unreachable block (ram,0x00969440) */

/* WARNING: Removing unreachable block (ram,0x00969424) */

/* WARNING: Removing unreachable block (ram,0x0096944d) */

/* WARNING: Removing unreachable block (ram,0x00969461) */

/* WARNING: Removing unreachable block (ram,0x00969474) */



void __fastcall FUN_00969210(int *param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  void *pvVar4;

  int *piVar5;

  void *pvStack_18;

  void *pvStack_c;

  int *piStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  piStack_8 = (int *)&LAB_009b2348;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (DAT_00afa360 == -1) {

    ExceptionList = &pvStack_c;

    FUN_00968c00();

  }

  (**(code **)(*param_1 + 0x14))(&DAT_00afdfec);

  (**(code **)(*param_1 + 0x18))(&DAT_00d1a6c0);

  (**(code **)(*param_1 + 0x1c))(0x3f800000);

  (**(code **)(*param_1 + 0x34))();

  piVar1 = (int *)param_1[0x31];

  for (piVar5 = (int *)param_1[0x30]; piVar5 != piVar1; piVar5 = piVar5 + 1) {

    iVar2 = *piVar5;

    uVar3 = *(uint *)(iVar2 + 0xbc);

    if (((uVar3 >> 1 & 1) == 0) && ((uVar3 >> 2 & 1) == 0)) {

      pvVar4 = operator_new(0x210);

      if (pvVar4 != (void *)0x0) {

        FUN_007321d0(pvVar4,iVar2);

      }

      FUN_00456960(0);

    }

  }

  piVar1 = (int *)param_1[0x35];

  for (piVar5 = (int *)param_1[0x34]; piVar5 != piVar1; piVar5 = piVar5 + 1) {

    iVar2 = *piVar5;

    uVar3 = *(uint *)(iVar2 + 0xbc);

    if (((uVar3 >> 1 & 1) == 0) && ((uVar3 >> 2 & 1) == 0)) {

      pvVar4 = operator_new(0x210);

      if (pvVar4 != (void *)0x0) {

        FUN_007321d0(pvVar4,iVar2);

      }

      FUN_00456960(0);

    }

  }

  (**(code **)(*piStack_8 + 0x58))();

  ExceptionList = pvStack_18;

  return;

}
