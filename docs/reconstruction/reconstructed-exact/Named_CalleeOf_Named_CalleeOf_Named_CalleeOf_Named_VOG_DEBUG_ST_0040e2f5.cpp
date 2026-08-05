// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0040e2f5
// -----------------------------------------------------------------------------
// Stable ID: aa_0040e2f5
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0040e2f5  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: LeaveCriticalSection×2, FUN_0040e2f5, InterlockedIncrement.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint8_t Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0040e2f5(void)



{

  int unaff_EBP;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x10));

  if (*(char *)(unaff_EBP + -0x11) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x28));

  }

  InterlockedIncrement((LONG *)(unaff_ESI + 0xc));

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return *(uint8_t *)(unaff_EBP + -0x12);

}
