// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0088ad60
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ad60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
// Address:   0x0088ad60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs: callee helper. Evidence string: "i_d_s_2d_wnd_icon_default.dds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_s_2d_wnd_icon_default.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~421 non-empty decompiler lines.
//  - Control keywords: if×35, while×18, do×11, for×5, goto×4, return×1.
//  - Notable callees: PathFileExistsA×2, FUN_00406320, FUN_004c77b0, FUN_007b6420, FUN_007b66c0, FUN_007b6a20, FUN_0088a700, FUN_0088ac20.
//  - Strings: "i_d_s_2d_wnd_icon_default.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0088ad60(int *param_1,char param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float fVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char cVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  BOOL BVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uVar12;

  int iVar13;

  float *pfVar14;

  uint uVar15;

  uint uVar16;

  char *pcVar17;

  int *piVar18;

  int iVar19;

  uint32_t /* width from decompiler */ *puVar20;

  int *piVar21;

  char *pcVar22;

  float10 fVar23;

  byte bStack_2c4;

  byte bStack_2c3;

  byte bStack_2c2;

  char cStack_2c1;

  int *piStack_2c0;

  uint32_t /* width from decompiler */ uStack_2bc;

  float fStack_2b8;

  int aiStack_2b4 [2];

  int iStack_2ac;

  float fStack_2a8;

  float fStack_2a4;

  float fStack_2a0;

  float fStack_29c;

  float fStack_298;

  float fStack_294;

  float fStack_290;

  int iStack_28c;

  int iStack_288;

  int iStack_284;

  int iStack_280;

  int iStack_27c;

  int iStack_278;

  int iStack_274;

  int *piStack_268;

  int iStack_258;

  int aiStack_254 [2];

  uint8_t auStack_24c [12];

  uint8_t auStack_240 [8];

  uint8_t auStack_238 [4];

  uint8_t auStack_234 [12];

  uint8_t auStack_228 [8];

  uint8_t auStack_220 [8];

  uint8_t auStack_218 [4];

  uint8_t auStack_214 [11];

  char cStack_209;

  char acStack_208 [4];

  char acStack_204 [4];

  char acStack_200 [4];

  char acStack_1fc [4];

  char acStack_1f8 [2];

  char cStack_1f6;

  char cStack_105;

  char acStack_104 [260];

  

  cVar6 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar6 != '\0') {

    cStack_2c1 = param_3;

    if (param_2 != '\0') {

      piVar21 = *(int **)param_1[0x149];

      piStack_2c0 = piVar21;

      if (piVar21 != (int *)param_1[0x149]) {

        do {

          iVar7 = param_1[0x14c];

          if (iVar7 != param_1[0x14d]) {

            do {

              if (*(int *)(iVar7 + 0x14) == piVar21[4]) goto LAB_0088aff6;

              iVar7 = iVar7 + 0x18;

            } while (iVar7 != param_1[0x14d]);

          }

          FUN_0088ac20();

          piVar18 = piStack_268;

          iStack_258 = piVar21[3];

          aiStack_254[0] = piVar21[4];

          if ((iStack_258 != 0) && (piStack_268 != (int *)0x0)) {

            acStack_204[0] = s_i_d_s_2d_wnd_icon__00a540d0[4];

            acStack_204[1] = s_i_d_s_2d_wnd_icon__00a540d0[5];

            acStack_204[2] = s_i_d_s_2d_wnd_icon__00a540d0[6];

            acStack_204[3] = s_i_d_s_2d_wnd_icon__00a540d0[7];

            acStack_208[0] = s_i_d_s_2d_wnd_icon__00a540d0[0];

            acStack_208[1] = s_i_d_s_2d_wnd_icon__00a540d0[1];

            acStack_208[2] = s_i_d_s_2d_wnd_icon__00a540d0[2];

            acStack_208[3] = s_i_d_s_2d_wnd_icon__00a540d0[3];

            acStack_1fc[0] = s_i_d_s_2d_wnd_icon__00a540d0[0xc];

            acStack_1fc[1] = s_i_d_s_2d_wnd_icon__00a540d0[0xd];

            acStack_1fc[2] = s_i_d_s_2d_wnd_icon__00a540d0[0xe];

            acStack_1fc[3] = s_i_d_s_2d_wnd_icon__00a540d0[0xf];

            acStack_200[0] = s_i_d_s_2d_wnd_icon__00a540d0[8];

            acStack_200[1] = s_i_d_s_2d_wnd_icon__00a540d0[9];

            acStack_200[2] = s_i_d_s_2d_wnd_icon__00a540d0[10];

            acStack_200[3] = s_i_d_s_2d_wnd_icon__00a540d0[0xb];

            pcVar8 = (char *)(iStack_258 + 0x5ca);

            cStack_1f6 = s_i_d_s_2d_wnd_icon__00a540d0[0x12];

            acStack_1f8[0] = s_i_d_s_2d_wnd_icon__00a540d0[0x10];

            acStack_1f8[1] = s_i_d_s_2d_wnd_icon__00a540d0[0x11];

            pcVar9 = pcVar8;

            do {

              cVar6 = *pcVar9;

              pcVar9 = pcVar9 + 1;

            } while (cVar6 != '\0');

            pcVar22 = &cStack_209;

            do {

              pcVar17 = pcVar22 + 1;

              pcVar22 = pcVar22 + 1;

            } while (*pcVar17 != '\0');

            pcVar17 = pcVar8;

            for (uVar15 = (uint)((int)pcVar9 - (int)pcVar8) >> 2; uVar15 != 0; uVar15 = uVar15 - 1)

            {

              *(uint32_t /* width from decompiler */ *)pcVar22 = *(uint32_t /* width from decompiler */ *)pcVar17;

              pcVar17 = pcVar17 + 4;

              pcVar22 = pcVar22 + 4;

            }

            for (uVar15 = (int)pcVar9 - (int)pcVar8 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

              *pcVar22 = *pcVar17;

              pcVar17 = pcVar17 + 1;

              pcVar22 = pcVar22 + 1;

            }

            pcVar9 = &cStack_209;

            do {

              pcVar8 = pcVar9 + 1;

              pcVar9 = pcVar9 + 1;

            } while (*pcVar8 != '\0');

            *(uint32_t /* width from decompiler */ *)pcVar9 = DAT_00a540cc;

            pcVar9 = &cStack_209;

            do {

              pcVar8 = pcVar9;

              pcVar9 = pcVar8 + 1;

            } while (pcVar8[1] != '\0');

            *(uint32_t /* width from decompiler */ *)(pcVar8 + 1) = DAT_00a2c53c;

            pcVar8[5] = DAT_00a2c540;

            aiStack_2b4[0] = FUN_007b6a20();

            if ((*(byte *)(aiStack_2b4[0] + 4) & 1) == 0) {

LAB_0088af8e:

              cVar6 = FUN_007b66c0(aiStack_2b4[0]);

              piVar21 = piStack_2c0;

              piVar18 = piStack_268;

              if (cVar6 == '\0') {

                pcVar9 = "i_d_s_2d_wnd_icon_default.dds";

                pcVar8 = acStack_208;

                for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {

                  *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar9;

                  pcVar9 = pcVar9 + 4;

                  pcVar8 = pcVar8 + 4;

                }

                *(uint16_t *)pcVar8 = *(uint16_t *)pcVar9;

              }

            }

            else {

              BVar10 = PathFileExistsA(acStack_208);

              if (BVar10 == 0) {

                pcVar9 = (char *)FUN_007b6420();

                pcVar8 = (char *)&DAT_00d1e574;

                do {

                  pcVar22 = pcVar8;

                  if (0xf < *(uint *)(pcVar8 + 0x14)) {

                    pcVar22 = *(char **)pcVar8;

                  }

                  pcVar17 = acStack_104;

                  do {

                    cVar6 = *pcVar22;

                    *pcVar17 = cVar6;

                    pcVar22 = pcVar22 + 1;

                    pcVar17 = pcVar17 + 1;

                    pcVar11 = pcVar9;

                  } while (cVar6 != '\0');

                  do {

                    cVar6 = *pcVar11;

                    pcVar11 = pcVar11 + 1;

                  } while (cVar6 != '\0');

                  uVar15 = (int)pcVar11 - (int)pcVar9;

                  pcVar22 = &cStack_105;

                  do {

                    pcVar17 = pcVar22 + 1;

                    pcVar22 = pcVar22 + 1;

                  } while (*pcVar17 != '\0');

                  pcVar17 = pcVar9;

                  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

                    *(uint32_t /* width from decompiler */ *)pcVar22 = *(uint32_t /* width from decompiler */ *)pcVar17;

                    pcVar17 = pcVar17 + 4;

                    pcVar22 = pcVar22 + 4;

                  }

                  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

                    *pcVar22 = *pcVar17;

                    pcVar17 = pcVar17 + 1;

                    pcVar22 = pcVar22 + 1;

                  }

                  BVar10 = PathFileExistsA(acStack_104);

                  piVar21 = piStack_2c0;

                  piVar18 = piStack_268;

                  if (BVar10 != 0) goto LAB_0088afc0;

                  pcVar8 = pcVar8 + 0x1c;

                } while ((int)pcVar8 < 0xd1e7a4);

                goto LAB_0088af8e;

              }

            }

LAB_0088afc0:

            iVar7 = *piVar18;

            uVar12 = (**(code **)(iVar7 + 0x2c8))(0);

            (**(code **)(iVar7 + 0x50))(acStack_208,uVar12);

          }

          FUN_00406320();

          cStack_2c1 = '\x01';

LAB_0088aff6:

          if (*(char *)((int)piVar21 + 0x15) == '\0') {

            piVar18 = (int *)piVar21[2];

            if (*(char *)((int)piVar18 + 0x15) == '\0') {

              cVar6 = *(char *)(*piVar18 + 0x15);

              piVar21 = piVar18;

              piVar18 = (int *)*piVar18;

              while (piStack_2c0 = piVar21, cVar6 == '\0') {

                cVar6 = *(char *)(*piVar18 + 0x15);

                piVar21 = piVar18;

                piVar18 = (int *)*piVar18;

              }

            }

            else {

              cVar6 = *(char *)(piVar21[1] + 0x15);

              piVar4 = (int *)piVar21[1];

              piVar18 = piVar21;

              while ((piVar21 = piVar4, piStack_2c0 = piVar21, cVar6 == '\0' &&

                     (piVar18 == (int *)piVar21[2]))) {

                cVar6 = *(char *)(piVar21[1] + 0x15);

                piVar4 = (int *)piVar21[1];

                piVar18 = piVar21;

              }

            }

          }

        } while (piVar21 != (int *)param_1[0x149]);

      }

      puVar20 = (uint32_t /* width from decompiler */ *)param_1[0x14c];

      if (puVar20 != (uint32_t /* width from decompiler */ *)param_1[0x14d]) {

        do {

          puVar1 = *(uint32_t /* width from decompiler */ **)param_1[0x149];

          while (puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x149]) {

            if (puVar1[4] == puVar20[5]) {

              puVar20 = puVar20 + 6;

              goto LAB_0088b128;

            }

            if (*(char *)((int)puVar1 + 0x15) == '\0') {

              puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

              if (*(char *)((int)puVar2 + 0x15) == '\0') {

                cVar6 = *(char *)((int)*puVar2 + 0x15);

                puVar1 = puVar2;

                puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

                while (cVar6 == '\0') {

                  cVar6 = *(char *)((int)*puVar2 + 0x15);

                  puVar1 = puVar2;

                  puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

                }

              }

              else {

                cVar6 = *(char *)((int)puVar1[1] + 0x15);

                puVar5 = (uint32_t /* width from decompiler */ *)puVar1[1];

                puVar2 = puVar1;

                while ((puVar1 = puVar5, cVar6 == '\0' && (puVar2 == (uint32_t /* width from decompiler */ *)puVar1[2]))) {

                  cVar6 = *(char *)((int)puVar1[1] + 0x15);

                  puVar5 = (uint32_t /* width from decompiler */ *)puVar1[1];

                  puVar2 = puVar1;

                }

              }

            }

          }

          FUN_0088a700();

          puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x14d];

          puVar5 = puVar20;

          puVar2 = puVar20;

          while (puVar2 = puVar2 + 6, puVar2 != puVar1) {

            *puVar5 = *puVar2;

            puVar5[1] = puVar2[1];

            puVar5[2] = puVar2[2];

            puVar5[3] = puVar2[3];

            puVar5[4] = puVar2[4];

            puVar5[5] = puVar2[5];

            puVar5 = puVar5 + 6;

          }

          param_1[0x14d] = param_1[0x14d] + -0x18;

          cStack_2c1 = '\x01';

LAB_0088b128:

        } while (puVar20 != (uint32_t /* width from decompiler */ *)param_1[0x14d]);

      }

    }

    piStack_2c0 = (int *)0x0;

    iStack_2ac = 0;

    while( true ) {

      iVar7 = 0;

      if (param_1[0x14c] != 0) {

        iVar7 = (param_1[0x14d] - param_1[0x14c]) / 0x18;

      }

      if (iVar7 <= (int)piStack_2c0) break;

      piVar21 = (int *)(param_1[0x14c] + iStack_2ac);

      if ((piVar21[5] != 0) && (piVar21[4] != 0)) {

        if (piVar21[1] != 0) {

          iVar7 = *(int *)(piVar21[4] + 8);

          fStack_290 = (float)(int)(g_dwClientTickMs - *(int *)(piVar21[4] + 0x14)) *

                       g_flMsToSeconds_Inferred;

          uStack_2bc = (float)iVar7;

          if (iVar7 < 0) {

            uStack_2bc = uStack_2bc + _DAT_00aaa5dc;

          }

          uStack_2bc = uStack_2bc * g_flMsToSeconds_Inferred;

          fStack_2a4 = fStack_290 / uStack_2bc;

          if (uStack_2bc == g_flZero) {

            fStack_2a4 = g_flOne;

          }

          (**(code **)(*(int *)piVar21[1] + 0x3b0))(fStack_2a4);

          fStack_29c = (float)piStack_2c0 - fStack_294;

          if (fStack_29c == g_flZero) {

            fStack_2b8 = g_flOne;

          }

          else {

            fVar23 = (float10)(**(code **)(*(int *)piVar21[1] + 0x3c0))();

            fStack_2b8 = (float)(fVar23 / (float10)fStack_29c);

          }

          (**(code **)(*(int *)piVar21[1] + 0x3b4))(fStack_2b8);

          (**(code **)(*(int *)piVar21[1] + 0x3ac))(0x3f800000);

        }

        iVar7 = (**(code **)(*(int *)piVar21[5] + 0x1ac))();

        if (iVar7 == 0) {

          fStack_2a8 = 0.0;

        }

        else {

          piVar18 = (int *)piVar21[5];

          iVar7 = (**(code **)(*piVar18 + 0x1b0))();

          uStack_2bc = (float)iVar7;

          iVar7 = (**(code **)(*piVar18 + 0x1ac))();

          fStack_2a8 = uStack_2bc / (float)iVar7;

        }

        if ((piVar21[2] != 0) &&

           (fVar23 = (float10)(**(code **)(*(int *)piVar21[2] + 0x3c8))(), fVar3 = fStack_2a8,

           (float10)fStack_2a8 != fVar23)) {

          (**(code **)(*(int *)piVar21[2] + 0x3ac))(fStack_2a8);

          FUN_004c77b0(aiStack_2b4,fVar3);

          (**(code **)(*(int *)piVar21[2] + 0x15c))(1,aiStack_2b4);

          bStack_2c3 = (byte)((uint)uStack_2bc >> 8) >> 3;

          bStack_2c2 = uStack_2bc._2_1_ >> 3;

          bStack_2c4 = (byte)((uint)uStack_2bc >> 3) & 0x1f;

          cStack_2c1 = -1;

          (**(code **)(*(int *)piVar21[2] + 0x15c))(0,&bStack_2c4);

          (**(code **)(*(int *)piVar21[2] + 0x34c))();

        }

        if (cStack_2c1 != '\0') {

          if (param_1[0x14f] == 0) {

            iVar7 = 0;

          }

          else {

            iVar7 = (**(code **)(*(int *)param_1[0x14f] + 0x120))(auStack_218,1,0);

            iVar7 = *(int *)(iVar7 + 4);

          }

          uVar15 = (uint)piStack_2c0 & 0x80000003;

          if ((int)uVar15 < 0) {

            uVar15 = (uVar15 - 1 | 0xfffffffc) + 1;

          }

          iVar19 = (int)((int)piStack_2c0 + ((int)piStack_2c0 >> 0x1f & 3U)) >> 2;

          if ((int *)*piVar21 != (int *)0x0) {

            iVar13 = (**(code **)(*(int *)*piVar21 + 0x124))(auStack_220);

            fStack_2a4 = (float)DAT_00d1e81c *

                         (*(float *)(iVar13 + 4) - (float)(int)(uVar15 * 0x42)) * DAT_00aaa678;

            pfVar14 = (float *)(**(code **)(*(int *)*piVar21 + 0x124))(auStack_214);

            iStack_28c = (int)fStack_2a8 + iVar7;

            fStack_290 = (float)(int)((float)DAT_00d1e818 * (*pfVar14 - (float)(iVar19 * 0x48)) *

                                     DAT_00aaa67c);

            (**(code **)(*(int *)*piVar21 + 0x110))(&fStack_290);

          }

          if (piVar21[1] != 0) {

            iVar13 = (**(code **)(*(int *)piVar21[1] + 0x124))(auStack_238);

            fStack_2a0 = (float)DAT_00d1e81c *

                         (*(float *)(iVar13 + 4) - (float)(int)(uVar15 * 0x42)) * DAT_00aaa678;

            pfVar14 = (float *)(**(code **)(*(int *)piVar21[1] + 0x124))(aiStack_254);

            iStack_274 = (int)fStack_2a4 + iVar7;

            iStack_278 = (int)((float)DAT_00d1e818 * (*pfVar14 - (float)(iVar19 * 0x48)) *

                              DAT_00aaa67c);

            (**(code **)(*(int *)piVar21[1] + 0x110))(&iStack_278);

          }

          if (piVar21[2] != 0) {

            iVar13 = (**(code **)(*(int *)piVar21[2] + 0x124))(auStack_228);

            fStack_298 = (float)DAT_00d1e81c *

                         (*(float *)(iVar13 + 4) - (float)(int)(uVar15 * 0x42)) * DAT_00aaa678;

            pfVar14 = (float *)(**(code **)(*(int *)piVar21[2] + 0x124))(auStack_24c);

            iStack_284 = (int)fStack_29c + iVar7;

            iStack_288 = (int)((float)DAT_00d1e818 * (*pfVar14 - (float)(iVar19 * 0x48)) *

                              DAT_00aaa67c);

            (**(code **)(*(int *)piVar21[2] + 0x110))(&iStack_288);

          }

          if (piVar21[3] != 0) {

            iVar13 = (**(code **)(*(int *)piVar21[3] + 0x124))(auStack_240);

            fStack_290 = (float)DAT_00d1e81c *

                         (*(float *)(iVar13 + 4) - (float)(int)(uVar15 * 0x42)) * DAT_00aaa678;

            pfVar14 = (float *)(**(code **)(*(int *)piVar21[3] + 0x124))(auStack_234);

            iStack_27c = (int)fStack_294 + iVar7;

            iStack_280 = (int)((float)DAT_00d1e818 * (*pfVar14 - (float)(iVar19 * 0x48)) *

                              DAT_00aaa67c);

            (**(code **)(*(int *)piVar21[3] + 0x110))(&iStack_280);

          }

          if ((int *)*piVar21 != (int *)0x0) {

            (**(code **)(*(int *)*piVar21 + 0x74))((int)piStack_2c0 + 0x9c48);

          }

          if (piVar21[3] != 0) {

            (**(code **)(*(int *)piVar21[3] + 0x74))((int)piStack_2c0 + 0x9c48);

          }

        }

      }

      piStack_2c0 = (int *)((int)piStack_2c0 + 1);

      iStack_2ac = iStack_2ac + 0x18;

    }

  }

  return;

}
