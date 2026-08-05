// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_00756060
// -----------------------------------------------------------------------------
// Stable ID: aa_00756060
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
// Address:   0x00756060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00755db0, FUN_00755e80, FUN_00756060, FUN_0076c4d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_00756060(void)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  *(uint8_t *)(unaff_ESI + 0x48) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40);

  FUN_0076c4d0();

  cVar1 = (**(code **)(**(int **)(unaff_ESI + 8) + 8))();

  if (cVar1 != '\0') {

    FUN_00755db0(unaff_EDI);

    FUN_00755e80(unaff_EDI);

    return 1;

  }

  return 0;

}
