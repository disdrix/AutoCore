// =============================================================================
// Named_CalleeOf_Named_Combat_0051f8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f8e0
// Callee of Named_Combat (+1 other named callers)
// Address:   0x0051f8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Combat: combat/reward helper. Evidence string: "Unknown". Supports parent flow (not a free-standing entry point). Named_Combat (+1 other named callers).
// Embedded strings (evidence):
//   - "Human"
//   - "Unknown"
//   - "Biomek"
//   - "Mutant"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0051f8e0.
//  - Strings: "Human"; "Unknown"; "Biomek"; "Mutant".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_Combat (+1 other named callers)
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

char * Named_CalleeOf_Named_Combat_0051f8e0(int param_1)



{

  if (param_1 == 0) {

    return "Human";

  }

  if (param_1 != 1) {

    if (param_1 != 2) {

      return "Unknown";

    }

    return "Biomek";

  }

  return "Mutant";

}
