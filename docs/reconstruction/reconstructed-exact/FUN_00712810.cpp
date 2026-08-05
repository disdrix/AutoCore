// =============================================================================
// FUN_00712810
// -----------------------------------------------------------------------------
// Stable ID: aa_00712810
// Address:   0x00712810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712810 @ 0x00712810
// Stable ID: aa_00712810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00712810.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00712810(int *param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  

  if ((short)param_1[2] < 0x55) {

    iVar2 = 0;

    iVar3 = 0x21;

    do {

      pfVar1 = (float *)(*param_1 + iVar2);

      iVar2 = iVar2 + 4;

      iVar3 = iVar3 + -1;

      *pfVar1 = *pfVar1 * _DAT_00a0f6d8;

    } while (iVar3 != 0);

    *(short *)(param_1 + 2) = (short)param_1[2] + 1;

    return;

  }

  *(uint16_t *)(param_1 + 2) = 0x54;

  *(short *)(param_1 + 2) = (short)param_1[2] + 1;

  return;

}
