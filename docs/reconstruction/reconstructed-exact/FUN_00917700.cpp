// =============================================================================
// FUN_00917700
// -----------------------------------------------------------------------------
// Stable ID: aa_00917700
// Address:   0x00917700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00917700 @ 0x00917700
// Stable ID: aa_00917700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~214 non-empty decompiler lines.
//  - Control keywords: if×26, goto×5, for×4, return×3, do×2, while×2.
//  - Notable callees: _CIacos×2, fcos×2, fsin×2, ABS, FUN_00404dc0, FUN_004e88e0, FUN_004e8a40, FUN_00567ce0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_00917700(void)



{

  uint uVar1;

  bool bVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char cVar7;

  int unaff_ESI;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 extraout_ST0_01;

  float10 fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float afStack_4c [2];

  float fStack_44;

  uint32_t /* width from decompiler */ local_40;

  float fStack_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t auStack_30 [20];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  puStack_18 = &LAB_009ad329;

  local_1c = ExceptionList;

  if ((*(int *)(unaff_ESI + 0xcc4) != 6) && (*(int *)(unaff_ESI + 0xcc4) != 7)) {

    return 1;

  }

  fVar14 = (float)DAT_00d1d87c;

  if (DAT_00d1d87c < 0) {

    fVar14 = fVar14 + _DAT_00aaa5dc;

  }

  ExceptionList = &local_1c;

  if ((g_flZero != fVar14) && (ExceptionList = &local_1c, *(char *)(unaff_ESI + 0x493) == '\0')) {

    ExceptionList = &local_1c;

    *(float *)(unaff_ESI + 0x538) =

         *(float *)(unaff_ESI + 0x538) - (float)DAT_00d1d87c * _DAT_00d1b2d8;

  }

  if (*(float *)(unaff_ESI + 0x53c) == 0.0) {

    if (*(char *)(unaff_ESI + 0x493) == '\0') {

      if (DAT_00d1b20b == '\0') {

        *(float *)(unaff_ESI + 0x53c) =

             *(float *)(unaff_ESI + 0x53c) - (float)DAT_00d1d880 * _DAT_00d1b2d8;

      }

      else {

        *(float *)(unaff_ESI + 0x53c) =

             (float)DAT_00d1d880 * _DAT_00d1b2d8 + *(float *)(unaff_ESI + 0x53c);

      }

      goto LAB_009177de;

    }

  }

  else {

LAB_009177de:

    if (*(char *)(unaff_ESI + 0x493) == '\0') {

      *(uint8_t *)(unaff_ESI + 0xa85) = 0;

    }

  }

  *(int *)(unaff_ESI + 0xa4c) = *(int *)(unaff_ESI + 0xa4c) - (int)*(float *)(unaff_ESI + 0x53c);

  iVar4 = DAT_00afe294;

  if (DAT_00afe294 < *(int *)(unaff_ESI + 0xa4c)) {

    *(int *)(unaff_ESI + 0xa4c) = DAT_00afe294;

  }

  iVar5 = -iVar4;

  if (*(int *)(unaff_ESI + 0xa4c) < iVar5) {

    *(int *)(unaff_ESI + 0xa4c) = iVar5;

  }

  uVar1 = DAT_00d206c0 & 1;

  fVar14 = (float)iVar4;

  *(float *)(unaff_ESI + 0xcc8) =

       ((float)*(int *)(unaff_ESI + 0xa4c) / fVar14) * _DAT_00afe298 + _DAT_00d1f0b0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x53c) = 0;

  if (uVar1 == 0) {

    DAT_00d206c0 = DAT_00d206c0 | 1;

    DAT_00d206bc = *(float *)(unaff_ESI + 0x538);

  }

  local_14 = 0xffffffff;

  cVar7 = *(char *)(unaff_ESI + 0x493);

  if ((((cVar7 != '\0') && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) && (DAT_00d1b212 != '\0')) &&

     (((*(float *)(unaff_ESI + 0x538) <= 0.0 && *(float *)(unaff_ESI + 0x538) != 0.0 &&

       (0.0 < DAT_00d206bc)) || ((0.0 < *(float *)(unaff_ESI + 0x538) && (DAT_00d206bc < 0.0)))))) {

    *(uint8_t *)(unaff_ESI + 0xa85) = 1;

  }

  DAT_00d206bc = *(float *)(unaff_ESI + 0x538);

  fVar14 = fVar14 * DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538) = 0;

  fVar14 = DAT_00d206bc / fVar14;

  if (((DAT_00d1b6d8 == 0) || (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) || (DAT_00d1b212 == '\0')) {

    fVar14 = *(float *)(unaff_ESI + 0xa48) + fVar14;

    *(uint8_t *)(unaff_ESI + 0xa85) = 0;

    fVar8 = (float10)fsin((float10)fVar14);

    *(float *)(unaff_ESI + 0xa48) = fVar14;

    *(float *)(unaff_ESI + 0x5ac) = (float)fVar8;

    fVar8 = (float10)fcos((float10)fVar14);

    *(float *)(unaff_ESI + 0x5b4) = (float)-fVar8;

    goto LAB_00917b70;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)

           (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                       0x1a4))();

  local_40 = *puVar6;

  fStack_3c = (float)puVar6[1];

  local_38 = puVar6[2];

  local_34 = puVar6[3];

  FUN_004e8a40(&local_40,auStack_30);

  FUN_004e88e0(afStack_4c,auStack_30);

  fVar12 = 0.0 - fStack_44;

  fVar9 = 0.0 - afStack_4c[0];

  if (0.0 <= fVar12) {

    if (fVar9 <= 0.0) {

      _CIacos();

      fVar8 = -extraout_ST0_01;

    }

    else {

      _CIacos();

      fVar8 = extraout_ST0_00;

    }

  }

  else {

    _CIasin();

    fVar8 = extraout_ST0;

  }

  fVar3 = DAT_00aaa7dc;

  fVar11 = (float)fVar8;

  for (fVar13 = *(float *)(unaff_ESI + 0xa48) + fVar14; fVar13 < 0.0; fVar13 = fVar13 + DAT_00aaa7dc

      ) {

  }

  if (*(float *)(unaff_ESI + 0xa48) <= 0.0 && *(float *)(unaff_ESI + 0xa48) != 0.0) {

    fVar10 = *(float *)(unaff_ESI + 0xa48);

    do {

      fVar10 = fVar10 + DAT_00aaa7dc;

    } while (fVar10 < 0.0);

    *(float *)(unaff_ESI + 0xa48) = fVar10;

  }

  for (; fVar11 < 0.0; fVar11 = fVar11 + fVar3) {

  }

  for (; fVar3 <= fVar13; fVar13 = fVar13 - fVar3) {

  }

  fVar10 = *(float *)(unaff_ESI + 0xa48);

  if (fVar3 <= fVar10) {

    do {

      fVar10 = fVar10 - fVar3;

    } while (fVar3 <= fVar10);

    *(float *)(unaff_ESI + 0xa48) = fVar10;

  }

  for (; fVar3 <= fVar11; fVar11 = fVar11 - fVar3) {

  }

  fVar14 = *(float *)(unaff_ESI + 0xa48) + fVar14;

  if ((fVar14 < 0.0) || (_DAT_00aaa9a8 <= (double)fVar14)) {

    bVar2 = true;

  }

  else {

    bVar2 = false;

  }

  cVar7 = *(char *)(unaff_ESI + 0x493);

  if (cVar7 == '\0') {

LAB_00917af0:

    *(float *)(unaff_ESI + 0xa48) = fVar13;

  }

  else {

    if (bVar2) {

      if (((fVar11 < *(float *)(unaff_ESI + 0xa48) || fVar11 == *(float *)(unaff_ESI + 0xa48)) ||

          (fVar11 <= fVar13)) && ((*(float *)(unaff_ESI + 0xa48) <= fVar11 || (fVar13 <= fVar11))))

      goto LAB_00917af0;

    }

    else if (((fVar11 < *(float *)(unaff_ESI + 0xa48) || fVar11 == *(float *)(unaff_ESI + 0xa48)) ||

             (fVar13 <= fVar11)) &&

            ((*(float *)(unaff_ESI + 0xa48) <= fVar11 || (fVar11 <= fVar13)))) goto LAB_00917af0;

    *(float *)(unaff_ESI + 0xa48) = fVar11;

  }

  if (*(char *)(unaff_ESI + 0xa85) == '\0') {

    fVar8 = (float10)fsin((float10)*(float *)(unaff_ESI + 0xa48));

    *(float *)(unaff_ESI + 0x5ac) = (float)fVar8;

    fVar8 = (float10)fcos((float10)*(float *)(unaff_ESI + 0xa48));

    *(float *)(unaff_ESI + 0x5b4) = (float)-fVar8;

    if (g_flMsToSeconds_Inferred <=

        ABS(*(float *)(unaff_ESI + 0x5b4) + *(float *)(unaff_ESI + 0x5ac) + fStack_44 +

            afStack_4c[0])) goto LAB_00917b70;

  }

  *(float *)(unaff_ESI + 0x5ac) = fVar9;

  *(float *)(unaff_ESI + 0x5b4) = fVar12;

  *(float *)(unaff_ESI + 0xa48) = fVar11;

  *(uint8_t *)(unaff_ESI + 0xa85) = 1;

LAB_00917b70:

  if (((cVar7 == '\0') && (*(char *)(unaff_ESI + 0x494) != '\0')) &&

     (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf5) !=

      '\0')) {

    local_40 = 0;

    local_38 = 0;

    local_34 = 0;

    fStack_3c = g_flOne;

    FUN_00567ce0(&local_40,0.0 - *(float *)(unaff_ESI + 0xa48));

    if (*(int *)(DAT_00d1b6d8 + 8) == 0) {

      ExceptionList = local_1c;

      return 0;

    }

    FUN_00404dc0(auStack_30);

  }

  if (*(char *)(unaff_ESI + 0x493) == '\0') {

    DAT_00d1d86c = DAT_00d1d9d8 / 2;

    DAT_00d1d870 = DAT_00d1d9dc / 2;

    DAT_00d1d87c = 0;

    DAT_00d1d880 = 0;

  }

  ExceptionList = local_1c;

  return 1;

}
