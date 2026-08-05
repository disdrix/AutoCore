// =============================================================================
// FUN_0044e650
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e650
// Address:   0x0044e650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044e650 @ 0x0044e650
// Stable ID: aa_0044e650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×15, while×5, do×2, return×2, for×1.
//  - Notable callees: FUN_0043b870, FUN_0044a380, FUN_0044e650, FUN_0044e950, FUN_00469ea0, block.
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

/* WARNING: Removing unreachable block (ram,0x0044e735) */



void FUN_0044e650(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  char *pcVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  char *pcVar13;

  int local_8;

  

  uVar10 = *(uint *)(unaff_ESI + 0x24);

  if (uVar10 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar10 < iVar7 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar10) {

        *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) * 2 + 1;

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x14) == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

      }

      *(int *)(unaff_ESI + 0x20) = iVar7 * 2 + -3;

      FUN_0044a380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    uVar10 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar11 = *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + *(int *)(unaff_ESI + 0x14));

    if (puVar11 != *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + *(int *)(unaff_ESI + 0x14) + 4)) {

      do {

        local_8 = uVar10 * 4;

        uVar8 = FUN_0043b870();

        if ((uVar8 & *(uint *)(unaff_ESI + 0x20)) == uVar10) {

          puVar12 = (uint32_t /* width from decompiler */ *)*puVar11;

        }

        else {

          puVar12 = (uint32_t /* width from decompiler */ *)*puVar11;

          if (puVar12 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + local_8);

            uVar8 = uVar10;

            while ((puVar11 == puVar3 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4) = puVar12, uVar8 != 0))

                  ) {

              uVar8 = uVar8 - 1;

              puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4);

            }

            iVar7 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar11[1] = puVar12;

            *(int *)puVar12[1] = iVar7;

            **(uint32_t /* width from decompiler */ **)(iVar7 + 4) = puVar11;

            uVar5 = *(uint32_t /* width from decompiler */ *)(iVar7 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar7 + 4) = puVar12[1];

            puVar12[1] = puVar11[1];

            puVar11[1] = uVar5;

            puVar11 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar8 = *(uint *)(unaff_ESI + 0x24);

              (uVar10 < uVar8 &&

              (piVar2 = (int *)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4),

              *piVar2 == *(int *)(unaff_ESI + 8))); uVar8 = uVar8 - 1) {

            *piVar2 = (int)puVar11;

          }

          if (puVar12 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar11 = puVar12;

      } while (puVar12 != *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + 4 + *(int *)(unaff_ESI + 0x14)));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  pcVar6 = (char *)*param_2;

  uVar10 = 0;

  if (pcVar6 != (char *)0x0) {

    cVar4 = *pcVar6;

    pcVar13 = pcVar6;

    while (cVar4 != '\0') {

      uVar10 = uVar10 * 0x10 + (int)cVar4;

      uVar8 = uVar10 & 0xf0000000;

      if (uVar8 != 0) {

        uVar10 = uVar10 ^ uVar8 >> 0x18 ^ uVar8;

      }

      pcVar1 = pcVar13 + 1;

      pcVar13 = pcVar13 + 1;

      cVar4 = *pcVar1;

    }

  }

  uVar10 = *(uint *)(unaff_ESI + 0x20) & uVar10;

  if (*(uint *)(unaff_ESI + 0x24) <= uVar10) {

    uVar10 = uVar10 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar7 = uVar10 * 4;

  puVar11 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar7);

  if (puVar11 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7)) {

    do {

      puVar11 = (uint32_t /* width from decompiler */ *)puVar11[1];

      if ((char *)puVar11[2] <= pcVar6) {

        if (pcVar6 <= (char *)puVar11[2]) {

          *param_1 = (int)puVar11;

          *(uint8_t *)(param_1 + 1) = 0;

          return;

        }

        puVar11 = (uint32_t /* width from decompiler */ *)*puVar11;

        break;

      }

    } while (puVar11 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7));

  }

  iVar9 = FUN_0044e950(puVar11,puVar11[1]);

  FUN_00469ea0();

  puVar11[1] = iVar9;

  **(int **)(iVar9 + 4) = iVar9;

  iVar9 = puVar11[1];

  puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7);

  while ((puVar11 == puVar12 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar7) = iVar9, uVar10 != 0))

        ) {

    uVar10 = uVar10 - 1;

    iVar7 = uVar10 * 4;

    puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7);

  }

  *param_1 = iVar9;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
