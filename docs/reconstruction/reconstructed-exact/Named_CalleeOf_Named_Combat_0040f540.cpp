// =============================================================================
// Named_CalleeOf_Named_Combat_0040f540
// -----------------------------------------------------------------------------
// Stable ID: aa_0040f540
// Callee of Named_Combat
// Address:   0x0040f540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Combat: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040f540.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Combat
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_CalleeOf_Named_Combat_0040f540(int param_1)



{

  int iVar1;

  

  iVar1 = (int)*(short *)(param_1 + 0xea) + (int)*(short *)(param_1 + 0xe8);

  if (0x50 < iVar1) {

    iVar1 = 0x50;

  }

  return iVar1;

}
