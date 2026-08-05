// =============================================================================
// FUN_006bb0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bb0c0
// Address:   0x006bb0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bb0c0 @ 0x006bb0c0
// Stable ID: aa_006bb0c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_006bb0c0.
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

void FUN_006bb0c0(int *param_1,float *param_2)



{

  float fVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  

  if (0 < param_1[1]) {

    pfVar2 = (float *)*param_1;

    fVar1 = pfVar2[1];

    fVar3 = pfVar2[2];

    fVar4 = pfVar2[3];

    *param_2 = *pfVar2;

    param_2[1] = fVar1;

    param_2[2] = fVar3;

    param_2[3] = fVar4;

    pfVar2 = (float *)*param_1;

    fVar1 = pfVar2[1];

    fVar3 = pfVar2[2];

    fVar4 = pfVar2[3];

    param_2[4] = *pfVar2;

    param_2[5] = fVar1;

    param_2[6] = fVar3;

    param_2[7] = fVar4;

    iVar6 = 0;

    if (0 < param_1[1]) {

      iVar5 = 0;

      do {

        fVar1 = *(float *)(iVar5 + *param_1);

        if (*param_2 < *(float *)(iVar5 + *param_1)) {

          fVar1 = *param_2;

        }

        *param_2 = fVar1;

        fVar1 = *(float *)(iVar5 + *param_1);

        if (*(float *)(iVar5 + *param_1) < param_2[4]) {

          fVar1 = param_2[4];

        }

        param_2[4] = fVar1;

        fVar1 = *(float *)(iVar5 + 4 + *param_1);

        if (param_2[1] < fVar1) {

          fVar1 = param_2[1];

        }

        param_2[1] = fVar1;

        fVar1 = *(float *)(iVar5 + 4 + *param_1);

        if (fVar1 < param_2[5]) {

          fVar1 = param_2[5];

        }

        param_2[5] = fVar1;

        fVar1 = *(float *)(iVar5 + 8 + *param_1);

        if (param_2[2] < fVar1) {

          fVar1 = param_2[2];

        }

        param_2[2] = fVar1;

        fVar1 = *(float *)(iVar5 + 8 + *param_1);

        if (fVar1 < param_2[6]) {

          fVar1 = param_2[6];

        }

        param_2[6] = fVar1;

        iVar6 = iVar6 + 1;

        iVar5 = iVar5 + 0x10;

      } while (iVar6 < param_1[1]);

    }

  }

  return;

}
