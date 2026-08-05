// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMiss_00537410
// -----------------------------------------------------------------------------
// Stable ID: aa_00537410
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMissionDialog
// Address:   0x00537410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMissionDialog: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00537410.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMissionDialog
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMiss_00537410(int param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 8);

  cVar1 = *(char *)(iVar2 + 0x49);

  while (cVar1 == '\0') {

    iVar2 = *(int *)(iVar2 + 8);

    cVar1 = *(char *)(iVar2 + 0x49);

  }

  return;

}
