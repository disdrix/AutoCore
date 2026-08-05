// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_rename_sent_to_servers_00793b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00793b80
// Callee of Named_CalleeOf_Named_rename_sent_to_servers
// Address:   0x00793b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_rename_sent_to_servers: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00793b80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_rename_sent_to_servers
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

int Named_CalleeOf_Named_CalleeOf_Named_rename_sent_to_servers_00793b80(void)



{

  char cVar1;

  char *in_EAX;

  char *pcVar2;

  

  cVar1 = *in_EAX;

  pcVar2 = in_EAX;

  while (cVar1 != '\0') {

    pcVar2 = pcVar2 + 1;

    cVar1 = *pcVar2;

  }

  return (int)pcVar2 - (int)in_EAX;

}
