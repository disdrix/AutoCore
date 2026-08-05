// =============================================================================
// Named_CalleeOf_Client_LoadVogIniConfig_004a81c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a81c0
// Callee of Client_LoadVogIniConfig (+2 other named callers)
// Address:   0x004a81c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_LoadVogIniConfig: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_LoadVogIniConfig (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004a81c0, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_LoadVogIniConfig (+2 other named callers)
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

void __thiscall Named_CalleeOf_Client_LoadVogIniConfig_004a81c0(int param_1,char *param_2)



{

  strncpy((char *)(param_1 + 0xc),param_2,0x20);

  *(uint8_t *)(param_1 + 0x2c) = 0;

  return;

}
