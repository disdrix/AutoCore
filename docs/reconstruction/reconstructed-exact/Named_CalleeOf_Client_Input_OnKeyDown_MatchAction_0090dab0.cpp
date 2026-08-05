// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dab0
// Callee of Client_Input_OnKeyDown_MatchAction
// Address:   0x0090dab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0090d400, FUN_0090dab0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_OnKeyDown_MatchAction
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

void Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = &DAT_00d09a38;

  do {

    FUN_0090d400();

    puVar1 = puVar1 + 1;

  } while ((int)puVar1 < 0xd09a4c);

  return;

}
