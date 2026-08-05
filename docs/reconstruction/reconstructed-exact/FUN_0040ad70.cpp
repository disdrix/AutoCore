// =============================================================================
// FUN_0040ad70
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ad70
// Address:   0x0040ad70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ad70 @ 0x0040ad70
// Stable ID: aa_0040ad70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040ad70.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x0040ad70; evidence only — no invented semantics):
//  - Entry: `uint FUN_0040ad70(int param_1)`.
//  - Branches: if (0x7f < in_EAX) → return in_EAX & 0xffffff00.
//  - Returns (2 site(s)): `in_EAX & 0xffffff00`; `((*(param_1 + 0xd30 + ((in_EAX & 0xff...`.




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

uint FUN_0040ad70(int param_1)



{

  uint in_EAX;

  

  if (0x7f < (byte)in_EAX) {

    return in_EAX & 0xffffff00;

  }

  return (uint)((*(uint *)(param_1 + 0xd30 + ((in_EAX & 0xff) >> 5) * 4) &

                1 << ((byte)in_EAX & 0x1f)) != 0);

}
