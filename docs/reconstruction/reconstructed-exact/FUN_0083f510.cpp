// =============================================================================
// FUN_0083f510
// -----------------------------------------------------------------------------
// Stable ID: aa_0083f510
// Address:   0x0083f510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083f510 @ 0x0083f510
// Stable ID: aa_0083f510
// Embedded strings (evidence for future rename):
//   - "%s [%d]"
//   - "i_d_s_2d_wnd_icon_default.dds"
//   - "  %s %d."
//   - "Hold (SHIFT) to see next rank stats"
//   - "Release (SHIFT) to see current rank stats"
//   - "Level"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1058 non-empty decompiler lines.
//  - Control keywords: if×45, while×20, do×19, for×12, goto×6, return×3.
//  - Notable callees: FUN_007a6de0×15, sprintf×6, CONCAT22×3, FUN_007a69d0×2, FUN_0083edd0×2, FUN_0054fe50, FUN_00551160, FUN_00551700.
//  - Strings: "%s [%d]"; "i_d_s_2d_wnd_icon_default.dds"; "  %s %d."; "Hold (SHIFT) to see next rank stats".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0083f510(void)



{

  short sVar1;

  byte bVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  int iVar6;

  char *pcVar7;

  int *piVar8;

  int *piVar9;

  int iVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  int iVar14;

  uint uVar15;

  uint uVar16;

  uint8_t **ppuVar17;

  int *unaff_EBX;

  char *pcVar18;

  short unaff_DI;

  char *pcVar19;

  char *pcVar20;

  float fVar21;

  uint32_t /* width from decompiler */ *puStack_12ac;

  uint32_t /* width from decompiler */ uStack_12a8;

  uint8_t *****pppppuStack_12a4;

  uint32_t /* width from decompiler */ uStack_12a0;

  char *pcStack_129c;

  uint32_t /* width from decompiler */ uStack_1298;

  uint32_t /* width from decompiler */ uStack_1294;

  uint32_t /* width from decompiler */ uStack_1290;

  int iStack_128c;

  int iStack_1288;

  uint32_t /* width from decompiler */ uStack_1284;

  uint8_t *****pppppuStack_1280;

  uint32_t /* width from decompiler */ uStack_127c;

  uint32_t /* width from decompiler */ uStack_1278;

  uint32_t /* width from decompiler */ uStack_1274;

  uint8_t ****ppppuStack_1270;

  uint32_t /* width from decompiler */ uStack_126c;

  uint32_t /* width from decompiler */ ****ppppuStack_1268;

  uint8_t ****ppppuStack_1264;

  uint32_t /* width from decompiler */ ****ppppuStack_1260;

  uint8_t ****ppppuStack_125c;

  uint32_t /* width from decompiler */ ***pppuStack_123c;

  uint32_t /* width from decompiler */ uStack_1238;

  uint32_t /* width from decompiler */ **ppuStack_1234;

  uint32_t /* width from decompiler */ uStack_1230;

  uint8_t ***pppuStack_122c;

  int iStack_1228;

  uint32_t /* width from decompiler */ ***pppuStack_1224;

  uint8_t ***pppuStack_1220;

  uint32_t /* width from decompiler */ uStack_121c;

  uint8_t ***pppuStack_1218;

  uint32_t /* width from decompiler */ uStack_1214;

  int **ppiStack_1210;

  int iStack_120c;

  uint32_t /* width from decompiler */ ***pppuStack_1208;

  uint32_t /* width from decompiler */ uStack_1204;

  uint32_t /* width from decompiler */ ***pppuStack_1200;

  uint8_t *puStack_11fc;

  uint32_t /* width from decompiler */ **ppuStack_11f8;

  uint32_t /* width from decompiler */ uStack_11f4;

  uint32_t /* width from decompiler */ uStack_11f0;

  uint8_t **ppuStack_11ec;

  uint32_t /* width from decompiler */ uStack_11e8;

  uint32_t /* width from decompiler */ uStack_11e4;

  uint32_t /* width from decompiler */ *puStack_11e0;

  uint32_t /* width from decompiler */ *puStack_11dc;

  uint32_t /* width from decompiler */ **ppuStack_11d8;

  int **ppiStack_11d4;

  uint32_t /* width from decompiler */ uStack_11d0;

  uint32_t /* width from decompiler */ uStack_11cc;

  uint32_t /* width from decompiler */ **ppuStack_11c8;

  uint32_t /* width from decompiler */ **ppuStack_11c4;

  uint8_t **ppuStack_11c0;

  uint32_t /* width from decompiler */ uStack_11bc;

  uint8_t **ppuStack_11b8;

  uint32_t /* width from decompiler */ uStack_11b4;

  uint32_t /* width from decompiler */ *puStack_11b0;

  uint32_t /* width from decompiler */ *puStack_11ac;

  uint32_t /* width from decompiler */ uStack_11a8;

  uint32_t /* width from decompiler */ ***pppuStack_11a4;

  int *piStack_11a0;

  uint8_t *puStack_119c;

  uint8_t **ppuStack_1198;

  uint32_t /* width from decompiler */ uStack_1194;

  uint32_t /* width from decompiler */ **ppuStack_1190;

  int *piStack_118c;

  uint8_t **ppuStack_1188;

  uint32_t /* width from decompiler */ uStack_1184;

  uint32_t /* width from decompiler */ **ppuStack_1180;

  uint32_t /* width from decompiler */ *puStack_117c;

  int iStack_1178;

  int ****ppppiStack_1174;

  int iStack_1170;

  uint32_t /* width from decompiler */ *puStack_116c;

  int iStack_1168;

  int *piStack_1164;

  uint8_t ****ppppuStack_1160;

  uint32_t /* width from decompiler */ uStack_115c;

  int ***pppiStack_1158;

  uint32_t /* width from decompiler */ uStack_1154;

  uint8_t *puStack_1150;

  uint32_t /* width from decompiler */ uStack_114c;

  uint32_t /* width from decompiler */ uStack_1148;

  uint8_t *puStack_1144;

  uint8_t *puStack_1140;

  uint8_t *puStack_113c;

  int iStack_1138;

  uint32_t /* width from decompiler */ uStack_1134;

  char cStack_1131;

  int *piStack_1130;

  uint8_t ****ppppuStack_112c;

  uint8_t *puStack_1128;

  float *pfStack_1124;

  uint32_t /* width from decompiler */ *puStack_1120;

  uint32_t /* width from decompiler */ uStack_111c;

  uint8_t ***pppuStack_1118;

  int aiStack_1114 [2];

  int **ppiStack_110c;

  uint32_t /* width from decompiler */ uStack_1108;

  int iStack_1104;

  float fStack_1100;

  float fStack_10fc;

  uint8_t *puStack_10f8;

  uint8_t *puStack_10f4;

  uint32_t /* width from decompiler */ uStack_10f0;

  uint8_t **ppuStack_10ec;

  int *piStack_10e0;

  int iStack_10dc;

  uint8_t *puStack_10d8;

  uint8_t local_10b0 [12];

  uint8_t auStack_10a4 [4];

  uint32_t /* width from decompiler */ local_10a0;

  uint32_t /* width from decompiler */ local_109c;

  uint32_t /* width from decompiler */ uStack_1090;

  uint32_t /* width from decompiler */ uStack_108c;

  char cStack_1081;

  uint8_t auStack_1080 [2];

  uint32_t /* width from decompiler */ uStack_107e;

  char acStack_106e [38];

  char acStack_1048 [8];

  uint8_t local_1040;

  char cStack_1031;

  uint16_t uStack_1030;

  uint32_t /* width from decompiler */ auStack_102e [21];

  uint8_t auStack_fd8 [2];

  uint32_t /* width from decompiler */ auStack_fd6 [12];

  char acStack_fa4 [2];

  uint32_t /* width from decompiler */ auStack_fa2 [476];

  char acStack_830 [504];

  int local_638 [91];

  short sStack_4cc;

  short sStack_b2;

  short sStack_4a;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x83f520;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  local_109c = FUN_007a69d0();

  if (unaff_EBX[0x2c2] != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX[0x2c2] + 0x688) = DAT_00d1b644;

  }

  cVar3 = *(char *)((int)unaff_EBX + 0x4fd);

  iVar14 = 0x18c;

  piVar9 = unaff_EBX + 0x146;

  piVar8 = local_638;

  while( true ) {

    if (iVar14 == 0) break;

    iVar14 = iVar14 + -1;

    *piVar8 = *piVar9;

    piVar9 = piVar9 + 1;

    piVar8 = piVar8 + 1;

  }

  if (((cVar3 == '\0') ||

      (piVar9 = (int *)CONCAT22((short)((uint)piVar9 >> 0x10),*(short *)((int)unaff_EBX + 0xb0e)),

      (short)(ushort)*(byte *)(unaff_EBX + 0x2c3) <= *(short *)((int)unaff_EBX + 0xb0e))) ||

     (*(char *)((int)unaff_EBX + 0x4fe) != '\0')) {

    piVar9 = (int *)CONCAT22((short)((uint)piVar9 >> 0x10),*(short *)((int)unaff_EBX + 0xb0e));

    bVar2 = 0;

    if (*(short *)((int)unaff_EBX + 0xb0e) == 0) goto LAB_0083f598;

  }

  else {

LAB_0083f598:

    bVar2 = 1;

  }

  puStack_10d8 = (uint8_t *)0x83f5b5;

  Skill_SetRankAndReevaluate(local_638,(void *)((uint)bVar2 + (int)piVar9),unaff_DI);

  if (unaff_EBX[0x2d4] == 0) {

    return;

  }

  local_10a0 = FUN_007a69d0();

  puStack_10d8 = local_10b0;

  local_1040 = 0;

  iStack_10dc = 0x83f5e8;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d4] + 0x140))();

  uStack_1090 = *puVar4;

  uStack_108c = puVar4[1];

  if ((char)unaff_EBX[0x13f] == '\0') {

    iStack_10dc = 1;

    piStack_10e0 = (int *)0x1;

    (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x1d8))();

  }

  else {

    if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

      piVar9 = unaff_EBX + 0x1a7;

      iVar14 = -(int)piVar9;

      do {

        iVar6 = *piVar9;

        (acStack_1048 + iVar14)[(int)piVar9] = (char)iVar6;

        piVar9 = (int *)((int)piVar9 + 1);

      } while ((char)iVar6 != '\0');

    }

    else {

      iStack_10dc = (int)(short)(sStack_4cc + sStack_4a);

      piStack_10e0 = unaff_EBX + 0x1a7;

      ppuStack_10ec = (uint8_t **)0x83f659;

      sprintf(acStack_1048,"%s [%d]");

    }

    iStack_10dc = 1;

    piStack_10e0 = (int *)0x1;

    (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x1d8))();

  }

  ppuStack_10ec = (uint8_t **)0x83f6a9;

  pfVar5 = (float *)(**(code **)(*(int *)unaff_EBX[0x2d4] + 0x134))();

  fVar21 = (float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678;

  puStack_10d8 = (uint8_t *)(int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  ppuStack_10ec = &puStack_10d8;

  uStack_10f0 = 0x83f6f5;

  (**(code **)(*(int *)unaff_EBX[0x2d4] + 300))();

  uStack_10f0 = 0x83f703;

  (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x13c))();

  uStack_10f0 = 1;

  puStack_10f4 = &stack0xffffef34;

  puStack_10f8 = (uint8_t *)0x83f718;

  (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x140))();

  puStack_10f8 = &stack0xffffef1c;

  fStack_10fc = 1.2119128e-38;

  piStack_10e0 = (int *)(int)fVar21;

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 300))();

  fStack_10fc = -NAN;

  fStack_1100 = 1.4013e-45;

  iStack_1104 = 0x83f745;

  (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x160))();

  iStack_1104 = 0;

  uStack_1108 = 1;

  ppiStack_110c = &piStack_10e0;

  aiStack_1114[1] = 0x83f75c;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d4] + 0x120))();

  puStack_10f4 = (uint8_t *)*puVar4;

  aiStack_1114[1] = 0;

  piVar9 = (int *)unaff_EBX[0x2d4];

  aiStack_1114[0] = 1;

  pppuStack_1118 = &ppuStack_10ec;

  uStack_111c = 0x83f77b;

  iVar14 = (**(code **)(*piVar9 + 0x120))();

  uStack_111c = 1;

  puStack_1120 = &uStack_1108;

  pfStack_1124 = (float *)0x83f78e;

  iVar6 = (**(code **)(*piVar9 + 0x140))();

  pfStack_1124 = &fStack_1100;

  iStack_1104 = *(int *)(iVar14 + 4) + *(int *)(iVar6 + 4) + unaff_EBX[0x144];

  puStack_1128 = (uint8_t *)0x83f7b1;

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x134))();

  fStack_10fc = (float)DAT_00d1e81c * *(float *)(iVar14 + 4) * DAT_00aaa678;

  puStack_1128 = &stack0xffffef1c;

  ppppuStack_112c = (uint8_t ****)0x83f7e3;

  pfVar5 = (float *)(**(code **)(*(int *)unaff_EBX[0x2d4] + 0x134))();

  aiStack_1114[0] = (int)fStack_1100;

  pppuStack_1118 = (uint8_t ***)(int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  ppppuStack_112c = &pppuStack_1118;

  piStack_1130 = (int *)0x83f820;

  (**(code **)(*(int *)unaff_EBX[0x2d5] + 300))();

  piStack_1130 = aiStack_1114;

  uStack_1134 = 0x83f833;

  (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x118))();

  uStack_1134 = 0x83f841;

  (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x34c))();

  uStack_1134 = 0;

  iStack_1138 = 0x83f851;

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x164))();

  *(uint8_t *)(iVar14 + 3) = 0;

  if ((char)unaff_EBX[0x13f] == '\0') {

    iStack_1138 = DAT_00d1b6d8;

    puStack_113c = auStack_10a4;

    puStack_1140 = (uint8_t *)0x83f878;

    FUN_00553090();

    iStack_1138 = 1;

    puStack_113c = (uint8_t *)0x1;

    puStack_1140 = auStack_10a4;

    puStack_1144 = (uint8_t *)0x83f892;

    (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x1d8))();

    if (sStack_b2 < 1) {

      puStack_1144 = (uint8_t *)0xffbbbbbb;

    }

    else {

      puStack_1144 = (uint8_t *)((-(uint)(cStack_1131 != '\0') & 0xfffff489) - 1);

    }

    uStack_1148 = 1;

    uStack_114c = 0x83f8c5;

    (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x160))();

    uStack_114c = 1;

    puStack_1150 = (uint8_t *)0x83f8d5;

    (**(code **)(*(int *)unaff_EBX[0x2d5] + 0xcc))();

  }

  else {

    iStack_1138 = 0;

    puStack_113c = (uint8_t *)0x83f8e7;

    (**(code **)(*(int *)unaff_EBX[0x2d5] + 0xcc))();

  }

  puStack_1150 = (uint8_t *)0x0;

  uStack_1154 = 1;

  pppiStack_1158 = &ppiStack_110c;

  uStack_115c = 0x83f8fe;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x120))();

  puStack_1140 = (uint8_t *)*puVar4;

  puStack_113c = (uint8_t *)puVar4[1];

  uStack_115c = 0x83f919;

  cVar3 = (**(code **)(*(int *)unaff_EBX[0x2d5] + 0xd0))();

  if (cVar3 == '\0') {

    iVar14 = 0;

  }

  else {

    uStack_115c = 1;

    ppppuStack_1160 = &pppuStack_1118;

    piStack_1164 = (int *)0x83f932;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x140))();

    iVar14 = *(int *)(iVar14 + 4) + unaff_EBX[0x144];

  }

  piVar9 = (int *)unaff_EBX[0x2d4];

  uStack_115c = 0;

  ppppuStack_1160 = (uint8_t ****)0x1;

  piStack_1164 = &iStack_1138;

  iStack_1168 = 0x83f958;

  puStack_113c = (uint8_t *)(**(code **)(*piVar9 + 0x120))();

  iStack_1168 = 1;

  puStack_116c = &uStack_1154;

  iStack_1170 = 0x83f96d;

  iVar6 = (**(code **)(*piVar9 + 0x140))();

  puStack_1150 = (uint8_t *)

                 (*(int *)(puStack_1144 + 4) + *(int *)(iVar6 + 4) + unaff_EBX[0x144] + iVar14);

  iStack_1170 = 0x83f991;

  (**(code **)(*(int *)unaff_EBX[0x2da] + 0x34c))();

  iStack_1170 = 1;

  ppppiStack_1174 = (int ****)0x83f9a1;

  (**(code **)(*(int *)unaff_EBX[0x2da] + 0xcc))();

  ppppiStack_1174 = &pppiStack_1158;

  iStack_1178 = 0x83f9b4;

  (**(code **)(*(int *)unaff_EBX[0x2da] + 0x118))();

  iStack_1178 = 1;

  puStack_117c = &stack0xffffeecc;

  ppuStack_1180 = (uint32_t /* width from decompiler */ **)0x83f9c9;

  puStack_116c = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x140))();

  puStack_116c = (uint32_t /* width from decompiler */ *)*puStack_116c;

  ppuStack_1180 = &puStack_116c;

  iStack_1168 = 0;

  uStack_1184 = 0x83f9ea;

  (**(code **)(*(int *)unaff_EBX[0x2da] + 300))();

  if (unaff_EBX[0x2db] != 0) {

    uStack_1184 = 0x83fa05;

    (**(code **)(*(int *)unaff_EBX[0x2db] + 0x34c))();

    uStack_1184 = 1;

    ppuStack_1188 = (uint8_t **)0x83fa15;

    (**(code **)(*(int *)unaff_EBX[0x2db] + 0xcc))();

    ppuStack_1188 = &puStack_1144;

    piStack_118c = (int *)0x83fa28;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x2db] + 0x124))();

    piStack_118c = &iStack_1168;

    ppppuStack_1160 = (uint8_t ****)((float)DAT_00d1e81c * *(float *)(iVar14 + 4) * DAT_00aaa678)

    ;

    ppuStack_1190 = (uint32_t /* width from decompiler */ **)0x83fa5a;

    pfVar5 = (float *)(**(code **)(*(int *)unaff_EBX[0x2db] + 0x124))();

    iStack_1178 = (int)(float)piStack_1164 + iStack_1170;

    puStack_117c = (uint32_t /* width from decompiler */ *)

                   ((int)ppppiStack_1174 - (int)((float)DAT_00d1e818 * *pfVar5 * _DAT_00aaa6ac));

    ppuStack_1190 = &puStack_117c;

    uStack_1194 = 0x83faa1;

    (**(code **)(*(int *)unaff_EBX[0x2db] + 0x110))();

    auStack_1080 = (uint8_t  [2])0x0;

    puVar4 = (uint32_t /* width from decompiler */ *)(auStack_1080 + 2);

    for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    pcVar20 = &cStack_1081;

    do {

      pcVar7 = pcVar20;

      pcVar20 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_i_d_s_2d_wnd_icon__00a540d0._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_i_d_s_2d_wnd_icon__00a540d0._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_i_d_s_2d_wnd_icon__00a540d0._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_i_d_s_2d_wnd_icon__00a540d0._12_4_;

    *(uint16_t *)(pcVar7 + 0x11) = s_i_d_s_2d_wnd_icon__00a540d0._16_2_;

    pcVar7[0x13] = s_i_d_s_2d_wnd_icon__00a540d0[0x12];

    pcVar20 = (char *)((int)unaff_EBX + 0xabe);

    pcVar7 = pcVar20;

    do {

      cVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar3 != '\0');

    pcVar19 = &cStack_1081;

    do {

      pcVar18 = pcVar19 + 1;

      pcVar19 = pcVar19 + 1;

    } while (*pcVar18 != '\0');

    pcVar18 = pcVar20;

    for (uVar15 = (uint)((int)pcVar7 - (int)pcVar20) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar19 = *(uint32_t /* width from decompiler */ *)pcVar18;

      pcVar18 = pcVar18 + 4;

      pcVar19 = pcVar19 + 4;

    }

    for (uVar15 = (int)pcVar7 - (int)pcVar20 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

      *pcVar19 = *pcVar18;

      pcVar18 = pcVar18 + 1;

      pcVar19 = pcVar19 + 1;

    }

    pcVar20 = &cStack_1081;

    do {

      pcVar7 = pcVar20 + 1;

      pcVar20 = pcVar20 + 1;

    } while (*pcVar7 != '\0');

    *(uint32_t /* width from decompiler */ *)pcVar20 = DAT_00a540cc;

    pcVar20 = &cStack_1081;

    do {

      pcVar7 = pcVar20;

      pcVar20 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    ppuStack_1198 = (uint8_t **)auStack_1080;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_00a2c53c;

    uStack_1194 = 0xffffffff;

    pcVar7[5] = DAT_00a2c540;

    puStack_119c = (uint8_t *)0x83fb8c;

    FUN_007b6a20();

    puStack_119c = (uint8_t *)0x83fb93;

    cVar3 = FUN_007b6730();

    if (cVar3 == '\0') {

      pcVar20 = "i_d_s_2d_wnd_icon_default.dds";

      puVar4 = (uint32_t /* width from decompiler */ *)auStack_1080;

      for (iVar14 = 7; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar20;

        pcVar20 = pcVar20 + 4;

        puVar4 = puVar4 + 1;

      }

      *(uint16_t *)puVar4 = *(uint16_t *)pcVar20;

    }

    iVar14 = *(int *)unaff_EBX[0x2db];

    uStack_1194 = 0;

    ppuStack_1198 = (uint8_t **)0x83fbc0;

    ppuStack_1198 = (uint8_t **)(**(code **)(*(int *)unaff_EBX[0x2db] + 0x2c8))();

    puStack_119c = auStack_1080;

    piStack_11a0 = (int *)0x83fbd2;

    (**(code **)(iVar14 + 0x50))();

    if (unaff_EBX[0x2dc] != 0) {

      uStack_1184 = 0x83fbed;

      (**(code **)(*(int *)unaff_EBX[0x2dc] + 0x34c))();

      uStack_1184 = 1;

      ppuStack_1188 = (uint8_t **)0x83fbfd;

      (**(code **)(*(int *)unaff_EBX[0x2dc] + 0xcc))();

      ppuStack_1188 = &puStack_1144;

      piStack_118c = (int *)0x83fc10;

      iVar14 = (**(code **)(*(int *)unaff_EBX[0x2dc] + 0x124))();

      piStack_118c = &iStack_1168;

      ppppuStack_1160 =

           (uint8_t ****)((float)DAT_00d1e81c * *(float *)(iVar14 + 4) * DAT_00aaa678);

      ppuStack_1190 = (uint32_t /* width from decompiler */ **)0x83fc42;

      pfVar5 = (float *)(**(code **)(*(int *)unaff_EBX[0x2dc] + 0x124))();

      iStack_1178 = (int)(float)piStack_1164 + iStack_1170;

      puStack_117c = (uint32_t /* width from decompiler */ *)

                     ((int)ppppiStack_1174 - (int)((float)DAT_00d1e818 * *pfVar5 * _DAT_00aaa6ac));

      ppuStack_1190 = &puStack_117c;

      uStack_1194 = 0x83fc89;

      (**(code **)(*(int *)unaff_EBX[0x2dc] + 0x110))();

    }

  }

  piVar9 = piStack_1164;

  uStack_1184 = 1;

  ppuStack_1188 = &puStack_1140;

  piStack_118c = (int *)0x83fca2;

  piVar8 = (int *)(**(code **)(*(int *)unaff_EBX[0x2dc] + 0x140))();

  iStack_1178 = unaff_EBX[0x143] + iStack_1170 + *piVar8;

  piStack_118c = &iStack_1178;

  ppppiStack_1174 = (int ****)piVar9;

  ppuStack_1190 = (uint32_t /* width from decompiler */ **)0x83fcc9;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x118))();

  ppuStack_1190 = (uint32_t /* width from decompiler */ **)0x1;

  uStack_1194 = 0x83fcd9;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0xcc))();

  uStack_1194 = 0x83fce7;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x34c))();

  uStack_1194 = 1;

  ppuStack_1198 = &puStack_1150;

  puStack_119c = (uint8_t *)0x83fcfc;

  piVar9 = (int *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x140))();

  puStack_119c = (uint8_t *)0x1;

  piStack_11a0 = &iStack_1178;

  pppuStack_11a4 = (uint32_t /* width from decompiler */ ***)0x83fd13;

  piVar8 = (int *)(**(code **)(*(int *)unaff_EBX[0x2dc] + 0x140))();

  ppuStack_1190 = (uint32_t /* width from decompiler */ **)((*piVar9 / 2 - unaff_EBX[0x143]) - *piVar8);

  pppuStack_11a4 = &ppuStack_1190;

  piStack_118c = (int *)0x0;

  uStack_11a8 = 0x83fd41;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 300))();

  uStack_11a8 = 1;

  puStack_11ac = (uint32_t /* width from decompiler */ *)0x1;

  puStack_11b0 = (uint32_t /* width from decompiler */ *)0x0;

  uStack_11b4 = 0x83fd54;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x1d8))();

  uStack_11b4 = 0;

  ppuStack_11b8 = (uint8_t **)0x83fd63;

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x164))();

  *(uint8_t *)(iVar14 + 3) = 0;

  ppuVar17 = (uint8_t **)((-(uint)(uStack_11a8._3_1_ != '\0') & 0xfffff489) - 1);

  uStack_11bc = 1;

  ppuStack_11c0 = (uint8_t **)0x83fd8f;

  ppuStack_11b8 = ppuVar17;

  pppuStack_11a4 = (uint32_t /* width from decompiler */ ***)ppuVar17;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x160))();

  acStack_fa4[0] = '\0';

  acStack_fa4[1] = '\0';

  puVar4 = auStack_fa2;

  for (iVar14 = 0xff; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  ppuStack_11c0 = (uint8_t **)0x3ff;

  ppuStack_11c4 = (uint32_t /* width from decompiler */ **)acStack_fa4;

  ppuStack_11c8 = (uint32_t /* width from decompiler */ **)0x83fdc2;

  iVar14 = FUN_00551160();

  if (iVar14 != 0) {

    pcVar20 = acStack_fa4;

    do {

      cVar3 = *pcVar20;

      pcVar20 = pcVar20 + 1;

    } while (cVar3 != '\0');

    iVar14 = (int)pcVar20 - (int)(acStack_fa4 + 1);

    if ((iVar14 != 0) && (*(char *)((int)auStack_fa2 + iVar14 + -3) == '\n')) {

      *(uint8_t *)((int)auStack_fa2 + iVar14 + -3) = 0;

    }

    ppuStack_11c0 = (uint8_t **)0x1;

    ppuStack_11c4 = (uint32_t /* width from decompiler */ **)0x1;

    ppuStack_11c8 = (uint32_t /* width from decompiler */ **)acStack_fa4;

    uStack_11cc = 0x83fe0a;

    (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x1d8))();

  }

  ppuStack_11c0 = (uint8_t **)0x83fe18;

  (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x13c))();

  ppuStack_11c0 = (uint8_t **)0x1;

  ppuStack_11c4 = &puStack_117c;

  ppuStack_11c8 = (uint32_t /* width from decompiler */ **)0x83fe2d;

  piVar9 = (int *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x140))();

  puStack_11ac = (uint32_t /* width from decompiler */ *)((int)puStack_11ac + unaff_EBX[0x143] * 2 + *piVar9 / 2);

  ppuStack_11c8 = &puStack_11ac;

  uStack_11cc = 0x83fe58;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x118))();

  uStack_11cc = 1;

  uStack_11d0 = 0x83fe68;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0xcc))();

  uStack_11d0 = 0x83fe76;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x34c))();

  uStack_11d0 = 1;

  ppiStack_11d4 = &piStack_118c;

  ppuStack_11d8 = (uint32_t /* width from decompiler */ **)0x83fe8b;

  piVar9 = (int *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x140))();

  puStack_11ac = (uint32_t /* width from decompiler */ *)(*piVar9 / 2);

  ppuStack_11d8 = &puStack_11ac;

  uStack_11a8 = 0;

  puStack_11dc = (uint32_t /* width from decompiler */ *)0x83feaf;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 300))();

  puStack_11dc = (uint32_t /* width from decompiler */ *)0x1;

  puStack_11e0 = (uint32_t /* width from decompiler */ *)0x1;

  uStack_11e4 = 0;

  uStack_11e8 = 0x83fec2;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x1d8))();

  uStack_11e8 = 0;

  ppuStack_11ec = (uint8_t **)0x83fed1;

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x164))();

  *(uint8_t *)(iVar14 + 3) = 0;

  uStack_11f0 = 1;

  uStack_11f4 = 0x83fee6;

  ppuStack_11ec = ppuVar17;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x160))();

  auStack_fd8 = (uint8_t  [2])0x0;

  puVar4 = auStack_fd6;

  for (iVar14 = 0xff; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  uStack_11f4 = 0x400;

  ppuStack_11f8 = (uint32_t /* width from decompiler */ **)auStack_fd8;

  *(uint16_t *)puVar4 = 0;

  puStack_11fc = (uint8_t *)0x83ff19;

  iVar14 = FUN_00551700();

  if (iVar14 != 0) {

    pcVar20 = auStack_fd8;

    do {

      cVar3 = *pcVar20;

      pcVar20 = pcVar20 + 1;

    } while (cVar3 != '\0');

    iVar14 = (int)pcVar20 - (int)(auStack_fd8 + 1);

    if ((iVar14 != 0) && (*(char *)((int)auStack_fd6 + iVar14 + -3) == '\n')) {

      *(uint8_t *)((int)auStack_fd6 + iVar14 + -3) = 0;

    }

    uStack_11f4 = 1;

    ppuStack_11f8 = (uint32_t /* width from decompiler */ **)0x1;

    puStack_11fc = auStack_fd8;

    pppuStack_1200 = (uint32_t /* width from decompiler */ ***)0x83ff61;

    (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x1d8))();

  }

  uStack_11f4 = 0x83ff6f;

  (**(code **)(*(int *)unaff_EBX[0x2d9] + 0x13c))();

  piVar9 = (int *)unaff_EBX[0x2d9];

  uStack_11f4 = 1;

  ppuStack_11f8 = &puStack_11b0;

  puStack_11fc = (uint8_t *)0x83ff8a;

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x140))();

  puStack_11fc = (uint8_t *)0x1;

  pppuStack_1200 = &ppuStack_11d8;

  uStack_1204 = 0x83ff9d;

  iVar6 = (**(code **)(*piVar9 + 0x140))();

  uStack_1204 = 1;

  if (*(int *)(iVar6 + 4) < *(int *)(iVar14 + 4)) {

    piVar9 = (int *)unaff_EBX[0x2d8];

    pppuStack_1208 = &ppuStack_1190;

  }

  else {

    piVar9 = (int *)unaff_EBX[0x2d9];

    pppuStack_1208 = &ppuStack_1180;

  }

  iStack_120c = 0x83ffc9;

  iVar14 = (**(code **)(*piVar9 + 0x140))();

  iVar14 = *(int *)(iVar14 + 4);

  iStack_120c = 1;

  ppiStack_1210 = &piStack_11a0;

  uStack_1214 = 0x83ffe1;

  iVar6 = (**(code **)(*(int *)unaff_EBX[0x2dc] + 0x140))();

  uStack_1214 = 1;

  if (iVar14 < *(int *)(iVar6 + 4)) {

    piVar9 = (int *)unaff_EBX[0x2dc];

    pppuStack_1218 = &ppuStack_1198;

  }

  else {

    piVar9 = (int *)unaff_EBX[0x2d9];

    pppuStack_1218 = &ppuStack_1188;

    uStack_121c = 0x840010;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d8] + 0x140))();

    uStack_121c = 1;

    pppuStack_1220 = &ppuStack_11b8;

    pppuStack_1224 = (uint32_t /* width from decompiler */ ***)0x840023;

    iVar6 = (**(code **)(*piVar9 + 0x140))();

    if (*(int *)(iVar6 + 4) < *(int *)(iVar14 + 4)) {

      piVar9 = (int *)unaff_EBX[0x2d8];

      pppuStack_1218 = &ppuStack_11b8;

    }

    else {

      piVar9 = (int *)unaff_EBX[0x2d9];

      pppuStack_1218 = &ppuStack_11c0;

    }

  }

  uStack_1214 = 1;

  uStack_121c = 0x84004c;

  iVar14 = (**(code **)(*piVar9 + 0x140))();

  uVar11 = *(uint32_t /* width from decompiler */ *)(iVar14 + 4);

  uStack_121c = 1;

  pppuStack_1220 = (uint8_t ***)&puStack_11e0;

  pppuStack_1224 = (uint32_t /* width from decompiler */ ***)0x840064;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2da] + 0x140))();

  ppuStack_11f8 = (uint32_t /* width from decompiler */ **)*puVar4;

  pppuStack_1224 = &ppuStack_11f8;

  iStack_1228 = 0x840081;

  uStack_11f4 = uVar11;

  (**(code **)(*(int *)unaff_EBX[0x2da] + 300))();

  if (unaff_EBX[0x2db] == 0) {

LAB_0084012e:

    if (unaff_EBX[0x2dc] != 0) {

      piVar9 = (int *)unaff_EBX[0x2dc];

      iStack_1228 = 1;

      pppuStack_122c = &ppuStack_11ec;

      uStack_1230 = (uint8_t ***)0x840158;

      uStack_1204 = (**(code **)(*(int *)unaff_EBX[0x2da] + 0x140))();

      uStack_1230 = (uint8_t ***)0x1;

      ppuStack_1234 = &puStack_11dc;

      uStack_1238 = 0x84016d;

      iVar6 = (**(code **)(*piVar9 + 0x140))();

      iVar14 = *(int *)(iStack_120c + 4);

      iVar6 = *(int *)(iVar6 + 4);

      uStack_1238 = 0;

      pppuStack_123c = (uint32_t /* width from decompiler */ ***)0x1;

      iVar10 = (**(code **)(*piVar9 + 0x120))();

      iVar10 = *(int *)(iVar10 + 4);

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2dc] + 0x120))();

      pppuStack_122c = (uint8_t ***)*puVar4;

      iStack_1228 = (iVar14 - iVar6) / 2 + iVar10;

      (**(code **)(*(int *)unaff_EBX[0x2dc] + 0x110))();

    }

  }

  else if (unaff_EBX[0x2dc] != 0) {

    piVar9 = (int *)unaff_EBX[0x2dc];

    piVar8 = (int *)unaff_EBX[0x2db];

    iStack_1228 = 1;

    pppuStack_122c = &ppuStack_11ec;

    uStack_1230 = (uint8_t ***)0x8400bc;

    uStack_1204 = (**(code **)(*(int *)unaff_EBX[0x2da] + 0x140))();

    uStack_1230 = (uint8_t ***)0x1;

    ppuStack_1234 = &puStack_11dc;

    uStack_1238 = 0x8400d1;

    iVar6 = (**(code **)(*piVar9 + 0x140))();

    iVar14 = *(int *)(iStack_120c + 4);

    iVar6 = *(int *)(iVar6 + 4);

    uStack_1238 = 0;

    pppuStack_123c = (uint32_t /* width from decompiler */ ***)0x1;

    iVar10 = (**(code **)(*piVar8 + 0x120))();

    iVar10 = *(int *)(iVar10 + 4);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2db] + 0x120))();

    pppuStack_122c = (uint8_t ***)*puVar4;

    iStack_1228 = (iVar14 - iVar6) / 2 + iVar10;

    (**(code **)(*(int *)unaff_EBX[0x2db] + 0x110))();

    goto LAB_0084012e;

  }

  iStack_1228 = 0;

  pppuStack_122c = (uint8_t ***)0x1;

  uStack_1230 = &ppuStack_11ec;

  ppuStack_1234 = (uint32_t /* width from decompiler */ **)0x8401e1;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d7] + 0x120))();

  pppuStack_1218 = (uint8_t ***)*puVar4;

  uStack_1214 = puVar4[1];

  piVar9 = (int *)unaff_EBX[0x2da];

  ppuStack_1234 = (uint32_t /* width from decompiler */ **)0x0;

  uStack_1238 = 1;

  pppuStack_123c = &ppuStack_11f8;

  iVar14 = (**(code **)(*piVar9 + 0x120))();

  iVar6 = (**(code **)(*piVar9 + 0x140))();

  iStack_1228 = *(int *)(iVar14 + 4) + *(int *)(iVar6 + 4) + unaff_EBX[0x144];

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x118))();

  uStack_1030 = 0;

  puVar4 = auStack_102e;

  for (iVar14 = 0x1ff; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  if (unaff_EBX != (int *)0xfffff943) {

    pcVar7 = (char *)FUN_007a6de0();

    pcVar20 = (char *)&uStack_1030;

    do {

      cVar3 = *pcVar7;

      *pcVar20 = cVar3;

      pcVar7 = pcVar7 + 1;

      pcVar20 = pcVar20 + 1;

    } while (cVar3 != '\0');

  }

  if (0 < *(int *)(DAT_00d1b6d8 + 0x6b4)) {

    FUN_007a6de0();

    ppppuStack_125c = (uint8_t ****)0x8402bd;

    sprintf(acStack_830,"  %s %d.");

    pcVar20 = acStack_830;

    do {

      cVar3 = *pcVar20;

      pcVar20 = pcVar20 + 1;

    } while (cVar3 != '\0');

    uVar15 = (int)pcVar20 - (int)acStack_830;

    pcVar20 = &cStack_1031;

    do {

      pcVar7 = pcVar20 + 1;

      pcVar20 = pcVar20 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = acStack_830;

    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar20 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar20 = pcVar20 + 4;

    }

    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

      *pcVar20 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar20 = pcVar20 + 1;

    }

  }

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x268))();

  FUN_0083f160();

  if (((char)unaff_EBX[0x13f] != '\0') && (unaff_EBX[0x145] != 0)) {

    uStack_1030 = uStack_1030 & 0xff00;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x145] + 0x34))();

    if (0 < iVar14) {

      pcVar20 = (char *)&uStack_1030;

      do {

        cVar3 = *pcVar20;

        pcVar20 = pcVar20 + 1;

      } while (cVar3 != '\0');

      pppuStack_1220 = (uint8_t ***)(pcVar20 + -((int)&uStack_1030 + 1));

      if (pppuStack_1220 != (uint8_t ***)0x0) {

        FUN_0083edd0();

        (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x250))();

        (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x224))();

      }

    }

    uStack_1030 = 10;

    if ((*(byte *)(unaff_EBX[0x145] + 0x639) & 2) == 0) {

      if ((*(char *)(unaff_EBX[0x145] + 0xfe) != '\0') && (iVar14 = FUN_007fcb80(), iVar14 != 0)) {

        pcVar7 = (char *)FUN_007a6de0();

        pcVar20 = pcVar7;

        do {

          cVar3 = *pcVar20;

          pcVar20 = pcVar20 + 1;

        } while (cVar3 != '\0');

        uVar15 = (int)pcVar20 - (int)pcVar7;

        pcVar20 = &cStack_1031;

        do {

          pcVar19 = pcVar20 + 1;

          pcVar20 = pcVar20 + 1;

        } while (*pcVar19 != '\0');

        goto LAB_008404af;

      }

      if (((*(char *)(unaff_EBX[0x145] + 0xfe) != '\0') && (DAT_00d1b938 != 0)) &&

         (cVar3 = FUN_0088a910(), cVar3 != '\0')) {

        pcVar7 = (char *)FUN_007a6de0();

        pcVar20 = pcVar7;

        do {

          cVar3 = *pcVar20;

          pcVar20 = pcVar20 + 1;

        } while (cVar3 != '\0');

        uVar15 = (int)pcVar20 - (int)pcVar7;

        pcVar20 = &cStack_1031;

        do {

          pcVar19 = pcVar20 + 1;

          pcVar20 = pcVar20 + 1;

        } while (*pcVar19 != '\0');

        goto LAB_008404af;

      }

    }

    else {

      pcVar7 = (char *)FUN_007a6de0();

      pcVar20 = pcVar7;

      do {

        cVar3 = *pcVar20;

        pcVar20 = pcVar20 + 1;

      } while (cVar3 != '\0');

      uVar15 = (int)pcVar20 - (int)pcVar7;

      pcVar20 = &cStack_1031;

      do {

        pcVar19 = pcVar20 + 1;

        pcVar20 = pcVar20 + 1;

      } while (*pcVar19 != '\0');

LAB_008404af:

      for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar20 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar20 = pcVar20 + 4;

      }

      for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

        *pcVar20 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar20 = pcVar20 + 1;

      }

      FUN_0083edd0();

    }

    pcVar20 = (char *)&uStack_1030;

    do {

      cVar3 = *pcVar20;

      pcVar20 = pcVar20 + 1;

    } while (cVar3 != '\0');

    if (1 < (uint)((int)pcVar20 - ((int)&uStack_1030 + 1))) {

      (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x224))();

    }

  }

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x13c))();

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x34c))();

  (**(code **)(*(int *)unaff_EBX[0x2d7] + 0x160))();

  ppppuStack_125c = &pppuStack_1218;

  ppppuStack_1260 = (uint32_t /* width from decompiler */ ****)0x840547;

  (**(code **)(*(int *)unaff_EBX[0x2d5] + 0x120))();

  piVar9 = (int *)unaff_EBX[0x2d7];

  ppppuStack_1260 = (uint32_t /* width from decompiler */ ****)0x0;

  ppppuStack_1264 = (uint8_t ****)0x1;

  ppppuStack_1268 = &pppuStack_1224;

  uStack_126c = 0x840565;

  (**(code **)(*piVar9 + 0x120))();

  uStack_126c = 1;

  ppppuStack_1270 = &pppuStack_1218;

  uStack_1274 = 0x84057a;

  (**(code **)(*piVar9 + 0x140))();

  uStack_1274 = 0x84059c;

  (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x34c))();

  if (((*(short *)((int)unaff_EBX + 0xb0e) < (short)(ushort)*(byte *)(unaff_EBX + 0x2c3)) &&

      (0 < *(short *)((int)unaff_EBX + 0xb0e))) &&

     ((*(char *)((int)unaff_EBX + 0x4fe) == '\0' && ((char)unaff_EBX[0x13f] == '\0')))) {

    uStack_1274 = 1;

    uStack_1278 = 0x8405e6;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 0xcc))();

    uStack_1278 = 1;

    uStack_127c = &pppuStack_123c;

    pppppuStack_1280 = (uint8_t *****)0x8405fb;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d5] + 0x140))();

    ppppuStack_125c = (uint8_t ****)*puVar4;

    pppppuStack_1280 = &ppppuStack_125c;

    uStack_1284 = (uint32_t /* width from decompiler */ *****)0x840618;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 300))();

    ppppuStack_1260 = ppppuStack_1268;

    ppppuStack_125c = ppppuStack_1264;

    uStack_1284 = &ppppuStack_1260;

    iStack_1288 = 0x84063b;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x110))();

    iStack_1288 = 0;

    iStack_128c = 0x84064a;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x164))();

    *(uint8_t *)(iVar14 + 3) = 0;

    iStack_128c = (-(uint)(uStack_127c._3_1_ != '\0') & 0xb77) - 0xb78;

    uStack_1290 = 1;

    uStack_1294 = 0x840671;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x160))();

    uStack_1294 = 1;

    uStack_1298 = 1;

    if (uStack_1284._3_1_ == '\0') {

      pcStack_129c = "Hold (SHIFT) to see next rank stats";

      uStack_12a0 = 0x84069e;

      (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x1d8))();

    }

    else {

      pcStack_129c = "Release (SHIFT) to see current rank stats";

      uStack_12a0 = 0x84068f;

      (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x1d8))();

    }

    uStack_12a0 = 0x8406ac;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x13c))();

    uStack_12a0 = 1;

    pppppuStack_12a4 = &ppppuStack_1264;

    uStack_12a8 = 0x8406c1;

    iVar14 = (**(code **)(*(int *)unaff_EBX[0x2dd] + 0x140))();

    iStack_1288 = iStack_1288 + *(int *)(iVar14 + 4) + unaff_EBX[0x144];

  }

  else {

    uStack_1274 = 0;

    uStack_1278 = 0x8406df;

    (**(code **)(*(int *)unaff_EBX[0x2dd] + 0xcc))();

  }

  uStack_12a8 = 0x8406ed;

  (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x34c))();

  uStack_12a8 = 1;

  puStack_12ac = &uStack_126c;

  piVar9 = (int *)(**(code **)(*(int *)unaff_EBX[0x2d5] + 0x140))();

  iStack_128c = *piVar9;

  iStack_1288 = 0;

  (**(code **)(*(int *)unaff_EBX[0x2d6] + 300))(&iStack_128c);

  (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x118))(&uStack_1298);

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x164))(0);

  *(uint8_t *)(iVar14 + 3) = 0;

  if ((((char)unaff_EBX[0x13f] == '\0') &&

      (*(short *)((int)unaff_EBX + 0xb0e) < (short)(ushort)*(byte *)(unaff_EBX + 0x2c3))) &&

     (*(char *)((int)unaff_EBX + 0x4fe) == '\0')) {

    iVar14 = FUN_0054fe50(CONCAT22((short)((uint)iVar14 >> 0x10),*(short *)((int)unaff_EBX + 0xb0e))

                          + 1);

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x27c))();

    if (iVar6 < iVar14) {

      if (*(short *)((int)unaff_EBX + 0x51a) == 0) {

        uVar11 = FUN_007a6de0("Level",0xffffffff);

        uVar12 = FUN_007a6de0("Requires",0xffffffff);

        sprintf((char *)&iStack_1228,"%s:  %s %d",uVar12,uVar11,iVar14);

      }

      else {

        if (*(short *)((int)unaff_EBX + 0x51a) == 1) {

          pcVar20 = "Skill Point";

        }

        else {

          pcVar20 = "Skill Points";

        }

        uVar11 = FUN_007a6de0(pcVar20,0xffffffff);

        iVar6 = (int)*(short *)((int)unaff_EBX + 0x51a);

        uVar12 = FUN_007a6de0("Level",0xffffffff);

        uVar13 = FUN_007a6de0("Requires",0xffffffff);

        sprintf((char *)&iStack_1228,"%s:  %s %d, %d %s",uVar13,uVar12,iVar14,iVar6,uVar11);

      }

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x1d8))(&iStack_1228,1,1);

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x160))(1,0xffff2020);

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 4))(1);

      goto LAB_008409f7;

    }

    if ((short)(ushort)*(byte *)(unaff_EBX + 0x2c3) <= *(short *)((int)unaff_EBX + 0xb0e)) {

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 0xcc))(0);

      goto LAB_008409f7;

    }

    cVar3 = FUN_005533f0(DAT_00d1b6d8);

    if (cVar3 == '\0') {

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x160))(1,0xffff2020);

      if (*(short *)((int)unaff_EBX + 0x51a) == 1) {

        pcVar20 = "Skill Point";

      }

      else {

        pcVar20 = "Skill Points";

      }

      uVar11 = FUN_007a6de0(pcVar20,0xffffffff);

      iVar14 = (int)*(short *)((int)unaff_EBX + 0x51a);

      uVar12 = FUN_007a6de0("Requires",0xffffffff);

      sprintf((char *)&uStack_1230,"%s:  %d %s",uVar12,iVar14,uVar11);

    }

    else {

      (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x160))(1,0xff20ff20);

      if (*(short *)((int)unaff_EBX + 0x51a) == 0) {

        pcVar20 = "Left-Click to Upgrade For Free";

        puVar4 = &uStack_1230;

        for (iVar14 = 7; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar20;

          pcVar20 = pcVar20 + 4;

          puVar4 = puVar4 + 1;

        }

        *(uint16_t *)puVar4 = *(uint16_t *)pcVar20;

        *(char *)((int)puVar4 + 2) = pcVar20[2];

      }

      else {

        if (*(short *)((int)unaff_EBX + 0x51a) == 1) {

          pcVar20 = "Skill Point";

        }

        else {

          pcVar20 = "Skill Points";

        }

        uVar11 = FUN_007a6de0(pcVar20,0xffffffff);

        sVar1 = *(short *)((int)unaff_EBX + 0x51a);

        uVar12 = FUN_007a6de0("and Upgrade",0xffffffff);

        iVar14 = (int)sVar1;

        uVar13 = FUN_007a6de0("Left-Click to spend",0xffffffff);

        sprintf((char *)&uStack_1230,"%s %d %s %s",uVar13,iVar14,uVar11,uVar12);

      }

    }

    (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x1d8))(&uStack_1230,1,1);

    uVar11 = 1;

  }

  else {

    uVar11 = 0;

  }

  (**(code **)(*(int *)unaff_EBX[0x2d6] + 0xcc))(uVar11);

LAB_008409f7:

  (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x13c))();

  iVar14 = (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x120))(&uStack_1298,1,0);

  iVar14 = *(int *)(iVar14 + 4);

  cVar3 = (**(code **)(*(int *)unaff_EBX[0x2d6] + 0xd0))();

  if (cVar3 != '\0') {

    iVar6 = (**(code **)(*(int *)unaff_EBX[0x2d6] + 0x140))(&pppppuStack_12a4,1);

    iVar14 = iVar14 + *(int *)(iVar6 + 4);

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_EBX[0x2d3] + 0x140))(&pppppuStack_12a4,1);

  pcStack_129c = (char *)*puVar4;

  uStack_1298 = puVar4[1];

  iVar6 = (**(code **)(*(int *)unaff_EBX[0x2d4] + 0x120))(&puStack_12ac,1,0);

  pppppuStack_12a4 = (uint8_t *****)(*(int *)(iVar6 + 4) + iVar14);

  (**(code **)(*(int *)unaff_EBX[0x2d3] + 8))(&uStack_12a8);

  (**(code **)(*unaff_EBX + 8))(&puStack_12ac);

  (**(code **)(*unaff_EBX + 0x34c))();

  return;

}
