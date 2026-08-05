// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_0092e580
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e580
// Callee of Client_Input_PollBoundActions
// Address:   0x0092e580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092e580.
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

void Named_CalleeOf_Client_Input_PollBoundActions_0092e580(void)



{

  float fVar1;

  int in_EAX;

  bool bVar2;

  

  fVar1 = g_flOne;

  if ((*(int *)(in_EAX + 0xe98) != 0) && (0 < *(int *)(*(int *)(in_EAX + 0xe98) + 0x6b4))) {

    bVar2 = *(char *)(in_EAX + 0xa1) == '\0';

    *(bool *)(in_EAX + 0xa1) = bVar2;

    *(float *)(in_EAX + 0x9b0) = fVar1;

    *(bool *)(*(int *)(in_EAX + 0xde8) + 0x2e1) = !bVar2;

  }

  return;

}
