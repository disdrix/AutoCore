// =============================================================================
// FUN_0076d140
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d140
// Address:   0x0076d140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d140 @ 0x0076d140
// Stable ID: aa_0076d140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004933f0, FUN_0076d140, _atexit.
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



undefined * FUN_0076d140(void)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab8f3;

  local_c = ExceptionList;

  if ((DAT_00d1f894 & 1) == 0) {

    DAT_00d1f894 = DAT_00d1f894 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    DAT_00d1f88c = FUN_004933f0();

    _DAT_00d1f890 = 0;

    _atexit((_func_4879 *)&LAB_009c3290);

  }

  ExceptionList = local_c;

  return &DAT_00d1f888;

}
