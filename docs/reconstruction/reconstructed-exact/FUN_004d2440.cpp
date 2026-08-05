// =============================================================================
// FUN_004d2440
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2440
// Address:   0x004d2440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2440 @ 0x004d2440
// Stable ID: aa_004d2440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, return×2, goto×1.
//  - Notable callees: FUN_004d2440, FUN_005a58c0, SQRT.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_004d2440(int param_1,float *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint uVar10;

  int iVar11;

  int *piVar12;

  float *pfVar13;

  uint uVar14;

  uint uVar15;

  float10 fVar16;

  float fVar17;

  int unaff_retaddr;

  uint local_34;

  float local_30;

  float local_2c;

  int local_1c;

  uint8_t local_18 [8];

  uint8_t auStack_10 [4];

  uint8_t auStack_c [8];

  uint32_t /* width from decompiler */ uStack_4;

  

  uVar3 = (uint)(*param_2 / *(float *)(param_1 + 0xe7c0));

  iVar7 = *(int *)(param_1 + 0xe7b8);

  uVar3 = ((int)uVar3 < 0) - 1 & uVar3;

  uVar14 = (uint)(param_2[2] / *(float *)(param_1 + 0xe7c4));

  if ((int)(iVar7 - 1U) < (int)uVar3) {

    uVar3 = iVar7 - 1U;

  }

  uVar4 = *(int *)(param_1 + 0xe7bc) - 1;

  uVar14 = ((int)uVar14 < 0) - 1 & uVar14;

  if ((int)uVar4 < (int)uVar14) {

    uVar14 = uVar4;

  }

  local_2c = *(float *)(param_1 + 0xe7b4);

  iVar5 = (iVar7 * uVar14 + uVar3) * 0x20;

  iVar11 = *(int *)(iVar5 + 4 + (int)local_2c);

  if ((iVar11 == 0) || (*(int *)(iVar5 + (int)local_2c + 8) - iVar11 >> 2 == 0)) {

    uVar10 = uVar14 - 1;

    local_34 = uVar3 - 1;

    local_30 = -NAN;

    do {

      uVar14 = ((int)local_34 < 0) - 1 & local_34;

      uVar3 = iVar7 - 1U;

      if ((int)uVar14 <= (int)(iVar7 - 1U)) {

        uVar3 = uVar14;

      }

      iVar11 = -1;

      uVar15 = uVar10;

      do {

        uVar14 = ((int)uVar15 < 0) - 1 & uVar15;

        if ((int)uVar4 < (int)uVar14) {

          uVar14 = uVar4;

        }

        iVar6 = (iVar7 * uVar14 + uVar3) * 0x20 + (int)local_2c;

        iVar5 = *(int *)(iVar6 + 4);

        if ((iVar5 != 0) && (local_1c = *(int *)(iVar6 + 8) - iVar5 >> 2, local_1c != 0))

        goto LAB_004d2590;

        iVar11 = iVar11 + 1;

        uVar15 = uVar15 + 1;

      } while (iVar11 < 2);

      local_34 = local_34 + 1;

      local_30 = (float)((int)local_30 + 1);

    } while ((int)local_30 < 2);

  }

  else {

LAB_004d2590:

    if ((uVar3 != 0xffffffff) && (uVar14 != 0xffffffff)) {

      iVar7 = (iVar7 * uVar14 + uVar3) * 0x20 + (int)local_2c;

      pfVar13 = *(float **)(iVar7 + 4);

      piVar12 = (int *)0x0;

      if (pfVar13 != *(float **)(iVar7 + 8)) {

        do {

          piVar2 = (int *)*pfVar13;

          iVar7 = (**(code **)(*piVar2 + 0x40))(local_18);

          local_30 = *(float *)(iVar7 + 8) - *(float *)(unaff_retaddr + 8);

          pfVar8 = (float *)(**(code **)(*piVar2 + 0x40))(auStack_10);

          local_2c = SQRT((*pfVar8 - *param_2) * (*pfVar8 - *param_2) + local_2c * local_2c);

          if (local_2c < local_30) {

            piVar12 = (int *)*pfVar13;

            local_30 = local_2c;

          }

          pfVar13 = pfVar13 + 1;

        } while (pfVar13 !=

                 *(float **)

                  ((*(int *)(param_1 + 0xe7b8) * uVar14 + uVar3) * 0x20 + 8 +

                  *(int *)(param_1 + 0xe7b4)));

        if (piVar12 != (int *)0x0) {

          iVar7 = (**(code **)(*piVar12 + 0x40))(auStack_c);

          puVar1 = *(uint32_t /* width from decompiler */ **)(iVar7 + 8);

          puVar9 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar12 + 0x40))(&local_1c);

          fVar17 = 0.0;

          *puVar1 = *puVar9;

          puVar1[1] = 0;

          puVar1[2] = uStack_4;

          puVar1[3] = 0;

          if (*(int *)((int)local_30 + 0xe4e0) != 0) {

            fVar16 = (float10)FUN_005a58c0(*puVar1,uStack_4);

            fVar17 = (float)fVar16;

          }

          puVar1[1] = fVar17;

          *param_2 = (float)piVar12;

          return 1;

        }

      }

    }

  }

  return 0;

}
