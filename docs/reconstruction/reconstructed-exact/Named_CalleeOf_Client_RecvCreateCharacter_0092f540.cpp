// =============================================================================
// Named_CalleeOf_Client_RecvCreateCharacter_0092f540
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f540
// Callee of Client_RecvCreateCharacter
// Address:   0x0092f540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Client_RefreshLocalCharacterLevelUi×2, FUN_004cd310×2, FUN_0092f540.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvCreateCharacter
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

void __fastcall Named_CalleeOf_Client_RecvCreateCharacter_0092f540(int param_1)



{

  int in_EAX;

  

  *(int *)(param_1 + 0xe98) = in_EAX;

  if (in_EAX == 0) {

    FUN_004cd310(0);

    Client_RefreshLocalCharacterLevelUi();

    return;

  }

  FUN_004cd310(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX);

  Client_RefreshLocalCharacterLevelUi();

  return;

}
