// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00745e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00745e20
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00745e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00745e20, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

bool Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00745e20(void)



{

  int iVar1;

  int unaff_EDI;

  

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  iVar1 = *(int *)(unaff_EDI + 0x10);

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  return iVar1 != 0;

}
