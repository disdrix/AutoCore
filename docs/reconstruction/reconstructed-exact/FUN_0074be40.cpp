// =============================================================================
// FUN_0074be40
// -----------------------------------------------------------------------------
// Stable ID: aa_0074be40
// Address:   0x0074be40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074be40 @ 0x0074be40
// Stable ID: aa_0074be40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0074be40, FUN_0076f6e0.
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

void FUN_0074be40(void)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float *unaff_EDI;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_0076f6e0();

  fVar3 = unaff_EDI[3];

  *unaff_EDI = local_c;

  unaff_EDI[1] = local_8;

  unaff_EDI[2] = local_4;

  pfVar1 = unaff_EDI + 5;

  *pfVar1 = local_c;

  unaff_EDI[6] = local_8;

  unaff_EDI[7] = local_4;

  pfVar2 = unaff_EDI + 8;

  *pfVar2 = local_c;

  unaff_EDI[9] = local_8;

  unaff_EDI[10] = local_4;

  *pfVar1 = *pfVar1 - fVar3;

  unaff_EDI[6] = unaff_EDI[6] - fVar3;

  unaff_EDI[7] = unaff_EDI[7] - fVar3;

  *pfVar2 = *pfVar2 + fVar3;

  unaff_EDI[9] = unaff_EDI[9] + fVar3;

  unaff_EDI[10] = unaff_EDI[10] + fVar3;

  return;

}
