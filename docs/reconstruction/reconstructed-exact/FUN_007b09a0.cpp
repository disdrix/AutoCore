// =============================================================================
// FUN_007b09a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b09a0
// Address:   0x007b09a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b09a0 @ 0x007b09a0
// Stable ID: aa_007b09a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×22, return×4, for×2, do×2, while×2, goto×1.
//  - Notable callees: FUN_0040ead0, FUN_0040ebd0, FUN_007a7380, FUN_007ae250, FUN_007ae350, FUN_007b09a0, FUN_0099b010, FUN_0099b230.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ * FUN_007b09a0(int *param_1)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  uint64_t uVar11;

  uint local_34;

  uint32_t /* width from decompiler */ local_2c;

  uint8_t local_14 [4];

  int local_10;

  int local_c;

  uint local_8;

  int local_4;

  

  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  iVar3 = *(int *)(*param_1 + 0x4c);

  if (iVar3 == 0) {

    puVar2 = &DAT_00d1ed24;

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)(iVar3 + 4);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_007ae350(puVar2);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    local_2c = 0xff000000;

    uVar11 = FUN_007a7380(*(uint32_t /* width from decompiler */ *)(*param_1 + 0x24));

    iVar8 = (int)((ulonglong)uVar11 >> 0x20);

    iVar3 = (int)uVar11;

    if (-1 < iVar3) {

      local_c = *(int *)(iVar8 + 0x20);

      iVar8 = *(int *)(iVar8 + 0x1c);

      iVar4 = local_c * iVar8 + 7;

      uVar10 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;

      if ((int)uVar10 < 0) {

        uVar10 = 1;

      }

      local_10 = iVar8;

      puVar2 = operator_new__(uVar10);

      if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

        return (uint32_t /* width from decompiler */ *)0x0;

      }

      puVar5 = puVar2;

      for (uVar6 = uVar10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint8_t *)puVar5 = 0;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      }

      iVar4 = FUN_0040ebd0(0,0);

      if (iVar4 == 0) {

        operator_delete__(puVar2);

        iVar3 = *param_1;

        if (iVar3 != 0) {

          uVar10 = *(uint *)(iVar3 + 0x2c) & 0xf;

          if (uVar10 == 1) {

            (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))(*(int **)(iVar3 + 0x10),0);

          }

          else if (uVar10 == 2) {

            (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))

                      (*(int **)(iVar3 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c),0);

          }

          else if (uVar10 == 4) {

            (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))(*(int **)(iVar3 + 0x10),0);

          }

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = 0;

        }

        return (uint32_t /* width from decompiler */ *)0x0;

      }

      local_34 = 0;

      if (0 < iVar8) {

        do {

          iVar9 = 0;

          uVar10 = local_34;

          if (0 < local_c) {

            do {

              uVar6 = uVar10 & 0x80000007;

              if ((int)uVar6 < 0) {

                uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;

              }

              if (iVar3 == 0) {

                FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(*param_1 + 0x24));

                puVar5 = (uint32_t /* width from decompiler */ *)FUN_0099b010();

LAB_007b0b9e:

                local_2c = *puVar5;

              }

              else if (iVar3 == 1) {

                iVar8 = *param_1;

                if (iVar8 == 0) {

                  uVar7 = 0;

                }

                else {

                  uVar7 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x40);

                }

                local_8 = local_34;

                local_4 = iVar9;

                puVar5 = (uint32_t /* width from decompiler */ *)

                         FUN_0099b230(local_14,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x24),&local_8,iVar4,uVar7);

                goto LAB_007b0b9e;

              }

              if ((char)((uint)local_2c >> 0x18) != '\0') {

                pbVar1 = (byte *)(((int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3) + (int)puVar2);

                *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar6 & 0x1f);

              }

              iVar9 = iVar9 + 1;

              iVar8 = local_10;

              uVar10 = uVar10 + local_10;

            } while (iVar9 < local_c);

          }

          local_34 = local_34 + 1;

        } while ((int)local_34 < iVar8);

      }

      iVar3 = *param_1;

      if (iVar3 != 0) {

        uVar10 = *(uint *)(iVar3 + 0x2c) & 0xf;

        if (uVar10 == 1) {

          (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))(*(int **)(iVar3 + 0x10),0);

        }

        else if (uVar10 == 2) {

          (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))

                    (*(int **)(iVar3 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c),0);

        }

        else if (uVar10 == 4) {

          (**(code **)(**(int **)(iVar3 + 0x10) + 0x50))(*(int **)(iVar3 + 0x10),0);

        }

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = 0;

      }

      FUN_007ae250(puVar2);

    }

  }

  return puVar2;

}
