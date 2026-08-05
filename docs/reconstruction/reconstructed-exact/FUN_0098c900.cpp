// =============================================================================
// FUN_0098c900
// -----------------------------------------------------------------------------
// Stable ID: aa_0098c900
// Address:   0x0098c900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098c900 @ 0x0098c900
// Stable ID: aa_0098c900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×14, return×2, for×1, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00796d40, FUN_0098c900.
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

uint32_t /* width from decompiler */ FUN_0098c900(void)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  int unaff_ESI;

  uint uVar11;

  uint32_t /* width from decompiler */ uVar12;

  char local_14 [20];

  

  iVar4 = FUN_00796d40();

  local_14[0] = '\0';

  local_14[1] = '\0';

  local_14[2] = '\0';

  local_14[3] = '\0';

  local_14[4] = '\0';

  local_14[5] = '\0';

  local_14[6] = '\0';

  local_14[7] = '\0';

  local_14[8] = '\0';

  local_14[9] = '\0';

  local_14[10] = '\0';

  local_14[0xb] = '\0';

  local_14[0xc] = '\0';

  local_14[0xd] = '\0';

  local_14[0xe] = '\0';

  local_14[0xf] = '\0';

  local_14[0x10] = '\0';

  local_14[0x11] = '\0';

  local_14[0x12] = '\0';

  local_14[0x13] = '\0';

  if (*(int *)(iVar4 + 0x74) == 0) {

    pcVar5 = local_14;

    for (iVar9 = 0x44; iVar9 != 0; iVar9 = iVar9 + -1) {

      pcVar5[0] = '\0';

      pcVar5[1] = '\0';

      pcVar5[2] = '\0';

      pcVar5[3] = '\0';

      pcVar5 = pcVar5 + 4;

    }

    if (*(int *)(iVar4 + 0x78) == 0) {

      return 0;

    }

    piVar10 = *(int **)(iVar4 + 0x78);

    iVar4 = *piVar10;

    uVar12 = 0x110;

  }

  else {

    piVar10 = *(int **)(iVar4 + 0x74);

    iVar4 = *piVar10;

    uVar12 = 0x14;

  }

  (**(code **)(iVar4 + 0x24))(piVar10,uVar12,local_14);

  pcVar5 = (char *)(unaff_ESI + 0x664);

  iVar6 = (unaff_ESI - (int)pcVar5) + 0x665;

  iVar7 = (unaff_ESI - (int)pcVar5) + 0x666;

  iVar9 = 3 - (int)pcVar5;

  iVar4 = -(int)pcVar5;

  uVar11 = 0;

  iVar2 = 1 - (int)pcVar5;

  iVar3 = 2 - (int)pcVar5;

  iVar8 = (unaff_ESI - (int)pcVar5) + 0x667;

  do {

    sVar1 = (short)uVar11;

    if (pcVar5[(int)(local_14 + iVar4)] == *pcVar5) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar1 + 0xf00)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (*pcVar5 < '\0') {

      *pcVar5 = pcVar5[(int)(local_14 + iVar4)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar1 + 0xf00;

    }

    if (pcVar5[(int)(local_14 + iVar2)] == pcVar5[iVar6]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar1 + 0xf01)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar5[iVar6] < '\0') {

      pcVar5[iVar6] = pcVar5[(int)(local_14 + iVar2)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar1 + 0xf01;

    }

    if (pcVar5[(int)(local_14 + iVar3)] == pcVar5[iVar7]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar1 + 0xf02)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar5[iVar7] < '\0') {

      pcVar5[iVar7] = pcVar5[(int)(local_14 + iVar3)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar1 + 0xf02;

    }

    if (pcVar5[(int)(local_14 + iVar9)] == pcVar5[iVar8]) {

      if (*(short *)(unaff_ESI + 0x77c) == (short)(sVar1 + 0xf03)) {

        *(uint8_t *)(unaff_ESI + 0x780) = 1;

      }

    }

    else if (pcVar5[iVar8] < '\0') {

      pcVar5[iVar8] = pcVar5[(int)(local_14 + iVar9)];

    }

    else {

      *(short *)(unaff_ESI + 0x77c) = sVar1 + 0xf03;

    }

    uVar11 = uVar11 + 4;

    pcVar5 = pcVar5 + 4;

  } while (uVar11 < 8);

  return CONCAT31((int3)((uint)pcVar5 >> 8),*(char *)(unaff_ESI + 0x780) != '\0');

}
