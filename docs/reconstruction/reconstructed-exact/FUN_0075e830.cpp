// =============================================================================
// FUN_0075e830
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e830
// Address:   0x0075e830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075e830 @ 0x0075e830
// Stable ID: aa_0075e830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0075e360, FUN_0075e830, _CIpow.
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

void FUN_0075e830(uint32_t /* width from decompiler */ param_1)



{

  float *pfVar1;

  int iVar2;

  float10 fVar3;

  float local_bfc [767];

  

  iVar2 = 0;

  pfVar1 = local_bfc;

  do {

    fVar3 = (float10)_CIpow();

    pfVar1[-1] = (float)fVar3;

    *pfVar1 = (float)fVar3;

    iVar2 = iVar2 + 1;

    pfVar1[1] = (float)fVar3;

    pfVar1 = pfVar1 + 3;

  } while (iVar2 < 0x100);

  FUN_0075e360(param_1);

  return;

}
