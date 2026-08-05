// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0041a020
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a020
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
// Address:   0x0041a020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0041a020, _com_issue_errorex.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0041a020(void)



{

  uint uVar1;

  int in_EAX;

  ULONG UVar2;

  IUnknown *unaff_ESI;

  

  uVar1 = *(uint *)(in_EAX + 4);

  UVar2 = (*unaff_ESI->lpVtbl[0x13].AddRef)(unaff_ESI);

  if ((int)UVar2 < 0) {

    _com_issue_errorex(UVar2,unaff_ESI,(_GUID *)&DAT_00a86138);

  }

  return uVar1 & 0xffff;

}
