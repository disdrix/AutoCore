// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×1.
//  - Notable callees: FUN_00631dc0×4, CARRY4×2, FUN_00631da0×2, FUN_00631f80×2, FUN_0063f610×2, received×2, up×2, FUN_005b3300.
//  - Strings: "VisualDebugger: [".
//  - Return sites: 1.

// =============================================================================
// Named_A_new_network_client_has_been_received_host_name_005d8b40
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8b40
// Address:   0x005d8b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "A new network client has been received (host name not availibe at present)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_A_new_network_client_has_been_received_host_name_005d8b40(int param_1)



{

  uint *puVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  uint64_t uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  char *pcVar17;

  uint32_t /* width from decompiler */ uVar18;

  

  if (*(char *)(param_1 + 0x2c) != '\0') {

    *(uint8_t *)(param_1 + 0x50) = 0;

    uVar12 = FUN_0063f610();

    iVar4 = (int)((ulonglong)uVar12 >> 0x20);

    uVar3 = (uint)uVar12;

    uVar9 = uVar3 - *(uint *)(param_1 + 0x30);

    puVar1 = (uint *)(param_1 + 0x38);

    uVar10 = *puVar1;

    *puVar1 = *puVar1 + uVar9;

    *(int *)(param_1 + 0x3c) =

         *(int *)(param_1 + 0x3c) +

         ((iVar4 - *(int *)(param_1 + 0x34)) - (uint)(uVar3 < *(uint *)(param_1 + 0x30))) +

         (uint)CARRY4(uVar10,uVar9);

    uVar9 = uVar3 - *(uint *)(param_1 + 0x40);

    puVar1 = (uint *)(param_1 + 0x48);

    uVar10 = *puVar1;

    *puVar1 = *puVar1 + uVar9;

    *(int *)(param_1 + 0x4c) =

         *(int *)(param_1 + 0x4c) +

         ((iVar4 - *(int *)(param_1 + 0x44)) - (uint)(uVar3 < *(uint *)(param_1 + 0x40))) +

         (uint)CARRY4(uVar10,uVar9);

    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

  }

  if (*(int *)(param_1 + 8) != 0) {

    iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x20))();

    if (iVar4 != 0) {

      if (0 < DAT_00d030ec) {

        pcVar17 = "VisualDebugger: [";

        (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

        FUN_00631dc0(pcVar17);

        uVar18 = 0x5d;

        pcVar17 = "A new network client has been received (host name not availibe at present)";

        (**(code **)(*DAT_00d030e0 + 4))

                  ("A new network client has been received (host name not availibe at present)",0x5d

                  );

        FUN_00631dc0(pcVar17);

        uVar18 = FUN_00631da0(uVar18);

        FUN_00631f80(uVar18);

      }

      iVar16 = 0x2c;

      iVar11 = iVar4 + 0x14;

      iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x2c,0x30);

      *(uint16_t *)(iVar5 + 4) = 0x2c;

      piVar6 = (int *)FUN_00642630();

      (**(code **)(*piVar6 + 0x38))(iVar11);

      iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x2c,0x30);

      *(uint16_t *)(iVar5 + 4) = 0x2c;

      FUN_00641040(iVar4,piVar6);

      FUN_00640bf0(iVar11);

      iVar14 = 0x30;

      iVar13 = 0x14;

      iVar5 = (**(code **)(*DAT_00b05060 + 0x10))();

      *(uint16_t *)(iVar5 + 4) = 0x14;

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00642830(iVar4);

      iVar4 = (**(code **)(*DAT_00b05060 + 0x10))(0x40,0x30);

      *(uint16_t *)(iVar4 + 4) = 0x40;

      FUN_0063fd00(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28));

      FUN_0063fc20(iVar11);

      iVar4 = (**(code **)(*DAT_00b05060 + 0x10))(0x1c,0x30);

      *(uint16_t *)(iVar4 + 4) = 0x1c;

      iVar4 = FUN_00641340(iVar16,puVar7,*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),iVar14);

      FUN_00641190(iVar13 + 8);

      *(short *)((int)puVar7 + 6) = *(short *)((int)puVar7 + 6) + -1;

      if (*(short *)((int)puVar7 + 6) == 0) {

        (**(code **)*puVar7)(1);

      }

      iVar15 = *(int *)(param_1 + 0x10);

      iVar5 = iVar15 + 1;

      uVar10 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

      if ((int)uVar10 < iVar5) {

        iVar8 = uVar10 * 2;

        if (iVar8 <= iVar5) {

          iVar8 = iVar5;

        }

        FUN_005b3300((int *)(param_1 + 0xc),iVar8,0x14);

      }

      *(int *)(param_1 + 0x10) = iVar15 + 1;

      piVar2 = (int *)(*(int *)(param_1 + 0xc) + iVar15 * 0x14);

      *piVar2 = iVar13;

      piVar2[1] = (int)piVar6;

      piVar2[2] = iVar16;

      piVar2[3] = iVar4;

      piVar2[4] = iVar14;

      FUN_006419a0(iVar11);

      (**(code **)(*piVar6 + 0x34))(0x41800000);

      FUN_00640e30();

      iVar4 = 0;

      if (0 < *(int *)(param_1 + 0x1c)) {

        do {

          FUN_00640f00(**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x18) + iVar4 * 4));

          iVar4 = iVar4 + 1;

        } while (iVar4 < *(int *)(param_1 + 0x1c));

      }

    }

  }

  iVar4 = *(int *)(param_1 + 0x10) + -1;

  if (-1 < iVar4) {

    iVar5 = iVar4 * 0x14;

    do {

      piVar6 = *(int **)(*(int *)(param_1 + 0xc) + iVar5);

      if (piVar6 != (int *)0x0) {

        pcVar17 = (char *)(**(code **)(*piVar6 + 4))(&stack0x00000004);

        if (*pcVar17 == '\0') {

          if (0 < DAT_00d030ec) {

            pcVar17 = "VisualDebugger: [";

            (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

            FUN_00631dc0(pcVar17);

            uVar18 = 0x5d;

            pcVar17 = "Client has died, cleaning up (host name not available at present)";

            (**(code **)(*DAT_00d030e0 + 4))

                      ("Client has died, cleaning up (host name not available at present)",0x5d);

            FUN_00631dc0(pcVar17);

            uVar18 = FUN_00631da0(uVar18);

            FUN_00631f80(uVar18);

          }

          FUN_005d8710(iVar4);

        }

      }

      iVar4 = iVar4 + -1;

      iVar5 = iVar5 + -0x14;

    } while (-1 < iVar4);

  }

  if (*(char *)(param_1 + 0x2c) != '\0') {

    *(uint8_t *)(param_1 + 0x50) = 1;

    uVar12 = FUN_0063f610();

    *(uint64_t *)(param_1 + 0x30) = uVar12;

    *(uint64_t *)(param_1 + 0x40) = uVar12;

  }

  return;

}
