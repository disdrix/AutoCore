// =============================================================================
// FUN_005fe910
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe910
// Address:   0x005fe910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fe910 @ 0x005fe910
// Stable ID: aa_005fe910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005fe910.
//  - Return sites: 2.

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

void __thiscall FUN_005fe910(int param_1,short *param_2,char param_3)



{

  if (param_3 != '\0') {

    *(short *)(param_1 + 0xb6) = *(short *)(param_1 + 0xb6) - *param_2;

    *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) - param_2[1];

    *(short *)(param_1 + 0xba) = *(short *)(param_1 + 0xba) - param_2[2];

    *(short *)(param_1 + 0xbc) = *(short *)(param_1 + 0xbc) - param_2[3];

    *(short *)(param_1 + 0xbe) = *(short *)(param_1 + 0xbe) - param_2[4];

    *(short *)(param_1 + 0xc0) = *(short *)(param_1 + 0xc0) - param_2[5];

    return;

  }

  *(short *)(param_1 + 0xb6) = *(short *)(param_1 + 0xb6) + *param_2;

  *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) + param_2[1];

  *(short *)(param_1 + 0xba) = *(short *)(param_1 + 0xba) + param_2[2];

  *(short *)(param_1 + 0xbc) = *(short *)(param_1 + 0xbc) + param_2[3];

  *(short *)(param_1 + 0xbe) = *(short *)(param_1 + 0xbe) + param_2[4];

  *(short *)(param_1 + 0xc0) = *(short *)(param_1 + 0xc0) + param_2[5];

  return;

}
