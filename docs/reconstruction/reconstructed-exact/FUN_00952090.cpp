// =============================================================================
// FUN_00952090
// -----------------------------------------------------------------------------
// Stable ID: aa_00952090
// Address:   0x00952090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00952090 @ 0x00952090
// Stable ID: aa_00952090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00952090, FUN_00971a20, FUN_00989e00, strtok.
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

uint32_t /* width from decompiler */ FUN_00952090(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char *pcVar1;

  

  pcVar1 = strtok((char *)0x0,param_2);

  if ((pcVar1 != (char *)0x0) && (*(int *)(DAT_00d1f050 + 0x6c) != 0)) {

    FUN_00989e00(&param_2,pcVar1);

    FUN_00971a20(&param_2,1);

  }

  return 1;

}
