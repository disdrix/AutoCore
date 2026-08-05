// =============================================================================
// Named_CalleeOf_Named_gfxFontImpl_00443530
// -----------------------------------------------------------------------------
// Stable ID: aa_00443530
// Callee of Named_gfxFontImpl
// Address:   0x00443530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxFontImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×13, while×4, do×2, return×2, for×1.
//  - Notable callees: FUN_00443530, FUN_00444190, FUN_0044a380, FUN_00463dc0, block.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxFontImpl
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

/* WARNING: Removing unreachable block (ram,0x0044360b) */



void Named_CalleeOf_Named_gfxFontImpl_00443530(int *param_1,ushort *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  ushort uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  uVar7 = *(uint *)(unaff_ESI + 0x24);

  if (uVar7 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar7 < iVar4 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar7) {

        *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) * 2 + 1;

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x14) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

      }

      *(int *)(unaff_ESI + 0x20) = iVar4 * 2 + -3;

      FUN_0044a380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    uVar7 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar7 * 4);

    if (puVar8 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar7 * 4)) {

      do {

        if (((uint)*(ushort *)(puVar8 + 2) & *(uint *)(unaff_ESI + 0x20)) == uVar7) {

          puVar9 = (uint32_t /* width from decompiler */ *)*puVar8;

        }

        else {

          puVar9 = (uint32_t /* width from decompiler */ *)*puVar8;

          if (puVar9 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar7 * 4);

            uVar5 = uVar7;

            while ((puVar8 == puVar1 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar5 * 4) = puVar9, uVar5 != 0)))

            {

              uVar5 = uVar5 - 1;

              puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar5 * 4);

            }

            iVar4 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar8[1] = puVar9;

            *(int *)puVar9[1] = iVar4;

            **(uint32_t /* width from decompiler */ **)(iVar4 + 4) = puVar8;

            uVar3 = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 4) = puVar9[1];

            puVar9[1] = puVar8[1];

            puVar8[1] = uVar3;

            puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar5 = *(uint *)(unaff_ESI + 0x24);

              (uVar7 < uVar5 &&

              (*(int *)(*(int *)(unaff_ESI + 0x14) + uVar5 * 4) == *(int *)(unaff_ESI + 8)));

              uVar5 = uVar5 - 1) {

            *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar5 * 4) = puVar8;

          }

          if (puVar9 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar8 = puVar9;

      } while (puVar9 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar7 * 4));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  uVar2 = *param_2;

  uVar7 = (uint)uVar2 & *(uint *)(unaff_ESI + 0x20);

  if (*(uint *)(unaff_ESI + 0x24) <= uVar7) {

    uVar7 = uVar7 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar4 = uVar7 * 4;

  puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar4);

  if (puVar8 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar4)) {

    do {

      puVar8 = (uint32_t /* width from decompiler */ *)puVar8[1];

      if (*(ushort *)(puVar8 + 2) <= uVar2) {

        if (uVar2 <= *(ushort *)(puVar8 + 2)) {

          *param_1 = (int)puVar8;

          *(uint8_t *)(param_1 + 1) = 0;

          return;

        }

        puVar8 = (uint32_t /* width from decompiler */ *)*puVar8;

        break;

      }

    } while (puVar8 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar4));

  }

  iVar6 = FUN_00444190(puVar8,puVar8[1]);

  FUN_00463dc0();

  puVar8[1] = iVar6;

  **(int **)(iVar6 + 4) = iVar6;

  iVar6 = puVar8[1];

  puVar9 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar4);

  while ((puVar8 == puVar9 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar4) = iVar6, uVar7 != 0))) {

    uVar7 = uVar7 - 1;

    iVar4 = uVar7 * 4;

    puVar9 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar4);

  }

  *param_1 = iVar6;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
