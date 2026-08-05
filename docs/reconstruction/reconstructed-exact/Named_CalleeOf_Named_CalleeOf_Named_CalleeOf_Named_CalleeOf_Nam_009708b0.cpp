// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_009708b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009708b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x009708b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: _stricmp×2, FUN_009708b0, strrchr.
//  - Strings: "geo"; "xml".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_009708b0(void)



{

  int *in_EAX;

  char *pcVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  pcVar1 = (char *)*in_EAX;

  if ((char *)*in_EAX == (char *)0x0) {

    pcVar1 = PTR_DAT_00afa2bc;

  }

  pcVar1 = strrchr(pcVar1,0x2e);

  if (pcVar1 == (char *)0x0) {

    return 0;

  }

  iVar2 = _stricmp(pcVar1 + 1,"geo");

  if (iVar2 == 0) {

    *unaff_EBX = 0;

    return 1;

  }

  iVar2 = _stricmp(pcVar1 + 1,"xml");

  if (iVar2 == 0) {

    *unaff_EBX = 3;

    return 1;

  }

  return 0;

}
