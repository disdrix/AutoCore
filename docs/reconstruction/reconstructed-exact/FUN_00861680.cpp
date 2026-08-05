// =============================================================================
// FUN_00861680
// -----------------------------------------------------------------------------
// Stable ID: aa_00861680
// Address:   0x00861680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00861680 @ 0x00861680
// Stable ID: aa_00861680
// Embedded strings (evidence for future rename):
//   - "Broken: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~212 non-empty decompiler lines.
//  - Control keywords: if×17, return×13, for×5, do×5, while×5, switch×1.
//  - Notable callees: __RTDynamicCast×3, Client_SendInventoryGrab_FromGrid×2, Client_UI_InventoryDropToGrid×2, FUN_007a6de0×2, FUN_00790730, FUN_00795b10, FUN_007a69d0, FUN_007fbbb0.
//  - Strings: "Broken: ".
//  - Return sites: 13.

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

uint8_t __thiscall FUN_00861680(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint8_t uVar2;

  char *pcVar3;

  char *pcVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint uVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  char *pcVar13;

  uint16_t *puVar14;

  uint32_t /* width from decompiler */ uVar15;

  int *local_418 [2];

  int iStack_410;

  uint8_t auStack_40c [4];

  char acStack_408 [2];

  uint32_t /* width from decompiler */ auStack_406 [256];

  

  if ((DAT_00d1b6d8 == 0) || (param_1[0x15b] == 0)) {

    return 0;

  }

  local_418[0] = param_1;

  switch(*(int *)(param_1[0x15b] + 4) + -1) {

  case 0:

  case 2:

  case 4:

    if (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0) {

      Client_UI_InventoryDropToGrid();

      (**(code **)(*param_1 + 0x33c))(0);

      return 1;

    }

    if (param_1[0x12e] == 0) {

      auStack_40c = (uint8_t  [4])DAT_00d1d904;

      if (DAT_00d1d900 == 3) {

        FUN_0093c3b0(param_1);

      }

    }

    else {

      piVar7 = (int *)__RTDynamicCast(param_1[0x12e],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                      &CWndInventoryItem::RTTI_Type_Descriptor,0);

      if (piVar7 != (int *)0x0) {

        if ((((DAT_00d1bdfa != '\0') && (DAT_00d1b978 != (int *)0x0)) &&

            (cVar1 = (**(code **)(*DAT_00d1b978 + 0x3d8))(), cVar1 != '\0')) &&

           (cVar1 = (**(code **)(*DAT_00d1b978 + 0xd0))(), cVar1 != '\0')) {

          if (DAT_00d1b978[0x68ae] != 0) {

            acStack_408[0] = '[';

            acStack_408[1] = '\0';

            puVar12 = auStack_406;

            for (iVar9 = 0xff; iVar9 != 0; iVar9 = iVar9 + -1) {

              *puVar12 = 0;

              puVar12 = puVar12 + 1;

            }

            *(uint16_t *)puVar12 = 0;

            local_418[0] = (int *)FUN_007a69d0();

            iVar9 = (**(code **)(*piVar7 + 0x3ac))();

            if ((*(uint *)(iVar9 + 0x17c) >> 0x13 & 1) != 0) {

              pcVar3 = (char *)FUN_007a6de0("Broken: ",0xffffffff);

              pcVar4 = pcVar3;

              do {

                cVar1 = *pcVar4;

                pcVar4 = pcVar4 + 1;

              } while (cVar1 != '\0');

              pcVar13 = auStack_40c + 3;

              do {

                pcVar11 = pcVar13 + 1;

                pcVar13 = pcVar13 + 1;

              } while (*pcVar11 != '\0');

              pcVar11 = pcVar3;

              for (uVar10 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar10 != 0; uVar10 = uVar10 - 1

                  ) {

                *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar11;

                pcVar11 = pcVar11 + 4;

                pcVar13 = pcVar13 + 4;

              }

              for (uVar10 = (int)pcVar4 - (int)pcVar3 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

                *pcVar13 = *pcVar11;

                pcVar11 = pcVar11 + 1;

                pcVar13 = pcVar13 + 1;

              }

            }

            piVar5 = (int *)(**(code **)(*piVar7 + 0x3ac))();

            uVar15 = 0xffffffff;

            uVar8 = (**(code **)(*piVar5 + 0x15c))(0xffffffff);

            pcVar3 = (char *)FUN_007a6de0(uVar8,uVar15);

            pcVar4 = pcVar3;

            do {

              cVar1 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            pcVar13 = auStack_40c + 3;

            do {

              pcVar11 = pcVar13 + 1;

              pcVar13 = pcVar13 + 1;

            } while (*pcVar11 != '\0');

            pcVar11 = pcVar3;

            for (uVar10 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar10 != 0; uVar10 = uVar10 - 1)

            {

              *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar11;

              pcVar11 = pcVar11 + 4;

              pcVar13 = pcVar13 + 4;

            }

            for (uVar10 = (int)pcVar4 - (int)pcVar3 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

              *pcVar13 = *pcVar11;

              pcVar11 = pcVar11 + 1;

              pcVar13 = pcVar13 + 1;

            }

            puVar14 = (uint16_t *)(auStack_40c + 3);

            do {

              pcVar4 = (char *)((int)puVar14 + 1);

              puVar14 = (uint16_t *)((int)puVar14 + 1);

            } while (*pcVar4 != '\0');

            iVar9 = *piVar7;

            *puVar14 = DAT_00a62c94;

            piVar5 = (int *)(**(code **)(iVar9 + 0x3ac))();

            iVar9 = (**(code **)(*piVar5 + 0x210))(0);

            if (iVar9 == 0) {

              uVar8 = 0xffffffff;

              uVar15 = 0xffffffff;

            }

            else {

              piVar5 = (int *)(**(code **)(*piVar7 + 0x3ac))();

              iVar6 = (**(code **)(*piVar5 + 0x210))(0);

              iVar9 = *(int *)(*(int *)(iVar6 + 4) + 4);

              uVar8 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x164 + iVar6);

              uVar15 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x168 + iVar6);

            }

            local_418[0] = (int *)0xffff00ff;

            iVar9 = (**(code **)(*piVar7 + 0x3ac))();

            FUN_00795b10(auStack_40c,1,*(uint32_t /* width from decompiler */ *)(iVar9 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar9 + 0x164)

                         ,uVar8,uVar15,local_418,0);

            if (DAT_00d1b978[0xac] != 0) {

              iVar9 = *(int *)DAT_00d1b978[0xac];

              uVar8 = (**(code **)(*DAT_00d1b978 + 0x88))();

              (**(code **)(iVar9 + 0x3c0))(uVar8);

            }

            iVar9 = *DAT_00d1b978;

            uVar8 = (**(code **)(*(int *)DAT_00d1b978[0x68ae] + 0x88))();

            (**(code **)(iVar9 + 0x3c0))(uVar8);

          }

          return 1;

        }

        piVar5 = (int *)(**(code **)(*piVar7 + 0x3ac))();

        iVar9 = (**(code **)(*piVar5 + 0x25c))();

        if ((1 < iVar9) &&

           ((DAT_00d1bdfa != '\0' || (cVar1 = (**(code **)(*DAT_00d1b890 + 0x3d8))(), cVar1 != '\0')

            ))) {

          (**(code **)(*piVar7 + 0x3ac))();

          FUN_007fecb0(piVar7,DAT_00d1d86c,DAT_00d1d870);

          (**(code **)(*local_418[0] + 0x33c))(0);

          return 1;

        }

        auStack_40c = (uint8_t  [4])DAT_00d1d904;

        if (DAT_00d1d900 == -1) {

          piVar7 = (int *)(**(code **)(*piVar7 + 0x3ac))();

          uVar8 = (**(code **)(*piVar7 + 0x25c))();

          uVar2 = Client_SendInventoryGrab_FromGrid(param_1,uVar8);

          (**(code **)(*local_418[0] + 0x33c))(0);

          return uVar2;

        }

        iStack_410 = DAT_00d1d900;

        if ((char)DAT_00d1d904 != '\0') {

          (**(code **)(*piVar7 + 0x3ac))();

          FUN_00941ac0(&DAT_00d1a660);

          return 1;

        }

        uVar8 = (**(code **)(*piVar7 + 0x3ac))();

        FUN_0093d110(uVar8);

        return 1;

      }

    }

    break;

  default:

    FUN_007fbbb0();

    uVar2 = FUN_00790730(param_2,param_3);

    return uVar2;

  case 3:

    if (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0) {

      Client_UI_InventoryDropToGrid();

      (**(code **)(*param_1 + 0x33c))(0);

      return 1;

    }

    if (param_1[0x12e] != 0) {

      __RTDynamicCast(param_1[0x12e],0,&CNDUIWindow::RTTI_Type_Descriptor,

                      &CWndInventoryItem::RTTI_Type_Descriptor,0);

      FUN_00861280();

    }

    (**(code **)(*param_1 + 0x33c))(0);

    return 1;

  case 5:

    break;

  case 6:

    if (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0) {

      FUN_00860d90();

      return 1;

    }

    if ((param_1[0x12e] != 0) &&

       (piVar7 = (int *)__RTDynamicCast(param_1[0x12e],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                        &CWndInventoryItem::RTTI_Type_Descriptor,0),

       piVar7 != (int *)0x0)) {

      piVar7 = (int *)(**(code **)(*piVar7 + 0x3ac))();

      uVar8 = (**(code **)(*piVar7 + 0x25c))();

      uVar2 = Client_SendInventoryGrab_FromGrid(param_1,uVar8);

      (**(code **)(*local_418[0] + 0x33c))(0);

      return uVar2;

    }

  }

  return 1;

}
