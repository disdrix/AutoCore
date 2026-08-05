// =============================================================================
// FUN_0051a0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051a0e0
// Address:   0x0051a0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051a0e0 @ 0x0051a0e0
// Stable ID: aa_0051a0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CNDHash_LookupByKey, FUN_00519660, FUN_0051a0e0.
//  - Return sites: 3.

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

void * FUN_0051a0e0(uint param_1)



{

  void *pvVar1;

  

  if ((int)param_1 < 0) {

    return (void *)0x0;

  }

  if ((DAT_00b042ec < 1) && (FUN_00519660(), DAT_00b042ec < 1)) {

    return (void *)0x0;

  }

  pvVar1 = CNDHash_LookupByKey(&DAT_00b042e0,param_1);

  return pvVar1;

}
