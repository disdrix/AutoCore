// =============================================================================
// FUN_00746c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00746c10
// Address:   0x00746c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746c10 @ 0x00746c10
// Stable ID: aa_00746c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00746910, FUN_00746c10.
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

uint32_t /* width from decompiler */ FUN_00746c10(void)



{

  int iVar1;

  int in_EAX;

  uint16_t *puVar2;

  uint16_t unaff_SI;

  

  iVar1 = *(int *)(in_EAX + 8);

  for (puVar2 = *(uint16_t **)(in_EAX + 4); puVar2 != (uint16_t *)(iVar1 + -8);

      puVar2 = puVar2 + 4) {

    *puVar2 = unaff_SI;

  }

  FUN_00746910();

  return 0;

}
