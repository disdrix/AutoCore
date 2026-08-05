// =============================================================================
// FUN_00717240
// -----------------------------------------------------------------------------
// Stable ID: aa_00717240
// Address:   0x00717240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717240 @ 0x00717240
// Stable ID: aa_00717240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: do×5, while×5, if×4, return×1.
//  - Notable callees: FUN_00717240, FUN_00717630.
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

void FUN_00717240(int param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float *pfVar17;

  int iVar18;

  float *pfVar19;

  uint uVar20;

  int iVar21;

  float *pfVar22;

  float *pfVar23;

  float *pfVar24;

  float *pfVar25;

  int local_68;

  float *local_3c;

  int local_18;

  uint local_14;

  int local_c;

  int local_8;

  

  local_8 = 1;

  pfVar24 = (float *)&DAT_00a13e04;

  iVar21 = param_3;

  iVar18 = local_8;

  if (param_3 != 0x100) {

    pfVar24 = (float *)&DAT_00a13f84;

  }

  do {

    local_8 = iVar18;

    param_3 = iVar21;

    uVar20 = param_3 >> 2;

    iVar21 = (local_8 * 0x10 + -0xc) * uVar20;

    local_68 = iVar21 + -0x10 + param_1;

    local_3c = (float *)(iVar21 + -0x10 + param_2);

    if (local_8 != 0) {

      local_c = local_8;

      do {

        pfVar24 = pfVar24 + (param_3 >> 4) * -0x18;

        if (-1 < (int)(uVar20 - 4)) {

          local_14 = uVar20 >> 2;

          do {

            pfVar19 = local_3c + uVar20;

            iVar21 = local_68 - (int)local_3c;

            local_18 = 4;

            pfVar17 = local_3c + uVar20 * 3;

            pfVar22 = local_3c;

            pfVar23 = local_3c + uVar20 * 2;

            do {

              pfVar25 = pfVar24;

              fVar1 = *pfVar25;

              fVar2 = pfVar25[4];

              fVar3 = pfVar25[8];

              fVar4 = pfVar25[0xc];

              fVar5 = pfVar25[0x10];

              fVar7 = *(float *)(iVar21 + (int)pfVar23) + *(float *)(iVar21 + (int)pfVar22);

              fVar6 = pfVar25[0x14];

              fVar8 = *(float *)(iVar21 + (int)pfVar22) - *(float *)(iVar21 + (int)pfVar23);

              fVar9 = *(float *)(iVar21 + (int)pfVar17) + *(float *)(iVar21 + (int)pfVar19);

              fVar11 = *(float *)(iVar21 + (int)pfVar19) - *(float *)(iVar21 + (int)pfVar17);

              fVar12 = *pfVar23 + *pfVar22;

              fVar13 = *pfVar22 - *pfVar23;

              fVar14 = *pfVar17 + *pfVar19;

              fVar15 = *pfVar19 - *pfVar17;

              fVar10 = fVar7 - fVar9;

              fVar16 = fVar12 - fVar14;

              *(float *)(iVar21 + (int)pfVar22) = fVar9 + fVar7;

              *pfVar22 = fVar14 + fVar12;

              *(float *)(iVar21 + (int)pfVar19) = fVar10 * fVar1 - fVar16 * fVar2;

              *pfVar19 = fVar16 * fVar1 + fVar10 * fVar2;

              fVar1 = fVar15 + fVar8;

              fVar2 = fVar13 - fVar11;

              fVar8 = fVar8 - fVar15;

              pfVar22 = pfVar22 + 1;

              pfVar19 = pfVar19 + 1;

              local_18 = local_18 + -1;

              fVar13 = fVar13 + fVar11;

              *(float *)(iVar21 + -4 + (int)(pfVar23 + 1)) = fVar1 * fVar3 - fVar2 * fVar4;

              *pfVar23 = fVar2 * fVar3 + fVar1 * fVar4;

              *(float *)(iVar21 + -4 + (int)(pfVar17 + 1)) = fVar8 * fVar5 - fVar13 * fVar6;

              *pfVar17 = fVar13 * fVar5 + fVar8 * fVar6;

              pfVar17 = pfVar17 + 1;

              pfVar23 = pfVar23 + 1;

              pfVar24 = pfVar25 + 1;

            } while (local_18 != 0);

            local_68 = local_68 + -0x10;

            local_3c = local_3c + -4;

            pfVar24 = pfVar25 + 0x15;

            local_14 = local_14 - 1;

          } while (local_14 != 0);

        }

        local_68 = local_68 + uVar20 * -0xc;

        local_3c = local_3c + uVar20 * -3;

        local_c = local_c + -1;

      } while (local_c != 0);

    }

    iVar18 = param_3 + (param_3 >> 0x1f & 3U);

    iVar21 = iVar18 >> 2;

    param_3 = local_8 << 2;

    pfVar24 = pfVar24 + (iVar18 >> 6) * 0x18;

    iVar18 = param_3;

  } while (4 < iVar21);

  pfVar24 = (float *)(local_8 * 0x40 + -0x10 + param_1);

  if (param_3 != 0) {

    pfVar19 = (float *)((int)pfVar24 + param_2 + (4 - param_1));

    do {

      fVar1 = *(float *)((param_1 - param_2) + (int)pfVar19);

      fVar2 = pfVar24[2] + *pfVar24;

      fVar3 = *pfVar24 - pfVar24[2];

      fVar4 = pfVar19[1] + pfVar19[-1];

      fVar5 = pfVar19[-1] - pfVar19[1];

      param_3 = param_3 + -1;

      fVar6 = pfVar24[3] + fVar1;

      fVar1 = fVar1 - pfVar24[3];

      fVar7 = pfVar19[2] + *pfVar19;

      fVar8 = *pfVar19 - pfVar19[2];

      *pfVar24 = fVar6 + fVar2;

      pfVar19[-1] = fVar7 + fVar4;

      pfVar24[2] = fVar8 + fVar3;

      pfVar19[1] = fVar5 - fVar1;

      *(float *)((param_1 - param_2) + 0x10 + (int)(pfVar19 + -4)) = fVar2 - fVar6;

      *pfVar19 = fVar4 - fVar7;

      pfVar24[3] = fVar3 - fVar8;

      pfVar19[2] = fVar5 + fVar1;

      pfVar19 = pfVar19 + -4;

      pfVar24 = pfVar24 + -4;

    } while (param_3 != 0);

  }

  FUN_00717630(param_1,param_2,local_8 * 0x10);

  return;

}
