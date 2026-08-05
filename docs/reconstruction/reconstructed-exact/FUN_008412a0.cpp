// =============================================================================
// FUN_008412a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008412a0
// Address:   0x008412a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008412a0 @ 0x008412a0
// Stable ID: aa_008412a0
// Embedded strings (evidence for future rename):
//   - "%s [%d]"
//   - "  %s %d."
//   - "%s  %s %d\n"
//   - "%s  %s %d, %d %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~572 non-empty decompiler lines.
//  - Control keywords: if×27, do×4, while×4, goto×3, for×3, return×2.
//  - Notable callees: FUN_007a6de0×6, sprintf×4, CONCAT22, FUN_0054fe50, FUN_00553010, FUN_00553090, FUN_005533f0, FUN_007a69d0.
//  - Strings: "%s [%d]"; "  %s %d."; "%s  %s %d\n"; "%s  %s %d, %d %s\n".
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

void FUN_008412a0(void)



{

  ushort uVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  int iVar6;

  char *pcVar7;

  uint uVar8;

  int iVar9;

  int *piVar10;

  int *piVar11;

  int iVar12;

  int **ppiVar13;

  uint uVar14;

  char *pcVar15;

  uint8_t **ppuVar16;

  uint32_t /* width from decompiler */ *puStack_ae0;

  uint32_t /* width from decompiler */ uStack_adc;

  uint32_t /* width from decompiler */ **ppuStack_ad8;

  uint32_t /* width from decompiler */ uStack_ad4;

  uint32_t /* width from decompiler */ uStack_ad0;

  int *piStack_acc;

  uint32_t /* width from decompiler */ *puStack_ac8;

  uint32_t /* width from decompiler */ uStack_ac4;

  uint32_t /* width from decompiler */ *puStack_ac0;

  int iStack_abc;

  uint8_t **ppuStack_ab8;

  uint32_t /* width from decompiler */ uStack_ab4;

  uint8_t *puStack_ab0;

  int *piStack_aac;

  uint32_t /* width from decompiler */ uStack_aa8;

  uint32_t /* width from decompiler */ uStack_aa4;

  int *piStack_aa0;

  uint32_t /* width from decompiler */ *puStack_a9c;

  uint32_t /* width from decompiler */ uStack_a98;

  uint8_t *puStack_a94;

  int iStack_a90;

  int ***pppiStack_a8c;

  uint32_t /* width from decompiler */ uStack_a88;

  uint32_t /* width from decompiler */ uStack_a84;

  uint32_t /* width from decompiler */ uStack_a80;

  uint32_t /* width from decompiler */ uStack_a7c;

  int **ppiStack_a54;

  uint32_t /* width from decompiler */ ***pppuStack_a50;

  uint32_t /* width from decompiler */ *puStack_a4c;

  uint32_t /* width from decompiler */ **ppuStack_a48;

  int iStack_a44;

  float fStack_a40;

  uint32_t /* width from decompiler */ ***pppuStack_a3c;

  uint32_t /* width from decompiler */ uStack_a38;

  int *piStack_a34;

  uint32_t /* width from decompiler */ uStack_a30;

  uint32_t /* width from decompiler */ uStack_a2c;

  uint32_t /* width from decompiler */ uStack_a28;

  uint32_t /* width from decompiler */ uStack_a24;

  uint32_t /* width from decompiler */ uStack_a20;

  uint32_t /* width from decompiler */ **ppuStack_a1c;

  uint32_t /* width from decompiler */ **ppuStack_a18;

  char ***pppcStack_a14;

  uint32_t /* width from decompiler */ uStack_a10;

  uint32_t /* width from decompiler */ *puStack_a0c;

  int *piStack_a08;

  uint8_t *puStack_a04;

  uint32_t /* width from decompiler */ *puStack_a00;

  uint32_t /* width from decompiler */ ***pppuStack_9fc;

  int iStack_9f8;

  uint8_t *puStack_9f4;

  float fStack_9f0;

  float fStack_9ec;

  uint32_t /* width from decompiler */ **ppuStack_9e8;

  uint32_t /* width from decompiler */ uStack_9e4;

  uint32_t /* width from decompiler */ uStack_9e0;

  uint32_t /* width from decompiler */ uStack_9dc;

  uint32_t /* width from decompiler */ uStack_9d8;

  uint32_t /* width from decompiler */ **ppuStack_9d4;

  uint32_t /* width from decompiler */ *puStack_9c0;

  uint32_t /* width from decompiler */ *puStack_9bc;

  int iStack_9b8;

  uint32_t /* width from decompiler */ *puStack_9b4;

  uint32_t /* width from decompiler */ uStack_9b0;

  uint32_t /* width from decompiler */ uStack_9ac;

  uint32_t /* width from decompiler */ *puStack_9a8;

  uint32_t /* width from decompiler */ uStack_9a4;

  uint32_t /* width from decompiler */ uStack_9a0;

  uint32_t /* width from decompiler */ uStack_99c;

  uint32_t /* width from decompiler */ uStack_998;

  int **ppiStack_994;

  uint32_t /* width from decompiler */ uStack_990;

  int *piStack_98c;

  int *piStack_980;

  int iStack_97c;

  uint8_t *puStack_978;

  uint32_t /* width from decompiler */ uStack_974;

  uint8_t local_964 [32];

  uint32_t /* width from decompiler */ local_944;

  uint32_t /* width from decompiler */ uStack_940;

  uint32_t /* width from decompiler */ uStack_93c;

  char acStack_910 [8];

  uint8_t local_908;

  char acStack_8d8 [127];

  char cStack_859;

  char acStack_858 [2];

  uint32_t /* width from decompiler */ auStack_856 [532];

  

  if (DAT_00d1b6d8 == (char ***)0x0) {

    return;

  }

  if (in_EAX[0x2d4] == 0) goto LAB_00841e2f;

  uStack_974 = 0x8412d0;

  local_944 = FUN_007a69d0();

  uStack_974 = 1;

  puStack_978 = local_964;

  local_908 = 0;

  iStack_97c = 0x8412f0;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)in_EAX[0x2d4] + 0x140))();

  uStack_940 = *puVar4;

  uStack_93c = puVar4[1];

  if ((char)in_EAX[0x13f] == '\0') {

    iStack_97c = 1;

    piStack_980 = (int *)0x1;

    (**(code **)(*(int *)in_EAX[0x2d4] + 0x1d8))();

  }

  else {

    if ((DAT_00d1b6d8 == (char ***)0x0) || ((int)DAT_00d1b6d8[0x1ad] < 1)) {

      piVar10 = in_EAX + 0x1a7;

      iVar6 = -(int)piVar10;

      do {

        iVar9 = *piVar10;

        (acStack_910 + iVar6)[(int)piVar10] = (char)iVar9;

        piVar10 = (int *)((int)piVar10 + 1);

      } while ((char)iVar9 != '\0');

    }

    else {

      piStack_980 = in_EAX + 0x1a7;

      iStack_97c = (int)(short)(*(short *)((int)in_EAX + 0xb0e) + (short)in_EAX[0x1a3]);

      piStack_98c = (int *)0x84135c;

      sprintf(acStack_910,"%s [%d]");

    }

    iStack_97c = 1;

    piStack_980 = (int *)0x1;

    (**(code **)(*(int *)in_EAX[0x2d4] + 0x1d8))();

  }

  piStack_98c = (int *)0x8413a6;

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d4] + 0x134))();

  iStack_97c = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  puStack_978 = (uint8_t *)(int)((float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678);

  piStack_98c = &iStack_97c;

  uStack_990 = 0x8413f2;

  (**(code **)(*(int *)in_EAX[0x2d4] + 300))();

  uStack_990 = 0x841400;

  (**(code **)(*(int *)in_EAX[0x2d4] + 0x13c))();

  uStack_990 = 1;

  ppiStack_994 = &piStack_980;

  uStack_998 = 0x841415;

  (**(code **)(*(int *)in_EAX[0x2d4] + 0x140))();

  if (*(short *)((int)in_EAX + 0xb0e) < 1) {

    uStack_998 = 0xffbbbbbb;

    uStack_99c = 1;

    uStack_9a0 = 0x841442;

    (**(code **)(*(int *)in_EAX[0x2d4] + 0x160))();

  }

  else {

    uStack_998 = 0xffffffff;

    uStack_99c = 1;

    uStack_9a0 = 0x841431;

    (**(code **)(*(int *)in_EAX[0x2d4] + 0x160))();

  }

  uStack_9a0 = 0;

  uStack_9a4 = 1;

  puStack_9a8 = &uStack_990;

  uStack_9ac = 0x841459;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d7] + 0x120))();

  piStack_980 = *(int **)(iVar6 + 4);

  piVar10 = (int *)in_EAX[0x2d4];

  uStack_9ac = 0;

  uStack_9b0 = 1;

  puStack_9b4 = &uStack_99c;

  iStack_9b8 = 0x84147f;

  uStack_9a0 = (**(code **)(*piVar10 + 0x120))();

  iStack_9b8 = 1;

  puStack_9bc = &uStack_998;

  puStack_9c0 = (uint32_t /* width from decompiler */ *)0x841494;

  iVar6 = (**(code **)(*piVar10 + 0x140))();

  ppiStack_994 = (int **)(puStack_9a8[1] + *(int *)(iVar6 + 4) + in_EAX[0x144]);

  puStack_9c0 = &uStack_998;

  (**(code **)(*(int *)in_EAX[0x2d7] + 0x118))();

  if ((DAT_00d1b6d8 != (char ***)0x0) && (0 < (int)DAT_00d1b6d8[0x1ad])) {

    acStack_858[0] = '\0';

    acStack_858[1] = '\0';

    puVar4 = auStack_856;

    for (iVar6 = 0x1ff; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    pcVar7 = (char *)((int)in_EAX + 0x6bd);

    if (pcVar7 != (char *)0x0) {

      iVar6 = -2 - (int)pcVar7;

      do {

        cVar3 = *pcVar7;

        pcVar7[(int)auStack_856 + iVar6] = cVar3;

        pcVar7 = pcVar7 + 1;

      } while (cVar3 != '\0');

    }

    FUN_007a6de0();

    ppuStack_9d4 = (uint32_t /* width from decompiler */ **)0x841539;

    sprintf(acStack_8d8,"  %s %d.");

    pcVar7 = acStack_8d8;

    do {

      cVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar3 != '\0');

    uVar8 = (int)pcVar7 - (int)acStack_8d8;

    pcVar7 = &cStack_859;

    do {

      pcVar15 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar15 != '\0');

    pcVar15 = acStack_8d8;

    for (uVar14 = uVar8 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar15;

      pcVar15 = pcVar15 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar7 = *pcVar15;

      pcVar15 = pcVar15 + 1;

      pcVar7 = pcVar7 + 1;

    }

  }

  (**(code **)(*(int *)in_EAX[0x2d7] + 0x1d8))();

  ppuStack_9d4 = (uint32_t /* width from decompiler */ **)0x8415ad;

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d7] + 0x134))();

  puStack_9c0 = (uint32_t /* width from decompiler */ *)((float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678);

  puStack_9bc = (uint32_t /* width from decompiler */ *)(int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  iStack_9b8 = (int)(float)puStack_9c0;

  ppuStack_9d4 = &puStack_9bc;

  uStack_9d8 = 0x841619;

  (**(code **)(*(int *)in_EAX[0x2d7] + 300))();

  uStack_9d8 = 0x841627;

  (**(code **)(*(int *)in_EAX[0x2d7] + 0x13c))();

  uStack_9d8 = 0x841635;

  (**(code **)(*(int *)in_EAX[0x2d7] + 0x34c))();

  if (*(short *)((int)in_EAX + 0xb0e) < 1) {

    uStack_9d8 = 0xffbbbbbb;

    uStack_9dc = 1;

    uStack_9e0 = 0x841665;

    (**(code **)(*(int *)in_EAX[0x2d7] + 0x160))();

  }

  else {

    uStack_9d8 = 0xffcccce0;

    uStack_9dc = 1;

    uStack_9e0 = 0x841654;

    (**(code **)(*(int *)in_EAX[0x2d7] + 0x160))();

  }

  uStack_9e0 = 0;

  uStack_9e4 = 1;

  ppuStack_9e8 = &puStack_9c0;

  fStack_9ec = 1.2130351e-38;

  (**(code **)(*(int *)in_EAX[0x2d5] + 0x120))();

  fStack_9ec = 0.0;

  piVar10 = (int *)in_EAX[0x2d7];

  fStack_9f0 = 1.4013e-45;

  puStack_9f4 = &stack0xfffff634;

  iStack_9f8 = 0x84169b;

  iVar6 = (**(code **)(*piVar10 + 0x120))();

  iStack_9f8 = 1;

  pppuStack_9fc = &ppuStack_9e8;

  puStack_a00 = (uint32_t /* width from decompiler */ *)0x8416ae;

  iVar9 = (**(code **)(*piVar10 + 0x140))();

  puStack_a00 = &uStack_9e0;

  ppuStack_9d4 = (uint32_t /* width from decompiler */ **)(*(int *)(iVar6 + 4) + *(int *)(iVar9 + 4) + in_EAX[0x144]);

  puStack_a04 = (uint8_t *)0x8416d1;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d5] + 0x134))();

  puStack_a04 = &stack0xfffff630;

  fStack_9ec = (float)DAT_00d1e81c * *(float *)(iVar6 + 4) * DAT_00aaa678;

  piStack_a08 = (int *)0x841703;

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d5] + 0x134))();

  puStack_9f4 = (uint8_t *)(int)fStack_9f0;

  iStack_9f8 = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  piStack_a08 = &iStack_9f8;

  puStack_a0c = (uint32_t /* width from decompiler */ *)0x841740;

  (**(code **)(*(int *)in_EAX[0x2d5] + 300))();

  puStack_a0c = &uStack_9e4;

  uStack_a10 = 0x841753;

  (**(code **)(*(int *)in_EAX[0x2d5] + 0x118))();

  uStack_a10 = 0;

  pppcStack_a14 = (char ***)0x841763;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d5] + 0x164))();

  *(uint8_t *)(iVar6 + 3) = 0xff;

  if ((char)in_EAX[0x13f] == '\0') {

    pppcStack_a14 = DAT_00d1b6d8;

    ppuStack_a18 = &puStack_9a8;

    ppuStack_a1c = (uint32_t /* width from decompiler */ **)0x84178b;

    FUN_00553090();

    pppcStack_a14 = (char ***)0x1;

    ppuStack_a18 = (uint32_t /* width from decompiler */ **)0x1;

    ppuStack_a1c = &puStack_9a8;

    uStack_a20 = 0x8417a2;

    (**(code **)(*(int *)in_EAX[0x2d5] + 0x1d8))();

    uVar1 = *(ushort *)((int)in_EAX + 0xb0e);

    if ((short)uVar1 < 1) {

      piVar10 = (int *)in_EAX[0x2d5];

      uStack_a20 = 0xffbbbbbb;

LAB_008417f5:

      uStack_a24 = 1;

      uStack_a28 = 0x8417ff;

      (**(code **)(*piVar10 + 0x160))();

    }

    else {

      piVar10 = (int *)in_EAX[0x2d5];

      if ((short)(ushort)*(byte *)(in_EAX + 0x2c3) < (short)uVar1) {

        uStack_a20 = 0xff20ff20;

        uStack_a24 = 1;

        uStack_a28 = 0x8417d1;

        (**(code **)(*piVar10 + 0x160))();

      }

      else {

        if (uVar1 == *(byte *)(in_EAX + 0x2c3)) {

          uStack_a20 = 0xffaedeff;

          goto LAB_008417f5;

        }

        uStack_a20 = 0xffffffff;

        uStack_a24 = 1;

        uStack_a28 = 0x8417e8;

        (**(code **)(*piVar10 + 0x160))();

      }

    }

    uStack_a28 = 1;

    uStack_a2c = 0x84180f;

    (**(code **)(*(int *)in_EAX[0x2d5] + 0xcc))();

  }

  else {

    pppcStack_a14 = (char ***)0x0;

    ppuStack_a18 = (uint32_t /* width from decompiler */ **)0x841821;

    (**(code **)(*(int *)in_EAX[0x2d5] + 0xcc))();

  }

  uStack_a2c = 0;

  uStack_a30 = 1;

  piStack_a34 = &iStack_9f8;

  uStack_a38 = 0x841838;

  piVar10 = (int *)(**(code **)(*(int *)in_EAX[0x2d5] + 0x120))();

  uStack_a38 = 1;

  pppuStack_a3c = &ppuStack_a18;

  fStack_a40 = 1.2131006e-38;

  piVar11 = (int *)(**(code **)(*(int *)in_EAX[0x2d5] + 0x140))();

  ppuStack_a18 = (uint32_t /* width from decompiler */ **)(*piVar11 + in_EAX[0x143] + *piVar10);

  fStack_a40 = 0.0;

  iStack_a44 = 1;

  ppuStack_a48 = &puStack_a0c;

  puStack_a4c = (uint32_t /* width from decompiler */ *)0x841874;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d5] + 0x120))();

  uStack_a20 = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

  puStack_a4c = &uStack_a24;

  pppuStack_a50 = (uint32_t /* width from decompiler */ ***)0x84188e;

  (**(code **)(*(int *)in_EAX[0x2d6] + 0x118))();

  pppuStack_a50 = &ppuStack_a1c;

  ppiStack_a54 = (int **)0x8418a1;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d6] + 0x134))();

  ppiStack_a54 = &piStack_a34;

  pppuStack_a3c = (uint32_t /* width from decompiler */ ***)((float)DAT_00d1e81c * *(float *)(iVar6 + 4) * DAT_00aaa678);

  pfVar5 = (float *)(**(code **)(*(int *)in_EAX[0x2d6] + 0x134))();

  iStack_a44 = (int)fStack_a40;

  ppuStack_a48 = (uint32_t /* width from decompiler */ **)(int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c);

  (**(code **)(*(int *)in_EAX[0x2d6] + 300))();

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d6] + 0x164))();

  *(uint8_t *)(iVar6 + 3) = 0xff;

  if (((char)in_EAX[0x13f] == '\0') &&

     (*(short *)((int)in_EAX + 0xb0e) < (short)(ushort)*(byte *)(in_EAX + 0x2c3))) {

    iVar6 = FUN_0054fe50();

    iVar9 = (**(code **)(*(int *)(DAT_00d1b6d8[1][1] + 4 + (int)DAT_00d1b6d8) + 0x27c))();

    if (iVar9 < iVar6) {

      ppuStack_a48 = (uint32_t /* width from decompiler */ **)

                     CONCAT22((short)((uint)iVar9 >> 0x10),*(short *)((int)in_EAX + 0x51a));

      if (*(short *)((int)in_EAX + 0x51a) == 0) {

        FUN_007a6de0();

        FUN_007a6de0();

        sprintf((char *)&puStack_9f4,"%s  %s %d\n");

      }

      else {

        FUN_007a6de0();

        FUN_007a6de0();

        FUN_007a6de0();

        uStack_a7c = 0x8419d4;

        sprintf((char *)&puStack_9f4,"%s  %s %d, %d %s\n");

      }

      (**(code **)(*(int *)in_EAX[0x2d6] + 0x1d8))();

      (**(code **)(*(int *)in_EAX[0x2d6] + 0x160))();

      (**(code **)(*(int *)in_EAX[0x2d6] + 4))();

    }

    else if (*(short *)((int)in_EAX + 0xb0e) < (short)(ushort)*(byte *)(in_EAX + 0x2c3)) {

      FUN_00553010();

      (**(code **)(*(int *)in_EAX[0x2d6] + 0x1d8))();

      (**(code **)(*(int *)in_EAX[0x2d6] + 0xcc))();

      cVar3 = FUN_005533f0();

      if (cVar3 == '\0') {

        (**(code **)(*(int *)in_EAX[0x2d6] + 0x160))();

      }

      else {

        (**(code **)(*(int *)in_EAX[0x2d6] + 0x160))();

      }

    }

    else {

      (**(code **)(*(int *)in_EAX[0x2d6] + 0xcc))();

    }

  }

  else {

    (**(code **)(*(int *)in_EAX[0x2d6] + 0xcc))();

  }

  cVar3 = (**(code **)(*(int *)in_EAX[0x2d5] + 0xd0))();

  if ((cVar3 == '\0') && (cVar3 = (**(code **)(*(int *)in_EAX[0x2d6] + 0xd0))(), cVar3 == '\0')) {

    uStack_a7c = 0x841b27;

    (**(code **)(*(int *)in_EAX[0x2d5] + 0xcc))();

    uStack_a7c = 1;

    uStack_a80 = 1;

    uStack_a84 = 0;

    uStack_a88 = 0x841b3b;

    (**(code **)(*(int *)in_EAX[0x2d5] + 0x1d8))();

    uStack_a88 = 1;

    pppiStack_a8c = &ppiStack_a54;

    iStack_a90 = 0x841b50;

    iVar6 = (**(code **)(*(int *)in_EAX[0x2d5] + 0x140))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

    iStack_a90 = 1;

    puStack_a94 = &stack0xfffff590;

    uStack_a98 = 0x841b68;

    piVar10 = (int *)(**(code **)(*(int *)in_EAX[0x2d6] + 0x140))();

    uStack_a98 = 1;

    puStack_a9c = &uStack_a80;

    piStack_aa0 = (int *)0x841b7f;

    piVar11 = (int *)(**(code **)(*(int *)in_EAX[0x2d5] + 0x140))();

    piStack_aa0 = &iStack_a90;

    iStack_a90 = *piVar11 + in_EAX[0x143] + *piVar10;

    uStack_aa4 = 0x841ba4;

    pppiStack_a8c = (int ***)uVar2;

    (**(code **)(*(int *)in_EAX[0x2d5] + 300))();

  }

  else {

    cVar3 = (**(code **)(*(int *)in_EAX[0x2d6] + 0xd0))();

    if (cVar3 == '\0') {

      uStack_aa4 = 1;

      uStack_aa8 = 0x841bc8;

      (**(code **)(*(int *)in_EAX[0x2d6] + 0xcc))();

      uStack_aa8 = 1;

      piStack_aac = (int *)0x1;

      puStack_ab0 = (uint8_t *)0x0;

      uStack_ab4 = 0x841bdc;

      (**(code **)(*(int *)in_EAX[0x2d6] + 0x1d8))();

      uStack_ab4 = 0x841bea;

      (**(code **)(*(int *)in_EAX[0x2d6] + 0x34c))();

    }

  }

  uStack_aa4 = 0;

  uStack_aa8 = 0x841bfa;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d8] + 0x164))();

  *(uint8_t *)(iVar6 + 3) = 0xff;

  uStack_aa8 = 0;

  piStack_aac = (int *)0x841c0e;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d9] + 0x164))();

  *(uint8_t *)(iVar6 + 3) = 0xff;

  piStack_aac = (int *)0x841c19;

  FUN_00840ac0();

  piVar10 = (int *)in_EAX[0x2d9];

  piStack_aac = (int *)0x1;

  puStack_ab0 = &stack0xfffff588;

  uStack_ab4 = 0x841c34;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d8] + 0x140))();

  uStack_ab4 = 1;

  ppuStack_ab8 = &puStack_a94;

  iStack_abc = 0x841c47;

  iVar9 = (**(code **)(*piVar10 + 0x140))();

  iStack_abc = 1;

  puStack_ac0 = &uStack_a88;

  if (*(int *)(iVar9 + 4) < *(int *)(iVar6 + 4)) {

    uStack_ac4 = 0x841c64;

    iVar6 = (**(code **)(*(int *)in_EAX[0x2d8] + 0x140))();

    ppuVar16 = *(uint8_t ***)(iVar6 + 4);

    uStack_ac4 = 1;

    puStack_ac8 = &uStack_aa4;

    piStack_acc = (int *)0x841c7c;

    piVar10 = (int *)(**(code **)(*(int *)in_EAX[0x2d9] + 0x140))();

    iStack_abc = *piVar10;

    piVar10 = (int *)in_EAX[0x2d9];

  }

  else {

    uStack_ac4 = 0x841c98;

    iVar6 = (**(code **)(*(int *)in_EAX[0x2d9] + 0x140))();

    ppuVar16 = *(uint8_t ***)(iVar6 + 4);

    uStack_ac4 = 1;

    puStack_ac8 = &uStack_aa4;

    piStack_acc = (int *)0x841cb0;

    piVar10 = (int *)(**(code **)(*(int *)in_EAX[0x2d8] + 0x140))();

    iStack_abc = *piVar10;

    piVar10 = (int *)in_EAX[0x2d8];

  }

  piStack_acc = &iStack_abc;

  uStack_ad0 = 0x841cca;

  ppuStack_ab8 = ppuVar16;

  (**(code **)(*piVar10 + 8))();

  uStack_ad0 = 0;

  uStack_ad4 = 1;

  ppuStack_ad8 = &puStack_a9c;

  uStack_adc = 0x841ce1;

  iVar6 = (**(code **)(*(int *)in_EAX[0x2d8] + 0x120))();

  iVar6 = *(int *)(iVar6 + 4);

  uStack_adc = 0x841cf2;

  cVar3 = (**(code **)(*(int *)in_EAX[0x2d8] + 0xd0))();

  if (cVar3 == '\0') {

    uStack_adc = 0x841d04;

    cVar3 = (**(code **)(*(int *)in_EAX[0x2d9] + 0xd0))();

    if (cVar3 != '\0') goto LAB_00841d0c;

  }

  else {

LAB_00841d0c:

    piVar10 = (int *)in_EAX[0x2d8];

    piVar11 = (int *)in_EAX[0x2d9];

    uStack_adc = 0;

    puStack_ae0 = (uint32_t /* width from decompiler */ *)0x1;

    piStack_aac = piVar10;

    uStack_ad0 = (**(code **)(*piVar11 + 0x120))(&uStack_aa8);

    iVar6 = (**(code **)(*piVar11 + 0x140))(&puStack_ac8,1);

    puVar4 = ppuStack_ad8[1];

    iVar6 = *(int *)(iVar6 + 4);

    iVar9 = (**(code **)(*piVar10 + 0x120))(&puStack_ae0,1,0);

    iVar12 = (**(code **)(*piStack_acc + 0x140))(&puStack_ab0,1);

    if ((int)puVar4 + iVar6 < *(int *)(iVar9 + 4) + *(int *)(iVar12 + 4)) {

      piVar10 = (int *)in_EAX[0x2d8];

      iVar6 = (**(code **)(*piVar10 + 0x120))(&puStack_ab0);

      ppiVar13 = &piStack_aac;

    }

    else {

      piVar10 = (int *)in_EAX[0x2d9];

      iVar6 = (**(code **)(*piVar10 + 0x120))(&uStack_aa8,1,0);

      ppiVar13 = &piStack_acc;

    }

    iVar9 = (**(code **)(*piVar10 + 0x140))(ppiVar13,1);

    iVar6 = *(int *)(iVar6 + 4) + *(int *)(iVar9 + 4);

  }

  uStack_adc = 1;

  puStack_ae0 = &uStack_a98;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)in_EAX[0x2d3] + 0x140))();

  uStack_aa8 = *puVar4;

  uStack_aa4 = puVar4[1];

  iVar9 = (**(code **)(*(int *)in_EAX[0x2d4] + 0x120))(&piStack_aa0,1,0);

  puStack_ab0 = (uint8_t *)(*(int *)(iVar9 + 4) + iVar6);

  (**(code **)(*(int *)in_EAX[0x2d3] + 8))(&uStack_ab4);

  (**(code **)(*in_EAX + 8))(&ppuStack_ab8);

LAB_00841e2f:

  if (in_EAX[0x2da] != 0) {

    uStack_974 = 0;

    puStack_978 = (uint8_t *)0x841e45;

    (**(code **)(*(int *)in_EAX[0x2da] + 4))();

  }

  if (in_EAX[0x2db] != 0) {

    uStack_974 = 0;

    puStack_978 = (uint8_t *)0x841e5b;

    (**(code **)(*(int *)in_EAX[0x2db] + 4))();

  }

  if (in_EAX[0x2dc] != 0) {

    uStack_974 = 0;

    puStack_978 = (uint8_t *)0x841e71;

    (**(code **)(*(int *)in_EAX[0x2dc] + 4))();

  }

  if (in_EAX[0x2dd] != 0) {

    uStack_974 = 0;

    puStack_978 = (uint8_t *)0x841e89;

    (**(code **)(*(int *)in_EAX[0x2dd] + 4))();

  }

  return;

}
