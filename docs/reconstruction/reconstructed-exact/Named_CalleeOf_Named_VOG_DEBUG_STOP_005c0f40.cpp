// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005c0f40
// -----------------------------------------------------------------------------
// Stable ID: aa_005c0f40
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005c0f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Compressed Texture copy". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Compressed Texture copy"
//   - "NDDiffTerrainLayered2.fx"
//   - "DiffuseTexture"
//   - "black.dds"
//   - "GlowTexture"
//   - "fEdgeMaxX"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~386 non-empty decompiler lines.
//  - Control keywords: if×40, do×8, while×8, return×5, goto×2.
//  - Notable callees: FUN_0096efd0×7, CONCAT31×5, FUN_00989e00×5, FUN_0096ef70×4, FUN_0096f3e0×3, FUN_00970140×3, FUN_00752370×2, FUN_00752a00×2.
//  - Strings: "Compressed Texture copy"; "NDDiffTerrainLayered2.fx"; "DiffuseTexture"; "black.dds".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_005c0f40(int *param_1,int param_2)



{

  float fVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int **ppiVar8;

  int iVar9;

  int iVar10;

  int *piVar11;

  float fVar12;

  int *local_46c;

  int local_468;

  int *local_464;

  int *local_460;

  int local_45c;

  uint32_t /* width from decompiler */ local_458;

  uint32_t /* width from decompiler */ local_454;

  float local_450;

  float local_44c;

  undefined **local_448;

  uint32_t /* width from decompiler */ local_444;

  uint32_t /* width from decompiler */ local_440;

  uint32_t /* width from decompiler */ local_43c;

  uint32_t /* width from decompiler */ local_438;

  uint32_t /* width from decompiler */ local_434;

  uint32_t /* width from decompiler */ local_430;

  uint32_t /* width from decompiler */ local_42c;

  uint32_t /* width from decompiler */ local_428;

  uint32_t /* width from decompiler */ local_424;

  uint32_t /* width from decompiler */ local_420;

  uint8_t local_41c [260];

  uint8_t local_318 [780];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6d24;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (DAT_00bc5520 == '\0') {

    ExceptionList = &local_c;

    CVOGTerrain_BuildTileUVTable();

    DAT_00bc5520 = '\x01';

  }

  FUN_005bf720();

  iVar6 = param_1[6];

  param_1[0xd] = 8;

  param_1[0xe] = 0x40;

  *param_1 = param_2;

  param_1[0x18] = 0;

  param_1[1] = *(int *)(param_2 + 0x10) / iVar6;

  iVar5 = *(int *)(param_2 + 0x14) / iVar6;

  iVar10 = param_1[1] * iVar5;

  param_1[2] = iVar5;

  param_1[3] = iVar10;

  fVar1 = *(float *)(param_2 + 0x18);

  param_1[0xf] = (int)fVar1;

  iVar5 = DAT_00af4048;

  param_1[0x10] = (int)((float)iVar6 * fVar1);

  param_1[0x11] = iVar5;

  local_46c = operator_new__(iVar10 * 0xf0 + 4);

  local_4 = 0;

  if (local_46c == (int *)0x0) {

    piVar11 = (int *)0x0;

  }

  else {

    piVar11 = local_46c + 1;

    *local_46c = iVar10;

    _eh_vector_constructor_iterator_(piVar11,0xf0,iVar10,FUN_005bf1e0,FUN_005bf900);

  }

  param_1[4] = (int)piVar11;

  DAT_00bc5524 = param_2;

  pvVar2 = (void *)param_1[0x12];

  local_4 = 0xffffffff;

  if (pvVar2 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  local_46c = operator_new(4);

  local_4 = 1;

  if (local_46c == (int *)0x0) {

    iVar6 = 0;

  }

  else {

    iVar6 = FUN_0096ef70();

  }

  local_468 = param_1[2] * param_1[6] >> ((byte)param_1[0x18] & 0x1f);

  local_46c = (int *)(param_1[1] * param_1[6] >> ((byte)param_1[0x18] & 0x1f));

  local_4 = 0xffffffff;

  param_1[0x12] = iVar6;

  FUN_0096f0e0(0x16,&local_46c,1,1,1,0);

  fVar1 = g_flOne;

  fVar12 = g_flOne / (float)*(int *)(param_2 + 0x10);

  param_1[0x19] = (int)fVar12;

  param_1[0x1a] = (int)(fVar1 / (float)*(int *)(param_2 + 0x14));

  fVar1 = DAT_00a0f298;

  param_1[0x1b] = (int)(fVar12 * DAT_00a0f298);

  param_1[0x1c] = (int)((float)param_1[0x1a] * fVar1);

  local_46c = (int *)0x0;

  if (*(int *)param_1[0x12] == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = FUN_0096be60(0,0,0,(*(uint *)(*(int *)param_1[0x12] + 0x2c) & 0x80) != 0);

  }

  param_1[0x15] = iVar6;

  if (iVar6 != 0) {

    if (*(int *)param_1[0x12] == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(*(int *)param_1[0x12] + 0x40);

    }

    param_1[0x16] = iVar6;

    param_1[0x17] = 4;

    local_460 = (int *)0x0;

    if (0 < param_1[2]) {

      do {

        iVar6 = 0;

        if (0 < param_1[1]) {

          do {

            FUN_005bf270(param_1,iVar6,local_460);

            local_46c = (int *)((int)local_46c + 1);

            iVar6 = iVar6 + 1;

          } while (iVar6 < param_1[1]);

        }

        local_460 = (int *)((int)local_460 + 1);

      } while ((int)local_460 < param_1[2]);

    }

  }

  piVar11 = (int *)0x0;

  if (*(int *)param_1[0x12] != 0) {

    FUN_0096bb40(0);

  }

  param_1[0x15] = 0;

  FUN_007a4400("Compressed Texture copy");

  local_4 = 2;

  local_46c = operator_new(4);

  local_4._0_1_ = 3;

  if (local_46c != (int *)0x0) {

    piVar11 = (int *)FUN_0096ef70();

  }

  local_460 = (int *)(param_1[1] * param_1[6] >> ((byte)param_1[0x18] & 0x1f));

  local_45c = param_1[2] * param_1[6] >> ((byte)param_1[0x18] & 0x1f);

  local_4 = CONCAT31(local_4._1_3_,2);

  local_46c = piVar11;

  iVar6 = FUN_0096f0e0(0x31545844,&local_460,1,1,1,0);

  if (iVar6 < 0) {

    if (piVar11 != (int *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar11);

    }

LAB_005c1346:

    local_4 = 0xffffffff;

    FUN_007a4390();

    local_46c = operator_new(8);

    local_4 = 4;

    if (local_46c == (int *)0x0) {

      iVar6 = 0;

    }

    else {

      iVar6 = FUN_0096f530();

    }

    local_4 = 0xffffffff;

    param_1[0x14] = iVar6;

    FUN_00989e00(&local_46c,"NDDiffTerrainLayered2.fx");

    FUN_009701d0(&local_46c);

    FUN_004a9040(*(uint8_t *)(param_2 + 0x1c),local_41c);

    local_448 = &PTR_FUN_009caec8;

    local_444 = 0;

    local_440 = 0;

    local_43c = 0;

    local_438 = 0x101;

    local_434 = 1;

    local_430 = 0;

    local_42c = DAT_00aaa688;

    local_428 = 0;

    local_424 = 1;

    local_4 = 5;

    local_420 = 6;

    FUN_0096ef70();

    local_4._0_1_ = 6;

    FUN_00989e00(&local_46c,local_41c);

    iVar6 = FUN_0096f3e0(&local_46c,&local_448);

    if (iVar6 < 0) {

      local_4 = CONCAT31(local_4._1_3_,5);

      FUN_0096efd0();

      uVar7 = 0;

    }

    else {

      FUN_00970140("DiffuseTexture",local_454);

      FUN_004a90b0(*(uint8_t *)(param_2 + 0x1c),local_318);

      FUN_0096ef70();

      local_4 = CONCAT31(local_4._1_3_,7);

      FUN_00989e00(&local_46c,local_318);

      iVar6 = FUN_0096f3e0(&local_46c,&local_448);

      if (iVar6 != 0) {

        FUN_00989e00(&local_46c,"black.dds");

        FUN_0096f3e0(&local_46c,0);

      }

      FUN_00970140("GlowTexture",local_458);

      local_450 = (float)*(int *)(param_2 + 0x10) * *(float *)(param_2 + 0x18);

      local_44c = (float)*(int *)(param_2 + 0x14) * *(float *)(param_2 + 0x18);

      if (*(int *)param_1[0x14] == 0) {

        local_46c = (int *)0xffffffff;

        ppiVar8 = &local_46c;

      }

      else {

        ppiVar8 = (int **)FUN_00752370(&local_46c,"fEdgeMaxX");

      }

      piVar11 = *ppiVar8;

      cVar4 = FUN_0096fdf0();

      iVar6 = FUN_00752a00(piVar11,&local_450);

      if ((iVar6 == -1) && (cVar4 != '\0')) {

        FUN_0096f5d0();

      }

      if (*(int *)param_1[0x14] == 0) {

        local_46c = (int *)0xffffffff;

        ppiVar8 = &local_46c;

      }

      else {

        ppiVar8 = (int **)FUN_00752370(&local_46c,"fEdgeMaxZ");

      }

      piVar11 = *ppiVar8;

      cVar4 = FUN_0096fdf0();

      iVar6 = FUN_00752a00(piVar11,&local_44c);

      if ((iVar6 == -1) && (cVar4 != '\0')) {

        FUN_0096f5d0();

      }

      local_46c = operator_new(8);

      local_4._0_1_ = 8;

      if (local_46c == (int *)0x0) {

        iVar6 = 0;

      }

      else {

        iVar6 = FUN_0096f530();

      }

      local_4 = CONCAT31(local_4._1_3_,7);

      param_1[0x13] = iVar6;

      FUN_00989e00(&local_460,"NDDiffTerrainBasic.fx");

      FUN_009701d0(&local_460);

      FUN_00970140("DiffuseTexture",*(uint32_t /* width from decompiler */ *)param_1[0x12]);

      local_46c = (int *)0x0;

      if (0 < param_1[2]) {

        do {

          iVar6 = 0;

          if (0 < param_1[1]) {

            do {

              FUN_005bfa90(param_1);

              iVar6 = iVar6 + 1;

            } while (iVar6 < param_1[1]);

          }

          local_46c = (int *)((int)local_46c + 1);

        } while ((int)local_46c < param_1[2]);

      }

      iVar6 = param_1[1];

      param_1[0xd] = 8;

      if ((iVar6 < 8) || (param_1[2] < 8)) {

        iVar5 = param_1[2];

        if (iVar6 < param_1[2]) {

          iVar5 = iVar6;

        }

        param_1[0xd] = iVar5;

      }

      iVar5 = param_1[0xd];

      param_1[0xe] = iVar5 * iVar5;

      puVar3 = (uint32_t /* width from decompiler */ *)param_1[0xc];

      param_1[9] = iVar6 / iVar5;

      param_1[10] = param_1[2] / iVar5;

      param_1[0xb] = (param_1[2] / iVar5) * (iVar6 / iVar5);

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        if (puVar3[-1] == 0) {

          operator_delete__(puVar3 + -1);

        }

        else {

          (**(code **)*puVar3)(3);

        }

      }

      iVar6 = param_1[0xb];

      param_1[0xc] = 0;

      local_46c = operator_new__(iVar6 * 0xd8 + 4);

      local_4._0_1_ = 9;

      if (local_46c == (int *)0x0) {

        piVar11 = (int *)0x0;

      }

      else {

        piVar11 = local_46c + 1;

        *local_46c = iVar6;

        _eh_vector_constructor_iterator_(piVar11,0xd8,iVar6,FUN_005bf5e0,FUN_005bf620);

      }

      local_4._0_1_ = 7;

      param_1[0xc] = (int)piVar11;

      local_460 = (int *)0x0;

      if (0 < param_1[10]) {

        do {

          local_46c = (int *)0x0;

          if (0 < param_1[9]) {

            do {

              iVar6 = param_1[0xc] + (int)(param_1[9] * (int)local_460 + (int)local_46c) * 0xd8;

              FUN_005c0db0(param_1,param_1[0xe]);

              local_464 = (int *)0x0;

              if (0 < param_1[0xd]) {

                do {

                  iVar5 = param_1[0xd] * (int)local_460 + (int)local_464;

                  iVar10 = 0;

                  if (0 < param_1[0xd]) {

                    do {

                      iVar9 = (param_1[1] * iVar5 + param_1[0xd] * (int)local_46c + iVar10) * 0xf0 +

                              param_1[4];

                      *(int *)(*(int *)(iVar6 + 200) + *(int *)(iVar6 + 0xcc) * 4) = iVar9;

                      *(int *)(iVar6 + 0xcc) = *(int *)(iVar6 + 0xcc) + 1;

                      *(int *)(iVar9 + 200) = iVar6;

                      iVar9 = CVOGTerrainChunk_BuildVertexBuffer

                                        (param_1,param_1[6],*(uint32_t /* width from decompiler */ *)(iVar6 + 0xd0));

                      *(int *)(iVar6 + 0xd4) = *(int *)(iVar6 + 0xd4) + iVar9;

                      *(int *)(iVar6 + 0xd0) = *(int *)(iVar6 + 0xd0) + iVar9 * 0x28;

                      iVar10 = iVar10 + 1;

                    } while (iVar10 < param_1[0xd]);

                  }

                  local_464 = (int *)((int)local_464 + 1);

                } while ((int)local_464 < param_1[0xd]);

              }

              FUN_005c0100(param_1);

              local_46c = (int *)((int)local_46c + 1);

            } while ((int)local_46c < param_1[9]);

          }

          local_460 = (int *)((int)local_460 + 1);

        } while ((int)local_460 < param_1[10]);

      }

      local_4._0_1_ = 6;

      FUN_0096efd0();

      local_4 = CONCAT31(local_4._1_3_,5);

      FUN_0096efd0();

      uVar7 = 1;

    }

    ExceptionList = local_c;

    return uVar7;

  }

  piVar11 = *(int **)(*local_46c + 0x10);

  local_460 = (int *)0x0;

  local_464 = (int *)0x0;

  iVar6 = (**(code **)(**(int **)(*(int *)param_1[0x12] + 0x10) + 0x48))

                    (*(int **)(*(int *)param_1[0x12] + 0x10),0,&local_460);

  iVar5 = (**(code **)(*piVar11 + 0x48))(piVar11,0,&stack0xfffffb90);

  if ((-1 < iVar6) && (-1 < iVar5)) {

    if (local_460 == (int *)0x0) goto LAB_005c131e;

    if (local_464 != (int *)0x0) {

      D3DXLoadSurfaceFromSurface(local_464,0,0,local_460,0,0,0xffffffff,0);

      if (local_460 != (int *)0x0) {

        (**(code **)(*local_460 + 8))(local_460);

      }

      local_460 = (int *)0x0;

      if (local_464 != (int *)0x0) {

        (**(code **)(*local_464 + 8))(local_464);

      }

      pvVar2 = (void *)param_1[0x12];

      local_464 = (int *)0x0;

      if (pvVar2 != (void *)0x0) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      param_1[0x12] = (int)local_46c;

      goto LAB_005c1346;

    }

  }

  if (local_460 != (int *)0x0) {

    (**(code **)(*local_460 + 8))(local_460);

  }

LAB_005c131e:

  local_460 = (int *)0x0;

  if (local_464 != (int *)0x0) {

    (**(code **)(*local_464 + 8))(local_464);

  }

  piVar11 = local_46c;

  local_464 = (int *)0x0;

  FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar11);

}
