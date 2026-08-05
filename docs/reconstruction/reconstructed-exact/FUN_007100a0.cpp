// =============================================================================
// FUN_007100a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007100a0
// Address:   0x007100a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007100a0 @ 0x007100a0
// Stable ID: aa_007100a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_007100a0.
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

int FUN_007100a0(int param_1,float *param_2,int param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float local_8;

  int local_4;

  

  iVar6 = 0;

  local_8 = 0.0;

  local_4 = 0;

  iVar5 = 0;

  if (0 < param_4) {

    do {

      iVar5 = 0;

      fVar2 = g_flZero;

      if (3 < param_3) {

        iVar7 = (param_3 - 4U >> 2) + 1;

        iVar5 = iVar7 * 4;

        pfVar3 = (float *)(param_1 + 8);

        pfVar4 = param_2;

        do {

          param_2 = pfVar4 + 4;

          iVar7 = iVar7 + -1;

          fVar2 = (pfVar3[1] - pfVar4[3]) * (pfVar3[1] - pfVar4[3]) +

                  (*pfVar3 - pfVar4[2]) * (*pfVar3 - pfVar4[2]) +

                  (pfVar3[-1] - pfVar4[1]) * (pfVar3[-1] - pfVar4[1]) +

                  (pfVar3[-2] - *pfVar4) * (pfVar3[-2] - *pfVar4) + fVar2;

          pfVar3 = pfVar3 + 4;

          pfVar4 = param_2;

        } while (iVar7 != 0);

      }

      for (; iVar5 < param_3; iVar5 = iVar5 + 1) {

        fVar1 = *(float *)(param_1 + iVar5 * 4) - *param_2;

        param_2 = param_2 + 1;

        fVar2 = fVar1 * fVar1 + fVar2;

      }

      iVar5 = iVar6;

      if ((iVar6 != 0) && (local_8 <= fVar2)) {

        fVar2 = local_8;

        iVar5 = local_4;

      }

      local_4 = iVar5;

      local_8 = fVar2;

      iVar6 = iVar6 + 1;

      iVar5 = local_4;

    } while (iVar6 < param_4);

  }

  return iVar5;

}
