// =============================================================================
// FUN_00411770
// -----------------------------------------------------------------------------
// Stable ID: aa_00411770
// Address:   0x00411770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411770 @ 0x00411770
// Stable ID: aa_00411770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00411770.
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



void FUN_00411770(void)



{

  float *in_EAX;

  float fVar1;

  

  fVar1 = *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1] + in_EAX[2] * in_EAX[2] + in_EAX[3] * in_EAX[3];

  if ((_DAT_00a240ec <= fVar1) || (fVar1 <= DAT_00aaa640)) {

    fVar1 = g_flOne / fVar1;

    *in_EAX = 0.0 - *in_EAX * fVar1;

    in_EAX[1] = 0.0 - in_EAX[1] * fVar1;

    in_EAX[2] = 0.0 - in_EAX[2] * fVar1;

    in_EAX[3] = fVar1 * in_EAX[3];

  }

  return;

}
