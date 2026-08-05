// =============================================================================
// FUN_0043fb50
// -----------------------------------------------------------------------------
// Stable ID: aa_0043fb50
// Address:   0x0043fb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043fb50 @ 0x0043fb50
// Stable ID: aa_0043fb50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×13, while×4, do×2, return×2, for×1.
//  - Notable callees: FUN_0043fb50, FUN_0043fe60, FUN_0044a380, FUN_006759b0, block.
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

/* WARNING: Removing unreachable block (ram,0x0043fc2a) */



void FUN_0043fb50(int *param_1,uint *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  uVar6 = *(uint *)(unaff_ESI + 0x24);

  if (uVar6 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar6 < iVar3 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar6) {

        *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) * 2 + 1;

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x14) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

      }

      *(int *)(unaff_ESI + 0x20) = iVar3 * 2 + -3;

      FUN_0044a380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    uVar6 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar7 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar6 * 4);

    if (puVar7 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar6 * 4)) {

      do {

        if ((puVar7[2] & *(uint *)(unaff_ESI + 0x20)) == uVar6) {

          puVar8 = (uint32_t /* width from decompiler */ *)*puVar7;

        }

        else {

          puVar8 = (uint32_t /* width from decompiler */ *)*puVar7;

          if (puVar8 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar6 * 4);

            uVar4 = uVar6;

            while ((puVar7 == puVar1 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) = puVar8, uVar4 != 0)))

            {

              uVar4 = uVar4 - 1;

              puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4);

            }

            iVar3 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar7[1] = puVar8;

            *(int *)puVar8[1] = iVar3;

            **(uint32_t /* width from decompiler */ **)(iVar3 + 4) = puVar7;

            uVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = puVar8[1];

            puVar8[1] = puVar7[1];

            puVar7[1] = uVar2;

            puVar7 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar4 = *(uint *)(unaff_ESI + 0x24);

              (uVar6 < uVar4 &&

              (*(int *)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) == *(int *)(unaff_ESI + 8)));

              uVar4 = uVar4 - 1) {

            *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) = puVar7;

          }

          if (puVar8 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar7 = puVar8;

      } while (puVar8 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar6 * 4));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  uVar6 = *param_2;

  uVar4 = uVar6 & *(uint *)(unaff_ESI + 0x20);

  if (*(uint *)(unaff_ESI + 0x24) <= uVar4) {

    uVar4 = uVar4 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar3 = uVar4 * 4;

  puVar7 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar3);

  if (puVar7 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar3)) {

    do {

      puVar7 = (uint32_t /* width from decompiler */ *)puVar7[1];

      if ((uint)puVar7[2] <= uVar6) {

        if (uVar6 <= (uint)puVar7[2]) {

          *param_1 = (int)puVar7;

          *(uint8_t *)(param_1 + 1) = 0;

          return;

        }

        puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

        break;

      }

    } while (puVar7 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar3));

  }

  iVar5 = FUN_006759b0(puVar7,puVar7[1],param_2);

  FUN_0043fe60();

  puVar7[1] = iVar5;

  **(int **)(iVar5 + 4) = iVar5;

  iVar5 = puVar7[1];

  puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar3);

  while ((puVar7 == puVar8 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar3) = iVar5, uVar4 != 0))) {

    uVar4 = uVar4 - 1;

    iVar3 = uVar4 * 4;

    puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar3);

  }

  *param_1 = iVar5;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
