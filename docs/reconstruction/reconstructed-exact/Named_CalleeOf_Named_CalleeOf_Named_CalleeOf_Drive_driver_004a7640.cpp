// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_driver_004a7640
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7640
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_driver (+1 other named callers)
// Address:   0x004a7640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_driver: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Drive_driver (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004a7640, FUN_005c96c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_driver (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_driver_004a7640(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_005c96c0(param_2,param_3,param_4,param_1,param_4);

  return param_2 + param_3 * 4;

}
