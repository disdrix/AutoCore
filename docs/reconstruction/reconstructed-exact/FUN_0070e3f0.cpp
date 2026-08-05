// =============================================================================
// FUN_0070e3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e3f0
// Address:   0x0070e3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e3f0 @ 0x0070e3f0
// Stable ID: aa_0070e3f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0070e3f0.
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

void FUN_0070e3f0(int param_1,int param_2,float param_3,int param_4)



{

  float *pfVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  

  iVar4 = 0;

  if (3 < param_4) {

    iVar2 = (param_4 - 4U >> 2) + 1;

    iVar4 = iVar2 * 4;

    pfVar1 = (float *)(param_2 + 4);

    pfVar3 = (float *)(param_1 + 0xc);

    do {

      iVar2 = iVar2 + -1;

      pfVar1[-1] = param_3 * pfVar3[-3];

      *pfVar1 = param_3 * *(float *)((param_1 - param_2) + -0x10 + (int)(pfVar1 + 4));

      pfVar1[1] = param_3 * pfVar3[-1];

      pfVar1[2] = param_3 * *pfVar3;

      pfVar1 = pfVar1 + 4;

      pfVar3 = pfVar3 + 4;

    } while (iVar2 != 0);

  }

  if (iVar4 < param_4) {

    param_4 = param_4 - iVar4;

    pfVar1 = (float *)(param_2 + iVar4 * 4);

    do {

      param_4 = param_4 + -1;

      *pfVar1 = param_3 * *(float *)((int)pfVar1 + (param_1 - param_2));

      pfVar1 = pfVar1 + 1;

    } while (param_4 != 0);

  }

  return;

}
