// =============================================================================
// FUN_005a5050
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5050
// Address:   0x005a5050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a5050 @ 0x005a5050
// Stable ID: aa_005a5050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a5050.
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

void __fastcall FUN_005a5050(uint32_t /* width from decompiler */ *param_1)



{

  *(uint8_t *)(param_1 + 5) = 1;

  *(uint8_t *)((int)param_1 + 0x15) = 1;

  *(uint8_t *)((int)param_1 + 0x16) = 1;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  *(uint8_t *)((int)param_1 + 0x17) = 0;

  *(uint8_t *)(param_1 + 6) = 0;

  *(uint8_t *)((int)param_1 + 0x19) = 0;

  *(uint8_t *)((int)param_1 + 0x1a) = 0;

  *(uint8_t *)((int)param_1 + 0x1b) = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  return;

}
