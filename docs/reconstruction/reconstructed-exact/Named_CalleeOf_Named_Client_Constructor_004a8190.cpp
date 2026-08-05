// =============================================================================
// Named_CalleeOf_Named_Client_Constructor_004a8190
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8190
// Callee of Named_Client_Constructor
// Address:   0x004a8190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_Constructor: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004a8190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_Constructor
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

void __fastcall Named_CalleeOf_Named_Client_Constructor_004a8190(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_LAB_009ca23c;

  *(uint8_t *)(param_1 + 3) = 0;

  *(uint8_t *)((int)param_1 + 0x2d) = 0;

  *(uint8_t *)((int)param_1 + 0x4e) = 0;

  *(uint8_t *)((int)param_1 + 0x6f) = 0;

  *(uint8_t *)(param_1 + 0x24) = 0;

  return;

}
