// =============================================================================
// Named_CalleeOf_Named_Required_Combat_00599dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00599dd0
// Callee of Named_Required_Combat (+3 other named callers)
// Address:   0x00599dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Required_Combat: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Required_Combat (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00599dd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Required_Combat (+3 other named callers)
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

char __fastcall Named_CalleeOf_Named_Required_Combat_00599dd0(int param_1)



{

  char cVar1;

  

  cVar1 = *(int *)(param_1 + 0x498) != -1;

  if (*(int *)(param_1 + 0x49c) != -1) {

    cVar1 = cVar1 + '\x01';

  }

  if (*(int *)(param_1 + 0x4a0) != -1) {

    cVar1 = cVar1 + '\x01';

  }

  if (*(int *)(param_1 + 0x4a4) != -1) {

    cVar1 = cVar1 + '\x01';

  }

  if (*(int *)(param_1 + 0x4a8) != -1) {

    cVar1 = cVar1 + '\x01';

  }

  return cVar1;

}
