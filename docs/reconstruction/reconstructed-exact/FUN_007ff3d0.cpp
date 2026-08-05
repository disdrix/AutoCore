// =============================================================================
// FUN_007ff3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ff3d0
// Address:   0x007ff3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ff3d0 @ 0x007ff3d0
// Stable ID: aa_007ff3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×29, return×3, while×3, goto×3, do×2, for×1.
//  - Notable callees: FUN_00403450×2, FUN_00411e40×2, FUN_007fbee0×2, FUN_007fca10×2, FUN_00857ee0×2, FUN_00402d50, FUN_00411e10, FUN_007aa3e0.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x007ff764) */



void __thiscall FUN_007ff3d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  char *pcVar8;

  int local_1b0;

  uint8_t *puStack_1a4;

  uint8_t auStack_1a0 [128];

  uint16_t uStack_120;

  uint32_t /* width from decompiler */ auStack_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b1590;

  local_14 = ExceptionList;

  if (*(int *)(param_1 + 0xde8) == 0) {

    return;

  }

  if ((DAT_00d1e818 == param_2) && (DAT_00d1e81c == param_3)) {

    return;

  }

  ExceptionList = &local_14;

  piVar3 = (int *)FUN_007aa3e0();

  DAT_00d1e818 = param_2;

  DAT_00d1e81c = param_3;

  if ((*piVar3 < param_2) || (piVar3[1] < param_3)) {

    DAT_00d1e818 = *piVar3;

    DAT_00d1e81c = piVar3[1];

  }

  FUN_007aac60();

  FUN_007b1900();

  if (*(int **)(param_1 + 0x309c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x309c) + 0x28))(0);

  }

  if (*(int **)(param_1 + 0x30a0) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30a0) + 0x28))(0);

  }

  if (*(int **)(param_1 + 0x30a4) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30a4) + 0x28))(0);

  }

  if (*(int **)(param_1 + 0x30a8) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30a8) + 0x28))(0);

  }

  if (*(int **)(param_1 + 0x30ac) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30ac) + 0x28))(0);

  }

  if (*(int **)(param_1 + 0x30b0) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30b0) + 0x28))(0);

  }

  *(uint8_t *)(param_1 + 0x30b4) = 1;

  *(uint8_t *)(param_1 + 0x30b5) = 0;

  if (*(int **)(param_1 + 0x309c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x309c) + 4))(0);

  }

  FUN_007fc970();

  *(uint8_t *)(param_1 + 0x30b8) = 1;

  *(uint8_t *)(param_1 + 0x30b9) = 0;

  if (*(int **)(param_1 + 0x30a4) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30a4) + 4))(0);

  }

  *(uint8_t *)(param_1 + 0x30ba) = 1;

  *(uint8_t *)(param_1 + 0x30bb) = 0;

  if (*(int **)(param_1 + 0x30a8) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30a8) + 4))(0);

  }

  *(uint8_t *)(param_1 + 0x30bc) = 1;

  *(uint8_t *)(param_1 + 0x30bd) = 0;

  if (*(int **)(param_1 + 0x30ac) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30ac) + 4))(0);

  }

  *(uint8_t *)(param_1 + 0x30be) = 1;

  *(uint8_t *)(param_1 + 0x30bf) = 0;

  if (*(int **)(param_1 + 0x30b0) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x30b0) + 4))(0);

  }

  if (*(int **)(param_1 + 0x113c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x113c) + 0x28))(0);

  }

  FUN_007fbbb0();

  if ((((*(int **)(param_1 + 0xf40) != (int *)0x0) &&

       (iVar1 = **(int **)(param_1 + 0xf40), iVar1 != 0)) &&

      (iVar4 = *(int *)(param_1 + 0xf38), iVar1 == iVar4)) &&

     ((*(int *)(iVar4 + 0xcb4) != 0 &&

      (cVar2 = (**(code **)(**(int **)(iVar4 + 0xcb4) + 0xd0))(), cVar2 != '\0')))) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0xf38) + 0xcb4) + 4))(0);

  }

  if (((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(*(int *)(param_1 + 0xe98) + 0xcd0) != 0)) &&

     (*(int *)(param_1 + 0x9b8) != 0)) {

    uVar5 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x9b8) + 0x494);

    FUN_007fc150();

    FUN_007fc270(uVar5);

  }

  if ((*(int **)(param_1 + 0x1044) != (int *)0x0) &&

     (cVar2 = (**(code **)(**(int **)(param_1 + 0x1044) + 0x3d8))(), cVar2 != '\0')) {

    FUN_007fca10();

  }

  FUN_007fdcc0(&DAT_00d1a840);

  FUN_007fca10();

  if (((*(int **)(param_1 + 0xf40) != (int *)0x0) &&

      (iVar1 = **(int **)(param_1 + 0xf40), iVar1 != 0)) && (*(int *)(iVar1 + 0x4c0) != 0)) {

    FUN_00411e10();

    iVar4 = FUN_00411e40();

    while (iVar4 != 0) {

      FUN_007fbee0();

      iVar4 = FUN_00411e40();

    }

    *(uint8_t *)(*(int *)(iVar1 + 0x4c0) + 0x1d) = 0;

  }

  local_1b0 = 0x3a;

  do {

    FUN_007fbee0();

    local_1b0 = local_1b0 + -1;

  } while (local_1b0 != 0);

  if ((*(int **)(param_1 + 0x1084) == (int *)0x0) ||

     (cVar2 = (**(code **)(**(int **)(param_1 + 0x1084) + 0x3d8))(), cVar2 == '\0')) {

    if ((*(int **)(param_1 + 0x10a4) == (int *)0x0) ||

       (cVar2 = (**(code **)(**(int **)(param_1 + 0x10a4) + 0x3d8))(), cVar2 == '\0')) {

      if ((((*(int **)(param_1 + 0x10a8) != (int *)0x0) &&

           (cVar2 = (**(code **)(**(int **)(param_1 + 0x10a8) + 0x3d8))(), cVar2 != '\0')) &&

          (iVar1 = *(int *)(param_1 + 0xe04), iVar1 != 0)) && (*(int *)(iVar1 + 0xe4f8) != 0)) {

        uStack_120 = 0;

        puVar6 = auStack_11e;

        for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar6 = 0;

          puVar6 = puVar6 + 1;

        }

        *(uint16_t *)puVar6 = 0;

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(iVar1 + 0xe4f8) + 0x124);

        pcVar7 = (char *)*puVar6;

        pcVar8 = (char *)&uStack_120;

        do {

          cVar2 = *pcVar7;

          *pcVar8 = cVar2;

          pcVar7 = pcVar7 + 1;

          pcVar8 = pcVar8 + 1;

        } while (cVar2 != '\0');

        uStack_c = 0xffffffff;

        if (puStack_1a4 != auStack_1a0) {

          free(puStack_1a4);

        }

        iVar1 = *(int *)(*(int *)(param_1 + 0x10a8) + 0x538);

        if (iVar1 != 0) {

          FUN_00857ee0(iVar1);

        }

      }

      goto LAB_007ff8be;

    }

    iVar1 = *(int *)(param_1 + 0xe04);

    if ((iVar1 == 0) || (*(int *)(iVar1 + 0xe4f8) == 0)) goto LAB_007ff8be;

    iVar1 = *(int *)(iVar1 + 0xe4f8);

    uVar5 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar1 + 0x124,uVar5);

    uStack_c = 1;

    iVar1 = *(int *)(*(int *)(param_1 + 0x10a4) + 0x518);

    if (iVar1 != 0) {

      FUN_00857ee0(iVar1);

    }

  }

  else {

    iVar1 = *(int *)(param_1 + 0xe04);

    if ((iVar1 == 0) || (*(int *)(iVar1 + 0xe4f8) == 0)) goto LAB_007ff8be;

    iVar1 = *(int *)(iVar1 + 0xe4f8);

    uVar5 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar1 + 0x124,uVar5);

    uStack_c = 0;

    iVar1 = *(int *)(*(int *)(param_1 + 0x1084) + 0x534);

    if (iVar1 != 0) {

      FUN_00850800(iVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1084) + 0x53c));

    }

  }

  uStack_c = 0xffffffff;

LAB_007ff8be:

  piVar3 = *(int **)(param_1 + 0x10b0);

  if ((((piVar3 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x3d8))(), cVar2 != '\0')) &&

      (piVar3[0x199] != 0)) &&

     ((cVar2 = (**(code **)(*(int *)piVar3[0x199] + 0x3d8))(), cVar2 != '\0' &&

      (cVar2 = (**(code **)(*(int *)piVar3[0x199] + 0xd0))(), cVar2 != '\0')))) {

    (**(code **)(*(int *)piVar3[0x199] + 0x47c))();

  }

  FUN_00931570();

  ExceptionList = local_14;

  return;

}
