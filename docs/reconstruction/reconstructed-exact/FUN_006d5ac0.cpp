// =============================================================================
// FUN_006d5ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d5ac0
// Address:   0x006d5ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d5ac0 @ 0x006d5ac0
// Stable ID: aa_006d5ac0
// Embedded strings (evidence for future rename):
//   - "TtMultiSphereTri"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~249 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, goto×1, return×1.
//  - Notable callees: rdtsc×2, FUN_005b3300, FUN_006d5ac0, FUN_006f7820.
//  - Strings: "TtMultiSphereTri".
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

void __thiscall FUN_006d5ac0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint64_t uVar8;

  int iVar9;

  short sVar10;

  float *pfVar11;

  float *pfVar12;

  float *pfVar13;

  int iVar14;

  float *pfVar15;

  uint uVar16;

  int iVar17;

  float *pfVar18;

  short *local_fc;

  float *local_f8;

  uint local_f4;

  float local_e0;

  float local_dc;

  float local_d8;

  uint32_t /* width from decompiler */ local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  uint32_t /* width from decompiler */ local_c4;

  float local_c0;

  float local_bc;

  float local_b8;

  uint32_t /* width from decompiler */ local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_90 [35];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtMultiSphereTri";

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_3;

  fVar1 = *(float *)(iVar4 + 0x10);

  iVar5 = param_3[2];

  fVar2 = *(float *)(iVar4 + 0x14);

  pfVar11 = (float *)(iVar5 + 0x20);

  fVar3 = *(float *)(iVar4 + 0x18);

  iVar6 = *param_2;

  local_e0 = fVar1 * *pfVar11 + fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40)

             + *(float *)(iVar5 + 0x50);

  local_dc = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_d8 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  local_d4 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_d0 = fVar1 * *pfVar11 + fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40)

             + *(float *)(iVar5 + 0x50);

  local_cc = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_c8 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  local_c4 = 0;

  fVar1 = *(float *)(iVar4 + 0x30);

  fVar2 = *(float *)(iVar4 + 0x34);

  fVar3 = *(float *)(iVar4 + 0x38);

  pfVar13 = (float *)(iVar6 + 0x10);

  pfVar18 = local_90;

  local_c0 = fVar1 * *pfVar11 + fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40)

             + *(float *)(iVar5 + 0x50);

  local_bc = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_b8 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  iVar5 = param_2[2];

  local_b4 = 0;

  pfVar11 = (float *)(iVar5 + 0x20);

  local_f4 = *(uint *)(iVar6 + 0xc);

  iVar14 = local_f4 - 1;

  local_fc = (short *)iVar14;

  if (3 < (int)local_f4) {

    uVar16 = local_f4 >> 2;

    local_fc = (short *)(iVar14 + uVar16 * -4);

    pfVar12 = pfVar13;

    pfVar15 = local_90 + 6;

    do {

      fVar1 = *pfVar12;

      fVar2 = pfVar12[1];

      fVar3 = pfVar12[2];

      *pfVar18 = fVar1 * *pfVar11 +

                 fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40) +

                 *(float *)(iVar5 + 0x50);

      pfVar15[-5] = fVar1 * *(float *)(iVar5 + 0x24) +

                    fVar2 * *(float *)(iVar5 + 0x34) + fVar3 * *(float *)(iVar5 + 0x44) +

                    *(float *)(iVar5 + 0x54);

      pfVar15[-4] = fVar1 * *(float *)(iVar5 + 0x28) +

                    fVar2 * *(float *)(iVar5 + 0x38) + fVar3 * *(float *)(iVar5 + 0x48) +

                    *(float *)(iVar5 + 0x58);

      pfVar15[-3] = 0.0;

      fVar1 = pfVar12[4];

      fVar2 = pfVar12[5];

      fVar3 = pfVar12[6];

      pfVar15[-2] = fVar1 * *pfVar11 +

                    fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40) +

                    *(float *)(iVar5 + 0x50);

      pfVar15[-1] = fVar1 * *(float *)(iVar5 + 0x24) +

                    fVar2 * *(float *)(iVar5 + 0x34) + fVar3 * *(float *)(iVar5 + 0x44) +

                    *(float *)(iVar5 + 0x54);

      *pfVar15 = fVar1 * *(float *)(iVar5 + 0x28) +

                 fVar2 * *(float *)(iVar5 + 0x38) + fVar3 * *(float *)(iVar5 + 0x48) +

                 *(float *)(iVar5 + 0x58);

      pfVar15[1] = 0.0;

      fVar1 = pfVar12[8];

      fVar2 = pfVar12[9];

      fVar3 = pfVar12[10];

      pfVar15[2] = fVar1 * *pfVar11 +

                   fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40) +

                   *(float *)(iVar5 + 0x50);

      pfVar18 = pfVar18 + 0x10;

      pfVar13 = pfVar12 + 0x10;

      uVar16 = uVar16 - 1;

      pfVar15[3] = fVar1 * *(float *)(iVar5 + 0x24) +

                   fVar2 * *(float *)(iVar5 + 0x34) + fVar3 * *(float *)(iVar5 + 0x44) +

                   *(float *)(iVar5 + 0x54);

      pfVar15[4] = fVar1 * *(float *)(iVar5 + 0x28) +

                   fVar2 * *(float *)(iVar5 + 0x38) + fVar3 * *(float *)(iVar5 + 0x48) +

                   *(float *)(iVar5 + 0x58);

      pfVar15[5] = 0.0;

      fVar1 = pfVar12[0xc];

      fVar2 = pfVar12[0xd];

      fVar3 = pfVar12[0xe];

      pfVar15[6] = fVar1 * *pfVar11 +

                   fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40) +

                   *(float *)(iVar5 + 0x50);

      pfVar15[7] = fVar1 * *(float *)(iVar5 + 0x24) +

                   fVar2 * *(float *)(iVar5 + 0x34) + fVar3 * *(float *)(iVar5 + 0x44) +

                   *(float *)(iVar5 + 0x54);

      pfVar15[8] = fVar1 * *(float *)(iVar5 + 0x28) +

                   fVar2 * *(float *)(iVar5 + 0x38) + fVar3 * *(float *)(iVar5 + 0x48) +

                   *(float *)(iVar5 + 0x58);

      pfVar15[9] = 0.0;

      pfVar12 = pfVar13;

      pfVar15 = pfVar15 + 0x10;

    } while (uVar16 != 0);

  }

  if (-1 < (int)local_fc) {

    iVar17 = (int)local_fc + 1;

    do {

      fVar1 = *pfVar13;

      fVar2 = pfVar13[1];

      iVar17 = iVar17 + -1;

      fVar3 = pfVar13[2];

      *pfVar18 = fVar1 * *pfVar11 +

                 fVar2 * *(float *)(iVar5 + 0x30) + fVar3 * *(float *)(iVar5 + 0x40) +

                 *(float *)(iVar5 + 0x50);

      pfVar18[1] = fVar1 * *(float *)(iVar5 + 0x24) +

                   fVar2 * *(float *)(iVar5 + 0x34) + fVar3 * *(float *)(iVar5 + 0x44) +

                   *(float *)(iVar5 + 0x54);

      pfVar18[2] = fVar1 * *(float *)(iVar5 + 0x28) +

                   fVar2 * *(float *)(iVar5 + 0x38) + fVar3 * *(float *)(iVar5 + 0x48) +

                   *(float *)(iVar5 + 0x58);

      pfVar18[3] = 0.0;

      pfVar13 = pfVar13 + 4;

      pfVar18 = pfVar18 + 4;

    } while (iVar17 != 0);

  }

  iVar5 = *param_5;

  iVar17 = *(int *)(iVar5 + 4) + local_f4;

  uVar16 = *(uint *)(iVar5 + 8) & 0x7fffffff;

  if ((int)uVar16 < iVar17) {

    iVar9 = uVar16 * 2;

    if (iVar17 < iVar9) {

      iVar17 = iVar9;

    }

    FUN_005b3300(iVar5,iVar17,0x30);

  }

  if (-1 < iVar14) {

    local_f8 = (float *)(iVar6 + 0x1c);

    local_fc = (short *)(param_1 + 0x1c + iVar14 * 2);

    pfVar13 = local_90 + 2;

    do {

      fVar1 = *local_f8;

      fVar2 = fVar1 + *(float *)(iVar4 + 0xc);

      FUN_006f7820(pfVar13 + -2,&local_e0,param_1 + 0xc,&local_b0);

      if (fVar2 + *(float *)(param_4 + 8) <= local_a0) {

        if (*local_fc != -1) {

          (**(code **)(**(int **)(param_1 + 8) + 8))(*local_fc);

          *local_fc = -1;

        }

      }

      else {

        piVar7 = (int *)*param_5;

        fVar1 = -fVar1;

        iVar5 = piVar7[1];

        piVar7[1] = iVar5 + 1;

        pfVar18 = (float *)(iVar5 * 0x30 + *piVar7);

        *pfVar18 = pfVar13[-2];

        pfVar18[1] = pfVar13[-1];

        pfVar18[2] = *pfVar13;

        pfVar18[3] = pfVar13[1];

        *pfVar18 = local_b0 * fVar1 + *pfVar18;

        pfVar18[1] = local_ac * fVar1 + pfVar18[1];

        pfVar18[2] = local_a8 * fVar1 + pfVar18[2];

        pfVar18[3] = local_a4 * fVar1 + pfVar18[3];

        pfVar18[4] = local_b0;

        pfVar18[5] = local_ac;

        pfVar18[6] = local_a8;

        pfVar18[7] = local_a4;

        pfVar18[3] = local_a0 - fVar2;

        sVar10 = *local_fc;

        if (sVar10 == -1) {

          sVar10 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,pfVar18);

          *local_fc = sVar10;

          if (sVar10 == -1) {

            *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

            goto LAB_006d5fe2;

          }

        }

        *(short *)(pfVar18 + 8) = sVar10;

      }

LAB_006d5fe2:

      local_f8 = local_f8 + 4;

      local_fc = local_fc + -1;

      pfVar13 = pfVar13 + 4;

      local_f4 = local_f4 - 1;

    } while (local_f4 != 0);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
