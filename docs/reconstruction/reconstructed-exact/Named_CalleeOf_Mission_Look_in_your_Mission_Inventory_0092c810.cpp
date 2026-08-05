// =============================================================================
// Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_0092c810
// -----------------------------------------------------------------------------
// Stable ID: aa_0092c810
// Callee of Mission_Look_in_your_Mission_Inventory
// Address:   0x0092c810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Look_in_your_Mission_Inventory: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0092c810.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Look_in_your_Mission_Inventory
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

int Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_0092c810(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(*(int *)(in_EAX + 0x4d0) + 0x11c);

  if (iVar1 == 0) {

    return 0;

  }

  return *(int *)(*(int *)(in_EAX + 0x4d0) + 0x120) - iVar1 >> 2;

}
