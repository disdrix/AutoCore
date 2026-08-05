// =============================================================================
// FUN_0098c460
// -----------------------------------------------------------------------------
// Stable ID: aa_0098c460
// Address:   0x0098c460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098c460 @ 0x0098c460
// Stable ID: aa_0098c460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~231 non-empty decompiler lines.
//  - Control keywords: if×36, goto×11, return×3, while×2, for×1, do×1, switch×1.
//  - Notable callees: CONCAT31×2, FUN_00796d40, FUN_0098c460.
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

uint32_t /* width from decompiler */ FUN_0098c460(void)



{

  ushort uVar1;

  short sVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  uint *puVar7;

  ushort uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  int unaff_ESI;

  int *piVar14;

  uint uVar15;

  int iStack_11c;

  int iStack_118;

  int iStack_114;

  int local_110 [4];

  int iStack_100;

  uint auStack_fc [4];

  char acStack_ec [192];

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  

  iVar5 = FUN_00796d40();

  piVar14 = local_110;

  for (iVar9 = 0x44; iVar9 != 0; iVar9 = iVar9 + -1) {

    *piVar14 = 0;

    piVar14 = piVar14 + 1;

  }

  if (*(int *)(iVar5 + 0x78) == 0) {

    return 0;

  }

  (**(code **)(**(int **)(iVar5 + 0x78) + 0x24))(*(int **)(iVar5 + 0x78),0x110,local_110);

  pcVar6 = (char *)(unaff_ESI + 0x69c);

  iVar10 = (unaff_ESI - (int)pcVar6) + 0x69d;

  iVar11 = (unaff_ESI - (int)pcVar6) + 0x69e;

  iVar9 = 3 - (int)pcVar6;

  iVar5 = -(int)pcVar6;

  uVar15 = 0;

  iVar3 = 1 - (int)pcVar6;

  iVar4 = 2 - (int)pcVar6;

  iVar12 = (unaff_ESI - (int)pcVar6) + 0x69f;

  do {

    sVar2 = (short)uVar15;

    if (pcVar6[(int)(acStack_ec + iVar5)] == *pcVar6) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar2 + -0x1000)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (*pcVar6 < '\0') {

      *pcVar6 = pcVar6[(int)(acStack_ec + iVar5)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar2 + -0x1000;

    }

    if (pcVar6[(int)(acStack_ec + iVar3)] == pcVar6[iVar10]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar2 + -0xfff)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar6[iVar10] < '\0') {

      pcVar6[iVar10] = pcVar6[(int)(acStack_ec + iVar3)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar2 + -0xfff;

    }

    if (pcVar6[(int)(acStack_ec + iVar4)] == pcVar6[iVar11]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar2 + -0xffe)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar6[iVar11] < '\0') {

      pcVar6[iVar11] = pcVar6[(int)(acStack_ec + iVar4)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar2 + -0xffe;

    }

    if (pcVar6[(int)(acStack_ec + iVar9)] == pcVar6[iVar12]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar2 + -0xffd)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar6[iVar12] < '\0') {

      pcVar6[iVar12] = pcVar6[(int)(acStack_ec + iVar9)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar2 + -0xffd;

    }

    uVar15 = uVar15 + 4;

    pcVar6 = pcVar6 + 4;

  } while (uVar15 < 0x80);

  uVar15 = iStack_11c - *(int *)(unaff_ESI + 0x66c);

  uVar13 = (int)uVar15 >> 0x1f;

  if ((int)((uVar15 ^ uVar13) - uVar13) < 0x9c5) {

    uVar15 = iStack_118 - *(int *)(unaff_ESI + 0x670);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf101;

      if (iStack_118 < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf181;

      }

      goto LAB_0098c854;

    }

    uVar15 = iStack_114 - *(int *)(unaff_ESI + 0x674);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf102;

      if (iStack_114 < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf182;

      }

      goto LAB_0098c854;

    }

    uVar15 = local_110[0] - *(int *)(unaff_ESI + 0x678);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf110;

      if (local_110[0] < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf190;

      }

      goto LAB_0098c854;

    }

    uVar15 = local_110[1] - *(int *)(unaff_ESI + 0x67c);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf111;

      if (local_110[1] < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf191;

      }

      goto LAB_0098c854;

    }

    uVar15 = local_110[2] - *(int *)(unaff_ESI + 0x680);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf112;

      if (local_110[2] < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf192;

      }

      goto LAB_0098c854;

    }

    uVar15 = local_110[3] - *(int *)(unaff_ESI + 0x684);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf120;

      if (local_110[3] < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf1a0;

      }

      goto LAB_0098c854;

    }

    uVar15 = iStack_100 - *(int *)(unaff_ESI + 0x688);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf121;

      if (iStack_100 < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf1a1;

      }

      goto LAB_0098c854;

    }

    uVar15 = iStack_2c - *(int *)(unaff_ESI + 0x75c);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf140;

      if (iStack_2c < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf1c0;

      }

      goto LAB_0098c854;

    }

    uVar15 = iStack_28 - *(int *)(unaff_ESI + 0x760);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf141;

      if (iStack_28 < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf1c1;

      }

      goto LAB_0098c854;

    }

    uVar15 = iStack_24 - *(int *)(unaff_ESI + 0x764);

    uVar13 = (int)uVar15 >> 0x1f;

    if (0x9c4 < (int)((uVar15 ^ uVar13) - uVar13)) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf142;

      if (iStack_24 < 0) {

        *(uint16_t *)(unaff_ESI + 0x77c) = 0xf1c2;

      }

      goto LAB_0098c854;

    }

  }

  else {

    *(uint16_t *)(unaff_ESI + 0x77c) = 0xf100;

    if (iStack_11c < 0) {

      *(uint16_t *)(unaff_ESI + 0x77c) = 0xf180;

    }

LAB_0098c854:

    *(uint8_t *)(unaff_ESI + 0x780) = 1;

  }

  uVar15 = 0;

  puVar7 = (uint *)(unaff_ESI + 0x68c);

  while (((short)auStack_fc[uVar15] == -1 || (auStack_fc[uVar15] == *puVar7))) {

    uVar15 = uVar15 + 1;

    puVar7 = puVar7 + 1;

    if (3 < uVar15) {

      return CONCAT31((int3)((uint)puVar7 >> 8),*(char *)(unaff_ESI + 0x780) != '\0');

    }

  }

  uVar13 = auStack_fc[uVar15];

  uVar1 = (ushort)uVar15;

  uVar8 = uVar1 | 0xf200;

  *(ushort *)(unaff_ESI + 0x77c) = uVar8;

  switch(uVar13 / 9000) {

  case 0:

    break;

  case 1:

    uVar8 = uVar1 | 0xf210;

    break;

  case 2:

    uVar8 = uVar1 | 0xf220;

    break;

  case 3:

    uVar8 = uVar1 | 0xf240;

    break;

  default:

    goto switchD_0098c8ae_default;

  }

  *(ushort *)(unaff_ESI + 0x77c) = uVar8;

switchD_0098c8ae_default:

  *(uint8_t *)(unaff_ESI + 0x780) = 1;

  return CONCAT31((int3)((ulonglong)uVar13 * 0xe90452d5 >> 8),*(char *)(unaff_ESI + 0x780) != '\0');

}
