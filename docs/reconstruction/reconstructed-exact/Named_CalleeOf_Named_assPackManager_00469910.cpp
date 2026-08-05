// =============================================================================
// Named_CalleeOf_Named_assPackManager_00469910
// -----------------------------------------------------------------------------
// Stable ID: aa_00469910
// Callee of Named_assPackManager
// Address:   0x00469910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×15, while×5, do×2, return×2, for×1.
//  - Notable callees: FUN_0043b870, FUN_0044a380, FUN_00469910, FUN_00469ea0, FUN_0046a210, block.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x004699f5) */



void Named_CalleeOf_Named_assPackManager_00469910(int *param_1,uint32_t /* width from decompiler */ *param_2)



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

  char *pcVar10;

  uint uVar11;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int local_8;

  

  uVar11 = *(uint *)(unaff_ESI + 0x24);

  if (uVar11 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar11 < iVar7 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar11) {

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

    uVar11 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar12 = *(uint32_t /* width from decompiler */ **)(uVar11 * 4 + *(int *)(unaff_ESI + 0x14));

    if (puVar12 != *(uint32_t /* width from decompiler */ **)(uVar11 * 4 + *(int *)(unaff_ESI + 0x14) + 4)) {

      do {

        local_8 = uVar11 * 4;

        uVar8 = FUN_0043b870();

        if ((uVar8 & *(uint *)(unaff_ESI + 0x20)) == uVar11) {

          puVar13 = (uint32_t /* width from decompiler */ *)*puVar12;

        }

        else {

          puVar13 = (uint32_t /* width from decompiler */ *)*puVar12;

          if (puVar13 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + local_8);

            uVar8 = uVar11;

            while ((puVar12 == puVar3 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4) = puVar13, uVar8 != 0))

                  ) {

              uVar8 = uVar8 - 1;

              puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4);

            }

            iVar7 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar12[1] = puVar13;

            *(int *)puVar13[1] = iVar7;

            **(uint32_t /* width from decompiler */ **)(iVar7 + 4) = puVar12;

            uVar5 = *(uint32_t /* width from decompiler */ *)(iVar7 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar7 + 4) = puVar13[1];

            puVar13[1] = puVar12[1];

            puVar12[1] = uVar5;

            puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar8 = *(uint *)(unaff_ESI + 0x24);

              (uVar11 < uVar8 &&

              (piVar2 = (int *)(*(int *)(unaff_ESI + 0x14) + uVar8 * 4),

              *piVar2 == *(int *)(unaff_ESI + 8))); uVar8 = uVar8 - 1) {

            *piVar2 = (int)puVar12;

          }

          if (puVar13 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar12 = puVar13;

      } while (puVar13 != *(uint32_t /* width from decompiler */ **)(uVar11 * 4 + 4 + *(int *)(unaff_ESI + 0x14)));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  pcVar6 = (char *)*param_2;

  uVar11 = 0;

  if (pcVar6 != (char *)0x0) {

    cVar4 = *pcVar6;

    pcVar10 = pcVar6;

    while (cVar4 != '\0') {

      uVar11 = uVar11 * 0x10 + (int)cVar4;

      uVar8 = uVar11 & 0xf0000000;

      if (uVar8 != 0) {

        uVar11 = uVar11 ^ uVar8 >> 0x18 ^ uVar8;

      }

      pcVar1 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

      cVar4 = *pcVar1;

    }

  }

  uVar11 = *(uint *)(unaff_ESI + 0x20) & uVar11;

  if (*(uint *)(unaff_ESI + 0x24) <= uVar11) {

    uVar11 = uVar11 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar7 = uVar11 * 4;

  puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar7);

  if (puVar12 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7)) {

    do {

      puVar12 = (uint32_t /* width from decompiler */ *)puVar12[1];

      if ((char *)puVar12[2] <= pcVar6) {

        if (pcVar6 <= (char *)puVar12[2]) {

          *param_1 = (int)puVar12;

          *(uint8_t *)(param_1 + 1) = 0;

          return;

        }

        puVar12 = (uint32_t /* width from decompiler */ *)*puVar12;

        break;

      }

    } while (puVar12 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7));

  }

  iVar9 = FUN_0046a210(puVar12,puVar12[1],param_2);

  FUN_00469ea0();

  puVar12[1] = iVar9;

  **(int **)(iVar9 + 4) = iVar9;

  iVar9 = puVar12[1];

  puVar13 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7);

  while ((puVar12 == puVar13 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar7) = iVar9, uVar11 != 0))

        ) {

    uVar11 = uVar11 - 1;

    iVar7 = uVar11 * 4;

    puVar13 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar7);

  }

  *param_1 = iVar9;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
