// =============================================================================
// Named_CalleeOf_Named_Lost_Connection_To_Server_00861c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00861c10
// Callee of Named_Lost_Connection_To_Server
// Address:   0x00861c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Lost_Connection_To_Server: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00861c10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Lost_Connection_To_Server
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Lost_Connection_To_Server_00861c10(void)



{

  char cVar1;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((cVar1 != '\0') && (unaff_ESI[0x13f] != 0)) {

    cVar1 = (**(code **)(*(int *)unaff_ESI[0x13f] + 0xd0))();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  return 0;

}
