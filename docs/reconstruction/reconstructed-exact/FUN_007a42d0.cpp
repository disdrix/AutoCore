// =============================================================================
// FUN_007a42d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a42d0
// Address:   0x007a42d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a42d0 @ 0x007a42d0
// Stable ID: aa_007a42d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00424890, FUN_004248c0, FUN_007a4200, FUN_007a42d0, time.
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

void FUN_007a42d0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  time_t tVar2;

  

  *unaff_EDI = &PTR_FUN_00a97168;

  *(uint8_t *)(unaff_EDI + 1) = 0;

  unaff_EDI[2] = 0;

  unaff_EDI[3] = 0;

  unaff_EDI[4] = 0;

  unaff_EDI[5] = 0;

  tVar2 = time((time_t *)0x0);

  pvVar1 = operator_new(0x9c8);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    FUN_00424890();

    FUN_004248c0();

  }

  unaff_EDI[5] = pvVar1;

  if (*(char *)(unaff_EDI + 1) == '\0') {

    FUN_007a4200((int)tVar2);

  }

  return;

}
