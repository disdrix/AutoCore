// =============================================================================
// FUN_00649280
// -----------------------------------------------------------------------------
// Stable ID: aa_00649280
// Address:   0x00649280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00649280 @ 0x00649280
// Stable ID: aa_00649280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_00635880, FUN_00649280.
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

void __thiscall FUN_00649280(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  float *pfVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  int local_234;

  uint8_t *local_200;

  int local_1fc;

  int local_1f8;

  uint8_t local_1f0 [492];

  

  iVar5 = *(int *)(param_2 + 0x10);

  local_200 = local_1f0;

  local_1fc = 0;

  local_1f8 = -0x7ffffff1;

  if (0xf < iVar5) {

    iVar8 = 0x1e;

    if (0x1d < iVar5) {

      iVar8 = iVar5;

    }

    FUN_005b3300(&local_200,iVar8,0x20);

  }

  iVar8 = *(int *)(param_1 + 0x24);

  local_234 = 0;

  if (0 < iVar5) {

    iVar11 = 0;

    do {

      iVar6 = *(int *)(*(int *)(param_1 + 8) + local_234 * 4);

      iVar7 = *(int *)(iVar6 + 0x3c);

      *(uint32_t /* width from decompiler */ *)(local_200 + iVar11) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0xb0);

      pfVar9 = (float *)(local_200 + iVar11);

      pfVar9[1] = *(float *)(iVar7 + 0xb4);

      pfVar9[2] = *(float *)(iVar7 + 0xb8);

      pfVar9[3] = *(float *)(iVar7 + 0xbc);

      iVar6 = *(int *)(iVar6 + 0x3c);

      pfVar9[4] = *(float *)(iVar6 + 0x30);

      pfVar9[5] = *(float *)(iVar6 + 0x34);

      pfVar9[6] = *(float *)(iVar6 + 0x38);

      pfVar9[7] = *(float *)(iVar6 + 0x3c);

      fVar2 = g_flLevelUpUiBase_Inferred;

      if (iVar8 != 0) {

        iVar6 = *(int *)(param_1 + 0x20);

        fVar1 = *(float *)(iVar11 + 0x1c + iVar6);

        fVar12 = 0.0 - *(float *)(iVar11 + 0x10 + iVar6);

        fVar14 = 0.0 - *(float *)(iVar11 + 0x14 + iVar6);

        fVar15 = 0.0 - *(float *)(iVar11 + 0x18 + iVar6);

        fVar20 = pfVar9[5] * fVar1 + fVar14 * pfVar9[7] + (pfVar9[6] * fVar12 - pfVar9[4] * fVar15);

        fVar19 = pfVar9[4] * fVar1 + pfVar9[7] * fVar12 + (pfVar9[5] * fVar15 - pfVar9[6] * fVar14);

        fVar17 = pfVar9[6] * fVar1 + fVar15 * pfVar9[7] + (pfVar9[4] * fVar14 - pfVar9[5] * fVar12);

        fVar18 = pfVar9[7] * fVar1 - (pfVar9[6] * fVar15 + pfVar9[5] * fVar14 + pfVar9[4] * fVar12);

        pfVar9[4] = fVar19;

        pfVar9[5] = fVar20;

        pfVar9[6] = fVar17;

        pfVar9[7] = fVar18;

        pfVar10 = (float *)(*(int *)(param_1 + 0x20) + iVar11);

        fVar16 = fVar18 * fVar18 * fVar2 - g_flOne;

        fVar13 = (fVar20 * pfVar10[1] + *(float *)(*(int *)(param_1 + 0x20) + 8 + iVar11) * fVar17 +

                 *pfVar10 * fVar19) * fVar2;

        fVar18 = fVar18 * fVar2;

        fVar2 = *pfVar10;

        fVar1 = pfVar10[2];

        fVar12 = pfVar10[1];

        fVar14 = *pfVar10;

        fVar15 = pfVar10[1];

        fVar3 = pfVar10[2];

        fVar4 = pfVar10[3];

        *pfVar9 = *pfVar9 - ((fVar20 * pfVar10[2] - fVar17 * pfVar10[1]) * fVar18 +

                            pfVar9[4] * fVar13 + *pfVar10 * fVar16);

        pfVar9[1] = pfVar9[1] -

                    ((fVar2 * pfVar9[6] - fVar1 * fVar19) * fVar18 +

                    pfVar9[5] * fVar13 + fVar16 * fVar15);

        pfVar9[2] = pfVar9[2] -

                    ((fVar19 * fVar12 - fVar20 * fVar14) * fVar18 +

                    fVar13 * pfVar9[6] + fVar3 * fVar16);

        pfVar9[3] = pfVar9[3] - (fVar18 * 0.0 + pfVar9[7] * fVar13 + fVar4 * fVar16);

      }

      local_234 = local_234 + 1;

      iVar11 = iVar11 + 0x20;

    } while (local_234 < iVar5);

  }

  local_1fc = iVar5;

  FUN_00635880(&local_200);

  if (-1 < local_1f8) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_200,local_1f8 << 5,0x12);

  }

  return;

}
