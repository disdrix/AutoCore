// =============================================================================
// FUN_0084fbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fbd0
// Address:   0x0084fbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084fbd0 @ 0x0084fbd0
// Stable ID: aa_0084fbd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0084fbd0.
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



void FUN_0084fbd0(void)



{

  int in_EAX;

  float in_XMM0_Da;

  float in_XMM1_Da;

  float fVar1;

  

  fVar1 = in_XMM0_Da;

  if (in_XMM0_Da <= in_XMM1_Da) {

    fVar1 = in_XMM1_Da;

  }

  DAT_00af9328 = in_XMM0_Da;

  DAT_00af932c = in_XMM1_Da;

  *(float *)(in_EAX + 0x500) = fVar1;

  if (in_XMM1_Da <= in_XMM0_Da) {

    in_XMM0_Da = in_XMM1_Da;

  }

  _DAT_00af9330 = (in_XMM0_Da * DAT_00a0f298) / *(float *)(in_EAX + 0x504);

  if (_DAT_00af9330 < g_flOne) {

    _DAT_00af9330 = g_flOne;

  }

  return;

}
