// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_00404bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00404bc0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x00404bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_00404bc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_00404bc0(int param_1,uint param_2)



{

  CNDHash_LookupByKey(*(void **)(param_1 + 0x18),param_2);

  return;

}
