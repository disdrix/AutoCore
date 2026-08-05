// =============================================================================
// FUN_0070e350
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e350
// Address:   0x0070e350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e350 @ 0x0070e350
// Stable ID: aa_0070e350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0070e350.
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

void FUN_0070e350(float param_1,int param_2,int param_3,int param_4)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = 0;

  iVar6 = param_4 + 1;

  fVar1 = g_flOne;

  if (3 < iVar6) {

    iVar3 = (param_4 - 3U >> 2) + 1;

    iVar5 = iVar3 * 4;

    pfVar2 = (float *)(param_3 + 4);

    pfVar4 = (float *)(param_2 + 0xc);

    do {

      iVar3 = iVar3 + -1;

      pfVar2[-1] = fVar1 * pfVar4[-3];

      *pfVar2 = fVar1 * param_1 * *(float *)((param_2 - param_3) + -0x10 + (int)(pfVar2 + 4));

      fVar1 = fVar1 * param_1 * param_1;

      pfVar2[1] = fVar1 * pfVar4[-1];

      fVar1 = fVar1 * param_1;

      pfVar2[2] = fVar1 * *pfVar4;

      fVar1 = fVar1 * param_1;

      pfVar2 = pfVar2 + 4;

      pfVar4 = pfVar4 + 4;

    } while (iVar3 != 0);

  }

  if (iVar5 < iVar6) {

    iVar6 = iVar6 - iVar5;

    pfVar2 = (float *)(param_3 + iVar5 * 4);

    do {

      iVar6 = iVar6 + -1;

      *pfVar2 = fVar1 * *(float *)((int)pfVar2 + (param_2 - param_3));

      fVar1 = fVar1 * param_1;

      pfVar2 = pfVar2 + 1;

    } while (iVar6 != 0);

  }

  return;

}
