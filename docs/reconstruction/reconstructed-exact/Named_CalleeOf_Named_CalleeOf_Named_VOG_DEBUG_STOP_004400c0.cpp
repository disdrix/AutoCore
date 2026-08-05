// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004400c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004400c0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004400c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004400c0, ROUND, ceil.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

int Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004400c0(float param_1)



{

  uint uVar1;

  uint uVar2;

  double dVar3;

  

  dVar3 = ceil((double)param_1);

  uVar2 = -((uint)(float)dVar3 >> 0x17 & 0xff);

  uVar1 = -(uint)(0xffffff69 < uVar2);

  return (int)ROUND((float)((uint)(float)dVar3 & (uVar1 << ((char)uVar2 + 0x96U & 0x1f) | ~uVar1)));

}
