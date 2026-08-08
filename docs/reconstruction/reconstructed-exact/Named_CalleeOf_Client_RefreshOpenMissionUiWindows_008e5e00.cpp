// =============================================================================
// RETIRED SCAFFOLD (R10-015 2026-08-05)
// Prefer: Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp
// Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5e00
// Callee of Client_RefreshOpenMissionUiWindows
// Address:   0x008e5e00  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (was: unknown scaffold)
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      R10-015 accept-with-gaps -- do not use this scaffold name.
// =============================================================================

// PURPOSE (auto): Called from Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~180 non-empty decompiler lines.
//  - Control keywords: if×16, while×3, do×1, return×1.
//  - Notable callees: FUN_007a69d0×5, FUN_007a6de0×5, FUN_004022a0×4, FUN_008e4430×3, DeleteCriticalSection×2, FUN_0040c700×2, FUN_0040db00×2, FUN_0040dc40×2.
//  - Strings: "%s %s".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RefreshOpenMissionUiWindows
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

void Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00(void)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  longlong lVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  uint uVar8;

  int unaff_EDI;

  longlong lVar9;

  uint64_t uVar10;

  uint32_t /* width from decompiler */ uVar11;

  undefined *puVar12;

  uint uStack_464;

  int *piStack_460;

  int iStack_45c;

  int iStack_458;

  uint64_t uStack_448;

  int iStack_440;

  uint32_t /* width from decompiler */ uStack_43c;

  undefined **ppuStack_438;

  _RTL_CRITICAL_SECTION _Stack_434;

  char acStack_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b7402;

  local_c = ExceptionList;

  if (*(int *)(unaff_EDI + 0x754) != 0) {

    ExceptionList = &local_c;

    iStack_440 = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x490))();

    uStack_43c = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x49c))();

    uStack_448 = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x44c))();

    if ((uStack_448 == -1) && (*(int *)(unaff_EDI + 0x7cc) != 0)) {

      uStack_448 = *(longlong *)(*(int *)(unaff_EDI + 0x7cc) + 0x160);

    }

    (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x458))();

    lVar4 = uStack_448;

    if (DAT_00d1b6d8 != 0) {

      if ((*(int *)(DAT_00d1b6d8 + 0x250) != 0) &&

         (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0)) {

        uStack_464 = 0;

        FUN_0040db00();

        uStack_4 = 0;

        iVar5 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0);

        iStack_45c = iVar5 + 0x2c;

        piStack_460 = (int *)0x0;

        if (*(int *)(iVar5 + 0x50) != 0) {

          FUN_004294f0();

          iVar5 = FUN_004022a0(&uStack_464,&piStack_460);

          piVar7 = piStack_460;

          while (piStack_460 = piVar7, iVar5 == 0) {

            if ((piVar7 != (int *)0x0) && (((uint)piVar7[0x5f] >> 0x13 & 1) != 0)) {

              iVar5 = **(int **)(unaff_EDI + 0x754);

              uVar11 = 0xffffffff;

              uVar6 = (**(code **)(*piVar7 + 0x15c))(0xffffffff,piVar7[0x58],piVar7[0x59],1);

              FUN_007a69d0(uVar6);

              uVar6 = FUN_007a6de0(uVar6,uVar11);

              (**(code **)(iVar5 + 0x444))(uVar6);

              iStack_45c = piVar7[0x59];

              iVar5 = **(int **)(unaff_EDI + 0x754);

              iVar1 = piVar7[0x58];

              uVar6 = FUN_008e4430(&uStack_464);

              (**(code **)(iVar5 + 0x464))(iVar1,iStack_45c,1,uVar6);

            }

            iVar5 = FUN_004022a0(&uStack_464,&piStack_460);

            piVar7 = piStack_460;

          }

          FUN_0040c700();

        }

        uStack_4 = 0xffffffff;

        ppuStack_438 = &PTR_FUN_00a34140;

        FUN_0040dc40();

        DeleteCriticalSection(&_Stack_434);

      }

      lVar4 = uStack_448;

      if (DAT_00d1b6d8 != 0) {

        if ((*(int *)(DAT_00d1b6d8 + 0xcbc) != 0) && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) {

          uStack_464 = 0;

          FUN_0040db00();

          uStack_4 = 1;

          iStack_458 = *(int *)(DAT_00d1b6d8 + 0xcbc) + 0x2c;

          piStack_460 = (int *)0x0;

          if (*(int *)(*(int *)(DAT_00d1b6d8 + 0xcbc) + 0x50) != 0) {

            FUN_004294f0();

            iVar5 = FUN_004022a0(&uStack_464,&piStack_460);

            piVar7 = piStack_460;

            while (piStack_460 = piVar7, iVar5 == 0) {

              if ((piVar7 != (int *)0x0) && (((uint)piVar7[0x5f] >> 0x13 & 1) != 0)) {

                uVar11 = 0xffffffff;

                uVar6 = (**(code **)(*piVar7 + 0x15c))(0xffffffff);

                FUN_007a69d0(uVar6);

                uVar6 = FUN_007a6de0(uVar6,uVar11);

                uVar11 = 0xffffffff;

                puVar12 = &DAT_00a3af64;

                FUN_007a69d0(&DAT_00a3af64,0xffffffff,uVar6);

                uVar6 = FUN_007a6de0(puVar12,uVar11);

                sprintf(acStack_40c,"%s %s",uVar6);

                (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x444))

                          (acStack_40c,piVar7[0x58],piVar7[0x59],1);

                iStack_45c = piVar7[0x59];

                iVar5 = piVar7[0x58];

                iVar1 = **(int **)(unaff_EDI + 0x754);

                uVar6 = FUN_008e4430(&uStack_464);

                (**(code **)(iVar1 + 0x464))(iVar5,iStack_45c,1,uVar6);

              }

              iVar5 = FUN_004022a0(&uStack_464,&piStack_460);

              piVar7 = piStack_460;

            }

            FUN_0040c700();

          }

          uStack_4 = 0xffffffff;

          ppuStack_438 = &PTR_FUN_00a34140;

          FUN_0040dc40();

          DeleteCriticalSection(&_Stack_434);

        }

        lVar4 = uStack_448;

        if (DAT_00d1b6d8 != 0) {

          iVar5 = FUN_00522000();

          uStack_464 = 0;

          iStack_458 = iVar5;

          lVar4 = uStack_448;

          if (0 < iVar5) {

            do {

              uVar8 = uStack_464;

              uVar2 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + (uStack_464 & 0xff) * 8);

              uVar3 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + (uStack_464 & 0xff) * 8);

              lVar4 = uStack_448;

              if ((uVar2 & uVar3) != 0xffffffff) {

                piVar7 = (int *)CVOGReaction_ResolveObjectTarget(1,uVar2,uVar3);

                lVar4 = uStack_448;

                if (piVar7 != (int *)0x0) {

                  uVar11 = 0xffffffff;

                  uVar6 = (**(code **)(*piVar7 + 0x15c))(0xffffffff);

                  FUN_007a69d0(uVar6);

                  uVar6 = FUN_007a6de0(uVar6,uVar11);

                  uVar11 = 0xffffffff;

                  puVar12 = &DAT_00a3af60;

                  FUN_007a69d0(&DAT_00a3af60,0xffffffff,uVar6);

                  uVar6 = FUN_007a6de0(puVar12,uVar11);

                  sprintf(acStack_40c,"%s %s",uVar6);

                  (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x444))

                            (acStack_40c,piVar7[0x58],piVar7[0x59],1);

                  iStack_45c = piVar7[0x59];

                  iVar5 = **(int **)(unaff_EDI + 0x754);

                  iVar1 = piVar7[0x58];

                  uVar6 = FUN_008e4430(&uStack_464);

                  (**(code **)(iVar5 + 0x464))(iVar1,iStack_45c,1,uVar6);

                  uVar8 = uStack_464;

                  iVar5 = iStack_458;

                  lVar4 = uStack_448;

                }

              }

              uStack_464 = uVar8 + 1;

              uStack_448 = lVar4;

            } while ((int)uStack_464 < iVar5);

          }

        }

      }

    }

    uStack_448 = lVar4;

    (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x448))(lVar4);

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x754) + 0x568) = 0;

    (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x498))(uStack_448._4_4_);

    lVar9 = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x44c))();

    if (lVar9 != lVar4) {

      uVar10 = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x44c))();

      FUN_008e5ce0(unaff_EDI,uVar10);

    }

    iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x754) + 0x490))();

    if (iStack_440 != iVar5) {

      FUN_007fbd30();

    }

  }

  ExceptionList = local_c;

  return;

}
