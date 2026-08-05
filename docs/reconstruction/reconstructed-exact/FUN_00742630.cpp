// =============================================================================
// FUN_00742630
// -----------------------------------------------------------------------------
// Stable ID: aa_00742630
// Address:   0x00742630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00742630 @ 0x00742630
// Stable ID: aa_00742630
// Embedded strings (evidence for future rename):
//   - "FPS: %1.1f"
//   - "Submitted per frame:"
//   - "Triangles:\t %d"
//   - "Vertices:\t\t %d"
//   - "Indices:\t\t %d"
//   - "Primitives:\t %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~445 non-empty decompiler lines.
//  - Control keywords: if×23, do×3, while×3, return×2.
//  - Notable callees: FUN_00759730×20, FUN_0040aef0×19, sprintf×17, ROUND×4, CONCAT13×3, FUN_00758460×2, CONCAT22, FUN_00440680.
//  - Strings: "FPS: %1.1f"; "Submitted per frame:"; "Triangles:\t %d"; "Vertices:\t\t %d".
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



uint32_t /* width from decompiler */ __thiscall FUN_00742630(int param_1,int *param_2)



{

  char *pcVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  char *extraout_ECX;

  uint uVar6;

  float fVar7;

  int iVar8;

  int *piVar9;

  char *pcStack_14c;

  char *pcStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  int *piStack_118;

  int iStack_114;

  char *pcStack_10c;

  char *pcStack_108;

  uint32_t /* width from decompiler */ uStack_104;

  char *pcStack_100;

  uint8_t *puStack_fc;

  float *pfStack_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  int iStack_ec;

  float fStack_e8;

  float fStack_e4;

  int iStack_e0;

  int local_dc;

  uint8_t *local_d8;

  float fStack_d4;

  char *pcStack_d0;

  int iStack_cc;

  char *pcStack_c8;

  char *pcStack_c4;

  int iStack_c0;

  int iStack_bc;

  float fStack_b8;

  uint8_t *puStack_b4;

  float fStack_b0;

  char *local_ac;

  float fStack_a8;

  uint8_t *puStack_a4;

  int iStack_a0;

  char acStack_9c [128];

  char *pcStack_1c;

  undefined *puStack_18;

  char *pcStack_14;

  char *pcStack_10;

  

  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2[0x3a];

  if ((*(int *)(param_1 + 4) < 200) && (DAT_00b026ac != '\0')) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  FUN_00758c80();

  pcVar1 = *(char **)(*(int *)(param_1 + 0x7c) + 0x7c);

  local_f4 = param_1 + 0x7c;

  local_d8 = (uint8_t *)((int)pcVar1 * 0x11);

  local_dc = 300;

  local_ac = pcVar1;

  (**(code **)(*param_2 + 8))();

  fStack_e8 = (float)param_2[0x3d] * DAT_00a0f524;

  puStack_a4 = DAT_00d1f024 + iStack_e0;

  iStack_a0 = local_dc + (int)DAT_00d1f028;

  local_ac = DAT_00d1f024;

  iVar4 = (int)pcVar1 / 2;

  pcStack_d0 = puStack_a4 + -iVar4;

  fStack_a8 = DAT_00d1f028;

  local_d8 = DAT_00d1f024 + iVar4;

  fVar7 = (float)((int)DAT_00d1f028 + iVar4);

  iStack_cc = iStack_a0 + -iVar4;

  iStack_ec = 0;

  fStack_e4 = (float)(int)ROUND(fStack_e8);

  local_f4 = (int)fStack_e4 << 0x18;

  uStack_144 = 0;

  pcStack_148 = &DAT_00d1ec78;

  pcStack_14c = (char *)(float)iStack_cc;

  fStack_d4 = fVar7;

  FUN_00758460((float)(int)local_d8,(float)(int)fVar7,(float)(int)pcStack_d0);

  FUN_00757ff0();

  iVar4 = param_2[0x1a] + 1;

  param_2[0x1a] = iVar4;

  param_2[0x1d] = (int)(float)-iVar4;

  if (param_2[0x1c] < iVar4) {

    param_2[0x1c] = iVar4;

  }

  FUN_00440680();

  param_2[0x12] = (int)local_d8;

  param_2[0x13] = (int)fVar7;

  param_2[0x14] = (int)pcStack_d0;

  iVar4 = param_2[0x1a] + 1;

  param_2[0x15] = iStack_cc;

  param_2[0x1a] = iVar4;

  param_2[0x1d] = (int)(float)-iVar4;

  if (param_2[0x1c] < iVar4) {

    param_2[0x1c] = iVar4;

  }

  fStack_e8 = (float)param_2[0x3d] * DAT_00aaa6f8;

  iStack_bc = (int)ROUND(fStack_e8);

  local_f4 = CONCAT13((char)iStack_bc,0x800080);

  pcStack_108 = (char *)((int)pcVar1 / 2);

  local_f4 = CONCAT22(local_f4._2_2_,0xff80);

  uStack_104 = (char *)CONCAT13((char)iStack_bc,0xffff);

  iStack_ec = DAT_00d1f614;

  if (*(int *)(DAT_00d1f614 + 0x54) == 0) {

    uStack_f0 = 0.0;

  }

  else {

    uStack_f0 = ((float)*(int *)(DAT_00d1f614 + 0x58) * DAT_00a0f520) /

                (float)*(int *)(DAT_00d1f614 + 0x54);

  }

  pcStack_10c = pcVar1;

  sprintf(acStack_9c,"FPS: %1.1f");

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  uStack_144 = 0xffffffff;

  pcStack_148 = "Submitted per frame:";

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_108 = (char *)((int)pcVar1 * 2);

  pcStack_10c = pcVar1;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&local_f4);

  pcStack_100 = (char *)(iStack_114 + 0x70);

  sprintf(acStack_9c,"Triangles:\t %d");

  pcStack_108 = pcVar1 + (int)pcStack_108;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Vertices:\t\t %d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Indices:\t\t %d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Primitives:\t %d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  pcStack_10c = (char *)(param_2[0x20] / 2);

  uStack_144 = 0xffffffff;

  pcStack_148 = "Submitted per second:";

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_108 = (char *)((int)pcVar1 * 2);

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&local_f4);

  if (*(int *)(iStack_ec + 0x54) == 0) {

    uStack_f0 = 0.0;

  }

  else {

    uStack_f0 = ((float)*(int *)(iStack_ec + 0x58) * DAT_00a0f520) /

                (float)*(int *)(iStack_ec + 0x54);

  }

  uStack_f0 = uStack_f0 * _DAT_00a240ec;

  sprintf(acStack_9c,"Triangles:\t%5.3fM");

  pcStack_108 = pcVar1 + (int)pcStack_108;

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Vertices:\t\t%5.3fM");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Indices:\t\t%5.3fM");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Primitives:\t%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  uStack_144 = 0xffffffff;

  pcStack_148 = "State changes per frame:\t\tWorking Set:";

  pcStack_108 = pcStack_108 + ((int)pcVar1 * 3) / 2;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_10c = pcVar1;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&local_f4);

  sprintf(acStack_9c,"Effect Instances:\t%d/%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Effects:\t\t\t%d/%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Vertex Decls:\t\t%d/%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Vertex Buffers:\t%d/%d");

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  pcStack_108 = pcStack_108 + (int)pcVar1;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_14c = pcStack_10c;

  pcStack_c8 = pcStack_10c;

  pcStack_c4 = pcStack_108;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Index Buffers:\t%d/%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  sprintf(acStack_9c,"Textures:\t\t%d/%d");

  pcStack_108 = pcStack_108 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_14c = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_148 = pcStack_14c;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_10c,&uStack_104);

  pcStack_c8 = pcStack_c8 + 0xc0;

  pcStack_c4 = pcStack_c4 + (int)pcVar1;

  sprintf(acStack_9c,"%5.3fMB");

  pcStack_c4 = pcStack_c4 + (int)pcVar1;

  uStack_144 = 0xffffffff;

  pcStack_148 = acStack_9c;

  puStack_fc = (uint8_t *)&pcStack_14c;

  pcStack_14c = extraout_ECX;

  FUN_0040aef0(&pcStack_14c);

  FUN_00759730(param_2,&pcStack_c8,&uStack_104);

  pcStack_108 = (char *)(iStack_cc - (int)pcVar1);

  pcStack_10c = pcStack_d0;

  fVar7 = (float)((int)pcVar1 << 4) * DAT_00aaa7b8;

  puStack_fc = (uint8_t *)((float)((int)pcStack_d0 - (int)local_d8) * _DAT_00aaab94);

  fStack_e4 = fVar7;

  if (0 < *(int *)(iStack_ec + 0x6c)) {

    iVar4 = param_2[0x1a] + -1;

    param_2[0x1a] = iVar4;

    param_2[0x1d] = (int)(float)-iVar4;

    if (param_2[0x1c] < iVar4) {

      param_2[0x1c] = iVar4;

    }

    iVar4 = *(int *)(iStack_ec + 0x6c);

    uStack_f0 = (float)(iStack_114 + 0x8c);

    local_f4 = iStack_ec + 0x98;

    uStack_104 = pcStack_100;

    fStack_e8 = 5.60519e-45;

    do {

      if (*uStack_104 != '\0') {

        *(char *)((int)uStack_f0 + 3) = (char)iStack_bc;

        iVar8 = iVar4 + -1;

        uVar6 = *(int *)(local_f4 + 0xc) + iVar8;

        uVar5 = uVar6 >> 2;

        iVar3 = uVar5 * -4;

        if (*(uint *)(local_f4 + 8) <= uVar5) {

          uVar5 = uVar5 - *(uint *)(local_f4 + 8);

        }

        fStack_b8 = (float)(int)pcStack_108;

        fStack_d4 = fStack_b8 -

                    (float)*(int *)(*(int *)(*(int *)(local_f4 + 4) + uVar5 * 4) +

                                   (uVar6 + iVar3) * 4) * fVar7;

        local_d8 = (uint8_t *)(float)(int)pcStack_10c;

        pcStack_100 = (char *)0x0;

        puStack_b4 = local_d8;

        if (1 < iVar4) {

          pcStack_c8 = (char *)(iStack_ec + 0xac);

          iStack_c0 = iVar4 + -1;

          do {

            iVar8 = iVar8 + -1;

            uVar5 = (uint)(*(int *)(pcStack_c8 + 0xc) + iVar8) >> 2;

            iVar3 = uVar5 * -4;

            if (*(uint *)(pcStack_c8 + 8) <= uVar5) {

              uVar5 = uVar5 - *(uint *)(pcStack_c8 + 8);

            }

            pcStack_100 = pcStack_100 +

                          *(int *)(*(int *)(*(int *)(pcStack_c8 + 4) + uVar5 * 4) +

                                  (*(int *)(pcStack_c8 + 0xc) + iVar8 + iVar3) * 4);

            uVar6 = *(int *)(local_f4 + 0xc) + iVar8;

            uVar5 = uVar6 >> 2;

            iVar3 = uVar5 * -4;

            if (*(uint *)(local_f4 + 8) <= uVar5) {

              uVar5 = uVar5 - *(uint *)(local_f4 + 8);

            }

            fStack_a8 = fStack_b8 -

                        (float)*(int *)(*(int *)(*(int *)(local_f4 + 4) + uVar5 * 4) +

                                       (uVar6 + iVar3) * 4) * fVar7;

            local_ac = (char *)((float)puStack_b4 - (float)(int)pcStack_100 * (float)puStack_fc);

            FUN_00757970();

            iStack_c0 = iStack_c0 + -1;

            local_d8 = local_ac;

            fStack_d4 = fStack_a8;

            fVar7 = fStack_e4;

          } while (iStack_c0 != 0);

        }

      }

      uStack_104 = uStack_104 + -0x1c;

      uStack_f0 = (float)((int)uStack_f0 + -4);

      local_f4 = local_f4 + -0x14;

      fStack_e8 = (float)((int)fStack_e8 + -1);

    } while (fStack_e8 != 0.0);

    iVar4 = param_2[0x1a] + 1;

    param_2[0x1a] = iVar4;

    param_2[0x1d] = (int)(float)-iVar4;

    fStack_e8 = 0.0;

    if (param_2[0x1c] < iVar4) {

      param_2[0x1c] = iVar4;

    }

  }

  fVar7 = (float)*(int *)(iStack_ec + 0x54) / (float)*(int *)(iStack_ec + 0x58);

  if (0.0 < fVar7) {

    puStack_fc = (uint8_t *)((int)pcStack_108 + (int)fStack_b0);

    fStack_b0 = (float)iStack_e0 / fVar7;

    pcStack_100 = (char *)(iStack_114 + 0x80);

    piStack_118 = (int *)(iStack_ec + 0x44);

    local_f4 = 0;

    puStack_b4 = (uint8_t *)(fStack_b0 * 0.0);

    piVar9 = (int *)(iStack_114 + 0x14);

    fStack_b8 = 0.0;

    do {

      uStack_104 = (char *)((float)*piStack_118 / (float)*(int *)(iStack_ec + 0x58));

      piVar9[-1] = (int)pcStack_108;

      piVar9[1] = (int)puStack_fc;

      uVar6 = -((uint)puStack_b4 >> 0x17 & 0xff);

      uVar5 = -(uint)(0xffffff69 < uVar6);

      fStack_e8 = (float)((uint)puStack_b4 & (uVar5 << ((char)uVar6 + 0x96U & 0x1f) | ~uVar5));

      pcStack_c8 = (char *)(int)ROUND(fStack_e8);

      fStack_b8 = (float)uStack_104 + fStack_b8;

      puStack_b4 = (uint8_t *)(fStack_b8 * fStack_b0);

      piVar9[-2] = (int)pcStack_c8;

      uVar6 = -((uint)puStack_b4 >> 0x17 & 0xff);

      uVar5 = -(uint)(0xffffff69 < uVar6);

      fStack_e4 = (float)((uint)puStack_b4 & (uVar5 << ((char)uVar6 + 0x96U & 0x1f) | ~uVar5));

      iStack_c0 = (int)ROUND(fStack_e4);

      iVar4 = piVar9[2];

      *piVar9 = iStack_c0;

      pcStack_100[3] = (char)iStack_bc;

      if ((char)iVar4 == '\0') {

        pcStack_100[3] = 'P';

      }

      pcStack_14c = (char *)(float)piVar9[1];

      uStack_144 = 0;

      pcStack_148 = &DAT_00d1ec78;

      FUN_00758460((float)piVar9[-2],(float)piVar9[-1],(float)*piVar9);

      if (*(char *)((int)piVar9 + 9) != '\0') {

        pcStack_1c = "Pal3D";

        puStack_18 = &DAT_00a2daf4;

        pcStack_14 = "Application";

        pcStack_10 = "Stats";

        uStack_144 = 0x7439f9;

        sprintf(acStack_9c,"%s: %1.3fms");

        FUN_00755ab0();

        fStack_d4 = (float)(piVar9[4] - (int)fStack_a8 / 2);

        local_d8 = (uint8_t *)(piVar9[3] - (int)local_ac / 2);

        if ((int)local_d8 < 0) {

          local_d8 = (uint8_t *)0x0;

        }

        if (iStack_e0 < (int)(local_d8 + (int)local_ac)) {

          local_d8 = (uint8_t *)(iStack_e0 - (int)local_ac);

        }

        iVar4 = param_2[0x1a] + 1;

        pcStack_14c = (char *)-iVar4;

        param_2[0x1a] = iVar4;

        param_2[0x1d] = (int)(float)(int)pcStack_14c;

        if (param_2[0x1c] < iVar4) {

          param_2[0x1c] = iVar4;

        }

        uStack_144 = 0xffffffff;

        pcStack_148 = acStack_9c;

        piVar2 = (int *)*pfStack_f8;

        if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

          (**(code **)(*piVar2 + 4))();

        }

        pcStack_14c = (char *)*pfStack_f8;

        uStack_f0 = (float)CONCAT13((char)iStack_bc,0xc8e6c8);

        FUN_00759730(param_2,&local_d8,&uStack_f0);

        param_2[0x1a] = param_2[0x1a] + -1;

        iVar4 = param_2[0x1a];

        param_2[0x1d] = (int)(float)-iVar4;

        if (param_2[0x1c] < iVar4) {

          param_2[0x1c] = iVar4;

        }

      }

      piStack_118 = piStack_118 + 1;

      pcStack_100 = pcStack_100 + 4;

      local_f4 = local_f4 + 1;

      piVar9 = piVar9 + 7;

    } while (local_f4 < 4);

  }

  param_2[0x1a] = param_2[0x1a] + -1;

  iVar4 = param_2[0x1a];

  param_2[0x1d] = (int)(float)-iVar4;

  if (param_2[0x1c] < iVar4) {

    param_2[0x1c] = iVar4;

  }

  FUN_00757230();

  param_2[0x1a] = param_2[0x1a] + -1;

  iVar4 = param_2[0x1a];

  param_2[0x1d] = (int)(float)-iVar4;

  if (param_2[0x1c] < iVar4) {

    param_2[0x1c] = iVar4;

  }

  FUN_00759090();

  return 0;

}
