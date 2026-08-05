// =============================================================================
// FUN_00415f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00415f70
// Address:   0x00415f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00415f70 @ 0x00415f70
// Stable ID: aa_00415f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00415dd0, FUN_00415f70.
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

void FUN_00415f70(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)

{
  void *local_10;
  uint8_t *puStack_c;
  uint32_t /* width from decompiler */ local_8;
  
  puStack_c = &LAB_009bd910;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    FUN_00415dd0(param_1,param_2);
  }
  ExceptionList = local_10;
  return;
}
