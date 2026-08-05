// =============================================================================
// Named_CalleeOf_Client_InteractClickPickTarget_0040b1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b1b0
// Callee of Client_InteractClickPickTarget
// Address:   0x0040b1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_InteractClickPickTarget: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0040b1b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_InteractClickPickTarget
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Client_InteractClickPickTarget_0040b1b0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

  return CONCAT31((int3)((uint)iVar1 >> 8),*(int *)(*(int *)(iVar1 + 0x3c) + 0x4e0) == 1);

}
