// =============================================================================
// Named_CalleeOf_CVOGCreature_SetupGraphics_007b6730
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6730
// Callee of CVOGCreature_SetupGraphics
// Address:   0x007b6730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007b6450, FUN_007b66c0, FUN_007b6730.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCreature_SetupGraphics
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

bool __fastcall Named_CalleeOf_CVOGCreature_SetupGraphics_007b6730(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  

  cVar1 = FUN_007b6450();

  if (cVar1 != '\0') {

    return true;

  }

  cVar1 = FUN_007b66c0(param_1);

  return cVar1 != '\0';

}
