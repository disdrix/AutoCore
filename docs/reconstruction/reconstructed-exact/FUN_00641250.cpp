// =============================================================================
// FUN_00641250
// -----------------------------------------------------------------------------
// Stable ID: aa_00641250
// Address:   0x00641250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641250 @ 0x00641250
// Stable ID: aa_00641250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063fb30, FUN_00641250, FUN_00642740, FUN_00652910, FUN_00652d00.
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

void __fastcall FUN_00641250(int param_1)



{

  char *pcVar1;

  uint8_t local_29;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [28];

  

  FUN_00652d00(local_20);

  FUN_00652910(&local_28,8,1);

  pcVar1 = (char *)FUN_0063fb30(&local_29);

  if ((*pcVar1 != '\0') && (*(int *)(param_1 + 0x10) != 0)) {

    FUN_00642740(&local_29,local_28,local_24,local_20);

  }

  return;

}
