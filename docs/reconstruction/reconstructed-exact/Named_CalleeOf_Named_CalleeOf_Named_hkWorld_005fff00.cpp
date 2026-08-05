// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005fff00
// -----------------------------------------------------------------------------
// Stable ID: aa_005fff00
// Callee of Named_CalleeOf_Named_hkWorld
// Address:   0x005fff00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005ffed0, FUN_005fff00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_hkWorld
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005fff00(int param_1)



{

  FUN_005ffed0();

  *(uint8_t *)(param_1 + 0x18) = 1;

  *(uint16_t *)(param_1 + 0x1a) = 0xffff;

  return param_1;

}
