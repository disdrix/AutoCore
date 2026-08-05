// =============================================================================
// FUN_004099b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004099b0
// Address:   0x004099b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004099b0 @ 0x004099b0
// Stable ID: aa_004099b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004099b0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004099b0; evidence only — no invented semantics):
//  - Entry: `void __thiscall FUN_004099b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 para...`.
//  - Writes: *param_1 = param_2; param_1[1] = param_3; param_1[2] = param_4.
//  - Returns (1 site(s)): `void`.
//  - Assign `param_1 = param_2`.




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

void __thiscall

FUN_004099b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ *param_5,uint8_t param_6)



{

  *param_1 = param_2;

  param_1[1] = param_3;

  param_1[2] = param_4;

  param_1[4] = *param_5;

  param_1[5] = param_5[1];

  param_1[6] = param_5[2];

  param_1[7] = param_5[3];

  *(uint8_t *)(param_1 + 8) = param_6;

  *(uint8_t *)((int)param_1 + 0x21) = 0;

  return;

}
