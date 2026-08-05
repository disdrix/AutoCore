// =============================================================================
// FUN_006c8400
// -----------------------------------------------------------------------------
// Stable ID: aa_006c8400
// Address:   0x006c8400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c8400 @ 0x006c8400
// Stable ID: aa_006c8400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: goto×10, if×8, do×1, switch×1, while×1, return×1.
//  - Notable callees: FUN_006c8400.
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

void __thiscall FUN_006c8400(int param_1,float *param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  byte bVar11;

  int iVar12;

  uint uVar13;

  uint uVar14;

  float *pfVar15;

  float *pfVar16;

  float local_50;

  float local_4c;

  float local_48;

  

  pfVar2 = *(float **)(param_1 + 0x30);

  iVar12 = *(int *)(param_1 + 0x34) << 2;

  uVar14 = 0;

  local_50 = -3.4028235e+38;

  local_4c = -3.4028235e+38;

  local_48 = -3.4028235e+38;

  if (0 < iVar12) {

    fVar3 = *param_2;

    fVar4 = param_2[1];

    fVar5 = param_2[2];

    pfVar16 = pfVar2 + 6;

    pfVar15 = pfVar2;

    uVar13 = 3;

    fVar10 = DAT_00aaa63c;

    do {

      fVar8 = fVar5 * pfVar16[2] + fVar4 * pfVar16[-2] + fVar3 * *pfVar15;

      fVar6 = fVar5 * pfVar16[3] + fVar4 * pfVar16[-1] + fVar3 * pfVar16[-5];

      fVar7 = fVar5 * pfVar16[4] + fVar4 * *pfVar16 + fVar3 * pfVar16[-4];

      fVar9 = fVar5 * pfVar16[5] + fVar4 * pfVar16[1] + fVar3 * pfVar16[-3];

      bVar11 = (local_48 < fVar7) << 1 | (local_4c < fVar6) << 2 | (local_50 < fVar8) << 3 |

               fVar10 < fVar9;

      if (bVar11 != 0) {

        switch(bVar11) {

        case 1:

          goto LAB_006c8627;

        case 2:

          goto code_r0x006c861e;

        case 4:

code_r0x006c8606:

          uVar14 = uVar13 - 2;

          local_50 = fVar6;

          local_4c = fVar6;

          local_48 = fVar6;

          fVar10 = fVar6;

          goto LAB_006c8639;

        case 7:

LAB_006c85e8:

          if (fVar7 < fVar6) {

            if (fVar9 < fVar6) goto code_r0x006c8606;

            goto LAB_006c8627;

          }

          goto LAB_006c860f;

        case 8:

          goto code_r0x006c85df;

        case 0xb:

          goto code_r0x006c85c1;

        }

        if (fVar8 <= fVar6) goto LAB_006c85e8;

code_r0x006c85c1:

        if (fVar7 < fVar8) {

          if (fVar8 <= fVar9) goto LAB_006c8627;

code_r0x006c85df:

          uVar14 = uVar13 - 3;

          local_50 = fVar8;

          local_4c = fVar8;

          local_48 = fVar8;

          fVar10 = fVar8;

        }

        else {

LAB_006c860f:

          if (fVar7 <= fVar9) {

LAB_006c8627:

            uVar14 = uVar13;

            local_50 = fVar9;

            local_4c = fVar9;

            local_48 = fVar9;

            fVar10 = fVar9;

          }

          else {

code_r0x006c861e:

            uVar14 = uVar13 - 1;

            local_50 = fVar7;

            local_4c = fVar7;

            local_48 = fVar7;

            fVar10 = fVar7;

          }

        }

      }

LAB_006c8639:

      pfVar15 = pfVar15 + 0xc;

      iVar1 = uVar13 + 1;

      pfVar16 = pfVar16 + 0xc;

      uVar13 = uVar13 + 4;

    } while (iVar1 < iVar12);

  }

  iVar12 = (int)uVar14 >> 2;

  uVar13 = uVar14 & 3;

  *param_3 = pfVar2[iVar12 * 0xc + uVar13];

  param_3[1] = pfVar2[iVar12 * 0xc + uVar13 + 4];

  param_3[2] = pfVar2[iVar12 * 0xc + uVar13 + 8];

  param_3[3] = (float)(uVar14 | 0x3f000000);

  return;

}
