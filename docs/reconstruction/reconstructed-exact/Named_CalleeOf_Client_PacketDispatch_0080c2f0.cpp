// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080c2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c2f0
// Callee of Client_PacketDispatch
// Address:   0x0080c2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fef20, FUN_0080c2f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_0080c2f0(void)



{

  int *piVar1;

  char cVar2;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x1058);

  cVar2 = (**(code **)(*piVar1 + 0x3d8))();

  if ((cVar2 != '\0') && (piVar1[0x19e] != 0 || piVar1[0x19f] != 0)) {

    FUN_007fef20(10,0,0);

  }

  return;

}
