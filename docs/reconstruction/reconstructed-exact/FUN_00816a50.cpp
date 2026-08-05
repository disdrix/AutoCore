// =============================================================================
// FUN_00816a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00816a50
// Address:   0x00816a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00816a50 @ 0x00816a50
// Stable ID: aa_00816a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00816940, FUN_00816a50.
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

void __fastcall FUN_00816a50(uint16_t param_1,int *param_2)



{

  char cVar1;

  uint16_t in_AX;

  

  *(uint16_t *)((int)param_2 + 0x81a) = param_1;

  *(uint16_t *)(param_2 + 0x206) = in_AX;

  cVar1 = (**(code **)(*param_2 + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_00816940();

  }

  return;

}
