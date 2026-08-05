// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3530
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3530
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a3530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_006a3530, FUN_006a3db0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3530(void)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  int iStack00000004;

  

  pfVar2 = (float *)&DAT_00d08fc8;

  do {

    iVar1 = FUN_006a3db0();

    iStack00000004 = iVar1 * 0x41a7 + (iVar1 / 0x1f31d) * -0x7fffffff;

    if (iStack00000004 < 1) {

      iStack00000004 = iStack00000004 + 0x7fffffff;

    }

    pfVar3 = pfVar2 + 1;

    *pfVar2 = _DAT_009e45b8 * (float)iStack00000004;

    pfVar2 = pfVar3;

  } while ((int)pfVar3 < 0xd091c8);

  _DAT_00d091d0 = (double)iStack00000004;

  return;

}
