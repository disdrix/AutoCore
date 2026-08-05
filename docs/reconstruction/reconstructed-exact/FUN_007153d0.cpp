// =============================================================================
// FUN_007153d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007153d0
// Address:   0x007153d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007153d0 @ 0x007153d0
// Stable ID: aa_007153d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, for×2, while×2, return×1.
//  - Notable callees: FUN_007153d0, FUN_00715500, FUN_007159e0, FUN_00715a00, ROUND, ftol.
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

void FUN_007153d0(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5,

                 uint32_t /* width from decompiler */ param_6,float param_7)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_598 [256];

  float local_198 [100];

  int local_8;

  

  iVar3 = FUN_00715500(param_1,param_2,param_3,param_4,param_6,local_198,local_598,param_7);

  iVar7 = 0;

  iVar8 = 0;

  local_8 = iVar3;

  fVar9 = (float10)FUN_007159e0(local_198[0]);

  fVar9 = (float10)FUN_00715a00((float)(fVar9 - (float10)DAT_00a10e78));

  param_7 = (float)fVar9;

  param_2 = 0;

  iVar4 = iVar7;

  fVar2 = g_flZero;

  if (0 < iVar3) {

    do {

      fVar1 = local_198[param_2 + -0x100];

      iVar7 = (int)ROUND((fVar1 + fVar2) * DAT_00a0f298);

      iVar8 = iVar4;

      if (iVar4 < iVar7) {

        iVar6 = iVar7 - iVar4;

        iVar8 = iVar4 + iVar6;

        pfVar5 = (float *)(param_5 + iVar4 * 4);

        for (; iVar3 = local_8, iVar6 != 0; iVar6 = iVar6 + -1) {

          *pfVar5 = param_7;

          pfVar5 = pfVar5 + 1;

        }

      }

      param_7 = local_198[param_2];

      param_2 = param_2 + 1;

      iVar4 = iVar7;

      fVar2 = fVar1;

    } while (param_2 < iVar3);

  }

  iVar4 = ftol();

  iVar7 = iVar7 + iVar4;

  if (0x100 < iVar7) {

    iVar7 = 0x100;

  }

  if (iVar8 < iVar7) {

    pfVar5 = (float *)(param_5 + iVar8 * 4);

    for (iVar4 = iVar7 - iVar8; iVar4 != 0; iVar4 = iVar4 + -1) {

      *pfVar5 = param_7;

      pfVar5 = pfVar5 + 1;

    }

  }

  if (iVar7 < 0x100) {

    iVar4 = 0x100 - iVar7;

    pfVar5 = (float *)(param_5 + iVar7 * 4);

    do {

      iVar4 = iVar4 + -1;

      *pfVar5 = pfVar5[-1] * DAT_00a111a8;

      pfVar5 = pfVar5 + 1;

    } while (iVar4 != 0);

  }

  return;

}
