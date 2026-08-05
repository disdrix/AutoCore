// =============================================================================
// FUN_0094dca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094dca0
// Address:   0x0094dca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094dca0 @ 0x0094dca0
// Stable ID: aa_0094dca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055df80, FUN_0094dca0, atof, strtok.
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

uint32_t /* width from decompiler */ FUN_0094dca0(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char *_String;

  double dVar1;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  _String = strtok((char *)0x0,param_2);

  if (_String != (char *)0x0) {

    dVar1 = atof(_String);

    local_1c = -(float)dVar1;

    local_20 = 0;

    local_18 = 0;

    local_14 = 0;

    FUN_0055df80(&local_20);

  }

  return 1;

}
