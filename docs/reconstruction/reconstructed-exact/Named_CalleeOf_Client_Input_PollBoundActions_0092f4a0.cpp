// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_0092f4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f4a0
// Callee of Client_Input_PollBoundActions
// Address:   0x0092f4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092f4a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_0092f4a0(void)



{

  int in_EAX;

  

  DAT_00afe100 = DAT_00afe100 == '\0';

  if (*(int *)(in_EAX + 0xe04) != 0) {

    *(char *)(*(int *)(*(int *)(in_EAX + 0xe04) + 0xe894) + 0x78) = DAT_00afe100;

  }

  return;

}
