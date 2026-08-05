// =============================================================================
// FUN_0044eb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0044eb40
// Address:   0x0044eb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044eb40 @ 0x0044eb40
// Stable ID: aa_0044eb40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0044eb40, FUN_00988fd0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0044eb40(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  FUN_00988fd0(param_1);

  if (((param_2 & 1) != 0) && (param_1 != (uint32_t /* width from decompiler */ *)0x0)) {

    *param_1 = DAT_00d218f4;

    DAT_00d218f4 = param_1;

  }

  return param_1;

}
