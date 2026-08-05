// =============================================================================
// Named_CalleeOf_Named_Starting_ShutDown_on_Client_007f9b20
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9b20
// Callee of Named_Starting_ShutDown_on_Client
// Address:   0x007f9b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Starting_ShutDown_on_Client: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_007f9b20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Starting_ShutDown_on_Client
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

void Named_CalleeOf_Named_Starting_ShutDown_on_Client_007f9b20(int *param_1)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = param_1 + 0x126;

  iVar2 = 3;

  do {

    if ((void *)*piVar1 != (void *)0x0) {

      operator_delete__((void *)*piVar1);

    }

    *piVar1 = 0;

    piVar1[-3] = 0;

    piVar1 = piVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  (**(code **)(*param_1 + 0x34c))();

  return;

}
