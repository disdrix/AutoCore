// =============================================================================
// FUN_00713300
// -----------------------------------------------------------------------------
// Stable ID: aa_00713300
// Address:   0x00713300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713300 @ 0x00713300
// Stable ID: aa_00713300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00713300.
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

int FUN_00713300(float *param_1,float *param_2,int param_3)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  

  iVar2 = 0;

  iVar4 = 0;

  if (0 < param_3) {

    fVar3 = 1e+38;

    do {

      fVar1 = (param_2[1] - param_1[1]) * (param_2[1] - param_1[1]) +

              (*param_2 - *param_1) * (*param_2 - *param_1);

      if ((int)fVar1 < (int)fVar3) {

        iVar2 = iVar4;

        fVar3 = fVar1;

      }

      iVar4 = iVar4 + 1;

      param_2 = param_2 + 2;

    } while (iVar4 < param_3);

  }

  return iVar2;

}
