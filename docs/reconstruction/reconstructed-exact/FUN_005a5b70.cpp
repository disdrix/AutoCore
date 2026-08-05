// =============================================================================
// FUN_005a5b70
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5b70
// Address:   0x005a5b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a5b70 @ 0x005a5b70
// Stable ID: aa_005a5b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: block×2, FUN_005a5b70, SQRT.
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

/* WARNING: Removing unreachable block (ram,0x005a5cc3) */

/* WARNING: Removing unreachable block (ram,0x005a5cdd) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005a5b70(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  uint uVar5;

  float *pfVar6;

  float *pfVar7;

  uint uVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  int local_4c;

  

  fVar4 = DAT_009d81fc;

  pfVar7 = (float *)*param_2;

  local_4c = param_2[1];

  if (-1 < local_4c + -1) {

    pfVar6 = (float *)(param_3 + 8);

    do {

      pfVar6[-1] = g_flOne;

      pfVar6[1] = DAT_009d81e0;

      pfVar6[-2] = 0.0;

      *pfVar6 = 0.0;

      fVar1 = *(float *)(param_1 + 0x34);

      fVar2 = pfVar7[1];

      iVar3 = *(int *)(param_1 + 0xc);

      uVar5 = (uint)(*(float *)(param_1 + 0x30) * (*(float *)(param_1 + 0x40) + *pfVar7) + fVar4) >>

              6 & 0xffff;

      uVar8 = (uint)(*(float *)(param_1 + 0x38) * (*(float *)(param_1 + 0x48) + pfVar7[2]) + fVar4)

              >> 6 & 0xffff;

      if ((uVar5 < iVar3 - 1U) && (uVar8 < *(int *)(param_1 + 0x10) - 1U)) {

        fVar11 = *pfVar7 * *(float *)(param_1 + 0x30) - (float)uVar5;

        fVar13 = *(float *)(param_1 + 0x38) * pfVar7[2] - (float)uVar8;

        fVar12 = (float)*(ushort *)

                         (*(int *)(param_1 + 0x60) + 2 +

                         (*(int *)(param_1 + 0xc) * uVar8 + uVar5) * 2) * DAT_009d81dc;

        fVar14 = (float)*(ushort *)

                         (*(int *)(param_1 + 0x60) +

                         (*(int *)(param_1 + 0xc) * (uVar8 + 1) + uVar5) * 2) * DAT_009d81dc;

        if (fVar13 + fVar11 <= g_flOne) {

          fVar9 = (float)*(ushort *)(*(int *)(param_1 + 0x60) + (iVar3 * uVar8 + uVar5) * 2) *

                  DAT_009d81dc;

          fVar10 = fVar14 - fVar9;

          fVar11 = fVar10 * fVar13 + (fVar12 - fVar9) * fVar11 + fVar9;

          pfVar6[-2] = 0.0 - (fVar12 - fVar9);

        }

        else {

          fVar9 = (float)*(ushort *)

                          (*(int *)(param_1 + 0x60) + 2 + ((uVar8 + 1) * iVar3 + uVar5) * 2) *

                  DAT_009d81dc;

          fVar10 = fVar9 - fVar12;

          fVar9 = fVar9 - fVar14;

          fVar11 = (fVar11 - g_flOne) * fVar9 + fVar10 * fVar13 + fVar12;

          pfVar6[-2] = 0.0 - fVar9;

        }

        *pfVar6 = 0.0 - fVar10;

        pfVar6[-2] = *(float *)(param_1 + 0x30) * pfVar6[-2];

        pfVar6[-1] = *(float *)(param_1 + 0x34) * pfVar6[-1];

        *pfVar6 = *(float *)(param_1 + 0x38) * *pfVar6;

        pfVar6[1] = *(float *)(param_1 + 0x3c) * pfVar6[1];

        fVar13 = *pfVar6 * *pfVar6 + pfVar6[-2] * pfVar6[-2] + pfVar6[-1] * pfVar6[-1];

        if (fVar13 == 0.0) {

          fVar13 = 0.0;

        }

        else {

          fVar13 = g_flOne / SQRT(fVar13);

        }

        pfVar6[-2] = fVar13 * pfVar6[-2];

        pfVar6[-1] = fVar13 * pfVar6[-1];

        *pfVar6 = fVar13 * *pfVar6;

        pfVar6[1] = pfVar6[1] * fVar13;

        pfVar6[1] = (fVar1 * fVar2 - fVar11) * *(float *)(param_1 + 0x24) - pfVar7[3];

      }

      pfVar6 = pfVar6 + 4;

      pfVar7 = pfVar7 + 4;

      local_4c = local_4c + -1;

    } while (local_4c != 0);

  }

  return;

}
