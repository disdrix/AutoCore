// =============================================================================
// FUN_007907b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007907b0
// Address:   0x007907b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007907b0 @ 0x007907b0
// Stable ID: aa_007907b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×24, return×4, for×1.
//  - Notable callees: FUN_007907b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_007907b0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int unaff_EBX;

  int iVar6;

  int unaff_EBP;

  int iVar7;

  int unaff_ESI;

  bool bVar8;

  int iStack_38;

  int iStack_34;

  int *piStack_30;

  uint32_t /* width from decompiler */ *puStack_2c;

  uint32_t /* width from decompiler */ *puStack_28;

  int iStack_24;

  int iStack_10;

  int iStack_c;

  uint32_t /* width from decompiler */ auStack_8 [2];

  

  iStack_24 = 0x7907c1;

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  iVar4 = DAT_00d17944;

  if ((cVar2 != '\0') && (*(char *)((int)param_1 + 0x493) != '\0')) {

    iVar7 = (int)(short)param_3;

    iVar6 = (int)(short)((uint)param_3 >> 0x10);

    bVar8 = DAT_00d17944 != 0;

    param_1[299] = 0;

    if (bVar8) {

      if (iVar7 < 0) {

        iVar7 = 0;

      }

      else {

        iVar1 = *(int *)(*(int *)(iVar4 + 0x2c) + 0x80);

        if (iVar1 <= iVar7) {

          iVar7 = iVar1 + -1;

        }

      }

      if (iVar6 < 0) {

        iVar6 = 0;

      }

      else {

        iVar4 = *(int *)(*(int *)(iVar4 + 0x2c) + 0x84);

        if (iVar4 <= iVar6) {

          iVar6 = iVar4 + -1;

        }

      }

    }

    iStack_10 = iVar7 - param_1[0x122];

    param_1[0x122] = iVar7;

    iStack_c = iVar6 - param_1[0x123];

    param_1[0x123] = iVar6;

    if ((int *)param_1[0x12e] != (int *)0x0) {

      iStack_24 = 0x79085d;

      cVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x2f0))();

      if (cVar2 != '\0') {

        iStack_24 = 0x79086f;

        cVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x2f4))();

        if (cVar2 != '\0') {

          iStack_24 = 0x79087d;

          cVar2 = (**(code **)(*param_1 + 0x3dc))();

          if (cVar2 == '\0') {

            iStack_24 = 0x79088b;

            cVar2 = (**(code **)(*param_1 + 1000))();

            if (cVar2 == '\0') {

              puStack_2c = (uint32_t /* width from decompiler */ *)param_1[0x12e];

              piStack_30 = (int *)0x7908a2;

              puStack_28 = (uint32_t /* width from decompiler */ *)iVar7;

              iStack_24 = iVar6;

              (**(code **)(*param_1 + 0x424))();

            }

          }

        }

      }

    }

    if ((int *)param_1[0x12e] != (int *)0x0) {

      iStack_24 = 0x7908b8;

      cVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x2e4))();

      if (cVar2 != '\0') {

        iStack_24 = 0x7908ce;

        cVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x2f4))();

        if (cVar2 != '\0') {

          for (piVar3 = *(int **)(param_1[0x12e] + 0x2b0); piVar3 != (int *)0x0;

              piVar3 = (int *)piVar3[0xac]) {

            iStack_24 = 0x7908f0;

            cVar2 = (**(code **)(*piVar3 + 0x2e8))();

            if ((cVar2 != '\0') && ((iStack_10 != 0 || (iStack_c != 0)))) {

              iStack_24 = 0;

              puStack_28 = (uint32_t /* width from decompiler */ *)0x1;

              puStack_2c = auStack_8;

              DAT_00d17968 = 1;

              piStack_30 = (int *)0x790928;

              (**(code **)(*piVar3 + 0x120))();

              iStack_10 = iStack_10 + unaff_EBP;

              unaff_EBX = unaff_EBX + unaff_ESI;

              piStack_30 = (int *)&stack0xffffffec;

              iStack_34 = 0x790947;

              (**(code **)(*piVar3 + 0x11c))();

              iStack_34 = 0x790951;

              (**(code **)(*piVar3 + 0x94))();

              iStack_34 = 0x79095b;

              (**(code **)(*piVar3 + 0x34c))();

              iStack_34 = 0x790965;

              (**(code **)(*param_1 + 0x318))();

              break;

            }

          }

        }

      }

    }

    iVar4 = param_1[0x12d];

    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x1c) != 0)) {

      iStack_24 = 1;

      puStack_28 = auStack_8;

      puStack_2c = (uint32_t /* width from decompiler */ *)0x79098f;

      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x140))();

      puStack_2c = (uint32_t /* width from decompiler */ *)0x1;

      piStack_30 = &iStack_10;

      iStack_34 = 0x7909b6;

      (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x140))();

      iStack_34 = 1;

      iStack_38 = 1;

      piVar3 = (int *)(**(code **)(*param_1 + 0x120))(&stack0xffffffe8);

      puStack_2c = (uint32_t /* width from decompiler */ *)((int)puStack_2c - *piVar3);

      iVar4 = (**(code **)(*param_1 + 0x120))(&iStack_24,1,1);

      iStack_34 = iStack_34 - *(int *)(iVar4 + 4);

      (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x11c))(&iStack_38);

      (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x34c))();

    }

    if ((int *)param_1[0x12e] != (int *)0x0) {

      iStack_24 = param_3;

      puStack_28 = (uint32_t /* width from decompiler */ *)param_2;

      puStack_2c = (uint32_t /* width from decompiler */ *)0x790a3c;

      (**(code **)(*(int *)param_1[0x12e] + 0x368))();

    }

    iStack_24 = 1;

    puStack_28 = (uint32_t /* width from decompiler */ *)0x1;

    iStack_34 = 0x790a4c;

    piStack_30 = (int *)iVar7;

    puStack_2c = (uint32_t /* width from decompiler */ *)iVar6;

    piVar5 = (int *)(**(code **)(*param_1 + 0x3d0))();

    piVar3 = (int *)param_1[0x12e];

    if (piVar5 != piVar3) {

      if (piVar3 != (int *)0x0) {

        iStack_34 = auStack_8[0];

        iStack_38 = iStack_c;

        (**(code **)(*piVar3 + 0x370))();

        (**(code **)(*param_1 + 0x430))(param_1[0x12e],iVar7,iVar6);

      }

      iStack_34 = 0x790a8f;

      (**(code **)(*param_1 + 0x318))();

      if (piVar5 != (int *)0x0) {

        iStack_34 = 0x790a9d;

        cVar2 = (**(code **)(*piVar5 + 0x304))();

        if (cVar2 != '\0') {

          param_1[0x12e] = 0;

          return 1;

        }

      }

      param_1[0x12e] = (int)piVar5;

      if (piVar5 != (int *)0x0) {

        iStack_34 = auStack_8[0];

        iStack_38 = iStack_c;

        (**(code **)(*piVar5 + 0x36c))();

        if ((int *)param_1[0x12e] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x12e] + 0x368))(unaff_EBX,iStack_10);

        }

        (**(code **)(*param_1 + 0x314))(iVar7,iVar6);

      }

      return 1;

    }

    if (piVar5 != (int *)0x0) {

      iStack_34 = auStack_8[0];

      iStack_38 = iStack_c;

      (**(code **)(*piVar5 + 0x368))();

      return 1;

    }

  }

  return 0;

}
