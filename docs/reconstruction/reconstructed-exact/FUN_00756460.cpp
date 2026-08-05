// =============================================================================
// FUN_00756460
// -----------------------------------------------------------------------------
// Stable ID: aa_00756460
// Address:   0x00756460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756460 @ 0x00756460
// Stable ID: aa_00756460
// Embedded strings (evidence for future rename):
//   - "gFogDensity"
//   - "gFogColor"
//   - "Direction"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~157 non-empty decompiler lines.
//  - Control keywords: if×12, return×2, while×1.
//  - Notable callees: FUN_00416160, FUN_00442b90, FUN_00442d50, FUN_00442e40, FUN_00756460, FUN_0075c500, FUN_0076c3c0, FUN_00972f10.
//  - Strings: "gFogDensity"; "gFogColor"; "Direction".
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

uint32_t /* width from decompiler */ __thiscall FUN_00756460(int param_1,void *param_2)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int extraout_ECX;

  int iVar9;

  int iVar10;

  undefined ***pppuStack_164;

  int *piStack_160;

  int *piStack_15c;

  char *pcStack_158;

  int **ppiStack_154;

  undefined **ppuStack_150;

  int *piStack_14c;

  int iStack_148;

  char *pcStack_144;

  int *piStack_140;

  int *piStack_13c;

  int iStack_138;

  undefined **ppuStack_134;

  void *pvStack_54;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b2475;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  *(uint8_t *)(DAT_00d1f048 + 0x2d) = *(uint8_t *)(param_1 + 0x78);

  *(uint8_t *)(DAT_00d1f048 + 0xf) = *(uint8_t *)(param_1 + 0x78);

  if (*(char *)(param_1 + 0x48) != '\0') {

    ppuStack_134 = (undefined **)0x7564ab;

    uVar6 = FUN_0076c3c0();

    if (*(uint *)(extraout_ECX + 0x34) <= uVar6) {

      *(uint8_t *)(param_1 + 0x48) = 0;

    }

  }

  iVar3 = DAT_00d1f05c;

  if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

    piStack_13c = (int *)0x0;

  }

  else {

    piStack_13c = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    ppuStack_134 = (undefined **)0xa9f558;

    iStack_138 = 0;

    piStack_140 = (int *)0x7564d7;

    piStack_13c = (int *)(**(code **)(*piStack_13c + 0x24))();

  }

  piStack_140 = *(int **)(*(int *)(iVar3 + 4) + 0xc);

  ppuStack_134 = (undefined **)0xffffffff;

  iStack_138 = param_1 + 0x70;

  pcStack_144 = (char *)0x7564ea;

  (**(code **)(*piStack_140 + 0x50))();

  if (*(int *)(*(int *)(iVar3 + 4) + 0xc) == 0) {

    piStack_14c = (int *)0x0;

  }

  else {

    piStack_14c = *(int **)(*(int *)(iVar3 + 4) + 0xc);

    pcStack_144 = "gFogDensity";

    iStack_148 = 0;

    ppuStack_150 = (undefined **)0x756507;

    piStack_14c = (int *)(**(code **)(*piStack_14c + 0x24))();

  }

  ppuStack_150 = *(undefined ***)(*(int *)(iVar3 + 4) + 0xc);

  pcStack_144 = (char *)0xffffffff;

  iStack_148 = param_1 + 0x74;

  ppiStack_154 = (int **)0x75651a;

  (**(code **)(*ppuStack_150 + 0x50))();

  piStack_140 = *(int **)(param_1 + 0x60);

  piStack_13c = *(int **)(param_1 + 100);

  iStack_138 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  ppuStack_134 = *(undefined ***)(param_1 + 0x6c);

  ppiStack_154 = &piStack_140;

  pcStack_158 = "gFogColor";

  piStack_15c = (int *)0x756549;

  FUN_00442d50();

  if (*(int *)(*(int *)(iVar3 + 4) + 0xc) == 0) {

    piStack_15c = (int *)0x0;

  }

  else {

    piStack_15c = *(int **)(*(int *)(iVar3 + 4) + 0xc);

    ppiStack_154 = (int **)0xa30104;

    pcStack_158 = (char *)0x0;

    piStack_160 = (int *)0x75656f;

    piStack_15c = (int *)(**(code **)(*piStack_15c + 0x24))();

  }

  piStack_160 = *(int **)(*(int *)(iVar3 + 4) + 0xc);

  ppiStack_154 = (int **)0xffffffff;

  pcStack_158 = &stack0xfffffed0;

  pppuStack_164 = (undefined ***)0x756583;

  (**(code **)(*piStack_160 + 0x50))();

  if (DAT_00afe010 != 0) {

    pppuStack_164 = *(undefined ****)(DAT_00afe010 + 0xc);

    (*(code *)(*pppuStack_164)[0x41])();

  }

  if (DAT_00afe034 != 0) {

    pppuStack_164 = *(undefined ****)(DAT_00afe034 + 0xc);

    (*(code *)(*pppuStack_164)[0x41])();

  }

  pppuStack_164 = *(undefined ****)(param_1 + 4);

  FUN_00442b90();

  iVar3 = *(int *)((int)param_2 + 0x30);

  pppuStack_164 = (undefined ***)0x7565c6;

  FUN_0075c500();

  pppuStack_164 = &ppuStack_134;

  ppuStack_134 = &PTR_FUN_00a9f494;

  (**(code **)(**(int **)(param_1 + 8) + 0x28))(iVar3 + 0xbc);

  if ((*(char *)(DAT_00d1f048 + 0xf) != '\0') &&

     (piVar4 = *(int **)(*(int *)(param_1 + 4) + 0x3c), piVar4 != (int *)0x0)) {

    uVar7 = (**(code **)(*piVar4 + 0x1c))();

    FUN_00416160(uVar7);

    uVar7 = (**(code **)(*piVar4 + 0x40))("Direction");

    (**(code **)(*piVar4 + 0x5c))(uVar7,&stack0xfffffed8);

    FUN_00972f10(&pppuStack_164,&stack0xfffffed0);

    FUN_00442e40(&piStack_140);

    iVar5 = g_nInferredThreatDefault;

    iVar8 = 0;

    iVar10 = 0;

    while( true ) {

      if (*(int *)(iVar3 + 0xc0) == 0) {

        iVar9 = 0;

      }

      else {

        iVar9 = *(int *)(iVar3 + 0xc4) - *(int *)(iVar3 + 0xc0) >> 4;

      }

      if (iVar9 <= iVar10) break;

      pfVar1 = (float *)(iVar8 + 8 + (int)piStack_13c);

      if (0.0 < *(float *)(iVar8 + 4 + (int)piStack_13c) * (float)piStack_160 +

                *(float *)(iVar8 + (int)piStack_13c) * (float)pppuStack_164 +

                (float)piStack_15c * *pfVar1) {

        pfVar2 = (float *)(iVar8 + 0xc + (int)piStack_13c);

        *pfVar2 = *pfVar2 - (*(float *)(iVar8 + 4 + (int)piStack_13c) *

                             (0.0 - (float)piStack_160) * (float)iVar5 +

                             *(float *)(iVar8 + (int)piStack_13c) *

                             (0.0 - (float)pppuStack_164) * (float)iVar5 +

                            (0.0 - (float)piStack_15c) * (float)iVar5 * *pfVar1);

      }

      iVar10 = iVar10 + 1;

      iVar8 = iVar8 + 0x10;

    }

    piStack_14c = param_2;

    ppuStack_150 = &PTR_LAB_00a9f524;

    (**(code **)(**(int **)(param_1 + 8) + 0x28))(&piStack_140,&ppuStack_150);

    if (param_2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(param_2);

    }

  }

  ExceptionList = pvStack_54;

  return 0;

}
