// =============================================================================
// FUN_007444e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007444e0
// Address:   0x007444e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007444e0 @ 0x007444e0
// Stable ID: aa_007444e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~227 non-empty decompiler lines.
//  - Control keywords: if×14, while×12, for×2, do×1, return×1.
//  - Notable callees: FUN_00767160×4, FUN_00426f60×3, FUN_0044dc00, FUN_007444e0.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ FUN_007444e0(int param_1)



{

  int *piVar1;

  char cVar2;

  uint uVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint uVar11;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar12;

  undefined *puVar13;

  uint32_t /* width from decompiler */ uVar14;

  int **ppiVar15;

  int *piVar16;

  int *local_2c [3];

  uint uStack_20;

  uint uStack_14;

  int iStack_4;

  

  piVar16 = *(int **)(param_1 + 0x14);

  piVar10 = (int *)0x0;

  piVar4 = piVar16;

  piVar1 = (int *)*piVar16;

  while (local_2c[0] = piVar1, piVar1 != piVar16) {

    if ((piVar4[3] != piVar1[3]) || (piVar4 == piVar16)) {

      piVar10 = (int *)((int)piVar10 + 2);

    }

    piVar10 = (int *)((int)piVar10 + 1);

    FUN_0044dc00();

    piVar4 = piVar1;

    piVar1 = local_2c[0];

  }

  if (unaff_ESI[7] == 0) {

    piVar16 = (int *)0x4;

    ppiVar15 = local_2c;

    local_2c[0] = piVar10;

  }

  else {

    uVar3 = FUN_00767160(&DAT_00a37c64,piVar10);

    unaff_ESI[1] = unaff_ESI[1] | uVar3;

    piVar16 = (int *)0x2;

    unaff_ESI[8] = 0;

    ppiVar15 = (int **)&DAT_00a97b84;

  }

  uVar3 = (**(code **)(*(int *)*unaff_ESI + 0x18))(ppiVar15);

  unaff_ESI[1] = unaff_ESI[1] | uVar3;

  piVar4 = (int *)**(int **)(iStack_4 + 0x14);

  iVar9 = iStack_4;

  if (piVar4 != *(int **)(iStack_4 + 0x14)) {

    do {

      FUN_00426f60();

      puVar12 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14);

      cVar2 = *(char *)((int)puVar12[1] + 0x25);

      puVar7 = (uint32_t /* width from decompiler */ *)puVar12[1];

      while (cVar2 == '\0') {

        if (local_2c[0] < (int *)puVar7[3]) {

          puVar6 = (uint32_t /* width from decompiler */ *)*puVar7;

          puVar12 = puVar7;

        }

        else {

          puVar6 = (uint32_t /* width from decompiler */ *)puVar7[2];

        }

        puVar7 = puVar6;

        cVar2 = *(char *)((int)puVar6 + 0x25);

      }

      puVar7 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(iVar9 + 0x14))[1];

      cVar2 = *(char *)((int)puVar7 + 0x25);

      puVar6 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14);

      while (cVar2 == '\0') {

        if ((int *)puVar7[3] < local_2c[0]) {

          puVar5 = (uint32_t /* width from decompiler */ *)puVar7[2];

          puVar7 = puVar6;

        }

        else {

          puVar5 = (uint32_t /* width from decompiler */ *)*puVar7;

        }

        puVar6 = puVar7;

        puVar7 = puVar5;

        cVar2 = *(char *)((int)puVar5 + 0x25);

      }

      iVar8 = 0;

      while (puVar6 != puVar12) {

        iVar8 = iVar8 + 1;

        if (*(char *)((int)puVar6 + 0x25) == '\0') {

          puVar7 = (uint32_t /* width from decompiler */ *)puVar6[2];

          if (*(char *)((int)puVar7 + 0x25) == '\0') {

            cVar2 = *(char *)((int)*puVar7 + 0x25);

            puVar6 = puVar7;

            puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

            while (cVar2 == '\0') {

              cVar2 = *(char *)((int)*puVar7 + 0x25);

              puVar6 = puVar7;

              puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

            }

          }

          else {

            cVar2 = *(char *)((int)puVar6[1] + 0x25);

            puVar5 = (uint32_t /* width from decompiler */ *)puVar6[1];

            puVar7 = puVar6;

            while ((puVar6 = puVar5, cVar2 == '\0' && (puVar7 == (uint32_t /* width from decompiler */ *)puVar6[2]))) {

              cVar2 = *(char *)((int)puVar6[1] + 0x25);

              puVar5 = (uint32_t /* width from decompiler */ *)puVar6[1];

              puVar7 = puVar6;

            }

          }

        }

      }

      if (unaff_ESI[7] == 0) {

        uVar14 = 4;

        puVar13 = &stack0xffffffd0;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a37c64,iVar8 + 1);

        unaff_ESI[1] = unaff_ESI[1] | uVar3;

        uVar14 = 2;

        unaff_ESI[8] = 0;

        puVar13 = &DAT_00a97b84;

      }

      uVar3 = (**(code **)(*(int *)*unaff_ESI + 0x18))(puVar13,uVar14);

      unaff_ESI[1] = unaff_ESI[1] | uVar3;

      piVar4 = piVar4 + 3;

      for (uVar3 = 0;

          ((uVar11 = 0xffffffff, *(int *)(iVar9 + 0x50) != 0 &&

           (uVar3 < (uint)(*(int *)(iVar9 + 0x54) - *(int *)(iVar9 + 0x50) >> 2))) &&

          (uVar11 = uVar3, *piVar4 != *(int *)(*(int *)(iVar9 + 0x50) + uVar3 * 4)));

          uVar3 = uVar3 + 1) {

        piVar4 = piVar16;

      }

      if (unaff_ESI[7] == 0) {

        uVar14 = 4;

        puVar13 = &stack0xffffffc8;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a37c64,uVar11);

        unaff_ESI[1] = unaff_ESI[1] | uVar3;

        uVar14 = 2;

        unaff_ESI[8] = 0;

        puVar13 = &DAT_00a97b84;

      }

      uVar3 = (**(code **)(*(int *)*unaff_ESI + 0x18))(puVar13,uVar14);

      unaff_ESI[1] = unaff_ESI[1] | uVar3;

      FUN_00426f60();

      puVar12 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(iVar9 + 0x14))[1];

      cVar2 = *(char *)((int)puVar12 + 0x25);

      puVar7 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14);

      while (cVar2 == '\0') {

        if ((uint)puVar12[3] < uStack_20) {

          puVar6 = (uint32_t /* width from decompiler */ *)puVar12[2];

          puVar12 = puVar7;

        }

        else {

          puVar6 = (uint32_t /* width from decompiler */ *)*puVar12;

        }

        puVar7 = puVar12;

        puVar12 = puVar6;

        cVar2 = *(char *)((int)puVar6 + 0x25);

      }

      FUN_00426f60();

      piVar4 = *(int **)(iVar9 + 0x14);

      cVar2 = *(char *)(piVar4[1] + 0x25);

      puVar12 = (uint32_t /* width from decompiler */ *)piVar4[1];

      while (cVar2 == '\0') {

        if (uStack_14 < (uint)puVar12[3]) {

          puVar6 = (uint32_t /* width from decompiler */ *)*puVar12;

          piVar4 = puVar12;

        }

        else {

          puVar6 = (uint32_t /* width from decompiler */ *)puVar12[2];

        }

        puVar12 = puVar6;

        cVar2 = *(char *)((int)puVar6 + 0x25);

      }

      while (puVar7 != piVar4) {

        piVar1 = (int *)(iVar9 + 0x50);

        iVar8 = iVar9;

        for (uVar3 = 0;

            ((iVar9 = iVar8, uVar11 = 0xffffffff, *piVar1 != 0 &&

             (uVar3 < (uint)(*(int *)(iVar8 + 0x54) - *piVar1 >> 2))) &&

            (iVar9 = iStack_4, uVar11 = uVar3,

            puVar7[6] != *(int *)(*(int *)(iVar8 + 0x50) + uVar3 * 4))); uVar3 = uVar3 + 1) {

          iVar8 = iStack_4;

        }

        if (unaff_ESI[7] == 0) {

          uVar14 = 4;

          puVar13 = &stack0xffffffd0;

        }

        else {

          uVar3 = FUN_00767160(&DAT_00a37c64,uVar11);

          unaff_ESI[1] = unaff_ESI[1] | uVar3;

          uVar14 = 2;

          unaff_ESI[8] = 0;

          puVar13 = &DAT_00a97b84;

        }

        uVar3 = (**(code **)(*(int *)*unaff_ESI + 0x18))(puVar13,uVar14);

        unaff_ESI[1] = unaff_ESI[1] | uVar3;

        if (*(char *)((int)puVar7 + 0x25) == '\0') {

          puVar12 = (uint32_t /* width from decompiler */ *)puVar7[2];

          if (*(char *)((int)puVar12 + 0x25) == '\0') {

            cVar2 = *(char *)((int)*puVar12 + 0x25);

            puVar7 = puVar12;

            puVar12 = (uint32_t /* width from decompiler */ *)*puVar12;

            while (cVar2 == '\0') {

              cVar2 = *(char *)((int)*puVar12 + 0x25);

              puVar7 = puVar12;

              puVar12 = (uint32_t /* width from decompiler */ *)*puVar12;

            }

          }

          else {

            cVar2 = *(char *)((int)puVar7[1] + 0x25);

            puVar6 = (uint32_t /* width from decompiler */ *)puVar7[1];

            puVar12 = puVar7;

            while ((puVar7 = puVar6, cVar2 == '\0' && (puVar12 == (uint32_t /* width from decompiler */ *)puVar7[2]))) {

              cVar2 = *(char *)((int)puVar7[1] + 0x25);

              puVar6 = (uint32_t /* width from decompiler */ *)puVar7[1];

              puVar12 = puVar7;

            }

          }

        }

      }

    } while (piVar4 != *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14));

  }

  return 0;

}
