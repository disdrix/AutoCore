// =============================================================================
// FUN_00404a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00404a40
// Address:   0x00404a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404a40 @ 0x00404a40
// Stable ID: aa_00404a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00404a40.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00404a40; evidence only — no invented semantics):
//  - Entry: `void __thiscall FUN_00404a40(int param_1,float param_2)`.
//  - Branches: if (((param_2 != *(param_1 + 0x9c)) && (param_2 != *(param_1 + 0xa0))) &&...).
//  - Returns (1 site(s)): `void`.




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

void __thiscall FUN_00404a40(int param_1,float param_2)



{

  if (((param_2 != *(float *)(param_1 + 0x9c)) && (param_2 != *(float *)(param_1 + 0xa0))) &&

     (param_2 != *(float *)(param_1 + 0xa4))) {

    *(float *)(param_1 + 0xa4) = param_2;

    *(float *)(param_1 + 0xa0) = param_2;

    *(float *)(param_1 + 0x9c) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0xffffffff;

    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

    *(uint8_t *)(param_1 + 0xb8) = 0;

  }

  return;

}
