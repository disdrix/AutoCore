// =============================================================================
// FUN_006f60b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f60b0
// Address:   0x006f60b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f60b0 @ 0x006f60b0
// Stable ID: aa_006f60b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006f60b0.
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

void FUN_006f60b0(int param_1,int param_2,int param_3,float param_4,int param_5,int *param_6,

                 int *param_7,int *param_8)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int *piVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  float *pfVar16;

  float *pfVar17;

  float *local_6c;

  int local_68;

  

  fVar1 = *(float *)(*(int *)(param_3 + 0xc) + 8);

  piVar5 = (int *)*param_7;

  iVar14 = piVar5[1];

  iVar15 = *param_6 + iVar14;

  local_68 = 0;

  if ((int)(piVar5[2] & 0x7fffffffU) < iVar15) {

    iVar13 = (piVar5[2] & 0x7fffffffU) * 2;

    if (iVar13 <= iVar15) {

      iVar13 = iVar15;

    }

    FUN_005b3300(piVar5,iVar13,0x30);

  }

  piVar5[1] = iVar15;

  local_6c = (float *)(iVar14 * 0x30 + *piVar5);

  if (0 < *param_6) {

    pfVar17 = local_6c + 6;

    pfVar16 = (float *)(param_5 + 0x18);

    do {

      fVar2 = pfVar16[-6];

      fVar3 = pfVar16[-5];

      iVar14 = *(int *)(param_1 + 8);

      fVar4 = pfVar16[-4];

      iVar15 = *(int *)(param_2 + 8);

      fVar8 = fVar2 * *(float *)(iVar14 + 0x20) +

              fVar3 * *(float *)(iVar14 + 0x30) + fVar4 * *(float *)(iVar14 + 0x40) +

              *(float *)(iVar14 + 0x50);

      fVar7 = fVar2 * *(float *)(iVar14 + 0x24) +

              fVar3 * *(float *)(iVar14 + 0x34) + fVar4 * *(float *)(iVar14 + 0x44) +

              *(float *)(iVar14 + 0x54);

      fVar6 = fVar2 * *(float *)(iVar14 + 0x28) +

              fVar3 * *(float *)(iVar14 + 0x38) + fVar4 * *(float *)(iVar14 + 0x48) +

              *(float *)(iVar14 + 0x58);

      fVar2 = pfVar16[-2];

      fVar3 = pfVar16[-1];

      fVar4 = *pfVar16;

      fVar10 = fVar2 * *(float *)(iVar15 + 0x20) +

               fVar3 * *(float *)(iVar15 + 0x30) + fVar4 * *(float *)(iVar15 + 0x40) +

               *(float *)(iVar15 + 0x50);

      fVar9 = fVar2 * *(float *)(iVar15 + 0x24) +

              fVar3 * *(float *)(iVar15 + 0x34) + fVar4 * *(float *)(iVar15 + 0x44) +

              *(float *)(iVar15 + 0x54);

      fVar2 = fVar2 * *(float *)(iVar15 + 0x28) +

              fVar3 * *(float *)(iVar15 + 0x38) + fVar4 * *(float *)(iVar15 + 0x48) +

              *(float *)(iVar15 + 0x58);

      fVar3 = (fVar6 - fVar2) * pfVar16[4] +

              (fVar8 - fVar10) * pfVar16[2] + (fVar7 - fVar9) * pfVar16[3];

      fVar4 = fVar8 - (fVar3 * pfVar16[2] + fVar10);

      fVar11 = fVar7 - (fVar3 * pfVar16[3] + fVar9);

      fVar12 = fVar6 - (fVar3 * pfVar16[4] + fVar2);

      if (((*(float *)(param_3 + 8) <= fVar3) || (fVar3 <= param_4)) ||

         (fVar1 * fVar1 <= fVar4 * fVar4 + fVar11 * fVar11 + fVar12 * fVar12)) {

        (**(code **)(*param_8 + 8))(*(uint16_t *)(pfVar16 + 1));

        iVar14 = *param_6;

        *param_6 = iVar14 + -1;

        iVar14 = (iVar14 + -1) * 0x30;

        pfVar16[-6] = *(float *)(iVar14 + param_5);

        iVar14 = iVar14 + param_5;

        pfVar16[-5] = *(float *)(iVar14 + 4);

        pfVar16[-4] = *(float *)(iVar14 + 8);

        pfVar16[-3] = *(float *)(iVar14 + 0xc);

        pfVar16[-2] = *(float *)(iVar14 + 0x10);

        pfVar16[-1] = *(float *)(iVar14 + 0x14);

        *pfVar16 = *(float *)(iVar14 + 0x18);

        pfVar16[1] = *(float *)(iVar14 + 0x1c);

        pfVar16[2] = *(float *)(iVar14 + 0x20);

        pfVar16[3] = *(float *)(iVar14 + 0x24);

        pfVar16[4] = *(float *)(iVar14 + 0x28);

        pfVar16[5] = *(float *)(iVar14 + 0x2c);

        *(int *)(*param_7 + 4) = *(int *)(*param_7 + 4) + -1;

      }

      else {

        fVar4 = pfVar16[-3];

        fVar11 = g_flOne - fVar4;

        pfVar17[-4] = fVar6 * fVar4 + fVar2 * fVar11;

        pfVar17[-3] = (fVar11 + fVar4) * g_flZero;

        *local_6c = fVar4 * fVar8 + fVar11 * fVar10;

        pfVar17[-5] = fVar7 * fVar4 + fVar9 * fVar11;

        pfVar17[-2] = pfVar16[2];

        pfVar17[-1] = pfVar16[3];

        *pfVar17 = pfVar16[4];

        pfVar17[1] = pfVar16[5];

        pfVar17[-3] = fVar3;

        local_68 = local_68 + 1;

        *(uint16_t *)(pfVar17 + 2) = *(uint16_t *)(pfVar16 + 1);

        pfVar17 = pfVar17 + 0xc;

        pfVar16 = pfVar16 + 0xc;

        local_6c = local_6c + 0xc;

      }

    } while (local_68 < *param_6);

  }

  return;

}
