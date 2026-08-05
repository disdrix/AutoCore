// =============================================================================
// FUN_00716600
// -----------------------------------------------------------------------------
// Stable ID: aa_00716600
// Address:   0x00716600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716600 @ 0x00716600
// Stable ID: aa_00716600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_007159e0, FUN_00716600.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00716600(float param_1,uint32_t /* width from decompiler */ param_2)



{

  float *pfVar1;

  int iVar2;

  float10 fVar3;

  

  iVar2 = 0;

  pfVar1 = (float *)&DAT_00a1283c;

  do {

    if (*pfVar1 < param_1) break;

    pfVar1 = pfVar1 + 1;

    iVar2 = iVar2 + 1;

  } while ((int)pfVar1 < 0xa12850);

  fVar3 = (float10)FUN_007159e0(param_2);

  return (fVar3 * (float10)DAT_00a0f298 + (float10)*(float *)(&UNK_00a12824 + iVar2 * 4)) -

         (float10)_DAT_00a1285c;

}
