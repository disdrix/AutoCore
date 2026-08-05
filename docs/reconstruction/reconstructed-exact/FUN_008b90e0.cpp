// =============================================================================
// FUN_008b90e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b90e0
// Address:   0x008b90e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b90e0 @ 0x008b90e0
// Stable ID: aa_008b90e0
// Embedded strings (evidence for future rename):
//   - "%d: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: do×8, while×8, if×4, for×2, return×1.
//  - Notable callees: FUN_008b90e0, fclose, fopen, fprintf.
//  - Strings: "%d: %s\n".
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

void FUN_008b90e0(void)



{

  char *pcVar1;

  char cVar2;

  char *in_EAX;

  char *pcVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  char *pcVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint16_t *puVar11;

  int local_408;

  uint8_t local_404 [4];

  char local_400 [1024];

  

  if ((in_EAX != (char *)0x0) &&

     (local_404 = (uint8_t  [4])fopen(in_EAX,"w"), local_404 != (uint8_t  [4])0x0)) {

    local_408 = 0;

    puVar10 = &DAT_00d177c8;

    do {

      pcVar8 = (char *)(&DAT_00d17788)[local_408];

      local_400[0] = '\0';

      if ((pcVar8 != (char *)0x0) && (pcVar3 = pcVar8, *pcVar8 != '\0')) {

        do {

          cVar2 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        uVar4 = (int)pcVar3 - (int)pcVar8;

        pcVar3 = local_404 + 3;

        do {

          pcVar1 = pcVar3 + 1;

          pcVar3 = pcVar3 + 1;

        } while (*pcVar1 != '\0');

        for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar3 = pcVar3 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar3 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar3 = pcVar3 + 1;

        }

      }

      puVar11 = (uint16_t *)(local_404 + 3);

      do {

        pcVar8 = (char *)((int)puVar11 + 1);

        puVar11 = (uint16_t *)((int)puVar11 + 1);

      } while (*pcVar8 != '\0');

      *puVar11 = DAT_00a46e78;

      iVar9 = 5;

      do {

        pcVar8 = (char *)*puVar10;

        if ((pcVar8 != (char *)0x0) && (*pcVar8 != '\0')) {

          pcVar3 = local_400;

          do {

            cVar2 = *pcVar3;

            pcVar3 = pcVar3 + 1;

          } while (cVar2 != '\0');

          iVar5 = (int)pcVar3 - (int)(local_400 + 1);

          do {

            iVar6 = iVar5;

            if (*pcVar8 == ';') {

              local_400[iVar5] = ';';

              iVar6 = iVar5 + 1;

            }

            local_400[iVar6] = *pcVar8;

            pcVar8 = pcVar8 + 1;

            iVar5 = iVar6 + 1;

          } while (*pcVar8 != '\0');

          local_400[iVar6 + 1] = '\0';

          puVar11 = (uint16_t *)(local_404 + 3);

          do {

            pcVar8 = (char *)((int)puVar11 + 1);

            puVar11 = (uint16_t *)((int)puVar11 + 1);

          } while (*pcVar8 != '\0');

          *puVar11 = DAT_00a46e78;

        }

        puVar10 = puVar10 + 1;

        iVar9 = iVar9 + -1;

      } while (iVar9 != 0);

      local_408 = local_408 + 1;

      fprintf((FILE *)local_404,"%d: %s\n",local_408,local_400);

    } while (local_408 < 0xf);

    fclose((FILE *)local_404);

  }

  return;

}
