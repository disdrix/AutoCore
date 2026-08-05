// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0042c4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c4e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0042c4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0042b2a0, FUN_0042c4e0, FUN_0042c620, FUN_0042c6c0, FUN_0042fe60.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0042c4e0(void)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  int unaff_EBX;

  

  FUN_0042c620();

  iVar2 = FUN_0042c6c0();

  if (iVar2 != 0) {

    FUN_0042fe60();

  }

  *(int *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) + 1;

  piVar1 = (int *)(in_EAX + 0x24);

  FUN_0042b2a0();

  *piVar1 = *piVar1 + 1;

  piVar1 = (int *)(*(int *)(in_EAX + 0x2c) + -4 + *piVar1 * 4);

  if (piVar1 != (int *)0x0) {

    *piVar1 = unaff_EBX;

  }

  return;

}
