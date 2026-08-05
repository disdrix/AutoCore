// =============================================================================
// Gfx_NDLeaf
// -----------------------------------------------------------------------------
// Stable ID: aa_005b67a0
// Address:   0x005b67a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_NDLeaf @ 0x005b67a0
// Stable ID: aa_005b67a0
// Embedded strings (evidence for future rename):
//   - "NDLeaf.fx"
//   - "DiffuseTexture"
//   - "WindMatrices"
//   - "LeafTables"
//   - "AlphaRefValue"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×20, do×4, while×4, return×3.
//  - Notable callees: FUN_00752370×3, FUN_0096f510×2, FUN_00414c20, Gfx_NDLeaf, FUN_006868a0, FUN_00687220, FUN_00687810, FUN_0068a4d0.
//  - Strings: "NDLeaf.fx"; "DiffuseTexture"; "WindMatrices"; "LeafTables".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDLeaf.fx"
 * Domain alias of FUN_005b67a0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Gfx_NDLeaf(int param_1)



{

  int *piVar1;

  uint *puVar2;

  char cVar3;

  ushort uVar4;

  int iVar5;

  int *piVar6;

  uint16_t uVar7;

  void *pvVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iVar13;

  int iVar14;

  int *piVar15;

  uint32_t /* width from decompiler */ **ppuVar16;

  uint uVar17;

  uint32_t /* width from decompiler */ *puStack_68;

  int iStack_64;

  int local_60;

  uint uStack_5c;

  int local_54 [3];

  uint32_t /* width from decompiler */ *local_48;

  uint8_t auStack_44 [4];

  uint8_t auStack_40 [4];

  uint8_t auStack_3c [4];

  int *local_38;

  uint8_t uStack_34;

  uint8_t uStack_33;

  uint8_t uStack_32;

  short local_30 [6];

  uint8_t auStack_24 [4];

  void *pvStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a69de;

  local_c = ExceptionList;

  local_30[0] = 0;

  local_30[1] = 1;

  local_30[2] = 2;

  local_30[3] = 0;

  local_30[4] = 2;

  local_30[5] = 3;

  ExceptionList = &local_c;

  uVar7 = FUN_00687220();

  *(uint16_t *)(param_1 + 0x74) = uVar7;

  FUN_006868a0(1);

  pvVar8 = operator_new__((uint)*(ushort *)(param_1 + 0x74) * 4);

  *(void **)(param_1 + 0x14) = pvVar8;

  if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {

    pvVar8 = operator_new__((uint)*(ushort *)(param_1 + 0x74));

    *(void **)(param_1 + 0x7c) = pvVar8;

    pvVar8 = operator_new__((uint)*(ushort *)(param_1 + 0x74) * 4);

    *(void **)(*(int *)(param_1 + 0x174) + 0x114) = pvVar8;

  }

  FUN_0096f530();

  local_4 = 0;

  FUN_00989e00(local_54,"NDLeaf.fx");

  iVar9 = FUN_009701d0(local_54);

  if (-1 < iVar9) {

    FUN_00970140("DiffuseTexture",**(uint32_t /* width from decompiler */ **)(param_1 + 0x24));

    iVar9 = 0;

    if (*(short *)(param_1 + 0x74) != 0) {

      do {

        puVar10 = operator_new(0xdc);

        local_4._0_1_ = 1;

        local_48 = puVar10;

        if (puVar10 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar10 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          FUN_00748960();

          *puVar10 = &PTR_FUN_009d9924;

          puVar10[1] = &PTR_LAB_009d9914;

          puVar10[0x34] = 0xffffffff;

          puVar10[0x35] = 0xffffffff;

          puVar10[0x36] = 0xffffffff;

          *(uint8_t *)(puVar10 + 0x33) = 0;

          puVar10[0x31] = 0;

          puVar10[0x32] = 0;

        }

        *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x14) + iVar9 * 4) = puVar10;

        local_4 = (uint)local_4._1_3_ << 8;

        uVar11 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();

        *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4) + 100) = uVar11;

        iVar5 = **(int **)(*(int *)(param_1 + 0x14) + iVar9 * 4);

        uVar11 = (**(code **)(**(int **)(param_1 + 8) + 100))();

        (**(code **)(iVar5 + 0x34))(uVar11);

        piVar15 = local_38;

        iVar5 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);

        if ((local_38 != (int *)0x0) && (local_38[1] = local_38[1] + 1, local_38[1] == 1)) {

          (**(code **)(*local_38 + 4))();

        }

        piVar6 = *(int **)(iVar5 + 0x20);

        if (piVar6 != (int *)0x0) {

          piVar1 = piVar6 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar6 + 8))();

          }

        }

        *(int **)(iVar5 + 0x20) = piVar15;

        *(uint8_t *)(iVar5 + 0x24) = uStack_34;

        *(uint8_t *)(iVar5 + 0x25) = uStack_33;

        *(uint8_t *)(iVar5 + 0x26) = uStack_32;

        iVar9 = iVar9 + 1;

      } while (iVar9 < (int)(uint)*(ushort *)(param_1 + 0x74));

    }

    local_54[0] = 0;

    if (*(short *)(param_1 + 0x74) != 0) {

      local_60 = 0;

      do {

        iVar9 = local_54[0];

        FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),4,0,0,local_54[0]);

        uVar4 = *(ushort *)(*(int *)(param_1 + 0x50) + 0x84);

        if (uVar4 == 0) {

          puVar10 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x14) + local_60 * 4);

          if (puVar10 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar10)(1);

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + local_60 * 4) = 0;

          local_54[0] = iVar9;

        }

        else {

          iVar9 = *(int *)(*(int *)(param_1 + 0x14) + local_60 * 4);

          *(uint *)(iVar9 + 0xbc) = *(uint *)(iVar9 + 0xbc) | 1;

          if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {

            cVar3 = *(char *)(*(int *)(param_1 + 4) + 0x7d);

            *(uint8_t *)(*(int *)(param_1 + 0x7c) + local_60) = 0;

            pvStack_20 = (void *)0x0;

            uStack_1c = 0;

            uStack_18 = 0;

            uStack_14 = 0;

            uStack_10 = 0;

            local_4._0_1_ = 2;

            FUN_007478c0(DAT_00af3efc);

            local_4._0_1_ = 3;

            FUN_00414c20((uint)uVar4 * 6,auStack_24,(-(uint)(cVar3 != '\0') & 0xfffffffe) + 2 | 0x20

                         ,0);

            local_4 = (uint)local_4._1_3_ << 8;

            uStack_14 = 0;

            uStack_10 = 0;

            if (pvStack_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete(pvStack_20);

            }

            iVar5 = *(int *)(iVar9 + 0x14);

            pvStack_20 = (void *)0x0;

            uStack_1c = 0;

            uStack_18 = 0;

            if (((*(int *)(iVar5 + 0x10) != 0) &&

                (puStack_68 = (uint32_t /* width from decompiler */ *)

                              FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x14),

                                           *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18),0),

                puStack_68 != (uint32_t /* width from decompiler */ *)0x0)) && (uVar17 = 0, uVar4 != 0)) {

              iStack_64 = 0;

              do {

                iVar5 = *(int *)(param_1 + 0x50);

                uStack_5c = 0;

                puVar10 = puStack_68 + 6;

                do {

                  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x90) + iStack_64);

                  *puStack_68 = *puVar12;

                  puStack_68[1] = puVar12[1];

                  puStack_68[2] = puVar12[2];

                  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0xa0) + iStack_64);

                  puVar10[-3] = *puVar12;

                  puVar10[-2] = puVar12[1];

                  puVar10[-1] = puVar12[2];

                  iVar13 = (int)local_30[uStack_5c];

                  iVar14 = *(int *)(*(int *)(iVar5 + 0x94) + uVar17 * 4);

                  *puVar10 = *(uint32_t /* width from decompiler */ *)(iVar14 + iVar13 * 8);

                  puVar10[1] = *(uint32_t /* width from decompiler */ *)(iVar14 + 4 + iVar13 * 8);

                  puVar10[2] = (float)*(byte *)(*(int *)(iVar5 + 0xb0) + uVar17);

                  puVar10[3] = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0xac) + uVar17 * 4);

                  puVar10[4] = (float)*(byte *)(*(int *)(iVar5 + 0x8c) + uVar17) * DAT_00aaa690 +

                               (float)iVar13;

                  iVar14 = FUN_00687810();

                  puStack_68 = puStack_68 + 0xc;

                  uStack_5c = uStack_5c + 1;

                  puVar10[5] = *(uint32_t /* width from decompiler */ *)(iVar14 + local_60 * 4);

                  puVar10 = puVar10 + 0xc;

                } while (uStack_5c < 6);

                iStack_64 = iStack_64 + 0xc;

                uVar17 = uVar17 + 1;

              } while (uVar17 < uVar4);

            }

            if (*(int *)(*(int *)(iVar9 + 0x14) + 0x10) != 0) {

              FUN_007464e0();

            }

            *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x174) + 0x114) + local_60 * 4) =

                 *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

          }

          else {

            piVar15 = *(int **)(*(int *)(*(int *)(param_1 + 0x174) + 0x114) + local_60 * 4);

            if ((piVar15 != (int *)0x0) && (piVar15[1] = piVar15[1] + 1, piVar15[1] == 1)) {

              (**(code **)(*piVar15 + 4))();

            }

            piVar6 = *(int **)(iVar9 + 0x14);

            if (piVar6 != (int *)0x0) {

              piVar1 = piVar6 + 1;

              *piVar1 = *piVar1 + -1;

              if (*piVar1 == 0) {

                (**(code **)(*piVar6 + 8))();

              }

            }

            *(int **)(iVar9 + 0x14) = piVar15;

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xac) = 4;

          *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xa8) = (uint)uVar4 * 2;

          FUN_0096f740();

          puVar2 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xbc);

          *puVar2 = *puVar2 & 0xfffffffe;

          FUN_007647c0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + local_60 * 4));

          if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0x20) == 0) {

            local_54[1] = 0xffffffff;

            piVar15 = local_54 + 1;

          }

          else {

            piVar15 = (int *)FUN_00752370(auStack_44,"WindMatrices");

          }

          *(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xd0) = *piVar15;

          if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0x20) == 0) {

            local_54[2] = 0xffffffff;

            piVar15 = local_54 + 2;

          }

          else {

            piVar15 = (int *)FUN_00752370(auStack_40,"LeafTables");

          }

          *(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xd4) = *piVar15;

          if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0x20) == 0) {

            local_48 = (uint32_t /* width from decompiler */ *)0xffffffff;

            ppuVar16 = &local_48;

          }

          else {

            ppuVar16 = (uint32_t /* width from decompiler */ **)FUN_00752370(auStack_3c,"AlphaRefValue");

          }

          *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0x14) + local_60 * 4) + 0xd8) = *ppuVar16;

        }

        local_54[0] = local_54[0] + 1;

        local_60 = (int)(short)local_54[0];

      } while (local_60 < (int)(uint)*(ushort *)(param_1 + 0x74));

    }

    local_4 = 0xffffffff;

    FUN_0096f510();

    ExceptionList = local_c;

    return;

  }

  local_4 = 0xffffffff;

  FUN_0096f510();

  ExceptionList = local_c;

  return;

}
