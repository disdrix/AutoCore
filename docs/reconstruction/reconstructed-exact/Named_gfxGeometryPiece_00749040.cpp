// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×14, return×8, for×4.
//  - Notable callees: vog_LogMessage×4, FUN_006a5dac×3, FUN_006b7a5a×3, FUN_0076cec0×3, FUN_00414a50×2, FUN_0044ba80×2, D3DXCreateMesh, FUN_00440110.
//  - Strings: "%s - %s\r\n%s"; "Optimization Failed.".
//  - Return sites: 8.

// =============================================================================
// Named_gfxGeometryPiece_00749040
// -----------------------------------------------------------------------------
// Stable ID: aa_00749040
// Address:   0x00749040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxGeometryPiece"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Named_gfxGeometryPiece_00749040(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *unaff_EBP;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  int *piVar7;

  int *piVar8;

  int *piStack_4c;

  int *piStack_48;

  int *piStack_44;

  int *piStack_2c;

  int *piStack_28;

  int **ppiStack_24;

  int *local_10;

  int local_c [2];

  int local_4;

  

  if (*(int *)(param_1 + 0x1c) != 0) {

    ppiStack_24 = (int **)0xaa1588;

    piStack_28 = (int *)0x749063;

    vog_LogMessage();

    return 0xffffffff;

  }

  local_10 = (int *)0x0;

  piStack_28 = (int *)*DAT_00d1f044;

  local_4 = param_1 + 0x10;

  piStack_2c = *(int **)(*(int *)(param_1 + 0x14) + 0x28);

  ppiStack_24 = &local_10;

  piStack_28 = (int *)D3DXCreateMesh();

  if ((int)piStack_28 < 0) {

    ppiStack_24 = (int **)0xaa1438;

    piStack_2c = (int *)0x7490bf;

    piStack_2c = (int *)FUN_006b7a5a();

    FUN_006a5dac();

    FUN_0076cec0();

    piStack_44 = (int *)0x3;

    piStack_48 = (int *)0x3ca;

    piStack_4c = (int *)0xaa1588;

    vog_LogMessage();

  }

  else {

    iVar3 = *(int *)(param_1 + 0x14);

    if (*(int *)(iVar3 + 0x10) != 0) {

      piStack_28 = *(int **)(iVar3 + 0x18);

      ppiStack_24 = (int **)0x4;

      piStack_2c = *(int **)(iVar3 + 0x14);

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_00746520();

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        ppiStack_24 = (int **)local_c;

        piStack_28 = (int *)0x0;

        piStack_2c = local_10;

        (**(code **)(*local_10 + 0x3c))();

        if (unaff_EBP == (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00414a50();

        }

        else {

          if ((*(int *)(param_1 + 0x14) == 0) ||

             (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0x10), iVar3 == 0)) {

            iVar3 = 0;

          }

          else {

            iVar3 = *(int *)(iVar3 + 8);

          }

          if (*(int *)(param_1 + 0x14) == 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x18);

          }

          for (uVar6 = (uint)(iVar5 * iVar3) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *unaff_EBP = *puVar1;

            puVar1 = puVar1 + 1;

            unaff_EBP = unaff_EBP + 1;

          }

          for (uVar6 = iVar5 * iVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

            *(uint8_t *)unaff_EBP = *(uint8_t *)puVar1;

            puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

            unaff_EBP = (uint32_t /* width from decompiler */ *)((int)unaff_EBP + 1);

          }

          FUN_00414a50();

          (**(code **)(*unaff_ESI + 0x40))();

          if ((*(int *)(*(int *)(param_1 + 0xc) + 0x10) != 0) &&

             (puVar1 = (uint32_t /* width from decompiler */ *)FUN_00743be0(), puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

            (**(code **)(*unaff_ESI + 0x44))();

            if (unaff_EDI == (uint32_t /* width from decompiler */ *)0x0) {

              FUN_0044ba80();

            }

            else {

              if (*(int *)(param_1 + 0xc) == 0) {

                iVar3 = 0;

              }

              else {

                iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x1c);

              }

              for (uVar6 = (uint)(iVar3 * 2) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

                *unaff_EDI = *puVar1;

                puVar1 = puVar1 + 1;

                unaff_EDI = unaff_EDI + 1;

              }

              for (uVar6 = iVar3 * 2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                *(uint8_t *)unaff_EDI = *(uint8_t *)puVar1;

                puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

                unaff_EDI = (uint32_t /* width from decompiler */ *)((int)unaff_EDI + 1);

              }

              FUN_0044ba80();

              (**(code **)(*piStack_28 + 0x48))();

              piStack_44 = (int *)0x749233;

              piVar2 = operator_new__(*(int *)(param_1 + 0xa8) * 0xc);

              piStack_44 = (int *)0x0;

              piStack_48 = piStack_2c;

              piStack_4c = (int *)0x749245;

              piVar7 = piVar2;

              iVar3 = (**(code **)(*piStack_2c + 0x50))();

              if (iVar3 < 0) {

                piStack_4c = (int *)0xaa140c;

                uVar4 = FUN_006b7a5a(iVar3);

                uVar4 = FUN_006a5dac(iVar3,uVar4);

                uVar4 = FUN_0076cec0(&piStack_2c,"%s - %s\r\n%s",uVar4);

                vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp"

                               ,0x3f7,3,uVar4);

                operator_delete__(piVar2);

                (**(code **)(*piVar7 + 8))(piVar7);

                return 0xffffffff;

              }

              piStack_4c = (int *)0x0;

              piVar8 = (int *)0x0;

              piVar7 = piVar2;

              iVar3 = (**(code **)(*unaff_ESI + 0x6c))(unaff_ESI,ppiStack_24,piVar2,0);

              operator_delete__(piVar2);

              if (iVar3 < 0) {

                uVar4 = FUN_006b7a5a(iVar3,"Optimization Failed.");

                uVar4 = FUN_006a5dac(iVar3,uVar4);

                uVar4 = FUN_0076cec0(&piStack_44,"%s - %s\r\n%s",uVar4);

                vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp"

                               ,0x401,3,uVar4);

                (**(code **)(*piVar7 + 8))(piVar7);

                return 0xffffffff;

              }

              (**(code **)(*piVar8 + 0x3c))(piVar8,0,&piStack_4c);

              if (ppiStack_24 != (int **)0x0) {

                *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

                piStack_44 = (int *)ppiStack_24;

                piStack_48 = (int *)0x749344;

                FUN_00440110();

                piStack_44 = piStack_28;

                piStack_48 = (int *)0x749355;

                (**(code **)(*piStack_28 + 0x44))();

                if (&stack0x00000000 == (uint8_t *)0x14) {

                  return 0xffffffff;

                }

                piStack_48 = (int *)0x0;

                piStack_4c = piStack_2c;

                FUN_0044bad0();

                piStack_48 = (int *)0x0;

                piStack_4c = (int *)0x749378;

                (**(code **)(_DAT_00000000 + 8))();

                return 0;

              }

            }

            (**(code **)(*piStack_28 + 8))();

            return 0xffffffff;

          }

        }

        (**(code **)(*unaff_ESI + 8))();

        return 0xffffffff;

      }

    }

  }

  return 0xffffffff;

}
