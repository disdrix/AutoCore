// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_rename_sent_to_servers_00793930
// -----------------------------------------------------------------------------
// Stable ID: aa_00793930
// Callee of Named_CalleeOf_Named_rename_sent_to_servers
// Address:   0x00793930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_rename_sent_to_servers: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00793930.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_rename_sent_to_servers_00793930(char *param_1)



{

  char *pcVar1;

  char cVar2;

  

  cVar2 = *param_1;

  while (cVar2 != '\0') {

    if (('@' < cVar2) && (cVar2 < '[')) {

      *param_1 = cVar2 + ' ';

    }

    pcVar1 = param_1 + 1;

    param_1 = param_1 + 1;

    cVar2 = *pcVar1;

  }

  return;

}
