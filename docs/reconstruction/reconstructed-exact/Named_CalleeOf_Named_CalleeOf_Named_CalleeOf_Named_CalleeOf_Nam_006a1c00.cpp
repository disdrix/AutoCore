// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a1c00
// -----------------------------------------------------------------------------
// Stable ID: aa_006a1c00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a1c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_006a36f0×2, FUN_006a1c00, FUN_006a3530, FUN_006a35e0, FUN_006a3db0, time.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a1c00(int param_1)



{

  int iVar1;

  time_t tVar2;

  

  if (param_1 != -1) {

    FUN_006a3530();

    DAT_00d08f98 = '\x01';

    return;

  }

  param_1 = 0x3039;

  if (DAT_00d08f98 != '\0') {

    FUN_006a35e0();

    param_1 = FUN_006a3db0();

  }

  tVar2 = time((time_t *)0x0);

  iVar1 = (int)tVar2;

  if (iVar1 < param_1) {

    FUN_006a36f0((double)iVar1 / (double)param_1);

    DAT_00d08f98 = '\x01';

    return;

  }

  FUN_006a36f0((double)param_1 / (double)iVar1);

  DAT_00d08f98 = '\x01';

  return;

}
