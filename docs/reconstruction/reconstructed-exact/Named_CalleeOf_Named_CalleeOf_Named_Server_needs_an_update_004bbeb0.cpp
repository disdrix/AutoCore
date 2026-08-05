// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bbeb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbeb0
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x004bbeb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00410420×3, FUN_004bc580×3, FUN_004bbeb0, FUN_004bcce0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bbeb0(int param_1)



{

  FUN_004bcce0(5);

  FUN_004bc580();

  FUN_004bc580();

  FUN_004bc580();

  FUN_00410420(0,0);

  FUN_00410420(0,0);

  FUN_00410420(0,0);

  if (*(char *)(param_1 + 0xc) != '\0') {

    (**(code **)(**(int **)(param_1 + 4) + 4))();

  }

  if (*(char *)(param_1 + 0xd) != '\0') {

                    /* WARNING: Could not recover jumptable at 0x004bbf13. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + 8) + 4))();

    return;

  }

  return;

}
