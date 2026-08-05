// =============================================================================
// FUN_00972b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00972b20
// Address:   0x00972b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00972b20 @ 0x00972b20
// Stable ID: aa_00972b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00972b20.
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

void __fastcall FUN_00972b20(int param_1)



{

  float fVar1;

  

  fVar1 = g_flOne;

  if (*(char *)(param_1 + 0xb8) != '\0') {

    *(float *)(param_1 + 0xa8) = g_flOne / *(float *)(param_1 + 0x9c);

    *(float *)(param_1 + 0xac) = fVar1 / *(float *)(param_1 + 0xa0);

    *(float *)(param_1 + 0xb0) = fVar1 / *(float *)(param_1 + 0xa4);

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffb;

    return;

  }

  fVar1 = g_flOne / *(float *)(param_1 + 0x9c);

  *(float *)(param_1 + 0xac) = fVar1;

  *(float *)(param_1 + 0xa8) = fVar1;

  *(float *)(param_1 + 0xb0) = fVar1;

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffb;

  return;

}
