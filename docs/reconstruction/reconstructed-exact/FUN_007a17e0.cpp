// =============================================================================
// FUN_007a17e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a17e0
// Address:   0x007a17e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a17e0 @ 0x007a17e0
// Stable ID: aa_007a17e0
// Embedded strings (evidence for future rename):
//   - "gGrassPushDownPoint"
//   - "gGrassPushDownDirection"
//   - "gCameraAlphaRay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×17, do×5, while×5, return×1.
//  - Notable callees: FUN_00404d80×2, FUN_007a17e0, SQRT.
//  - Strings: "gGrassPushDownPoint"; "gGrassPushDownDirection"; "gCameraAlphaRay".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_007a17e0(float *param_1,int param_2,float param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float *pfVar11;

  int iVar12;

  int iVar13;

  float fVar14;

  uint32_t /* width from decompiler */ uStack_30;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  float fStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  puStack_18 = &LAB_009adda9;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  if ((DAT_00d20a70 & 1) == 0) {

    DAT_00d20a70 = DAT_00d20a70 | 1;

    local_14 = 0;

    ExceptionList = &pvStack_1c;

    FUN_00404d80(&DAT_00d209f0,0x10,8,FUN_005edf20);

  }

  if ((DAT_00d20a70 & 2) == 0) {

    DAT_00d20a70 = DAT_00d20a70 | 2;

    local_14 = 1;

    FUN_00404d80(&DAT_00d20988,0xc,8,FUN_005edf20);

  }

  local_14 = 0xffffffff;

  if ((DAT_00d20a70 & 4) == 0) {

    DAT_00d20a70 = DAT_00d20a70 | 4;

    DAT_00d2097c = 0.0;

    DAT_00d20980 = 0.0;

    DAT_00d20984 = 0.0;

  }

  fVar4 = DAT_00d20984;

  fVar2 = DAT_00d20980;

  fVar1 = DAT_00d2097c;

  if (DAT_00d1f201 == '\0') {

    _DAT_00d20974 = 0x1010101;

    _DAT_00d20978 = 0x1010101;

    _DAT_00d2096c = 0;

    puVar10 = &DAT_00d20990;

    puVar7 = &DAT_00d209f8;

    _DAT_00d20970 = 0;

    do {

      puVar7[-2] = 0;

      puVar7[-1] = 0;

      *puVar7 = 0;

      puVar7[1] = 0;

      puVar10[-2] = 0;

      puVar10[-1] = 0;

      *puVar10 = 0;

      puVar7 = puVar7 + 4;

      puVar10 = puVar10 + 3;

    } while ((int)puVar7 < 0xd20a78);

    DAT_00d1f201 = '\x01';

  }

  fVar6 = g_flLevelUpUiBase_Inferred;

  fVar5 = DAT_00a0f698;

  DAT_00d209f4 = param_1[1] + param_4[1];

  DAT_00d209f8 = param_1[2] + param_4[2];

  DAT_00d209f0 = *param_4 + *param_1;

  DAT_00d209fc = g_flOne;

  DAT_00d20988 = *param_1;

  DAT_00d2098c = param_1[1];

  DAT_00d20990 = param_1[2];

  pfVar11 = (float *)&DAT_00d20a0c;

  iVar8 = 0;

  iVar12 = 7;

  do {

    if ((&DAT_00d20975)[iVar8] == '\0') {

      if ((&DAT_00d2096d)[iVar8] == '\0') {

        fVar14 = *pfVar11;

        *pfVar11 = fVar14 - param_3;

        if (fVar14 - param_3 <= 0.0) {

          *pfVar11 = 0.0;

          (&DAT_00d20975)[iVar8] = 1;

        }

      }

      else {

        fVar14 = param_3 * fVar6 + *pfVar11;

        *pfVar11 = fVar14;

        if (fVar5 <= fVar14) {

          *pfVar11 = fVar5;

          (&DAT_00d2096d)[iVar8] = 0;

        }

      }

    }

    iVar8 = iVar8 + 1;

    pfVar11 = pfVar11 + 4;

    iVar12 = iVar12 + -1;

  } while (iVar12 != 0);

  if (g_flOne < (fVar4 - param_4[2]) * (fVar4 - param_4[2]) +

                (fVar2 - param_4[1]) * (fVar2 - param_4[1]) +

                (fVar1 - *param_4) * (fVar1 - *param_4)) {

    iVar8 = 1;

    do {

      if ((&DAT_00d20974)[iVar8] != '\0') {

        DAT_00d2097c = *param_4 - *param_1 * DAT_00a0f70c;

        DAT_00d20980 = param_4[1] - param_1[1] * DAT_00a0f70c;

        DAT_00d20984 = param_4[2] - param_1[2] * DAT_00a0f70c;

        (&DAT_00d209f0)[iVar8 * 4] = DAT_00d2097c;

        (&DAT_00d209f4)[iVar8 * 4] = DAT_00d20980;

        (&DAT_00d209fc)[iVar8 * 4] = 0.0;

        (&DAT_00d209f8)[iVar8 * 4] = DAT_00d20984;

        fVar1 = param_1[2];

        fVar2 = param_1[1];

        (&DAT_00d20988)[iVar8 * 3] = *param_1;

        (&DAT_00d2098c)[iVar8 * 3] = fVar2;

        (&DAT_00d20990)[iVar8 * 3] = fVar1;

        (&DAT_00d20974)[iVar8] = 0;

        (&DAT_00d2096c)[iVar8] = 1;

        break;

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < 8);

  }

  iVar8 = DAT_00d1f05c;

  if ((*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) != 0) &&

     (piVar3 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc),

     iVar12 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gGrassPushDownPoint"), iVar12 != 0)) {

    iVar13 = 0;

    puVar7 = &DAT_00d209f0;

    do {

      if (*(int *)(*(int *)(iVar8 + 4) + 0xc) == 0) {

        uVar9 = 0;

      }

      else {

        piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

        uVar9 = (**(code **)(*piVar3 + 0x2c))(piVar3,iVar12,iVar13);

      }

      if (*(int *)(iVar8 + 4) != 0) {

        piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

        (**(code **)(*piVar3 + 0x50))(piVar3,uVar9,puVar7,0xffffffff);

      }

      puVar7 = puVar7 + 4;

      iVar13 = iVar13 + 1;

    } while ((int)puVar7 < 0xd20a70);

  }

  if ((*(int *)(*(int *)(iVar8 + 4) + 0xc) != 0) &&

     (piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc),

     iVar12 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gGrassPushDownDirection"), iVar12 != 0)) {

    iVar13 = 0;

    puVar7 = &DAT_00d20988;

    do {

      if (*(int *)(*(int *)(iVar8 + 4) + 0xc) == 0) {

        uVar9 = 0;

      }

      else {

        piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

        uVar9 = (**(code **)(*piVar3 + 0x2c))(piVar3,iVar12,iVar13);

      }

      if (*(int *)(iVar8 + 4) != 0) {

        piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

        (**(code **)(*piVar3 + 0x50))(piVar3,uVar9,puVar7,0xffffffff);

      }

      puVar7 = puVar7 + 3;

      iVar13 = iVar13 + 1;

    } while ((int)puVar7 < 0xd209e8);

  }

  iVar12 = *(int *)(*(int *)(param_2 + 0x2e4) + 8);

  fVar1 = *(float *)(iVar12 + 0x90) - *param_4;

  uStack_30 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x294);

  fVar4 = *(float *)(iVar12 + 0x94) - param_4[1];

  fVar2 = *(float *)(iVar12 + 0x98) - param_4[2];

  pvStack_2c = *(void **)(param_2 + 0x298);

  uStack_28 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x29c);

  fStack_24 = SQRT(fVar1 * fVar1 + fVar4 * fVar4 + fVar2 * fVar2);

  if (*(int *)(*(int *)(iVar8 + 4) + 0xc) == 0) {

    uVar9 = 0;

  }

  else {

    piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

    uVar9 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gCameraAlphaRay");

  }

  piVar3 = *(int **)(*(int *)(iVar8 + 4) + 0xc);

  (**(code **)(*piVar3 + 0x50))(piVar3,uVar9,&uStack_30,0xffffffff);

  ExceptionList = pvStack_2c;

  return;

}
