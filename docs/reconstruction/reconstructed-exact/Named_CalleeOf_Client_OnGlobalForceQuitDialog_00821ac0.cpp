// =============================================================================
// Named_CalleeOf_Client_OnGlobalForceQuitDialog_00821ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00821ac0
// Callee of Client_OnGlobalForceQuitDialog (+1 other named callers)
// Address:   0x00821ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnGlobalForceQuitDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnGlobalForceQuitDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: strncpy×2, FUN_00821ac0.
//  - Return sites: 1.

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

void Named_CalleeOf_Client_OnGlobalForceQuitDialog_00821ac0(char *param_1)



{

  char *in_EAX;

  int unaff_ESI;

  

  strncpy((char *)(unaff_ESI + 8),in_EAX,0x20);

  *(uint8_t *)(unaff_ESI + 0x28) = 0;

  strncpy((char *)(unaff_ESI + 0x29),param_1,0x20);

  *(uint8_t *)(unaff_ESI + 0x49) = 0;

  return;

}
