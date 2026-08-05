// =============================================================================
// FUN_00446a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00446a20
// Address:   0x00446a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00446a20 @ 0x00446a20
// Stable ID: aa_00446a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00446a20.
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

uint8_t * FUN_00446a20(uint8_t *param_1,int param_2,uint8_t *param_3)



{

  uint8_t *puVar1;

  int iVar2;

  

  puVar1 = param_1;

  for (iVar2 = param_2; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = *param_3;

    puVar1 = puVar1 + 1;

  }

  return param_1 + param_2;

}
