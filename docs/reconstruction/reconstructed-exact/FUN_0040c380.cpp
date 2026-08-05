// =============================================================================
// FUN_0040c380
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c380
// Address:   0x0040c380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c380 @ 0x0040c380
// Stable ID: aa_0040c380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040c380, SQRT.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c380; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040c380(int param_1)`.
//  - Branches: if (g_flZero < SQRT(in_EAX[2] * in_EAX[2] + in_EAX[1] * in_EAX[1] + *in_E...).
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

void __fastcall FUN_0040c380(int param_1)



{

  float *in_EAX;

  

  if (g_flZero < SQRT(in_EAX[2] * in_EAX[2] + in_EAX[1] * in_EAX[1] + *in_EAX * *in_EAX)) {

    *(float *)(param_1 + 0x30) = *in_EAX;

    *(float *)(param_1 + 0x34) = in_EAX[1];

    *(float *)(param_1 + 0x38) = in_EAX[2];

    *(float *)(param_1 + 0x3c) = in_EAX[3];

  }

  return;

}
