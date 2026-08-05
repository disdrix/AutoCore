// =============================================================================
// FUN_006555e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006555e0
// Address:   0x006555e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006555e0 @ 0x006555e0
// Stable ID: aa_006555e0
// Embedded strings (evidence for future rename):
//   - "DebugDisplay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063f710, FUN_006523b0, FUN_00654e60, FUN_006555e0.
//  - Strings: "DebugDisplay".
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

uint32_t /* width from decompiler */ * __fastcall FUN_006555e0(uint32_t /* width from decompiler */ *param_1)



{

  FUN_006523b0();

  *param_1 = &PTR_FUN_009e5dcc;

  param_1[2] = &PTR_LAB_009e5dc4;

  if (DAT_00d03518 == 0) {

    DAT_00d03518 = FUN_0063f710("DebugDisplay",&LAB_00655640);

  }

  FUN_00654e60(param_1);

  return param_1;

}
