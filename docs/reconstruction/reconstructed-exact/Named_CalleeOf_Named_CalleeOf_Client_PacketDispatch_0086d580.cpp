// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0086d580
// -----------------------------------------------------------------------------
// Stable ID: aa_0086d580
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x0086d580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper. Evidence string: ".dds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - ".dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~184 non-empty decompiler lines.
//  - Control keywords: if×16, do×2, while×2, return×1.
//  - Notable callees: sprintf×3, CVOGReaction_GiveItemByCbid×2, FUN_004ce940×2, FUN_00508e20×2, strncat×2, strncpy×2, FUN_007a69d0, FUN_007a6de0.
//  - Strings: ".dds"; "%d %s\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

/* WARNING: Removing unreachable block (ram,0x0086d687) */



void __thiscall

Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0086d580(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4,char *param_5,int *param_6)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ in_EAX;

  int iVar3;

  int *piVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int *unaff_EDI;

  int iVar11;

  size_t sVar12;

  int *local_124;

  int iStack_118;

  int iStack_114;

  char acStack_110 [4];

  char acStack_10c [244];

  int *piStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ *puStack_10;

  int iStack_c;

  int iStack_8;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = in_EAX;

  iVar5 = *param_6;

  local_124 = (int *)((uint)local_124 & 0xffffff00);

  piVar2 = local_124;

  local_124 = param_6;

  if (iVar5 != -1) {

    if (*param_5 == '\0') {

      *(uint8_t *)(param_1 + 0x520) = 0;

    }

    else {

      *(uint8_t *)(param_1 + 0x520) = 1;

      FUN_004ce940();

      iVar3 = FUN_00508e20();

      if (iVar3 != 0) {

        iVar5 = *(int *)(iVar3 + 0x84);

      }

    }

    piVar4 = (int *)CVOGReaction_GiveItemByCbid(iVar5);

    if (piVar4 != (int *)0x0) {

      iVar5 = (**(code **)(*piVar4 + 8))();

      if (-1 < iVar5) {

        sVar12 = 0x80;

        pcVar6 = (char *)(**(code **)(*piVar4 + 0x1c4))();

        strncpy(acStack_10c,pcVar6,sVar12);

        strncat(acStack_10c,".dds",0x80);

        piVar1 = *(int **)(param_1 + 0x59c);

        iVar5 = *piVar1;

        uVar7 = (**(code **)(iVar5 + 0x2d8))();

        uVar7 = (**(code **)(*piVar1 + 0x2c8))(uVar7);

        (**(code **)(iVar5 + 0x50))(acStack_10c,uVar7);

        (**(code **)(**(int **)(param_1 + 0x5b0) + 0x1d8))(5,1,1);

        (**(code **)(**(int **)(param_1 + 0x5b0) + 0x34c))();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = *puStack_10;

        (**(code **)(**(int **)(param_1 + 0x5b0) + 4))(1);

        (**(code **)(**(int **)(param_1 + 0x588) + 4))(1);

        (**(code **)(**(int **)(param_1 + 0x59c) + 4))(1);

        if (*piStack_18 < 2) {

          (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))(0,1,1);

        }

        else {

          sprintf(&stack0xfffffec4,"%d",*piStack_18);

          (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))(&stack0xfffffec4,1,1);

        }

        (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();

        local_124 = param_3;

      }

      (**(code **)*piVar4)(1);

    }

  }

  *(uint8_t *)(param_1 + 0x520) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0xffffffff;

  (**(code **)(**(int **)(param_1 + 0x5b0) + 4))();

  (**(code **)(**(int **)(param_1 + 0x5b0) + 0x1d8))(0);

  (**(code **)(**(int **)(param_1 + 0x5b0) + 0x34c))();

  (**(code **)(**(int **)(param_1 + 0x588) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x59c) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))(0,1,1);

  (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();

  (**(code **)(**(int **)(param_1 + 0x580) + 4))();

  iStack_114 = (int)param_6 - (int)local_124;

  iStack_118 = 1;

  puVar9 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5a0);

  do {

    local_124 = local_124 + 1;

    iVar5 = *local_124;

    if (iVar5 != -1) {

      if (*(char *)(iStack_118 + param_4) == '\0') {

        *(uint8_t *)(param_1 + 0x521) = 0;

      }

      else {

        *(uint8_t *)(param_1 + 0x521) = 1;

        FUN_004ce940();

        iVar3 = FUN_00508e20();

        if (iVar3 != 0) {

          iVar5 = *(int *)(iVar3 + 0x84);

        }

      }

      piVar4 = (int *)CVOGReaction_GiveItemByCbid(iVar5);

      if (piVar4 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar4 + 8))();

        if (-1 < iVar3) {

          sVar12 = 0x80;

          pcVar6 = (char *)(**(code **)(*piVar4 + 0x1c4))();

          strncpy(acStack_110,pcVar6,sVar12);

          strncat(acStack_110,".dds",0x80);

          piVar4 = (int *)*puVar9;

          iVar3 = *piVar4;

          uVar7 = (**(code **)(iVar3 + 0x2d8))();

          iVar8 = (**(code **)(*piVar4 + 0x2c8))(uVar7);

          (**(code **)(iVar3 + 0x50))(acStack_110);

          if (piVar2 == (int *)0x0) {

            iVar3 = (**(code **)(*unaff_EDI + 0x15c))();

          }

          else {

            iVar3 = (int)piVar2 + 4;

          }

          iVar11 = 1;

          (**(code **)(*(int *)puVar9[5] + 0x1d8))(iVar3,1);

          (**(code **)(*(int *)puVar9[5] + 0x34c))();

          puVar9[-0x24] = *(uint32_t /* width from decompiler */ *)(iStack_14 + iVar8 * 4);

          (**(code **)(*(int *)puVar9[5] + 4))(1);

          (**(code **)(*(int *)puVar9[-5] + 4))(1);

          (**(code **)(*(int *)*puVar9 + 4))(1);

          if (*(int *)(iVar5 + iVar11) < 2) {

            (**(code **)(*(int *)*puVar9 + 0x1d8))(0,1,1);

          }

          else {

            sprintf(&stack0xfffffec0,"%d",*(int *)(iVar5 + iVar11));

            (**(code **)(*(int *)*puVar9 + 0x1d8))(&stack0xfffffec0,1,1);

          }

          (**(code **)(*(int *)*puVar9 + 0x34c))();

          unaff_EDI = (int *)((int)unaff_EDI + 1);

          puVar9 = puVar9 + 1;

          piVar4 = (int *)0x1;

        }

        (**(code **)*piVar4)(1);

      }

    }

    iVar5 = 1;

    iStack_118 = iStack_118 + 1;

  } while (iStack_118 < 5);

  puVar9 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b0);

  do {

    puVar10 = puVar9 + 1;

    *(uint8_t *)(param_1 + 0x520 + iVar5) = 0;

    puVar9[-0x28] = 0xffffffff;

    (**(code **)(*(int *)*puVar10 + 4))();

    (**(code **)(*(int *)*puVar10 + 0x1d8))(0,1);

    (**(code **)(*(int *)*puVar10 + 0x34c))();

    (**(code **)(*(int *)puVar9[-9] + 4))(0);

    (**(code **)(*(int *)puVar9[-4] + 4))(0);

    (**(code **)(*(int *)puVar9[-4] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)puVar9[-4] + 0x34c))();

    iVar5 = iVar5 + 1;

    puVar9 = puVar10;

  } while (iVar5 < 5);

  (**(code **)(**(int **)(param_1 + 0x584) + 4))();

  if (*(int *)(param_1 + 0x578) != 0) {

    FUN_007a69d0();

    (**(code **)(**(int **)(param_1 + 0x578) + 0x1d8))(0,1);

    if (puStack_10 != (uint32_t /* width from decompiler */ *)0x0) {

      uVar7 = FUN_007a6de0(&DAT_00a43258,0xffffffff);

      sprintf((char *)&iStack_114,"%d %s\n",puStack_10,uVar7);

      (**(code **)(**(int **)(param_1 + 0x578) + 0x250))(&iStack_114);

    }

    if ((iStack_c != 0 || iStack_8 != 0) && (DAT_00d1ad30 != 0)) {

      FUN_00977a30(DAT_00d1ad30,iStack_c,iStack_8);

      (**(code **)(**(int **)(param_1 + 0x578) + 0x250))(&DAT_00a15104);

    }

    (**(code **)(**(int **)(param_1 + 0x578) + 0xcc))(1);

    (**(code **)(**(int **)(param_1 + 0x578) + 0x34c))();

  }

  (**(code **)(**(int **)(param_1 + 0x574) + 4))();

  (**(code **)(**(int **)(param_1 + 0x57c) + 4))(1);

  return;

}
