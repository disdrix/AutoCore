// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assCatalog_00744d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00744d10
// Callee of Named_CalleeOf_Named_assCatalog
// Address:   0x00744d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assCatalog: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0043bfb0, FUN_00744d10, FUN_0075d530.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assCatalog
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

int * Named_CalleeOf_Named_CalleeOf_Named_assCatalog_00744d10(int *param_1,int param_2)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  int iVar2;

  

  iVar2 = *(int *)(in_EAX + 0x50);

  if ((iVar2 == 0) || (*(int *)(in_EAX + 0x54) - iVar2 >> 2 == 0)) {

    iVar2 = 0;

  }

  else {

    iVar2 = param_2 - iVar2 >> 2;

  }

  FUN_0043bfb0(param_2,1,unaff_EBX);

  iVar1 = *(int *)(in_EAX + 0x50);

  if (DAT_00d1f050 != 0) {

    FUN_0075d530();

  }

  *param_1 = iVar1 + iVar2 * 4;

  return param_1;

}
