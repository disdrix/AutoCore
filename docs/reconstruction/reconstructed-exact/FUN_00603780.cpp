// =============================================================================
// FUN_00603780
// -----------------------------------------------------------------------------
// Stable ID: aa_00603780
// Address:   0x00603780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00603780 @ 0x00603780
// Stable ID: aa_00603780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0040f840, FUN_00603780.
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

int FUN_00603780(int param_1,int param_2,int param_3)



{

  void *local_10;

  uint8_t *puStack_c;

  uint8_t local_8;

  undefined3 uStack_7;

  

  puStack_c = &LAB_009a7e91;

  local_10 = ExceptionList;

  uStack_7 = 0;

  ExceptionList = &local_10;

  for (; param_1 != param_2; param_1 = param_1 + 0x18) {

    local_8 = 1;

    if (param_3 != 0) {

      FUN_0040f840(param_1);

      *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

      *(uint32_t /* width from decompiler */ *)(param_3 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    }

    param_3 = param_3 + 0x18;

  }

  ExceptionList = local_10;

  return param_3;

}
