// =============================================================================
// Gfx_PalToolMaterialNoMap
// -----------------------------------------------------------------------------
// Stable ID: aa_007300c0
// Address:   0x007300c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalToolMaterialNoMap @ 0x007300c0
// Stable ID: aa_007300c0
// Embedded strings (evidence for future rename):
//   - "PalToolMaterialNoMap.fx"
//   - "MatDiffuse"
//   - "MatAmbient"
//   - "MatSpecular"
//   - "MatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~393 non-empty decompiler lines.
//  - Control keywords: if×39, for×6, return×4.
//  - Notable callees: FUN_00414b60×7, FUN_00414c20×4, FUN_00752370×4, FUN_0096fff0×4, FUN_00457a00×3, CONCAT31×2, FUN_00414a50×2, FUN_00414bc0×2.
//  - Strings: "PalToolMaterialNoMap.fx"; "MatDiffuse"; "MatAmbient"; "MatSpecular".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalToolMaterialNoMap.fx"
 * Domain alias of FUN_007300c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00730710) */

/* WARNING: Removing unreachable block (ram,0x00730716) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Gfx_PalToolMaterialNoMap(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  char cVar4;

  uint32_t /* width from decompiler */ **ppuVar5;

  int *piVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint uVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *local_f0;

  uint32_t /* width from decompiler */ local_ec;

  undefined **local_e8;

  int *local_e4;

  float local_e0;

  int local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  float local_cc;

  uint32_t /* width from decompiler */ *puStack_c8;

  int iStack_c4;

  uint8_t local_c0 [4];

  void *pvStack_bc;

  int iStack_b8;

  int iStack_b4;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  float local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  float local_94;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint8_t local_70 [8];

  uint32_t /* width from decompiler */ *puStack_68;

  int iStack_64;

  int iStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  float local_34;

  uint8_t local_28 [20];

  uint8_t uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1eb6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00981310(local_c0);

  local_4 = 0;

  local_a0 = DAT_00d1a6c0;

  local_e8 = (undefined **)0x0;

  local_e4 = (int *)0x0;

  local_ac = 0;

  local_9c = DAT_00d1a6c4;

  local_98 = DAT_00d1a6c8;

  local_e0 = g_flOne;

  local_a8 = 0;

  local_a4 = g_flOne;

  local_94 = g_flOne;

  FUN_009813a0(local_c0,100);

  FUN_0098ef00(local_70);

  local_4 = CONCAT31(local_4._1_3_,1);

  local_40 = DAT_00d1a6c0;

  local_3c = DAT_00d1a6c4;

  local_38 = DAT_00d1a6c8;

  local_34 = g_flOne;

  FUN_0098f2b0(100);

  FUN_00989e00(&local_dc,"PalToolMaterialNoMap.fx");

  piVar12 = (int *)(param_1 + 0x24);

  FUN_009701d0(&local_dc);

  if (*piVar12 == 0) {

    local_f0 = (uint32_t /* width from decompiler */ *)0xffffffff;

    ppuVar5 = &local_f0;

  }

  else {

    ppuVar5 = (uint32_t /* width from decompiler */ **)FUN_00752370(&local_ec,"MatDiffuse");

  }

  if (-1 < (int)*ppuVar5) {

    FUN_0096fff0(piVar12,*ppuVar5);

  }

  if (*piVar12 == 0) {

    local_f0 = (uint32_t /* width from decompiler */ *)0xffffffff;

    ppuVar5 = &local_f0;

  }

  else {

    ppuVar5 = (uint32_t /* width from decompiler */ **)FUN_00752370(local_28,"MatAmbient");

  }

  if (-1 < (int)*ppuVar5) {

    FUN_0096fff0(piVar12,*ppuVar5);

  }

  local_d8 = DAT_00a0f298;

  local_d4 = DAT_00a0f298;

  local_d0 = DAT_00a0f298;

  local_cc = g_flOne;

  if (*piVar12 == 0) {

    local_f0 = (uint32_t /* width from decompiler */ *)0xffffffff;

    ppuVar5 = &local_f0;

  }

  else {

    ppuVar5 = (uint32_t /* width from decompiler */ **)FUN_00752370(&local_e8,"MatSpecular");

  }

  if (-1 < (int)*ppuVar5) {

    FUN_0096fff0(piVar12,*ppuVar5);

  }

  ppuVar5 = &local_f0;

  if (*piVar12 == 0) {

    local_f0 = (uint32_t /* width from decompiler */ *)0xffffffff;

  }

  else {

    ppuVar5 = (uint32_t /* width from decompiler */ **)FUN_00752370(ppuVar5,"MatEmissive");

  }

  if (-1 < (int)*ppuVar5) {

    FUN_0096fff0(piVar12,*ppuVar5);

  }

  piVar6 = (int *)FUN_0073d940(*piVar12);

  if (piVar6 != (int *)0x0) {

    piVar6[1] = piVar6[1] + 1;

    if (piVar6[1] == 1) {

      (**(code **)(*piVar6 + 4))();

    }

    piVar2 = (int *)*piVar12;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *piVar12 = (int)piVar6;

  }

  if (*(int *)(*piVar12 + 0x14) == 0) {

    cVar4 = '\0';

  }

  else {

    cVar4 = *(char *)(*(int *)(*piVar12 + 0x14) + 0x10);

  }

  local_dc = (-(uint)(cVar4 != '\0') & 0xfffffff0) + 0x20;

  if (iStack_b8 == 0) {

    uVar9 = 0;

  }

  else {

    uVar9 = (iStack_b4 - iStack_b8) / 0x24;

  }

  *(uint *)(param_1 + 0x20) = uVar9 / 3;

  if (iStack_58 == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = (iStack_54 - iStack_58) / 6;

  }

  *(int *)(param_1 + 0x1c) = iVar7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 4;

  uStack_84 = 0;

  uStack_80 = 0;

  uStack_7c = 0;

  uStack_78 = 0;

  uStack_74 = 0;

  local_e4 = (int *)0x0;

  local_e8 = &PTR_FUN_00a9db18;

  local_4._0_1_ = 3;

  uVar8 = FUN_00414bc0(0x152);

  local_4._0_1_ = 4;

  if (puStack_68 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar7 = 0;

  }

  else {

    iVar7 = (iStack_64 - (int)puStack_68) / 0x24;

  }

  iVar7 = FUN_00414c20(iVar7,uVar8,8,0);

  local_4._0_1_ = 3;

  FUN_00414b60();

  piVar12 = local_e4;

  if (iVar7 < 0) {

    local_4._0_1_ = 2;

    if (local_e4 != (int *)0x0) {

      piVar12 = local_e4 + 1;

      *piVar12 = *piVar12 + -1;

      if (*piVar12 == 0) {

        (**(code **)(*local_e4 + 8))();

      }

    }

    FUN_00414b60();

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00457a00(local_70);

  }

  else {

    piVar6 = (int *)local_e4[4];

    if (piVar6 == (int *)0x0) {

      puVar13 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      piVar2 = (int *)*piVar6;

      if (piVar2 == (int *)0x0) {

        puVar13 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar7 = (**(code **)(*piVar2 + 0x2c))

                          (piVar2,piVar6[2] * local_e4[5],piVar6[2] * local_e4[6],&local_f0,0x800);

        if (iVar7 < 0) {

          puVar13 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          piVar6[4] = piVar6[4] + 1;

          puVar13 = local_f0;

        }

      }

    }

    if (piVar12[4] == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(piVar12[4] + 8);

    }

    iVar3 = piVar12[6];

    puVar11 = puStack_68;

    for (uVar9 = (uint)(iVar3 * iVar7) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

      *puVar13 = *puVar11;

      puVar11 = puVar11 + 1;

      puVar13 = puVar13 + 1;

    }

    for (uVar9 = iVar3 * iVar7 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

      *(uint8_t *)puVar13 = *(uint8_t *)puVar11;

      puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

      puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

    }

    FUN_00414a50();

    FUN_004451c0(&local_d8,piVar12 + 9);

    local_4 = CONCAT31(local_4._1_3_,5);

    FUN_00747390();

    if (puStack_68 == (uint32_t /* width from decompiler */ *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = (iStack_64 - (int)puStack_68) / 0x24;

    }

    FUN_00414c20(iVar7,&local_d8,local_dc,0);

    if (iStack_58 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = (iStack_54 - iStack_58) / 6;

    }

    FUN_0044b9c0(iVar7 * 3,0x20,0,0);

    iVar7 = *(int *)(param_1 + 0x18);

    piVar6 = *(int **)(iVar7 + 0x10);

    if (piVar6 == (int *)0x0) {

      puVar13 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar13 = *(uint32_t /* width from decompiler */ **)(iVar7 + 0x18);

      piVar2 = (int *)*piVar6;

      if (piVar2 == (int *)0x0) {

        puVar13 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar7 = (**(code **)(*piVar2 + 0x2c))

                          (piVar2,piVar6[4] * (int)puVar13,piVar6[4] * *(int *)(iVar7 + 0x1c),

                           &stack0xffffff04,0x800);

        if (iVar7 < 0) {

          puVar13 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          piVar6[3] = piVar6[3] + 1;

        }

      }

    }

    if (puStack_68 == (uint32_t /* width from decompiler */ *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = (iStack_64 - (int)puStack_68) / 6;

    }

    for (uVar9 = (uint)(iVar7 * 6) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

      *puVar13 = *puStack_68;

      puStack_68 = puStack_68 + 1;

      puVar13 = puVar13 + 1;

    }

    for (uVar9 = iVar7 * 6 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

      *(uint8_t *)puVar13 = *(uint8_t *)puStack_68;

      puStack_68 = (uint32_t /* width from decompiler */ *)((int)puStack_68 + 1);

      puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

    }

    FUN_0044ba80();

    FUN_0044bbc0(&stack0xffffff08,param_1 + 0x14,0);

    FUN_00414b60();

    uStack_14 = 2;

    piVar6 = piVar12 + 1;

    *piVar6 = *piVar6 + -1;

    if (*piVar6 == 0) {

      (**(code **)(*piVar12 + 8))();

    }

    uStack_14 = 6;

    uVar8 = FUN_00414bc0(0x152);

    uStack_14 = 7;

    if (puStack_c8 == (uint32_t /* width from decompiler */ *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = (iStack_c4 - (int)puStack_c8) / 0x24;

    }

    iVar7 = FUN_00414c20(iVar7,uVar8,8,0);

    uStack_14 = 6;

    FUN_00414b60();

    puVar13 = puRam00000018;

    piVar12 = piRam00000010;

    if (-1 < iVar7) {

      puVar11 = (uint32_t /* width from decompiler */ *)0x0;

      if ((piRam00000010 != (int *)0x0) && (piVar6 = (int *)*piRam00000010, piVar6 != (int *)0x0)) {

        iVar7 = (**(code **)(*piVar6 + 0x2c))

                          (piVar6,piRam00000010[2] * iRam00000014,

                           piRam00000010[2] * (int)puRam00000018,&stack0xffffff04,0x800);

        if (iVar7 < 0) {

          puVar11 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          piVar12[4] = piVar12[4] + 1;

          puVar11 = puVar13;

        }

      }

      if (piRam00000010 == (int *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = piRam00000010[2];

      }

      uVar10 = (int)puRam00000018 * iVar7;

      puVar13 = puStack_c8;

      for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

        *puVar11 = *puVar13;

        puVar13 = puVar13 + 1;

        puVar11 = puVar11 + 1;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint8_t *)puVar11 = *(uint8_t *)puVar13;

        puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

        puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

      }

      FUN_00414a50();

      FUN_004451c0(&local_e8,0x24);

      uStack_14 = 8;

      FUN_00747390();

      iVar7 = 0;

      if (puStack_c8 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar7 = (iStack_c4 - (int)puStack_c8) / 0x24;

      }

      FUN_00414c20(iVar7,&local_e8,local_ec,0);

      FUN_0044bbc0(&stack0xffffff08,0,0);

      FUN_00414b60();

      uStack_14 = 2;

      iRam00000004 = iRam00000004 + -1;

      if (iRam00000004 == 0) {

        (**(code **)(_DAT_00000000 + 8))();

      }

      FUN_00414b60();

      uStack_14 = 0;

      FUN_00457a00(&uStack_80);

      if (pvStack_bc == (void *)0x0) {

        ExceptionList = pvStack_10;

        return 0;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_bc);

    }

    uStack_14 = 2;

    FUN_00414b60();

    uStack_14 = 0;

    FUN_00457a00(&uStack_80);

  }

  if (pvStack_bc == (void *)0x0) {

    ExceptionList = pvStack_10;

    return 0xffffffff;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvStack_bc);

}
