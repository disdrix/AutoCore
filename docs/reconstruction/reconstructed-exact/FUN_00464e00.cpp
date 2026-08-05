// =============================================================================
// FUN_00464e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00464e00
// Address:   0x00464e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00464e00 @ 0x00464e00
// Stable ID: aa_00464e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×2.
//  - Notable callees: FUN_00464e00.
//  - Return sites: 2.

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

void FUN_00464e00(void)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int unaff_EDI;

  float fVar5;

  

  iVar3 = *(int *)(unaff_EDI + 0x14);

  fVar5 = 0.0;

  iVar4 = 1;

  if (3 < iVar3 + -1) {

    pfVar1 = (float *)(*(int *)(unaff_EDI + 0xc) + 0xc);

    iVar2 = (iVar3 - 5U >> 2) + 1;

    iVar4 = iVar2 * 4 + 1;

    do {

      fVar5 = pfVar1[-2] + fVar5 + pfVar1[-1] + *pfVar1 + pfVar1[1];

      pfVar1 = pfVar1 + 4;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  if (iVar4 < iVar3) {

    pfVar1 = (float *)(*(int *)(unaff_EDI + 0xc) + iVar4 * 4);

    iVar3 = iVar3 - iVar4;

    do {

      fVar5 = fVar5 + *pfVar1;

      pfVar1 = pfVar1 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  if (g_flOne <= fVar5) {

    return;

  }

  return;

}
