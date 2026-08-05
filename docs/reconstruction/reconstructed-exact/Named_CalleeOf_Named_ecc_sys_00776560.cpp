// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00776560
// -----------------------------------------------------------------------------
// Stable ID: aa_00776560
// Callee of Named_ecc_sys
// Address:   0x00776560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00775200, FUN_00775b30, FUN_00776560.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Named_ecc_sys_00776560(void)



{

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if ((in_EAX[2] == 1) || (*in_EAX == 0)) {

    return 0xfffffffd;

  }

  if ((0 < *in_EAX) && ((*(byte *)in_EAX[3] & 1) != 0)) {

    uVar1 = FUN_00775b30();

    return uVar1;

  }

  uVar1 = FUN_00775200();

  return uVar1;

}
