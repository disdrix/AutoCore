// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00513d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00513d10
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00513d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, switch×1, if×1, goto×1.
//  - Notable callees: CONCAT31, FUN_00513d10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_Dispatch
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

uint __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00513d10(int param_1)



{

  int *piVar1;

  uint uVar2;

  

  uVar2 = *(uint *)(param_1 + 0xa8);

  switch(*(uint32_t /* width from decompiler */ *)(uVar2 + 0x38)) {

  case 6:

    piVar1 = (int *)(uVar2 + 0x3c);

    uVar2 = 0;

    if (((*piVar1 != 0) && (uVar2 = (uint)*(short *)(*piVar1 + 0x3f4), 9 < (int)uVar2)) &&

       ((int)uVar2 < 0xc)) goto switchD_00513d28_caseD_a;

    break;

  case 10:

  case 0xc:

  case 0xe:

  case 0x10:

  case 0x1c:

switchD_00513d28_caseD_a:

    return CONCAT31((int3)(uVar2 >> 8),1);

  }

  return uVar2 & 0xffffff00;

}
