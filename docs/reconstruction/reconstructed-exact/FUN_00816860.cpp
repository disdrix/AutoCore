// =============================================================================
// FUN_00816860
// -----------------------------------------------------------------------------
// Stable ID: aa_00816860
// Address:   0x00816860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00816860 @ 0x00816860
// Stable ID: aa_00816860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, for×3, if×2, return×1.
//  - Notable callees: FUN_007f5120×2, FUN_00816860.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00816860(void)



{

  char cVar1;

  short sVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  int unaff_EBX;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  char *pcVar9;

  char local_108 [2];

  uint32_t /* width from decompiler */ auStack_106 [64];

  

  if (*(int *)(unaff_EBX + 0x810) != 0) {

    sVar2 = *(short *)(unaff_EBX + 0x81e);

    local_108[0] = '\0';

    local_108[1] = '\0';

    puVar8 = auStack_106;

    for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar8 = 0;

      puVar8 = puVar8 + 1;

    }

    *(uint8_t *)puVar8 = 0;

    if (sVar2 != 0) {

      pcVar3 = (char *)FUN_007f5120();

      pcVar6 = local_108;

      do {

        cVar1 = *pcVar3;

        *pcVar6 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      puVar8 = (uint32_t /* width from decompiler */ *)&stack0xfffffef7;

      do {

        pcVar6 = (char *)((int)puVar8 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      } while (*pcVar6 != '\0');

      *puVar8 = _DAT_00a7c818;

    }

    pcVar3 = (char *)FUN_007f5120();

    pcVar6 = pcVar3;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    pcVar9 = &stack0xfffffef7;

    do {

      pcVar7 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = pcVar3;

    for (uVar5 = (uint)((int)pcVar6 - (int)pcVar3) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar9 = pcVar9 + 4;

    }

    for (uVar5 = (int)pcVar6 - (int)pcVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar9 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar9 = pcVar9 + 1;

    }

    (**(code **)(**(int **)(unaff_EBX + 0x810) + 0x1d8))(local_108,1,1);

    (**(code **)(**(int **)(unaff_EBX + 0x810) + 0x34c))();

  }

  return;

}
