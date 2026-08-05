// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_00422d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00422d70
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x00422d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: FUN_0041d7b0×2, FUN_00422d70, FUN_00423170, FUN_00437cd0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride
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

/* WARNING: Restarted to delay deadcode elimination for space: stack */



int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_00422d70(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int local_4;

  

  FUN_00423170();

  FUN_00437cd0();

  iVar1 = (*(code *)**(uint32_t /* width from decompiler */ **)*param_1)((uint32_t /* width from decompiler */ *)*param_1,&DAT_00a8601c);

  if (iVar1 < 0) {

    FUN_0041d7b0();

    return iVar1;

  }

  iVar1 = (**(code **)(local_4 + 0xc))(&local_4,0,&DAT_00a8600c);

  FUN_0041d7b0();

  return iVar1;

}
