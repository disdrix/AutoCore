// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×32, return×2.
//  - Notable callees: FUN_00519d20×2, FUN_00845360×2, FUN_00845be0×2, UI_BuildItemTooltipStats×2, FUN_00514390, FUN_00833120, FUN_00833680, FUN_00833d50.
//  - Strings: "Loading Vehicles...".
//  - Return sites: 2.

// =============================================================================
// Drive_Loading_Vehicles
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d980
// Address:   0x0088d980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Loading Vehicles..."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Drive_Loading_Vehicles(int *param_1,int *param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  int iStack_c;

  uint32_t /* width from decompiler */ auStack_8 [2];

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    piVar1 = (int *)param_1[0x169];

    param_1[0x169] = (int)param_2;

    if ((param_2 == (int *)0x0) || (iVar3 = (**(code **)(*param_2 + 0x1d4))(), iVar3 == 0)) {

      if (param_1[0x173] != 0) {

        FUN_00833d50();

      }

      if ((int *)param_1[0x173] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x173] + 0x40))(0,0);

      }

      if ((int *)param_1[0x170] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x170] + 0x1d8))(0,1,1);

      }

      if ((int *)param_1[0x172] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x172] + 0x1d8))("Loading Vehicles...",1,1);

      }

      if ((int *)param_1[0x17a] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x17a] + 4))(0);

      }

      if ((int *)param_1[0x175] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x175] + 0x15c))(0,&DAT_00afdef0);

        (**(code **)(*(int *)param_1[0x175] + 0xcc))(0);

      }

      if ((int *)param_1[0x177] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x177] + 0x15c))(0,&DAT_00afdef0);

        (**(code **)(*(int *)param_1[0x177] + 0xcc))(0);

      }

      if ((int *)param_1[0x174] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x174] + 4))(0);

      }

      if ((int *)param_1[0x176] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x176] + 4))(0);

      }

      if ((int *)param_1[0x171] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x171] + 4))(0);

      }

    }

    else if (piVar1 != param_2) {

      iVar3 = (**(code **)(*param_2 + 0x1d4))();

      if (param_1[0x173] != 0) {

        FUN_00833e30(iVar3);

        FUN_00833120();

        FUN_00833680();

      }

      if ((int *)param_1[0x170] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x170] + 0x268))();

        (**(code **)(*(int *)param_1[0x170] + 0x1b0))(7);

        iVar4 = UI_BuildItemTooltipStats(param_2,1,0);

        if (iVar4 != 0) {

          (**(code **)(*(int *)param_1[0x170] + 0x250))(&DAT_00a15104);

        }

        iVar4 = FUN_00845be0();

        if (iVar4 != 0) {

          (**(code **)(*(int *)param_1[0x170] + 0x250))(&DAT_00a15104);

        }

        FUN_00845360(param_1[0x170],1);

        piVar1 = (int *)param_1[0x170];

        auStack_8[0] = (**(code **)(*piVar1 + 0x140))(&stack0xffffffec,1);

        iVar4 = (**(code **)(*piVar1 + 0x204))(&stack0xffffffec);

        if (*(int *)(iStack_c + 4) < *(int *)(iVar4 + 4)) {

          (**(code **)(*(int *)param_1[0x170] + 0x268))();

          (**(code **)(*(int *)param_1[0x170] + 0x1b0))(8);

          iVar4 = UI_BuildItemTooltipStats(param_2,1,0);

          if (iVar4 != 0) {

            (**(code **)(*(int *)param_1[0x170] + 0x250))(&DAT_00a15104);

          }

          iVar4 = FUN_00845be0();

          if (iVar4 != 0) {

            (**(code **)(*(int *)param_1[0x170] + 0x250))(&DAT_00a15104);

          }

          FUN_00845360(param_1[0x170],1);

        }

        (**(code **)(*(int *)param_1[0x170] + 0x1f0))();

      }

      (**(code **)(*param_1 + 0x458))();

      if ((int *)param_1[0x172] != (int *)0x0) {

        iVar4 = *(int *)param_1[0x172];

        uVar5 = (**(code **)(*param_2 + 0x15c))(1,1);

        (**(code **)(iVar4 + 0x1d8))(uVar5);

        cVar2 = FUN_00514390(DAT_00d1b6d8,1);

        if (cVar2 == '\0') {

          puVar6 = (uint32_t /* width from decompiler */ *)&stack0xffffffe4;

        }

        else {

          auStack_8[0] = 0xffffffff;

          puVar6 = auStack_8;

        }

        (**(code **)(*(int *)param_1[0x172] + 0x15c))(1,puVar6);

      }

      if ((int *)param_1[0x17a] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x17a] + 4))(1);

      }

      if ((int *)param_1[0x175] != (int *)0x0) {

        iVar4 = *(int *)param_1[0x175];

        uVar7 = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x1a8));

        (**(code **)(iVar4 + 0x160))(0,uVar7 | 0xff000000);

        (**(code **)(*(int *)param_1[0x175] + 0xcc))(1);

      }

      if ((int *)param_1[0x177] != (int *)0x0) {

        iVar4 = *(int *)param_1[0x177];

        uVar7 = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x1ac));

        (**(code **)(iVar4 + 0x160))(0,uVar7 | 0xff000000);

        (**(code **)(*(int *)param_1[0x177] + 0xcc))(1);

      }

      if ((int *)param_1[0x174] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x174] + 4))(1);

      }

      if ((int *)param_1[0x176] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x176] + 4))(1);

      }

      (**(code **)(*param_1 + 0x46c))();

    }

    if ((int *)param_1[0x173] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x173] + 0x34c))();

    }

    if ((int *)param_1[0x170] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x170] + 0x34c))();

    }

    if ((int *)param_1[0x172] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x172] + 0x34c))();

    }

    if ((int *)param_1[0x175] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x175] + 0x34c))();

    }

    if ((int *)param_1[0x177] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x177] + 0x34c))();

    }

    (**(code **)(*param_1 + 0x45c))();

    return;

  }

  return;

}
