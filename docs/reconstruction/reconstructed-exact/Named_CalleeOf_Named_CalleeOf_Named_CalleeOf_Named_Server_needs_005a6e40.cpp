// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_005a6e40
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6e40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
// Address:   0x005a6e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a6e40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_005a6e40(int param_1,char param_2,char param_3)



{

  if ((((*(int *)(param_1 + 0xec) != 0) && (-1 < param_2)) &&

      ((int)param_2 < *(int *)(param_1 + 0xf0))) && ((-1 < param_3 && (param_3 < '\x03')))) {

    return *(int *)(param_1 + 0xec) + (param_2 * 3 + (int)param_3) * 0x14c;

  }

  return 0;

}
