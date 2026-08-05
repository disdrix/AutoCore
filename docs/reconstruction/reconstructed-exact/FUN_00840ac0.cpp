// =============================================================================
// FUN_00840ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00840ac0
// Address:   0x00840ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00840ac0 @ 0x00840ac0
// Stable ID: aa_00840ac0
// Embedded strings (evidence for future rename):
//   - "\nStatus Effects Nullified: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~287 non-empty decompiler lines.
//  - Control keywords: if×28, do×8, while×8, return×6, goto×5, for×1.
//  - Notable callees: FUN_007a6de0×4, FUN_005506a0×2, CONCAT31, FUN_007a4480, FUN_007a69d0, FUN_007fcb80, FUN_0083f510, FUN_00840ac0.
//  - Strings: "\nStatus Effects Nullified: %s\n".
//  - Return sites: 6.

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

void FUN_00840ac0(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int *in_EAX;

  char *pcVar4;

  float *pfVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  uint uVar9;

  uint16_t *puVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iStack_c14;

  uint8_t *puStack_c10;

  float *pfStack_c0c;

  uint8_t *puStack_c08;

  uint8_t **ppuStack_c04;

  short sRank;

  uint8_t *puStack_bf0;

  int iStack_bec;

  uint8_t *puStack_be8;

  float fStack_be4;

  int iVar13;

  uint8_t auStack_bc8 [4];

  int iStack_bc4;

  uint8_t local_bc0 [3];

  uint32_t /* width from decompiler */ uStack_bbd;

  char acStack_bb6 [2];

  int iStack_bb4;

  uint8_t auStack_bac [136];

  char acStack_b24 [192];

  uint8_t auStack_a64 [8];

  uint8_t auStack_a5c [1032];

  int aiStack_654 [5];

  uint8_t local_640;

  int iStack_64;

  int iStack_5e;

  

  local_640 = 0;

  _local_bc0 = FUN_007a69d0();

  cVar3 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar3 == '\0') {

    fStack_be4 = 1.2126229e-38;

    FUN_007a4480();

    return;

  }

  if ((DAT_00d1a8f4 != '\0') && ((char *)((int)in_EAX + 0x6bd) != (char *)0x0)) {

    fStack_be4 = 1.2126286e-38;

    pcVar4 = strstr((char *)((int)in_EAX + 0x6bd),"[$");

    if (pcVar4 != (char *)0x0) {

      FUN_0083f510();

      return;

    }

  }

  if (in_EAX[0x2d8] == 0) {

    return;

  }

  if (in_EAX[0x2d5] == 0) {

    return;

  }

  if (in_EAX[0x2d9] == 0) {

    return;

  }

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x124))();

  iStack_bb4 = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  iVar13 = 0;

  piVar7 = (int *)in_EAX[0x2d5];

  fStack_be4 = 1.4013e-45;

  puStack_be8 = auStack_bac;

  iStack_bec = 0x840bad;

  (**(code **)(*piVar7 + 0x120))();

  iStack_bec = 1;

  puStack_bf0 = auStack_bc8;

  iVar6 = (**(code **)(*piVar7 + 0x140))();

  iStack_bc4 = *(int *)(iVar13 + 4) + *(int *)(iVar6 + 4) + in_EAX[0x144];

  sRank = (short)auStack_bc8;

  (**(code **)(*(int *)in_EAX[0x2d8] + 0x118))();

  (**(code **)(*(int *)in_EAX[0x2d8] + 0x268))();

  auStack_a5c[0] = 0;

  if ((char)in_EAX[0x13f] == '\0') {

    iVar6 = *(int *)in_EAX[0x2d8];

    ppuStack_c04 = (uint8_t **)0x840f07;

    FUN_007a6de0();

    (**(code **)(iVar6 + 0x224))();

    if (0 < *(short *)((int)in_EAX + 0xb0e)) {

      if (in_EAX[0x2c2] != 0) {

        *(uint32_t /* width from decompiler */ *)(in_EAX[0x2c2] + 0x688) = DAT_00d1b644;

      }

      FUN_005506a0();

      (**(code **)(*(int *)in_EAX[0x2d8] + 0x224))();

      goto LAB_00840f8b;

    }

LAB_00840f6f:

    iVar6 = *(int *)in_EAX[0x2d8];

  }

  else {

    if (in_EAX[0x145] == 0) goto LAB_00840f8b;

    ppuStack_c04 = (uint8_t **)auStack_a5c;

    puStack_c08 = (uint8_t *)0x840c3a;

    iVar6 = (**(code **)(*(int *)in_EAX[0x145] + 0x30))();

    if (0 < iVar6) {

      (**(code **)(*(int *)in_EAX[0x2d8] + 0x224))();

    }

    uVar9 = in_EAX[0x2ce];

    if (uVar9 != 0) {

      uStack_bbd._1_1_ = 0;

      puVar10 = (uint16_t *)(local_bc0 + 3);

      do {

        pcVar4 = (char *)((int)puVar10 + 1);

        puVar10 = (uint16_t *)((int)puVar10 + 1);

      } while (*pcVar4 != '\0');

      *puVar10 = DAT_00a6c044;

      if ((uVar9 & 0x100000) == 0) {

        uVar9 = *(uint *)(DAT_00d1b6d8 + 0x318) & uVar9;

        if (uVar9 == 0) goto LAB_00840e5a;

        if ((uVar9 & 2) != 0) {

          pcVar4 = local_bc0 + 3;

          do {

            pcVar11 = pcVar4;

            pcVar4 = pcVar11 + 1;

          } while (pcVar11[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 1) = s_Stunned__00a6c010._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 5) = s_Stunned__00a6c010._4_4_;

          pcVar11[9] = s_Stunned__00a6c010[8];

        }

        if ((uVar9 & 4) != 0) {

          pcVar4 = local_bc0 + 3;

          do {

            pcVar11 = pcVar4;

            pcVar4 = pcVar11 + 1;

          } while (pcVar11[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 1) = s_Lockdown__00a6c004._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 5) = s_Lockdown__00a6c004._4_4_;

          *(uint16_t *)(pcVar11 + 9) = s_Lockdown__00a6c004._8_2_;

        }

        if ((uVar9 & 8) != 0) {

          pcVar4 = local_bc0 + 3;

          do {

            pcVar11 = pcVar4;

            pcVar4 = pcVar11 + 1;

          } while (pcVar11[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 1) = s_Silence__00a6bff8._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 5) = s_Silence__00a6bff8._4_4_;

          pcVar11[9] = s_Silence__00a6bff8[8];

        }

        if ((uVar9 & 0x10) != 0) {

          pcVar4 = local_bc0 + 3;

          do {

            pcVar11 = pcVar4;

            pcVar4 = pcVar11 + 1;

          } while (pcVar11[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 1) = s_No_Fire__00a6bfec._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 5) = s_No_Fire__00a6bfec._4_4_;

          pcVar11[9] = s_No_Fire__00a6bfec[8];

        }

        if ((uVar9 & 0x200) != 0) {

          pcVar4 = local_bc0 + 3;

          do {

            pcVar11 = pcVar4;

            pcVar4 = pcVar11 + 1;

          } while (pcVar11[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar11 + 1) = s_Blind__00a6bfe4._0_4_;

          *(uint16_t *)(pcVar11 + 5) = s_Blind__00a6bfe4._4_2_;

          pcVar11[7] = s_Blind__00a6bfe4[6];

        }

        if ((uVar9 & 0x40) != 0) {

          puVar2 = (uint32_t /* width from decompiler */ *)(local_bc0 + 3);

          do {

            puVar12 = puVar2;

            puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

          } while (*(char *)((int)puVar12 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a6bfdc;

          *(uint16_t *)((int)puVar12 + 5) = DAT_00a6bfe0;

        }

        if ((uVar9 & 0x1000) != 0) {

          puVar2 = (uint32_t /* width from decompiler */ *)(local_bc0 + 3);

          do {

            puVar12 = puVar2;

            puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

          } while (*(char *)((int)puVar12 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a6bfd4;

          *(uint16_t *)((int)puVar12 + 5) = DAT_00a6bfd8;

        }

        pcVar4 = strrchr((char *)((int)&uStack_bbd + 1),0x2c);

        if (pcVar4 != (char *)0x0) {

          pcVar4[0] = '}';

          pcVar4[1] = '\0';

        }

        ppuStack_c04 = (uint8_t **)0x840e26;

        sprintf(acStack_b24,"\nStatus Effects Nullified: %s\n");

      }

      iVar6 = *(int *)in_EAX[0x2d8];

      ppuStack_c04 = (uint8_t **)0x840e49;

      FUN_007a6de0();

      (**(code **)(iVar6 + 0x224))();

    }

LAB_00840e5a:

    if ((*(byte *)(in_EAX[0x145] + 0x639) & 2) == 0) {

      if ((*(char *)(in_EAX[0x145] + 0xfe) != '\0') && (iVar6 = FUN_007fcb80(), iVar6 != 0))

      goto LAB_00840f6f;

      if (((*(char *)(in_EAX[0x145] + 0xfe) == '\0') || (DAT_00d1b938 == 0)) ||

         (cVar3 = FUN_0088a910(), cVar3 == '\0')) goto LAB_00840f8b;

      iVar6 = *(int *)in_EAX[0x2d8];

    }

    else {

      iVar6 = *(int *)in_EAX[0x2d8];

    }

  }

  ppuStack_c04 = (uint8_t **)0x840f7e;

  FUN_007a6de0();

  (**(code **)(iVar6 + 0x224))();

LAB_00840f8b:

  (**(code **)(*(int *)in_EAX[0x2d9] + 0x268))();

  if (((char)in_EAX[0x13f] == '\0') &&

     (*(short *)((int)in_EAX + 0xb0e) < (short)(ushort)*(byte *)(in_EAX + 0x2c3))) {

    piVar7 = in_EAX + 0x146;

    piVar8 = aiStack_654;

    for (iVar6 = 0x18c; iVar6 != 0; iVar6 = iVar6 + -1) {

      *piVar8 = *piVar7;

      piVar7 = piVar7 + 1;

      piVar8 = piVar8 + 1;

    }

    auStack_a5c[0] = 0;

    Skill_SetRankAndReevaluate(aiStack_654,(void *)(iStack_5e + 1),sRank);

    if (iStack_64 != 0) {

      *(uint32_t /* width from decompiler */ *)(iStack_64 + 0x688) = DAT_00d1b644;

    }

    FUN_005506a0();

    iVar6 = *(int *)in_EAX[0x2d9];

    ppuStack_c04 = (uint8_t **)0x84103a;

    FUN_007a6de0();

    (**(code **)(iVar6 + 0x224))();

    ppuStack_c04 = (uint8_t **)auStack_a64;

    puStack_c08 = (uint8_t *)0x841062;

    (**(code **)(*(int *)in_EAX[0x2d9] + 0x224))();

    puStack_c08 = (uint8_t *)0x1;

    pfStack_c0c = (float *)0x841072;

    (**(code **)(*(int *)in_EAX[0x2d9] + 0xcc))();

  }

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d9] + 0x134))();

  puStack_be8 = (uint8_t *)(int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  fStack_be4 = (float)(int)((float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678);

  (**(code **)(*(int *)in_EAX[0x2d9] + 300))();

  ppuStack_c04 = (uint8_t **)0x8410e4;

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x134))();

  puStack_be8 = (uint8_t *)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  fStack_be4 = (float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678;

  puStack_bf0 = (uint8_t *)(int)(float)puStack_be8;

  iStack_bec = (int)fStack_be4;

  ppuStack_c04 = &puStack_bf0;

  puStack_c08 = (uint8_t *)0x841150;

  (**(code **)(*(int *)in_EAX[0x2d8] + 300))();

  puStack_c08 = (uint8_t *)0x1;

  pfStack_c0c = &fStack_be4;

  puStack_c10 = (uint8_t *)0x841165;

  (**(code **)(*(int *)in_EAX[0x2d9] + 0x140))();

  puStack_c10 = &stack0xfffff404;

  iStack_c14 = 0x841186;

  (**(code **)(*(int *)in_EAX[0x2d9] + 300))();

  fVar1 = fStack_be4;

  iStack_c14 = 1;

  piVar7 = (int *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x140))(&puStack_bf0);

  puStack_c08 = puStack_bf0 + in_EAX[0x143] + *piVar7;

  ppuStack_c04 = (uint8_t **)fVar1;

  (**(code **)(*(int *)in_EAX[0x2d9] + 0x118))(&puStack_c08);

  cVar3 = (**(code **)(*(int *)in_EAX[0x2d9] + 0xd0))();

  if (cVar3 == '\0') {

    piVar7 = (int *)(**(code **)(*(int *)in_EAX[0x2d9] + 0x140))(&stack0xfffff404,1);

    piVar8 = (int *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x140))(&stack0xfffff40c,1);

    iStack_c14 = *piVar8 + *piVar7 + in_EAX[0x143];

  }

  else {

    (**(code **)(*(int *)in_EAX[0x2d9] + 0x13c))();

    (**(code **)(*(int *)in_EAX[0x2d9] + 0x34c))();

    piVar7 = (int *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x140))(&stack0xfffff404,1);

    iStack_c14 = *piVar7;

  }

  puStack_c10 = (uint8_t *)0x0;

  (**(code **)(*(int *)in_EAX[0x2d8] + 300))(&iStack_c14);

  (**(code **)(*(int *)in_EAX[0x2d8] + 0x13c))();

  piVar7 = (int *)in_EAX[0x2d8];

  (**(code **)(*piVar7 + 0xcc))(CONCAT31((int3)((uint)piVar7 >> 8),piVar7[0x83] != 0));

  (**(code **)(*(int *)in_EAX[0x2d8] + 0x34c))();

  return;

}
