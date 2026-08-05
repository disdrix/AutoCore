// =============================================================================
// FUN_004ce020
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce020
// Address:   0x004ce020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ce020 @ 0x004ce020
// Stable ID: aa_004ce020
// Embedded strings (evidence for future rename):
//   - ".fam"
//   - ".tga"
//   - ".dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: do×13, while×13, if×7, for×6, return×1.
//  - Notable callees: strstr×4, strrchr×2, FUN_004ce020, _strlwr.
//  - Strings: ".fam"; ".tga"; ".dds".
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

void __thiscall FUN_004ce020(int param_1,char *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  

  pcVar4 = (char *)(param_1 + 0xb4);

  iVar7 = (int)pcVar4 - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar7] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  _strlwr(pcVar4);

  pcVar3 = strrchr(pcVar4,0x5c);

  if (pcVar3 != (char *)0x0) {

    *pcVar3 = '\0';

    pcVar3 = pcVar3 + 1;

    iVar7 = (int)pcVar4 - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar7] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar3 = strrchr(pcVar4,0x2f);

  if (pcVar3 != (char *)0x0) {

    *pcVar3 = '\0';

    pcVar3 = pcVar3 + 1;

    iVar7 = (int)pcVar4 - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar7] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar3 = strstr(pcVar4,".fam");

  if (pcVar3 != (char *)0x0) {

    if (*(int *)(param_1 + 0xe4f8) != 0) {

      pcVar9 = (char *)(*(int *)(param_1 + 0xe4f8) + 0x1e);

      pcVar8 = pcVar4;

      do {

        cVar1 = *pcVar8;

        *pcVar9 = cVar1;

        pcVar8 = pcVar8 + 1;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

    }

    *pcVar3 = '\0';

  }

  *(char *)(param_1 + 0xe3a0) = '\0';

  *(char *)(param_1 + 0xe198) = '\0';

  *(char *)(param_1 + 0xe29c) = '\0';

  pcVar3 = pcVar4;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar9 = (char *)(param_1 + 0xe197);

  do {

    pcVar8 = pcVar9 + 1;

    pcVar9 = pcVar9 + 1;

  } while (*pcVar8 != '\0');

  pcVar8 = pcVar4;

  for (uVar5 = (uint)((int)pcVar3 - (int)pcVar4) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar8;

    pcVar8 = pcVar8 + 4;

    pcVar9 = pcVar9 + 4;

  }

  for (uVar5 = (int)pcVar3 - (int)pcVar4 & 3; pcVar3 = pcVar4, uVar5 != 0; uVar5 = uVar5 - 1) {

    *pcVar9 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar9 = pcVar9 + 1;

  }

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  uVar5 = (int)pcVar3 - (int)pcVar4;

  pcVar3 = (char *)(param_1 + 0xe29b);

  do {

    pcVar9 = pcVar3 + 1;

    pcVar3 = pcVar3 + 1;

  } while (*pcVar9 != '\0');

  pcVar9 = pcVar4;

  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar9;

    pcVar9 = pcVar9 + 4;

    pcVar3 = pcVar3 + 4;

  }

  for (uVar5 = uVar5 & 3; pcVar8 = pcVar4, uVar5 != 0; uVar5 = uVar5 - 1) {

    *pcVar3 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    pcVar3 = pcVar3 + 1;

  }

  do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

  } while (cVar1 != '\0');

  uVar5 = (int)pcVar8 - (int)pcVar4;

  pcVar3 = (char *)(param_1 + 0xe39f);

  do {

    pcVar9 = pcVar3 + 1;

    pcVar3 = pcVar3 + 1;

  } while (*pcVar9 != '\0');

  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar4;

    pcVar4 = pcVar4 + 4;

    pcVar3 = pcVar3 + 4;

  }

  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

    *pcVar3 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    pcVar3 = pcVar3 + 1;

  }

  pcVar4 = strstr((char *)(param_1 + 0xe198),".fam");

  if (pcVar4 == (char *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0xe197);

    do {

      puVar10 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a285c4;

    *(uint8_t *)((int)puVar10 + 5) = DAT_00a285c8;

  }

  pcVar4 = strstr((char *)(param_1 + 0xe29c),".tga");

  if (pcVar4 == (char *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0xe29b);

    do {

      puVar10 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a395dc;

    *(uint8_t *)((int)puVar10 + 5) = DAT_00a395e0;

  }

  pcVar4 = strstr((char *)(param_1 + 0xe3a0),".dds");

  if (pcVar4 == (char *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0xe39f);

    do {

      puVar10 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a2c53c;

    *(uint8_t *)((int)puVar10 + 5) = DAT_00a2c540;

  }

  return;

}
