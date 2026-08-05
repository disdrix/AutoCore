// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxFont_004638c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004638c0
// Callee of Named_CalleeOf_Named_gfxFont
// Address:   0x004638c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxFont: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×15, while×4, for×3, do×2, return×2.
//  - Notable callees: FUN_0044a380, FUN_004638c0, FUN_00463dc0, FUN_00464080, block.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxFont
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

/* WARNING: Removing unreachable block (ram,0x004639d7) */



void Named_CalleeOf_Named_CalleeOf_Named_gfxFont_004638c0(int *param_1,

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                 *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  bool bVar3;

  uint uVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  uint uVar9;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  

  uVar9 = *(uint *)(unaff_ESI + 0x24);

  if (uVar9 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar9 < iVar8 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar9) {

        *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) * 2 + 1;

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x14) == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

      }

      *(int *)(unaff_ESI + 0x20) = iVar8 * 2 + -3;

      FUN_0044a380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    uVar9 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar10 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar9 * 4);

    if (puVar10 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar9 * 4)) {

      do {

        iVar8 = puVar10[7];

        if ((uint)puVar10[8] < 0x10) {

          pcVar7 = (char *)(puVar10 + 3);

        }

        else {

          pcVar7 = (char *)puVar10[3];

        }

        uVar4 = 0x1505;

        for (; iVar8 != 0; iVar8 = iVar8 + -1) {

          uVar4 = (int)*pcVar7 + uVar4 * 0x21;

          pcVar7 = pcVar7 + 1;

        }

        if (((puVar10[10] ^ puVar10[9] ^ uVar4) & *(uint *)(unaff_ESI + 0x20)) == uVar9) {

          puVar11 = (uint32_t /* width from decompiler */ *)*puVar10;

        }

        else {

          puVar11 = (uint32_t /* width from decompiler */ *)*puVar10;

          if (puVar11 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar9 * 4);

            uVar4 = uVar9;

            while ((puVar10 == puVar1 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) = puVar11, uVar4 != 0))

                  ) {

              uVar4 = uVar4 - 1;

              puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4);

            }

            iVar8 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar10[1] = puVar11;

            *(int *)puVar11[1] = iVar8;

            **(uint32_t /* width from decompiler */ **)(iVar8 + 4) = puVar10;

            uVar2 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar8 + 4) = puVar11[1];

            puVar11[1] = puVar10[1];

            puVar10[1] = uVar2;

            puVar10 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar4 = *(uint *)(unaff_ESI + 0x24);

              (uVar9 < uVar4 &&

              (*(int *)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) == *(int *)(unaff_ESI + 8)));

              uVar4 = uVar4 - 1) {

            *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar4 * 4) = puVar10;

          }

          if (puVar11 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar10 = puVar11;

      } while (puVar11 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + uVar9 * 4));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  iVar8 = *(int *)(param_2 + 0x14);

  if (*(uint *)(param_2 + 0x18) < 0x10) {

    pbVar5 = param_2 + 4;

  }

  else {

    pbVar5 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

              (param_2 + 4);

  }

  uVar9 = 0x1505;

  for (; iVar8 != 0; iVar8 = iVar8 + -1) {

    uVar9 = (int)(char)*pbVar5 + uVar9 * 0x21;

    pbVar5 = pbVar5 + 1;

  }

  uVar9 = (*(uint *)(param_2 + 0x1c) ^ *(uint *)(param_2 + 0x20) ^ uVar9) &

          *(uint *)(unaff_ESI + 0x20);

  if (*(uint *)(unaff_ESI + 0x24) <= uVar9) {

    uVar9 = uVar9 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar8 = uVar9 * 4;

  puVar10 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar8);

  if (puVar10 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar8)) {

    do {

      puVar10 = (uint32_t /* width from decompiler */ *)puVar10[1];

      bVar3 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (param_2,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                  *)(puVar10 + 2));

      if ((!bVar3) &&

         ((bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                             (param_2,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                       *)(puVar10 + 2)), !bVar3 ||

          (((int)puVar10[9] <= *(int *)(param_2 + 0x1c) &&

           ((*(int *)(param_2 + 0x1c) != puVar10[9] ||

            ((int)puVar10[10] <= *(int *)(param_2 + 0x20))))))))) {

        bVar3 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                            *)(puVar10 + 2),param_2);

        if ((!bVar3) &&

           ((bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                                 *)(puVar10 + 2),param_2), !bVar3 ||

            ((*(int *)(param_2 + 0x1c) <= (int)puVar10[9] &&

             ((puVar10[9] != *(int *)(param_2 + 0x1c) ||

              (*(int *)(param_2 + 0x20) <= (int)puVar10[10])))))))) {

          *param_1 = (int)puVar10;

          *(uint8_t *)(param_1 + 1) = 0;

          return;

        }

        puVar10 = (uint32_t /* width from decompiler */ *)*puVar10;

        break;

      }

    } while (puVar10 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar8));

  }

  iVar6 = FUN_00464080(puVar10,puVar10[1]);

  FUN_00463dc0();

  puVar10[1] = iVar6;

  **(int **)(iVar6 + 4) = iVar6;

  iVar6 = puVar10[1];

  puVar11 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar8);

  while ((puVar10 == puVar11 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar8) = iVar6, uVar9 != 0)))

  {

    uVar9 = uVar9 - 1;

    iVar8 = uVar9 * 4;

    puVar11 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar8);

  }

  *param_1 = iVar6;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
