// =============================================================================
// FUN_00749d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00749d10
// Address:   0x00749d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00749d10 @ 0x00749d10
// Stable ID: aa_00749d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~162 non-empty decompiler lines.
//  - Control keywords: if×13, for×4, return×2.
//  - Notable callees: FUN_00414c20×2, FUN_00414a50, FUN_00414b60, FUN_0044b9c0, FUN_0044ba80, FUN_0044bbc0, FUN_007478c0, FUN_00748260.
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

uint32_t /* width from decompiler */ __thiscall FUN_00749d10(int param_1,int *param_2)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  undefined *puVar8;

  uint uVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ *puStack_30;

  undefined **ppuStack_2c;

  int *piStack_28;

  uint8_t auStack_24 [4];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b23da;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00748260();

  piVar1 = param_2;

  uVar3 = (**(code **)(*param_2 + 0x10))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = uVar3;

  uVar3 = (**(code **)*piVar1)();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = uVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  if (*(int *)(param_1 + 0xa8) != 0) {

    piStack_28 = (int *)0x0;

    ppuStack_2c = &PTR_FUN_00a9db18;

    uStack_20 = 0;

    uStack_1c = 0;

    uStack_18 = 0;

    uStack_14 = 0;

    uStack_10 = 0;

    uStack_4 = 1;

    uVar3 = (**(code **)(*piVar1 + 0x14))();

    FUN_007478c0(uVar3);

    uVar14 = 0;

    uVar13 = 8;

    puVar12 = auStack_24;

    uVar3 = (**(code **)(*piVar1 + 8))(puVar12,8,0);

    FUN_00414c20(uVar3,puVar12,uVar13,uVar14);

    piVar10 = (int *)piStack_28[4];

    if (piVar10 != (int *)0x0) {

      piVar6 = (int *)*piVar10;

      param_2 = (int *)piStack_28[6];

      if (piVar6 == (int *)0x0) {

        piVar10 = (int *)0x0;

      }

      else {

        iVar4 = (**(code **)(*piVar6 + 0x2c))

                          (piVar6,piVar10[2] * piStack_28[5],piVar10[2] * (int)param_2,&param_2,

                           0x800);

        if (iVar4 < 0) {

          piVar10 = (int *)0x0;

        }

        else {

          piVar10[4] = piVar10[4] + 1;

          piVar10 = param_2;

        }

      }

      if (piVar10 != (int *)0x0) {

        iVar4 = (**(code **)(*piVar1 + 0x18))();

        iVar5 = (**(code **)(*piVar1 + 8))();

        piVar6 = (int *)(**(code **)(*piVar1 + 0x1c))();

        for (uVar9 = (uint)(iVar4 * iVar5) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *piVar10 = *piVar6;

          piVar6 = piVar6 + 1;

          piVar10 = piVar10 + 1;

        }

        for (uVar9 = iVar4 * iVar5 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(char *)piVar10 = (char)*piVar6;

          piVar6 = (int *)((int)piVar6 + 1);

          piVar10 = (int *)((int)piVar10 + 1);

        }

      }

    }

    FUN_00414a50();

    iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x14);

    if ((iVar4 == 0) || (param_2 = (int *)0x10, *(char *)(iVar4 + 0x10) == '\0')) {

      param_2 = (int *)0x20;

    }

    cVar2 = (**(code **)(*piVar1 + 4))();

    if (cVar2 != '\0') {

      uVar3 = (**(code **)(*piVar1 + 0xc))(0x20,0,0);

      FUN_0044b9c0(uVar3);

      iVar4 = *(int *)(param_1 + 0xc);

      piVar10 = *(int **)(iVar4 + 0x10);

      if (piVar10 != (int *)0x0) {

        puStack_30 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x18);

        piVar6 = (int *)*piVar10;

        if (piVar6 == (int *)0x0) {

          puVar11 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          iVar4 = (**(code **)(*piVar6 + 0x2c))

                            (piVar6,piVar10[4] * (int)puStack_30,piVar10[4] * *(int *)(iVar4 + 0x1c)

                             ,&puStack_30,0x800);

          if (iVar4 < 0) {

            puVar11 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            piVar10[3] = piVar10[3] + 1;

            puVar11 = puStack_30;

          }

        }

        if (puVar11 != (uint32_t /* width from decompiler */ *)0x0) {

          iVar4 = (**(code **)(*piVar1 + 0xc))();

          puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar1 + 0x20))();

          for (uVar9 = (uint)(iVar4 * 2) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

            *puVar11 = *puVar7;

            puVar7 = puVar7 + 1;

            puVar11 = puVar11 + 1;

          }

          for (uVar9 = iVar4 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

            *(uint8_t *)puVar11 = *(uint8_t *)puVar7;

            puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

            puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

          }

        }

      }

      FUN_0044ba80();

    }

    iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x14);

    if (iVar4 == 0) {

      puVar8 = &DAT_00d1eccc;

    }

    else {

      puVar8 = (undefined *)(iVar4 + 0xac);

    }

    uVar14 = 0;

    uVar3 = param_2;

    uVar13 = (**(code **)(*piVar1 + 8))(puVar8,param_2,0);

    FUN_00414c20(uVar13,puVar8,uVar3,uVar14);

    uVar3 = FUN_0044bbc0(&ppuStack_2c,param_1 + 8,0);

    FUN_00414b60();

    uStack_4 = 0xffffffff;

    piVar1 = piStack_28 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piStack_28 + 8))();

    }

    ExceptionList = pvStack_c;

    return uVar3;

  }

  ExceptionList = pvStack_c;

  return 0;

}
