// =============================================================================
// FUN_0086b510
// -----------------------------------------------------------------------------
// Stable ID: aa_0086b510
// Address:   0x0086b510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086b510 @ 0x0086b510
// Stable ID: aa_0086b510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~188 non-empty decompiler lines.
//  - Control keywords: if×26, return×12, do×2, while×2, switch×1.
//  - Notable callees: FUN_007fca10×3, FUN_004ce940×2, FUN_007fef20×2, CVOGReaction_GiveItemByCbid, FUN_00508e20, FUN_00509c70, FUN_00516720, FUN_007fcc10.
//  - Return sites: 12.

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

uint32_t /* width from decompiler */ __thiscall FUN_0086b510(int param_1,int param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t uVar7;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  int iVar12;

  int iStack_14;

  int iStack_4;

  

  switch(param_3 + -40000) {

  case 0:

    if (param_2 == 8) {

      FUN_007fca10();

      return 1;

    }

    break;

  case 1:

    if (param_2 == 8) {

      if (*(int **)(param_1 + 0x5b4) != (int *)0x0) {

        uVar8 = (**(code **)(**(int **)(param_1 + 0x5b4) + 0x44c))();

        FUN_0093a180(uVar8);

      }

      (**(code **)(**(int **)(param_1 + 0x59c) + 0xd4))(0);

      (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();

      (**(code **)(**(int **)(param_1 + 0x62c) + 0xd4))(0);

      (**(code **)(**(int **)(param_1 + 0x62c) + 0x34c))();

      return 1;

    }

    break;

  case 3:

    if (param_2 == 8) {

      FUN_0086b370();

      return 1;

    }

    break;

  case 5:

    if (param_2 == 8) {

      FUN_007fca10();

      FUN_007fef20(0x24,1,0);

      return 1;

    }

    break;

  case 6:

    if (param_2 == 8) {

      return 1;

    }

    break;

  case 7:

    if (param_2 == 8) {

      FUN_007fca10();

      FUN_007fef20(0x25,1,0);

      return 1;

    }

    break;

  case 8:

    if (param_2 == 8) {

      if (*(int **)(param_1 + 0x5b4) != (int *)0x0) {

        cVar1 = (**(code **)(**(int **)(param_1 + 0x5b4) + 0x478))();

        if (cVar1 == '\0') {

          uVar7 = (**(code **)(**(int **)(param_1 + 0x5b4) + 0x47c))();

          *(uint8_t *)(param_1 + 0x529) = uVar7;

        }

        else {

          cVar1 = (**(code **)(**(int **)(param_1 + 0x5b4) + 0x47c))();

          *(bool *)(param_1 + 0x529) = cVar1 == '\0';

        }

        (**(code **)(**(int **)(param_1 + 0x5b4) + 0x484))(*(uint8_t *)(param_1 + 0x529),0);

      }

      return 1;

    }

    break;

  case 9:

    if (param_2 == 8) {

      if (*(int **)(param_1 + 0x5b8) != (int *)0x0) {

        cVar1 = (**(code **)(**(int **)(param_1 + 0x5b8) + 0x478))();

        if (cVar1 == '\0') {

          uVar7 = (**(code **)(**(int **)(param_1 + 0x5b8) + 0x47c))();

        }

        else {

          cVar1 = (**(code **)(**(int **)(param_1 + 0x5b8) + 0x47c))();

          uVar7 = cVar1 == '\0';

        }

        *(uint8_t *)(param_1 + 0x529) = uVar7;

        (**(code **)(**(int **)(param_1 + 0x5b8) + 0x488))(0,*(uint8_t *)(param_1 + 0x529));

      }

      return 1;

    }

    break;

  case 10:

    if (param_2 == 8) {

      FUN_0092fdd0();

      return 1;

    }

    break;

  case 0xb:

    if (param_2 == 0x1a) {

      FUN_007fcc10();

      return 1;

    }

    break;

  case 0xc:

    if ((param_2 == 7) && (*(int **)(param_1 + 0x5b4) != (int *)0x0)) {

      uVar8 = (**(code **)(**(int **)(param_1 + 0x5b4) + 0x44c))();

      FUN_0086a900(uVar8);

      return 1;

    }

    break;

  case 0xd:

  case 0xe:

  case 0xf:

  case 0x10:

  case 0x11:

    if (param_2 == 5) {

      iStack_14 = *(int *)(param_1 + -0x26bc8 + param_3 * 4);

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

      if (*(char *)(param_1 + -0x96cd + param_3) != '\0') {

        iVar12 = iStack_14;

        FUN_004ce940(iStack_14);

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00508e20(iVar12);

        if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

          iStack_14 = puVar6[0x21];

        }

      }

      piVar2 = (int *)CVOGReaction_GiveItemByCbid(iStack_14);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 8))(iStack_14,DAT_00d1b644,0);

        if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00516720(puVar6 + 1);

          uVar4 = puVar6[0x22];

          uVar11 = 0;

          uVar10 = 0x80000000;

          uVar9 = 0;

          piVar5 = piVar2;

          FUN_004ce940(piVar2,0,0x80000000,0,uVar4);

          FUN_00509c70(piVar5,uVar9,uVar10,uVar11,uVar4);

          piVar5 = puVar6 + 0x24;

          iVar12 = 5;

          do {

            if (*piVar5 != -1) {

              (**(code **)(*piVar2 + 0x78))((short)*piVar5);

            }

            piVar5 = piVar5 + 1;

            iVar12 = iVar12 + -1;

          } while (iVar12 != 0);

          piVar5 = puVar6 + 0x29;

          iVar12 = 5;

          do {

            if (*piVar5 != -1) {

              (**(code **)(*piVar2 + 0x54))((short)*piVar5);

            }

            piVar5 = piVar5 + 1;

            iVar12 = iVar12 + -1;

          } while (iVar12 != 0);

          (**(code **)(*piVar2 + 100))();

          (**(code **)(*piVar2 + 0x9c))(*puVar6);

          param_3 = iStack_4;

        }

        puVar6 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(**(int **)(param_1 + -0x26b58 + param_3 * 4) + 0x140))

                           (&stack0xffffffe4,1);

        puVar3 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(**(int **)(param_1 + -0x26b58 + param_3 * 4) + 0x120))

                           (&stack0xffffffe4,1,1);

        FUN_007fd420(*puVar3,puVar3[1],*puVar6,puVar6[1]);

        if (DAT_00d1d8dc != (int *)0x0) {

          DAT_00d1d8dc[0x146] = 0;

        }

        (**(code **)*piVar2)(1);

      }

    }

    else if (param_2 == 6) {

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      if (DAT_00d1d8dc != (int *)0x0) {

        (**(code **)(*DAT_00d1d8dc + 4))(0);

      }

    }

  }

  uVar4 = FUN_0087b500(param_2,param_3);

  return uVar4;

}
