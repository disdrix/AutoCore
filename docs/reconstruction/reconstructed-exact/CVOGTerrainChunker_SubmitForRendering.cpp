// READABILITY (auto CF):
//  - Body size: ~234 non-empty decompiler lines.
//  - Control keywords: if×35, do×5, while×5, return×1.
//  - Notable callees: FUN_0076cef0×3, FUN_0076cf00×3, ABS×2, FUN_005c18a0×2, FUN_0075b390×2, FUN_0075b7f0×2, FUN_0075c960×2, CVOGTerrainChunker_SubmitForRendering.
//  - Strings: "CVOGTerrainChunker::SubmitForRendering"; "LOD calculations"; "Submit chunks".
//  - Return sites: 1.

// =============================================================================
// CVOGTerrainChunker_SubmitForRendering
// -----------------------------------------------------------------------------
// Stable ID: aa_005c1940
// Address:   0x005c1940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint __thiscall CVOGTerrainChunker_SubmitForRendering(int *param_1,int param_2)



{

  byte *pbVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  bool bVar8;

  bool bVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  int *piVar14;

  int iVar15;

  float fVar16;

  int local_50;

  int local_4c;

  uint local_48;

  uint local_44;

  float local_3c;

  int local_38;

  int local_34;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6d46;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CVOGTerrainChunker::SubmitForRendering");

  iVar12 = *(int *)(param_2 + 0x30);

  iVar10 = *(int *)(iVar12 + 8);

  local_4 = 0;

  if ((*(byte *)(iVar10 + 0xbc) & 1) != 0) {

    iVar10 = FUN_00972e50();

  }

  fVar2 = *(float *)(iVar10 + 0x30);

  iVar13 = *param_1;

  fVar3 = *(float *)(iVar10 + 0x38);

  fVar4 = *(float *)(iVar10 + 0x20);

  fVar5 = *(float *)(iVar10 + 0x28);

  iVar10 = *(int *)(iVar13 + 0x340);

  fVar16 = *(float *)(*(int *)(iVar10 + 0xe894) + 0x110);

  uVar6 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0xf4);

  if (fVar16 <= *(float *)(*(int *)(iVar10 + 0xe898) + 0x58) +

                *(float *)(*(int *)(iVar10 + 0xe898) + 0x54)) {

    fVar16 = *(float *)(*(int *)(iVar10 + 0xe898) + 0x58) +

             *(float *)(*(int *)(iVar10 + 0xe898) + 0x54);

  }

  if ((float)*(int *)(iVar13 + 0x10) * *(float *)(iVar13 + 0x18) <=

      (float)*(int *)(iVar13 + 0x14) * *(float *)(iVar13 + 0x18)) {

    iVar12 = *(int *)(iVar13 + 0x14);

  }

  else {

    iVar12 = *(int *)(iVar13 + 0x10);

  }

  fVar16 = (float)param_1[0x1d] * (float)iVar12 * *(float *)(iVar13 + 0x18) * DAT_00a0f298 + fVar16;

  FUN_0075b390(fVar16);

  FUN_0075b7f0();

  FUN_0076cf00("LOD calculations");

  iVar10 = param_1[1];

  iVar12 = param_1[2];

  local_4._0_1_ = 1;

  local_44 = 0;

  local_48 = 0;

  iVar13 = (int)((g_flOne / (float)param_1[0x10]) * fVar2);

  iVar15 = (int)((g_flOne / (float)param_1[0x10]) * fVar3);

  local_50 = iVar12;

  local_4c = iVar10;

  if (ABS(fVar4) <= ABS(fVar5)) {

    if (fVar5 < g_flZero) {

      local_50 = iVar15 + 2;

      if (iVar12 <= local_50) {

        local_50 = iVar12;

      }

    }

    else {

      local_48 = iVar15 - 2;

      local_48 = ((int)local_48 < 1) - 1 & local_48;

    }

  }

  else if (fVar4 < g_flZero) {

    iVar13 = iVar13 + 2;

    if (iVar13 < iVar10) {

      local_4c = iVar13;

    }

  }

  else {

    local_44 = iVar13 - 2;

    local_44 = ((int)local_44 < 1) - 1 & local_44;

  }

  local_34 = 0;

  if (0 < iVar12) {

    do {

      if ((local_34 < (int)local_48) || (bVar9 = false, local_50 < local_34)) {

        bVar9 = true;

      }

      local_38 = 0;

      if (0 < iVar10) {

        do {

          if (((local_38 < (int)local_44) || (local_4c < local_38)) || (bVar9)) {

            bVar8 = true;

          }

          else {

            bVar8 = false;

          }

          iVar12 = (iVar10 * local_34 + local_38) * 0xf0 + param_1[4];

          if (iVar12 != 0) {

            if ((!bVar8) &&

               (fVar4 = ((float)local_38 + DAT_00a0f298) * (float)param_1[0x10] - fVar2,

               fVar5 = ((float)local_34 + DAT_00a0f298) * (float)param_1[0x10] - fVar3,

               local_3c = SQRT(fVar4 * fVar4 + fVar5 * fVar5), fVar16 < local_3c)) {

              bVar8 = true;

            }

            if (*(int *)(iVar12 + 200) != 0) {

              pbVar1 = (byte *)(*(int *)(iVar12 + 200) + 0xc4);

              *pbVar1 = *pbVar1 | bVar8 == false;

            }

            *(bool *)(iVar12 + 0xd4) = bVar8;

            iVar10 = param_1[6];

            if (bVar8 == false) {

              iVar13 = 0;

              do {

                if (local_3c < (float)(&DAT_00af3f98)[iVar13 * 2] * (float)param_1[0x10]) {

                  iVar10 = *(int *)(iVar13 * 8 + 0xaf3f9c);

                  break;

                }

                iVar13 = iVar13 + 1;

              } while (iVar13 < 6);

            }

            *(int *)(iVar12 + 0xd8) = iVar10;

            if (iVar10 == param_1[6]) {

              *(uint32_t /* width from decompiler */ *)(iVar12 + 0xdc) = 0;

              FUN_005c18a0(param_1);

            }

            else if (*(int *)(iVar12 + 200) != 0) {

              *(uint8_t *)(*(int *)(iVar12 + 200) + 0xc5) = 1;

            }

          }

          iVar10 = param_1[1];

          local_38 = local_38 + 1;

        } while (local_38 < iVar10);

      }

      local_34 = local_34 + 1;

    } while (local_34 < param_1[2]);

  }

  local_4._0_1_ = 0;

  FUN_0076cef0();

  FUN_0076cf00("Submit chunks");

  local_4._0_1_ = 2;

  local_38 = 0;

  if (0 < param_1[0xb]) {

    local_4c = 0;

    do {

      piVar14 = (int *)(param_1[0xc] + local_4c);

      if ((char)piVar14[0x31] != '\0') {

        if (*(char *)((int)piVar14 + 0xc5) == '\0') {

          if (((piVar14[0x16] != 0) && (piVar14[0x17] != 0)) &&

             (*(int *)(piVar14[0x17] + 0x1c) != piVar14[0x18])) {

            (**(code **)(*piVar14 + 0x80))();

          }

          iVar12 = piVar14[0x19];

          if ((*(byte *)(piVar14 + 0x2f) & 1) != 0) {

            (**(code **)(*piVar14 + 0x5c))();

          }

          iVar12 = FUN_0075c960(piVar14 + 10,iVar12);

          if (iVar12 != -1) {

            (**(code **)(*piVar14 + 0x3c))(param_2);

          }

        }

        else {

          local_34 = 0;

          if (0 < param_1[0xe]) {

            do {

              piVar7 = *(int **)(piVar14[0x32] + local_34 * 4);

              if ((char)piVar7[0x35] == '\0') {

                iVar12 = piVar7[0x34];

                piVar7[0x37] = 0;

                iVar10 = param_1[1] * iVar12 + piVar7[0x33];

                if ((0 < iVar12) &&

                   (piVar7[0x36] < *(int *)((iVar10 - param_1[1]) * 0xf0 + 0xd8 + param_1[4]))) {

                  piVar7[0x37] = 1;

                }

                if ((iVar12 < param_1[2] + -1) &&

                   (piVar7[0x36] < *(int *)((param_1[1] + iVar10) * 0xf0 + 0xd8 + param_1[4]))) {

                  piVar7[0x37] = piVar7[0x37] | 2;

                }

                if ((0 < piVar7[0x33]) &&

                   (piVar7[0x36] < *(int *)(iVar10 * 0xf0 + -0x18 + param_1[4]))) {

                  piVar7[0x37] = piVar7[0x37] | 4;

                }

                if ((piVar7[0x33] < param_1[1] + -1) &&

                   (piVar7[0x36] < *(int *)(iVar10 * 0xf0 + 0x1c8 + param_1[4]))) {

                  piVar7[0x37] = piVar7[0x37] | 8;

                }

                FUN_005c18a0(param_1);

                if ((char)piVar7[0x35] == '\0') {

                  if (((piVar7[0x16] != 0) && (piVar7[0x17] != 0)) &&

                     (*(int *)(piVar7[0x17] + 0x1c) != piVar7[0x18])) {

                    (**(code **)(*piVar7 + 0x80))();

                  }

                  iVar12 = piVar7[0x19];

                  if ((*(byte *)(piVar7 + 0x2f) & 1) != 0) {

                    (**(code **)(*piVar7 + 0x5c))();

                  }

                  iVar12 = FUN_0075c960(piVar7 + 10,iVar12);

                  if (iVar12 != -1) {

                    (**(code **)(*piVar7 + 0x3c))(param_2);

                  }

                }

              }

              local_34 = local_34 + 1;

            } while (local_34 < param_1[0xe]);

          }

        }

      }

      local_4c = local_4c + 0xd8;

      local_38 = local_38 + 1;

      *(uint8_t *)(piVar14 + 0x31) = 0;

      *(uint8_t *)((int)piVar14 + 0xc5) = 0;

    } while (local_38 < param_1[0xb]);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0076cef0();

  FUN_0075b390(uVar6);

  FUN_0075b7f0();

  local_4 = 0xffffffff;

  uVar11 = FUN_0076cef0();

  ExceptionList = pvStack_c;

  return uVar11 & 0xffffff00;

}
