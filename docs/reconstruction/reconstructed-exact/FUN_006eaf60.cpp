// =============================================================================
// FUN_006eaf60
// -----------------------------------------------------------------------------
// Stable ID: aa_006eaf60
// Address:   0x006eaf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eaf60 @ 0x006eaf60
// Stable ID: aa_006eaf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~277 non-empty decompiler lines.
//  - Control keywords: if×27, while×6, do×5, goto×4, for×3, return×1.
//  - Notable callees: FUN_006cb7d0×3, FUN_005b3300×2, FUN_006ea4e0×2, FUN_006ea1b0, FUN_006ea560, FUN_006ea5d0, FUN_006eaf60.
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

void __thiscall FUN_006eaf60(int param_1,int param_2,int *param_3,int param_4,code *param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint *puVar9;

  uint *puVar10;

  uint *puVar11;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint *puVar12;

  int iVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint *puVar15;

  uint *puStack_394;

  uint uStack_38c;

  uint *puStack_388;

  uint uStack_384;

  uint *puStack_37c;

  int iStack_378;

  uint uStack_374;

  uint32_t /* width from decompiler */ local_360;

  uint32_t /* width from decompiler */ local_35c;

  uint32_t /* width from decompiler */ local_358;

  uint32_t /* width from decompiler */ local_354;

  uint32_t /* width from decompiler */ local_350;

  uint32_t /* width from decompiler */ local_34c;

  uint *local_348;

  uint32_t /* width from decompiler */ local_344 [2];

  uint32_t /* width from decompiler */ uStack_33c;

  int iStack_338;

  uint8_t auStack_328 [256];

  uint *puStack_228;

  int iStack_224;

  uint8_t *local_220;

  uint32_t /* width from decompiler */ local_21c;

  uint32_t /* width from decompiler */ local_218;

  uint8_t local_214 [528];

  

  FUN_006ea1b0(param_2,param_3,param_4,&local_360);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = local_360;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = local_35c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = local_358;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = local_354;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = local_350;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = local_34c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = local_344[0];

  local_220 = local_214;

  *(uint **)(param_1 + 0x38) = local_348;

  param_3 = (int *)*param_3;

  local_21c = 0;

  local_218 = 0x80000080;

  (**(code **)(*param_3 + 0x30))(&local_360,&local_220);

  local_348 = (uint *)param_3[3];

  uStack_38c = uStack_38c & 0xffffff00;

  if (1 < iStack_224) {

    FUN_006ea4e0(puStack_228,0,iStack_224 + -1,uStack_38c);

  }

  uStack_33c = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  iStack_338 = param_2;

  if (DAT_00d09691 != '\0') {

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    puVar12 = *(uint **)(param_1 + 0xc);

    piVar1 = (int *)(param_1 + 0xc);

    puStack_388 = puVar12 + *(int *)(param_1 + 0x10) * 3;

    puVar10 = puStack_228 + iStack_224;

    puVar9 = puStack_228;

    puVar15 = puStack_228;

    if (puVar12 != puStack_388) {

      do {

        if ((puVar15 == puVar10) || (*puVar12 != *puVar15)) {

          puVar15 = puVar9;

          if (puVar9 != puVar10) {

            do {

              if (*puVar12 == *puVar15) {

                puVar15 = puVar15 + 1;

                goto LAB_006eb137;

              }

              puVar15 = puVar15 + 1;

            } while (puVar15 != puVar10);

          }

          (**(code **)(*(int *)puVar12[2] + 0x14))();

          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

          iVar3 = ((int)puVar12 - *piVar1) / 0xc;

          if (iVar3 < *(int *)(param_1 + 0x10)) {

            iVar7 = iVar3 * 0xc;

            do {

              puVar8 = (uint32_t /* width from decompiler */ *)(iVar7 + *piVar1);

              *puVar8 = puVar8[3];

              puVar8[1] = puVar8[4];

              puVar8[2] = puVar8[5];

              iVar3 = iVar3 + 1;

              iVar7 = iVar7 + 0xc;

            } while (iVar3 < *(int *)(param_1 + 0x10));

          }

          puVar12 = puVar12 + -3;

          puStack_388 = puStack_388 + -3;

          puVar9 = puStack_228;

        }

        else {

          puVar15 = puVar15 + 1;

        }

LAB_006eb137:

        puVar12 = puVar12 + 3;

      } while (puVar12 != puStack_388);

    }

    iVar3 = *(int *)(param_1 + 0x10);

    puVar10 = puVar9;

    if (iStack_224 != iVar3) {

      puVar15 = (uint *)*piVar1;

      puStack_394 = puVar15 + iVar3 * 3;

      puVar12 = puVar9 + iStack_224;

      for (; puVar9 != puVar12; puVar9 = puVar9 + 1) {

        if ((puVar15 == puStack_394) || (*puVar15 != *puVar9)) {

          iVar7 = iVar3 + 1;

          iVar13 = (int)puVar9 - (int)puVar10 >> 2;

          puStack_394 = (uint *)(iVar3 - iVar13);

          uVar4 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

          if ((int)uVar4 < iVar7) {

            iVar3 = uVar4 * 2;

            if (iVar3 <= iVar7) {

              iVar3 = iVar7;

            }

            FUN_005b3300(piVar1,iVar3,0xc);

          }

          iVar13 = iVar13 * 0xc;

          iVar3 = iVar13 + *piVar1;

          if (-1 < (int)puStack_394 + -1) {

            iVar2 = iVar3 + 0xc;

            puVar8 = (uint32_t /* width from decompiler */ *)(iVar2 + ((int)puStack_394 + -1) * 0xc);

            do {

              puVar14 = (uint32_t /* width from decompiler */ *)((iVar3 - iVar2) + (int)puVar8);

              *puVar8 = *puVar14;

              puVar8[1] = puVar14[1];

              puVar8[2] = puVar14[2];

              puVar8 = puVar8 + -3;

              puStack_394 = (uint *)((int)puStack_394 + -1);

            } while (puStack_394 != (uint *)0x0);

          }

          puVar15 = (uint *)(*piVar1 + iVar13);

          *(int *)(param_1 + 0x10) = iVar7;

          puVar10 = (uint *)*puVar9;

          local_34c = (**(code **)(*local_348 + 0x34))(puVar10,auStack_328);

          local_348 = puVar10;

          pcVar5 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                                     (&stack0xfffffc6b,param_4,param_2,&local_34c,local_350,

                                      *unaff_EDI);

          if (*pcVar5 == '\0') {

            uVar4 = FUN_006cb7d0();

          }

          else {

            uVar4 = (*param_5)(param_2,local_344,param_4,uVar6);

          }

          puVar15[2] = uVar4;

          *puVar15 = *puVar9;

          iVar3 = *(int *)(param_1 + 0x10);

          puStack_394 = (uint *)(*piVar1 + iVar3 * 0xc);

          puVar10 = puStack_228;

        }

        puVar15 = puVar15 + 3;

      }

    }

    goto LAB_006eb5af;

  }

  uStack_384 = uStack_384 & 0xffffff00;

  if (1 < iStack_224) {

    FUN_006ea4e0(puStack_228,0,iStack_224 + -1,uStack_384);

  }

  puVar15 = puStack_228;

  puVar9 = *(uint **)(param_1 + 0xc);

  uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  puVar10 = puVar9 + *(int *)(param_1 + 0x10) * 3;

  puVar12 = puStack_228 + iStack_224;

  FUN_006ea560(iStack_224);

  iStack_378 = iStack_224;

  puVar11 = puStack_37c;

  if ((int)(uStack_374 & 0x7fffffff) < iStack_224) {

    iVar3 = (uStack_374 & 0x7fffffff) * 2;

    if (iVar3 <= iStack_224) {

      iVar3 = iStack_224;

    }

    FUN_005b3300(&puStack_37c,iVar3,0xc);

    puVar11 = puStack_37c;

  }

  while (puVar9 != puVar10) {

    if (puVar15 == puVar12) goto joined_r0x006eb473;

    uVar4 = *puVar15;

    if (uVar4 == *puVar9) {

      *puVar11 = *puVar9;

      puVar11[1] = puVar9[1];

      puVar11[2] = puVar9[2];

      puVar11 = puVar11 + 3;

      puVar9 = puVar9 + 3;

      puVar15 = puVar15 + 1;

    }

    else if (uVar4 < *puVar9) {

      local_34c = (**(code **)(*local_348 + 0x34))(uVar4,auStack_328);

      local_348 = puVar10;

      pcVar5 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                                 (&stack0xfffffc6b,param_4,param_2,&local_34c,local_350,*puVar15);

      if (*pcVar5 == '\0') {

        uVar4 = FUN_006cb7d0();

        puVar11[2] = uVar4;

      }

      else {

        uVar4 = (*param_5)(param_2,local_344,param_4,uVar6);

        puVar11[2] = uVar4;

      }

      *puVar11 = *puVar15;

      puVar11 = puVar11 + 3;

      puVar15 = puVar15 + 1;

    }

    else {

      if ((int *)puVar9[2] != (int *)0x0) {

        (**(code **)(*(int *)puVar9[2] + 0x14))();

      }

      puVar9 = puVar9 + 3;

    }

  }

  goto joined_r0x006eb492;

joined_r0x006eb473:

  for (; puVar9 != puVar10; puVar9 = puVar9 + 3) {

    if ((int *)puVar9[2] != (int *)0x0) {

      (**(code **)(*(int *)puVar9[2] + 0x14))();

    }

  }

joined_r0x006eb492:

  for (; puVar15 != puVar12; puVar15 = puVar15 + 1) {

    puVar10 = (uint *)*puVar15;

    local_34c = (**(code **)(*local_348 + 0x34))(puVar10,auStack_328);

    local_348 = puVar10;

    pcVar5 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                               (&stack0xfffffc6b,param_4,param_2,&local_34c,local_350,*puVar15);

    if (*pcVar5 == '\0') {

      uVar4 = FUN_006cb7d0();

      puVar11[2] = uVar4;

    }

    else {

      uVar4 = (*param_5)(param_2,local_344,param_4,uVar6);

      puVar11[2] = uVar4;

    }

    *puVar11 = *puVar15;

    puVar11 = puVar11 + 3;

  }

  uVar4 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

  if ((int)uVar4 < iStack_378) {

    if (-1 < (int)*(uint *)(param_1 + 0x14)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),uVar4 * 0xc,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(iStack_378 * 0xc,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar6;

    *(int *)(param_1 + 0x14) = iStack_378;

  }

  *(int *)(param_1 + 0x10) = iStack_378;

  puVar10 = *(uint **)(param_1 + 0xc);

  if (0 < iStack_378) {

    do {

      *puVar10 = *puStack_37c;

      puVar10[1] = puStack_37c[1];

      puVar12 = puStack_37c + 2;

      puStack_37c = puStack_37c + 3;

      iStack_378 = iStack_378 + -1;

      puVar10[2] = *puVar12;

      puVar10 = puVar10 + 3;

    } while (iStack_378 != 0);

  }

  FUN_006ea5d0();

  puVar10 = puStack_228;

LAB_006eb5af:

  if (-1 < (int)local_220) {

    (**(code **)(*DAT_00b05060 + 0x14))(puVar10,(int)local_220 << 2,0x12);

  }

  return;

}
