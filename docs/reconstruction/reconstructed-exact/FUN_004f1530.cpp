// =============================================================================
// FUN_004f1530
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1530
// Address:   0x004f1530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f1530 @ 0x004f1530
// Stable ID: aa_004f1530
// Embedded strings (evidence for future rename):
//   - "Rigid body of object \'%s\' is zero length"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×20, do×5, while×5, return×4, for×3.
//  - Notable callees: CONCAT31×3, FUN_00403450×2, FUN_005f3160×2, FUN_00743ba0×2, FUN_007464e0×2, FUN_007a4480×2, free×2, FUN_00404d80.
//  - Strings: "Rigid body of object \'%s\' is zero length".
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

/* WARNING: Removing unreachable block (ram,0x004f1b63) */



int * __fastcall FUN_004f1530(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  void *pvVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint uVar10;

  uint16_t *puVar11;

  int iVar12;

  char **ppcVar13;

  int iVar14;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar15;

  uint32_t /* width from decompiler */ auStack_2b4 [23];

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  undefined *puStack_250;

  int *piVar16;

  uint32_t /* width from decompiler */ *puStack_224;

  int *piStack_220;

  int *piStack_21c;

  uint32_t /* width from decompiler */ uStack_1fc;

  uint32_t /* width from decompiler */ uStack_1f8;

  uint32_t /* width from decompiler */ uStack_1f4;

  uint uStack_1e4;

  char *local_1ac;

  char local_1a8 [127];

  uint32_t /* width from decompiler */ uStack_129;

  void *pvStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a2b38;

  local_1c = ExceptionList;

  if (*(int *)(param_1 + 0x3c) != 0) {

    local_1ac = local_1a8;

    ExceptionList = &local_1c;

    (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450();

    pcVar3 = local_1ac;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)&uStack_129 + (1 - (int)local_1ac)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    if (local_1ac != local_1a8) {

      free(local_1ac);

    }

    puVar15 = &uStack_129;

    do {

      pcVar3 = (char *)((int)puVar15 + 1);

      puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

    } while (*pcVar3 != '\0');

    *puVar15 = DAT_009cb318;

    FUN_007b6a20();

    piVar4 = (int *)FUN_007b7420();

    if (piVar4 != (int *)0x0) {

      iVar5 = (**(code **)(*piVar4 + 0x1c))();

      if (iVar5 == 0) {

        (**(code **)*piVar4)();

        (*(code *)PTR_FUN_00af8c9c)();

        FUN_00403450();

        uStack_14 = 0;

        ppcVar13 = &local_1ac;

        puVar15 = auStack_2b4;

        for (iVar5 = 0x21; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar15 = *ppcVar13;

          ppcVar13 = ppcVar13 + 1;

          puVar15 = puVar15 + 1;

        }

        FUN_007a4480(1,"Rigid body of object \'%s\' is zero length");

        if (local_1ac != local_1a8) {

          free(local_1ac);

          ExceptionList = local_1c;

          return (int *)0x0;

        }

      }

      else {

        (**(code **)(*piVar4 + 0x1c))();

        FUN_005f3120();

        uStack_14 = 1;

        iVar5 = FUN_005f3740();

        piVar16 = (int *)0x1;

        (**(code **)*piVar4)();

        piStack_21c = *(int **)(iVar5 + 4);

        puVar15 = operator_new__((int)piStack_21c * 0x1c);

        puStack_18._0_1_ = 2;

        if (puVar15 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar15 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          FUN_00404d80();

        }

        puStack_18 = (uint8_t *)CONCAT31(puStack_18._1_3_,1);

        if (0 < (int)piStack_21c) {

          puVar9 = puVar15 + 6;

          do {

            puVar6 = (uint32_t /* width from decompiler */ *)FUN_004e88e0();

            puVar9[-6] = *puVar6;

            puVar9[-5] = puVar6[1];

            puVar9[-4] = puVar6[2];

            puVar9[-3] = DAT_00afdfc8;

            puVar9[-2] = DAT_00afdfcc;

            uVar2 = DAT_00afdfd0;

            *puVar9 = 0x7f5176af;

            piStack_21c = (int *)((int)piStack_21c + -1);

            puVar9[-1] = uVar2;

            puVar9 = puVar9 + 7;

          } while (piStack_21c != (int *)0x0);

        }

        piStack_21c = (int *)0x0;

        if (0 < *(int *)(iVar5 + 0x10)) {

          piStack_220 = (int *)0x0;

          do {

            piVar4 = (int *)(*(int *)(iVar5 + 0xc) + (int)piStack_220);

            FUN_0076e240();

            FUN_0076f5f0();

            puVar9 = puVar15 + *piVar4 * 7 + 3;

            *puVar9 = uStack_1fc;

            puVar9[1] = uStack_1f8;

            puVar9[2] = uStack_1f4;

            puVar9 = puVar15 + piVar4[1] * 7 + 3;

            *puVar9 = uStack_1fc;

            puVar9[1] = uStack_1f8;

            puVar9[2] = uStack_1f4;

            puVar9 = puVar15 + piVar4[2] * 7 + 3;

            *puVar9 = uStack_1fc;

            puVar9[1] = uStack_1f8;

            puVar9[2] = uStack_1f4;

            piStack_21c = (int *)((int)piStack_21c + 1);

            piStack_220 = (int *)((int)piStack_220 + 0xc);

          } while ((int)piStack_21c < *(int *)(iVar5 + 0x10));

        }

        pvVar7 = operator_new(0x14c);

        puStack_18._0_1_ = 3;

        if (pvVar7 == (void *)0x0) {

          piStack_220 = (int *)0x0;

        }

        else {

          piStack_220 = (int *)FUN_00764030();

        }

        puStack_18._0_1_ = 1;

        FUN_007638d0();

        pvVar7 = operator_new(0xc4);

        puStack_18._0_1_ = 4;

        if (pvVar7 == (void *)0x0) {

          piStack_21c = (int *)0x0;

        }

        else {

          piStack_21c = (int *)FUN_00748960();

        }

        puStack_18 = (uint8_t *)CONCAT31(puStack_18._1_3_,1);

        iVar8 = (**(code **)(*piStack_220 + 0xc))();

        piStack_21c[0x19] = iVar8;

        iVar8 = *piStack_21c;

        (**(code **)(*piStack_220 + 100))();

        (**(code **)(iVar8 + 0x34))();

        FUN_00989e00();

        FUN_009701d0();

        local_1c._0_1_ = 5;

        FUN_007478c0();

        piStack_21c[0x2f] = piStack_21c[0x2f] | 1;

        local_1c = (void *)CONCAT31(local_1c._1_3_,6);

        iVar8 = FUN_00414c20();

        if (iVar8 < 0) {

          (**(code **)*puStack_224)();

          (**(code **)*piStack_21c)();

        }

        else if ((*(int *)(piStack_21c[5] + 0x10) == 0) ||

                (puVar9 = (uint32_t /* width from decompiler */ *)FUN_00746520(), puVar9 == (uint32_t /* width from decompiler */ *)0x0)) {

          if (*(int *)(piStack_21c[5] + 0x10) != 0) {

            FUN_007464e0();

          }

          (**(code **)*puStack_224)();

          (**(code **)*piStack_21c)();

        }

        else {

          for (uVar10 = uStack_1e4 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

            *puVar9 = *puVar15;

            puVar15 = puVar15 + 1;

            puVar9 = puVar9 + 1;

          }

          for (uVar10 = uStack_1e4 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

            *(uint8_t *)puVar9 = *(uint8_t *)puVar15;

            puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

            puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

          }

          if (*(int *)(piStack_220[5] + 0x10) != 0) {

            FUN_007464e0();

          }

          FUN_0044b9c0();

          iVar8 = piStack_220[3];

          if (*(int *)(iVar8 + 0x10) != 0) {

            puStack_250 = *(undefined **)(iVar8 + 0x1c);

            uStack_254 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x18);

            uStack_258 = 0x4f1b19;

            iVar8 = FUN_00743be0();

            if (iVar8 != 0) {

              iVar14 = 0;

              if (0 < *(int *)(iVar5 + 0x10)) {

                iVar12 = 0;

                puVar11 = (uint16_t *)(iVar8 + 4);

                do {

                  iVar8 = *(int *)(iVar5 + 0xc) + iVar12;

                  puVar11[-2] = *(uint16_t *)(*(int *)(iVar5 + 0xc) + iVar12);

                  puVar11[-1] = *(uint16_t *)(iVar8 + 4);

                  *puVar11 = *(uint16_t *)(iVar8 + 8);

                  iVar14 = iVar14 + 1;

                  iVar12 = iVar12 + 0xc;

                  puVar11 = puVar11 + 3;

                  piStack_220 = unaff_EDI;

                } while (iVar14 < *(int *)(iVar5 + 0x10));

              }

              if (*(int *)(piStack_220[3] + 0x10) != 0) {

                FUN_00743ba0();

              }

              piStack_220[0x2a] = *(int *)(iVar5 + 0x10);

              piStack_220[0x2b] = 4;

              FUN_0096f740();

              puStack_250 = (undefined *)0x4f1c15;

              FUN_007647c0();

              (**(code **)(*piVar16 + 0x50))();

              if (puStack_224 == (uint32_t /* width from decompiler */ *)0x0) {

                uStack_2c = 0xffffffff;

                FUN_005f3160();

                ExceptionList = pvStack_34;

                return piVar16;

              }

                    /* WARNING: Subroutine does not return */

              puStack_250 = &UNK_004f1c34;

              operator_delete(puStack_224);

            }

          }

          puStack_250 = (undefined *)0x0;

          uStack_254 = 0x4f1b2d;

          FUN_007a4480();

          if (*(int *)(piStack_220[3] + 0x10) != 0) {

            FUN_00743ba0();

          }

          puStack_250 = (undefined *)0x4f1b4b;

          (**(code **)*piVar16)();

          puStack_250 = (undefined *)0x1;

          uStack_254 = 0x4f1b53;

          (**(code **)*piStack_220)();

        }

        uStack_14 = 0xffffffff;

        FUN_005f3160();

      }

    }

  }

  ExceptionList = local_1c;

  return (int *)0x0;

}
