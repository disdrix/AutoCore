// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_00481290
// -----------------------------------------------------------------------------
// Stable ID: aa_00481290
// Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
// Address:   0x00481290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00481290, _stricmp.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
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

bool __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_00481290(int *param_1)



{

  int *in_EAX;

  char *_Str2;

  int iVar1;

  char *_Str1;

  

  _Str2 = (char *)*in_EAX;

  if ((char *)*in_EAX == (char *)0x0) {

    _Str2 = PTR_DAT_00afa2bc;

  }

  _Str1 = (char *)*param_1;

  if ((char *)*param_1 == (char *)0x0) {

    _Str1 = PTR_DAT_00afa2bc;

  }

  iVar1 = _stricmp(_Str1,_Str2);

  return iVar1 < 0;

}
