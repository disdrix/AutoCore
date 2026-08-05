// =============================================================================
// FUN_00422580
// -----------------------------------------------------------------------------
// Stable ID: aa_00422580
// Address:   0x00422580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00422580 @ 0x00422580
// Stable ID: aa_00422580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00422580.
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

void FUN_00422580(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  for (; param_1 != param_2; param_1 = param_1 + 6) {

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = *param_1;

      param_3[1] = param_1[1];

      param_3[2] = param_1[2];

      param_3[3] = param_1[3];

      param_3[4] = param_1[4];

      param_3[5] = param_1[5];

    }

    param_3 = param_3 + 6;

  }

  return;

}
