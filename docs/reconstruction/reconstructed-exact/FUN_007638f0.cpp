// =============================================================================
// FUN_007638f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007638f0
// Address:   0x007638f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007638f0 @ 0x007638f0
// Stable ID: aa_007638f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~304 non-empty decompiler lines.
//  - Control keywords: if×24, while×6, for×4, do×3, return×1.
//  - Notable callees: FUN_00767160×10, FUN_00439920×2, CONCAT31, FUN_00436f80, FUN_00439050, FUN_00439770, FUN_0046f100, FUN_0073ee70.
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

void __thiscall FUN_007638f0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  char *pcVar7;

  uint uVar8;

  undefined *puVar9;

  void *pvVar10;

  int *piVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int unaff_EDI;

  int *piVar14;

  int iVar15;

  bool bVar16;

  int **ppiVar17;

  void **ppvVar18;

  uint32_t /* width from decompiler */ *puVar19;

  int *piStack_44;

  uint8_t auStack_2c [8];

  int *apiStack_24 [2];

  uint32_t /* width from decompiler */ *local_1c;

  int local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar4 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0a6c;

  pvStack_c = ExceptionList;

  piStack_44 = (int *)0x3;

  local_1c = param_2;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x47424f44);

  local_4 = 0;

  piStack_44 = (int *)0x763933;

  local_14 = (int *)FUN_00439770();

  *(char *)((int)local_14 + 0x15) = '\x01';

  local_14[1] = (int)local_14;

  *local_14 = (int)local_14;

  local_14[2] = (int)local_14;

  local_10 = 0;

  piStack_44 = &local_18;

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00763620(param_1);

  uVar5 = local_10;

  piVar12 = local_14;

  param_2 = (int *)*local_14;

  piVar14 = (int *)0x4;

  while (param_2 != piVar12) {

    pcVar7 = (char *)param_2[3];

    if ((char *)param_2[3] == (char *)0x0) {

      pcVar7 = PTR_DAT_00afa2bc;

    }

    pcVar1 = pcVar7 + 1;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    piVar14 = (int *)(pcVar7 + (int)((int)piVar14 + (1 - (int)pcVar1)));

    piStack_44 = (int *)0x7639a8;

    FUN_0046f100();

  }

  if (puVar4[7] == 0) {

    piStack_44 = (int *)0x4;

    puVar13 = &param_2;

    param_2 = piVar14;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))();

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    piStack_44 = piVar14;

    uVar8 = FUN_00767160(&DAT_00a37c64);

    puVar4[1] = puVar4[1] | uVar8;

    piStack_44 = (int *)0x2;

    puVar13 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))();

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  if (puVar4[7] == 0) {

    piVar14 = (int *)0x4;

    puVar19 = &local_4;

    local_4 = uVar5;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))();

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a37c64,uVar5);

    puVar4[1] = puVar4[1] | uVar8;

    piVar14 = (int *)0x2;

    puVar19 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))();

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  piVar12 = (int *)*apiStack_24[0];

  if (piVar12 != apiStack_24[0]) {

    do {

      puVar9 = (undefined *)piVar12[3];

      if ((undefined *)piVar12[3] == (undefined *)0x0) {

        puVar9 = PTR_DAT_00afa2bc;

      }

      if (puVar4[7] == 0) {

        uVar8 = FUN_00436f80(puVar4,puVar9);

        puVar4[1] = puVar4[1] | uVar8;

      }

      else {

        uVar8 = FUN_00767160(&DAT_00a9d6f8,puVar9);

        puVar4[1] = puVar4[1] | uVar8;

        uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

        puVar4[8] = 0;

        puVar4[1] = uVar8 | puVar4[1];

      }

      if (*(char *)((int)piVar12 + 0x15) == '\0') {

        piVar11 = (int *)piVar12[2];

        if (*(char *)((int)piVar11 + 0x15) == '\0') {

          cVar2 = *(char *)(*piVar11 + 0x15);

          piVar12 = piVar11;

          piVar11 = (int *)*piVar11;

          while (cVar2 == '\0') {

            cVar2 = *(char *)(*piVar11 + 0x15);

            piVar12 = piVar11;

            piVar11 = (int *)*piVar11;

          }

        }

        else {

          cVar2 = *(char *)(piVar12[1] + 0x15);

          piVar6 = (int *)piVar12[1];

          piVar11 = piVar12;

          while ((piVar12 = piVar6, cVar2 == '\0' && (piVar11 == (int *)piVar12[2]))) {

            cVar2 = *(char *)(piVar12[1] + 0x15);

            piVar6 = (int *)piVar12[1];

            piVar11 = piVar12;

          }

        }

      }

    } while (piVar12 != apiStack_24[0]);

  }

  FUN_0074bda0();

  if (*(int *)(unaff_EDI + 100) != 0) {

    FUN_00989520();

  }

  pvVar10 = (void *)0x0;

  if (*(int *)(unaff_EDI + 0x80) != 0) {

    pvVar10 = (void *)((*(int *)(unaff_EDI + 0x84) - *(int *)(unaff_EDI + 0x80)) / 0x14);

  }

  if (puVar4[7] == 0) {

    ppvVar18 = &pvStack_c;

    pvStack_c = pvVar10;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(ppvVar18,4);

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a9d718,pvVar10);

    puVar4[1] = puVar4[1] | uVar8;

    ppvVar18 = (void **)&DAT_00a97b84;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  local_14 = *(int **)(unaff_EDI + 0x80);

  piVar12 = *(int **)(unaff_EDI + 0x84);

  if (local_14 != piVar12) {

    piStack_44 = local_14 + 2;

    do {

      if (puVar4[7] == 0) {

        uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&stack0xffffffc0,4);

        puVar4[1] = puVar4[1] | uVar8;

      }

      else {

        uVar8 = FUN_00767160(&DAT_00a37c64,*local_14);

        puVar4[1] = puVar4[1] | uVar8;

        uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

        puVar4[8] = 0;

        puVar4[1] = uVar8 | puVar4[1];

      }

      if (*piVar14 == 0) {

        piVar11 = (int *)0x0;

      }

      else {

        piVar11 = (int *)((piVar14[1] - *piVar14) / 0x38);

      }

      if (puVar4[7] == 0) {

        piStack_44 = piVar11;

        uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&piStack_44,4);

        puVar4[1] = puVar4[1] | uVar8;

      }

      else {

        uVar8 = FUN_00767160(&DAT_00a9d718,piVar11);

        puVar4[1] = puVar4[1] | uVar8;

        uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

        puVar4[8] = 0;

        puVar4[1] = uVar8 | puVar4[1];

      }

      iVar3 = piStack_44[1];

      for (iVar15 = *piStack_44; iVar15 != iVar3; iVar15 = iVar15 + 0x38) {

        FUN_00439920();

        FUN_00439920();

      }

      piStack_44 = piStack_44 + 5;

      local_14 = local_14 + 5;

    } while (local_14 != piVar12);

  }

  FUN_0096b060();

  if (puVar13[0x4b] == 0) {

    piVar12 = (int *)0x0;

  }

  else {

    piVar12 = (int *)((int)(puVar13[0x4c] - puVar13[0x4b]) >> 3);

  }

  if (puVar4[7] == 0) {

    ppiVar17 = &local_14;

    local_14 = piVar12;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(ppiVar17,4);

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a9d718,piVar12);

    puVar4[1] = puVar4[1] | uVar8;

    ppiVar17 = (int **)&DAT_00a97b84;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  iVar3 = puVar19[0x4c];

  puVar13 = puVar19;

  for (iVar15 = puVar19[0x4b]; iVar15 != iVar3; iVar15 = iVar15 + 8) {

    if (*(int *)(iVar15 + 4) != 0) {

      puVar19 = puVar13;

      FUN_0073ee70();

      puVar13 = puVar19;

    }

  }

  if (puVar19[0x30] == 0) {

    puVar13 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar13 = (uint32_t /* width from decompiler */ *)((int)(puVar19[0x31] - puVar19[0x30]) >> 2);

  }

  if (puVar4[7] == 0) {

    local_1c = puVar13;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&local_1c,4);

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a9d718,puVar13);

    puVar4[1] = puVar4[1] | uVar8;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  puVar19 = ppvVar18[0x31];

  for (puVar13 = ppvVar18[0x30]; puVar13 != puVar19; puVar13 = puVar13 + 1) {

    (**(code **)(*(int *)*puVar13 + 0x38))(puVar4);

  }

  if (ppvVar18[0x34] == (void *)0x0) {

    piVar12 = (int *)0x0;

  }

  else {

    piVar12 = (int *)((int)ppvVar18[0x35] - (int)ppvVar18[0x34] >> 2);

  }

  if (puVar4[7] == 0) {

    apiStack_24[0] = piVar12;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(apiStack_24,4);

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a9d718,piVar12);

    puVar4[1] = puVar4[1] | uVar8;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  piVar11 = ppiVar17[0x35];

  for (piVar12 = ppiVar17[0x34]; piVar12 != piVar11; piVar12 = piVar12 + 1) {

    (**(code **)(*(int *)*piVar12 + 0x38))(puVar4);

  }

  bVar16 = ppiVar17[0x25] != (int *)0x0;

  if (puVar4[7] == 0) {

    auStack_2c[0] = bVar16;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(auStack_2c,1);

    puVar4[1] = puVar4[1] | uVar8;

  }

  else {

    uVar8 = FUN_00767160(&DAT_00a9d718,bVar16);

    puVar4[1] = puVar4[1] | uVar8;

    uVar8 = (**(code **)(*(int *)*puVar4 + 0x18))(&DAT_00a97b84,2);

    puVar4[8] = 0;

    puVar4[1] = uVar8 | puVar4[1];

  }

  if (bVar16) {

    (**(code **)(*ppiVar17[0x25] + 0x20))(puVar4);

  }

  FUN_00439050(&stack0xffffffcc,*piVar14,piVar14);

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar14);

}
