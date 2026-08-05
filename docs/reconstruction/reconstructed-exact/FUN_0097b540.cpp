// =============================================================================
// FUN_0097b540
// -----------------------------------------------------------------------------
// Stable ID: aa_0097b540
// Address:   0x0097b540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097b540 @ 0x0097b540
// Stable ID: aa_0097b540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~251 non-empty decompiler lines.
//  - Control keywords: if×35, for×8, do×2, return×2, while×2.
//  - Notable callees: FUN_00414a50×4, FUN_00746520×4, FUN_00404d80, FUN_004b4910, FUN_004b6f00, FUN_004b8ed0, FUN_004b99c0, FUN_0079ed10.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall FUN_0097b540(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  void *pvVar11;

  int iVar12;

  char cVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint uVar15;

  int iVar16;

  int iVar17;

  int iVar18;

  uint32_t /* width from decompiler */ *puVar19;

  uint32_t /* width from decompiler */ *puStack_14048;

  uint8_t auStack_14014 [81940];

  

  iVar12 = DAT_00d17944;

  if (((param_1[0x155] != 0) && (param_1[0x156] - param_1[0x155] >> 2 != 0)) &&

     (g_flZero < DAT_00af06e0)) {

    uVar10 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x2e4);

    *(int *)(DAT_00d17944 + 0x2e4) = param_1[0xa9];

    uVar1 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x294);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x298);

    puStack_14048 = (uint32_t /* width from decompiler */ *)(iVar12 + 0x294);

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x29c);

    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a0);

    uVar5 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a4);

    uVar6 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a8);

    uVar7 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2ac);

    uVar8 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2b0);

    uVar9 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2b4);

    FUN_0079ed10();

    puVar14 = (uint32_t /* width from decompiler */ *)param_1[0x155];

    if (puVar14 != (uint32_t /* width from decompiler */ *)param_1[0x156]) {

      puVar19 = puVar14 + 1;

      do {

        pvVar11 = (void *)*puVar14;

        cVar13 = FUN_004b8ed0(&param_2);

        if (cVar13 == '\0') {

          puVar14 = puVar14 + 1;

          puVar19 = puVar19 + 1;

        }

        else {

          memmove(puVar14,puVar19,(param_1[0x156] - (int)puVar19 >> 2) * 4);

          param_1[0x156] = param_1[0x156] + -4;

          if (pvVar11 != (void *)0x0) {

            FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar11);

          }

        }

      } while (puVar14 != (uint32_t /* width from decompiler */ *)param_1[0x156]);

    }

    FUN_00404d80(auStack_14014,0x4004,5,FUN_0066dcf0);

    iVar17 = param_1[0x155];

    if (iVar17 != param_1[0x156]) {

      do {

        FUN_004b6f00(auStack_14014);

        iVar17 = iVar17 + 4;

      } while (iVar17 != param_1[0x156]);

    }

    FUN_004b4910(auStack_14014);

    iVar17 = param_1[0x13f];

    if (iVar17 != 0) {

      if (*(int *)(iVar12 + 0x168) < 6) {

        if (0 < *(int *)(iVar17 + 0xa8)) {

          *(uint32_t /* width from decompiler */ *)(iVar17 + 0xa8) = 0;

          *(uint *)(param_1[0x13f] + 0xbc) = *(uint *)(param_1[0x13f] + 0xbc) & 0xfffffffe;

        }

      }

      else {

        *(uint *)(iVar17 + 0xbc) = *(uint *)(iVar17 + 0xbc) | 1;

        iVar18 = param_1[0x14d];

        if (*(int *)(iVar12 + 0x168) < iVar18) {

          iVar18 = *(int *)(iVar12 + 0x168);

        }

        iVar17 = *(int *)(iVar17 + 0x14);

        if (*(int *)(iVar17 + 0x10) != 0) {

          iVar16 = iVar18;

          if (iVar18 < 1) {

            iVar16 = *(int *)(iVar17 + 0x18);

          }

          puVar14 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar17 + 0x14),iVar16,1);

          if (puVar14 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar19 = *(uint32_t /* width from decompiler */ **)(iVar12 + 0x16c);

            for (uVar15 = (uint)(iVar18 * 0x1c) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

              *puVar14 = *puVar19;

              puVar19 = puVar19 + 1;

              puVar14 = puVar14 + 1;

            }

            for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {

              *(uint8_t *)puVar14 = *(uint8_t *)puVar19;

              puVar19 = (uint32_t /* width from decompiler */ *)((int)puVar19 + 1);

              puVar14 = (uint32_t /* width from decompiler */ *)((int)puVar14 + 1);

            }

            *(int *)(param_1[0x13f] + 0xa8) = iVar18 / 3;

            *(uint *)(param_1[0x13f] + 0xbc) = *(uint *)(param_1[0x13f] + 0xbc) & 0xfffffffe;

          }

        }

        FUN_00414a50();

      }

    }

    iVar17 = param_1[0x140];

    if (iVar17 != 0) {

      if (*(int *)(iVar12 + 0x17c) < 6) {

        if (0 < *(int *)(iVar17 + 0xa8)) {

          *(uint32_t /* width from decompiler */ *)(iVar17 + 0xa8) = 0;

          *(uint *)(param_1[0x140] + 0xbc) = *(uint *)(param_1[0x140] + 0xbc) & 0xfffffffe;

        }

      }

      else {

        *(uint *)(iVar17 + 0xbc) = *(uint *)(iVar17 + 0xbc) | 1;

        iVar18 = param_1[0x14e];

        if (*(int *)(iVar12 + 0x17c) < iVar18) {

          iVar18 = *(int *)(iVar12 + 0x17c);

        }

        iVar17 = *(int *)(iVar17 + 0x14);

        if (*(int *)(iVar17 + 0x10) != 0) {

          iVar16 = iVar18;

          if (iVar18 < 1) {

            iVar16 = *(int *)(iVar17 + 0x18);

          }

          puVar14 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar17 + 0x14),iVar16,1);

          if (puVar14 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar19 = *(uint32_t /* width from decompiler */ **)(iVar12 + 0x180);

            for (uVar15 = (uint)(iVar18 * 0x1c) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

              *puVar14 = *puVar19;

              puVar19 = puVar19 + 1;

              puVar14 = puVar14 + 1;

            }

            for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {

              *(uint8_t *)puVar14 = *(uint8_t *)puVar19;

              puVar19 = (uint32_t /* width from decompiler */ *)((int)puVar19 + 1);

              puVar14 = (uint32_t /* width from decompiler */ *)((int)puVar14 + 1);

            }

            *(int *)(param_1[0x140] + 0xa8) = iVar18 / 3;

            *(uint *)(param_1[0x140] + 0xbc) = *(uint *)(param_1[0x140] + 0xbc) & 0xfffffffe;

          }

        }

        FUN_00414a50();

      }

    }

    iVar17 = param_1[0x141];

    if (iVar17 != 0) {

      if (*(int *)(iVar12 + 400) < 6) {

        if (0 < *(int *)(iVar17 + 0xa8)) {

          *(uint32_t /* width from decompiler */ *)(iVar17 + 0xa8) = 0;

          *(uint *)(param_1[0x141] + 0xbc) = *(uint *)(param_1[0x141] + 0xbc) & 0xfffffffe;

        }

      }

      else {

        *(uint *)(iVar17 + 0xbc) = *(uint *)(iVar17 + 0xbc) | 1;

        iVar18 = param_1[0x14f];

        if (*(int *)(iVar12 + 400) < iVar18) {

          iVar18 = *(int *)(iVar12 + 400);

        }

        iVar17 = *(int *)(iVar17 + 0x14);

        if (*(int *)(iVar17 + 0x10) != 0) {

          iVar16 = iVar18;

          if (iVar18 < 1) {

            iVar16 = *(int *)(iVar17 + 0x18);

          }

          puVar14 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar17 + 0x14),iVar16,1);

          if (puVar14 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar19 = *(uint32_t /* width from decompiler */ **)(iVar12 + 0x194);

            for (uVar15 = (uint)(iVar18 * 0x1c) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

              *puVar14 = *puVar19;

              puVar19 = puVar19 + 1;

              puVar14 = puVar14 + 1;

            }

            for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {

              *(uint8_t *)puVar14 = *(uint8_t *)puVar19;

              puVar19 = (uint32_t /* width from decompiler */ *)((int)puVar19 + 1);

              puVar14 = (uint32_t /* width from decompiler */ *)((int)puVar14 + 1);

            }

            *(int *)(param_1[0x141] + 0xa8) = iVar18 / 3;

            *(uint *)(param_1[0x141] + 0xbc) = *(uint *)(param_1[0x141] + 0xbc) & 0xfffffffe;

          }

        }

        FUN_00414a50();

      }

    }

    iVar17 = param_1[0x142];

    if (iVar17 != 0) {

      if (*(int *)(iVar12 + 0x1cc) < 6) {

        if (0 < *(int *)(iVar17 + 0xa8)) {

          *(uint32_t /* width from decompiler */ *)(iVar17 + 0xa8) = 0;

          *(uint *)(param_1[0x142] + 0xbc) = *(uint *)(param_1[0x142] + 0xbc) & 0xfffffffe;

        }

      }

      else {

        *(uint *)(iVar17 + 0xbc) = *(uint *)(iVar17 + 0xbc) | 1;

        iVar18 = param_1[0x150];

        if (*(int *)(iVar12 + 0x1cc) < iVar18) {

          iVar18 = *(int *)(iVar12 + 0x1cc);

        }

        iVar17 = *(int *)(iVar17 + 0x14);

        if (*(int *)(iVar17 + 0x10) != 0) {

          iVar16 = iVar18;

          if (iVar18 < 1) {

            iVar16 = *(int *)(iVar17 + 0x18);

          }

          puVar14 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar17 + 0x14),iVar16,1);

          if (puVar14 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar19 = *(uint32_t /* width from decompiler */ **)(iVar12 + 0x1d0);

            for (uVar15 = (uint)(iVar18 * 0x1c) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

              *puVar14 = *puVar19;

              puVar19 = puVar19 + 1;

              puVar14 = puVar14 + 1;

            }

            for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {

              *(uint8_t *)puVar14 = *(uint8_t *)puVar19;

              puVar19 = (uint32_t /* width from decompiler */ *)((int)puVar19 + 1);

              puVar14 = (uint32_t /* width from decompiler */ *)((int)puVar14 + 1);

            }

            *(int *)(param_1[0x142] + 0xa8) = iVar18 / 3;

            *(uint *)(param_1[0x142] + 0xbc) = *(uint *)(param_1[0x142] + 0xbc) & 0xfffffffe;

          }

        }

        FUN_00414a50();

      }

    }

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2e4) = uVar10;

    *puStack_14048 = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x298) = uVar2;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x29c) = uVar3;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a0) = uVar4;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a4) = uVar5;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2a8) = uVar6;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2ac) = uVar7;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2b0) = uVar8;

    *(uint32_t /* width from decompiler */ *)(iVar12 + 0x2b4) = uVar9;

  }

  (**(code **)(*param_1 + 500))(param_2);

  cVar13 = (**(code **)(*param_1 + 0xf8))();

  if (cVar13 != '\0') {

    (**(code **)(*param_1 + 0x348))(puStack_14048);

  }

  if (param_1[0xad] != 0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(puStack_14048);

  }

  return;

}
