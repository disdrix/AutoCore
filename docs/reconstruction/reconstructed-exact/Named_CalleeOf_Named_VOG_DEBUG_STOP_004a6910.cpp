// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004a6910
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6910
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x004a6910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_004a6910.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

int Named_CalleeOf_Named_VOG_DEBUG_STOP_004a6910(void)



{

  uint3 uVar1;

  

  uVar1 = (uint3)((uint)DAT_00b036d4 >> 8);

  if ((DAT_00b036d4 != (int *)0x0) && (*DAT_00b036d4 != 0)) {

    return CONCAT31(uVar1,1);

  }

  return (uint)uVar1 << 8;

}
