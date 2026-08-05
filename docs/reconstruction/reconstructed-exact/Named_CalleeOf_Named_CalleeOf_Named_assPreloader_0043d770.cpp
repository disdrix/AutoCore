// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043d770
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d770
// Callee of Named_CalleeOf_Named_assPreloader
// Address:   0x0043d770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00439050, FUN_0043d770, FUN_0043dc20, FUN_0046f100.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPreloader
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

int Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043d770(void)



{

  int iVar1;

  int local_c;

  int local_8;

  int local_4;

  

  FUN_0043dc20();

  iVar1 = 0;

  local_c = local_8;

  while (local_c != local_4) {

    iVar1 = iVar1 + 1;

    FUN_0046f100();

  }

  FUN_00439050(&local_c,local_8,local_4);

  return iVar1;

}
