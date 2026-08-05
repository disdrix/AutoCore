// =============================================================================
// Named_CalleeOf_Client_LoadVogIniConfig_0092f920
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f920
// Callee of Client_LoadVogIniConfig (+1 other named callers)
// Address:   0x0092f920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_LoadVogIniConfig: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_LoadVogIniConfig (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0092f920.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_LoadVogIniConfig (+1 other named callers)
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

void Named_CalleeOf_Client_LoadVogIniConfig_0092f920(void)



{

  int in_EAX;

  

  DAT_00aefa50 = DAT_00aaa8a4;

  *(uint8_t *)(in_EAX + 0x9c3) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0) = 0;

  *(uint8_t *)(in_EAX + 0x9a5) = 0;

  *(uint8_t *)(in_EAX + 0x9e6) = 1;

  *(uint8_t *)(in_EAX + 0x9e7) = 1;

  *(uint8_t *)(in_EAX + 0x20) = 1;

  DAT_00b03e65 = 0;

  return;

}
