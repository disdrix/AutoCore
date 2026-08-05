// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_004269b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004269b0
// Callee of Mission_Received_Connect_Request_8x
// Address:   0x004269b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004269b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x
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

void Named_CalleeOf_Mission_Received_Connect_Request_8x_004269b0(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  int unaff_EDI;

  

  piVar2 = *(int **)(unaff_EDI + 0x1b4);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_EDI + 0x1b4) = unaff_ESI;

  if (unaff_ESI != 0) {

    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 1;

  }

  return;

}
