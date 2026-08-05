// =============================================================================
// FUN_00955010
// -----------------------------------------------------------------------------
// Stable ID: aa_00955010
// Address:   0x00955010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00955010 @ 0x00955010
// Stable ID: aa_00955010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~654 non-empty decompiler lines.
//  - Control keywords: if×37, while×9, do×4, goto×3, return×2, for×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×17, CONCAT31×14, FUN_00424830×12, FUN_005715d0×12, FUN_004248c0×9, FUN_00402410×8, FUN_00571620×6, Client_SendSectorPacket×5.
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

/* WARNING: Restarted to delay deadcode elimination for space: stack */



uint32_t /* width from decompiler */ __fastcall FUN_00955010(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t uVar4;

  char cVar5;

  char *_Str;

  uint uVar6;

  int iVar7;

  uint *puVar8;

  uint *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int *unaff_EBP;

  int *unaff_ESI;

  time_t tVar11;

  uint32_t /* width from decompiler */ uStack_220;

  uint8_t *puStack_21c;

  uint32_t /* width from decompiler */ **ppuStack_218;

  uint32_t /* width from decompiler */ uStack_214;

  uint8_t *puStack_210;

  uint32_t /* width from decompiler */ *puStack_20c;

  uint32_t /* width from decompiler */ uStack_208;

  uint8_t *puStack_204;

  int **ppiStack_200;

  uint32_t /* width from decompiler */ uStack_1fc;

  uint8_t *puStack_1f8;

  uint32_t /* width from decompiler */ *puStack_1f4;

  uint32_t /* width from decompiler */ uStack_1f0;

  uint8_t *puStack_1ec;

  int **ppiStack_1e8;

  uint8_t auStack_1e4 [4];

  uint32_t /* width from decompiler */ uStack_1e0;

  int *piStack_1dc;

  int *piStack_1d8;

  uint32_t /* width from decompiler */ uStack_1cc;

  uint8_t *puStack_1c8;

  uint *puStack_1c4;

  uint32_t /* width from decompiler */ *puStack_1c0;

  int iStack_1bc;

  int *piStack_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  uint32_t /* width from decompiler */ *puStack_1b0;

  int **ppiStack_1ac;

  int *local_190 [2];

  int **ppiStack_188;

  uint8_t *puStack_184;

  uint32_t /* width from decompiler */ uStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  uint uStack_178;

  int *local_174;

  uint local_170;

  uint32_t /* width from decompiler */ local_16c;

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  int *piStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  int local_154;

  uint32_t /* width from decompiler */ uStack_150;

  uint local_14c;

  int *piStack_148;

  uint uStack_144;

  uint32_t /* width from decompiler */ uStack_140;

  int *piStack_13c;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ auStack_130 [2];

  int local_128;

  int iStack_124;

  int local_120;

  uint8_t uStack_118;

  uint8_t uStack_117;

  uint8_t uStack_116;

  int local_114;

  int aiStack_110 [2];

  int iStack_108;

  int iStack_104;

  uint8_t uStack_100;

  uint8_t uStack_f8;

  uint8_t uStack_f7;

  uint8_t uStack_f6;

  uint32_t /* width from decompiler */ uStack_f4;

  uint32_t /* width from decompiler */ auStack_f0 [2];

  int iStack_e8;

  int iStack_e4;

  uint8_t uStack_e0;

  uint8_t uStack_d8;

  uint8_t uStack_d7;

  uint8_t uStack_d6;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ auStack_d0 [2];

  int iStack_c8;

  int iStack_c4;

  uint8_t uStack_c0;

  uint8_t uStack_b8;

  uint8_t uStack_b7;

  uint8_t uStack_b6;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ auStack_b0 [2];

  int iStack_a8;

  int iStack_a4;

  uint8_t uStack_a0;

  uint8_t uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  int aiStack_90 [2];

  int iStack_88;

  int iStack_84;

  uint8_t uStack_80;

  uint8_t uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ auStack_70 [2];

  int iStack_68;

  int iStack_64;

  uint8_t uStack_60;

  uint8_t uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint8_t uStack_4c;

  int iStack_48;

  int iStack_44;

  uint8_t uStack_40;

  uint8_t uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint8_t uStack_30;

  uint8_t uStack_2c;

  uint8_t uStack_28;

  char *pcStack_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb3ae;

  local_c = ExceptionList;

  iVar7 = *(int *)(param_1 + 0xe98);

  if ((((iVar7 == 0) || (piVar1 = *(int **)(iVar7 + 0xcbc), piVar1 == (int *)0x0)) ||

      (iVar7 = *(int *)(iVar7 + 0x250), iVar7 == 0)) || (*(int *)(iVar7 + 0x2b0) == 0)) {

    return 1;

  }

  piVar2 = *(int **)(iVar7 + 0x2b0);

  local_120 = piVar2[5] * piVar2[7];

  local_14c = piVar2[5] * piVar2[6];

  local_128 = piVar1[5] * piVar1[7];

  local_154 = piVar1[5] * piVar1[6];

  puVar10 = (uint32_t /* width from decompiler */ *)0x1;

  ppiStack_1ac = (int **)0x9550c2;

  ExceptionList = &local_c;

  local_190[0] = piVar1;

  local_114 = param_1;

  local_170 = FUN_0040fb90();

  local_16c = 0;

  local_4 = 0;

  ppiStack_1ac = &local_174;

  puStack_1b0 = (uint32_t /* width from decompiler */ *)0x9550dd;

  (**(code **)(*piVar2 + 0xc))();

  puStack_1b0 = (uint32_t /* width from decompiler */ *)0x9550e6;

  uStack_168 = FUN_0040fb90();

  uStack_164 = 0;

  puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

  puStack_1b0 = &local_16c;

  uStack_1b4 = 0x955101;

  (**(code **)(*piVar1 + 0xc))();

  uStack_1b4 = 0;

  puStack_1c8 = (uint8_t *)&puStack_1c0;

  puStack_1c4 = &local_170;

  uStack_1cc = 0x955116;

  FUN_00402410();

  local_c._0_1_ = 2;

  puStack_184 = (uint8_t *)&uStack_1cc;

  piStack_1d8 = (int *)0x955132;

  FUN_00402410();

  local_c = (void *)CONCAT31(local_c._1_3_,1);

  FUN_00931870();

  piStack_1d8 = (int *)0x95514d;

  _Str = strtok((char *)0x0,pcStack_1c);

  if (_Str != (char *)0x0) {

    puVar10 = (uint32_t /* width from decompiler */ *)atoi(_Str);

  }

  puVar3 = puStack_1c0;

  if (0 < (int)puVar10) {

    do {

      while (puStack_1b0 = puVar10, ppiStack_1ac = (int **)puVar3, ppiStack_1ac != &puStack_1c0) {

        piVar1 = ppiStack_1ac[2];

        if (piVar1 != (int *)0x0) {

          uVar4 = (**(code **)(*piVar1 + 0x250))();

          local_174 = (int *)CONCAT31(local_174._1_3_,uVar4);

          uVar4 = (**(code **)(*piVar1 + 0x254))();

          uStack_17c = CONCAT31(uStack_17c._1_3_,uVar4);

          CVOGReaction_RandomUnitScalar();

          uVar6 = FUN_00424830();

          if ((uVar6 & 1) == 0) {

            CVOGReaction_RandomUnitScalar();

            uVar6 = FUN_00424830();

            piStack_13c = (int *)CONCAT31(piStack_13c._1_3_,(char)(uVar6 % local_170));

            CVOGReaction_RandomUnitScalar();

            uVar6 = FUN_00424830();

            piVar2 = piStack_13c;

            uStack_134 = CONCAT31(uStack_134._1_3_,(char)(uVar6 % uStack_144));

            piStack_1d8 = piStack_13c;

            uStack_1e0 = 0x95521a;

            piStack_1dc = piVar1;

            cVar5 = FUN_005715d0();

            while ((cVar5 == '\0' && (iStack_1bc < 0x3d))) {

              iVar7 = CVOGReaction_RandomUnitScalar();

              iVar7 = *(int *)(iVar7 + 0x14);

              if (*(int *)(iVar7 + 0x9c4) == 0) {

                FUN_004248c0();

              }

              *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

              *(int *)(iVar7 + 0x9c0) = *(int *)(iVar7 + 0x9c0) + 4;

              iVar7 = CVOGReaction_RandomUnitScalar();

              iVar7 = *(int *)(iVar7 + 0x14);

              if (*(int *)(iVar7 + 0x9c4) == 0) {

                FUN_004248c0();

              }

              *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

              *(int *)(iVar7 + 0x9c0) = *(int *)(iVar7 + 0x9c0) + 4;

              iStack_1bc = iStack_1bc + 1;

              piStack_1d8 = piVar2;

              uStack_1e0 = 0x955282;

              piStack_1dc = piVar1;

              cVar5 = FUN_005715d0();

            }

            piStack_1d8 = piVar2;

            iStack_1bc = 0;

            uStack_1e0 = 0x95529e;

            piStack_1dc = piVar1;

            cVar5 = FUN_005715d0();

            if (cVar5 != '\0') {

              (**(code **)(*piVar1 + 0x25c))();

              piStack_1dc = (int *)0x9552bc;

              piStack_1d8 = piVar1;

              iVar7 = FUN_00571b80();

              if (iVar7 != 0) {

                (**(code **)(*piVar1 + 0x25c))();

                piStack_1d8 = piVar2;

                uStack_1e0 = 0x9552da;

                piStack_1dc = piVar1;

                cVar5 = FUN_00571620();

                if (cVar5 == '\0') {

                  (**(code **)(*piVar1 + 0x25c))();

LAB_009555d9:

                  uStack_1e0 = 0x9555df;

                  piStack_1dc = piVar1;

                  piStack_1d8 = local_174;

                  FUN_00571620();

                }

                else {

                  uStack_a0 = (uint8_t)piVar1[0x5a];

                  iStack_a8 = piVar1[0x58];

                  iStack_a4 = piVar1[0x59];

                  auStack_b0[0] = 0x2038;

                  uStack_98 = 1;

                  uStack_94 = (**(code **)(*piVar1 + 0x25c))();

                  piStack_1d8 = (int *)0x955348;

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_b0);

                  local_128 = piVar1[0x58];

                  iStack_124 = piVar1[0x59];

                  local_120 = CONCAT31(local_120._1_3_,(char)piVar1[0x5a]);

                  uStack_118 = piStack_13c._0_1_;

                  auStack_130[0] = 0x203a;

                  uStack_117 = (uint8_t)uStack_134;

                  uStack_116 = 1;

                  local_114 = (**(code **)(*piVar1 + 0x25c))();

                  puVar10 = auStack_130;

LAB_009553bb:

                  piStack_1d8 = (int *)0x9553cc;

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,puVar10);

                }

              }

            }

          }

          else if ((uVar6 & 1) == 1) {

            CVOGReaction_RandomUnitScalar();

            uVar6 = FUN_00424830();

            piStack_148 = (int *)CONCAT31(piStack_148._1_3_,(char)(uVar6 % uStack_178));

            CVOGReaction_RandomUnitScalar();

            uVar6 = FUN_00424830();

            piVar2 = piStack_148;

            uStack_140 = CONCAT31(uStack_140._1_3_,(char)(uVar6 % local_14c));

            piStack_1d8 = piStack_148;

            uStack_1e0 = 0x95544c;

            piStack_1dc = piVar1;

            cVar5 = FUN_005715d0();

            while ((cVar5 == '\0' && (iStack_1bc < 0x3d))) {

              CVOGReaction_RandomUnitScalar();

              FUN_00424830();

              CVOGReaction_RandomUnitScalar();

              FUN_00424830();

              iStack_1bc = iStack_1bc + 1;

              piStack_1d8 = piVar2;

              uStack_1e0 = 0x955482;

              piStack_1dc = piVar1;

              cVar5 = FUN_005715d0();

            }

            piStack_1d8 = piVar2;

            iStack_1bc = 0;

            uStack_1e0 = 0x95549a;

            piStack_1dc = piVar1;

            cVar5 = FUN_005715d0();

            if (cVar5 != '\0') {

              (**(code **)(*piVar1 + 0x25c))();

              piStack_1dc = (int *)0x9554ba;

              piStack_1d8 = piVar1;

              iVar7 = FUN_00571b80();

              if (iVar7 != 0) {

                (**(code **)(*piVar1 + 0x25c))();

                piStack_1d8 = piVar2;

                uStack_1e0 = 0x9554da;

                piStack_1dc = piVar1;

                cVar5 = FUN_00571620();

                if (cVar5 == '\0') {

                  (**(code **)(*piVar1 + 0x25c))();

                  goto LAB_009555d9;

                }

                uStack_60 = (uint8_t)piVar1[0x5a];

                iStack_68 = piVar1[0x58];

                iStack_64 = piVar1[0x59];

                auStack_70[0] = 0x2038;

                uStack_58 = 1;

                uStack_54 = (**(code **)(*piVar1 + 0x25c))();

                piStack_1d8 = (int *)0x955548;

                Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_70);

                uStack_e0 = (uint8_t)piVar1[0x5a];

                iStack_e8 = piVar1[0x58];

                iStack_e4 = piVar1[0x59];

                uStack_d8 = piStack_148._0_1_;

                auStack_f0[0] = 0x203a;

                uStack_d7 = (uint8_t)uStack_140;

                uStack_d6 = 3;

                uStack_d4 = (**(code **)(*piVar1 + 0x25c))();

                puVar10 = auStack_f0;

                goto LAB_009553bb;

              }

            }

          }

        }

        puVar10 = puStack_1b0;

        puVar3 = *ppiStack_1ac;

      }

      ppiStack_1ac = (int **)*ppiStack_188;

      if (ppiStack_1ac != ppiStack_188) {

        do {

          piVar1 = ppiStack_1ac[2];

          if (piVar1 != (int *)0x0) {

            uVar4 = (**(code **)(*piVar1 + 0x250))();

            unaff_EBP = (int *)CONCAT31((int3)((uint)unaff_EBP >> 8),uVar4);

            uVar4 = (**(code **)(*piVar1 + 0x254))();

            uStack_150 = CONCAT31(uStack_150._1_3_,uVar4);

            iVar7 = CVOGReaction_RandomUnitScalar();

            iVar7 = *(int *)(iVar7 + 0x14);

            if (*(int *)(iVar7 + 0x9c4) == 0) {

              FUN_004248c0();

            }

            *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

            uVar6 = **(uint **)(iVar7 + 0x9c0);

            *(uint **)(iVar7 + 0x9c0) = *(uint **)(iVar7 + 0x9c0) + 1;

            uVar6 = uVar6 ^ uVar6 >> 0xb;

            uVar6 = uVar6 ^ (uVar6 & 0xff3a58ad) << 7;

            uVar6 = uVar6 ^ (uVar6 & 0xffffdf8c) << 0xf;

            uVar6 = (uVar6 >> 0x12 ^ uVar6) & 1;

            if (uVar6 == 0) {

              CVOGReaction_RandomUnitScalar();

              uVar6 = FUN_00424830();

              uVar4 = (uint8_t)(uVar6 % uStack_178);

              unaff_ESI = (int *)CONCAT31((int3)((uint)unaff_ESI >> 8),uVar4);

              CVOGReaction_RandomUnitScalar();

              uVar6 = FUN_00424830();

              uVar6 = uVar6 % local_14c;

              uStack_1e0 = 0x9556de;

              piStack_1dc = piVar1;

              piStack_1d8 = unaff_ESI;

              cVar5 = FUN_005715d0();

              while ((cVar5 == '\0' && (iStack_1bc < 0x3d))) {

                if ((DAT_00d20c34 & 1) == 0) {

                  DAT_00d20c34 = DAT_00d20c34 | 1;

                  uStack_28 = 4;

                  _DAT_00d20c1c = &PTR_FUN_00a97168;

                  DAT_00d20c20 = '\0';

                  DAT_00d20c24 = 0;

                  _DAT_00d20c28 = 0;

                  _DAT_00d20c2c = 0;

                  DAT_00d20c30 = (uint *)0x0;

                  tVar11 = time((time_t *)0x0);

                  piStack_1d8 = (int *)0x955755;

                  puVar8 = operator_new(0x9c8);

                  uStack_28 = 5;

                  if (puVar8 == (uint *)0x0) {

                    puVar8 = (uint *)0x0;

                  }

                  else {

                    iVar7 = 1;

                    *puVar8 = (uint)tVar11;

                    puVar9 = puVar8;

                    do {

                      puVar9[1] = (*puVar9 >> 0x1e ^ *puVar9) * 0x6c078965 + iVar7;

                      iVar7 = iVar7 + 1;

                      puVar9 = puVar9 + 1;

                    } while (iVar7 < 0x270);

                    FUN_004248c0();

                  }

                  uStack_28 = 4;

                  DAT_00d20c30 = puVar8;

                  if (DAT_00d20c20 == '\0') {

                    FUN_007a4200();

                  }

                  _atexit((_func_4879 *)&LAB_009c30c0);

                  uStack_28 = 1;

                }

                puVar9 = DAT_00d20c30;

                puVar8 = DAT_00d20c30 + 0x271;

                if (DAT_00d20c30[0x271] == 0) {

                  FUN_004248c0();

                }

                *puVar8 = *puVar8 - 1;

                puVar9[0x270] = puVar9[0x270] + 4;

                if ((DAT_00d20c34 & 1) == 0) {

                  DAT_00d20c34 = DAT_00d20c34 | 1;

                  uStack_28 = 6;

                  _DAT_00d20c1c = &PTR_FUN_00a97168;

                  DAT_00d20c20 = '\0';

                  DAT_00d20c24 = 0;

                  _DAT_00d20c28 = 0;

                  _DAT_00d20c2c = 0;

                  DAT_00d20c30 = (uint *)0x0;

                  tVar11 = time((time_t *)0x0);

                  piStack_1d8 = (int *)0x955853;

                  puVar8 = operator_new(0x9c8);

                  uStack_28 = 7;

                  if (puVar8 == (uint *)0x0) {

                    puVar8 = (uint *)0x0;

                  }

                  else {

                    iVar7 = 1;

                    *puVar8 = (uint)tVar11;

                    puVar9 = puVar8;

                    do {

                      puVar9[1] = (*puVar9 >> 0x1e ^ *puVar9) * 0x6c078965 + iVar7;

                      iVar7 = iVar7 + 1;

                      puVar9 = puVar9 + 1;

                    } while (iVar7 < 0x270);

                    FUN_004248c0();

                  }

                  uStack_28 = 6;

                  DAT_00d20c30 = puVar8;

                  if (DAT_00d20c20 == '\0') {

                    FUN_007a4200();

                  }

                  _atexit((_func_4879 *)&LAB_009c30c0);

                  uStack_28 = 1;

                }

                puVar9 = DAT_00d20c30;

                puVar8 = DAT_00d20c30 + 0x271;

                if (DAT_00d20c30[0x271] == 0) {

                  FUN_004248c0();

                }

                *puVar8 = *puVar8 - 1;

                puVar9[0x270] = puVar9[0x270] + 4;

                iStack_1bc = iStack_1bc + 1;

                uStack_1e0 = 0x955913;

                piStack_1dc = piVar1;

                piStack_1d8 = unaff_ESI;

                cVar5 = FUN_005715d0();

              }

              iStack_1bc = 0;

              uStack_1e0 = 0x95593b;

              piStack_1dc = piVar1;

              piStack_1d8 = unaff_ESI;

              cVar5 = FUN_005715d0();

              if (cVar5 != '\0') {

                (**(code **)(*piVar1 + 0x25c))();

                piStack_1dc = (int *)0x955959;

                piStack_1d8 = piVar1;

                iVar7 = FUN_00571b80();

                if (iVar7 != 0) {

                  (**(code **)(*piVar1 + 0x25c))();

                  uStack_1e0 = 0x955977;

                  piStack_1dc = piVar1;

                  piStack_1d8 = unaff_ESI;

                  cVar5 = FUN_00571620();

                  if (cVar5 == '\0') {

                    (**(code **)(*piVar1 + 0x25c))();

LAB_00955cb9:

                    uStack_1e0 = 0x955cbf;

                    piStack_1dc = piVar1;

                    piStack_1d8 = unaff_EBP;

                    FUN_00571620();

                  }

                  else {

                    uStack_80 = (uint8_t)piVar1[0x5a];

                    iStack_88 = piVar1[0x58];

                    iStack_84 = piVar1[0x59];

                    aiStack_90[0] = 0x2038;

                    uStack_78 = 3;

                    uStack_74 = (**(code **)(*piVar1 + 0x25c))();

                    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

                      piStack_1d8 = aiStack_90;

                      piStack_1dc = (int *)0xffffffff;

                      uStack_1e0 = 0x9559e8;

                      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))();

                    }

                    uStack_100 = (uint8_t)piVar1[0x5a];

                    iStack_108 = piVar1[0x58];

                    iStack_104 = piVar1[0x59];

                    aiStack_110[0] = 0x203a;

                    uStack_f6 = 3;

                    uStack_f8 = uVar4;

                    uStack_f7 = (char)uVar6;

                    uStack_f4 = (**(code **)(*piVar1 + 0x25c))();

                    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

                      piStack_1d8 = aiStack_110;

                      piStack_1dc = (int *)0xffffffff;

                      uStack_1e0 = 0x955a6d;

                      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))();

                    }

                  }

                }

              }

            }

            else if (uVar6 == 1) {

              CVOGReaction_RandomUnitScalar();

              uVar6 = FUN_00424830();

              piStack_160 = (int *)CONCAT31(piStack_160._1_3_,(char)(uVar6 % local_170));

              CVOGReaction_RandomUnitScalar();

              uVar6 = FUN_00424830();

              piVar2 = piStack_160;

              uStack_180 = CONCAT31(uStack_180._1_3_,(char)(uVar6 % uStack_144));

              piStack_1d8 = piStack_160;

              uStack_1e0 = 0x955ae2;

              piStack_1dc = piVar1;

              cVar5 = FUN_005715d0();

              while ((cVar5 == '\0' && (iStack_1bc < 0x3d))) {

                iVar7 = CVOGReaction_RandomUnitScalar();

                iVar7 = *(int *)(iVar7 + 0x14);

                if (*(int *)(iVar7 + 0x9c4) == 0) {

                  FUN_004248c0();

                }

                *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

                *(int *)(iVar7 + 0x9c0) = *(int *)(iVar7 + 0x9c0) + 4;

                iVar7 = CVOGReaction_RandomUnitScalar();

                iVar7 = *(int *)(iVar7 + 0x14);

                if (*(int *)(iVar7 + 0x9c4) == 0) {

                  FUN_004248c0();

                }

                *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

                *(int *)(iVar7 + 0x9c0) = *(int *)(iVar7 + 0x9c0) + 4;

                iStack_1bc = iStack_1bc + 1;

                piStack_1d8 = piVar2;

                uStack_1e0 = 0x955b48;

                piStack_1dc = piVar1;

                cVar5 = FUN_005715d0();

              }

              piStack_1d8 = piVar2;

              iStack_1bc = 0;

              uStack_1e0 = 0x955b62;

              piStack_1dc = piVar1;

              cVar5 = FUN_005715d0();

              if (cVar5 != '\0') {

                (**(code **)(*piVar1 + 0x25c))();

                piStack_1dc = (int *)0x955b82;

                piStack_1d8 = piVar1;

                iVar7 = FUN_00571b80();

                if (iVar7 != 0) {

                  (**(code **)(*piVar1 + 0x25c))();

                  piStack_1d8 = piVar2;

                  uStack_1e0 = 0x955ba2;

                  piStack_1dc = piVar1;

                  cVar5 = FUN_00571620();

                  if (cVar5 == '\0') {

                    (**(code **)(*piVar1 + 0x25c))();

                    goto LAB_00955cb9;

                  }

                  CVOGReaction_RandomUnitScalar();

                  FUN_00424830();

                  uStack_40 = (uint8_t)piVar1[0x5a];

                  iStack_48 = piVar1[0x58];

                  iStack_44 = piVar1[0x59];

                  uStack_50 = 0x2038;

                  uStack_38 = 3;

                  uStack_34 = (**(code **)(*piVar1 + 0x25c))();

                  piStack_1d8 = (int *)0x955c1d;

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,&uStack_50);

                  uStack_c0 = (uint8_t)piVar1[0x5a];

                  iStack_c8 = piVar1[0x58];

                  iStack_c4 = piVar1[0x59];

                  uStack_b8 = piStack_160._0_1_;

                  auStack_d0[0] = 0x203a;

                  uStack_b7 = (uint8_t)uStack_180;

                  uStack_b6 = 1;

                  uStack_b4 = (**(code **)(*piVar1 + 0x25c))();

                  piStack_1d8 = (int *)0x955c9a;

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_d0);

                }

              }

            }

          }

          ppiStack_1ac = (int **)*ppiStack_1ac;

        } while (ppiStack_1ac != ppiStack_188);

      }

      Client_RefreshOpenMissionUiWindows();

      FUN_0092ce90();

      puStack_1b0 = (uint32_t /* width from decompiler */ *)((int)puStack_1b0 + -1);

      puVar3 = puStack_1c0;

      puVar10 = puStack_1b0;

    } while (puStack_1b0 != (uint32_t /* width from decompiler */ *)0x0);

  }

  uStack_158 = FUN_0040fb90();

  local_154 = 0;

  uStack_28 = 8;

  (**(code **)(*piStack_1b8 + 0xc))();

  local_16c = FUN_0040fb90();

  uStack_168 = 0;

  uStack_2c = 9;

  piStack_1d8 = (int *)0x955d41;

  (**(code **)(*piStack_1b8 + 0xc))();

  piStack_1d8 = (int *)0x1;

  puStack_1ec = auStack_1e4;

  ppiStack_1e8 = &local_174;

  uStack_1f0 = 0x955d57;

  FUN_00402410();

  uStack_30 = 10;

  piStack_1b8 = &uStack_1f0;

  puStack_1f8 = (uint8_t *)&uStack_1f0;

  puStack_1f4 = &uStack_164;

  uStack_1fc = 0x955d76;

  FUN_00402410();

  uStack_30 = 9;

  puStack_1f4 = (uint32_t /* width from decompiler */ *)0x955d82;

  FUN_00931870();

  puStack_1c0 = &uStack_1fc;

  puStack_204 = (uint8_t *)&uStack_1fc;

  ppiStack_200 = local_190;

  uStack_208 = 0x955d96;

  FUN_00402410();

  uStack_4c = 0xc;

  puStack_210 = (uint8_t *)&uStack_208;

  puStack_20c = &uStack_180;

  uStack_214 = 0x955db5;

  FUN_00402410();

  uStack_4c = 0xd;

  puStack_21c = (uint8_t *)&uStack_214;

  ppuStack_218 = &puStack_1b0;

  uStack_220 = 0x955dd1;

  FUN_00402410();

  uStack_4c = 0xe;

  FUN_00402410(&uStack_220,&iStack_1bc);

  uStack_4c = 9;

  FUN_0093bf60(uStack_15c);

  uStack_80 = 8;

  FUN_00404060();

                    /* WARNING: Subroutine does not return */

  operator_delete(puStack_1c0);

}
