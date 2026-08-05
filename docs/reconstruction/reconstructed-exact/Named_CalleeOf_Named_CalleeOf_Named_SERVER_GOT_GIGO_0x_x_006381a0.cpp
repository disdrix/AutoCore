// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_006381a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006381a0
// Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x006381a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006381a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_006381a0(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = param_1;

  if (param_1 < 0x33) {

    iVar2 = 0x33;

  }

  piVar1 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(iVar2 + 0xd,0x11);

  *piVar1 = param_1;

  piVar1[1] = iVar2;

  piVar1[2] = 0;

  return;

}
