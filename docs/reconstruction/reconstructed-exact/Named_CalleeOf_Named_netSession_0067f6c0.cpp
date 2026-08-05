// =============================================================================
// Named_CalleeOf_Named_netSession_0067f6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067f6c0
// Callee of Named_netSession
// Address:   0x0067f6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_0067f6c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_netSession
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_netSession_0067f6c0(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 4) == 0) {

    return 1;

  }

  iVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);

  return CONCAT31((int3)(iVar1 >> 10),iVar1 >> 2 == 0);

}
