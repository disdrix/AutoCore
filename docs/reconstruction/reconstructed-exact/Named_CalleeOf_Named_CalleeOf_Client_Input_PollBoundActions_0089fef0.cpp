// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0089fef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0089fef0
// Callee of Named_CalleeOf_Client_Input_PollBoundActions (+1 other named callers)
// Address:   0x0089fef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_Input_PollBoundActions (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_00826780, FUN_0089fef0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0089fef0(void)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  

  piVar1 = (int *)(in_EAX + 0x63c);

  iVar2 = 10;

  do {

    if ((*piVar1 != 0) && (*(char *)(*piVar1 + 0x4fc) != '\0')) {

      FUN_00826780(0);

    }

    piVar1 = piVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
