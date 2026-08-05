// =============================================================================
// FUN_00715340
// -----------------------------------------------------------------------------
// Stable ID: aa_00715340
// Address:   0x00715340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00715340 @ 0x00715340
// Stable ID: aa_00715340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_00715340.
//  - Return sites: 3.

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

void FUN_00715340(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  

  param_2 = param_2 + 1;

  iVar3 = 0;

  if (param_3 + -1 <= param_2) {

    *param_6 = 0;

    return;

  }

  pfVar1 = (float *)(param_1 + param_2 * 4);

  pfVar2 = (float *)(param_1 + 4 + param_2 * 4);

  do {

    if ((pfVar1[-1] <= *pfVar1) && (*pfVar2 < *pfVar1)) {

      *param_5 = param_2;

      param_5 = param_5 + 1;

      param_2 = param_2 + 1;

      pfVar1 = pfVar1 + 1;

      pfVar2 = pfVar2 + 1;

      iVar3 = iVar3 + 1;

      if (iVar3 == param_4) {

        *param_6 = iVar3;

        return;

      }

    }

    param_2 = param_2 + 1;

    pfVar1 = pfVar1 + 1;

    pfVar2 = pfVar2 + 1;

  } while (param_2 < param_3 + -1);

  *param_6 = iVar3;

  return;

}
