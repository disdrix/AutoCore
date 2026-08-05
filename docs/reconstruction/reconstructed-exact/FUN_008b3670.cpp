// =============================================================================
// FUN_008b3670
// -----------------------------------------------------------------------------
// Stable ID: aa_008b3670
// Address:   0x008b3670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b3670 @ 0x008b3670
// Stable ID: aa_008b3670
// Embedded strings (evidence for future rename):
//   - "<%s %d>"
//   - "%s.dds"
//   - "%s: 0/0"
//   - "%s: %d/%d"
//   - "X %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~432 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, do×1, while×1.
//  - Notable callees: sprintf×5, FUN_007a6de0×3, CVOGReaction_ResolveObjectTarget×2, FUN_00402d50×2, FUN_00599dd0×2, free×2, CONCAT13, FUN_0040f4e0.
//  - Strings: "<%s %d>"; "%s.dds"; "%s: 0/0"; "%s: %d/%d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008b3670(void)



{

  char cVar1;

  byte bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  int *piVar6;

  int unaff_EBX;

  uint uVar7;

  uint uVar8;

  uint8_t *puVar9;

  float fStack_96c;

  uint8_t *puStack_968;

  uint8_t *puStack_964;

  uint8_t *puStack_960;

  float fStack_95c;

  uint32_t /* width from decompiler */ uStack_958;

  uint8_t *puStack_954;

  uint8_t *puStack_950;

  uint8_t *puStack_94c;

  float fStack_948;

  uint32_t /* width from decompiler */ uStack_944;

  uint8_t *puStack_940;

  float *pfStack_93c;

  uint8_t *puStack_938;

  uint32_t /* width from decompiler */ uStack_934;

  uint32_t /* width from decompiler */ uStack_930;

  uint8_t *puStack_92c;

  uint32_t /* width from decompiler */ *puStack_928;

  uint8_t *puStack_924;

  uint32_t /* width from decompiler */ uStack_920;

  uint32_t /* width from decompiler */ uStack_91c;

  uint8_t *puStack_918;

  uint32_t /* width from decompiler */ *puStack_914;

  uint8_t *puStack_910;

  uint32_t /* width from decompiler */ uStack_90c;

  uint32_t /* width from decompiler */ uStack_908;

  uint8_t *puStack_904;

  uint32_t /* width from decompiler */ *puStack_900;

  float fVar10;

  float fVar11;

  float fVar12;

  uint32_t /* width from decompiler */ uStack_8d0;

  int local_8c0;

  float fStack_8a8;

  int iStack_8a4;

  float fStack_89c;

  float fStack_898;

  uint32_t /* width from decompiler */ uStack_890;

  float fStack_88c;

  uint8_t auStack_884 [12];

  uint32_t /* width from decompiler */ uStack_878;

  int iStack_874;

  uint32_t /* width from decompiler */ uStack_86c;

  int iStack_868;

  uint8_t auStack_860 [4];

  uint32_t /* width from decompiler */ uStack_85c;

  int iStack_858;

  uint8_t auStack_840 [28];

  uint uStack_824;

  uint8_t auStack_820 [4];

  uint8_t auStack_81c [4];

  uint8_t auStack_818 [4];

  uint8_t auStack_814 [4];

  uint8_t auStack_810 [4];

  uint8_t auStack_80c [4];

  uint8_t auStack_808 [8];

  uint8_t auStack_800 [12];

  uint8_t auStack_7f4 [16];

  uint8_t auStack_7e4 [48];

  uint8_t auStack_7b4 [44];

  uint8_t auStack_788 [56];

  uint8_t *puStack_750;

  uint8_t auStack_74c [128];

  uint8_t *puStack_6cc;

  uint8_t auStack_6c8 [128];

  char acStack_648 [108];

  char acStack_5dc [148];

  char acStack_548 [299];

  uint8_t uStack_41d;

  uint8_t uStack_31f;

  char acStack_318 [772];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b2acf;

  pvStack_14 = ExceptionList;

  if (DAT_00d1b6d8 == 0) {

    local_8c0 = 8;

    ExceptionList = &pvStack_14;

  }

  else {

    ExceptionList = &pvStack_14;

    local_8c0 = FUN_00522000();

  }

  FUN_007a69d0();

  uStack_8d0 = (float)(uint)(uint3)uStack_8d0;

  do {

    uVar8 = (uint)uStack_8d0._3_1_;

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x124))();

    fVar12 = 0.0;

    fVar11 = 1.4013e-45;

    fStack_88c = (float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + uStack_8d0) * DAT_00aaa678;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x120))();

    uStack_878 = *puVar4;

    iStack_874 = (int)fStack_898;

    (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x110))();

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x124))();

    fVar10 = 1.4013e-45;

    puVar9 = auStack_808;

    fStack_89c = (float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar11) * DAT_00aaa678;

    puStack_900 = (uint32_t /* width from decompiler */ *)0x8b37b1;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x120))();

    uStack_85c = *puVar4;

    iStack_858 = (int)fStack_8a8;

    puStack_900 = &uStack_85c;

    puStack_904 = (uint8_t *)0x8b37de;

    (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x110))();

    puStack_904 = auStack_788;

    uStack_908 = 0x8b37f5;

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x124))();

    uStack_908 = 0;

    uStack_90c = 1;

    puStack_910 = auStack_80c;

    fVar10 = (float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar10) * DAT_00aaa678;

    puStack_914 = (uint32_t /* width from decompiler */ *)0x8b3835;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x120))();

    uStack_890 = *puVar4;

    fStack_88c = (float)(int)fVar12;

    puStack_914 = &uStack_890;

    puStack_918 = (uint8_t *)0x8b3862;

    (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x110))();

    puStack_918 = auStack_7b4;

    uStack_91c = 0x8b3879;

    (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0x124))();

    uStack_91c = 0;

    uStack_920 = 1;

    puStack_924 = auStack_810;

    puStack_928 = (uint32_t /* width from decompiler */ *)0x8b38b9;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0x120))();

    uStack_86c = *puVar4;

    iStack_868 = (int)(float)puVar9;

    puStack_928 = &uStack_86c;

    puStack_92c = (uint8_t *)0x8b38e6;

    (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0x110))();

    puStack_92c = auStack_860;

    uStack_930 = 0x8b38fd;

    (**(code **)(**(int **)(unaff_EBX + 0x5ec + uVar8 * 4) + 0x124))();

    uStack_930 = 0;

    uStack_934 = 1;

    puStack_938 = auStack_814;

    pfStack_93c = (float *)0x8b393d;

    pfVar5 = (float *)(**(code **)(**(int **)(unaff_EBX + 0x5ec + uVar8 * 4) + 0x120))();

    fStack_8a8 = *pfVar5;

    iStack_8a4 = (int)(float)puStack_900;

    pfStack_93c = &fStack_8a8;

    puStack_940 = (uint8_t *)0x8b396a;

    (**(code **)(**(int **)(unaff_EBX + 0x5ec + uVar8 * 4) + 0x110))();

    puStack_940 = auStack_7e4;

    uStack_944 = 0x8b3981;

    (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x124))();

    uStack_944 = 0;

    fStack_948 = 1.4013e-45;

    puStack_94c = auStack_818;

    puStack_950 = (uint8_t *)0x8b39c1;

    (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x120))();

    puStack_950 = &stack0xfffff714;

    puStack_954 = (uint8_t *)0x8b39e5;

    (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x110))();

    puStack_954 = auStack_800;

    uStack_958 = 0x8b39fc;

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x5ac + uVar8 * 4) + 0x124))();

    uStack_958 = 0;

    fStack_95c = 1.4013e-45;

    puStack_960 = auStack_81c;

    puStack_914 = (uint32_t /* width from decompiler */ *)

                  ((float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fStack_948) * DAT_00aaa678);

    puStack_964 = (uint8_t *)0x8b3a3c;

    (**(code **)(**(int **)(unaff_EBX + 0x5ac + uVar8 * 4) + 0x120))();

    puStack_964 = &stack0xfffff708;

    puStack_968 = (uint8_t *)0x8b3a60;

    (**(code **)(**(int **)(unaff_EBX + 0x5ac + uVar8 * 4) + 0x110))();

    puStack_968 = auStack_7f4;

    fStack_96c = 1.2786107e-38;

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 0x124))();

    fStack_96c = 0.0;

    fVar12 = 1.4013e-45;

    pfStack_93c = (float *)((float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fStack_95c) *

                           DAT_00aaa678);

    (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 0x120))(auStack_820,1);

    puVar9 = &stack0xfffff704;

    (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 0x110))(puVar9);

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0x124))(&fStack_8a8);

    fVar11 = 1.4013e-45;

    fStack_948 = (float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar12) * DAT_00aaa678;

    puStack_900 = (uint32_t /* width from decompiler */ *)

                  (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0x120))(&fStack_89c,1,0);

    puStack_900 = (uint32_t /* width from decompiler */ *)*puStack_900;

    (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0x110))(&puStack_900);

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0x124))(&fStack_89c);

    fVar12 = 1.4013e-45;

    puStack_954 = (uint8_t *)

                  ((float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar11) * DAT_00aaa678);

    puVar4 = (uint32_t /* width from decompiler */ *)

             (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0x120))(&uStack_890,1,0);

    puStack_904 = (uint8_t *)*puVar4;

    puStack_900 = (uint32_t /* width from decompiler */ *)(int)(float)puStack_960;

    (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0x110))(&puStack_904);

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 0x124))(&uStack_890);

    fVar11 = 1.4013e-45;

    puStack_960 = (uint8_t *)

                  ((float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar12) * DAT_00aaa678);

    puVar4 = (uint32_t /* width from decompiler */ *)

             (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 0x120))(auStack_884,1,0);

    uStack_908 = *puVar4;

    puStack_904 = (uint8_t *)(int)fStack_96c;

    (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 0x110))(&uStack_908);

    iVar3 = (**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 0x124))(auStack_884);

    fStack_96c = (float)DAT_00d1e81c * (*(float *)(iVar3 + 4) + fVar11) * DAT_00aaa678;

    pfVar5 = (float *)(**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 0x120))

                                (&uStack_878,1,0);

    fStack_96c = *pfVar5;

    puStack_968 = (uint8_t *)(int)(float)puVar9;

    (**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 0x110))(&fStack_96c);

    if (DAT_00d1b6d8 == 0) {

      uVar7 = 0xffffffff;

      uStack_824 = 0xffffffff;

    }

    else {

      uVar7 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + uVar8 * 8);

      uStack_824 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + uVar8 * 8);

    }

    iVar3 = 0;

    if (DAT_00d1b6d8 != 0) {

      iVar3 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8);

      if ((iVar3 == 0) || (*(int *)(iVar3 + 0xe4e8) == 0)) {

        iVar3 = 0;

      }

      else {

        iVar3 = CVOGReaction_ResolveObjectTarget();

      }

    }

    if ((((((uVar7 & uStack_824) == 0xffffffff) || ((int)uVar8 < *(int *)(unaff_EBX + 0x6ac))) ||

         (*(int *)(unaff_EBX + 0x6ac) + 5 <= (int)uVar8)) ||

        ((local_8c0 <= (int)uVar8 || (iVar3 == 0)))) ||

       ((*(int *)(*(int *)(iVar3 + 0xa8) + 0x3c) == 0 || (iVar3 = FUN_00599dd0(), iVar3 == 0)))) {

      if (((int)uVar8 < *(int *)(unaff_EBX + 0x6ac)) ||

         (*(int *)(unaff_EBX + 0x6ac) + 5 <= (int)uVar8)) {

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 4))();

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 4))();

      }

      else {

        piVar6 = *(int **)(unaff_EBX + 0x56c + uVar8 * 4);

        iVar3 = *piVar6;

        (**(code **)(*piVar6 + 0x164))();

        (**(code **)(iVar3 + 0x154))();

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0xcc))();

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x34c))();

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0xcc))();

        if ((int)fVar10 <= (int)uVar8) {

          FUN_007a6de0();

          puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4361;

          sprintf(acStack_5dc,"<%s %d>");

        }

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x1d8))();

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x34c))();

      }

      puStack_900 = (uint32_t /* width from decompiler */ *)0x8b43c5;

      (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 4))();

      puStack_900 = (uint32_t /* width from decompiler */ *)0x0;

      puStack_904 = (uint8_t *)0x8b43d3;

      (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 4))();

      puStack_904 = (uint8_t *)0x0;

      uStack_908 = 0x8b43e1;

      (**(code **)(**(int **)(unaff_EBX + 0x5ec + uVar8 * 4) + 4))();

      uStack_908 = 0;

      uStack_90c = 0x8b43ef;

      (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 4))();

      uStack_90c = 0;

      puStack_910 = (uint8_t *)0x8b43fd;

      (**(code **)(**(int **)(unaff_EBX + 0x5ac + uVar8 * 4) + 4))();

      puStack_910 = (uint8_t *)0x0;

      puStack_914 = (uint32_t /* width from decompiler */ *)0x8b440b;

      (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 4))();

      puStack_914 = (uint32_t /* width from decompiler */ *)0x0;

      puStack_918 = (uint8_t *)0x8b4419;

      (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 4))();

      puStack_918 = (uint8_t *)0x0;

      uStack_91c = 0x8b4427;

      (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 4))();

      uStack_91c = 0;

      uStack_920 = 0x8b4435;

      (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 4))();

      uStack_920 = 0;

      puStack_924 = (uint8_t *)0x8b4445;

      (**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 4))();

    }

    else {

      piVar6 = (int *)CVOGReaction_ResolveObjectTarget();

      if ((piVar6 != (int *)0x0) &&

         ((*(int *)(piVar6[0x2a] + 0x3c) == 0 || (iVar3 = FUN_00599dd0(), iVar3 != 0)))) {

        (**(code **)(*piVar6 + 0x1c4))();

        sprintf(acStack_318,"%s.dds");

        (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x50))();

        (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x2c4))();

        (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0xcc))();

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0xcc))();

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x15c))();

        iVar3 = **(int **)(unaff_EBX + 0x58c + uVar8 * 4);

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b3e8e;

        puStack_900 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar6 + 0x15c))();

        puStack_904 = (uint8_t *)0x8b3ea0;

        (**(code **)(iVar3 + 0x1d8))();

        iVar3 = **(int **)(unaff_EBX + 0x58c + uVar8 * 4);

        puStack_904 = auStack_840;

        uStack_908 = 0x8b3eba;

        puStack_904 = (uint8_t *)FUN_00514050();

        uStack_908 = 1;

        uStack_90c = 0x8b3eca;

        (**(code **)(iVar3 + 0x15c))();

        uStack_90c = 1;

        puStack_910 = (uint8_t *)0x8b3edb;

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0xcc))();

        puStack_910 = (uint8_t *)0x1;

        puStack_914 = (uint32_t /* width from decompiler */ *)0x8b3eec;

        (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0xcc))();

        puStack_914 = (uint32_t /* width from decompiler */ *)0x1;

        puStack_918 = (uint8_t *)0x8b3efd;

        (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0xd4))();

        puStack_918 = (uint8_t *)0x1;

        uStack_91c = 0x8b3f0e;

        (**(code **)(**(int **)(unaff_EBX + 0x5ec + uVar8 * 4) + 0xcc))();

        uStack_91c = 1;

        uStack_920 = 0x8b3f1f;

        (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0xcc))();

        uStack_920 = 1;

        puStack_924 = (uint8_t *)0x8b3f2d;

        (**(code **)(**(int **)(unaff_EBX + 0x5ac + uVar8 * 4) + 4))();

        puStack_924 = (uint8_t *)0x1;

        puStack_928 = (uint32_t /* width from decompiler */ *)0x8b3f3b;

        (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 4))();

        puStack_928 = (uint32_t /* width from decompiler */ *)0x1;

        puStack_92c = (uint8_t *)0x8b3f4c;

        (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0xcc))();

        puStack_92c = (uint8_t *)0x1;

        uStack_930 = 0x8b3f5d;

        (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0xcc))();

        uStack_930 = 1;

        uStack_934 = 0x8b3f6e;

        (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 0xcc))();

        uStack_934 = 1;

        puStack_938 = (uint8_t *)0x8b3f7f;

        (**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 0xcc))();

        cVar1 = FUN_0052b040();

        if (cVar1 == '\0') {

          ExceptionList = pvStack_14;

          return;

        }

        iVar3 = FUN_0052ad60();

        FUN_0052ada0();

        uStack_41d = 0;

        uStack_31f = 0;

        if (iVar3 < 1) {

          FUN_00402d50();

          uStack_c = 1;

          FUN_007a6de0();

          sprintf(acStack_548,"%s: 0/0");

          uStack_c = 0xffffffff;

          if (puStack_750 != auStack_74c) {

            free(puStack_750);

          }

        }

        else {

          FUN_00402d50();

          uStack_c = 0;

          FUN_007a6de0();

          sprintf(acStack_548,"%s: %d/%d");

          uStack_c = 0xffffffff;

          if (puStack_6cc != auStack_6c8) {

            free(puStack_6cc);

          }

        }

        if (*(int *)(unaff_EBX + 0x60c + uVar8 * 4) != 0) {

          (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x1d8))();

          iVar3 = FUN_0040f4e0();

          if (iVar3 < 1) {

            (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x1d8))();

          }

          else {

            FUN_00977a30();

          }

          (**(code **)(**(int **)(unaff_EBX + 0x60c + uVar8 * 4) + 0x34c))();

        }

        if (*(int *)(unaff_EBX + 0x5cc + uVar8 * 4) != 0) {

          sprintf(acStack_648,"X %d");

          (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 0x1d8))();

          (**(code **)(**(int **)(unaff_EBX + 0x5cc + uVar8 * 4) + 0x34c))();

        }

        (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 300))();

        (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0x1d8))();

        iVar3 = **(int **)(unaff_EBX + 0x62c + uVar8 * 4);

        FUN_008e4430();

        (**(code **)(iVar3 + 0x15c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4244;

        (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0x1d8))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4253;

        (**(code **)(**(int **)(unaff_EBX + 0x62c + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4262;

        (**(code **)(**(int **)(unaff_EBX + 0x66c + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4271;

        (**(code **)(**(int **)(unaff_EBX + 0x64c + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b4280;

        (**(code **)(**(int **)(unaff_EBX + 0x6b8 + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b428f;

        (**(code **)(**(int **)(unaff_EBX + 0x56c + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b429e;

        (**(code **)(**(int **)(unaff_EBX + 0x58c + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b42ad;

        (**(code **)(**(int **)(unaff_EBX + 0x6d8 + uVar8 * 4) + 0x34c))();

        puStack_900 = (uint32_t /* width from decompiler */ *)0x8b42be;

        (**(code **)(**(int **)(unaff_EBX + 0x68c + uVar8 * 4) + 0x34c))();

      }

    }

    bVar2 = uStack_8d0._3_1_ + 1;

    uStack_8d0 = (float)CONCAT13(bVar2,(uint3)uStack_8d0);

  } while (bVar2 < 8);

  ExceptionList = pvStack_14;

  return;

}
