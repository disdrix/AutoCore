// =============================================================================
// FUN_00579fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00579fb0
// Address:   0x00579fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00579fb0 @ 0x00579fb0
// Stable ID: aa_00579fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: while×13, do×12, for×8, if×4, return×3, goto×2.
//  - Notable callees: FUN_00578f80, FUN_005792d0, FUN_00579fb0.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00579fb0(uint8_t *param_1,char *param_2,int param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  uint16_t *puVar9;

  char local_3000 [4096];

  char local_2000 [4096];

  char local_1000 [4092];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x579fba;

  if (param_1 == (uint8_t *)0x0) {

    return;

  }

  if (param_2 == (char *)0x0) {

    return;

  }

  puVar7 = *(uint32_t /* width from decompiler */ **)(param_3 + 4);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_3 + 8);

  *param_1 = 0;

  while (pcVar4 = param_2, puVar7 != puVar1) {

    pcVar3 = (char *)FUN_00578f80(param_2,local_2000,local_3000);

    if (pcVar3 == (char *)0x0) goto LAB_0057a152;

    pcVar4 = local_3000;

    do {

      cVar2 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    uVar5 = (int)pcVar4 - (int)local_3000;

    pcVar4 = param_1 + -1;

    do {

      pcVar8 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar8 != '\0');

    pcVar8 = local_3000;

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar8;

      pcVar8 = pcVar8 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar4 = *pcVar8;

      pcVar8 = pcVar8 + 1;

      pcVar4 = pcVar4 + 1;

    }

    cVar2 = FUN_005792d0(local_1000,local_2000,*puVar7,param_4,param_5);

    param_2 = pcVar3;

    if (cVar2 == '\0') {

      puVar9 = (uint16_t *)(param_1 + -1);

      do {

        pcVar4 = (char *)((int)puVar9 + 1);

        puVar9 = (uint16_t *)((int)puVar9 + 1);

      } while (*pcVar4 != '\0');

      *puVar9 = _DAT_00a62c98;

      pcVar4 = local_2000;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      uVar5 = (int)pcVar4 - (int)local_2000;

      pcVar4 = param_1 + -1;

      do {

        pcVar3 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar3 != '\0');

      pcVar3 = local_2000;

      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

        pcVar3 = pcVar3 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar4 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      }

      puVar9 = (uint16_t *)(param_1 + -1);

      do {

        pcVar4 = (char *)((int)puVar9 + 1);

        puVar9 = (uint16_t *)((int)puVar9 + 1);

      } while (*pcVar4 != '\0');

      *puVar9 = DAT_00a62c94;

    }

    else {

      pcVar4 = local_1000;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      uVar5 = (int)pcVar4 - (int)local_1000;

      pcVar4 = param_1 + -1;

      do {

        pcVar3 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar3 != '\0');

      pcVar3 = local_1000;

      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

        pcVar3 = pcVar3 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar4 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      }

      puVar7 = puVar7 + 1;

    }

  }

  do {

    cVar2 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  uVar5 = (int)pcVar4 - (int)param_2;

  pcVar4 = param_1 + -1;

  do {

    pcVar3 = pcVar4 + 1;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar3 != '\0');

LAB_0057a16c:

  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)param_2;

    param_2 = param_2 + 4;

    pcVar4 = pcVar4 + 4;

  }

  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

    *pcVar4 = *param_2;

    param_2 = param_2 + 1;

    pcVar4 = pcVar4 + 1;

  }

  return;

LAB_0057a152:

  do {

    cVar2 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  uVar5 = (int)pcVar4 - (int)param_2;

  pcVar4 = param_1 + -1;

  do {

    pcVar3 = pcVar4 + 1;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar3 != '\0');

  goto LAB_0057a16c;

}
