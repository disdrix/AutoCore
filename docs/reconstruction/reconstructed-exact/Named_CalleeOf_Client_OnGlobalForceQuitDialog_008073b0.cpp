// =============================================================================
// Named_CalleeOf_Client_OnGlobalForceQuitDialog_008073b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008073b0
// Callee of Client_OnGlobalForceQuitDialog (+1 other named callers)
// Address:   0x008073b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnGlobalForceQuitDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnGlobalForceQuitDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008073b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_OnGlobalForceQuitDialog (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Client_OnGlobalForceQuitDialog_008073b0(short param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(0xffffffff,param_2,(int)param_1,0);

      return 0;

    }

  }

  return 0x80004005;

}
