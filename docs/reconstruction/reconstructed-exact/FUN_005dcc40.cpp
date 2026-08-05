// =============================================================================
// FUN_005dcc40
// -----------------------------------------------------------------------------
// Stable ID: aa_005dcc40
// Address:   0x005dcc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dcc40 @ 0x005dcc40
// Stable ID: aa_005dcc40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, do×3, while×3.
//  - Notable callees: CONCAT31, FUN_00418e60, FUN_004cbfc0, FUN_004cd220, FUN_004e4620, FUN_00513880, FUN_005138a0, FUN_005743e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005dcc40(int param_1,float *param_2)



{

  char *pcVar1;

  float *pfVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  uint32_t /* width from decompiler */ uStack_98;

  int aiStack_94 [3];

  int iStack_88;

  char *pcStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  int iStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  int iStack_74;

  int iStack_70;

  int iStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  int iStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  int aiStack_5c [3];

  uint32_t /* width from decompiler */ uStack_50;

  int iStack_4c;

  int iStack_48;

  int iStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  

  if (param_2 == (float *)0x0) {

    return 0;

  }

  iStack_44 = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x13c + param_1;

  uStack_40 = 0x10;

  iStack_48 = 0x5dcc77;

  (**(code **)((int)*param_2 + 0x14))();

  iVar5 = *(int *)(*(int *)(param_1 + -0x1bc) + 4);

  pfVar2 = (float *)(iVar5 + -0x13c + param_1);

  *pfVar2 = *param_2 + *(float *)(iVar5 + -0x13c + param_1);

  pfVar2[1] = param_2[1] + pfVar2[1];

  pfVar2[2] = param_2[2] + pfVar2[2];

  pfVar2[3] = param_2[3] + pfVar2[3];

  iStack_48 = 0x5dcce6;

  iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x1bc + param_1) + 0x1cc

                      ))();

  if (iVar5 != 0) {

    iVar7 = *(int *)(*(int *)(iVar5 + 4) + 4);

    iVar6 = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + param_1;

    fVar3 = *(float *)(iVar6 + -0x138);

    iStack_48 = *(uint32_t /* width from decompiler */ *)(iVar6 + -0x134);

    iStack_4c = *(uint32_t /* width from decompiler */ *)(iVar6 + -0x13c);

    uStack_50 = 0x5dcd26;

    fVar8 = (float10)FUN_004cd220();

    *(float *)(iVar7 + 0xc0 + iVar5) = (float)((float10)fVar3 - fVar8);

  }

  iStack_4c = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + -300 + param_1;

  iStack_48 = 0x10;

  uStack_50 = 0x5dcd46;

  (**(code **)((int)*param_2 + 0x14))();

  aiStack_5c[2] = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x104 + param_1;

  uStack_50 = 4;

  aiStack_5c[1] = 0x5dcd60;

  (**(code **)((int)*param_2 + 0x14))();

  aiStack_5c[1] = 0x40;

  aiStack_5c[0] = param_1 + -0xdd;

  uStack_60 = 0x5dcd70;

  (**(code **)((int)*param_2 + 0x14))();

  iStack_64 = param_1 + -0x6c;

  uStack_60 = 4;

  uStack_68 = 0x5dcd7d;

  (**(code **)((int)*param_2 + 0x14))();

  uStack_68 = 4;

  iStack_6c = param_1 + -0x68;

  iStack_70 = 0x5dcd8a;

  (**(code **)((int)*param_2 + 0x14))();

  iStack_70 = 4;

  iStack_74 = param_1 + -100;

  uStack_78 = 0x5dcd97;

  (**(code **)((int)*param_2 + 0x14))();

  uStack_78 = 1;

  iStack_7c = param_1 + -0xe4;

  uStack_80 = 0x5dcda7;

  (**(code **)((int)*param_2 + 0x14))();

  uStack_80 = 1;

  pcVar1 = (char *)(param_1 + -0xe2);

  iStack_88 = 0x5dcdb7;

  pcStack_84 = pcVar1;

  (**(code **)((int)*param_2 + 0x14))();

  iStack_88 = 1;

  aiStack_94[2] = param_1 + -0xe1;

  aiStack_94[1] = 0x5dcdc7;

  (**(code **)((int)*param_2 + 0x14))();

  iVar5 = iStack_48;

  if (0x2b < iStack_48) {

    aiStack_94[1] = 1;

    aiStack_94[0] = param_1 + -0xde;

    uStack_98 = 0x5dcde0;

    (**(code **)((int)*param_2 + 0x14))();

  }

  aiStack_94[1] = 1;

  aiStack_94[0] = param_1 + -0xe0;

  uStack_98 = 0x5dcdf0;

  (**(code **)((int)*param_2 + 0x14))();

  uStack_98 = 1;

  iVar7 = param_1 + -0xdf;

  (**(code **)((int)*param_2 + 0x14))();

  if (iVar5 < 0x3c) {

    if ((*pcVar1 == '\0') || (0.0 < *(float *)(param_1 + -0x6c))) {

      *(uint8_t *)(param_1 + -0x35) = 0;

    }

    else {

      *(uint8_t *)(param_1 + -0x35) = 1;

    }

  }

  else {

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x35,1);

  }

  if ((*pcVar1 != '\0') &&

     (*(float *)(param_1 + -0x6c) <= g_flOverheatCoolFrac &&

      g_flOverheatCoolFrac != *(float *)(param_1 + -0x6c))) {

    *(float *)(param_1 + -0x6c) = g_flOverheatCoolFrac;

  }

  iVar5 = 4;

  aiStack_5c[0] = 0;

  (**(code **)((int)*param_2 + 0x14))(aiStack_5c);

  FUN_005743e0(0,0,0);

  FUN_004e4620(iStack_64);

  aiStack_5c[0] = 0;

  if (0 < iStack_64) {

    do {

      FUN_00513880(param_2,aiStack_94 + 2);

      iVar6 = *(int *)(param_1 + -0x78);

      if ((iVar6 == 0) ||

         ((uint)(*(int *)(param_1 + -0x70) - iVar6 >> 3) <=

          (uint)(*(int *)(param_1 + -0x74) - iVar6 >> 3))) {

        FUN_00418e60(*(uint32_t /* width from decompiler */ *)(param_1 + -0x74),1,aiStack_94 + 2);

      }

      else {

        piVar4 = *(int **)(param_1 + -0x74);

        *piVar4 = aiStack_94[2];

        piVar4[1] = iStack_88;

        *(int **)(param_1 + -0x74) = piVar4 + 2;

      }

      aiStack_5c[0] = aiStack_5c[0] + 1;

    } while (aiStack_5c[0] < iStack_64);

  }

  aiStack_94[0] = 0;

  (**(code **)((int)*param_2 + 0x14))(aiStack_94,4);

  FUN_005de1b0(0,0,0,0,0);

  FUN_005de0e0(iVar7);

  iStack_64 = 0;

  if (0 < iVar7) {

    do {

      FUN_005138a0(param_2,&uStack_80);

      iVar6 = *(int *)(param_1 + -0x98);

      uStack_78 = CONCAT31(uStack_78._1_3_,

                           *(uint8_t *)

                            (*(int *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x118 + param_1) +

                            0x7d));

      if ((iVar6 == 0) ||

         ((uint)(*(int *)(param_1 + -0x90) - iVar6 >> 4) <=

          (uint)(*(int *)(param_1 + -0x94) - iVar6 >> 4))) {

        FUN_004cbfc0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x94),1,&uStack_80);

      }

      else {

        iVar6 = *(int *)(param_1 + -0x94);

        FUN_00608720(iVar6,1,&uStack_80,param_1 + -0x9c,uStack_68);

        *(int *)(param_1 + -0x94) = iVar6 + 0x10;

      }

      iStack_64 = iStack_64 + 1;

    } while (iStack_64 < iVar7);

  }

  iVar7 = 0;

  uStack_98 = 0;

  (**(code **)((int)*param_2 + 0x14))(&uStack_98,4);

  FUN_005806e0(0,0,0,0);

  FUN_00580520(iVar5);

  if (0 < iVar5) {

    do {

      (**(code **)((int)*param_2 + 0x14))(aiStack_94,0xc);

      FUN_00580980(aiStack_94);

      iVar7 = iVar7 + 1;

    } while (iVar7 < iVar5);

  }

  iVar5 = iStack_70;

  if (8 < iStack_70) {

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x30,4);

  }

  if (0x36 < iVar5) {

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x28,4);

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = 0;

  return 1;

}
