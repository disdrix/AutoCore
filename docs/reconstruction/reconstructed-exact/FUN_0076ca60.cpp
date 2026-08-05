// =============================================================================
// FUN_0076ca60
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ca60
// Address:   0x0076ca60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076ca60 @ 0x0076ca60
// Stable ID: aa_0076ca60
// Embedded strings (evidence for future rename):
//   - "%s%1.3fms: %s (%1.3fa)\n"
//   - "%s%1.3fms: %s Unlogged (%1.3fa)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×11, do×7, while×7, for×4, return×1.
//  - Notable callees: FUN_0076ca60×2, _snprintf×2, Unlogged, s.
//  - Strings: "%s%1.3fms: %s (%1.3fa)\n"; "%s%1.3fms: %s Unlogged (%1.3fa)\n".
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



void __thiscall FUN_0076ca60(int param_1,int param_2,size_t *param_3,int param_4)



{

  char cVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  uint uVar8;

  int iVar9;

  char *pcVar10;

  uint16_t *puVar11;

  uint local_514;

  int local_510;

  uint8_t local_508 [4];

  char local_504 [260];

  char local_400 [1024];

  

  uVar8 = *(uint *)(param_1 + 0x5c);

  if (1 < uVar8) {

    local_504[0] = '\0';

    iVar6 = param_4;

    if (0 < param_4) {

      do {

        puVar11 = (uint16_t *)(local_508 + 3);

        do {

          pcVar7 = (char *)((int)puVar11 + 1);

          puVar11 = (uint16_t *)((int)puVar11 + 1);

        } while (*pcVar7 != '\0');

        iVar6 = iVar6 + -1;

        *puVar11 = DAT_00a2a000;

      } while (iVar6 != 0);

    }

    if (*(uint *)(param_1 + 0x74) == 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = *(uint *)(param_1 + 0x54) / *(uint *)(param_1 + 0x74);

    }

    fVar3 = (float)(int)uVar5;

    if ((int)uVar5 < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    fVar4 = (float)(int)uVar8;

    if ((int)uVar8 < 0) {

      fVar4 = fVar4 + _DAT_00aaa5dc;

    }

    iVar6 = _snprintf(local_400,*param_3,"%s%1.3fms: %s (%1.3fa)\n",local_504,

                      (double)(fVar4 * g_flMsToSeconds_Inferred),*(uint32_t /* width from decompiler */ *)(param_1 + 4),

                      (double)(fVar3 * g_flMsToSeconds_Inferred));

    pcVar7 = local_400;

    do {

      cVar1 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    uVar8 = (int)pcVar7 - (int)local_400;

    pcVar7 = (char *)(param_2 + -1);

    do {

      pcVar10 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar10 != '\0');

    pcVar10 = local_400;

    for (uVar5 = uVar8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

      pcVar10 = pcVar10 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar7 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      pcVar7 = pcVar7 + 1;

    }

    *param_3 = *param_3 - iVar6;

    iVar6 = 0;

    if ((*(int *)(param_1 + 0x40) != 0) &&

       (iVar9 = *(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) >> 2, 0 < iVar9)) {

      if (*(uint *)(param_1 + 0x74) == 0) {

        local_514 = 0;

      }

      else {

        local_514 = *(uint *)(param_1 + 0x54) / *(uint *)(param_1 + 0x74);

      }

      local_510 = *(int *)(param_1 + 0x5c);

      if (0 < iVar9) {

        local_508 = (uint8_t  [4])(param_4 + 1);

        do {

          iVar2 = *(int *)(*(int *)(param_1 + 0x40) + iVar6 * 4);

          FUN_0076ca60(param_2,param_3,local_508);

          if (*(uint *)(iVar2 + 0x74) == 0) {

            uVar8 = 0;

          }

          else {

            uVar8 = *(uint *)(iVar2 + 0x54) / *(uint *)(iVar2 + 0x74);

          }

          local_514 = local_514 - uVar8;

          local_510 = local_510 - *(int *)(iVar2 + 0x5c);

          iVar6 = iVar6 + 1;

        } while (iVar6 < iVar9);

      }

      if ((int)local_514 < 0) {

        local_514 = 0;

      }

      if (local_510 < 0) {

        local_510 = 0;

      }

      iVar6 = _snprintf(local_400,*param_3,"%s%1.3fms: %s Unlogged (%1.3fa)\n",local_504,

                        (double)((float)local_510 * g_flMsToSeconds_Inferred),

                        *(uint32_t /* width from decompiler */ *)(param_1 + 4),

                        (double)((float)(int)local_514 * g_flMsToSeconds_Inferred));

      *param_3 = *param_3 - iVar6;

      pcVar7 = local_400;

      do {

        cVar1 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

      uVar8 = (int)pcVar7 - (int)local_400;

      pcVar7 = (char *)(param_2 + -1);

      do {

        pcVar10 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar10 != '\0');

      pcVar10 = local_400;

      for (uVar5 = uVar8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

        *pcVar7 = *pcVar10;

        pcVar10 = pcVar10 + 1;

        pcVar7 = pcVar7 + 1;

      }

    }

  }

  return;

}
