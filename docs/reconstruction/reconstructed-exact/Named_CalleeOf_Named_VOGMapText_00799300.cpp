// =============================================================================
// Named_CalleeOf_Named_VOGMapText_00799300
// -----------------------------------------------------------------------------
// Stable ID: aa_00799300
// Callee of Named_VOGMapText (+7 other named callers)
// Address:   0x00799300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGMapText (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00798bb0, FUN_00799300, _wtof.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOGMapText (+7 other named callers)
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

char Named_CalleeOf_Named_VOGMapText_00799300(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  char cVar1;

  double dVar2;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 != '\0') {

    dVar2 = _wtof(local_80);

    *param_3 = (float)dVar2;

  }

  return cVar1;

}
