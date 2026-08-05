// =============================================================================
// FUN_00435290
// -----------------------------------------------------------------------------
// Stable ID: aa_00435290
// Address:   0x00435290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00435290 @ 0x00435290
// Stable ID: aa_00435290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00435290.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_00435290(void)



{

  int *piVar1;

  int in_EAX;

  

  piVar1 = (int *)(in_EAX + 4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    return 0;

  }

  *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) - *(int *)(*(int *)(in_EAX + 0x14) + 0x30);

  return 1;

}
