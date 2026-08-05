// =============================================================================
// FUN_00973170
// -----------------------------------------------------------------------------
// Stable ID: aa_00973170
// Address:   0x00973170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00973170 @ 0x00973170
// Stable ID: aa_00973170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00972f10, FUN_00973170.
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

void FUN_00973170(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  float *pfVar1;

  int unaff_ESI;

  uint8_t local_c [12];

  

  pfVar1 = (float *)FUN_00972f10(local_c,in_EAX);

  *(float *)(unaff_ESI + 0x90) = *pfVar1 + *(float *)(unaff_ESI + 0x90);

  *(float *)(unaff_ESI + 0x94) = pfVar1[1] + *(float *)(unaff_ESI + 0x94);

  *(float *)(unaff_ESI + 0x98) = pfVar1[2] + *(float *)(unaff_ESI + 0x98);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xbc) = 0xffffffff;

  *(int *)(unaff_ESI + 0xb4) = *(int *)(unaff_ESI + 0xb4) + 1;

  return;

}
