// =============================================================================
// FUN_0072b4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b4f0
// Address:   0x0072b4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b4f0 @ 0x0072b4f0
// Stable ID: aa_0072b4f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004406e0, FUN_0046d070, FUN_0072b310, FUN_0072b4f0.
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

void FUN_0072b4f0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  pvVar1 = operator_new(0x50);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0046d070();

  }

  FUN_004406e0();

  FUN_0072b310(uVar2,DAT_00afa624);

  return;

}
