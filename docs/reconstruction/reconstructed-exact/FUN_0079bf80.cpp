// =============================================================================
// FUN_0079bf80
// -----------------------------------------------------------------------------
// Stable ID: aa_0079bf80
// Address:   0x0079bf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079bf80 @ 0x0079bf80
// Stable ID: aa_0079bf80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~211 non-empty decompiler lines.
//  - Control keywords: do×17, while×17, if×13, for×8, return×6.
//  - Notable callees: FUN_007a69d0×2, FUN_007b6420×2, FUN_007b66c0×2, FUN_007b6a20×2, PathFileExistsA×2, FUN_0079bf80.
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

uint32_t /* width from decompiler */ FUN_0079bf80(char *param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  char *pcVar6;

  BOOL BVar7;

  uint uVar8;

  int unaff_EBX;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char local_208 [4];

  uint8_t auStack_204 [255];

  char cStack_105;

  char local_104 [260];

  

  if (param_1 == (char *)0x0) {

    return 0;

  }

  iVar2 = FUN_007a69d0();

  if (*(int *)(iVar2 + 0x2c) != 0) {

    pcVar3 = *(char **)(unaff_EBX + 0x4c8);

    iVar2 = -(int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)(local_208 + iVar2)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    iVar2 = FUN_007a69d0();

    iVar2 = *(int *)(iVar2 + 0x2c);

    pcVar3 = param_1;

    if (iVar2 == 1) {

      puVar10 = (uint32_t /* width from decompiler */ *)&stack0xfffffdf7;

      do {

        pcVar5 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar5 != '\0');

      *puVar10 = DAT_00a96c64;

    }

    else if (iVar2 == 2) {

      puVar10 = (uint32_t /* width from decompiler */ *)&stack0xfffffdf7;

      do {

        pcVar5 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar5 != '\0');

      *puVar10 = DAT_00a96c60;

    }

    else if (iVar2 == 3) {

      puVar10 = (uint32_t /* width from decompiler */ *)&stack0xfffffdf7;

      do {

        pcVar5 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar5 != '\0');

      *puVar10 = DAT_00a96c68;

    }

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)param_1;

    pcVar3 = &stack0xfffffdf7;

    do {

      pcVar5 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_1;

    for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar3 = pcVar3 + 1;

    }

    puVar10 = (uint32_t /* width from decompiler */ *)&stack0xfffffdf7;

    do {

      puVar11 = puVar10;

      puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

    } while (*(char *)((int)puVar11 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a2c53c;

    *(uint8_t *)((int)puVar11 + 5) = DAT_00a2c540;

    iVar2 = FUN_007b6a20();

    if ((*(byte *)(iVar2 + 4) & 1) != 0) {

      pcVar5 = (char *)FUN_007b6420();

      pcVar3 = DAT_00d1e574;

      if (DAT_00d1e588 < 0x10) {

        pcVar3 = (char *)&DAT_00d1e574;

      }

      pcVar9 = local_104;

      do {

        cVar1 = *pcVar3;

        *pcVar9 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar9 = pcVar9 + 1;

        pcVar6 = pcVar5;

      } while (cVar1 != '\0');

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar6 - (int)pcVar5;

      pcVar3 = &cStack_105;

      do {

        pcVar9 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar9 != '\0');

      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar3 = pcVar3 + 1;

      }

      BVar7 = PathFileExistsA(local_104);

      if (BVar7 != 0) {

        return 2;

      }

    }

    cVar1 = FUN_007b66c0(iVar2);

    if (cVar1 != '\0') {

      return 2;

    }

  }

  pcVar3 = *(char **)(unaff_EBX + 0x4c8);

  iVar2 = -(int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)(local_208 + iVar2)] = cVar1;

    pcVar3 = pcVar3 + 1;

    pcVar5 = param_1;

  } while (cVar1 != '\0');

  do {

    cVar1 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  uVar4 = (int)pcVar5 - (int)param_1;

  pcVar3 = &stack0xfffffdf7;

  do {

    pcVar5 = pcVar3 + 1;

    pcVar3 = pcVar3 + 1;

  } while (*pcVar5 != '\0');

  for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)param_1;

    param_1 = param_1 + 4;

    pcVar3 = pcVar3 + 4;

  }

  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar3 = *param_1;

    param_1 = param_1 + 1;

    pcVar3 = pcVar3 + 1;

  }

  puVar10 = (uint32_t /* width from decompiler */ *)&stack0xfffffdf7;

  do {

    puVar11 = puVar10;

    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  } while (*(char *)((int)puVar11 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a2c53c;

  *(uint8_t *)((int)puVar11 + 5) = DAT_00a2c540;

  iVar2 = FUN_007b6a20();

  if ((*(byte *)(iVar2 + 4) & 1) != 0) {

    pcVar5 = (char *)FUN_007b6420();

    pcVar3 = DAT_00d1e574;

    if (DAT_00d1e588 < 0x10) {

      pcVar3 = (char *)&DAT_00d1e574;

    }

    pcVar9 = local_104;

    do {

      cVar1 = *pcVar3;

      *pcVar9 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar9 = pcVar9 + 1;

      pcVar6 = pcVar5;

    } while (cVar1 != '\0');

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar6 - (int)pcVar5;

    pcVar3 = &cStack_105;

    do {

      pcVar9 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar9 != '\0');

    for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar3 = pcVar3 + 1;

    }

    BVar7 = PathFileExistsA(local_104);

    if (BVar7 != 0) {

      return 1;

    }

  }

  cVar1 = FUN_007b66c0(iVar2);

  if (cVar1 != '\0') {

    return 1;

  }

  return 0;

}
