// =============================================================================
// FUN_00635bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00635bd0
// Address:   0x00635bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635bd0 @ 0x00635bd0
// Stable ID: aa_00635bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_00635bd0.
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

void __thiscall FUN_00635bd0(int param_1,int *param_2)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  short sVar10;

  float fVar11;

  int iVar12;

  int iVar13;

  float *pfVar14;

  float *pfVar15;

  int iVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  int local_18;

  

  iVar16 = *(int *)(param_1 + 0x10);

  if ((int)(param_2[2] & 0x7fffffffU) < iVar16) {

    iVar12 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar12 <= iVar16) {

      iVar12 = iVar16;

    }

    FUN_005b3300(param_2,iVar12,0x20);

  }

  param_2[1] = iVar16;

  fVar11 = g_flLevelUpUiBase_Inferred;

  local_18 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    iVar16 = 0;

    do {

      sVar10 = *(short *)(*(int *)(*(int *)(param_1 + 8) + 8) + local_18 * 2);

      iVar12 = *param_2;

      pfVar15 = (float *)(*(int *)(param_1 + 0xc) + iVar16);

      if (sVar10 == -1) {

        *(float *)(iVar16 + iVar12) = *pfVar15;

        *(float *)(iVar16 + 4 + iVar12) = pfVar15[1];

        *(float *)(iVar16 + 8 + iVar12) = pfVar15[2];

        *(float *)(iVar16 + 0xc + iVar12) = pfVar15[3];

        pfVar1 = (float *)(iVar16 + 0x10 + iVar12);

        *pfVar1 = pfVar15[4];

        pfVar1[1] = pfVar15[5];

        pfVar1[2] = pfVar15[6];

        pfVar1[3] = pfVar15[7];

      }

      else {

        fVar21 = pfVar15[5];

        iVar13 = sVar10 * 0x20;

        fVar22 = *(float *)(iVar13 + 0x18 + iVar12);

        fVar17 = *(float *)(iVar13 + 0x18 + iVar12) * pfVar15[4] -

                 *(float *)(iVar13 + 0x10 + iVar12) * pfVar15[6];

        fVar19 = pfVar15[5] * *(float *)(iVar13 + 0x10 + iVar12) -

                 *(float *)(iVar13 + 0x14 + iVar12) * pfVar15[4];

        fVar23 = *(float *)(iVar13 + 0x14 + iVar12);

        fVar24 = pfVar15[6];

        *(float *)(iVar16 + 0x18 + iVar12) = fVar19;

        *(float *)(iVar16 + 0x14 + iVar12) = fVar17;

        *(uint32_t /* width from decompiler */ *)(iVar16 + 0x1c + iVar12) = 0;

        pfVar14 = (float *)(iVar13 + iVar12);

        *(float *)(iVar16 + 0x10 + iVar12) = fVar23 * fVar24 - fVar21 * fVar22;

        fVar21 = pfVar14[7];

        *(float *)(iVar16 + 0x10 + iVar12) =

             pfVar15[4] * fVar21 + *(float *)(iVar16 + 0x10 + iVar12);

        fVar17 = pfVar15[5] * fVar21 + fVar17;

        *(float *)(iVar16 + 0x14 + iVar12) = fVar17;

        *(float *)(iVar16 + 0x18 + iVar12) = fVar21 * pfVar15[6] + fVar19;

        fVar22 = pfVar15[7];

        *(float *)(iVar16 + 0x1c + iVar12) = fVar21 * fVar22;

        fVar23 = pfVar15[7];

        *(float *)(iVar16 + 0x10 + iVar12) =

             pfVar14[4] * fVar23 + *(float *)(iVar16 + 0x10 + iVar12);

        *(float *)(iVar16 + 0x14 + iVar12) = pfVar14[5] * fVar23 + fVar17;

        *(float *)(iVar16 + 0x18 + iVar12) =

             pfVar14[6] * fVar23 + *(float *)(iVar16 + 0x18 + iVar12);

        *(float *)(iVar16 + 0x1c + iVar12) = pfVar14[7] * fVar23 + fVar21 * fVar22;

        *(float *)(iVar16 + 0x1c + iVar12) =

             pfVar14[7] * pfVar15[7] -

             (pfVar14[6] * pfVar15[6] + pfVar14[5] * pfVar15[5] + pfVar14[4] * pfVar15[4]);

        fVar25 = pfVar14[7] * pfVar14[7] * fVar11 - g_flOne;

        fVar18 = (pfVar14[5] * pfVar15[1] + pfVar15[2] * pfVar14[6] + *pfVar15 * pfVar14[4]) *

                 fVar11;

        fVar20 = pfVar14[7] * fVar11;

        fVar21 = pfVar14[5];

        fVar22 = pfVar15[2];

        fVar23 = pfVar14[6];

        fVar24 = pfVar15[1];

        fVar17 = pfVar14[4];

        fVar19 = pfVar15[2];

        fVar3 = pfVar14[5];

        fVar4 = *pfVar15;

        fVar5 = *pfVar15;

        fVar6 = pfVar14[6];

        fVar7 = pfVar14[4];

        fVar8 = pfVar15[1];

        *(float *)(iVar16 + iVar12) = *pfVar15 * fVar25;

        *(float *)(iVar16 + 4 + iVar12) = fVar25 * pfVar15[1];

        *(float *)(iVar16 + 8 + iVar12) = pfVar15[2] * fVar25;

        fVar9 = pfVar15[3];

        pfVar15 = (float *)(iVar16 + 4 + iVar12);

        *(float *)(iVar16 + 0xc + iVar12) = fVar9 * fVar25;

        *(float *)(iVar16 + iVar12) = pfVar14[4] * fVar18 + *(float *)(iVar16 + iVar12);

        pfVar1 = (float *)(iVar16 + 0xc + iVar12);

        *pfVar15 = pfVar14[5] * fVar18 + *pfVar15;

        *(float *)(iVar16 + 8 + iVar12) = fVar18 * pfVar14[6] + *(float *)(iVar16 + 8 + iVar12);

        pfVar2 = (float *)(iVar16 + 8 + iVar12);

        *pfVar1 = pfVar14[7] * fVar18 + fVar9 * fVar25;

        fVar22 = (fVar21 * fVar22 - fVar23 * fVar24) * fVar20 + *(float *)(iVar16 + iVar12);

        fVar23 = (fVar5 * fVar6 - fVar17 * fVar19) * fVar20 + *pfVar15;

        *pfVar15 = fVar23;

        fVar24 = (fVar7 * fVar8 - fVar3 * fVar4) * fVar20 + *pfVar2;

        *(float *)(iVar16 + iVar12) = fVar22;

        *pfVar2 = fVar24;

        fVar21 = fVar20 * 0.0 + *pfVar1;

        *pfVar1 = fVar21;

        *(float *)(iVar16 + iVar12) = *pfVar14 + fVar22;

        *pfVar15 = pfVar14[1] + fVar23;

        *pfVar2 = pfVar14[2] + fVar24;

        *pfVar1 = pfVar14[3] + fVar21;

      }

      local_18 = local_18 + 1;

      iVar16 = iVar16 + 0x20;

    } while (local_18 < *(int *)(param_1 + 0x10));

  }

  return;

}
