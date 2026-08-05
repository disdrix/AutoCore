// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00516be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00516be0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00516be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, goto×1, return×1.
//  - Notable callees: FUN_00516a00, FUN_00516be0.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00516be0(int *param_1)



{

  int iVar1;

  

  iVar1 = (**(code **)(*param_1 + 0x1d4))();

  if (iVar1 != 0) {

    iVar1 = (**(code **)(*param_1 + 0x1d4))();

    if (*(char *)(iVar1 + 0x2ac) != '\0') goto LAB_00516c0c;

  }

  (**(code **)(*param_1 + 0x100))();

LAB_00516c0c:

  (**(code **)(*param_1 + 0x48))();

  if ((*(int *)(param_1[0x2a] + 0x38) != 0x12) && (*(int *)(param_1[0x2a] + 0x38) != 0x14)) {

    FUN_00516a00(1);

  }

  return;

}
