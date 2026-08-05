// =============================================================================
// FUN_004702b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004702b0
// Address:   0x004702b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004702b0 @ 0x004702b0
// Stable ID: aa_004702b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×6, for×6, return×5, do×4, while×4.
//  - Notable callees: FUN_00476d60×4, FUN_00477740×4, FUN_004702b0.
//  - Return sites: 5.

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

void FUN_004702b0(int param_1,int param_2,char *param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 uint8_t param_6,int param_7,char *param_8,int param_9)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    pcVar2 = param_3;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar3 = (char *)FUN_00477740();

    *(char **)(param_2 + 0xa0) = pcVar3;

    if (pcVar3 == (char *)0x0) {

      FUN_00476d60();

      return;

    }

    pcVar7 = param_3;

    for (uVar6 = (uint)(pcVar2 + (1 - (int)(param_3 + 1))) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar6 = (uint)(pcVar2 + (1 - (int)(param_3 + 1))) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar3 = pcVar3 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4) = param_4;

    *(uint8_t *)(param_2 + 0xb4) = param_6;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8) = param_5;

    *(uint8_t *)(param_2 + 0xb5) = (uint8_t)param_7;

    pcVar2 = param_8;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar3 = (char *)FUN_00477740();

    *(char **)(param_2 + 0xac) = pcVar3;

    if (pcVar3 == (char *)0x0) {

      FUN_00476d60();

      return;

    }

    pcVar7 = param_8;

    for (uVar6 = (uint)(pcVar2 + (1 - (int)(param_8 + 1))) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar6 = (uint)(pcVar2 + (1 - (int)(param_8 + 1))) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar3 = pcVar3 + 1;

    }

    iVar4 = FUN_00477740();

    *(int *)(param_2 + 0xb0) = iVar4;

    if (iVar4 == 0) {

      FUN_00476d60();

      return;

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + param_7 * 4) = 0;

    if (0 < param_7) {

      iVar4 = 0;

      do {

        pcVar3 = *(char **)(param_9 + iVar4 * 4);

        pcVar2 = pcVar3 + 1;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uVar5 = FUN_00477740();

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xb0) + iVar4 * 4) = uVar5;

        puVar9 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_2 + 0xb0) + iVar4 * 4);

        if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00476d60();

          return;

        }

        puVar8 = *(uint32_t /* width from decompiler */ **)(param_9 + iVar4 * 4);

        for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar2)) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *puVar9 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar9 = puVar9 + 1;

        }

        iVar4 = iVar4 + 1;

        for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar2)) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

          puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

          puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        }

      } while (iVar4 < param_7);

    }

    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) | 4;

    *(byte *)(param_2 + 0xb8) = *(byte *)(param_2 + 0xb8) | 0x80;

  }

  return;

}
